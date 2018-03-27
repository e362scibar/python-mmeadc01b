/**
 * @file     dev_mmeadc01b_unregister_interrupt_callback
 * @brief    MME-ADC01-B: unregister callback function
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
#include "./dev_mmeadc01b_util.h"        /* utilities   */

/**
 * dev_mmeadc01b_unregister_interrupt_callback()
 * @brief    unregister callback function
 *
 * @param    [in]   fd      int     ::= a file descriptor
 * @return          stat            ::= process status
 */
int
dev_mmeadc01b_unregister_interrupt_callback (int fd)
{
    int     stat = MMEADC01B_ERR_OK;

    if (fd     < 0) {
        COUT(1, "<devfile> is not opened.\n");
        return  MMEADC01B_ERR_INVALID;
    }

    /* unregister callback */
    dev_mmeadc01b_set_interrupt_callback(NULL);

    /* request to clear a PID */
    stat       = ioctl(fd, MMEADC01B_CLR_PID , NULL);
    if (stat   < 0) {
        stat   = MMEADC01B_ERR_INVALID;
    }

    return  stat;
}

/* end */
