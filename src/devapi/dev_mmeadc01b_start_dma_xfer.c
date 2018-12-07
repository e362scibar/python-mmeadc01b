/**
 * @file     dev_mmeadc01b_start_dma_xfer.c
 * @brief    MME-ADC01-B: start DMA xfer w/ specific Ring position.
 *
 * @note
 *
 * @date     2018-08-06
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_start_dma_xfer()
 * @brief    start DMA xfer w/ specific Ring position.
 *
 * @param    [in]   fd         int     ::= a file descriptor
 * @param    [in]   req_acq   uint32_t ::= request to retrieve data from a board.
 * @param    [in]   idx_ring   int     ::= index # of the Ring
 * @return          stat                ::= process status
 */
int
dev_mmeadc01b_start_dma_xfer                (int fd, uint32_t req_acq, int idx_ring)
{
    int       stat      = MMEADC01B_ERR_OK;

    /** @todo:ymzk: start DMA xfer w/ specific Ring position. */

    return  stat;
}

/* end */
