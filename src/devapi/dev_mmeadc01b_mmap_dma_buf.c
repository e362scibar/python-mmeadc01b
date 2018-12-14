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

#include "mmeadc01b_defs.h"              /* IOCTL cmd   */
#include "dev_api_mmeadc01b.h"           /* own library */

/**
 * dev_mmeadc01b_mmap_dma_buf()
 * @brief    memory mapping to DMA xfer buffer.
 *
 * @param    [in]    fd              int  ::= file descriptor of the MME-ADC01-B
 * @param    [out] **dbuf            void ::= mapped area addresses
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_mmap_dma_buf                  (int fd, void **dbuf)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       idx_dbuf;
    uint32_t  ofs;
    uint32_t  len_mmap;
    uint8_t  *dbuf_virt;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    /* ADC */
    for (idx_dbuf = ADC_CH_1;    idx_dbuf <= ADC_CH_10;    idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_ADC_DAT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
        printf("idx_dbuf %d\n", idx_dbuf);
    }

    /* I/Q */
    for (idx_dbuf = DDC_CH_IQ_1; idx_dbuf <= DDC_CH_IQ_16; idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_DDC_DAT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
        printf("idx_dbuf %d\n", idx_dbuf);
    }

#if 0                           /* for BPM */
    /* SP  */
    for (idx_dbuf = SP_CH_1;     idx_dbuf <= SP_CH_10;     idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_SP_DAT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* CAL Tone */
    for (idx_dbuf = TONE_CH_1;   idx_dbuf <= TONE_CH_10;   idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_TONE_DAT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM 1  > COD TbT    */
    {
        idx_dbuf       = BPM_CH_1_TBT;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_TBT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM 1  > COD FA     */
    {
        idx_dbuf       = BPM_CH_1_FA;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_FA;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM 1  > COD SA     */
    {
        idx_dbuf       = BPM_CH_1_SA;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_SA;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM 1  > SP Process */
    for (idx_dbuf = BPM_CH_1_SP_1; idx_dbuf <= BPM_CH_1_SP_4;   idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_SP_BLOCK; /* 4[MB] per block */
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM  2 > COD TbT    */
    {
        idx_dbuf       = BPM_CH_2_TBT;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_TBT;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM  2 > COD FA     */
    {
        idx_dbuf       = BPM_CH_2_FA;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_FA;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM  2 > COD SA     */
    {
        idx_dbuf       = BPM_CH_2_SA;
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_SA;
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }

    /* BPM  2 > SP Process */
    for (idx_dbuf = BPM_CH_2_SP_1; idx_dbuf <= BPM_CH_2_SP_4;   idx_dbuf++) {
        stat           = ioctl(fd, MMEADC01B_PREP_DMA_BUF, &ofs);
        if (stat       < 0) {
            stat       = MMEADC01B_ERR_INVALID;
        }
        len_mmap       = LEN_BPM_DAT_SP_BLOCK; /* 4[MB] per block */
        dbuf_virt      = mmap(0, len_mmap, (PROT_WRITE | PROT_READ), MAP_SHARED, fd, ofs);
        if (dbuf_virt == MAP_FAILED) {
            perror("Error mmapping the file(dma)");
            stat = MMEADC01B_ERR_MMAP;
            break;
        }
        dbuf[idx_dbuf] = dbuf_virt;
        COUT(1, " dbuf[%2d]=%p\n", idx_dbuf, dbuf_virt);
    }
#endif  /* for BPM */

    return  stat;
}

/* end */
