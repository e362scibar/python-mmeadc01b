/**
 * @file     dev_mmeadc01b_dac_read.c
 * @brief    MME-ADC01-B: read  data from DAC registers
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

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */

/**
 * dev_mmeadc01b_dac_read()
 * @brief    read  data from DAC registers
 *
 * @param    [in]   id               int  ::= file descriptor of the MME-ADC01-B
 * @param    [in]   id_adc           int  ::= device ID of DAC
 * @param    [in]   addr             int  ::= ADC register address to start to read
 * @param    [in]   num              int  ::= # of DAC registers to be read
 * @param    [out] *rbuf    unsigned int  ::= register data to be raad
 * @return          stat                  ::= process status
 */
int
dev_mmeadc01b_dac_read                      (int fd,             int  addr, int    num, unsigned int  *rbuf)
{
    int                 stat = MMEADC01B_ERR_OK;
    mmeadc01b_dev_rw_t  dev;

    if (fd    <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return   MMEADC01B_ERR_INVALID;
    }
    if (num   <= 0) {
        num    = 1;
    }


    dev.addr   = addr;
    dev.buf    = rbuf;
    dev.num    = num;

    stat       = ioctl(fd, MMEADC01B_DAC_READ , &dev);
    if (stat   < 0) {
        printf(" %s():[L%4d]: DAC register read  error = %d\n",
               __func__, __LINE__, stat);
        stat   = MMEADC01B_ERR_READ;
    }

    return  stat;
}

/* end */
