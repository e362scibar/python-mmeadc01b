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
#define  MMEADC01B_ERR_OK                        0       /* no error occured  */

#define  MMEADC01B_ERR_BAR            (-1402000000)      /*    invalid BAR #   */
#define  MMEADC01B_ERR_ADDR           (-1402000001)      /*    invalid address */
#define  MMEADC01B_ERR_RANGE          (-1402000002)      /*     out of range   */
#define  MMEADC01B_ERR_FORMAT         (-1402000003)      /* wrong data format  */
#define  MMEADC01B_ERR_READ           (-1402000004)      /*       read error   */
#define  MMEADC01B_ERR_WRITE          (-1402000005)      /*      write error   */
#define  MMEADC01B_ERR_MMAP           (-1402000006)      /*       mmap error   */
#define  MMEADC01B_ERR_MUNMAP         (-1402000007)      /*     munmap error   */
#define  MMEADC01B_ERR_INVALID        (-1402000008)      /*  something invalid */
#define  MMEADC01B_ERR_BUSY           (-1402000009)      /*       busy         */
#define  MMEADC01B_ERR_TIMEOUT        (-1402000010)      /*      timed out     */

#endif  /* DEV_API_MMEADC01B_ERR_DEFINE */

/* end */
