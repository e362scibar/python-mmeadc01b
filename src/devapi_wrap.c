#include <Python.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "dev_api_mmeadc01b.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

#define NBUF 256

#define INT24_TO_INT32(a) ((((a)&0xFFFFFF)<0x800000)?((a)&0xFFFFFF):(((a)&0xFFFFFF)-0x1000000))

/* Helper functions */

static int check_num(int num){
  if(num > NBUF){
    printf("N data too large. %d (max %d)\n", num, NBUF);
    return 1;
  }else if(num <= 0){
    printf("number of data is 0 or negative. %d\n", num);
    return -1;
  }
  return 0;
}

static int check_bpm_ch(int ch){
  if(ch < 0 || ch >= N_BPM_CH){
    char str[NBUF];
    sprintf(str, "Invalid BPM channel %d", ch);
    PyErr_SetString(PyExc_IndexError, str);
    return -1;
  }
  return 0;
}

static int check_sp_block(int block){
  if(block < 0 || block >= N_BPM_SP_BLOCKS){
    char str[NBUF];
    sprintf(str, "Invalid SP block %d", block);
    PyErr_SetString(PyExc_IndexError, str);
    return -1;
  }
  return 0;
}

static PyObject* set_tuple(int num, const unsigned int* buf){
  int i;
  PyObject* data = PyTuple_New(num);
  for(i=0; i<num; i++){
    PyTuple_SetItem(data, i, PyLong_FromUnsignedLong(buf[i]));
  }
  return data;
}

static int get_tuple(unsigned int* buf, PyObject* data){
  int i, num;
  if(!PyTuple_Check(data)){
    return -1;
  }
  num = PyTuple_Size(data);
  if(check_num(num)){
    return -1;
  }
  for(i=0; i<num; i++){
    buf[i] = PyLong_AsUnsignedLong(PyTuple_GetItem(data, i));
  }
  return num;
}

static PyObject* set_tuple_char(int num, const unsigned char* buf){
  int i;
  PyObject* data = PyTuple_New(num);
  for(i=0; i<num; i++){
    PyTuple_SetItem(data, i, PyLong_FromUnsignedLong(buf[i]));
  }
  return data;
}

static int get_tuple_char(unsigned char* buf, PyObject* data){
  int i, num;
  if(!PyTuple_Check(data)){
    return -1;
  }
  num = PyTuple_Size(data);
  if(check_num(num)){
    return -1;
  }
  for(i=0; i<num; i++){
    buf[i] = (unsigned char)(PyLong_AsUnsignedLong(PyTuple_GetItem(data, i))&0xff);
  }
  return num;
}

static PyObject* set_tuple_ptr(void** buf){
  int i;
  PyObject* data = PyTuple_New(N_DMA_BUF);
  for(i=0; i<N_DMA_BUF; i++){
    PyTuple_SetItem(data, i, PyLong_FromVoidPtr(buf[i]));
  }
  return data;
}

static int get_tuple_ptr(void** buf, PyObject* data){
  int i, num;
  if(!PyTuple_Check(data)){
    return -1;
  }
  num = PyTuple_Size(data);
  if(num != N_DMA_BUF){
    printf("Illegal number of data. num = %d != N_DMA_BUF = %d\n", num, N_DMA_BUF);
  }
  for(i=0; i<N_DMA_BUF; i++){
    buf[i] = PyLong_AsVoidPtr(PyTuple_GetItem(data, i));
  }
  return num;
}

static PyObject* set_tuple_double(int num, const double* buf){
  int i;
  PyObject* data = PyTuple_New(num);
  for(i=0; i<num; i++){
    PyTuple_SetItem(data, i, PyFloat_FromDouble(buf[i]));
  }
  return data;
}

static int get_tuple_double(double* buf, PyObject* data){
  int i, num;
  if(!PyTuple_Check(data)){
    return -1;
  }
  num = PyTuple_Size(data);
  if(check_num(num)){
    return -1;
  }
  for(i=0; i<num; i++){
    buf[i] = PyFloat_AsDouble(PyTuple_GetItem(data, i));
  }
  return num;
}

static PyObject* set_tuple_meta(int num, const mmeadc01b_xfer_meta_t* xm){
  int i;
  PyObject* data = PyTuple_New(num);
  for(i=0; i<num; i++){
    PyObject* dict = Py_BuildValue("{s:i,s:i,s:i,s:i}",
      "idx_latest", xm[i].idx_latest, "idx_intl", xm[i].idx_intl,
      "wrapped", xm[i].wrapped, "npt", xm[i].npt);
    PyTuple_SetItem(data, i, dict);
  }
  return data;
}

/* Wrapper functions */

static PyObject* mmeadc01b_open(PyObject* self, PyObject* args){
  const char* devname;
  int fd;
  if(!PyArg_ParseTuple(args, "s", &devname)){
    return NULL;
  }
  fd = open(devname, O_RDWR | O_SYNC);
  if(fd == -1){
    PyErr_SetFromErrno(PyExc_OSError);
    return NULL;
  }
  return PyLong_FromLong(fd);
}

static PyObject* mmeadc01b_close(PyObject* self, PyObject* args){
  int status, fd;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = close(fd);
  if(fd == -1){
    PyErr_SetFromErrno(PyExc_OSError);
    return NULL;
  }
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_read(PyObject* self, PyObject* args){
  int status, fd, id_bar, ofs, num;
  unsigned int rbuf[NBUF];
  if(!PyArg_ParseTuple(args, "iiii", &fd, &id_bar, &ofs, &num)){
    return NULL;
  }
  if(check_num(num)){
    return NULL;
  }
  status = dev_mmeadc01b_read(fd, id_bar, ofs, num, rbuf);
  return Py_BuildValue("iO", status, set_tuple(num, rbuf));
}

static PyObject* mmeadc01b_write(PyObject* self, PyObject* args){
  int status, fd, id_bar, ofs, num;
  unsigned int wbuf[NBUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iiiO", &fd, &id_bar, &ofs, &data)){
    return NULL;
  }
  num = get_tuple(wbuf, data);
  if(num <= 0){
    return NULL;
  }
  status = dev_mmeadc01b_write(fd, id_bar, ofs, num, wbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_read_float(PyObject* self, PyObject* args){
  int status, i, fd, id_bar, ofs, num;
  unsigned int rbuf[NBUF];
  double dbuf[NBUF];
  if(!PyArg_ParseTuple(args, "iiii", &fd, &id_bar, &ofs, &num)){
    return NULL;
  }
  if(check_num(num)){
    return NULL;
  }
  status = dev_mmeadc01b_read(fd, id_bar, ofs, num, rbuf);
  for(i=0; i<num; i++){
    union _buf{
      unsigned int i;
      float f;
    }buf;
    buf.i = rbuf[i];
    dbuf[i] = (double)buf.f;
  }
  return Py_BuildValue("iO", status, set_tuple_double(num, dbuf));
}

static PyObject* mmeadc01b_write_float(PyObject* self, PyObject* args){
  int status, i, fd, id_bar, ofs, num;
  unsigned int wbuf[NBUF];
  double dbuf[NBUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iiiO", &fd, &id_bar, &ofs, &data)){
    return NULL;
  }
  num = get_tuple_double(dbuf, data);
  if(num <= 0){
    return NULL;
  }
  for(i=0; i<num; i++){
    union _buf{
      unsigned int i;
      float f;
    }buf;
    buf.f = (float)dbuf[i];
    wbuf[i] = buf.i;
  }
  status = dev_mmeadc01b_write(fd, id_bar, ofs, num, wbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_adc_read(PyObject* self, PyObject* args){
  int status, fd, id_adc, addr, num;
  unsigned int rbuf[NBUF];
  if(!PyArg_ParseTuple(args, "iiii", &fd, &id_adc, &addr, &num)){
    return NULL;
  }
  if(check_num(num)){
    return NULL;
  }
  status = dev_mmeadc01b_adc_read(fd, id_adc, addr, num, rbuf);
  return Py_BuildValue("iO", status, set_tuple(num, rbuf));
}

static PyObject* mmeadc01b_adc_write(PyObject* self, PyObject* args){
  int status, fd, id_adc, addr, num;
  unsigned int wbuf[NBUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iiiO", &fd, &id_adc, &addr, &data)){
    return NULL;
  }
  num = get_tuple(wbuf, data);
  if(num <= 0){
    return NULL;
  }
  status = dev_mmeadc01b_adc_write(fd, id_adc, addr, num, wbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_dac_read(PyObject* self, PyObject* args){
  int status, fd, addr, num;
  unsigned int rbuf[NBUF];
  if(!PyArg_ParseTuple(args, "iii", &fd, &addr, &num)){
    return NULL;
  }
  if(check_num(num)){
    return NULL;
  }
  status = dev_mmeadc01b_dac_read(fd, addr, num, rbuf);
  return Py_BuildValue("iO", status, set_tuple(num, rbuf));
}

static PyObject* mmeadc01b_dac_write(PyObject* self, PyObject* args){
  int status, fd, addr, num;
  unsigned int wbuf[NBUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iiO", &fd, &addr, &data)){
    return NULL;
  }
  num = get_tuple(wbuf, data);
  if(num <= 0){
    return NULL;
  }
  status = dev_mmeadc01b_dac_write(fd, addr, num, wbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_lmk_write(PyObject* self, PyObject* args){
  int status, fd, addr, num;
  unsigned int wbuf[NBUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iiO", &fd, &addr, &data)){
    return NULL;
  }
  num = get_tuple(wbuf, data);
  if(num <= 0){
    return NULL;
  }
  status = dev_mmeadc01b_lmk_write(fd, addr, num, wbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_user_i2c_read(PyObject* self, PyObject* args){
  int status, fd, slv, ofs, num;
  unsigned char txbuf, rbuf[NBUF];
  i2c_fmt_t fmt;
  if(!PyArg_ParseTuple(args, "iiii", &fd, &slv, &ofs, &num)){
    return NULL;
  }
  if(check_num(num)){
    return NULL;
  }
  txbuf = (unsigned char)(ofs&0xff);
  fmt.slv = slv;
  fmt.rw = I2C_READ;
  fmt.wbuf = &txbuf;
  fmt.wlen = 1;
  fmt.repeated = TRUE;
  fmt.rbuf = rbuf;
  fmt.rlen = num;
  status = dev_mmeadc01b_user_i2c_read(fd, &fmt);
  return Py_BuildValue("iO", status, set_tuple_char(num, rbuf));
}

static PyObject* mmeadc01b_user_i2c_write(PyObject* self, PyObject* args){
  int status, fd, slv, ofs, num;
  unsigned char txbuf[NBUF+1];
  PyObject* data;
  i2c_fmt_t fmt;
  if(!PyArg_ParseTuple(args, "iiiO", &fd, &slv, &ofs, &data)){
    return NULL;
  }
  num = get_tuple_char(&txbuf[1], data);
  if(num <= 0){
    return NULL;
  }
  txbuf[0] = (unsigned char)(ofs&0xff);
  fmt.slv = slv;
  fmt.rw = I2C_WRITE;
  fmt.wbuf = txbuf;
  fmt.wlen = num+1;
  fmt.repeated = FALSE;
  fmt.rbuf = NULL;
  fmt.rlen = 0;
  status = dev_mmeadc01b_user_i2c_write(fd, &fmt);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_mmap_dma_buf(PyObject* self, PyObject* args){
  int status, fd;
  void* dbuf[N_DMA_BUF];
  memset(dbuf, 0, sizeof(dbuf));
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_mmap_dma_buf(fd, dbuf);
  return Py_BuildValue("iO", status, set_tuple_ptr(dbuf));
}

static PyObject* mmeadc01b_munmap_dma_buf(PyObject* self, PyObject* args){
  int status, fd;
  void* dbuf[N_DMA_BUF];
  PyObject* data;
  if(!PyArg_ParseTuple(args, "iO", &fd, &data)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  status = dev_mmeadc01b_munmap_dma_buf(fd, dbuf);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_start_dma_xfer(PyObject* self, PyObject* args){
  int status, fd, idx_area;
  unsigned int req_acq;
  if(!PyArg_ParseTuple(args, "iIi", &fd, &req_acq, &idx_area)){
    return NULL;
  }
  status = dev_mmeadc01b_start_dma_xfer(fd, req_acq, idx_area);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_get_ring_status(PyObject* self, PyObject* args){
  int status, fd;
  unsigned int cmplt;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_get_ring_status(fd, &cmplt);
  return Py_BuildValue("iI", status, cmplt);
}

static PyObject* mmeadc01b_get_meta(PyObject* self, PyObject* args){
  int status, fd;
  mmeadc01b_xfer_meta_t xm[N_MMEADC01B_META_IDS];
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_get_meta(fd, xm);
  return Py_BuildValue("iO", status, set_tuple_meta(N_MMEADC01B_META_IDS, xm));
}

static PyObject* mmeadc01b_clear_dma_buf_status(PyObject* self, PyObject* args){
  int status, fd;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_clear_dma_buf_status(fd);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_set_clk_src(PyObject* self, PyObject* args){
  int status, fd, clk_src;
  if(!PyArg_ParseTuple(args, "ii", &fd, &clk_src)){
    return NULL;
  }
  status = dev_mmeadc01b_set_clk_src(fd, clk_src);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_get_clk_src(PyObject* self, PyObject* args){
  int status, fd, clk_src;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_get_clk_src(fd, &clk_src);
  return Py_BuildValue("ii", status, clk_src);
}

static PyObject* mmeadc01b_set_rot_coeff(PyObject* self, PyObject* args){
  int status, fd, ch;
  double gain, phase;
  if(!PyArg_ParseTuple(args, "iidd", &fd, &ch, &gain, &phase)){
    return NULL;
  }
  status = dev_mmeadc01b_set_rot_coeff(fd, ch, gain, phase);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_get_rot_coeff(PyObject* self, PyObject* args){
  int status, fd, ch;
  double gain, phase;
  if(!PyArg_ParseTuple(args, "ii", &fd, &ch)){
    return NULL;
  }
  status = dev_mmeadc01b_get_rot_coeff(fd, ch, &gain, &phase);
  return Py_BuildValue("idd", status, gain, phase);
}

static PyObject* mmeadc01b_get_waveform(PyObject* self, PyObject* args){
  int status=0, i, j;
  void* dbuf[N_DMA_BUF];
  const int ND = 2;
  /* N_ADC_CH = 10 */
  /* N_DDC_CH = 16 */
  npy_intp dims_wfm_adc[/*ND*/] = {N_ADC_CH, N_ADC_POINTS};
  npy_intp dims_wfm_iq[/*ND*/] = {N_DDC_CH, N_DDC_POINTS};
  PyObject* data;
  PyArrayObject* wfm_adc;
  PyArrayObject* wfm_iq;
  if(!PyArg_ParseTuple(args, "O", &data)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  wfm_adc = (PyArrayObject*)PyArray_SimpleNew(ND, dims_wfm_adc, NPY_FLOAT32);
  wfm_iq = (PyArrayObject*)PyArray_SimpleNew(ND, dims_wfm_iq, NPY_COMPLEX64);
  for(i=0; i<N_ADC_CH; i++){
    const int* p1 = dbuf[i];
    for(j=0; j<N_ADC_POINTS; j++){
      float* p2 = (float*)PyArray_GETPTR2(wfm_adc, (npy_intp)i, (npy_intp)j);
      *p2 = (float)((short)(p1[j]&0xFFFF));
    }
  }
  for(i=0; i<N_DDC_CH; i++){
    int* p1 = dbuf[N_ADC_CH+i];
    for(j=0; j<N_DDC_POINTS; j++){
      float* p2 = (float*)PyArray_GETPTR2(wfm_iq, (npy_intp)i, (npy_intp)j);
      p2[0] = (float)((short)(p1[j]&0xFFFF));
      p2[1] = (float)((short)((p1[j]>>16)&0xFFFF));
    }
  }
  return Py_BuildValue("iOO", status, wfm_adc, wfm_iq);
}

static PyObject* mmeadc01b_get_waveform_tone(PyObject* self, PyObject* args){
  int status=0, i, j, k;
  void* dbuf[N_DMA_BUF];
  const int ND = 3;
  const int N_TONE_FREQ = 4;
  /* N_TONE_CH = 10 */
  npy_intp dims[/*ND*/] = {N_TONE_CH, N_TONE_FREQ, N_TONE_POINTS};
  PyObject* data;
  PyArrayObject* wfm_tone;
  if(!PyArg_ParseTuple(args, "O", &data)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  wfm_tone = (PyArrayObject*)PyArray_SimpleNew(ND, dims, NPY_COMPLEX64);
  for(i=0; i<N_TONE_CH; i++){
    const int* p1 = dbuf[N_ADC_CH+N_DDC_CH+i];
    for(j=0; j<N_TONE_FREQ; j++){
      for(k=0; k<N_TONE_POINTS; k++){
        float* p2 = (float*)PyArray_GETPTR3(wfm_tone, (npy_intp)i, (npy_intp)j, (npy_intp)k);
        p2[0] = (float)INT24_TO_INT32(p1[k*N_TONE_FREQ*2+j*2]);
        p2[1] = (float)INT24_TO_INT32(p1[k*N_TONE_FREQ*2+j*2+1]);
      }
    }
  }
  return Py_BuildValue("iO", status, wfm_tone);
}

static PyObject* mmeadc01b_get_waveform_sp(PyObject* self, PyObject* args){
  int status=0, i, j, k;
  void* dbuf[N_DMA_BUF];
  const int ND = 3;
  /* N_BPM_CH = 2 */
  /* N_SP_CH = 8 */
  npy_intp dims[/*ND*/] = {N_BPM_CH, N_SP_CH/N_BPM_CH, N_SP_POINTS};
  PyObject* data;
  PyArrayObject* wfm_sp;
  if(!PyArg_ParseTuple(args, "O", &data)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  wfm_sp = (PyArrayObject*)PyArray_SimpleNew(ND, dims, NPY_COMPLEX64);
  for(i=0; i<N_BPM_CH; i++){
    for(j=0; j<N_SP_CH/N_BPM_CH; j++){
      const int* p1 = dbuf[N_ADC_CH+N_DDC_CH+i*N_SP_CH/N_BPM_CH+j];
      for(k=0; k<N_SP_POINTS; k++){
        float* p2 = (float*)PyArray_GETPTR3(wfm_sp, (npy_intp)i, (npy_intp)j, (npy_intp)k);
        p2[0] = (float)((short)(p1[k]&0xFFFF));
        p2[1] = (float)((short)((p1[k]>>16)&0xFFFF));
      }
    }
  }
  return Py_BuildValue("iO", status, wfm_sp);
}

/* BPM Data Stream */

static PyArrayObject* get_bpm_data(const int32_t* dbuf, const int nelem, const int npts){
  int i, j;
  const int ND = 2;
  /* N_BPM_CH = 2 */
  npy_intp dims[/*ND*/] = {nelem, npts};
  PyArrayObject* data;
  data = (PyArrayObject*)PyArray_SimpleNew(ND, dims, NPY_FLOAT32);
  for(i=0; i<nelem; i++){
    for(j=0; j<npts; j++){
      float* p = (float*)PyArray_GETPTR2(data, (npy_intp)i, (npy_intp)j);
      *p = (float)INT24_TO_INT32(dbuf[j*nelem+i]);
    }
  }
  return data;
}

static PyObject* mmeadc01b_get_tbt_data(PyObject* self, PyObject* args){
  int status=0, ch;
  const int index[N_BPM_CH] = {BPM_CH_1_TBT, BPM_CH_2_TBT};
  const int nelem = LEN_BPM_DAT_UNIT_TBT / sizeof(int32_t);
  const int npts = N_BPM_POINTS_TBT;
  void* dbuf[N_DMA_BUF];
  PyObject* data;
  PyArrayObject* data_tbt;
  if(!PyArg_ParseTuple(args, "Oi", &data, &ch)){
    return NULL;
  }
  if(check_bpm_ch(ch)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  data_tbt = get_bpm_data((const int32_t*)dbuf[index[ch]], nelem, npts);
  return Py_BuildValue("iO", status, data_tbt);
}

static PyObject* mmeadc01b_get_fa_data(PyObject* self, PyObject* args){
  int status=0, ch;
  const int index[N_BPM_CH] = {BPM_CH_1_FA, BPM_CH_2_FA};
  const int nelem = LEN_BPM_DAT_UNIT_FA / sizeof(int32_t);
  const int npts = N_BPM_POINTS_FA;
  void* dbuf[N_DMA_BUF];
  PyObject* data;
  PyArrayObject* data_fa;
  if(!PyArg_ParseTuple(args, "Oi", &data, &ch)){
    return NULL;
  }
  if(check_bpm_ch(ch)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  data_fa = get_bpm_data((const int32_t*)dbuf[index[ch]], nelem, npts);
  return Py_BuildValue("iO", status, data_fa);
}

static PyObject* mmeadc01b_get_sa_data(PyObject* self, PyObject* args){
  int status=0, ch;
  const int index[N_BPM_CH] = {BPM_CH_1_SA, BPM_CH_2_SA};
  const int nelem = LEN_BPM_DAT_UNIT_SA / sizeof(int32_t);
  const int npts = N_BPM_POINTS_SA;
  void* dbuf[N_DMA_BUF];
  PyObject* data;
  PyArrayObject* data_sa;
  if(!PyArg_ParseTuple(args, "Oi", &data, &ch)){
    return NULL;
  }
  if(check_bpm_ch(ch)){
    return NULL;
  }
  get_tuple_ptr(dbuf, data);
  data_sa = get_bpm_data((const int32_t*)dbuf[index[ch]], nelem, npts);
  return Py_BuildValue("iO", status, data_sa);
}

static PyObject* mmeadc01b_get_sp_data(PyObject* self, PyObject* args){
  int status=0, ch, block;
  const int ND = 3;
  const int index[N_BPM_CH] = {BPM_CH_1_SP_1, BPM_CH_2_SP_1};
  const int nmask = N_MMEADC01B_SP_MASK;
  const int nelem = LEN_BPM_DAT_UNIT_SA / sizeof(int32_t) / nmask;
  const int npts = N_BPM_POINTS_SP / N_BPM_SP_BLOCKS;
  void* dbuf[N_DMA_BUF];
  npy_intp dims[/*ND*/] = {nmask, nelem, npts};
  PyObject* data;
  PyArrayObject* data_sp;
  if(!PyArg_ParseTuple(args, "Oii", &data, &ch, &block)){
    return NULL;
  }
  if(check_bpm_ch(ch)){
    return NULL;
  }
  if(check_sp_block(block)){
    return NULL;
  }
  data_sp = (PyArrayObject*)PyArray_SimpleNew(ND, dims, NPY_FLOAT32);
  get_tuple_ptr(dbuf, data);
  {
    int i, j, k;
    const int* p1 = dbuf[index[ch]+block];
    for(i=0; i<nmask; i++){
      for(j=0; j<nelem; j++){
        for(k=0; k<npts; k++){
          float* p2 = (float*)PyArray_GETPTR3(data_sp, (npy_intp)i, (npy_intp)j, (npy_intp)k);
          size_t idx = k*nelem*nmask+i*nelem+j;
          *p2 = (float)INT24_TO_INT32(p1[idx]);
        }
      }
    }
  }
  return Py_BuildValue("iO", status, data_sp);
}

/* Module definition */

static PyMethodDef mmeadc01b_methods[] = {
  {"open", mmeadc01b_open, METH_VARARGS, "Open MMEADC01B device."},
  {"close", mmeadc01b_close, METH_VARARGS, "Close MMEADC01B device."},
  {"read", mmeadc01b_read, METH_VARARGS, "Read register."},
  {"write", mmeadc01b_write, METH_VARARGS, "Write register."},
  {"read_float", mmeadc01b_read_float, METH_VARARGS, "Read floating point numbers from registers."},
  {"write_float", mmeadc01b_write_float, METH_VARARGS, "Write floating point numbers to registers."},
  {"adc_read", mmeadc01b_adc_read, METH_VARARGS, "Read ADC configuration."},
  {"adc_write", mmeadc01b_adc_write, METH_VARARGS, "Write ADC configuration."},
  {"dac_read", mmeadc01b_dac_read, METH_VARARGS, "Read DAC configuration."},
  {"dac_write", mmeadc01b_dac_write, METH_VARARGS, "Write DAC configuration."},
  {"lmk_write", mmeadc01b_lmk_write, METH_VARARGS, "Write LMK configuration."},
  {"user_i2c_read", mmeadc01b_user_i2c_read, METH_VARARGS, "Read user I2C of RTM."},
  {"user_i2c_write", mmeadc01b_user_i2c_write, METH_VARARGS, "Write user I2C of RTM."},
  {"mmap_dma_buf", mmeadc01b_mmap_dma_buf, METH_VARARGS, "Mmap for DMA transfer."},
  {"munmap_dma_buf", mmeadc01b_munmap_dma_buf, METH_VARARGS, "Munmap for DMA transfer."},
  {"start_dma_xfer", mmeadc01b_start_dma_xfer, METH_VARARGS, "Start DMA transfer."},
  {"get_ring_status", mmeadc01b_get_ring_status, METH_VARARGS, "Get ring buffer status."},
  {"get_meta", mmeadc01b_get_meta, METH_VARARGS, "Get metadata."},
  {"clear_dma_buf_status", mmeadc01b_clear_dma_buf_status, METH_VARARGS, "Clear DMA buffer status."},
  {"set_clk_src", mmeadc01b_set_clk_src, METH_VARARGS, "Set clock source."},
  {"get_clk_src", mmeadc01b_get_clk_src, METH_VARARGS, "Get clock source."},
  {"set_rot_coeff", mmeadc01b_set_rot_coeff, METH_VARARGS, "Set rotator coefficient."},
  {"get_rot_coeff", mmeadc01b_get_rot_coeff, METH_VARARGS, "Get rotator coefficient."},
  {"get_waveform", mmeadc01b_get_waveform, METH_VARARGS, "Get ADC and IQ waveform data."},
  {"get_waveform_tone", mmeadc01b_get_waveform_tone, METH_VARARGS, "Get calibration tone waveform data."},
  {"get_waveform_sp", mmeadc01b_get_waveform_sp, METH_VARARGS, "Get SP waveform data."},
  {"get_tbt_data", mmeadc01b_get_tbt_data, METH_VARARGS, "Get TBT BPM data."},
  {"get_fa_data", mmeadc01b_get_fa_data, METH_VARARGS, "Get FA BPM data."},
  {"get_sa_data", mmeadc01b_get_sa_data, METH_VARARGS, "Get SA BPM data."},
  {"get_sp_data", mmeadc01b_get_sp_data, METH_VARARGS, "Get SP BPM data."},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mmeadc01b_module = {
  PyModuleDef_HEAD_INIT,
  "devapi", /* name of module */
  NULL, /* module documentation */
  -1,
  mmeadc01b_methods
};

PyMODINIT_FUNC PyInit_devapi(void){
  import_array();
  return PyModule_Create(&mmeadc01b_module);
}

