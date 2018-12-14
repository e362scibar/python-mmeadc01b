/**
 * @file     dev_mmeadc01b_user_i2c_write.c
 * @brief    MME-ADC01-B: write data to   slave device via User I2C bus
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
 * dev_mmeadc01b_user_i2c_write()
 * @brief    write data to   slave device via User I2C bus
 *
 * @param    [in]      fd        int   ::= file descriptor of the MME-ADC01-B
 * @param    [in,out] *fmt   i2c_fmt_t ::= I2C data format
 * @return             stat            ::= process status
 */
int
dev_mmeadc01b_user_i2c_write                (int fd,       i2c_fmt_t *fmt)
{
    int     stat = MMEADC01B_ERR_OK;

    /* read access w/ User I2C */
    stat       = ioctl(fd, MMEADC01B_USER_I2C_WRITE, fmt);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_INVALID;
    }

    return  stat;
}

/* end */
