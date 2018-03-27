/**
 * @file     dev_mmeadc01b_register_interrupt_callback.c
 * @brief    MME-ADC01-B: register callback function which is called signal handler
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
#include <sys/types.h>                   /* pid_t       */

#include "../mmeadc01b/mmeadc01b_defs.h" /* IOCTL cmd   */
#include "./dev_api_mmeadc01b.h"         /* own library */
#include "./dev_mmeadc01b_util.h"        /* utilities   */

/**
 * dev_mmeadc01b_register_interrupt_callback()
 * @brief    register callback function
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @param    [in]  *cb      void    ::= callback function
 * @param    [in]   pid     pid_t   ::= process ID which SIGNAL is sent.
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_register_interrupt_callback   (int fd, void *cb  , pid_t pid)
{
    int     stat = MMEADC01B_ERR_OK;

    if (fd     < 0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    /* register callback */
    dev_mmeadc01b_set_interrupt_callback(cb);

    /* pass the PID to driver */
    stat       = ioctl(fd, MMEADC01B_SET_PID , &pid);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_INVALID;
    }

    return  stat;
}

/* end */
