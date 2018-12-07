/**
 * @file     dev_mmeadc01b_get_rot_coeff.c
 * @brief    MME-ADC01-B: get current rotation coefficients.
 *
 * @note
 *
 * @date     2018-08-06
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <math.h>                        /* sin()/cos() */
#include <sys/ioctl.h>                   /* ioctl()     */
#include <sys/time.h>                    /* timeval     */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */
#include "./dev_mmeadc01b_util.h"        /* utilities   */

/**
 * dev_mmeadc01b_get_rot_coeff()
 * @brief    get current rotation coefficients.
 *
 * @param    [in]   fd         int  ::= a file descriptor
 * @param    [in]   id_ch      int  ::= rotation coeff. ch ID
 * @param    [out] *gain     double ::= gain amount
 * @param    [out] *rad      double ::= rotation angle theta (unit: [rad])
 * @return          stat       int  ::= process status
 */
int
dev_mmeadc01b_get_rot_coeff                 (int fd, int id_ch, double *gain, double *rad)
{
    int       stat      = MMEADC01B_ERR_OK;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    if ((id_ch < 0) || (N_MMEADC01B_ROT_COEFF_IDS <= id_ch)) { /* out of range ? */
        COUT(1, "unknown ID = %d.\n", id_ch);
        return  MMEADC01B_ERR_RANGE;
    }

    /* DAC or I/Q */
    stat = dev_mmeadc01b_util_get_rot_coeff(id_ch, gain, rad);


    return  stat;
}

/* end */
