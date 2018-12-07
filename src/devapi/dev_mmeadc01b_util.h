/**
 * @file     dev_api_mmeadc01b_util.h
 * @brief    MME-ADC01-B: DEV API library utilities
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#ifndef    DEV_API_MMEADC01B_UTIL_H
#define    DEV_API_MMEADC01B_UTIL_H

/* definitions */

/* extern declarations */
extern   int           dev_mmeadc01b_check_fpga_reg_range  (int   id_bar, int ofs, int num);
extern   int           dev_mmeadc01b_set_dma_xfer_cmplt    (uint32_t cmplt);
extern   int           dev_mmeadc01b_clr_dma_xfer_cmplt    (uint32_t cmplt);
extern uint32_t        dev_mmeadc01b_get_dma_xfer_cmplt    (void);
extern   int           dev_mmeadc01b_set_interrupt_callback(void *cb);
extern   int           dev_mmeadc01b_util_set_rot_coeff    (int id_ch, double  gain, double  rad);
extern   int           dev_mmeadc01b_util_get_rot_coeff    (int id_ch, double *gain, double *rad);

#endif  /* DEV_API_MMEADC01B_UTIL_H */

/* end */
