/**
 * @file     dev_mmeadc01b_get_ring_status.c
 * @brief    MME-ADC01-B: get ring status whether any data has been prepared
 *                         to transfer from board to CPU memory.
 *
 * @note
 *
 * @date     2018-09-13
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "mmeadc01b_defs.h"              /* IOCTL cmd   */
#include "dev_api_mmeadc01b.h"           /* own library */
#include "dev_mmeadc01b_util.h"          /* utilities   */

/**
 * dev_mmeadc01b_get_ring_status()
 * @brief    get ring status whether any data has been prepared
 *            to transfer from board to CPU memory.
 *
 * @param    [in]   fd         int     ::= a file descriptor
 * @param    [out] *cmplt     uint32_t ::= completion status (bitwise)
 */
int
dev_mmeadc01b_get_ring_status                   (int fd, uint32_t *cmplt)
{
    int       stat      = MMEADC01B_ERR_OK;

    /* get completion status */
    stat       = ioctl(fd, MMEADC01B_GET_RING_STATUS, cmplt);
    if (stat   < 0) {
        *cmplt = 0;
    }

    return  stat;
}

/* end */
