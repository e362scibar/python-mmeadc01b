/**
 * @file     dev_mmeadc01b_set_rot_coeff.c
 * @brief    MME-ADC01-B: condifure rotation coefficients.
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

/* trignometric function: sin() or cos() */
typedef double (* trigfunc)(double rad);

/**
 * _mmeadc01b_set_rot_coeff_dac()
 * @brief    configure DAC rotation coefficients.
 *
 * @param    [in]   fd         int  ::= a file descriptor
 * @param    [in]   ch         int  ::= DAC rotation coeff. ch # (dummy / unused)
 * @param    [in]   gain     double ::= gain amount
 * @param    [in]   rad      double ::= rotation angle theta (unit: [rad])
 * @return          stat            ::= process status
 */
static int
_mmeadc01b_set_rot_coeff_dac                   (int fd, int    ch, double gain, double rad)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       id_bar    = BAR0;
    int       ofs;
    int       num       = 1;
    uint32_t  wdat;

    /* gain           */
    ofs  = MMEADC01B_REG_DAC_OUT_ROT_GAIN;
    wdat = gain * MMEADC01B_DAC_OUT_ROT_GAIN_LSB;  /* LSB = 2^12 */
    stat = dev_mmeadc01b_write(fd, id_bar, ofs, num, &wdat);

    /* rotation angle */
    ofs  = MMEADC01B_REG_DAC_OUT_ROT_THETA;
    wdat = rad * MMEADC01B_DAC_OUT_ROT_THETA_LSB; /* LSB = 2^15 */
    stat = dev_mmeadc01b_write(fd, id_bar, ofs, num, &wdat);

    return  stat;
}

/**
 * _mmeadc01b_calc_iq_rot_coeff()
 * @brief    calc rotation coeff.
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @param    [in]   ch     trigfunc ::= trignometric function (sin ot cos)
 * @param    [in]   gain     double ::= gain amount
 * @param    [in]   rad      double ::= rotation angle theta (unit: [rad])
 * @param    [out] *wdat   uint32_t ::= rotation coeff.
 * @return          stat    int     ::= process status
 */
int
_mmeadc01b_calc_iq_rot_coeff(double gain, trigfunc trig, double rad, uint32_t *wdat)
{
    int       stat      = MMEADC01B_ERR_OK;
    double    coeff;

    coeff = gain * trig(rad);
    if ((coeff <  MIN_MMEADC01B_REG_IQ_ROT_COEFF) ||
        (coeff >= MAX_MMEADC01B_REG_IQ_ROT_COEFF)    ) { /* out of range ? */
        COUT(1, "unsuported coeff A = %lf. (coeff must be %lf <= coeff < %lf\n",
             coeff, MIN_MMEADC01B_REG_IQ_ROT_COEFF, MAX_MMEADC01B_REG_IQ_ROT_COEFF);
        return  MMEADC01B_ERR_RANGE;
    }

    /* LSB = 1 / (2^14) */
    *wdat  = (uint32_t)(coeff * MMEADC01B_IQ_ROT_COEFF_LSB);

    return  stat;
}

/**
 * _mmeadc01b_set_rot_coeff_iq()
 * @brief    configure I/Q rotation coefficients.
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @param    [in]   ch         int  ::= I/Q rotation coeff. ch #
 * @param    [in]   gain     double ::= gain amount
 * @param    [in]   rad      double ::= rotation angle theta (unit: [rad])
 * @return          stat       int  ::= process status
 */
int
_mmeadc01b_set_rot_coeff_iq                    (int fd, int    ch, double gain, double rad)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       id_bar    = BAR4;
    int       ofs;
    int       num       = 1;
    uint32_t  wdat;

    if ((ch < 0) || (N_MMEADC01B_IQ_ROT_COEFF_CH <= ch)) { /* out of range ? */
        COUT(1, "unknown I/Q ch = %d.\n", ch);
        return  MMEADC01B_ERR_RANGE;
    }

    /*
     * rotation coefficients:
     *      I       A   B    I
     *    (   ) = (       )(   )
     *      Q       C   A    Q
     *
     *     legend:
     *        A = gain *  cosθ
     *        B = gain * -sinθ
     *        C = gain *  sinθ
     */

    /* A     =  gain *  cosθ */
    ofs      =  MMEADC01B_REG_IQ_ROT_COEFF_A(ch);
    stat     = _mmeadc01b_calc_iq_rot_coeff(gain, cos, rad, &wdat);
    if (stat <  0) {
        return  stat;
    }
    stat     =  dev_mmeadc01b_write(fd, id_bar, ofs, num, &wdat);

    /* C     =  gain *  sinθ */
    ofs      =  MMEADC01B_REG_IQ_ROT_COEFF_C(ch);
    stat     = _mmeadc01b_calc_iq_rot_coeff(gain, sin, rad, &wdat);
    if (stat <  0) {
        return  stat;
    }
    stat     =  dev_mmeadc01b_write(fd, id_bar, ofs, num, &wdat);

    /* B     =  gain * -sinθ */
    ofs      =  MMEADC01B_REG_IQ_ROT_COEFF_B(ch);
    wdat    *= -1;
    stat     =  dev_mmeadc01b_write(fd, id_bar, ofs, num, &wdat);

    return  stat;
}

/**
 * dev_mmeadc01b_set_rot_coeff()
 * @brief    configure rotation coefficients.
 *
 * @param    [in]   fd         int  ::= a file descriptor
 * @param    [in]   id_ch      int  ::= rotation coeff. ch ID
 * @param    [in]   gain     double ::= gain amount
 * @param    [in]   rad      double ::= rotation angle theta (unit: [rad])
 * @return          stat       int  ::= process status
 */
int
dev_mmeadc01b_set_rot_coeff                 (int fd, int id_ch, double  gain, double  rad)
{
    int       stat      = MMEADC01B_ERR_OK;
    int       ch;

    if (fd  <  0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    if ((id_ch < 0) || (N_MMEADC01B_ROT_COEFF_IDS <= id_ch)) { /* out of range ? */
        COUT(1, "unknown ID = %d.\n", id_ch);
        return  MMEADC01B_ERR_RANGE;
    }

    /* DAC or I/Q */
    if (id_ch ==  MMEADC01B_ROT_COEFF_ID_DAC) { /* rotation for DAC */
        ch     =  0;            /* 0:dummy */
        stat   = _mmeadc01b_set_rot_coeff_dac(fd, ch, gain, rad);
    } else {                                    /* rotation for I/Q */
        ch     =  id_ch - MMEADC01B_ROT_COEFF_ID_IQ_1;
        stat   = _mmeadc01b_set_rot_coeff_iq (fd, ch, gain, rad);
    }

    /* update latest coefficient */
    dev_mmeadc01b_util_set_rot_coeff(id_ch,  gain,  rad);

    return  stat;
}

/* end */
