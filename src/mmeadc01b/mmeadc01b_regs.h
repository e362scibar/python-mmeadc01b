/**
 * @file     mmeadc01b_regs.h
 * @brief    MME-ADC01-B FPGA register map (2018-11-20 ver.)
 *
 * @note     updated for LLRF.
 *
 * @note     PCI BARs:
 *            BAR0: 0x7100 0000 ,,,
 *            BAR1: (no BAR)
 *            BAR2: 0x7200 0000 ...
 *            BAR3: (no BAR)
 *            BAR4: 0x7300 0000 ...
 *            BAR5: (no BAR)
 *
 * @date     2017-03-08
 * @author   ymzk/tokki/MELOS
 */

#ifndef    MMEADC01B_REGS_H
#define    MMEADC01B_REGS_H

/* MME-ADC01-B hardware info. */
#define    N_ADC_POINTS                           (16 << 10)             /* # of ADC sampling points/SRAM  16k[pt]  */
#define    N_DDC_POINTS                           ( 4 << 10)             /* # of DDC sampling points/SRAM   4k[pt]  */
#define    N_DAC_POINTS                           ( 8 << 10)             /* # of DAC sampling points/SRAM   8k[pt]  */
#define     N_SP_POINTS                           ( 4 << 10)             /* # of SP           points/SRAM   4k[pt]  */
#define   N_TONE_POINTS                           (     256)             /* # of CAL Tone     points/SRAM  256[pt]  */
#define    N_BPM_POINTS_TBT                       (64 << 10)             /* # of BPM COD TbT  points/SRAM  64k[pt]  */
#define    N_BPM_POINTS_FA                        (64 << 10)             /* # of BPM COD FA   points/SRAM  64k[pt]  */
#define    N_BPM_POINTS_SA                        (     256)             /* # of BPM COD SA   points/SRAM  256[pt]  */
#define    N_BPM_POINTS_SP                        (64 << 10)             /* # of BPM SP Proc  points/SRAM  64k[pt]  */

#define  LEN_ADC_DAT                          (N_ADC_POINTS      * 4)   /* length of ADC sampling data (unit: [B]) */
#define  LEN_DDC_DAT                          (N_DDC_POINTS      * 4)   /* length of DDC sampling data (unit: [B]) */
#define  LEN_DAC_DAT                          (N_DAC_POINTS      * 4)   /* length of DAC sampling data (unit: [B]) */
#define  LEN_SP_DAT                          (  N_SP_POINTS      * 4)   /* length of Single Path  data (unit: [B]) */
#define  LEN_TONE_DAT                        (N_TONE_POINTS *  8 * 4)   /* length of CAL Tone     data (unit: [B]) */
#define  LEN_BPM_DAT_TBT                 ( N_BPM_POINTS_TBT * 16 * 4)   /* length of BPM COD TbT  data (unit: [B]) */
#define  LEN_BPM_DAT_FA                  ( N_BPM_POINTS_FA  * 16 * 4)   /* length of BPM COD FA   data (unit: [B]) */
#define  LEN_BPM_DAT_SA                  ( N_BPM_POINTS_SA  * 32 * 4)   /* length of BPM COD SA   data (unit: [B]) */
#define  LEN_BPM_DAT_SP                  ( N_BPM_POINTS_SP  * 64 * 4)   /* length of BPM SP Proc  data (unit: [B]) */

#define  LEN_BPM_DAT_UNIT_TBT  (16 * 4)
#define  LEN_BPM_DAT_UNIT_FA   (16 * 4)
#define  LEN_BPM_DAT_UNIT_SA   (32 * 4)
#define  LEN_BPM_DAT_UNIT_SP   (64 * 4)

#define  LEN_BPM_DAT_SP_BLOCK            ( N_BPM_POINTS_SP  * 64    )   /* length of BPM SP Proc  data (unit: [B]) */

/*  - ADC                     */
#define  N_MMEADC01B_ADC_DEV                              5              /* # of ADCs imped on this board    */
#define  N_MMEADC01B_ADC_DEV_CH                           2              /* # of ADC channels which ADC has  */
#define  N_MMEADC01B_ADC_CH        (N_MMEADC01B_ADC_DEV * N_MMEADC01B_ADC_DEV_CH) /* total # of ADC channels */
/*  - DDC                     */
#define  N_MMEADC01B_DDC_DEV                              5              /* # of DDCs imped on this board    */
#define  N_MMEADC01B_DDC_DEV_CH                           2              /* # of DDC channels which has      */
#define  N_MMEADC01B_DDC_CH        (N_MMEADC01B_DDC_DEV * N_MMEADC01B_DDC_DEV_CH) /* total # of DDC channels */
#define  N_MMEADC01B_DDC_CH_IQ      N_MMEADC01B_DDC_CH                            /*  for   I/Q              */
/*  - DAC                     */
#define  N_MMEADC01B_DAC_DEV                              1              /* # of DACs imped on this board    */
#define  N_MMEADC01B_DAC_DEV_CH                           2              /* # of DAC channels which has      */
#define  N_MMEADC01B_DAC_CH        (N_MMEADC01B_DAC_DEV * N_MMEADC01B_DAC_DEV_CH) /* total # of DAC channels */

/*  - data channels           */
#define  ADC_CH_1                                         0  /* ADC channels */
#define  ADC_CH_2                                         1
#define  ADC_CH_3                                         2
#define  ADC_CH_4                                         3
#define  ADC_CH_5                                         4
#define  ADC_CH_6                                         5
#define  ADC_CH_7                                         6
#define  ADC_CH_8                                         7
#define  ADC_CH_9                                         8
#define  ADC_CH_10                                        9
#define  DDC_CH_IQ_1                                     10  /* DDC channels */
#define  DDC_CH_IQ_2                                     11
#define  DDC_CH_IQ_3                                     12
#define  DDC_CH_IQ_4                                     13
#define  DDC_CH_IQ_5                                     14
#define  DDC_CH_IQ_6                                     15
#define  DDC_CH_IQ_7                                     16
#define  DDC_CH_IQ_8                                     17
#define  DDC_CH_IQ_9                                     18
#define  DDC_CH_IQ_10                                    19
#define  DDC_CH_IQ_11                                    20  /*  I/Q ch 11: I ch 24-bit long */
#define  DDC_CH_IQ_12                                    21  /*  I/Q ch 12: Q ch 24-bit long */
#define  DDC_CH_IQ_13                                    22  /*  I/Q ch 13: (unused)         */
#define  DDC_CH_IQ_14                                    23  /*  I/Q ch 14: (unused)         */
#define  DDC_CH_IQ_15                                    24  /*  I/Q ch 15: (unused)         */
#define  DDC_CH_IQ_16                                    25  /*  I/Q ch 16: (unused)         */
#define  SP_CH_1                                         26  /* SP  channels */
#define  SP_CH_2                                         27
#define  SP_CH_3                                         28
#define  SP_CH_4                                         29
#define  SP_CH_7                                         30
#define  SP_CH_8                                         31
#define  SP_CH_9                                         32
#define  SP_CH_10                                        33
#define  TONE_CH_1                                       34  /* CAL Tone ch */
#define  TONE_CH_2                                       35
#define  TONE_CH_3                                       36
#define  TONE_CH_4                                       37
#define  TONE_CH_5                                       38
#define  TONE_CH_6                                       39
#define  TONE_CH_7                                       40
#define  TONE_CH_8                                       41
#define  TONE_CH_9                                       42
#define  TONE_CH_10                                      43
//#define  N_MMEADC01B_CH                                  44  /* total # of channels on MME-ADC01-B */

#define  BPM_CH_1_TBT                                    44
#define  BPM_CH_1_FA                                     45
#define  BPM_CH_1_SA                                     46
#define  BPM_CH_1_SP_1                                   47 /* BPM 1  > SP Process: 1    of 4 */
#define  BPM_CH_1_SP_2                                   48 /* BPM 1  > SP Process:  2   of 4 */
#define  BPM_CH_1_SP_3                                   49 /* BPM 1  > SP Process:   3  of 4 */
#define  BPM_CH_1_SP_4                                   50 /* BPM 1  > SP Process:    4 of 4 */
#define  BPM_CH_2_TBT                                    51
#define  BPM_CH_2_FA                                     52
#define  BPM_CH_2_SA                                     53
#define  BPM_CH_2_SP_1                                   54 /* BPM  2 > SP Process: 1    of 4 */
#define  BPM_CH_2_SP_2                                   55 /* BPM  2 > SP Process:  2   of 4 */
#define  BPM_CH_2_SP_3                                   56 /* BPM  2 > SP Process:   3  of 4 */
#define  BPM_CH_2_SP_4                                   57 /* BPM  2 > SP Process:    4 of 4 */
#define  N_MMEADC01B_CH                                  58  /* total # of channels on MME-ADC01-B */

#define  N_ADC_CH                                        10      /* ADC: 5 devices x 2 ch           */
#define  N_DDC_CH                                        16      /* DDC: ADC 10ch + 6 extra ch      */
#define  N_SP_CH                                  (N_ADC_CH - 2) /* -2: ch 5 and 6                  */
#define  N_TONE_CH                                       10      /* same as ADC channels            */
#define  N_TONE1_CH                                       5      /* CAL Tone 1-5                    */
#define  N_TONE2_CH                                       5      /* CAL Tone 6-10                   */
#define  N_BPM_CH                                         2      /* BPM1 and BPM2                   */
#define  N_BPM_SP_BLOCKS                                  4      /* SP Process consists of 4 blocks */

/*  - DATA acq. channels      */
/*
 *    6 6 6 6 5 5 5 5 5 5 5 5 5 5 4 4 4 4 4 4 4 4 4 4 3 3 3 3 3 3 3 3
 *    3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2
 *   +-----------+---+---------+-----+-------+-------+-----------+---+
 *   |           |    BPM 2    |    BPM 1    |                   |SP |
 *   | (_RSVD_)  |S|S|S|S|S|F|T|S|S|S|S|S|F|T| CAL Tone ch 10-1  |ch |
 *   |           |P|P|P|P|A|A|b|P|P|P|P|A|A|b|                   |10 |
 *   |           |4|3|2|1| | |T|4|3|2|1| | |T|                   | -9|
 *   +-----------+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-------+-----------+---+
 *
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-----------+---+-------+-------+-----------+---+---------------+
 *   | SP        | DDC extra |                   |                   |
 *   |   ch 8-7  |  ch 15-11 | DDC ch 10-1/base  | ADC ch 10-1       |
 *   |      4-1  |  (I/Q)    |  (I/Q)            |  (RAW)            |
 *   +-----------+---+-------+-------+-----------+---+---------------+
 *             bit 63-46: _(_Reseved_)
 *             bit 45   : BPM2
 *             bit 44   : BPM1
 *             bit 43-36: SP        ch 10/9/8/7/4/3/2/1
 *             bit 35-26: CAL Tone  ch 10-1
 *             bit 25-20: DDC       ch 16-11 (I/Q) extra-data (internally generated)
 *             bit 19-10: DDC       ch 10-1  (I/Q)  base
 *             bit  9-0 : ADC       ch 10-1
 */
#define  DAT_CH_ADC_1                                  BIT0
#define  DAT_CH_ADC_2                                  BIT1
#define  DAT_CH_ADC_3                                  BIT2
#define  DAT_CH_ADC_4                                  BIT3
#define  DAT_CH_ADC_5                                  BIT4
#define  DAT_CH_ADC_6                                  BIT5
#define  DAT_CH_ADC_7                                  BIT6
#define  DAT_CH_ADC_8                                  BIT7
#define  DAT_CH_ADC_9                                  BIT8
#define  DAT_CH_ADC_10                                 BIT9

#define  DAT_CH_DDC_IQ_1                              BIT10
#define  DAT_CH_DDC_IQ_2                              BIT11
#define  DAT_CH_DDC_IQ_3                              BIT12
#define  DAT_CH_DDC_IQ_4                              BIT13
#define  DAT_CH_DDC_IQ_5                              BIT14
#define  DAT_CH_DDC_IQ_6                              BIT15
#define  DAT_CH_DDC_IQ_7                              BIT16
#define  DAT_CH_DDC_IQ_8                              BIT17
#define  DAT_CH_DDC_IQ_9                              BIT18
#define  DAT_CH_DDC_IQ_10                             BIT19
#define  DAT_CH_DDC_IQ_11                             BIT20
#define  DAT_CH_DDC_IQ_12                             BIT21
#define  DAT_CH_DDC_IQ_13                             BIT22
#define  DAT_CH_DDC_IQ_14                             BIT23
#define  DAT_CH_DDC_IQ_15                             BIT24
#define  DAT_CH_DDC_IQ_16                             BIT25

#define  DAT_CH_SP_1                                  BIT26
#define  DAT_CH_SP_2                                  BIT27
#define  DAT_CH_SP_3                                  BIT28
#define  DAT_CH_SP_4                                  BIT29
#define  DAT_CH_SP_7                                  BIT30
#define  DAT_CH_SP_8                                  BIT31
#define  DAT_CH_SP_9                                  BIT32
#define  DAT_CH_SP_10                                 BIT33

#define  DAT_CH_TONE_1                                BIT34
#define  DAT_CH_TONE_2                                BIT35
#define  DAT_CH_TONE_3                                BIT36
#define  DAT_CH_TONE_4                                BIT37
#define  DAT_CH_TONE_5                                BIT38
#define  DAT_CH_TONE_6                                BIT39
#define  DAT_CH_TONE_7                                BIT40
#define  DAT_CH_TONE_8                                BIT41
#define  DAT_CH_TONE_9                                BIT42
#define  DAT_CH_TONE_10                               BIT43

#define  DAT_CH_BPM_1_TBT                             BIT44
#define  DAT_CH_BPM_1_FA                              BIT45
#define  DAT_CH_BPM_1_SA                              BIT46
#define  DAT_CH_BPM_1_SP_1                            BIT47
#define  DAT_CH_BPM_1_SP_2                            BIT48
#define  DAT_CH_BPM_1_SP_3                            BIT49
#define  DAT_CH_BPM_1_SP_4                            BIT50
#define  DAT_CH_BPM_2_TBT                             BIT51
#define  DAT_CH_BPM_2_FA                              BIT52
#define  DAT_CH_BPM_2_SA                              BIT53
#define  DAT_CH_BPM_2_SP_1                            BIT54
#define  DAT_CH_BPM_2_SP_2                            BIT55
#define  DAT_CH_BPM_2_SP_3                            BIT56
#define  DAT_CH_BPM_2_SP_4                            BIT57

#define  DAT_CH_ADC                              0x000003FF  /* bit  9-0  */
#define  DAT_CH_DDC                              0x03FFFC00  /* bit 25-10 */
#define  DAT_CH_SP            __UINT64_C(0x00000003FC000000) /* bit 43-36 */
#define  DAT_CH_TONE1         __UINT64_C(0x0000007C00000000) /* bit 30-26 */
#define  DAT_CH_TONE2         __UINT64_C(0x00000F8000000000) /* bit 35-31 */
#define  DAT_CH_BPM1_TBT      __UINT64_C(0x0000100000000000) /* bit 44    */
#define  DAT_CH_BPM1_FA       __UINT64_C(0x0000200000000000) /* bit 45    */
#define  DAT_CH_BPM1_SA       __UINT64_C(0x0000400000000000) /* bit 46    */
#define  DAT_CH_BPM1_SP1      __UINT64_C(0x0000800000000000) /* bit 47    */
#define  DAT_CH_BPM1_SP2      __UINT64_C(0x0001000000000000) /* bit 48    */
#define  DAT_CH_BPM1_SP3      __UINT64_C(0x0002000000000000) /* bit 49    */
#define  DAT_CH_BPM1_SP4      __UINT64_C(0x0004000000000000) /* bit 50    */
#define  DAT_CH_BPM2_TBT      __UINT64_C(0x0008000000000000) /* bit 51    */
#define  DAT_CH_BPM2_FA       __UINT64_C(0x0010000000000000) /* bit 52    */
#define  DAT_CH_BPM2_SA       __UINT64_C(0x0020000000000000) /* bit 53    */
#define  DAT_CH_BPM2_SP1      __UINT64_C(0x0040000000000000) /* bit 54    */
#define  DAT_CH_BPM2_SP2      __UINT64_C(0x0080000000000000) /* bit 55    */
#define  DAT_CH_BPM2_SP3      __UINT64_C(0x0100000000000000) /* bit 56    */
#define  DAT_CH_BPM2_SP4      __UINT64_C(0x0200000000000000) /* bit 57    */
#define  DAT_CH_ACQ                     (DAT_CH_ADC | DAT_CH_DDC | DAT_CH_SP)

/*
 * INT_SRC:
 * INT_CLR:
 * INT_MSK:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-+-+-----------+---------------+---------------+-------+-+-+-+-+
 *   |D|I|                                                     |S|I|A|
 *   |M|N|             (_Reserved_)                            |P|/|D|
 *   |A|T|                                                     | |Q|C|
 *   | |L|                                                     | | | |
 *   +-+-+-----------+---------------+---------------+-------+-+-+-+-+
 *             bit 31   : DMA
 *             bit 30   : Interlock
 *             bit 29-3 : (_Reserved_)
 *             bit  2   : SP  ch
 *             bit  1   : I/Q ch
 *             bit  0   : ADC ch
 */

/*
 * CMPLT_SRC:
 * CMPLT_CLR:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +---------------+-+-----+-+-+-+-+-+-------+-+-+-+---+---+-------+
 *   |                 |    BPM2     |R|    BPM1     | R | T |       |
 *   |  (_Reserverd_)  |S|S|S|S|S|F|T|S|S|S|S|S|S|F|T| S | o | _RSVD_|
 *   |                 |P|P|P|P|A|A|b|V|P|P|P|P|A|A|b| V | n |       |
 *   |                 |4|3|2|1| | |T|D|4|3|2|1| | |T| D | e |       |
 *   +---------------+-+-----+-+-+-+-+-+-------+-+-+-+---+---+-------+
 *             bit 31-23: (_Reserved_)
 *             bit 22   : BPM  2 SP Process (4 of 4)
 *             bit 21   : BPM  2 SP Process (3 of 4)
 *             bit 20   : BPM  2 SP Process (2 of 4)
 *             bit 19   : BPM  2 SP Process (1 of 4)
 *             bit 18   : BPM  2 COD SA
 *             bit 17   : BPM  2 COD FA
 *             bit 16   : BPM  2 COD TbT
 *             bit 15   : (_Reserved_)
 *             bit 14   : BPM 1  SP Process (4 of 4)
 *             bit 13   : BPM 1  SP Process (3 of 4)
 *             bit 12   : BPM 1  SP Process (2 of 4)
 *             bit 11   : BPM 1  SP Process (1 of 4)
 *             bit 10   : BPM 1  COD SA
 *             bit  9   : BPM 1  COD FA
 *             bit  8   : BPM 1  COD TbT
 *             bit  7-6 : (_Reserved_)
 *             bit  5   : CAL Tone ch 1-5
 *             bit  4   : CAL Tone ch 6-10
 *             bit  3-0 : (_Reserved_)
 */
#define  INT_SRC_NONE                                     0 /* no interrupt occured */

#define  INT_SRC_DMA                                  BIT31
#define  INT_SRC_INTL                                 BIT30

#define  INT_SRC_BPM2_SP_PROC4                        BIT22
#define  INT_SRC_BPM2_SP_PROC3                        BIT21
#define  INT_SRC_BPM2_SP_PROC2                        BIT20
#define  INT_SRC_BPM2_SP_PROC1                        BIT19
#define  INT_SRC_BPM2_COD_SA                          BIT18
#define  INT_SRC_BPM2_COD_FA                          BIT17
#define  INT_SRC_BPM2_COD_TBT                         BIT16

#define  INT_SRC_BPM1_SP_PROC4                        BIT14
#define  INT_SRC_BPM1_SP_PROC3                        BIT13
#define  INT_SRC_BPM1_SP_PROC2                        BIT12
#define  INT_SRC_BPM1_SP_PROC1                        BIT11
#define  INT_SRC_BPM1_COD_SA                          BIT10
#define  INT_SRC_BPM1_COD_FA                           BIT9
#define  INT_SRC_BPM1_COD_TBT                          BIT8

#define  INT_SRC_TONE2                                 BIT5
#define  INT_SRC_TONE1                                 BIT4
#define  INT_SRC_SP                                    BIT2
#define  INT_SRC_DDC                                   BIT1
#define  INT_SRC_ADC                                   BIT0

#define  INT_SRC_BPM2_SP_PROC                  (INT_SRC_BPM2_SP_PROC1 | INT_SRC_BPM2_SP_PROC2 | INT_SRC_BPM2_SP_PROC3 | INT_SRC_BPM2_SP_PROC4)
#define  INT_SRC_BPM1_SP_PROC                  (INT_SRC_BPM1_SP_PROC1 | INT_SRC_BPM1_SP_PROC2 | INT_SRC_BPM1_SP_PROC3 | INT_SRC_BPM1_SP_PROC4)

#define  INT_SRC_TONE                          (INT_SRC_TONE1 | INT_SRC_TONE2)                                                                         /* CAL Tones                             */

#define  INT_SRC_ACQ                           (INT_SRC_ADC   | INT_SRC_DDC  )                                                                         /*            ADC + I/Q                  */
#define  INT_SRC_WFM                           (INT_SRC_ADC   | INT_SRC_DDC   | INT_SRC_SP)                                                            /* waveforms (ADC + I/Q + SP)            */
#define  INT_SRC_MISC                          (INT_SRC_ADC   | INT_SRC_DDC   | INT_SRC_SP | INT_SRC_TONE | INT_SRC_BPM1_COD_SA | INT_SRC_BPM2_COD_SA) /* waveforms + CAL Tone + BPM[12] COD SA */

/* register map */
/* ************************************************************: BAR 0 */
#define  LEN_MMEADC01B_BAR_0                      (64 << 10)             /* BAR 0:  64 [kB]     */

/*  BAR 0: base control */
/*
 *  FPGA_VER:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-------+-------+---------------+---------------+---------------+
 *   | PCB   |  year |      month    |      day      |   sequence #  |
 *   +-------+-------+---------------+---------------+---------------+
 *             bit 31-28: PCB revision                       (1:revA/FY16, 2:revB/FY17)
 *             bit 27-24: FPGA built year/last one digit/BCD (e.g.: 2018 -> 8)
 *             bit 23-16: FPGA built month              /BCD (01-12)
 *             bit 15-8 : FPGA built day                /BCD (01-31)
 *             bit  7-0 : sequence #                    /BCD (01-99)
 */
#define  MMEADC01B_REG_FPGA_VER                  0x0000D000              /* FPGA_VER          */
#define  MMEADC01B_REG_PCB_REV(ver_fpga) (((ver_fpga) >> 28) & 0x0F)
#define  MMEADC01B_PCB_REV_A                              1
#define  MMEADC01B_PCB_REV_B                              2

#define  MMEADC01B_REG_RST_WDT                   0x0000D008              /* RST_WDT           */
#define  MMEADC01B_REG_WDT_CNT                   0x0000D00C              /* WDT_CNT           */

/*
 *  FPGA_VER:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +---------------+---------------+---------------+-------+---+---+
 *   |                          (_Reserved_)                 | R | G |
 *   +---------------+---------------+---------------+-------+---+---+
 *             bit 31-4 : (_Reserved_)
 *             bit  3-2 : RED   LED      (0:off, 1-2:blink, 3:on)
 *             bit  1-0 : Green LED      (0:off, 1-2:blink, 3:on)
 */
#define  MMEADC01B_REG_LED                       0x0000D010              /* LED               */
#define                LED_RED                 (BIT3 | BIT2)             /*  - Green LED      */
#define                LED_GREEN               (BIT1 | BIT0)             /*  - Red   LED      */
#define                LED_KEEP                          -1              /*  - LED kepp state */
#define                LED_OFF                            0              /*  - LED off        */
#define                LED_BLINK                          1              /*  - LED blink      */
#define                LED_ON                             3              /*  - LED on         */

#define  MMEADC01B_REG_CLK_SEL                   0x0000D018              /* CLK_SEL           */
#define  MMEADC01B_CLK_EXT                                0              /*  - External clock */
#define  MMEADC01B_CLK_RTM0                               1              /*  - from RTM 0     */
#define  MMEADC01B_CLK_RTM1                               2              /*  - from RTM  1    */
#define  MMEADC01B_CLK_INT                                3              /*  - Internal clock */

/*  BAR 0: External DI/DO */
#define  MMEADC01B_REG_DI                        0x0000D020              /* DI                */
#define  MMEADC01B_REG_DO                        0x0000D024              /* DO                */
#define  MMEADC01B_REG_OEN                       0x0000D028              /* OEN               */
#define  MMEADC01B_REG_DI_INV                    0x0000D02C              /* DI_INV            */

#define  MMEADC01B_REG_DO_MODE0                  0x0000D030              /* DO_MODE0          */
#define  MMEADC01B_REG_DO_MODE1                  0x0000D034              /* DO_MODE1          */

/*  BAR 0: trigger counter */
#define  MMEADC01B_REG_TRIGCNT_INIT              0x0000D040              /* TRIGCNT_INIT      */
#define  MMEADC01B_REG_TRIGCNT_CLR               0x0000D044              /* TRIGCNT_CLR       */
#define  MMEADC01B_REG_TRIGCNT                   0x0000D048              /* TRIGCNT           */
#define  MMEADC01B_REG_TRIGCNT_INTL              0x0000D04C              /* TRIGCNT_INTL      */
#define  MMEADC01B_REG_TRIGCNT_DI                0x0000D050              /* TRIGCNT_DI        */
#define  MMEADC01B_REG_TRIGCNT_DI_CLR_EN         0x0000D054              /* TRIGCNT_DI_CLR_EN */

/*  BAR 0: interrupts */
#define  MMEADC01B_REG_INT_SRC                   0x0000D060              /* INT_SRC            */
#define  MMEADC01B_REG_INT_CLR                   0x0000D064              /* INT_CLR            */
#define  MMEADC01B_REG_INT_MSK                   0x0000D068              /* INT_MSK            */

/*  BAR 0: DAC > trigger select */
#define  MMEADC01B_REG_DAC_TRIG_FORCED           0x0000D080              /* DAC_TRIG_FORCED    */
#define  MMEADC01B_REG_DAC_DI_TRIG_EN            0x0000D084              /* DAC_DI_TRIG_EN     */
#define  MMEADC01B_REG_DAC_SELF_TRIG_EN          0x0000D088              /* DAC_SELF_TRIG_EN   */

/*  BAR 0: DAC > output control */
#define  MMEADC01B_REG_DAC_OUT_SEL               0x0000D090              /* DAC_OUT_SEL        */

//#define  MMEADC01B_REG_DAC_OUT_SW_ON           0x0000D094              /* DAC_OUT_SW_ON      */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_PAT_STEP            0x0000D098              /* DAC_PAT_STEP       */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_PAT_DELAY           0x0000D09C              /* DAC_PAT_DELAY      */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_PAT_REPEAT          0x0000D0A0              /* DAC_PAT_REPEAT     */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_PAT_DEPTH           0x0000D0A4              /* DAC_PAT_DEPTH      */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_PAT_UPD             0x0000D0A8              /* DAC_PAT_UPD        */ // no BPM supported:
//
//#define  MMEADC01B_REG_DAC_OUT_ROT_GAIN        0x0000D0B0              /* DAC_OUT_ROT_GAIN   */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_OUT_ROT_THETA       0x0000D0B4              /* DAC_OUT_ROT_THETA  */ // no BPM supported:
//
//#define  MMEADC01B_DAC_OUT_ROT_GAIN_LSB            0x1000              /*  LSB = 2^12        */ // no BPM supported:
//#define  MMEADC01B_DAC_OUT_ROT_THETA_LSB           0x8000              /*  LSB = 2^15        */ // no BPM supported:
//
//#define  MMEADC01B_REG_DAC_OUT_LIMIT           0x0000D0BC              /* DAC_OUT_LIMIT      */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_OUT_OFS             0x0000D0C0              /* DAC_OUT_OFS        */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_OUT_STEP            0x0000D0C4              /* DAC_OUT_STEP       */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_OUT_DELAY           0x0000D0C8              /* DAC_OUT_DELAY      */ // no BPM supported:
//#define  MMEADC01B_REG_DAC_OUT_SW_STATUS       0x0000D0D0              /* DAC_OUT_SW_STATUS  */ // no BPM supported:

/*  BAR 0: periperal device I/Fs */
#define  MMEADC01B_REG_ADC_ST(  id_adc )  (0x0000E000 + ((id_adc) * 16)) /* ADC_ST ( id_adc )  */
#define  MMEADC01B_REG_ADC_WR(  id_adc )  (0x0000E004 + ((id_adc) * 16)) /* ADC_WR ( id_adc )  */
#define  MMEADC01B_REG_ADC_RD(  id_adc )  (0x0000E008 + ((id_adc) * 16)) /* ADC_RD ( id_adc )  */

#define  MMEADC01B_REG_DAC_ST                    0x0000E050              /* DAC_ST             */
#define  MMEADC01B_REG_DAC_WR                    0x0000E054              /* DAC_WR             */
#define  MMEADC01B_REG_DAC_RD                    0x0000E058              /* DAC_RD             */

#define  MMEADC01B_REG_LMK_ST                    0x0000E060              /* LMK_ST             */
#define  MMEADC01B_REG_LMK_WR                    0x0000E064              /* LMK_WR             */

#define  MMEADC01B_REG_USR_I2C_CMD               0x0000E070              /* USR_I2C_CMD        */
#define  USR_I2C_CMD_NOP                                  0              /*  cmd: NOP          */
#define  USR_I2C_CMD_START                                1              /*  cmd: START        */
#define  USR_I2C_CMD_TX                                   2              /*  cmd: Byte write   */
#define  USR_I2C_CMD_RX                                   3              /*  cmd: Byte read    */
#define  USR_I2C_CMD_STOP                                 4              /*  cmd: STOP         */
#define  USR_I2C_CMD_ACK                                  5              /*  cmd: ACK          */
#define  MMEADC01B_REG_USR_I2C_WR                0x0000E074              /* USR_I2C_WR         */
#define  USR_I2C_ACK                                      0              /*  issue ACK         */
#define  USR_I2C_NAK                                  BIT16              /*  issue NAK         */
#define  MMEADC01B_REG_USR_I2C_RD                0x0000E078              /* USR_I2C_RD         */

#define  MMEADC01B_REG_JESD204B_RST              0x0000E080              /* JESD204B_RST       */
#define  MMEADC01B_REG_GTX_RST                   0x0000E084              /* GTX_RST            */

#define  MMEADC01B_REG_F_CYCLIC_PW               0x0000E0A0              /* F_CYCLIC_PW        */
#define  MMEADC01B_REG_F_CYCLIC_PORT             0x0000E0A4              /* F_CYCLIC_PORT      */

/*  BAR 0: for debug purpose */
/*
 * MME-ADC01-B kernel driver configuration registers
 * (Software Configuration)
 *
 *  SW_CONFIG_0:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-----------------------------------------------------------+-+-+
 *   |                                                           |D|M|
 *   |                    (_Reserved_)                           |M|E|
 *   |                                                           |A|M|
 *   +-----------------------------------------------------------+-+-+
 *             bit 31-2 : (_Reserved_)
 *             bit  1   :  repeated DMA xfer                 (0:repeat, 1:single)
 *             bit  0   :  select memory device for DDC data (0:SRAM  , 1:SDRAM )   (unused)
 *
 *  SW_CONFIG_1:
 *  SW_CONFIG_2:
 *  SW_CONFIG_3:
 *             bit 31-0 : (_Reserved_)
 */
#define  MMEADC01B_REG_SW_CONFIG_0               0x0000E0BC
#define  MMEADC01B_DDC_MEM_SDRAM                       BIT0 /* (unused) */
#define  MMEADC01B_DDC_MEM_SRAM                           0 /* (unused) */

#define  MMEADC01B_DMA_XFER_REPEAT                     BIT1
#define  MMEADC01B_DMA_XFER_SINGLE                        0

#define  N_MMEADC01B_SW_CONFIG_REG_0                      0
#define  N_MMEADC01B_SW_CONFIG_REGS                       1

#define  N_MMEADC01B_REG_SW_CONFIG(id_swconf)   (MMEADC01B_REG_SW_CONFIG_0 + ((id_swconf) * 4))

/*  BAR 0: waveform acquisition */
#define  MMEADC01B_REG_ADC_REC_START             0x0000F000              /* ADC_REC_START/SRAM */

#define  MMEADC01B_REG_WAVE_SMPL_STEP            0x0000F004              /* _WAVE_SMPL_STEP    */
#define  MMEADC01B_REG_WAVE_TRIG_DELAY           0x0000F008              /* _WAVE_TRIG_DELAY   */

/*
 * 31 30          16 15             0
 * +-+--------------+----------------+
 * |W|     current offset address    |
 * +-+--------------+----------------+
 *
 *   bit 31  : wrapped            ... 0:no wrapped, 1:wrapped
 *   bit 30-0: current ofs addr   ... offset address of latast data
 */
#define  MMEADC01B_REG_ADC_ADDR                  0x0000F010              /* ADC_IDX            */
#define  MMEADC01B_REG_IQ_ADDR                   0x0000F014              /* I_Q_IDX            */

#define  MMEADC01B_IDX_WRAPPED                        BIT31              /* wrap around or not */

/*  BAR 0: waveform > trigger mode */
#define  MMEADC01B_REG_TRIG_FORCED               0x0000F020              /* TRIG_FORCED        */
#define  MMEADC01B_REG_DI_TRIG_EN                0x0000F024              /* DI_TRIG_EN         */
#define  MMEADC01B_REG_SELF_TRIG_EN              0x0000F028              /* SELF_TRIG_EN       */

/*  BAR 0: waveform > threshold for self trigger  */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC01    0x0000F030              /* THOLD_SELFTRIG_H_ADC01 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC02    0x0000F034              /* THOLD_SELFTRIG_H_ADC02 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC03    0x0000F038              /* THOLD_SELFTRIG_H_ADC03 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC04    0x0000F03C              /* THOLD_SELFTRIG_H_ADC04 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC05    0x0000F040              /* THOLD_SELFTRIG_H_ADC05 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC06    0x0000F044              /* THOLD_SELFTRIG_H_ADC06 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC07    0x0000F048              /* THOLD_SELFTRIG_H_ADC07 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC08    0x0000F04C              /* THOLD_SELFTRIG_H_ADC08 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC09    0x0000F050              /* THOLD_SELFTRIG_H_ADC09 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC10    0x0000F054              /* THOLD_SELFTRIG_H_ADC10 */

#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC01    0x0000F058              /* THOLD_SELFTRIG_L_ADC01 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC02    0x0000F05C              /* THOLD_SELFTRIG_L_ADC02 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC03    0x0000F060              /* THOLD_SELFTRIG_L_ADC03 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC04    0x0000F064              /* THOLD_SELFTRIG_L_ADC04 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC05    0x0000F068              /* THOLD_SELFTRIG_L_ADC05 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC06    0x0000F06C              /* THOLD_SELFTRIG_L_ADC06 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC07    0x0000F070              /* THOLD_SELFTRIG_L_ADC07 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC08    0x0000F074              /* THOLD_SELFTRIG_L_ADC08 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC09    0x0000F078              /* THOLD_SELFTRIG_L_ADC09 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC10    0x0000F07C              /* THOLD_SELFTRIG_L_ADC10 */

#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ01     0x0000F080              /* THOLD_SELFTRIG_H_IQ01 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ02     0x0000F084              /* THOLD_SELFTRIG_H_IQ02 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ03     0x0000F088              /* THOLD_SELFTRIG_H_IQ03 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ04     0x0000F08C              /* THOLD_SELFTRIG_H_IQ04 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ05     0x0000F090              /* THOLD_SELFTRIG_H_IQ05 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ06     0x0000F094              /* THOLD_SELFTRIG_H_IQ06 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ07     0x0000F098              /* THOLD_SELFTRIG_H_IQ07 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ08     0x0000F09C              /* THOLD_SELFTRIG_H_IQ08 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ09     0x0000F0A0              /* THOLD_SELFTRIG_H_IQ09 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ10     0x0000F0A4              /* THOLD_SELFTRIG_H_IQ10 */

#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ01     0x0000F0A8              /* THOLD_SELFTRIG_L_IQ01 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ02     0x0000F0AC              /* THOLD_SELFTRIG_L_IQ02 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ03     0x0000F0B0              /* THOLD_SELFTRIG_L_IQ03 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ04     0x0000F0B4              /* THOLD_SELFTRIG_L_IQ04 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ05     0x0000F0B8              /* THOLD_SELFTRIG_L_IQ05 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ06     0x0000F0BC              /* THOLD_SELFTRIG_L_IQ06 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ07     0x0000F0C0              /* THOLD_SELFTRIG_L_IQ07 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ08     0x0000F0C4              /* THOLD_SELFTRIG_L_IQ08 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ09     0x0000F0C8              /* THOLD_SELFTRIG_L_IQ09 */
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ10     0x0000F0CC              /* THOLD_SELFTRIG_L_IQ10 */

#define  MMEADC01B_REG_THOLD_SELFTRIG_H_ADC(ch) (MMEADC01B_REG_THOLD_SELFTRIG_H_ADC01 + ((ch) * 4))
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_ADC(ch) (MMEADC01B_REG_THOLD_SELFTRIG_L_ADC01 + ((ch) * 4))
#define  MMEADC01B_REG_THOLD_SELFTRIG_H_IQ(ch)  (MMEADC01B_REG_THOLD_SELFTRIG_H_IQ01  + ((ch) * 4))
#define  MMEADC01B_REG_THOLD_SELFTRIG_L_IQ(ch)  (MMEADC01B_REG_THOLD_SELFTRIG_L_IQ01  + ((ch) * 4))

/*  BAR 0: waveform > monitor */
#define  MMEADC01B_REG_MON_SELFTRIG              0x0000F0D0              /* MON_SELFTRIG       */

#define  MMEADC01B_REG_MON_IQ01                  0x0000F0D8              /* MON_IQ01           */
#define  MMEADC01B_REG_MON_IQ02                  0x0000F0DC              /* MON_IQ02           */
#define  MMEADC01B_REG_MON_IQ03                  0x0000F0E0              /* MON_IQ03           */
#define  MMEADC01B_REG_MON_IQ04                  0x0000F0E4              /* MON_IQ04           */
#define  MMEADC01B_REG_MON_IQ05                  0x0000F0E8              /* MON_IQ05           */
#define  MMEADC01B_REG_MON_IQ06                  0x0000F0EC              /* MON_IQ06           */
#define  MMEADC01B_REG_MON_IQ07                  0x0000F0F0              /* MON_IQ07           */
#define  MMEADC01B_REG_MON_IQ08                  0x0000F0F4              /* MON_IQ08           */
#define  MMEADC01B_REG_MON_IQ09                  0x0000F0F8              /* MON_IQ09           */
#define  MMEADC01B_REG_MON_IQ10                  0x0000F0FC              /* MON_IQ10           */

#define  MMEADC01B_REG_MON_IQ(ch)               (MMEADC01B_REG_MON_IQ01 + ((ch) * 4))

/*  BAR 0: waveform > ADC peak hold (abs) */
#define  MMEADC01B_REG_PEAKHOLD_ADC01            0x0000F100              /* PEAKHOLD_ADC01     */
#define  MMEADC01B_REG_PEAKHOLD_ADC02            0x0000F104              /* PEAKHOLD_ADC02     */
#define  MMEADC01B_REG_PEAKHOLD_ADC03            0x0000F108              /* PEAKHOLD_ADC03     */
#define  MMEADC01B_REG_PEAKHOLD_ADC04            0x0000F10C              /* PEAKHOLD_ADC04     */
#define  MMEADC01B_REG_PEAKHOLD_ADC05            0x0000F110              /* PEAKHOLD_ADC05     */
#define  MMEADC01B_REG_PEAKHOLD_ADC06            0x0000F114              /* PEAKHOLD_ADC06     */
#define  MMEADC01B_REG_PEAKHOLD_ADC07            0x0000F118              /* PEAKHOLD_ADC07     */
#define  MMEADC01B_REG_PEAKHOLD_ADC08            0x0000F11C              /* PEAKHOLD_ADC08     */
#define  MMEADC01B_REG_PEAKHOLD_ADC09            0x0000F120              /* PEAKHOLD_ADC09     */
#define  MMEADC01B_REG_PEAKHOLD_ADC10            0x0000F124              /* PEAKHOLD_ADC10     */

#define  MMEADC01B_REG_PEAKHOLD_ADC(ch)         (MMEADC01B_REG_PEAKHOLD_ADC01 + ((ch) * 4))

/* ************************************************************: BAR 2 */
#define  LEN_MMEADC01B_BAR_2                       (2 << 20)             /* BAR 2:   2 [MB]    */
/*   BAR 2: SRAM memory map */
#define  MMEADC01B_REG_ADC_1                     0x00000000              /* ADC_0     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_2                     0x00010000              /* ADC_1     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_3                     0x00020000              /* ADC_2     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_4                     0x00030000              /* ADC_3     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_5                     0x00040000              /* ADC_4     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_6                     0x00050000              /* ADC_5     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_7                     0x00060000              /* ADC_6     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_8                     0x00070000              /* ADC_7     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_9                     0x00080000              /* ADC_8     [31-16]:ADC, [15:0]:fixed 0  */
#define  MMEADC01B_REG_ADC_10                    0x00090000              /* ADC_9     [31-16]:ADC, [15:0]:fixed 0  */
//#define  MMEADC01B_REG_DAC_2_1                   0x000A0000              /* DAC_1_0   [31-16]:ch2, [15:0]:ch1      */ // noo BPM supported
#define  MMEADC01B_REG_DDC_IQ_1                  0x000C0000              /* DDC_IQ_0  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_2                  0x000C4000              /* DDC_IQ_1  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_3                  0x000C8000              /* DDC_IQ_2  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_4                  0x000CC000              /* DDC_IQ_3  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_5                  0x000D0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_6                  0x000D4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_7                  0x000D8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_8                  0x000DC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_9                  0x000E0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_10                 0x000E4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_11                 0x000E8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_12                 0x000EC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */
#define  MMEADC01B_REG_DDC_IQ_13                 0x000F0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */ // unused for BPM
#define  MMEADC01B_REG_DDC_IQ_14                 0x000F4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */ // unused for BPM
#define  MMEADC01B_REG_DDC_IQ_15                 0x000F8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */ // unused for BPM
#define  MMEADC01B_REG_DDC_IQ_16                 0x000FC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */ // unused for BPM

#define  MMEADC01B_REG_SRAM_ADC(   ch)   (MMEADC01B_REG_ADC_1    + (LEN_ADC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DAC(   ch)   (MMEADC01B_REG_DAC_2_1  + (LEN_DAC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DDC_IQ(ch)   (MMEADC01B_REG_DDC_IQ_1 + (LEN_DDC_DAT * (ch)))

/* ************************************************************: BAR 4: added for LLRF */
#define  LEN_MMEADC01B_BAR_4                       (2 << 20)             /* BAR 4:   2 [MB]    */
/*  BAR 4: I/Q modualtion coefficients */
#define  MMEADC01B_REG_N_DDC_COEFF               0x00000000              /* N_DDC_COEFF        */
#define  MMEADC01B_REG_DDC_COEFF_0               0x00000004              /* DDC_COEFF_0        */
#define  MMEADC01B_REG_DDC_COEFF_1               0x00000008              /* DDC_COEFF_1        */
#define  MMEADC01B_REG_DDC_COEFF_2               0x0000000C              /* DDC_COEFF_2        */
#define  MMEADC01B_REG_DDC_COEFF_3               0x00000010              /* DDC_COEFF_3        */
#define  MMEADC01B_REG_DDC_COEFF_4               0x00000014              /* DDC_COEFF_4        */
#define  MMEADC01B_REG_DDC_COEFF_5               0x00000018              /* DDC_COEFF_5        */
#define  MMEADC01B_REG_DDC_COEFF_6               0x0000001C              /* DDC_COEFF_6        */
#define  MMEADC01B_REG_DDC_COEFF_7               0x00000020              /* DDC_COEFF_7        */
#define  MMEADC01B_REG_DDC_COEFF_8               0x00000024              /* DDC_COEFF_8        */
#define  MMEADC01B_REG_DDC_COEFF_9               0x00000028              /* DDC_COEFF_9        */
#define  MMEADC01B_REG_DDC_COEFF_A               0x0000002C              /* DDC_COEFF_A        */
#define  MMEADC01B_REG_DDC_COEFF_B               0x00000030              /* DDC_COEFF_B        */
#define  MMEADC01B_REG_DDC_COEFF_C               0x00000034              /* DDC_COEFF_C        */
#define  MMEADC01B_REG_DDC_COEFF_D               0x00000038              /* DDC_COEFF_D        */
#define  MMEADC01B_REG_DDC_COEFF_E               0x0000003C              /* DDC_COEFF_E        */
#define  MMEADC01B_REG_DDC_COEFF_F               0x00000040              /* DDC_COEFF_F        */

#define  N_MMEADC01B_DDC_COEFF                         0x0F
#define  MMEADC01B_REG_DDC_COEFF(id_coeff)      (MMEADC01B_REG_DDC_COEFF_0 + ((id_coeff) * 4))

#define  MMEADC01B_DDC_THRU                      0x00000044              /* DDC_THRU           */
#define  MMEADC01B_DDC_EXT_SYNC_EN               0x00000048              /* DDC_EXT_SYNC_EN    */

/*  BAR 4: I/Q rotation, gain coefficients */
/*
 * rotation coefficients:
 *      I       A   B    I
 *    (   ) = (       )(   )
 *      Q       C   A    Q
 *
 *     legend:
 *        A = <gain> x  cosθ
 *        B = <gain> x -sinθ
 *        C = <gain> x  sinθ
 */
#define  MMEADC01B_REG_IQ_ROT_COEFF_A(ch)       (0x00000050 + ((ch) * 4)) /* IQ_ROT_COEFF_A(ch) */
#define  MMEADC01B_REG_IQ_ROT_COEFF_B(ch)       (0x00000078 + ((ch) * 4)) /* IQ_ROT_COEFF_B(ch) */
#define  MMEADC01B_REG_IQ_ROT_COEFF_C(ch)       (0x000000A0 + ((ch) * 4)) /* IQ_ROT_COEFF_C(ch) */

#define  N_MMEADC01B_IQ_ROT_COEFF_CH                     10              /* # of iq rot ch     */
#define  MIN_MMEADC01B_REG_IQ_ROT_COEFF                  -8.0
#define  MAX_MMEADC01B_REG_IQ_ROT_COEFF                   8.0
#define  MMEADC01B_IQ_ROT_COEFF_LSB                  0x4000

/*  BAR 4: vector sum */
//#define  MMEADC01B_REG_VECTSUM_CAV_FB          0x000000D0              /* VECTSUM_CAV_FB     */ // no BPM supported
//#define  MMEADC01B_REG_VECTSUM_KLY_FB          0x000000D4              /* VECTSUM_KLY_FB     */ // no BPM supported
//#define  MMEADC01B_REG_VECTSUM_DACOUT          0x000000D8              /* VECTSUM_DACOUT     */ // no BPM supported
//#define  MMEADC01B_REG_VECTSUM_SERIAL          0x000000DC              /* VECTSUM_SERIAL     */ // no BPM supported

/*  BAR 4: interlock > trigger select */
#define  MMEADC01B_REG_INTL_TRIG_FORCED          0x00001000              /* INTL_TRIG_FORCED   */
#define  MMEADC01B_REG_INTL_DI_TRIG_EN           0x00001004              /* INTL_DI_TRIG_EN    */
#define  MMEADC01B_REG_INTL_SELF_TRIG_EN         0x00001008              /* INTL_SELF_TRIG_EN  */

/*  BAR 4: interlock > interrupt source */
/*  - INTLOCK source channels     */
/*
 * INTL_MSK_1:
 * INTL_SRC_1:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-------+-----------------------+---------------+-------+-------+
 *   | Front |         RTM           | (_Reserved_)  |Tx20_17|Rx20_17|
 *   |  DI   |          DI           |               | DI    | DI    |
 *   +-------+-----------------------+---------------+-------+-------+
 *             bit 31-28: Front of AMC       (J2 : DI           ) ... FRONT_DI3_P/_N ... FRONT_DI0_P/_N
 *             bit 27-16: RTM                (J30: Zone 3       ) ... RTM_D11P/N     ... RTM_D0P/N
 *             bit 15-8 : (_Reserved_)
 *             bit  7-4 : Port 20-17 TX      (P1 : AMC card edge) ... MB_TX20P/N     ...  MB_TX17P/N
 *             bit  3-0 : Port 20-17 RX      (P1 : AMC card edge) ... MB_RX20P/N     ...  MB_RX17P/N
 *
 * INTL_MSK_2:
 * INTL_SRC_2:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-----------+---+-------+-------------------+-------------------+
 *   | (_RSVD_)  |FA |(RSVD) |        I/Q        |        ADC        |
 *   +-----------+---+-------+-------------------+-------------------+
 *             bit 31-28: (_Reserved_)
 *             bit 25-24: BPM COD FA          (BPM ch  2-1)
 *             bit 23-20: (_Reserved_)
 *             bit 19-10: ADC                 (ADC ch 10-1)
 *             bit  9-0 : I/Q                 (I/Q ch 10-1)
 */
#define  INTL_SRC_FRONT_AMC                      0xF0000000
#define  INTL_SRC_RTM                            0x0FFF0000
#define  INTL_SRC_P20_17_TX                      0x000000F0
#define  INTL_SRC_P20_17_RX                      0x0000000F

#define  INTL_SRC_ADC                            0x000003FF
#define  INTL_SRC_IQ                             0x000FFC00
#define  INTL_SRC_BPM                            0x00300000

#define  INTL_ID_1                                        0              /* Interlock ID 1     */
#define  INTL_ID_2                                        1              /* Interlock ID 2     */
#define  N_INTL_IDS                                       2              /* # of Interlock IDs */

#define  MMEADC01B_REG_INTL_EN( id_intl)        (0x00001004 + ((id_intl) * 4)) /* int mask bits for Interlock */
#define  MMEADC01B_REG_INTL_SRC(id_intl)        (0x00001010 + ((id_intl) * 4)) /* int src  bits for Interlock */
#define  MMEADC01B_REG_INTL_1ST(id_intl)        (0x00001020 + ((id_intl) * 4)) /* first intl source indicator */
#define  MMEADC01B_REG_CLR_INTER_LOCK            0x00001030                    /* clear interlock status      */

#define  INTL_SRC_P17_RX                                  0              /*                    */
#define  INTL_SRC_P18_RX                                  1              /*                    */
#define  INTL_SRC_P19_RX                                  2              /*                    */
#define  INTL_SRC_P20_RX                                  3              /*                    */
#define  INTL_SRC_P17_TX                                  4              /*                    */
#define  INTL_SRC_P18_TX                                  5              /*                    */
#define  INTL_SRC_P19_TX                                  6              /*                    */
#define  INTL_SRC_P20_TX                                  7              /*                    */
#define  INTL_SRC_RSVD_8                                  8              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_9                                  9              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_10                                10              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_11                                11              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_12                                12              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_13                                13              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_14                                14              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_15                                15              /* (_Reserved_)       */
#define  INTL_SRC_RTM_0                                  16              /* RTM_D0P/N          */
#define  INTL_SRC_RTM_1                                  17              /* RTM_D1P/N          */
#define  INTL_SRC_RTM_2                                  18              /* RTM_D2P/N          */
#define  INTL_SRC_RTM_3                                  19              /* RTM_D3P/N          */
#define  INTL_SRC_RTM_4                                  20              /* RTM_D4P/N          */
#define  INTL_SRC_RTM_5                                  21              /* RTM_D5P/N          */
#define  INTL_SRC_RTM_6                                  22              /* RTM_D6P/N          */
#define  INTL_SRC_RTM_7                                  23              /* RTM_D7P/N          */
#define  INTL_SRC_RTM_8                                  24              /* RTM_D8P/N          */
#define  INTL_SRC_RTM_9                                  25              /* RTM_D9P/N          */
#define  INTL_SRC_RTM_10                                 26              /* RTM_D10P/N         */
#define  INTL_SRC_RTM_11                                 27              /* RTM_D11P/N         */
#define  INTL_SRC_F_AMC_0                                28              /* FRONT DI3_P/_N     */
#define  INTL_SRC_F_AMC_2                                29              /* FRONT DI2_P/_N     */
#define  INTL_SRC_F_AMC_3                                30              /* FRONT DI1_P/_N     */
#define  INTL_SRC_F_AMC_4                                31              /* FRONT DI0_P/_N     */

#define  INTL_SRC_ADC_1                                  32              /* ADC ch 1           */
#define  INTL_SRC_ADC_2                                  33              /* ADC ch  2          */
#define  INTL_SRC_ADC_3                                  34              /* ADC ch   3         */
#define  INTL_SRC_ADC_4                                  35              /* ADC ch    4        */
#define  INTL_SRC_ADC_5                                  36              /* ADC ch     5       */
#define  INTL_SRC_ADC_6                                  37              /* ADC ch      6      */
#define  INTL_SRC_ADC_7                                  38              /* ADC ch       7     */
#define  INTL_SRC_ADC_8                                  39              /* ADC ch        8    */
#define  INTL_SRC_ADC_9                                  40              /* ADC ch         9   */
#define  INTL_SRC_ADC_10                                 41              /* ADC ch          10 */
#define  INTL_SRC_IQ_1                                   42              /* I/Q ch 1           */
#define  INTL_SRC_IQ_2                                   43              /* I/Q ch  2          */
#define  INTL_SRC_IQ_3                                   44              /* I/Q ch   3         */
#define  INTL_SRC_IQ_4                                   45              /* I/Q ch    4        */
#define  INTL_SRC_IQ_5                                   46              /* I/Q ch     5       */
#define  INTL_SRC_IQ_6                                   47              /* I/Q ch      6      */
#define  INTL_SRC_IQ_7                                   48              /* I/Q ch       7     */
#define  INTL_SRC_IQ_8                                   49              /* I/Q ch        8    */
#define  INTL_SRC_IQ_9                                   50              /* I/Q ch         9   */
#define  INTL_SRC_IQ_10                                  51              /* I/Q ch          10 */
#define  INTL_SRC_RSVD_52                                52              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_53                                53              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_54                                54              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_55                                55              /* (_Reserved_)       */
#define  INTL_SRC_BPM_FA_1                               56              /* BPM COD FA ch 1    */
#define  INTL_SRC_BPM_FA_2                               57              /* BPM COD FA ch  2   */
#define  INTL_SRC_RSVD_58                                58              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_59                                59              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_60                                60              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_61                                61              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_62                                62              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_63                                63              /* (_Reserved_)       */

#define  N_INTL_SRCS                                     64              /* # of Interlock sources        */

/*  BAR 4: I/Q FIR filter coefficients */
#define  MMEADC01B_REG_FIR_ON                    0x00001040              /* FIR_ON             */
#define  MMEADC01B_REG_FIR_UPD                   0x00001048              /* FIR_UPD            */
#define  MMEADC01B_REG_FIR_CH_SEL                0x0000104C              /* FIR_CH_SEL         */
#define  MMEADC01B_REG_FIR_COEFF_0               0x00001050              /* FIR_COEFF_0        */
#define  MMEADC01B_REG_FIR_COEFF_1               0x00001054              /* FIR_COEFF_1        */
#define  MMEADC01B_REG_FIR_COEFF_2               0x00001058              /* FIR_COEFF_2        */
#define  MMEADC01B_REG_FIR_COEFF_3               0x0000105C              /* FIR_COEFF_3        */
#define  MMEADC01B_REG_FIR_COEFF_4               0x00001060              /* FIR_COEFF_4        */
#define  MMEADC01B_REG_FIR_COEFF_5               0x00001064              /* FIR_COEFF_5        */
#define  MMEADC01B_REG_FIR_COEFF_6               0x00001068              /* FIR_COEFF_6        */
#define  MMEADC01B_REG_FIR_COEFF_7               0x0000106C              /* FIR_COEFF_7        */
#define  MMEADC01B_REG_FIR_COEFF_8               0x00001070              /* FIR_COEFF_8        */
#define  MMEADC01B_REG_FIR_COEFF_9               0x00001074              /* FIR_COEFF_9        */
#define  MMEADC01B_REG_FIR_COEFF_10              0x00001078              /* FIR_COEFF_10       */
#define  MMEADC01B_REG_FIR_COEFF_11              0x0000107C              /* FIR_COEFF_11       */
#define  MMEADC01B_REG_FIR_COEFF_12              0x00001080              /* FIR_COEFF_12       */
#define  MMEADC01B_REG_FIR_COEFF_13              0x00001084              /* FIR_COEFF_13       */
#define  MMEADC01B_REG_FIR_COEFF_14              0x00001088              /* FIR_COEFF_14       */
#define  MMEADC01B_REG_FIR_COEFF_15              0x0000108C              /* FIR_COEFF_15       */
#define  MMEADC01B_REG_FIR_COEFF_16              0x00001090              /* FIR_COEFF_16       */

#define  N_MMEADC01B_REG_FIR_COEFFS                      16
#define  MMEADC01B_REG_FIR_COEFF(id_coeff)      (MMEADC01B_REG_FIR_COEFF_0 + ((id_coeff) * 4))

/*  BAR 4: I/Q IIR filter coefficients */
//#define  MMEADC01B_REG_IIR_ON                  0x000010E0              /* IIR_ON             */ // no BPM supported
//#define  MMEADC01B_REG_IIR_COEFF               0x000010E4              /* IIR_COEFF          */ // no BPM supported

/*  BAR 4: CIC filter coefficients for feedback of coherent synchrotron oscillation */
//#define  MMEADC01B_REG_FSFB_CIC_RATE_UPD       0x000010F0              /* FSFB_CIC_RATE_UPD  */ // no BPM supported
//#define  MMEADC01B_REG_FSFB_CIC_RATE           0x000010F4              /* FSFB_CIC_RATE      */ // no BPM supported

/*  BAR 4: feedback control */
//#define  MMEADC01B_REG_CAV_IIR_COEFF           0x00002000              /* CAV_IIR_COEFF      */ // no BPM supported
//#define  MMEADC01B_REG_CAV_IIR_COEFF_T         0x00002004              /* CAV_IIR_COEFF_T    */ // no BPM supported
//#define  MMEADC01B_REG_KLY_IIR_COEFF           0x00002008              /* KLY_IIR_COEFF      */ // no BPM supported
//#define  MMEADC01B_REG_KLY_IIR_COEFF_T         0x0000200C              /* KLY_IIR_COEFF_T    */ // no BPM supported
//#define  MMEADC01B_REG_CAV_SV                  0x00002010              /* CAV_SV             */ // no BPM supported
//#define  MMEADC01B_REG_KLY_SV                  0x00002014              /* KLY_SV             */ // no BPM supported
//#define  MMEADC01B_REG_KLY_SV_SEL              0x00002018              /* KLY_SV_SEL         */ // no BPM supported
//#define  MMEADC01B_REG_FB_ON                   0x0000201C              /* FB_ON              */ // no BPM supported
//#define  MMEADC01B_REG_KLY_P_GAIN_R            0x00002020              /* KLY_P_GAIN_R       */ // no BPM supported
//#define  MMEADC01B_REG_KLY_P_GAIN_T            0x00002024              /* KLY_P_GAIN_T       */ // no BPM supported
//#define  MMEADC01B_REG_KLY_I_GAIN_R            0x00002028              /* KLY_I_GAIN_R       */ // no BPM supported
//#define  MMEADC01B_REG_KLY_I_GAIN_T            0x0000202C              /* KLY_I_GAIN_T       */ // no BPM supported
//#define  MMEADC01B_REG_CAV_P_GAIN_R            0x00002030              /* CAV_P_GAIN_R       */ // no BPM supported
//#define  MMEADC01B_REG_CAV_P_GAIN_T            0x00002034              /* CAV_P_GAIN_T       */ // no BPM supported
//#define  MMEADC01B_REG_CAV_I_GAIN_R            0x00002038              /* CAV_I_GAIN_R       */ // no BPM supported
//#define  MMEADC01B_REG_CAV_I_GAIN_T            0x0000203C              /* CAV_I_GAIN_T       */ // no BPM supported
//#define  MMEADC01B_REG_FF_SV                   0x00002040              /* FF_SV              */ // no BPM supported
//#define  MMEADC01B_REG_FF_GAIN                 0x00002044              /* FF_GAIN            */ // no BPM supported
//#define  MMEADC01B_REG_FF_NCO_FREQ_START       0x00002048              /* FF_NCO_FREQ_START  */ // no BPM supported
//#define  MMEADC01B_REG_FF_NCO_FREQ_STOP        0x0000204C              /* FF_NCO_FREQ_STOP   */ // no BPM supported
//#define  MMEADC01B_REG_FF_NCO_INC_FREQ         0x00002050              /* FF_NCO_INC_FREQ    */ // no BPM supported
//#define  MMEADC01B_REG_FF_NCO_INC_CYCLE        0x00002054              /* FF_NCO_INC_CYCLE   */ // no BPM supported
//#define  MMEADC01B_REG_FF_NCO_RST_REPEAT       0x00002058              /* FF_NCO_RST_REPEAT  */ // no BPM supported

//#define  MMEADC01B_REG_FSFB_SFP_ADC_SEL        0x00002070              /* FSFB_SFP_ADC_SEL   */ // no BPM supported
//#define  MMEADC01B_REG_FSFB_GAIN               0x00002074              /* FSFB_GAIN          */ // no BPM supported
//#define  MMEADC01B_REG_FSFB_LIMIT              0x00002078              /* FSFB_LIMIT         */ // no BPM supported

//#define  MMEADC01B_REG_MV_CONST                0x00002094              /* MV_CONST           */ // no BPM supported
//#define  MMEADC01B_REG_MV_SEL                  0x00002098              /* MV_SEL             */ // no BPM supported

//#define  MMEADC01B_REG_PI_STEP                 0x000020A4              /* PI_STEP            */ // no BPM supported

/*  BAR 4: real-time monitor */
//#define  MMEADC01B_REG_MON_CAV_IIR             0x00002100              /* CAV_IIR            */ // no BPM supported
//#define  MMEADC01B_REG_MON_KLY_IIR             0x00002104              /* KLY_IIR            */ // no BPM supported
//#define  MMEADC01B_REG_MON_KLY_ERR             0x00002108              /* KLY_ERR            */ // no BPM supported
//#define  MMEADC01B_REG_MON_KLY_PI_DIFF         0x0000210C              /* KLY_PI_DIFF        */ // no BPM supported
//#define  MMEADC01B_REG_MON_CAV_ERR             0x00002110              /* CAV_ERR            */ // no BPM supported
//#define  MMEADC01B_REG_MON_CAV_PI_DIFF         0x00002114              /* CAV_PI_DIFF        */ // no BPM supported
//#define  MMEADC01B_REG_MON_CAV_MV              0x00002118              /* CAV_MV             */ // no BPM supported
//#define  MMEADC01B_REG_MON_FF_SV               0x0000211C              /* FF_SV              */ // no BPM supported
//#define  MMEADC01B_REG_MON_MV_ROT              0x00002120              /* MV_ROT             */ // no BPM supported
//#define  MMEADC01B_REG_MON_MV_RFSW             0x00002124              /* MV_RFSW            */ // no BPM supported
//#define  MMEADC01B_REG_MON_MV_LIMIT            0x00002128              /* MV_LIMIT           */ // no BPM supported
//#define  MMEADC01B_REG_MON_MV                  0x0000212C              /* MV                 */ // no BPM supported
//#define  MMEADC01B_REG_MON_KLY_MV              0x00002130              /* KLY_MV             */ // no BPM supported

/*  BAR 4: COD > down sampling trigger */
#define  MMEADC01B_REG_COD_DS_INIT_TRIG          0x00100000              /* COD_DS_INIT_TRIG   */

/*  BAR 4: COD > CIC filter / decimator */
//#define  MMEADC01B_REG_COD_CIC_R_TBT_UPD       0x00100010              /* COD_CIC_R_TBT_UPD  */ // save FPGA resources
//#define  MMEADC01B_REG_COD_CIC_R_TBT           0x00100014              /* COD_CIC_R_TBT      */ // save FPGA resources
//#define  MMEADC01B_REG_COD_CIC_R_FA_UPD        0x00100018              /* COD_CIC_R_FA_UPD   */ // save FPGA resources
//#define  MMEADC01B_REG_COD_CIC_R_FA            0x0010001C              /* COD_CIC_R_FA       */ // save FPGA resources
//#define  MMEADC01B_REG_COD_CIC_R_SA_UPD        0x00100020              /* COD_CIC_R_SA_UPD   */ // save FPGA resources
//#define  MMEADC01B_REG_COD_CIC_R_SA            0x00100024              /* COD_CIC_R_SA       */ // save FPGA resources

/*  BAR 4: COD > CIC down-sampler */
//#define  MMEADC01B_REG_COD_DS_T_TBT_UPD        0x00100028              /* COD_DS_T_TBT_UPD   */ // save FPGA resources
//#define  MMEADC01B_REG_COD_DS_T_TBT            0x0010002C              /* COD_DS_T_TBT       */ // save FPGA resources
//#define  MMEADC01B_REG_COD_DS_T_FA_UPD         0x00100030              /* COD_DS_T_FA_UPD    */ // save FPGA resources
//#define  MMEADC01B_REG_COD_DS_T_FA             0x00100034              /* COD_DS_T_FA        */ // save FPGA resources
//#define  MMEADC01B_REG_COD_DS_T_SA_UPD         0x00100038              /* COD_DS_T_SA_UPD    */ // save FPGA resources
//#define  MMEADC01B_REG_COD_DS_T_SA             0x0010003C              /* COD_DS_T_SA        */ // save FPGA resources

/*  BAR 4: COD > FIR filter coefficients */
#define  MMEADC01B_REG_COD_FIR_ON                0x00100040              /* COD_FIR_ON           */
#define  MMEADC01B_REG_COD_FIR_COEFF_UPD         0x00100044              /* COD_FIR_COEFF_UPD    */
#define  MMEADC01B_REG_COD_FIR_COEFF_CHSEL       0x00100048              /* COD_FIR_COEFF_CHSEL  */
#define  MMEADC01B_REG_COD_FIR_COEFF_STRSEL      0x0010004C              /* COD_FIR_COEFF_STRSEL */
#define  MMEADC01B_REG_COD_FIR_COEFF_00          0x00100050              /* COD_FIR_COEFF_00     */
#define  MMEADC01B_REG_COD_FIR_COEFF_01          0x00100054              /* COD_FIR_COEFF_01     */
#define  MMEADC01B_REG_COD_FIR_COEFF_02          0x00100058              /* COD_FIR_COEFF_02     */
#define  MMEADC01B_REG_COD_FIR_COEFF_03          0x0010005C              /* COD_FIR_COEFF_03     */
#define  MMEADC01B_REG_COD_FIR_COEFF_04          0x00100060              /* COD_FIR_COEFF_04     */
#define  MMEADC01B_REG_COD_FIR_COEFF_05          0x00100064              /* COD_FIR_COEFF_05     */
#define  MMEADC01B_REG_COD_FIR_COEFF_06          0x00100068              /* COD_FIR_COEFF_06     */
#define  MMEADC01B_REG_COD_FIR_COEFF_07          0x0010006C              /* COD_FIR_COEFF_07     */
#define  MMEADC01B_REG_COD_FIR_COEFF_08          0x00100070              /* COD_FIR_COEFF_08     */
#define  MMEADC01B_REG_COD_FIR_COEFF_09          0x00100074              /* COD_FIR_COEFF_09     */
#define  MMEADC01B_REG_COD_FIR_COEFF_10          0x00100078              /* COD_FIR_COEFF_10     */
#define  MMEADC01B_REG_COD_FIR_COEFF_11          0x0010007C              /* COD_FIR_COEFF_11     */
#define  MMEADC01B_REG_COD_FIR_COEFF_12          0x00100080              /* COD_FIR_COEFF_12     */
#define  MMEADC01B_REG_COD_FIR_COEFF_13          0x00100084              /* COD_FIR_COEFF_13     */
#define  MMEADC01B_REG_COD_FIR_COEFF_14          0x00100088              /* COD_FIR_COEFF_14     */
#define  MMEADC01B_REG_COD_FIR_COEFF_15          0x0010008C              /* COD_FIR_COEFF_15     */
#define  MMEADC01B_REG_COD_FIR_COEFF_16          0x00100090              /* COD_FIR_COEFF_16     */
#define  MMEADC01B_REG_COD_FIR_COEFF_17          0x00100094              /* COD_FIR_COEFF_17     */
#define  MMEADC01B_REG_COD_FIR_COEFF_18          0x00100098              /* COD_FIR_COEFF_18     */
#define  MMEADC01B_REG_COD_FIR_COEFF_19          0x0010009C              /* COD_FIR_COEFF_19     */
//#define  MMEADC01B_REG_COD_FIR_COEFF_20        0x001000A0              /* COD_FIR_COEFF_20 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_21        0x001000A4              /* COD_FIR_COEFF_21 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_22        0x001000A8              /* COD_FIR_COEFF_22 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_23        0x001000AC              /* COD_FIR_COEFF_23 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_24        0x001000B0              /* COD_FIR_COEFF_24 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_25        0x001000B4              /* COD_FIR_COEFF_25 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_26        0x001000B8              /* COD_FIR_COEFF_26 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_27        0x001000BC              /* COD_FIR_COEFF_27 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_28        0x001000C0              /* COD_FIR_COEFF_28 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_29        0x001000C4              /* COD_FIR_COEFF_29 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_30        0x001000C8              /* COD_FIR_COEFF_30 */ // save FPGA resources
//#define  MMEADC01B_REG_COD_FIR_COEFF_31        0x001000CC              /* COD_FIR_COEFF_31 */ // save FPGA resources

#define  N_MMEADC01B_REG_COD_FIR_COEFFS                  20
#define  MMEADC01B_REG_COD_FIR_COEFF(id_coeff)   (MMEADC01B_REG_COD_FIR_COEFF_00 + ((id_coeff) * 4))

/*  BAR 4: SP  >  revolution frequency sync trigger */
#define  MMEADC01B_REG_SP_REV_INIT_TRIG          0x00100100              /* SP_REV_INIT_TRIG     */

/*  BAR 4: SP  >  waveform acquisition */
#define  MMEADC01B_REG_SP_REC_START              0x00100110              /* SP_REC_START         */

#define  MMEADC01B_REG_SP_WAVE_SMPL_STEP         0x00100114              /* SP_WAVE_SMPL_STEP    */
#define  MMEADC01B_REG_SP_WAVE_TRIG_DELAY        0x00100118              /* SP_WAVE_TRIG_DELAY   */

/*
 * 31 30          16 15             0
 * +-+--------------+----------------+
 * |W| next address to be stored     |
 * +-+--------------+----------------+
 *
 *   bit 31  : wrapped            ... 0:no wrapped, 1:wrapped
 *   bit 30-0: next address       ... next address to be stored
 */
#define  MMEADC01B_REG_SP_ADDR                   0x00100120              /* SP_ADDR              */

#define  MMEADC01B_REG_SP_MASK_SEL               0x00100124              /* SP_MASK_SEL          */

/*  BAR 4: SP   > waveform > trigger mode */
#define  MMEADC01B_REG_SP_TRIG_FORCED            0x00000130              /* SP_TRIG_FORCED       */
#define  MMEADC01B_REG_SP_DI_TRIG_EN             0x00000134              /* SP_DI_TRIG_EN        */

/*  BAR 4: BPM  > data xfer */
#define  MMEADC01B_REG_BPM_TX_CTRL               0x00100140              /* BPM_TX_CTRL          */
#define  MMEADC01B_REG_BPM_TX_MODE               0x00100144              /* BPM_TX_MODE          */

#define  MMEADC01B_REG_BPM1_COD_BAR_TBT          0x00100150              /* BPM1_COD_BAR_TBT     */
#define  MMEADC01B_REG_BPM1_COD_BAR_FA           0x00100154              /* BPM1_COD_BAR_FA      */

#define  MMEADC01B_REG_BPM1_SP_BAR               0x0010015C              /* BPM1_SP_BAR          */

#define  MMEADC01B_REG_BPM2_COD_BAR_TBT          0x00100160              /* BPM2_COD_BAR_TBT     */
#define  MMEADC01B_REG_BPM2_COD_BAR_FA           0x00100164              /* BPM2_COD_BAR_FA      */

#define  MMEADC01B_REG_BPM2_SP_BAR               0x0010016C              /* BPM2_SP_BAR          */

#define  MMEADC01B_REG_BPM1_COD_CAP_TBT          0x00100190              /* BPM1_COD_CAP_TBT     */
#define  MMEADC01B_REG_BPM1_COD_CAP_FA           0x00100194              /* BPM1_COD_CAP_FA      */
#define  MMEADC01B_REG_BPM1_COD_CAP_SA           0x00100198              /* BPM1_COD_CAP_SA      */
#define  MMEADC01B_REG_BPM1_SP_CAP               0x0010019C              /* BPM1_SP_CAP          */

#define  MMEADC01B_REG_BPM2_COD_CAP_TBT          0x001001A0              /* BPM2_COD_CAP_TBT     */
#define  MMEADC01B_REG_BPM2_COD_CAP_FA           0x001001A4              /* BPM2_COD_CAP_FA      */
#define  MMEADC01B_REG_BPM2_COD_CAP_SA           0x001001A8              /* BPM2_COD_CAP_SA      */
#define  MMEADC01B_REG_BPM2_SP_CAP               0x001001AC              /* BPM2_SP_CAP          */

/*  BAR 4: completion status for generating data  */
#define  MMEADC01B_REG_CMPLT_SRC                 0x001001E0              /* CMPLT_SRC            */
#define  MMEADC01B_REG_CMPLT_CLR                 0x001001E4              /* CMPLT_CLR            */

/*  BAR 4: BPM  > amplitude offsets */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_1         0x00101000              /* BPM_OFS_COD_TBT_1    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_2         0x00101004              /* BPM_OFS_COD_TBT_2    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_3         0x00101008              /* BPM_OFS_COD_TBT_3    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_4         0x0010100C              /* BPM_OFS_COD_TBT_4    */
//#define  MMEADC01B_REG_BPM_OFS_COD_TBT_5                               /* BPM_OFS_COD_TBT_5    */
//#define  MMEADC01B_REG_BPM_OFS_COD_TBT_6                               /* BPM_OFS_COD_TBT_6    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_7         0x00101010              /* BPM_OFS_COD_TBT_7    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_8         0x00101014              /* BPM_OFS_COD_TBT_8    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_9         0x00101018              /* BPM_OFS_COD_TBT_9    */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_10        0x0010101C              /* BPM_OFS_COD_TBT_10   */

#define  MMEADC01B_REG_BPM_OFS_COD_FA_1          0x00101020              /* BPM_OFS_COD_FA_1     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_2          0x00101024              /* BPM_OFS_COD_FA_2     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_3          0x00101028              /* BPM_OFS_COD_FA_3     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_4          0x0010102C              /* BPM_OFS_COD_FA_4     */
//#define  MMEADC01B_REG_BPM_OFS_COD_FA_5                                /* BPM_OFS_COD_FA_5     */
//#define  MMEADC01B_REG_BPM_OFS_COD_FA_6                                /* BPM_OFS_COD_FA_6     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_7          0x00101030              /* BPM_OFS_COD_FA_7     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_8          0x00101034              /* BPM_OFS_COD_FA_8     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_9          0x00101038              /* BPM_OFS_COD_FA_9     */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_10         0x0010103C              /* BPM_OFS_COD_FA_10    */

#define  MMEADC01B_REG_BPM_OFS_COD_SA_1          0x00101040              /* BPM_OFS_COD_SA_1     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_2          0x00101044              /* BPM_OFS_COD_SA_2     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_3          0x00101048              /* BPM_OFS_COD_SA_3     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_4          0x0010104C              /* BPM_OFS_COD_SA_4     */
//#define  MMEADC01B_REG_BPM_OFS_COD_SA_5                                /* BPM_OFS_COD_SA_5     */
//#define  MMEADC01B_REG_BPM_OFS_COD_SA_6                                /* BPM_OFS_COD_SA_6     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_7          0x00101050              /* BPM_OFS_COD_SA_7     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_8          0x00101054              /* BPM_OFS_COD_SA_8     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_9          0x00101058              /* BPM_OFS_COD_SA_9     */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_10         0x0010105C              /* BPM_OFS_COD_SA_10    */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_1        0x00101060              /* BPM_OFS_SP_MASK1_1   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_1        0x00101064              /* BPM_OFS_SP_MASK2_1   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_1        0x00101068              /* BPM_OFS_SP_MASK3_1   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_1        0x0010106C              /* BPM_OFS_SP_MASK4_1   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_1      0x00101070              /* BPM_OFS_SP_MASK5_1   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_1      0x00101074              /* BPM_OFS_SP_MASK6_1   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_1      0x00101078              /* BPM_OFS_SP_MASK7_1   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_1      0x0010107C              /* BPM_OFS_SP_MASK8_1   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_2        0x00101080              /* BPM_OFS_SP_MASK1_2   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_2        0x00101084              /* BPM_OFS_SP_MASK2_2   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_2        0x00101088              /* BPM_OFS_SP_MASK3_2   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_2        0x0010108C              /* BPM_OFS_SP_MASK4_2   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_2      0x00101090              /* BPM_OFS_SP_MASK5_2   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_2      0x00101094              /* BPM_OFS_SP_MASK6_2   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_2      0x00101098              /* BPM_OFS_SP_MASK7_2   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_2      0x0010109C              /* BPM_OFS_SP_MASK8_2   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_3        0x001010A0              /* BPM_OFS_SP_MASK1_3   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_3        0x001010A4              /* BPM_OFS_SP_MASK2_3   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_3        0x001010A8              /* BPM_OFS_SP_MASK3_3   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_3        0x001010AC              /* BPM_OFS_SP_MASK4_3   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_3      0x001010B0              /* BPM_OFS_SP_MASK5_3   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_3      0x001010B4              /* BPM_OFS_SP_MASK6_3   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_3      0x001010B8              /* BPM_OFS_SP_MASK7_3   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_3      0x001010BC              /* BPM_OFS_SP_MASK8_3   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_4        0x001010C0              /* BPM_OFS_SP_MASK1_4   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_4        0x001010C4              /* BPM_OFS_SP_MASK2_4   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_4        0x001010C8              /* BPM_OFS_SP_MASK3_4   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_4        0x001010CC              /* BPM_OFS_SP_MASK4_4   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_4      0x001010D0              /* BPM_OFS_SP_MASK5_4   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_4      0x001010D4              /* BPM_OFS_SP_MASK6_4   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_4      0x001010D8              /* BPM_OFS_SP_MASK7_4   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_4      0x001010DC              /* BPM_OFS_SP_MASK8_4   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_7        0x001010E0              /* BPM_OFS_SP_MASK1_7   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_7        0x001010E4              /* BPM_OFS_SP_MASK2_7   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_7        0x001010E8              /* BPM_OFS_SP_MASK3_7   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_7        0x001010EC              /* BPM_OFS_SP_MASK4_7   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_7      0x001010F0              /* BPM_OFS_SP_MASK5_7   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_7      0x001010F4              /* BPM_OFS_SP_MASK6_7   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_7      0x001010F8              /* BPM_OFS_SP_MASK7_7   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_7      0x001010FC              /* BPM_OFS_SP_MASK8_7   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_8        0x00101100              /* BPM_OFS_SP_MASK1_8   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_8        0x00101104              /* BPM_OFS_SP_MASK2_8   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_8        0x00101108              /* BPM_OFS_SP_MASK3_8   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_8        0x0010110C              /* BPM_OFS_SP_MASK4_8   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_8      0x00101110              /* BPM_OFS_SP_MASK5_8   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_8      0x00101114              /* BPM_OFS_SP_MASK6_8   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_8      0x00101118              /* BPM_OFS_SP_MASK7_8   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_8      0x0010111C              /* BPM_OFS_SP_MASK8_8   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_9        0x00101120              /* BPM_OFS_SP_MASK1_9   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_9        0x00101124              /* BPM_OFS_SP_MASK2_9   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_9        0x00101128              /* BPM_OFS_SP_MASK3_9   */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_9        0x0010112C              /* BPM_OFS_SP_MASK4_9   */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_9      0x00101130              /* BPM_OFS_SP_MASK5_9   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_9      0x00101134              /* BPM_OFS_SP_MASK6_9   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_9      0x00101138              /* BPM_OFS_SP_MASK7_9   */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_9      0x0010113C              /* BPM_OFS_SP_MASK8_9   */ // saves FPGA resources

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_10       0x00101140              /* BPM_OFS_SP_MASK1_10  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_10       0x00101144              /* BPM_OFS_SP_MASK2_10  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_10       0x00101148              /* BPM_OFS_SP_MASK3_10  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_10       0x0010114C              /* BPM_OFS_SP_MASK4_10  */
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_10     0x00101150              /* BPM_OFS_SP_MASK5_10  */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_10     0x00101154              /* BPM_OFS_SP_MASK6_10  */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_10     0x00101158              /* BPM_OFS_SP_MASK7_10  */ // saves FPGA resources
//#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_10     0x0010115C              /* BPM_OFS_SP_MASK8_10  */ // saves FPGA resources

/*  BAR 4: BPM  > COD FA w/ three detectors */
#define  MMEADC01B_REG_BPM3_COD_FA_3_SEL         0x00101160              /* BPM3_COD_FA_3_SEL    */

/*  BAR 4: BPM  > interlock for COD FA */
#define  MMEADC01B_REG_BPM_SELF_TRIG_EN          0x00101170              /* BPM_SELF_TRIG_EN     */
#define  MMEADC01B_REG_BPM_SELF_TRIG_SRC         0x00101174              /* BPM_SELF_TRIG_SRC    */

#define  MMEADC01B_REG_BPM1_X_THOLD_SELFTRIG_H   0x00101178              /* BPM1_X_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM1_Y_THOLD_SELFTRIG_H   0x0010117C              /* BPM1_Y_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM1_X_THOLD_SELFTRIG_L   0x00101180              /* BPM1_X_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM1_Y_THOLD_SELFTRIG_L   0x00101184              /* BPM1_Y_THOLD_SELFTRI */

#define  MMEADC01B_REG_BPM2_X_THOLD_SELFTRIG_H   0x00101188              /* BPM2_X_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM2_Y_THOLD_SELFTRIG_H   0x0010118C              /* BPM2_Y_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM2_X_THOLD_SELFTRIG_L   0x00101190              /* BPM2_X_THOLD_SELFTRI */
#define  MMEADC01B_REG_BPM2_Y_THOLD_SELFTRIG_L   0x00101194              /* BPM2_Y_THOLD_SELFTRI */

/*  BAR 4: BPM  > DEBUG */
#define  MMEADC01B_REG_BPM_DEBUG_SET0            0x001011B0              /* BPM_DEBUG_SET0       */
#define  MMEADC01B_REG_BPM_COD_DAC_SRC           0x001011B4              /* BPM_COD_DAC_SRC      */
#define  MMEADC01B_REG_BPM_DEBUG_SET2            0x001011B8              /* BPM_DEBUG_SET2       */
#define  MMEADC01B_REG_BPM_DEBUG_SET3            0x001011BC              /* BPM_DEBUG_SET3       */
#define  MMEADC01B_REG_BPM_DEBUG_SET4            0x001011C0              /* BPM_DEBUG_SET4       */
#define  MMEADC01B_REG_BPM_DEBUG_SET5            0x001011C4              /* BPM_DEBUG_SET5       */
#define  MMEADC01B_REG_BPM_DEBUG_SET6            0x001011C8              /* BPM_DEBUG_SET6       */
#define  MMEADC01B_REG_BPM_DEBUG_SET7            0x001011CC              /* BPM_DEBUG_SET7       */

#define  MMEADC01B_REG_BPM_DEBUG_MON0            0x001011D0              /* BPM_DEBUG_MON0       */
#define  MMEADC01B_REG_BPM_DEBUG_MON1            0x001011D4              /* BPM_DEBUG_MON1       */
#define  MMEADC01B_REG_BPM_DEBUG_MON2            0x001011D8              /* BPM_DEBUG_MON2       */
#define  MMEADC01B_REG_BPM_DEBUG_MON3            0x001011DC              /* BPM_DEBUG_MON3       */
#define  MMEADC01B_REG_BPM_DEBUG_MON4            0x001011E0              /* BPM_DEBUG_MON4       */
#define  MMEADC01B_REG_BPM_DEBUG_MON5            0x001011E4              /* BPM_DEBUG_MON5       */
#define  MMEADC01B_REG_BPM_DEBUG_MON6            0x001011E8              /* BPM_DEBUG_MON6       */
#define  MMEADC01B_REG_BPM_DEBUG_MON7            0x001011EC              /* BPM_DEBUG_MON7       */

/*  BAR 4: CAL Tone > configuration */
#define  MMEADC01B_REG_TONE_NCO_1_FREQ           0x00102000              /* TONE_NCO_1_FREQ      */
#define  MMEADC01B_REG_TONE_NCO_2_FREQ           0x00102004              /* TONE_NCO_2_FREQ      */
#define  MMEADC01B_REG_TONE_NCO_3_FREQ           0x00102008              /* TONE_NCO_3_FREQ      */
#define  MMEADC01B_REG_TONE_NCO_4_FREQ           0x0010200C              /* TONE_NCO_4_FREQ      */

//#define  MMEADC01B_REG_TONE_CIC1_R_UPD         0x00102010              /* TONE_CIC1_R_UPD      */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_CIC1_R             0x00102014              /* TONE_CIC1_R          */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_CIC2_R_UPD         0x00102018              /* TONE_CIC2_R_UPD      */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_CIC2_R             0x0010201C              /* TONE_CIC2_R          */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_DS_T_UPD           0x00102020              /* TONE_DS_T_UPD        */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_DS_T               0x00102024              /* TONE_DS_T            */ // saves FPGA resources

/*  BAR 4: CAL Tone > gain */
#define  MMEADC01B_REG_TONE_GAIN1_1              0x00102040              /* TONE_GAIN1_1         */
#define  MMEADC01B_REG_TONE_GAIN2_1              0x00102044              /* TONE_GAIN2_1         */
#define  MMEADC01B_REG_TONE_GAIN3_1              0x00102048              /* TONE_GAIN3_1         */
#define  MMEADC01B_REG_TONE_GAIN4_1              0x0010204C              /* TONE_GAIN4_1         */
#define  MMEADC01B_REG_TONE_GAIN1_2              0x00102050              /* TONE_GAIN1_2         */
#define  MMEADC01B_REG_TONE_GAIN2_2              0x00102054              /* TONE_GAIN2_2         */
#define  MMEADC01B_REG_TONE_GAIN3_2              0x00102058              /* TONE_GAIN3_2         */
#define  MMEADC01B_REG_TONE_GAIN4_2              0x0010205C              /* TONE_GAIN4_2         */
#define  MMEADC01B_REG_TONE_GAIN1_3              0x00102060              /* TONE_GAIN1_3         */
#define  MMEADC01B_REG_TONE_GAIN2_3              0x00102064              /* TONE_GAIN2_3         */
#define  MMEADC01B_REG_TONE_GAIN3_3              0x00102068              /* TONE_GAIN3_3         */
#define  MMEADC01B_REG_TONE_GAIN4_3              0x0010206C              /* TONE_GAIN4_3         */
#define  MMEADC01B_REG_TONE_GAIN1_4              0x00102070              /* TONE_GAIN1_4         */
#define  MMEADC01B_REG_TONE_GAIN2_4              0x00102074              /* TONE_GAIN2_4         */
#define  MMEADC01B_REG_TONE_GAIN3_4              0x00102078              /* TONE_GAIN3_4         */
#define  MMEADC01B_REG_TONE_GAIN4_4              0x0010207C              /* TONE_GAIN4_4         */
#define  MMEADC01B_REG_TONE_GAIN1_5              0x00102080              /* TONE_GAIN1_5         */
#define  MMEADC01B_REG_TONE_GAIN2_5              0x00102084              /* TONE_GAIN2_5         */
#define  MMEADC01B_REG_TONE_GAIN3_5              0x00102088              /* TONE_GAIN3_5         */
#define  MMEADC01B_REG_TONE_GAIN4_5              0x0010208C              /* TONE_GAIN4_5         */
#define  MMEADC01B_REG_TONE_GAIN1_6              0x00102090              /* TONE_GAIN1_6         */
#define  MMEADC01B_REG_TONE_GAIN2_6              0x00102094              /* TONE_GAIN2_6         */
#define  MMEADC01B_REG_TONE_GAIN3_6              0x00102098              /* TONE_GAIN3_6         */
#define  MMEADC01B_REG_TONE_GAIN4_6              0x0010209C              /* TONE_GAIN4_6         */
#define  MMEADC01B_REG_TONE_GAIN1_7              0x001020A0              /* TONE_GAIN1_7         */
#define  MMEADC01B_REG_TONE_GAIN2_7              0x001020A4              /* TONE_GAIN2_7         */
#define  MMEADC01B_REG_TONE_GAIN3_7              0x001020A8              /* TONE_GAIN3_7         */
#define  MMEADC01B_REG_TONE_GAIN4_7              0x001020AC              /* TONE_GAIN4_7         */
#define  MMEADC01B_REG_TONE_GAIN1_8              0x001020B0              /* TONE_GAIN1_8         */
#define  MMEADC01B_REG_TONE_GAIN2_8              0x001020B4              /* TONE_GAIN2_8         */
#define  MMEADC01B_REG_TONE_GAIN3_8              0x001020B8              /* TONE_GAIN3_8         */
#define  MMEADC01B_REG_TONE_GAIN4_8              0x001020BC              /* TONE_GAIN4_8         */
#define  MMEADC01B_REG_TONE_GAIN1_9              0x001020C0              /* TONE_GAIN1_9         */
#define  MMEADC01B_REG_TONE_GAIN2_9              0x001020C4              /* TONE_GAIN2_9         */
#define  MMEADC01B_REG_TONE_GAIN3_9              0x001020C8              /* TONE_GAIN3_9         */
#define  MMEADC01B_REG_TONE_GAIN4_9              0x001020CC              /* TONE_GAIN4_9         */
#define  MMEADC01B_REG_TONE_GAIN1_10             0x001020D0              /* TONE_GAIN1_10        */
#define  MMEADC01B_REG_TONE_GAIN2_10             0x001020D4              /* TONE_GAIN2_10        */
#define  MMEADC01B_REG_TONE_GAIN3_10             0x001020D8              /* TONE_GAIN3_10        */
#define  MMEADC01B_REG_TONE_GAIN4_10             0x001020DC              /* TONE_GAIN4_10        */

/*  BAR 4: CAL Tone > FIR filter coefficients */
#define  MMEADC01B_REG_TONE_FIR_ON               0x00102100              /* TONE_FIR_ON          */
#define  MMEADC01B_REG_TONE_FIR_UPD              0x00102108              /* TONE_FIR_UPD         */
#define  MMEADC01B_REG_TONE_FIR_CH_SEL           0x0010210C              /* TONE_FIR_CH_SEL      */

/*  BAR 4: CAL Tone > FIR filter coefficients */
#define  MMEADC01B_REG_TONE_FIR_COEFF_0          0x00102110              /* TONE_FIR_COEFF_0     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_1          0x00102114              /* TONE_FIR_COEFF_1     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_2          0x00102118              /* TONE_FIR_COEFF_2     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_3          0x0010211C              /* TONE_FIR_COEFF_3     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_4          0x00102120              /* TONE_FIR_COEFF_4     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_5          0x00102124              /* TONE_FIR_COEFF_5     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_6          0x00102128              /* TONE_FIR_COEFF_6     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_7          0x0010212C              /* TONE_FIR_COEFF_7     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_8          0x00102130              /* TONE_FIR_COEFF_8     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_9          0x00102134              /* TONE_FIR_COEFF_9     */
#define  MMEADC01B_REG_TONE_FIR_COEFF_10         0x00102138              /* TONE_FIR_COEFF_10    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_11         0x0010213C              /* TONE_FIR_COEFF_11    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_12         0x00102140              /* TONE_FIR_COEFF_12    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_13         0x00102144              /* TONE_FIR_COEFF_13    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_14         0x00102148              /* TONE_FIR_COEFF_14    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_15         0x0010214C              /* TONE_FIR_COEFF_15    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_16         0x00102150              /* TONE_FIR_COEFF_16    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_17         0x00102154              /* TONE_FIR_COEFF_17    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_18         0x00102158              /* TONE_FIR_COEFF_18    */
#define  MMEADC01B_REG_TONE_FIR_COEFF_19         0x0010215C              /* TONE_FIR_COEFF_19    */
//#define  MMEADC01B_REG_TONE_FIR_COEFF_20       0x00102160              /* TONE_FIR_COEFF_20    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_21       0x00102164              /* TONE_FIR_COEFF_21    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_22       0x00102168              /* TONE_FIR_COEFF_22    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_23       0x0010216C              /* TONE_FIR_COEFF_23    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_24       0x00102170              /* TONE_FIR_COEFF_24    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_25       0x00102174              /* TONE_FIR_COEFF_25    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_26       0x00102178              /* TONE_FIR_COEFF_26    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_27       0x0010217C              /* TONE_FIR_COEFF_27    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_28       0x00102180              /* TONE_FIR_COEFF_28    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_29       0x00102184              /* TONE_FIR_COEFF_29    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_30       0x00102188              /* TONE_FIR_COEFF_30    */ // saves FPGA resources
//#define  MMEADC01B_REG_TONE_FIR_COEFF_31       0x0010218C              /* TONE_FIR_COEFF_31    */ // saves FPGA resources

/*  BAR 4: CAL Tone >   */
#define  MMEADC01B_REG_TONE_TX_CTRL_L            0x001021A0              /* TONE_TX_CTRL_L       */
#define  MMEADC01B_REG_TONE_TX_CTRL_H            0x001021A4              /* TONE_TX_CTRL_H       */
#define  MMEADC01B_REG_TONE_CH_SEL_L             0x001021A8              /* TONE_CH_SEL_L        */
#define  MMEADC01B_REG_TONE_CH_SEL_H             0x001021AC              /* TONE_CH_SEL_H        */
#define  MMEADC01B_REG_TONE_TRANS_TIME           0x001021B0              /* TONE_TRANS_TIME      */

/*
 * 31 30        17 16   12 11       0
 * +-+------------+-+----------------+
 * |W|  (_RSVD_)  |     next addr    |
 * +-+------------+-+----------------+
 *
 *   bit 31   : wrapped            ... 0:no wrapped, 1:wrapped
 *   bit 30-17: (_Reserved_)
 *   bit 16-0 : next address       ... next address to be stored
 */
#define  MMEADC01B_REG_TONE_ADDR_1               0x001021B8              /* TONE_ADDR_1          */
#define  MMEADC01B_REG_TONE_ADDR_2               0x001021BC              /* TONE_ADDR_2          */
#define  MMEADC01B_REG_TONE_ADDR_3               0x001021C0              /* TONE_ADDR_3          */
#define  MMEADC01B_REG_TONE_ADDR_4               0x001021C4              /* TONE_ADDR_4          */
#define  MMEADC01B_REG_TONE_ADDR_5               0x001021C8              /* TONE_ADDR_5          */
#define  MMEADC01B_REG_TONE_ADDR_6               0x001021CC              /* TONE_ADDR_6          */
#define  MMEADC01B_REG_TONE_ADDR_7               0x001021D0              /* TONE_ADDR_7          */
#define  MMEADC01B_REG_TONE_ADDR_8               0x001021D4              /* TONE_ADDR_8          */
#define  MMEADC01B_REG_TONE_ADDR_9               0x001021D8              /* TONE_ADDR_9          */
#define  MMEADC01B_REG_TONE_ADDR_10              0x001021DC              /* TONE_ADDR_10         */

#define  MMEADC01B_REG_TONE_ADDR(ch)    (MMEADC01B_REG_TONE_ADDR_1 + ((ch) * 4))

#define  MMEADC01B_REG_TONE_CURR_CH_L            0x001021E0              /* TONE_CURR_CH_L       */
#define  MMEADC01B_REG_TONE_CURR_CH_H            0x001021E4              /* TONE_CURR_CH_H       */

/*  BAR 4: BPM[12] COD SA waveforms  */
#define  MMEADC01B_REG_BPM1_COD_SA               0x00140000              /* BPM 1  COD SA        */
#define  MMEADC01B_REG_BPM2_COD_SA               0x00148000              /* BPM  2 COD SA        */

#define  MMEADC01B_REG_SRAM_SA(ch)  (MMEADC01B_REG_BPM1_COD_SA + (LEN_BPM_DAT_SP * (ch)))

/*  BAR 4: SP   > BPM mask  */
/*
* mast bits assignment each mask (mask 1-8):
 *          31                               0
 *          +---------------------------------+
 *   0x0000 |31                              0|
 *          +---------------------------------+
 *   0x0004 |63                             32|
 *          +---------------------------------+
 *      :                    :
 *          +---------------------------------+
 *   0x01FC |4095                         4064|
 *          +---------------------------------+
 */
#define  MMEADC01B_REG_SP_BPM1_MASK1             0x00180000              /* SP_BPM1_MASK1        */
#define  MMEADC01B_REG_SP_BPM1_MASK2             0x00180200              /* SP_BPM1_MASK2        */
#define  MMEADC01B_REG_SP_BPM1_MASK3             0x00180400              /* SP_BPM1_MASK3        */
#define  MMEADC01B_REG_SP_BPM1_MASK4             0x00180600              /* SP_BPM1_MASK4        */
//#define  MMEADC01B_REG_SP_BPM1_MASK5           0x00180800              /* SP_BPM1_MASK5        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM1_MASK6           0x00180A00              /* SP_BPM1_MASK6        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM1_MASK7           0x00180C00              /* SP_BPM1_MASK7        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM1_MASK8           0x00180E00              /* SP_BPM1_MASK8        */ // saves FPGA resources

#define  MMEADC01B_REG_SP_BPM2_MASK1             0x00181000              /* SP_BPM2_MASK1        */
#define  MMEADC01B_REG_SP_BPM2_MASK2             0x00181200              /* SP_BPM2_MASK2        */
#define  MMEADC01B_REG_SP_BPM2_MASK3             0x00181400              /* SP_BPM2_MASK3        */
#define  MMEADC01B_REG_SP_BPM2_MASK4             0x00181600              /* SP_BPM2_MASK4        */
//#define  MMEADC01B_REG_SP_BPM2_MASK5           0x00181800              /* SP_BPM2_MASK5        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM2_MASK6           0x00181A00              /* SP_BPM2_MASK6        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM2_MASK7           0x00181C00              /* SP_BPM2_MASK7        */ // saves FPGA resources
//#define  MMEADC01B_REG_SP_BPM2_MASK8           0x00181E00              /* SP_BPM2_MASK8        */ // saves FPGA resources

/*  BAR 4: SP   > coefficients of polynominal  */
#define  MMEADC01B_REG_BPM1_POLY_4NODE_A00       0x001A0000              /* BPM1_POLY_4NODE_A00  */
#define  MMEADC01B_REG_BPM1_POLY_4NODE_B00       0x001A0100              /* BPM1_POLY_4NODE_B00  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_1_A00     0x001A0200              /* BPM1_POLY_3NODE_1_A0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_1_B00     0x001A0300              /* BPM1_POLY_3NODE_1_B0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_2_A00     0x001A0400              /* BPM1_POLY_3NODE_2_A0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_2_B00     0x001A0500              /* BPM1_POLY_3NODE_2_B0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_3_A00     0x001A0600              /* BPM1_POLY_3NODE_3_A0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_3_B00     0x001A0700              /* BPM1_POLY_3NODE_3_B0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_4_A00     0x001A0800              /* BPM1_POLY_3NODE_4_A0 */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_4_B00     0x001A0900              /* BPM1_POLY_3NODE_4_B0 */

#define  MMEADC01B_REG_BPM2_POLY_4NODE_A00       0x001A0A00              /* BPM2_POLY_4NODE_A00  */
#define  MMEADC01B_REG_BPM2_POLY_4NODE_B00       0x001A0B00              /* BPM2_POLY_4NODE_B00  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_1_A00     0x001A0C00              /* BPM2_POLY_3NODE_1_A0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_1_B00     0x001A0D00              /* BPM2_POLY_3NODE_1_B0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_2_A00     0x001A0E00              /* BPM2_POLY_3NODE_2_A0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_2_B00     0x001A0F00              /* BPM2_POLY_3NODE_2_B0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_3_A00     0x001A1000              /* BPM2_POLY_3NODE_3_A0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_3_B00     0x001A1100              /* BPM2_POLY_3NODE_3_B0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_4_A00     0x001A1200              /* BPM2_POLY_3NODE_4_A0 */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_4_B00     0x001A1300              /* BPM2_POLY_3NODE_4_B0 */

#define            OFS_SP_POLY_00                      0x00              /*    OFS_SP_POLY_00    */
#define            OFS_SP_POLY_01                      0x04              /*    OFS_SP_POLY_01    */
#define            OFS_SP_POLY_02                      0x08              /*    OFS_SP_POLY_02    */
#define            OFS_SP_POLY_03                      0x0C              /*    OFS_SP_POLY_03    */
#define            OFS_SP_POLY_04                      0x10              /*    OFS_SP_POLY_04    */
#define            OFS_SP_POLY_05                      0x14              /*    OFS_SP_POLY_05    */
#define            OFS_SP_POLY_06                      0x18              /*    OFS_SP_POLY_06    */
#define            OFS_SP_POLY_07                      0x1C              /*    OFS_SP_POLY_07    */
#define            OFS_SP_POLY_10                      0x20              /*    OFS_SP_POLY_10    */
#define            OFS_SP_POLY_11                      0x24              /*    OFS_SP_POLY_11    */
#define            OFS_SP_POLY_12                      0x28              /*    OFS_SP_POLY_12    */
#define            OFS_SP_POLY_13                      0x2C              /*    OFS_SP_POLY_13    */
#define            OFS_SP_POLY_14                      0x30              /*    OFS_SP_POLY_14    */
#define            OFS_SP_POLY_15                      0x34              /*    OFS_SP_POLY_15    */
#define            OFS_SP_POLY_16                      0x38              /*    OFS_SP_POLY_16    */
#define            OFS_SP_POLY_20                      0x40              /*    OFS_SP_POLY_20    */
#define            OFS_SP_POLY_21                      0x44              /*    OFS_SP_POLY_21    */
#define            OFS_SP_POLY_22                      0x48              /*    OFS_SP_POLY_22    */
#define            OFS_SP_POLY_23                      0x4C              /*    OFS_SP_POLY_23    */
#define            OFS_SP_POLY_24                      0x50              /*    OFS_SP_POLY_24    */
#define            OFS_SP_POLY_25                      0x54              /*    OFS_SP_POLY_25    */
#define            OFS_SP_POLY_30                      0x60              /*    OFS_SP_POLY_30    */
#define            OFS_SP_POLY_31                      0x64              /*    OFS_SP_POLY_31    */
#define            OFS_SP_POLY_32                      0x68              /*    OFS_SP_POLY_32    */
#define            OFS_SP_POLY_33                      0x6C              /*    OFS_SP_POLY_33    */
#define            OFS_SP_POLY_34                      0x70              /*    OFS_SP_POLY_34    */
#define            OFS_SP_POLY_40                      0x80              /*    OFS_SP_POLY_40    */
#define            OFS_SP_POLY_41                      0x84              /*    OFS_SP_POLY_41    */
#define            OFS_SP_POLY_42                      0x88              /*    OFS_SP_POLY_42    */
#define            OFS_SP_POLY_43                      0x8C              /*    OFS_SP_POLY_43    */
#define            OFS_SP_POLY_50                      0xA0              /*    OFS_SP_POLY_50    */
#define            OFS_SP_POLY_51                      0xA4              /*    OFS_SP_POLY_51    */
#define            OFS_SP_POLY_52                      0xA8              /*    OFS_SP_POLY_52    */
#define            OFS_SP_POLY_60                      0xC0              /*    OFS_SP_POLY_60    */
#define            OFS_SP_POLY_61                      0xC4              /*    OFS_SP_POLY_61    */
#define            OFS_SP_POLY_70                      0xE0              /*    OFS_SP_POLY_70    */

/*  BAR 4: CAL Tone >  */
/*
 * CAL TONE:                        pt:                                    TONE:                            I, Q:
 *  +-----------------------+ ------ +--------------------+  -------------  +--------------------+ --------- +--------------------+
 *  | ADC ch 1 (pt: 0..255) |        | [0]                | TONE 1..4       | TONE 1             | I, Q      | I                  |
 *  +-----------------------+        +--------------------+                 +--------------------+ _         +--------------------+
 *  | ADC ch 2              | \      | [1]                |  \              | TONE  2            |    - _    |   Q                |
 *  +-----------------------+  \     +--------------------+     \           +--------------------+         - +--------------------+
 *  | ADC ch 3              |   \    | [2]                |        \        | TONE   3           |
 *  +-----------------------+        +--------------------+           \     +--------------------+
 *          :                                :                           \  | TONE    4          |
 *  +-----------------------+     \  +--------------------+                 +--------------------+
 *  | ADC ch 10             |      \ | [255]              |
 *  +-----------------------+        +--------------------+
 */
#define  MMEADC01B_REG_TONE_1                    0x001C0000              /* TONE_1               */
#define  MMEADC01B_REG_TONE_2                    0x001C2000              /* TONE_2               */
#define  MMEADC01B_REG_TONE_3                    0x001C4000              /* TONE_3               */
#define  MMEADC01B_REG_TONE_4                    0x001C6000              /* TONE_4               */
#define  MMEADC01B_REG_TONE_5                    0x001C8000              /* TONE_5               */ // mind the gap between 5 and 6
#define  MMEADC01B_REG_TONE_6                    0x001D0000              /* TONE_6               */ // mind the gap between 5 and 6
#define  MMEADC01B_REG_TONE_7                    0x001D2000              /* TONE_7               */
#define  MMEADC01B_REG_TONE_8                    0x001D4000              /* TONE_8               */
#define  MMEADC01B_REG_TONE_9                    0x001D6000              /* TONE_9               */
#define  MMEADC01B_REG_TONE_10                   0x001D8000              /* TONE_10              */

#define  N_MMEADC01B_CAL_POINTS                         256

#define  N_MMEADC01B_CAL_TONES                            4

#define            OFS_TONE1_I                         0x00              /*    OFS_TONE1_I       */
#define            OFS_TONE1_Q                         0x04              /*    OFS_TONE1_Q       */
#define            OFS_TONE2_I                         0x08              /*    OFS_TONE2_I       */
#define            OFS_TONE2_Q                         0x0C              /*    OFS_TONE2_Q       */
#define            OFS_TONE3_I                         0x10              /*    OFS_TONE3_I       */
#define            OFS_TONE3_Q                         0x14              /*    OFS_TONE3_Q       */
#define            OFS_TONE4_I                         0x18              /*    OFS_TONE4_I       */
#define            OFS_TONE4_Q                         0x1C              /*    OFS_TONE4_Q       */

#define  MMEADC01B_REG_SRAM_TONE(ch)    (MMEADC01B_REG_TONE_1 + (LEN_TONE_DAT  * (ch)))

/*  BAR 4: SP  > waveform */
#define  MMEADC01B_REG_SP_1                      0x001E0000              /* SP_1                 */
#define  MMEADC01B_REG_SP_2                      0x001E4000              /* SP_2                 */
#define  MMEADC01B_REG_SP_3                      0x001E8000              /* SP_3                 */
#define  MMEADC01B_REG_SP_4                      0x001EC000              /* SP_4                 */
#define  MMEADC01B_REG_SP_7                      0x001F0000              /* SP_7                 */
#define  MMEADC01B_REG_SP_8                      0x001F4000              /* SP_8                 */
#define  MMEADC01B_REG_SP_9                      0x001F8000              /* SP_9                 */
#define  MMEADC01B_REG_SP_10                     0x001FC000              /* SP_10                */

#define  MMEADC01B_REG_SRAM_SP(ch_msk)    (MMEADC01B_REG_SP_1 + (LEN_SP_DAT  * (ch_msk)))

#endif  /* MMEADC01B_REGS_H */
