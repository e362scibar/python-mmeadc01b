/**
 * @file     dev_mmeadc01b_munmap_dma_buf.c
 * @brief    MME-ADC01-B: free memory mapped area for DMA xfer buffer
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */
#include <sys/mman.h>                    /* mmap()      */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_munmap_dma_buf()
 * @brief    free memory mapped area for DMA xfer buffer
 *
 * @param    [in]    id              int  ::= file descriptor of the MME-ADC01-B
 * @param    [in]   *len    unsigned int  ::= mapping length (unit: [B])
 * @param    [in]   *dbuf            void ::= mapped area addresses
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_munmap_dma_buf                (int fd,                        void **dbuf)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       idx_dbuf;
    uint32_t  ofs;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    for (idx_dbuf = 0; idx_dbuf < N_DMA_BUF; idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], LEN_DMA_BUF_PER_CH) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = LEN_DMA_BUF_PER_CH * idx_dbuf;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    return  stat;
}

/* end */
