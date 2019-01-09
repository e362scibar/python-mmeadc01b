/**
 * @file     dev_api_mmeadc01b_err_define.h
 * @brief    MME-ADC01-B: error code definitions
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#ifndef    DEV_API_MMEADC01BERR_FUNC_H
#define    DEV_API_MMEADC01BERR_FUNC_H

/* extern declarations */
extern   int    dev_mmeadc01b_read                          (int fd, int    id_bar , int  ofs , int    num, unsigned int  *rbuf);
extern   int    dev_mmeadc01b_write                         (int fd, int    id_bar , int  ofs , int    num, unsigned int  *wbuf);
extern   int    dev_mmeadc01b_adc_read                      (int fd, int    id_adc , int  addr, int    num, unsigned int  *rbuf);
extern   int    dev_mmeadc01b_adc_write                     (int fd, int    id_adc , int  addr, int    num, unsigned int  *wbuf);
extern   int    dev_mmeadc01b_dac_read                      (int fd,                 int  addr, int    num, unsigned int  *rbuf);
extern   int    dev_mmeadc01b_dac_write                     (int fd,                 int  addr, int    num, unsigned int  *wbuf);
extern   int    dev_mmeadc01b_lmk_write                     (int fd,                 int  addr, int    num, unsigned int  *wbuf);
extern   int    dev_mmeadc01b_user_i2c_read                 (int fd, i2c_fmt_t *fmt);
extern   int    dev_mmeadc01b_user_i2c_write                (int fd, i2c_fmt_t *fmt);
extern   int    dev_mmeadc01b_mmap_dma_buf                  (int fd, void **dbuf);
extern   int    dev_mmeadc01b_munmap_dma_buf                (int fd, void **dbuf);
extern   int    dev_mmeadc01b_start_dma_xfer                (int fd, uint32_t req_acq, int idx_area);
extern   int    dev_mmeadc01b_get_ring_status               (int fd, uint32_t  *cmplt);
extern   int    dev_mmeadc01b_get_meta                      (int fd, mmeadc01b_xfer_meta_t *xm);
extern   int    dev_mmeadc01b_clear_dma_buf_status          (int fd);
// unused //extern   int    dev_mmeadc01b_register_interrupt_callback   (int fd, void  *cb     , int  pid);
// unused //extern   int    dev_mmeadc01b_unregister_interrupt_callback (int fd);
extern   int    dev_mmeadc01b_set_clk_src                   (int fd, int    clk_src);
extern   int    dev_mmeadc01b_get_clk_src                   (int fd, int   *clk_src);
extern   int    dev_mmeadc01b_set_rot_coeff                 (int fd, int    id_ch  , double  gain, double  rad);
extern   int    dev_mmeadc01b_get_rot_coeff                 (int fd, int    id_ch  , double *gain, double *rad);

#endif  /* DEV_API_MMEADC01B_FUNC */

/* end */
