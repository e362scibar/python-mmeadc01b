/**
 * @file     dev_mmeadc01b_clear_dma_buf_status.c
 * @brief    MME-ADC01-B: clear DMA buffer transfer complete status
 *
 * @note
 *
 * @date     2017-11-28
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_clear_dma_buf_status()
 * @brief    clear DMA buffer transfer complete status
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @param    [in]   clk_src int     ::= clock source to be selected
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_clear_dma_buf_status          (int fd)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       idx_dbuf;
    uint32_t  ofs;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    for (idx_dbuf = 0; idx_dbuf < N_DMA_BUF; idx_dbuf++) {
        ofs      = LEN_DMA_BUF_PER_CH * idx_dbuf;
        stat     = ioctl(fd, MMEADC01B_REUSE_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    return  stat;
}

/* end */
