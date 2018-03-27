/**
 * @file     dev_mmeadc01b_get_clk_src.c
 * @brief    MME-ADC01-B: get current ADC sampling clock source
 *
 * @note
 *
 * @date     2017-11-24
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_get_clk_src()
 * @brief    get current ADC sampling clock source
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @param    [out] *clk_src int     ::= current clock source
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_get_clk_src                   (int fd, int  *clk_src)
{
    int     stat = MMEADC01B_ERR_OK;

    /* read access w/ User I2C */
    stat       = ioctl(fd, MMEADC01B_GET_CLK_SRC, clk_src);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_INVALID;
    }

    return  stat;
}

/* end */
