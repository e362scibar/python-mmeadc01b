/**
 * @file     dev_api_mmeadc01b_define.h
 * @brief    MME-ADC01-B: general MACROs
 *
 * @note
 *
 * @date     2017-11-16
 * @author   ymzk/tokki
 */

#ifndef    DEV_API_MMEADC01B_DEFINE_H
#define    DEV_API_MMEADC01B_DEFINE_H

#include "mmeadc01b_defs.h"                /* Child Driver   */

/* definitions */
#define  TRUE                 1
#define  FALSE                0

#define  YES                  1
#define  NO                   0

#define  ON                   1
#define  OFF                  0

#define  ENABLE               1
#define  DISABLE              0

#define  ACK                  1
#define  NAK                  0

#define  BIT31       0x80000000 /* bit pos: 31 */
#define  BIT30       0x40000000 /* bit pos: 30 */
#define  BIT29       0x20000000 /* bit pos: 29 */
#define  BIT28       0x10000000 /* bit pos: 28 */
#define  BIT27       0x08000000 /* bit pos: 27 */
#define  BIT26       0x04000000 /* bit pos: 26 */
#define  BIT25       0x02000000 /* bit pos: 25 */
#define  BIT24       0x01000000 /* bit pos: 24 */
#define  BIT23       0x00800000 /* bit pos: 23 */
#define  BIT22       0x00400000 /* bit pos: 22 */
#define  BIT21       0x00200000 /* bit pos: 21 */
#define  BIT20       0x00100000 /* bit pos: 20 */
#define  BIT19       0x00080000 /* bit pos: 19 */
#define  BIT18       0x00040000 /* bit pos: 18 */
#define  BIT17       0x00020000 /* bit pos: 17 */
#define  BIT16       0x00010000 /* bit pos: 16 */
#define  BIT15       0x00008000 /* bit pos: 15 */
#define  BIT14       0x00004000 /* bit pos: 14 */
#define  BIT13       0x00002000 /* bit pos: 13 */
#define  BIT12       0x00001000 /* bit pos: 12 */
#define  BIT11       0x00000800 /* bit pos: 11 */
#define  BIT10       0x00000400 /* bit pos: 10 */
#define  BIT9        0x00000200 /* bit pos:  9 */
#define  BIT8        0x00000100 /* bit pos:  8 */
#define  BIT7        0x00000080 /* bit pos:  7 */
#define  BIT6        0x00000040 /* bit pos:  6 */
#define  BIT5        0x00000020 /* bit pos:  5 */
#define  BIT4        0x00000010 /* bit pos:  4 */
#define  BIT3        0x00000008 /* bit pos:  3 */
#define  BIT2        0x00000004 /* bit pos:  2 */
#define  BIT1        0x00000002 /* bit pos:  1 */
#define  BIT0        0x00000001 /* bit pos:  0 */

/* log message
 *  LEVEL_COUT: defined in Makefile.
 *   level 9: all messages out (make sure huge amount of messages will be out)
 *   level 8: almost ioctl logs
 *   level 7: SG-desc DMA src/dst, TMtdrvPCIeDmac
 *   level 6:
 *   level 5:
 *   level 4:
 *   level 3:
 *   level 2:
 *   level 1: minimum: init()/prove()/open()/close()/remove()/exit()
 *   level 0: no log messages out w/o pr_err()
 */
#ifndef   LEVEL_COUT            /* undefined ?           */
# define  LEVEL_COUT         0  /*  0: no output         */
#endif

#if  (LEVEL_COUT > 0)
# define  COUT(level, fmt, ...)                 \
  do {                                          \
    if (level <= LEVEL_COUT)                    \
      printf(fmt, ##__VA_ARGS__);               \
  } while (0)
#else
# define  COUT(level, fmt, ...)
#endif

/* I2C */
#define  I2C_READ                          1 /* I2C communication direction: data from slave device */
#define  I2C_WRITE                         0 /* I2C communication direction: data to   slave device */

/* DMA xfer buffer */
#define  LEN_DMA_BUF_PER_CH        (64 << 10) /* 64 [kB] */

/* Interrupt sources */
#define  MMEADC01B_INT_SRC_ACQ             0 /* waveform acq done            */
#define  MMEADC01B_INT_SRC_INTL            1 /* interlock condition detected */

/* Rotation Coefficient IDs */
#define  MMEADC01B_ROT_COEFF_ID_DAC        0 /*  Rot Coeff ID: DAC            */
#define  MMEADC01B_ROT_COEFF_ID_IQ_1       1 /*  Rot Coeff ID: I/Q ch  1      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_2       2 /*  Rot Coeff ID: I/Q ch  2      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_3       3 /*  Rot Coeff ID: I/Q ch  3      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_4       4 /*  Rot Coeff ID: I/Q ch  4      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_5       5 /*  Rot Coeff ID: I/Q ch  5      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_6       6 /*  Rot Coeff ID: I/Q ch  6      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_7       7 /*  Rot Coeff ID: I/Q ch  7      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_8       8 /*  Rot Coeff ID: I/Q ch  8      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_9       9 /*  Rot Coeff ID: I/Q ch  9      */
#define  MMEADC01B_ROT_COEFF_ID_IQ_10     10 /*  Rot Coeff ID: I/Q ch 10      */
#define  N_MMEADC01B_ROT_COEFF_IDS        11 /* # of ratation coefficient IDs */

#endif  /* DEV_API_MMEADC01B_DEFINE_H */

/* end */
