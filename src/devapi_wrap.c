#include <Python.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "dev_api_mmeadc01b.h"

#define NBUF 256

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

/* Wrapper functions */

static PyObject* mmeadc01b_open(PyObject* self, PyObject* args){
  const char* devname;
  int fd;
  if(!PyArg_ParseTuple(args, "s", &devname)){
    return NULL;
  }
  fd = open(devname, O_RDWR | O_SYNC);
  return PyLong_FromLong(fd);
}

static PyObject* mmeadc01b_close(PyObject* self, PyObject* args){
  int status, fd;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = close(fd);
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
  if(!PyArg_ParseTuple(args, "iiO", &fd, &slv, &ofs, &data)){
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

static PyObject* mmeadc01b_get_meta(PyObject* self, PyObject* args){
  int status, fd;
  mmeadc01b_xfer_meta_t xm[N_MMEADC01B_META_IDS];
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_get_meta(fd, xm);
  return Py_BuildValue("i{s:i,s:i}{s:i,s:i}", status,
    "wrapped", xm[MMEADC01B_META_ID_ADC].wrapped,
    "npt", xm[MMEADC01B_META_ID_ADC].npt,
    "wrapped", xm[MMEADC01B_META_ID_IQ].wrapped,
    "npt", xm[MMEADC01B_META_ID_IQ].npt);
}

static PyObject* mmeadc01b_clear_dma_buf_status(PyObject* self, PyObject* args){
  int status, fd;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_clear_dma_buf_status(fd);
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_register_interrupt_callback(PyObject* self, PyObject* args){
  int status, fd;
  void* cb;
  PyObject* ptr;
  if(!PyArg_ParseTuple(args, "iO", &fd, &ptr)){
    return NULL;
  }
  cb = PyLong_AsVoidPtr(ptr);
  status = dev_mmeadc01b_register_interrupt_callback(fd, cb, getpid());
  return PyLong_FromLong(status);
}

static PyObject* mmeadc01b_unregister_interrupt_callback(PyObject* self, PyObject* args){
  int status, fd;
  if(!PyArg_ParseTuple(args, "i", &fd)){
    return NULL;
  }
  status = dev_mmeadc01b_unregister_interrupt_callback(fd);
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

/* Module definition */

static PyMethodDef mmeadc01b_methods[] = {
  {"open", mmeadc01b_open, METH_VARARGS, "Open MMEADC01B device."},
  {"close", mmeadc01b_close, METH_VARARGS, "Close MMEADC01B device."},
  {"read", mmeadc01b_read, METH_VARARGS, "Read register."},
  {"write", mmeadc01b_write, METH_VARARGS, "Write register."},
  {"adc_read", mmeadc01b_adc_read, METH_VARARGS, "Read ADC configuration."},
  {"adc_write", mmeadc01b_adc_write, METH_VARARGS, "Write ADC configuration."},
  {"dac_read", mmeadc01b_dac_read, METH_VARARGS, "Read DAC configuration."},
  {"dac_write", mmeadc01b_dac_write, METH_VARARGS, "Write DAC configuration."},
  {"lmk_write", mmeadc01b_lmk_write, METH_VARARGS, "Write LMK configuration."},
  {"user_i2c_read", mmeadc01b_user_i2c_read, METH_VARARGS, "Read user I2C of RTM."},
  {"user_i2c_write", mmeadc01b_user_i2c_write, METH_VARARGS, "Write user I2C of RTM."},
  {"mmap_dma_buf", mmeadc01b_mmap_dma_buf, METH_VARARGS, "Mmap for DMA transfer."},
  {"munmap_dma_buf", mmeadc01b_munmap_dma_buf, METH_VARARGS, "Munmap for DMA transfer."},
  {"get_meta", mmeadc01b_get_meta, METH_VARARGS, "Get metadata."},
  {"clear_dma_buf_status", mmeadc01b_clear_dma_buf_status, METH_VARARGS, "Clear DMA buffer status."},
  {"register_interrupt_callback", mmeadc01b_register_interrupt_callback, METH_VARARGS, "Register interrupt callback."},
  {"unregister_interrupt_callback", mmeadc01b_unregister_interrupt_callback, METH_VARARGS, "Unregister interrupt callback."},
  {"set_clk_src", mmeadc01b_set_clk_src, METH_VARARGS, "Set clock source."},
  {"get_clk_src", mmeadc01b_get_clk_src, METH_VARARGS, "Get clock source."},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mmeadc01b_module = {
  PyModuleDef_HEAD_INIT,
  "devapi", /* name of module */
  NULL, /* module documentation */
  -1,
  mmeadc01b_methods
};

PyMODINIT_FUNC PyInit_mmeadc01b(void){
  return PyModule_Create(&mmeadc01b_module);
}

