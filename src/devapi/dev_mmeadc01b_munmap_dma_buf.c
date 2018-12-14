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

#include "mmeadc01b_defs.h"              /* IOCTL cmd   */
#include "dev_api_mmeadc01b.h"           /* own library */

/**
 * dev_mmeadc01b_munmap_dma_buf()
 * @brief    free memory mapped area for DMA xfer buffer
 *
 * @param    [in]    fd              int  ::= file descriptor of the MME-ADC01-B
 * @param    [in]   *len    unsigned int  ::= mapping length (unit: [B])
 * @param    [in]   *dbuf            void ::= mapped area addresses
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_munmap_dma_buf                (int fd,                        void **dbuf)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       idx_dbuf;
    uint32_t  len_adc   = LEN_ADC_DAT;
    uint32_t  len_iq    = LEN_DDC_DAT;
//    uint32_t  len_sp    = LEN_SP_DAT;
//    uint32_t  len_tone  = LEN_TONE_DAT;
//    uint32_t  len_tbt   = LEN_BPM_DAT_TBT;
//    uint32_t  len_fa    = LEN_BPM_DAT_FA;
//    uint32_t  len_sa    = LEN_BPM_DAT_SA;
//    uint32_t  len_spp   = LEN_BPM_DAT_SP_BLOCK;
    uint32_t  ofs_adc   = 0;
    uint32_t  ofs_iq    = ofs_adc  + (len_adc  * N_ADC_CH );
//    uint32_t  ofs_sp    = ofs_iq   + (len_iq   * N_DDC_CH );
//    uint32_t  ofs_tone  = ofs_sp   + (len_sp   * N_SP_CH  );
//    uint32_t  ofs_tbt   = ofs_tone + (len_tone * N_TONE_CH);
//    uint32_t  ofs_fa    = ofs_tbt  +  len_tbt;
//    uint32_t  ofs_sa    = ofs_fa   +  len_fa;
//    uint32_t  ofs_spp   = ofs_sa   +  len_sa;
//    uint32_t  ofs_tbt2  = ofs_spp  +  len_spp;
//    uint32_t  ofs_fa2   = ofs_tbt2 +  len_tbt;
//    uint32_t  ofs_sa2   = ofs_fa2  +  len_fa;
//    uint32_t  ofs_spp2  = ofs_sa2  +  len_sa;
    uint32_t  len_mmap;
    uint32_t  ofs_base;
    uint32_t  ofs;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    stat     = ioctl(fd, MMEADC01B_INIT_DMA_POS, NULL);
    if (stat < 0) {
        stat = MMEADC01B_ERR_INVALID;
    }

    /* ADC */
    len_mmap = len_adc;
    ofs_base = ofs_adc;
    for (idx_dbuf = ADC_CH_1;    idx_dbuf <= ADC_CH_10;    idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* I/Q */
    len_mmap = len_iq;
    ofs_base = ofs_iq;
    for (idx_dbuf = DDC_CH_IQ_1; idx_dbuf <= DDC_CH_IQ_16; idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

#if 0                           /* for BPM */
    /* SP  */
    len_mmap = len_sp;
    ofs_base = ofs_sp;
    for (idx_dbuf = SP_CH_1;     idx_dbuf <= SP_CH_10;     idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* CAL Tone */
    len_mmap = len_tone;
    ofs_base = ofs_tone;
    for (idx_dbuf = TONE_CH_1;   idx_dbuf <= TONE_CH_10;   idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM 1  > COD TbT    */
    len_mmap = len_tbt;
    ofs_base = ofs_tbt;
    {
        idx_dbuf       = BPM_CH_1_TBT;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM 1  > COD FA     */
    len_mmap = len_fa;
    ofs_base = ofs_fa;
    {
        idx_dbuf       = BPM_CH_1_FA;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM 1  > COD SA     */
    len_mmap = len_sa;
    ofs_base = ofs_sa;
    {
        idx_dbuf       = BPM_CH_1_SA;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM 1  > SP Process */
    len_mmap = len_spp;
    ofs_base = ofs_spp;
    for (idx_dbuf = BPM_CH_1_SP_1; idx_dbuf <= BPM_CH_1_SP_4;   idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM  2 > COD TbT    */
    len_mmap = len_tbt;
    ofs_base = ofs_tbt2;
    {
        idx_dbuf       = BPM_CH_1_TBT;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM  2 > COD FA     */
    len_mmap = len_fa;
    ofs_base = ofs_fa2;
    {
        idx_dbuf       = BPM_CH_1_FA;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM  2 > COD SA     */
    len_mmap = len_sa;
    ofs_base = ofs_sa2;
    {
        idx_dbuf       = BPM_CH_1_SA;
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base;
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }

    /* BPM  2 > SP Process */
    len_mmap = len_spp;
    ofs_base = ofs_spp2;
    for (idx_dbuf = BPM_CH_1_SP_1; idx_dbuf <= BPM_CH_1_SP_4;   idx_dbuf++) {
        if (munmap(dbuf[idx_dbuf], len_mmap) == -1) {
            perror("Error un-mmapping the file(dma)");
            stat = MMEADC01B_ERR_MUNMAP;
        }
        ofs      = ofs_base + (len_mmap * idx_dbuf);
        stat     = ioctl(fd, MMEADC01B_CLEAN_DMA_BUF, &ofs);
        if (stat < 0) {
            stat = MMEADC01B_ERR_INVALID;
        }
    }
#endif  /* for BPM */

    return  stat;
}

/* end */
