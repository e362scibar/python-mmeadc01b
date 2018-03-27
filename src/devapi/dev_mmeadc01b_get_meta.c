/**
 * @file     dev_mmeadc01b_get_meta.c
 * @brief    MME-ADC01-B: get META info for waveform data which DMA xfered.
 *
 * @note
 *
 * @date     2017-12-04
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_get_meta()
 * @brief    get META info for waveform data which DMA xfered.
 *
 * @param    [in]   fd                     int     ::= a file descriptor
 * @param    [out] *meta  mmeadc01b_xfer_meta_t    ::= META info on DMA xfer
 * @return          stat                           ::= process status
 */
int
dev_mmeadc01b_get_meta                      (int fd, mmeadc01b_xfer_meta_t *xm)
{
    int     stat = MMEADC01B_ERR_OK;

    /* read access w/ User I2C */
    stat       = ioctl(fd, MMEADC01B_GET_META, xm);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_INVALID;
    }

    return  stat;
}

/* end */
