/**
 * @file     dev_api_mmeadc01b_err_define.h
 * @brief    MME-ADC01-B: error code definitions
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#ifndef    DEV_API_MMEADC01BERR_ERR_DEFINE_H
#define    DEV_API_MMEADC01BERR_ERR_DEFINE_H

/* error code  */
#define  MMEADC01B_ERR_MIN             -1402009999       /* 0xAC6F 0671       */
#define  MMEADC01B_ERR_MAX             -1402000000       /* 0xAC6F 2D80       */

#define  MMEADC01B_ERR_BASE      MMEADC01B_ERR_MIN       /* base error code   */

#define  MMEADC01B_ERR_OK                        0       /* no error occured  */

#define  MMEADC01B_ERR_BAR     (MMEADC01B_ERR_BASE +  0) /*    invalid BAR #   */
#define  MMEADC01B_ERR_ADDR    (MMEADC01B_ERR_BASE +  1) /*    invalid address */
#define  MMEADC01B_ERR_RANGE   (MMEADC01B_ERR_BASE +  2) /*     out of range   */
#define  MMEADC01B_ERR_FORMAT  (MMEADC01B_ERR_BASE +  3) /* wrong data format  */
#define  MMEADC01B_ERR_READ    (MMEADC01B_ERR_BASE +  4) /*       read error   */
#define  MMEADC01B_ERR_WRITE   (MMEADC01B_ERR_BASE +  5) /*      write error   */
#define  MMEADC01B_ERR_MMAP    (MMEADC01B_ERR_BASE +  6) /*       mmap error   */
#define  MMEADC01B_ERR_MUNMAP  (MMEADC01B_ERR_BASE +  7) /*     munmap error   */
#define  MMEADC01B_ERR_INVALID (MMEADC01B_ERR_BASE +  8) /*  something invalid */
#define  MMEADC01B_ERR_BUSY    (MMEADC01B_ERR_BASE +  9) /*       busy         */
#define  MMEADC01B_ERR_TIMEOUT (MMEADC01B_ERR_BASE + 10) /*      timed out     */


#endif  /* DEV_API_MMEADC01B_ERR_DEFINE */

/* end */
