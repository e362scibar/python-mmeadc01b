/**
 * @file     dev_mmeadc01b_get_completion_status.c
 * @brief    MME-ADC01-B: get DMA xfer completion status
 *
 * @note
 *
 * @date     2018-08-31
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */
#include "./dev_mmeadc01b_util.h"        /* utilities   */

/**
 * dev_mmeadc01b_get_completion_status()
 * @brief    get DMA xfer completion status
 *
 * @param    [in]   fd                     int     ::= a file descriptor
 * @param    [out] *cmplt                 uint32_t ::= DMA xfer completion status
 * @return          stat                           ::= process status
 */
int
dev_mmeadc01b_get_completion_status         (int fd, uint32_t  *cmplt)
{
    int       stat       = MMEADC01B_ERR_OK;

    /* completion status will be cleared automatically. */
    *cmplt = dev_mmeadc01b_get_dma_xfer_cmplt();

    return  stat;
}

/* end */
