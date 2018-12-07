/**
 * @file     dev_mmeadc01b_util.c
 * @brief    MME-ADC01-B: DEV API library utilities
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#include <stdio.h>                       /* printf()    */
#include <stdint.h>                      /* uint32_t    */
#include <string.h>                      /* memset()    */
#include <sys/time.h>                    /* timeval     */
#include <signal.h>                      /* sigaction   */
#include <semaphore.h>                   /* sem_wait()  */

#include "../mmeadc01b/mmeadc01b_defs.h" /* ioctl       */
#include "./dev_api_mmeadc01b.h"         /* own libraly */
#include "./dev_mmeadc01b_util.h"        /* utilities   */

/**
 * @struct dev_mmeadc01b_rot_coeff_t
 * @brief  Rotation coefficient
 */
typedef struct {
    double     gain;            /* gain amount                        */
    double     rad;             /* rotation angle theta (unit: [rad]) */
} dev_mmeadc01b_rot_coeff_t;

/**
 * @sturct dev_mmeadc01b_info_t
 * @brief  DEV API library info
 */
typedef struct {
    void                     (*cb)(int int_src);    /* callback function for interrupts */
    sem_t                      sem;
    uint32_t                   cmplt;               /* DMA xfer completion status       */
    dev_mmeadc01b_rot_coeff_t  rot[N_MMEADC01B_ROT_COEFF_IDS];
} dev_mmeadc01b_info_t;
static dev_mmeadc01b_info_t          dev_mmeadc01b_info = {
    .cb    = NULL,                 /* NULL:no cb function registed    */
    .cmplt = 0,                    /*    0:no data xfered             */
    .rot   = { { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 },
               { 1.0 , 0.0 }, },
};
#define _get_dev_mmeadc01b_info()  (&dev_mmeadc01b_info)

/**
 * @struct dev_mmeadc01b_reg_range_t
 * @brief  LUT for FPGA register address range
 */
typedef struct {
    int   id_bar;               /* BAR ID                   */
    int   base;                 /* base offset address      */
    int   len;                  /* adress range (unit: [B]) */
} dev_mmeadc01b_reg_range_t;
static const dev_mmeadc01b_reg_range_t  _mmeadc01b_fpga_range[] = {
    { BAR0, 0x00000000, LEN_MMEADC01B_BAR_0 }, /* BAR 0   */
    { BAR2, 0x00000000, LEN_MMEADC01B_BAR_2 }, /* BAR  2  */
    { BAR4, 0x00000000, LEN_MMEADC01B_BAR_4 }, /* BAR   4 */

    { -1 },                         /* -1 as a terminator */
};
#define _get_mmeadc01b_reg_range(idx_bar)  (_mmeadc01b_fpga_range)

/**
 * dev_mmeadc01b_check_fpga_reg_range()
 * @brief    check wtheather valid address or not ?
 *
 * @param    [in]   id_bar     int     ::= BAR<n>
 * @param    [in]   ofs        int     ::= offset address of FPGA register
 * @param    [in]   num        int     ::= # of registers to be read (shold be positive number)
 * @return          stat               ::= process status
 */
int
dev_mmeadc01b_check_fpga_reg_range(int id_bar, int ofs, int num)
{
    int                              stat    = MMEADC01B_ERR_RANGE;
    const dev_mmeadc01b_reg_range_t *range;
    int                              idx_bar = 0;
    int                              base;
    int                              end;
    int                              len;

    while (1) {
        range  = _get_mmeadc01b_reg_range() + idx_bar;
        if (range->id_bar == -1) { /* terminator found ? */
            break;                 /*  no more data      */
        }

        /*    base                    end
         *    /    ofs    ofs + len   /
         *   /     /      /          /
         *  +-----*======*----------+
         */
        if (id_bar  == range->id_bar) {                  /* BAR existed ?  */
            base     =        range->base;
            end      = base + range->len;
            len      = num  * sizeof(uint32_t);

            if ((base <= ofs) && ((ofs + len) <= end)) { /*  valid range ? */
                stat = MMEADC01B_ERR_OK;
                COUT(9, " %s():[L%4d]: id_bar=%d, ofs=%08X, len=%08X(%d) (%08X ~ %08X - 4)\n",
                     __func__, __LINE__, id_bar, ofs, len, num, base, end);
                break;
            }
        }
        idx_bar++;              /* next */
    }

    return  stat;
}


/**
 * dev_mmeadc01b_set_dma_xfer_cmplt()
 * @brief    set DMA xfer completion status
 *
 * @param    [in]   cmplt                 uint32_t ::= DMA xfer completion status
 * @return          stat                           ::= process status
 */
int
dev_mmeadc01b_set_dma_xfer_cmplt            (uint32_t cmplt)
{
    int                   stat =  0;
    dev_mmeadc01b_info_t *info = _get_dev_mmeadc01b_info();

    info->cmplt |=  cmplt;

    return  stat;
}

/**
 * dev_mmeadc01b_clr_dma_xfer_cmplt()
 * @brief    clear DMA xfer completion status
 *
 * @param    [in]   cmplt                 uint32_t ::= DMA xfer completion status to be cleared
 * @return          stat                           ::= process status
 */
int
dev_mmeadc01b_clr_dma_xfer_cmplt            (uint32_t cmplt)
{
    int                   stat =  0;
    dev_mmeadc01b_info_t *info = _get_dev_mmeadc01b_info();

    info->cmplt &= ~cmplt;

    return  stat;
}

/**
 * dev_mmeadc01b_get_dma_xfer_cmplt()
 * @brief    get DMA xfer completion status
 *
 * @param    - none -
 * @return          cmplt                 uint32_t ::= DMA xfer completion status
 */
uint32_t
dev_mmeadc01b_get_dma_xfer_cmplt            (void)
{
    dev_mmeadc01b_info_t *info = _get_dev_mmeadc01b_info();
    uint32_t              cmplt;

    cmplt       = info->cmplt;
    info->cmplt = 0;            /* auto cleared */

    return  cmplt;
}

/**
 * _dev_mmeadc01b_sig_action()
 * @brief    an action(signal handler) for SIGNAL from child driver
 *
 * @param    [in]   signo           int ::= signal number        (SIGUSR[12])
 * @param    [in]  *sinfo     siginfo_t ::= signal information   (/usr/include/bits/siginfo.h)
 * @param    [in]  *extra          void ::= extra  information
 * @return   - none -
 *
 * @date     2017-11-24
 * @authro   ymzk/tokki
 */
static void
_dev_mmeadc01b_sig_action(int signum, siginfo_t *sinfo, void *extra)
{
    dev_mmeadc01b_info_t *info = _get_dev_mmeadc01b_info();

    sem_wait(&info->sem);
    {
        void     (*cb)(int int_src) =  info->cb;
        uint32_t   occ_real         = sinfo->si_int;
        int        int_src          = (occ_real & INT_SRC_INTL) ? MMEADC01B_INT_SRC_INTL : MMEADC01B_INT_SRC_ACQ;

        if (cb) {               /* registered ? */
            cb(int_src);        /*  callback    */
        } else {
            printf(" %s():[L%4d]: no callback function found, signum=%d\n",
                   __func__, __LINE__, signum);
        }

        {
            uint32_t cmplt = MMEADC01B_CMPLT_AD | MMEADC01B_CMPLT_IO | MMEADC01B_CMPLT_SP;
            dev_mmeadc01b_set_dma_xfer_cmplt(cmplt);
        }
    }
    sem_post(&info->sem);
}

/**
 * dev_mmeadc01b_set_interrupt_callback()
 * @brief     register callback function which is called by signal handler
 *
 * @param     [in] *cb            void ::= callback function
 * @return          stat               ::= process status
 */
int
dev_mmeadc01b_set_interrupt_callback(void *cb)
{
    int                   stat =  0;
    dev_mmeadc01b_info_t *info = _get_dev_mmeadc01b_info();
    struct sigaction      act;

    if (cb != NULL ) {          /* register          ? */
        if (info->cb == NULL) { /*  no cb registered ? */
            /* register a callback function */
            info->cb  = cb;

            /* init. semaphore for SIGNAL handler */
            if (sem_init(&info->sem, 0, 1) < 0) {
                printf(" %s(): error sem_init()\n", __func__);
                return  MMEADC01B_ERR_INVALID;
            }

            /* register SIGNAL action to catch a SIGNAL from child driver */
            memset(&act, 0, sizeof(struct sigaction)); /* clear before config */
            act.sa_sigaction = _dev_mmeadc01b_sig_action;
            act.sa_flags     =  SA_SIGINFO;
            sigaction(SIGUSR1, &act, NULL);
        } else {
            printf(" %s():[L%4d]: cb has already benn registered.\n", __func__, __LINE__);
            printf(" %s():[L%4d]: you shold clear the cb first\n"   , __func__, __LINE__);
            return  MMEADC01B_ERR_INVALID;
        }
    } else {
        /* set default action */
        memset(&act, 0, sizeof(struct sigaction)); /* clear before config */
        act.sa_handler = SIG_DFL;
        sigaction(SIGUSR1, &act, NULL);

        /* clear semaphore */
        sem_destroy(&info->sem);

        /* clear the callback function */
        info->cb       = NULL;
    }

    return  stat;
}

/**
 * dev_mmeadc01b_set_util_rot_coeff()
 * @brief    set DMA xfer completion status
 *
 * @param    [in]   id_ch      int  ::= rotation coeff. ch ID
 * @param    [in]   gain     double ::= gain amount
 * @param    [in]   rad      double ::= rotation angle theta (unit: [rad])
 * @return          stat                           ::= process status
 */
int
dev_mmeadc01b_util_set_rot_coeff    (int id_ch, double  gain, double  rad)
{
    int                         stat =  0;
    dev_mmeadc01b_info_t       *info = _get_dev_mmeadc01b_info();
    dev_mmeadc01b_rot_coeff_t  *rot;

    if ((id_ch < 0) || (N_MMEADC01B_ROT_COEFF_IDS <= id_ch)) { /* out of range ? */
        return  MMEADC01B_ERR_RANGE;
    }

    rot       = info->rot + id_ch;
    rot->gain = gain;
    rot->rad  = rad;

    return  stat;
}

/**
 * dev_mmeadc01b_get_util_rot_coeff()
 * @brief    get DMA xfer completion status
 *
 * @param    - none -
 * @return          cmplt                 uint32_t ::= DMA xfer completion status
 */
int
dev_mmeadc01b_util_get_rot_coeff    (int id_ch, double *gain, double *rad)
{
    int                         stat =  0;
    dev_mmeadc01b_info_t       *info = _get_dev_mmeadc01b_info();
    dev_mmeadc01b_rot_coeff_t  *rot;

    if ((id_ch < 0) || (N_MMEADC01B_ROT_COEFF_IDS <= id_ch)) { /* out of range ? */
        return  MMEADC01B_ERR_RANGE;
    }

    rot       = info->rot + id_ch;
    *gain     =  rot->gain;
    *rad      =  rot->rad;

    return  stat;
}

/* end */
