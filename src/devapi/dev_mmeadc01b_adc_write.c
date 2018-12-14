/**
 * @file     dev_mmeadc01b_adc_write.c
 * @brief    MME-ADC01-B: write data to   ADC resisters
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

#include "mmeadc01b_defs.h"              /* IOCTL cmd   */
#include "dev_api_mmeadc01b.h"           /* own library */

/**
 * dev_mmeadc01b_adc_write()
 * @brief    write data to   ADC registers
 *
 * @param    [in]   fd               int  ::= file descriptor of the MME-ADC01-B
 * @param    [in]   id_adc           int  ::= device ID of ADC
 * @param    [in]   addr             int  ::= ADC register address to start to write
 * @param    [in]   num              int  ::= # of ADC registers to be written
 * @param    [in]  *wbuf    unsigned int  ::= register data to be written
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_adc_write                     (int fd, int id_adc, int  addr, int    num, unsigned int  *wbuf)
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

    dev.id_dev = id_adc;
    dev.addr   = addr;
    dev.buf    = wbuf;
    dev.num    = num;

    stat       = ioctl(fd, MMEADC01B_ADC_WRITE, &dev);
    if (stat   < 0) {
        printf(" %s():[L%4d]: ADC register write error = %d\n",
               __func__, __LINE__, stat);
        stat   = MMEADC01B_ERR_WRITE;
    }

    return  stat;
}

/* end */
