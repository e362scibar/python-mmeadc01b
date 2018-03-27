/**
 * @file     dev_mmeadc01b_mmap_dma_buf.c
 * @brief    MME-ADC01-B: memory mapping to DMA xfer buffer where wavefrom data stored.
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
 * dev_mmeadc01b_mmap_dma_buf()
 * @brief    memory mapping to DMA xfer buffer.
 *
 * @param    [in]    id              int  ::= file descriptor of the MME-ADC01-B
 * @param    [out] **dbuf            void ::= mapped area addresses
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_mmap_dma_buf                  (int fd, void **dbuf)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       idx_dbuf;
    uint32_t  ofs;
    uint8_t  *dbuf_virt;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    for (idx_dbuf = 0; idx_dbuf < N_DMA_BUF; idx_dbuf++) {
        ofs            = LEN_DMA_BUF_PER_CH * idx_dbuf;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        dbuf_virt      = mmap(0, LEN_DMA_BUF_PER_CH, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
    }

    return  stat;
}

/* end */
