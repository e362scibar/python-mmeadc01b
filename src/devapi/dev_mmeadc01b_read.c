/**
 * @file     dev_mmeadc01b_read.c
 * @brief    MME-ADC01-B: read  data from FPGA registers
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
#include "dev_mmeadc01b_util.h"          /* utilities   */

/**
 * dev_mmeadc01b_()
 * @brief    read  data from FPGA registers
 *
 * @param    [in]   fd         int     ::= a file descriptor
 * @param    [in]   id_bar     int     ::= BAR<n>
 * @param    [in]   ofs        int     ::= offset address of FPGA register
 * @param    [in]   num        int     ::= # of registers to be read
 * @param    [out] *rbuf      uint32_t ::= data to be read
 * @return          stat               ::= process status
 */
int
dev_mmeadc01b_read(int fd, int id_bar, int ofs, int num, uint32_t *rbuf)
{
    int                 stat = MMEADC01B_ERR_OK;
    mmeadc01b_reg_rw_t  mem;

    if (fd     < 0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }
    if (num    < 1) {
        num    = 1;
    }

    /* valid range ? */
    stat       = dev_mmeadc01b_check_fpga_reg_range(id_bar, ofs, num);
    if (stat   < 0) {
        return   stat;
    }

    /* build params to pass them drivers */
    mem.id_bar = id_bar;
    mem.ofs    = ofs;
    mem.buf    = rbuf;
    mem.num    = num;

    /* read FPGA register(s) */
    stat       = ioctl(fd, MMEADC01B_REG_READ , &mem);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_READ;
    }

    return  stat;
}

/* end */
