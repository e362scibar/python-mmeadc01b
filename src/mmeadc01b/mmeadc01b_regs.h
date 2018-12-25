/**
 * @file     mmeadc01b_regs.h
 * @brief    MME-ADC01-B FPGA register map (2017-11-21 ver.)
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
#define   N_TONE_POINTS                           (     256)             /* # of CAL Tone     points/SRAM  256[pt]  */
#define     N_SP_POINTS                           ( 4 << 10)             /* # of SP           points/SRAM   4k[pt]  */
#define    N_BPM_POINTS_TBT                       (64 << 10)             /* # of BPM COD TbT  points/SRAM  64k[pt]  */
#define    N_BPM_POINTS_FA                        (64 << 10)             /* # of BPM COD FA   points/SRAM  64k[pt]  */
#define    N_BPM_POINTS_SA                        (     256)             /* # of BPM COD SA   points/SRAM  256[pt]  */
#define    N_BPM_POINTS_SP                        (64 << 10)             /* # of BPM SP Proc  points/SRAM  64k[pt]  */

#define  LEN_ADC_DAT                          (N_ADC_POINTS      * 4)   /* length of ADC sampling data (unit: [B]) */
#define  LEN_DDC_DAT                          (N_DDC_POINTS      * 4)   /* length of DDC sampling data (unit: [B]) */
#define  LEN_DAC_DAT                          (N_DAC_POINTS      * 4)   /* length of DAC sampling data (unit: [B]) */
#define  LEN_TONE_DAT                        (N_TONE_POINTS *  8 * 4)   /* length of CAL Tone     data (unit: [B]) */
#define  LEN_SP_DAT                          (  N_SP_POINTS      * 4)   /* length of Single Path  data (unit: [B]) */
#define  LEN_BPM_DAT_TBT                 ( N_BPM_POINTS_TBT * 16 * 4)   /* length of BPM COD TbT  data (unit: [B]) */
#define  LEN_BPM_DAT_FA                  ( N_BPM_POINTS_FA  * 16 * 4)   /* length of BPM COD FA   data (unit: [B]) */
#define  LEN_BPM_DAT_SA                  ( N_BPM_POINTS_SA  * 32 * 4)   /* length of BPM COD SA   data (unit: [B]) */
#define  LEN_BPM_DAT_SP                  ( N_BPM_POINTS_SP  * 64 * 4)   /* length of BPM SP Proc  data (unit: [B]) */

#define  LEN_BPM_DAT_UNIT_TBT  (16 * 4)
#define  LEN_BPM_DAT_UNIT_FA   (16 * 4)
#define  LEN_BPM_DAT_UNIT_SA   (32 * 4)
#define  LEN_BPM_DAT_UNIT_SP   (64 * 4)

#define  LEN_BPM_DAT_SP_AREA             ( N_BPM_POINTS_SP  * 64    )   /* length of BPM SP Proc  data (unit: [B]) */

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
#define  DDC_CH_IQ_11                                    20
#define  DDC_CH_IQ_12                                    21
#define  DDC_CH_IQ_13                                    22
#define  DDC_CH_IQ_14                                    23
#define  DDC_CH_IQ_15                                    24
#define  DDC_CH_IQ_16                                    25
#define  TONE_CH_1                                       26  /* CAL Tone ch */
#define  TONE_CH_2                                       27
#define  TONE_CH_3                                       28
#define  TONE_CH_4                                       29
#define  TONE_CH_5                                       30
#define  TONE_CH_6                                       31
#define  TONE_CH_7                                       32
#define  TONE_CH_8                                       33
#define  TONE_CH_9                                       34
#define  TONE_CH_10                                      35
#define  SP_CH_1                                         36  /* SP  channels */
#define  SP_CH_2                                         37
#define  SP_CH_3                                         38
#define  SP_CH_4                                         39
#define  SP_CH_7                                         40
#define  SP_CH_8                                         41
#define  SP_CH_9                                         42
#define  SP_CH_10                                        43
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

#define  N_ADC_CH                                        10      /* ADC: 5 devices x 2 ch      */
#define  N_DDC_CH                                        16      /* DDC: ADC 10ch + 6 extra ch */
#define  N_TONE_CH                                 N_ADC_CH      /* same as ADC channels       */
#define  N_SP_CH                                  (N_ADC_CH - 2) /* -2: ch 5 and 6             */
#define  N_BPM_CH                                         2      /* BPM1 and BPM2              */
#define  N_BPM_SP_AREAS                                   4      /* SP Process consists of 4 areas */

/** @todo:ymzk: 26ch -> 44ch  */
/*  - DATA acq. channels      */
/*
 *    6 6 6 6 5 5 5 5 5 5 5 5 5 5 4 4 4 4 4 4 4 4 4 4 3 3 3 3 3 3 3 3
 *    3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2
 *   +---------------+---------------+---+-+-+-------+-------+-------+
 *   |                                   |B|B|               | CAL   |
 *   |            (_Reserved_)           |P|P| SP ch 10-1    |  TONE |
 *   |                                   |M|M| (except ch6-5)| ch    |
 *   |                                   |2|1|               |  10-7 |
 *   +---------------+---------------+---+-+-+-------+-------+-------+
 *
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-----------+---+-------+-------+-----------+---+---------------+
 *   | CAL Tone  | DDC extra |                   |                   |
 *   |   ch 6-1  |  ch 15-11 | DDC ch 10-1/base  | ADC ch 10-1       |
 *   |           |  (I/Q)    |  (I/Q)            |  (RAW)            |
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

#define  DAT_CH_TONE_1                                BIT26
#define  DAT_CH_TONE_2                                BIT27
#define  DAT_CH_TONE_3                                BIT28
#define  DAT_CH_TONE_4                                BIT29
#define  DAT_CH_TONE_5                                BIT30
#define  DAT_CH_TONE_6                                BIT31
#define  DAT_CH_TONE_7                                BIT32
#define  DAT_CH_TONE_8                                BIT33
#define  DAT_CH_TONE_9                                BIT34
#define  DAT_CH_TONE_10                               BIT35

#define  DAT_CH_SP_1                                  BIT36
#define  DAT_CH_SP_2                                  BIT37
#define  DAT_CH_SP_3                                  BIT38
#define  DAT_CH_SP_4                                  BIT39
#define  DAT_CH_SP_7                                  BIT40
#define  DAT_CH_SP_8                                  BIT41
#define  DAT_CH_SP_9                                  BIT42
#define  DAT_CH_SP_10                                 BIT43

#define  DAT_CH_BPM_1                                 BIT44
#define  DAT_CH_BPM_2                                 BIT45

#define  DAT_CH_ADC                              0x000003FF  /* bit  9-0  */
#define  DAT_CH_DDC                              0x03FFFC00  /* bit 25-10 */
#define  DAT_CH_TONE          __UINT64_C(0x0000000FFC000000) /* bit 35-26 */
#define  DAT_CH_SP            __UINT64_C(0x00000FF000000000) /* bit 43-36 */
#define  DAT_CH_BPM1          __UINT64_C(0x0000100000000000) /* bit 44    */
#define  DAT_CH_BPM2          __UINT64_C(0x0000200000000000) /* bit 45    */
#define  DAT_CH_ACQ                     (DAT_CH_ADC | DAT_CH_DDC | DAT_CH_TONE | DAT_CH_SP)

/*
 * INT_SRC:
 * INT_CLR:
 * INT_MSK:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-+-+-----------+---------------+-----------+-+-+---------+-+-+-+
 *   |D|I|                                       |B|B|         |S|I|A|
 *   |M|L|             (_Reserved_)              |P|P| (_RSVD_)|P|/|D|
 *   |A|K|                                       |M|M|         | |Q|C|
 *   | | |                                       |2|1|         | | | |
 *   +-+-+-----------+---------------+-----------+-+-+---------+-+-+-+
 *             bit 31   : DMA
 *             bit 30   : Inter lock
 *             bit 29-10: (_Reserved_)
 *             bit  9   : BPM2 data       (T.B.D.)
 *             bit  8   : BPM1 data
 *             bit  7-3 : (_Reserved_)
 *             bit  2   : SP  ch
 *             bit  1   : I/Q ch
 *             bit  0   : ADC ch
 */
#define  INT_SRC_NONE                                     0 /* no interrupt occured */

#define  INT_SRC_DMA                                  BIT31
#define  INT_SRC_INTL                                 BIT30
#define  INT_SRC_BPM2                                  BIT9
#define  INT_SRC_BPM1                                  BIT8
#define  INT_SRC_SP                                    BIT2
#define  INT_SRC_DDC                                   BIT1
#define  INT_SRC_ADC                                   BIT0

#define  INT_SRC_ACQ                           (INT_SRC_DDC | INT_SRC_ADC)

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
#define  MMEADC01B_REG_LED                       0x0000D010              /* LED               */

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
#define  MMEADC01B_REG_DO_TESTMODE               0x0000D02C              /* DO_TESTMODE       */

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
#define  MMEADC01B_REG_DAC_OUT_SW_ON             0x0000D094              /* DAC_OUT_SW_ON      */
#define  MMEADC01B_REG_DAC_PAT_STEP              0x0000D098              /* DAC_PAT_STEP       */
#define  MMEADC01B_REG_DAC_PAT_DELAY             0x0000D09C              /* DAC_PAT_DELAY      */
#define  MMEADC01B_REG_DAC_PAT_REPEAT            0x0000D0A0              /* DAC_PAT_REPEAT     */
#define  MMEADC01B_REG_DAC_PAT_DEPTH             0x0000D0A4              /* DAC_PAT_DEPTH      */
#define  MMEADC01B_REG_DAC_PAT_UPD               0x0000D0A8              /* DAC_PAT_UPD        */

#define  MMEADC01B_REG_DAC_OUT_ROT_GAIN          0x0000D0B0              /* DAC_OUT_ROT_GAIN   */
#define  MMEADC01B_REG_DAC_OUT_ROT_THETA         0x0000D0B4              /* DAC_OUT_ROT_THETA  */

#define  MMEADC01B_DAC_OUT_ROT_GAIN_LSB              0x1000              /*  LSB = 2^12        */
#define  MMEADC01B_DAC_OUT_ROT_THETA_LSB             0x8000              /*  LSB = 2^15        */

#define  MMEADC01B_REG_DAC_OUT_LIMIT             0x0000D0BC              /* DAC_OUT_LIMIT      */
#define  MMEADC01B_REG_DAC_OUT_OFS               0x0000D0C0              /* DAC_OUT_OFS        */
#define  MMEADC01B_REG_DAC_OUT_STEP              0x0000D0C4              /* DAC_OUT_STEP       */
#define  MMEADC01B_REG_DAC_OUT_DELAY             0x0000D0C8              /* DAC_OUT_DELAY      */
#define  MMEADC01B_REG_DAC_OUT_SW_STATUS         0x0000D0D0              /* DAC_OUT_SW_STATUS  */

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
#define  MMEADC01B_REG_PEAKHOLD_ADC01            0x0000F120              /* PEAKHOLD_ADC01     */
#define  MMEADC01B_REG_PEAKHOLD_ADC02            0x0000F124              /* PEAKHOLD_ADC02     */
#define  MMEADC01B_REG_PEAKHOLD_ADC03            0x0000F128              /* PEAKHOLD_ADC03     */
#define  MMEADC01B_REG_PEAKHOLD_ADC04            0x0000F12C              /* PEAKHOLD_ADC04     */
#define  MMEADC01B_REG_PEAKHOLD_ADC05            0x0000F130              /* PEAKHOLD_ADC05     */
#define  MMEADC01B_REG_PEAKHOLD_ADC06            0x0000F134              /* PEAKHOLD_ADC06     */
#define  MMEADC01B_REG_PEAKHOLD_ADC07            0x0000F138              /* PEAKHOLD_ADC07     */
#define  MMEADC01B_REG_PEAKHOLD_ADC08            0x0000F13C              /* PEAKHOLD_ADC08     */
#define  MMEADC01B_REG_PEAKHOLD_ADC09            0x0000F140              /* PEAKHOLD_ADC09     */
#define  MMEADC01B_REG_PEAKHOLD_ADC10            0x0000F144              /* PEAKHOLD_ADC10     */

#define  MMEADC01B_REG_PEAKHOLD_ADC(ch)         (MMEADC01B_REG_PEAKHOLD_ADC01 + ((ch) * 4))

/* ************************************************************: BAR 2 */
#define  LEN_MMEADC01B_BAR_2                       (2 << 20)             /* BAR 2:   2 [MB]    */
/*   BAR 2: SRAM memory map */
# define  MMEADC01B_REG_ADC_1                    0x00000000              /* ADC_0     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_2                    0x00010000              /* ADC_1     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_3                    0x00020000              /* ADC_2     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_4                    0x00030000              /* ADC_3     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_5                    0x00040000              /* ADC_4     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_6                    0x00050000              /* ADC_5     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_7                    0x00060000              /* ADC_6     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_8                    0x00070000              /* ADC_7     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_9                    0x00080000              /* ADC_8     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_ADC_10                   0x00090000              /* ADC_9     [31-16]:ADC, [15:0]:fixed 0  */
# define  MMEADC01B_REG_DAC_2_1                  0x000A0000              /* DAC_1_0   [31-16]:ch2, [15:0]:ch1      */
# define  MMEADC01B_REG_DDC_IQ_1                 0x000C0000              /* DDC_IQ_0  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_2                 0x000C4000              /* DDC_IQ_1  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_3                 0x000C8000              /* DDC_IQ_2  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_4                 0x000CC000              /* DDC_IQ_3  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_5                 0x000D0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_6                 0x000D4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_7                 0x000D8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_8                 0x000DC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_9                 0x000E0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_10                0x000E4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_11                0x000E8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_12                0x000EC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_13                0x000F0000              /* DDC_IQ_4  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_14                0x000F4000              /* DDC_IQ_5  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_15                0x000F8000              /* DDC_IQ_6  [31-16]:Q  , [15:0]:I        */
# define  MMEADC01B_REG_DDC_IQ_16                0x000FC000              /* DDC_IQ_7  [31-16]:Q  , [15:0]:I        */

#define  MMEADC01B_REG_SRAM_ADC(   ch)   (MMEADC01B_REG_ADC_1    + (LEN_ADC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DAC(   ch)   (MMEADC01B_REG_DAC_2_1  + (LEN_DAC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DDC_IQ(ch)   (MMEADC01B_REG_DDC_IQ_1 + (LEN_DDC_DAT * (ch)))

/* ************************************************************: BAR 4: added for LLRF */
//#define  LEN_MMEADC01B_BAR_4                     (128 << 10)             /* BAR 4: 128 [kB]    */
#define  LEN_MMEADC01B_BAR_4                     (2 << 20)               /* BAR 4: 2 [MB]    */
/*  BAR 4: I/Q modualtion coefficients */
#define  MMEADC01B_REG_N_IQMOD_COEFF             0x00000000              /* N_IQMOD_COEFF      */
#define  MMEADC01B_REG_IQMOD_COEFF_0             0x00000004              /* IQMOD_COEFF_0      */
#define  MMEADC01B_REG_IQMOD_COEFF_1             0x00000008              /* IQMOD_COEFF_1      */
#define  MMEADC01B_REG_IQMOD_COEFF_2             0x0000000C              /* IQMOD_COEFF_2      */
#define  MMEADC01B_REG_IQMOD_COEFF_3             0x00000010              /* IQMOD_COEFF_3      */
#define  MMEADC01B_REG_IQMOD_COEFF_4             0x00000014              /* IQMOD_COEFF_4      */
#define  MMEADC01B_REG_IQMOD_COEFF_5             0x00000018              /* IQMOD_COEFF_5      */
#define  MMEADC01B_REG_IQMOD_COEFF_6             0x0000001C              /* IQMOD_COEFF_6      */
#define  MMEADC01B_REG_IQMOD_COEFF_7             0x00000020              /* IQMOD_COEFF_7      */
#define  MMEADC01B_REG_IQMOD_COEFF_8             0x00000024              /* IQMOD_COEFF_8      */
#define  MMEADC01B_REG_IQMOD_COEFF_9             0x00000028              /* IQMOD_COEFF_9      */
#define  MMEADC01B_REG_IQMOD_COEFF_A             0x0000002C              /* IQMOD_COEFF_A      */
#define  MMEADC01B_REG_IQMOD_COEFF_B             0x00000030              /* IQMOD_COEFF_B      */
#define  MMEADC01B_REG_IQMOD_COEFF_C             0x00000034              /* IQMOD_COEFF_C      */
#define  MMEADC01B_REG_IQMOD_COEFF_D             0x00000038              /* IQMOD_COEFF_D      */
#define  MMEADC01B_REG_IQMOD_COEFF_E             0x0000003C              /* IQMOD_COEFF_E      */
#define  MMEADC01B_REG_IQMOD_COEFF_F             0x00000040              /* IQMOD_COEFF_F      */

#define  N_MMEADC01B_IQMOD_COEFF                     0x0F
#define  MMEADC01B_REG_IQMOD_COEFF(id_coeff)    (MMEADC01B_REG_IQMOD_COEFF_0 + ((id_coeff) * 4))

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
#define  MMEADC01B_REG_VECTSUM_CAV_FB            0x000000D0              /* VECTSUM_CAV_FB     */
#define  MMEADC01B_REG_VECTSUM_KLY_FB            0x000000D4              /* VECTSUM_KLY_FB     */
#define  MMEADC01B_REG_VECTSUM_DACOUT            0x000000D8              /* VECTSUM_DACOUT     */
#define  MMEADC01B_REG_VECTSUM_SERIAL            0x000000DC              /* VECTSUM_SERIAL     */

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
 *   +-------------------+---+-------------------+-------------------+
 *   |     (_Reserved_)  |BPM|        I/Q        |        ADC        |
 *   +-------------------+---+-------------------+-------------------+
 *             bit 31-22: (_Reserved_)
 *             bit 21-20: BPM                 (BPM     2-1)
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
#define  INTL_SRC_RSVD_56                                56              /* (_Reserved_)       */
#define  INTL_SRC_RSVD_57                                57              /* (_Reserved_)       */
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
#define  MMEADC01B_REG_FIR_COEFF_17              0x00001094              /* FIR_COEFF_17       */
#define  MMEADC01B_REG_FIR_COEFF_18              0x00001098              /* FIR_COEFF_18       */
#define  MMEADC01B_REG_FIR_COEFF_19              0x0000109C              /* FIR_COEFF_19       */
#define  MMEADC01B_REG_FIR_COEFF_20              0x000010A0              /* FIR_COEFF_20       */
#define  MMEADC01B_REG_FIR_COEFF_21              0x000010A4              /* FIR_COEFF_21       */
#define  MMEADC01B_REG_FIR_COEFF_22              0x000010A8              /* FIR_COEFF_22       */
#define  MMEADC01B_REG_FIR_COEFF_23              0x000010AC              /* FIR_COEFF_23       */
#define  MMEADC01B_REG_FIR_COEFF_24              0x000010B0              /* FIR_COEFF_24       */
#define  MMEADC01B_REG_FIR_COEFF_25              0x000010B4              /* FIR_COEFF_25       */
#define  MMEADC01B_REG_FIR_COEFF_26              0x000010B8              /* FIR_COEFF_26       */
#define  MMEADC01B_REG_FIR_COEFF_27              0x000010BC              /* FIR_COEFF_27       */
#define  MMEADC01B_REG_FIR_COEFF_28              0x000010C0              /* FIR_COEFF_28       */
#define  MMEADC01B_REG_FIR_COEFF_29              0x000010C4              /* FIR_COEFF_29       */
#define  MMEADC01B_REG_FIR_COEFF_30              0x000010C8              /* FIR_COEFF_30       */
#define  MMEADC01B_REG_FIR_COEFF_31              0x000010CC              /* FIR_COEFF_31       */

#define  N_MMEADC01B_REG_FIR_COEFFS                      32
#define  MMEADC01B_REG_FIR_COEFF(id_coeff)      (MMEADC01B_REG_FIR_COEFF_0 + ((id_coeff) * 4))

/*  BAR 4: I/Q CIC filter coefficients */
#define  MMEADC01B_REG_CIC_DECIM_RATE_UPD        0x000010E0              /* CIC_DECIM_RATE_UPD */
#define  MMEADC01B_REG_CIC_DECIM_RATE            0x000010E4              /* CIC_DECIM_RATE     */

/*  BAR 4: COD > down sampling trigger */
#define  MMEADC01B_REG_COD_DS_INIT_TRIG          0x00100000              /* COD_DS_INIT_TRIG   */

/*  BAR 4: COD > CIC filter / decimator */
#define  MMEADC01B_REG_COD_CIC_R_TBT_UPD         0x00100010              /*  */
#define  MMEADC01B_REG_COD_CIC_R_TBT             0x00100014              /*  */
#define  MMEADC01B_REG_COD_CIC_R_FA_UPD          0x00100018              /*  */
#define  MMEADC01B_REG_COD_CIC_R_FA              0x0010001C              /*  */
#define  MMEADC01B_REG_COD_CIC_R_SA_UPD          0x00100020              /*  */
#define  MMEADC01B_REG_COD_CIC_R_SA              0x00100024              /*  */

/*  BAR 4: COD > CIC down-sampler */
#define  MMEADC01B_REG_COD_DS_T_TBT_UPD          0x00100028              /*  */
#define  MMEADC01B_REG_COD_DS_T_TBT              0x0010002C              /*  */
#define  MMEADC01B_REG_COD_DS_T_FA_UPD           0x00100030              /*  */
#define  MMEADC01B_REG_COD_DS_T_FA               0x00100034              /*  */
#define  MMEADC01B_REG_COD_DS_T_SA_UPD           0x00100038              /*  */
#define  MMEADC01B_REG_COD_DS_T_SA               0x0010003C              /*  */

/*  BAR 4: COD > FIR filter coefficients */
#define  MMEADC01B_REG_COD_FIR_ON                0x00100040              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_UPD         0x00100044              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_CHSEL       0x00100048              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_STRSEL      0x0010004C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_00          0x00100050              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_01          0x00100054              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_02          0x00100058              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_03          0x0010005C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_04          0x00100060              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_05          0x00100064              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_06          0x00100068              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_07          0x0010006C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_08          0x00100070              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_09          0x00100074              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_10          0x00100078              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_11          0x0010007C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_12          0x00100080              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_13          0x00100084              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_14          0x00100088              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_15          0x0010008C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_16          0x00100090              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_17          0x00100094              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_18          0x00100098              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_19          0x0010009C              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_20          0x001000A0              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_21          0x001000A4              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_22          0x001000A8              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_23          0x001000AC              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_24          0x001000B0              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_25          0x001000B4              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_26          0x001000B8              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_27          0x001000BC              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_28          0x001000C0              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_29          0x001000C4              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_30          0x001000C8              /*  */
#define  MMEADC01B_REG_COD_FIR_COEFF_31          0x001000CC              /*  */

#define  N_MMEADC01B_REG_COD_FIR_COEFFS                  32
#define  MMEADC01B_REG_COD_FIR_COEFF(id_coeff)   (MMEADC01B_REG_COD_FIR_COEFF_00 + ((id_coeff) * 4))

/*  BAR 4: SP  >  revolution frequency sync trigger */
#define  MMEADC01B_REG_SP_REV_INIT_TRIG          0x00100100              /*  */

/*  BAR 4: SP  >  waveform acquisition */
#define  MMEADC01B_REG_SP_REC_START              0x00100110              /*  */

#define  MMEADC01B_REG_SP_WAVE_SMPL_STEP         0x00100114              /*  */
#define  MMEADC01B_REG_SP_WAVE_TRIG_DELAY        0x00100118              /*  */

/*
 * 31 30          16 15             0
 * +-+--------------+----------------+
 * |W| next address to be stored     |
 * +-+--------------+----------------+
 *
 *   bit 31  : wrapped            ... 0:no wrapped, 1:wrapped
 *   bit 30-0: next address       ... next address to be stored
 */
#define  MMEADC01B_REG_SP_ADDR                   0x00100120              /*  */

#define  MMEADC01B_REG_SP_MASK_SEL               0x00100124              /*  */

/*  BAR 4: SP   > waveform > trigger mode */
#define  MMEADC01B_REG_SP_TRIG_FORCED            0x00000130              /*  */
#define  MMEADC01B_REG_SP_DI_TRIG_EN             0x00000134              /*  */

/*  BAR 4: BPM  > data xfer */
#define  MMEADC01B_REG_BPM_TX_CTRL               0x00100140              /*  */
#define  MMEADC01B_REG_BPM_TX_MODE               0x00100144              /*  */

#define  MMEADC01B_REG_BPM1_COD_BAR_TBT          0x00100150              /*  */
#define  MMEADC01B_REG_BPM1_COD_BAR_FA           0x00100154              /*  */
#define  MMEADC01B_REG_BPM1_COD_BAR_SA           0x00100158              /*  */
#define  MMEADC01B_REG_BPM1_SP_BAR               0x0010015C              /*  */

#define  MMEADC01B_REG_BPM2_COD_BAR_TBT          0x00100160              /*  */
#define  MMEADC01B_REG_BPM2_COD_BAR_FA           0x00100164              /*  */
#define  MMEADC01B_REG_BPM2_COD_BAR_SA           0x00100168              /*  */
#define  MMEADC01B_REG_BPM2_SP_BAR               0x0010016C              /*  */

#define  MMEADC01B_REG_BPM1_INTL_COD_BAR_TBT     0x00100170              /*  */
#define  MMEADC01B_REG_BPM1_INTL_COD_BAR_FA      0x00100174              /*  */
#define  MMEADC01B_REG_BPM1_INTL_COD_BAR_SA      0x00100178              /*  */
#define  MMEADC01B_REG_BPM1_INTL_SP_BAR          0x0010017C              /*  */

#define  MMEADC01B_REG_BPM2_INTL_COD_BAR_TBT     0x00100180              /*  */
#define  MMEADC01B_REG_BPM2_INTL_COD_BAR_FA      0x00100184              /*  */
#define  MMEADC01B_REG_BPM2_INTL_COD_BAR_SA      0x00100188              /*  */
#define  MMEADC01B_REG_BPM2_INTL_SP_BAR          0x0010018C              /*  */

#define  MMEADC01B_REG_BPM1_COD_CAP_TBT          0x00100190              /*  */
#define  MMEADC01B_REG_BPM1_COD_CAP_FA           0x00100194              /*  */
#define  MMEADC01B_REG_BPM1_COD_CAP_SA           0x00100198              /*  */
#define  MMEADC01B_REG_BPM1_SP_CAP               0x0010019C              /*  */

#define  MMEADC01B_REG_BPM2_COD_CAP_TBT          0x001001A0              /*  */
#define  MMEADC01B_REG_BPM2_COD_CAP_FA           0x001001A4              /*  */
#define  MMEADC01B_REG_BPM2_COD_CAP_SA           0x001001A8              /*  */
#define  MMEADC01B_REG_BPM2_SP_CAP               0x001001AC              /*  */

#define  MMEADC01B_REG_BPM1_INTL_COD_CAP_TBT     0x001001B0              /*  */
#define  MMEADC01B_REG_BPM1_INTL_COD_CAP_FA      0x001001B4              /*  */
#define  MMEADC01B_REG_BPM1_INTL_COD_CAP_SA      0x001001B8              /*  */
#define  MMEADC01B_REG_BPM1_INTL_SP_CAP          0x001001BC              /*  */

#define  MMEADC01B_REG_BPM2_INTL_COD_CAP_TBT     0x001001C0              /*  */
#define  MMEADC01B_REG_BPM2_INTL_COD_CAP_FA      0x001001C4              /*  */
#define  MMEADC01B_REG_BPM2_INTL_COD_CAP_SA      0x001001C8              /*  */
#define  MMEADC01B_REG_BPM2_INTL_SP_CAP          0x001001CC              /*  */

/*  BAR 4: BPM  > amplitude offsets */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_1         0x00101000              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_2         0x00101004              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_3         0x00101008              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_4         0x0010100C              /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_TBT_5                               /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_TBT_6                               /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_7         0x00101010              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_8         0x00101014              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_9         0x00101018              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_TBT_10        0x0010101C              /*  */

#define  MMEADC01B_REG_BPM_OFS_COD_FA_1          0x00101020              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_2          0x00101024              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_3          0x00101028              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_4          0x0010102C              /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_FA_5                                /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_FA_6                                /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_7          0x00101030              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_8          0x00101034              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_9          0x00101038              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_FA_10         0x0010103C              /*  */

#define  MMEADC01B_REG_BPM_OFS_COD_SA_1          0x00101040              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_2          0x00101044              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_3          0x00101048              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_4          0x0010104C              /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_SA_5                                /*  */
//#define  MMEADC01B_REG_BPM_OFS_COD_SA_6                                /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_7          0x00101050              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_8          0x00101054              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_9          0x00101058              /*  */
#define  MMEADC01B_REG_BPM_OFS_COD_SA_10         0x0010105C              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_1        0x00101060              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_1        0x00101064              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_1        0x00101068              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_1        0x0010106C              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_1        0x00101070              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_1        0x00101074              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_1        0x00101078              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_1        0x0010107C              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_2        0x00101080              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_2        0x00101084              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_2        0x00101088              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_2        0x0010108C              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_2        0x00101090              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_2        0x00101094              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_2        0x00101098              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_2        0x0010109C              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_3        0x001010A0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_3        0x001010A4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_3        0x001010A8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_3        0x001010AC              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_3        0x001010B0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_3        0x001010B4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_3        0x001010B8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_3        0x001010BC              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_4        0x001010C0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_4        0x001010C4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_4        0x001010C8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_4        0x001010CC              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_4        0x001010D0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_4        0x001010D4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_4        0x001010D8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_4        0x001010DC              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_7        0x001010E0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_7        0x001010E4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_7        0x001010E8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_7        0x001010EC              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_7        0x001010F0              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_7        0x001010F4              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_7        0x001010F8              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_7        0x001010FC              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_8        0x00101100              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_8        0x00101104              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_8        0x00101108              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_8        0x0010110C              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_8        0x00101110              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_8        0x00101114              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_8        0x00101118              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_8        0x0010111C              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_9        0x00101120              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_9        0x00101124              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_9        0x00101128              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_9        0x0010112C              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_9        0x00101130              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_9        0x00101134              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_9        0x00101138              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_9        0x0010113C              /*  */

#define  MMEADC01B_REG_BPM_OFS_SP_MASK1_10       0x00101140              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK2_10       0x00101144              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK3_10       0x00101148              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK4_10       0x0010114C              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK5_10       0x00101150              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK6_10       0x00101154              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK7_10       0x00101158              /*  */
#define  MMEADC01B_REG_BPM_OFS_SP_MASK8_10       0x0010115C              /*  */

/*  BAR 4: BPM  > COD FA w/ three detectors */
#define  MMEADC01B_REG_BPM3_COD_FA_3_SEL         0x00100160              /*  */

/*  BAR 4: BPM  > interlock for COD FA */
#define  MMEADC01B_REG_BPM_SELF_TRIG_EN          0x00100170              /*  */
#define  MMEADC01B_REG_BPM_SELF_TRIG_SRC         0x00100174              /*  */

#define  MMEADC01B_REG_BPM1_X_THOLD_SELFTRIG_H   0x00100178              /*  */
#define  MMEADC01B_REG_BPM1_Y_THOLD_SELFTRIG_H   0x0010017C              /*  */
#define  MMEADC01B_REG_BPM1_X_THOLD_SELFTRIG_L   0x00100180              /*  */
#define  MMEADC01B_REG_BPM1_Y_THOLD_SELFTRIG_L   0x00100184              /*  */

#define  MMEADC01B_REG_BPM2_X_THOLD_SELFTRIG_H   0x00100188              /*  */
#define  MMEADC01B_REG_BPM2_Y_THOLD_SELFTRIG_H   0x0010018C              /*  */
#define  MMEADC01B_REG_BPM2_X_THOLD_SELFTRIG_L   0x00100190              /*  */
#define  MMEADC01B_REG_BPM2_Y_THOLD_SELFTRIG_L   0x00100194              /*  */

/*  BAR 4: BPM  > DEBUG */
#define  MMEADC01B_REG_BPM_DEBUG_SET0            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET1            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET2            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET3            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET4            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET5            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET6            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_SET7            0x00100000              /*  */

#define  MMEADC01B_REG_BPM_DEBUG_MON0            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON1            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON2            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON3            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON4            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON5            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON6            0x00100000              /*  */
#define  MMEADC01B_REG_BPM_DEBUG_MON7            0x00100000              /*  */

/*  BAR 4: CAL Tone > configuration */
#define  MMEADC01B_REG_TONE_NCO_1_FREQ           0x00102000              /*  */
#define  MMEADC01B_REG_TONE_NCO_2_FREQ           0x00102004              /*  */
#define  MMEADC01B_REG_TONE_NCO_3_FREQ           0x00102008              /*  */
#define  MMEADC01B_REG_TONE_NCO_4_FREQ           0x0010200C              /*  */

#define  MMEADC01B_REG_TONE_CIC1_R_UPD           0x00102010              /*  */
#define  MMEADC01B_REG_TONE_CIC1_R               0x00102014              /*  */
#define  MMEADC01B_REG_TONE_CIC2_R_UPD           0x00102018              /*  */
#define  MMEADC01B_REG_TONE_CIC2_R               0x0010201C              /*  */
#define  MMEADC01B_REG_TONE_DS_T_UPD             0x00102020              /*  */
#define  MMEADC01B_REG_TONE_DS_T                 0x00102024              /*  */

/*  BAR 4: CAL Tone > gain */
#define  MMEADC01B_REG_TONE_GAIN1_1              0x00102040              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_1              0x00102044              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_1              0x00102048              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_1              0x0010204C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_2              0x00102050              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_2              0x00102054              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_2              0x00102058              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_2              0x0010205C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_3              0x00102060              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_3              0x00102064              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_3              0x00102068              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_3              0x0010206C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_4              0x00102070              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_4              0x00102074              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_4              0x00102078              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_4              0x0010207C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_5              0x00102080              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_5              0x00102084              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_5              0x00102088              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_5              0x0010208C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_6              0x00102090              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_6              0x00102094              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_6              0x00102098              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_6              0x0010209C              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_7              0x001020A0              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_7              0x001020A4              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_7              0x001020A8              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_7              0x001020AC              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_8              0x001020B0              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_8              0x001020B4              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_8              0x001020B8              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_8              0x001020BC              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_9              0x001020C0              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_9              0x001020C4              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_9              0x001020C8              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_9              0x001020CC              /*  */
#define  MMEADC01B_REG_TONE_GAIN1_10             0x001020D0              /*  */
#define  MMEADC01B_REG_TONE_GAIN2_10             0x001020D4              /*  */
#define  MMEADC01B_REG_TONE_GAIN3_10             0x001020D8              /*  */
#define  MMEADC01B_REG_TONE_GAIN4_10             0x001020DC              /*  */

/*  BAR 4: CAL Tone > FIR filter coefficients */
#define  MMEADC01B_REG_TONE_FIR_ON               0x00102100              /*  */
#define  MMEADC01B_REG_TONE_FIR_UPD              0x00102108              /*  */
#define  MMEADC01B_REG_TONE_FIR_CH_SEL           0x0010210C              /*  */

/*  BAR 4: CAL Tone > FIR filter coefficients */
#define  MMEADC01B_REG_TONE_FIR_COEFF_0          0x00102110              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_1          0x00102114              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_2          0x00102118              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_3          0x0010211C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_4          0x00102120              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_5          0x00102124              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_6          0x00102128              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_7          0x0010212C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_8          0x00102130              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_9          0x00102134              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_10         0x00102138              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_11         0x0010213C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_12         0x00102140              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_13         0x00102144              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_14         0x00102148              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_15         0x0010214C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_16         0x00102150              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_17         0x00102154              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_18         0x00102158              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_19         0x0010215C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_20         0x00102160              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_21         0x00102164              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_22         0x00102168              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_23         0x0010216C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_24         0x00102170              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_25         0x00102174              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_26         0x00102178              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_27         0x0010217C              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_28         0x00102180              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_29         0x00102184              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_30         0x00102188              /*  */
#define  MMEADC01B_REG_TONE_FIR_COEFF_31         0x0010218C              /*  */

/*  BAR 4: CAL Tone >   */
#define  MMEADC01B_REG_TONE_TX_CTRL_L            0x001021A0              /*  */
#define  MMEADC01B_REG_TONE_TX_CTRL_H            0x001021A4              /*  */
#define  MMEADC01B_REG_TONE_CH_SEL_L             0x001021A8              /*  */
#define  MMEADC01B_REG_TONE_CH_SEL_H             0x001021AC              /*  */
#define  MMEADC01B_REG_TONE_TRANS_TIME           0x001021B0              /*  */

/*
 * 31 30          16 15 12 11       0
 * +-+--------------+-----+----------+
 * |W|    (_Reserved_)    | nxt addr |
 * +-+--------------+-----+----------+
 *
 *   bit 31   : wrapped            ... 0:no wrapped, 1:wrapped
 *   bit 30-12: (_Reserved_)
 *   bit 11-0 : next address       ... next address to be stored
 */
#define  MMEADC01B_REG_TONE_ADDR_1               0x001021B8              /*  */
#define  MMEADC01B_REG_TONE_ADDR_2               0x001021BC              /*  */
#define  MMEADC01B_REG_TONE_ADDR_3               0x001021C0              /*  */
#define  MMEADC01B_REG_TONE_ADDR_4               0x001021C4              /*  */
#define  MMEADC01B_REG_TONE_ADDR_5               0x001021C8              /*  */
#define  MMEADC01B_REG_TONE_ADDR_6               0x001021CC              /*  */
#define  MMEADC01B_REG_TONE_ADDR_7               0x001021D0              /*  */
#define  MMEADC01B_REG_TONE_ADDR_8               0x001021D4              /*  */
#define  MMEADC01B_REG_TONE_ADDR_9               0x001021D8              /*  */
#define  MMEADC01B_REG_TONE_ADDR_10              0x001021DC              /*  */

#define  MMEADC01B_REG_TONE_ADDR(ch)    (MMEADC01B_REG_TONE_ADDR_1 + ((ch) * 4))

#define  MMEADC01B_REG_TONE_CURR_CH_L            0x001021E0              /*  */
#define  MMEADC01B_REG_TONE_CURR_CH_H            0x001021E4              /*  */

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
#define  MMEADC01B_REG_SP_BPM1_MASK1             0x00180000              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK2             0x00180200              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK3             0x00180400              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK4             0x00180600              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK5             0x00180800              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK6             0x00180A00              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK7             0x00180C00              /*  */
#define  MMEADC01B_REG_SP_BPM1_MASK8             0x00180E00              /*  */

#define  MMEADC01B_REG_SP_BPM2_MASK1             0x00181000              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK2             0x00181200              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK3             0x00181400              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK4             0x00181600              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK5             0x00181800              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK6             0x00181A00              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK7             0x00181C00              /*  */
#define  MMEADC01B_REG_SP_BPM2_MASK8             0x00181E00              /*  */

/*  BAR 4: SP   > coefficients of polynominal  */
#define  MMEADC01B_REG_BPM1_POLY_4NODE_A00       0x001A0000              /*  */
#define  MMEADC01B_REG_BPM1_POLY_4NODE_B00       0x001A0100              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_1_A00     0x001A0200              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_1_B00     0x001A0300              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_2_A00     0x001A0400              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_2_B00     0x001A0500              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_3_A00     0x001A0600              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_3_B00     0x001A0700              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_4_A00     0x001A0800              /*  */
#define  MMEADC01B_REG_BPM1_POLY_3NODE_4_B00     0x001A0900              /*  */

#define  MMEADC01B_REG_BPM2_POLY_4NODE_A00       0x001A0A00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_4NODE_B00       0x001A0B00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_1_A00     0x001A0C00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_1_B00     0x001A0D00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_2_A00     0x001A0E00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_2_B00     0x001A0F00              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_3_A00     0x001A1000              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_3_B00     0x001A1100              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_4_A00     0x001A1200              /*  */
#define  MMEADC01B_REG_BPM2_POLY_3NODE_4_B00     0x001A1300              /*  */

#define            OFS_SP_POLY_00                      0x00              /*  */
#define            OFS_SP_POLY_01                      0x04              /*  */
#define            OFS_SP_POLY_02                      0x08              /*  */
#define            OFS_SP_POLY_03                      0x0C              /*  */
#define            OFS_SP_POLY_04                      0x10              /*  */
#define            OFS_SP_POLY_05                      0x14              /*  */
#define            OFS_SP_POLY_06                      0x18              /*  */
#define            OFS_SP_POLY_07                      0x1C              /*  */
#define            OFS_SP_POLY_10                      0x20              /*  */
#define            OFS_SP_POLY_11                      0x24              /*  */
#define            OFS_SP_POLY_12                      0x28              /*  */
#define            OFS_SP_POLY_13                      0x2C              /*  */
#define            OFS_SP_POLY_14                      0x30              /*  */
#define            OFS_SP_POLY_15                      0x34              /*  */
#define            OFS_SP_POLY_16                      0x38              /*  */
#define            OFS_SP_POLY_20                      0x40              /*  */
#define            OFS_SP_POLY_21                      0x44              /*  */
#define            OFS_SP_POLY_22                      0x48              /*  */
#define            OFS_SP_POLY_23                      0x4C              /*  */
#define            OFS_SP_POLY_24                      0x50              /*  */
#define            OFS_SP_POLY_25                      0x54              /*  */
#define            OFS_SP_POLY_30                      0x60              /*  */
#define            OFS_SP_POLY_31                      0x64              /*  */
#define            OFS_SP_POLY_32                      0x68              /*  */
#define            OFS_SP_POLY_33                      0x6C              /*  */
#define            OFS_SP_POLY_34                      0x70              /*  */
#define            OFS_SP_POLY_40                      0x80              /*  */
#define            OFS_SP_POLY_41                      0x84              /*  */
#define            OFS_SP_POLY_42                      0x88              /*  */
#define            OFS_SP_POLY_43                      0x8C              /*  */
#define            OFS_SP_POLY_50                      0xA0              /*  */
#define            OFS_SP_POLY_51                      0xA4              /*  */
#define            OFS_SP_POLY_52                      0xA8              /*  */
#define            OFS_SP_POLY_60                      0xC0              /*  */
#define            OFS_SP_POLY_61                      0xC4              /*  */
#define            OFS_SP_POLY_70                      0xE0              /*  */

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
#define  MMEADC01B_REG_TONE_1                    0x001C0000              /*  */
#define  MMEADC01B_REG_TONE_2                    0x001C2000              /*  */
#define  MMEADC01B_REG_TONE_3                    0x001C4000              /*  */
#define  MMEADC01B_REG_TONE_4                    0x001C6000              /*  */
#define  MMEADC01B_REG_TONE_5                    0x001C8000              /*  */
#define  MMEADC01B_REG_TONE_6                    0x001CA000              /*  */
#define  MMEADC01B_REG_TONE_7                    0x001CC000              /*  */
#define  MMEADC01B_REG_TONE_8                    0x001CE000              /*  */
#define  MMEADC01B_REG_TONE_9                    0x001D0000              /*  */
#define  MMEADC01B_REG_TONE_10                   0x001D2000              /*  */

#define  N_MMEADC01B_CAL_POINTS                         256

#define  N_MMEADC01B_CAL_TONES                            4

#define            OFS_TONE1_I                         0x00              /*  */
#define            OFS_TONE1_Q                         0x04              /*  */
#define            OFS_TONE2_I                         0x08              /*  */
#define            OFS_TONE2_Q                         0x0C              /*  */
#define            OFS_TONE3_I                         0x10              /*  */
#define            OFS_TONE3_Q                         0x14              /*  */
#define            OFS_TONE4_I                         0x18              /*  */
#define            OFS_TONE4_Q                         0x1C              /*  */

#define  MMEADC01B_REG_SRAM_TONE(ch)    (MMEADC01B_REG_TONE_1 + (LEN_TONE_DAT  * (ch)))

/*  BAR 4: SP  > waveform */
#define  MMEADC01B_REG_SP_1                      0x001E0000              /*  */
#define  MMEADC01B_REG_SP_2                      0x001E4000              /*  */
#define  MMEADC01B_REG_SP_3                      0x001E8000              /*  */
#define  MMEADC01B_REG_SP_4                      0x001EC000              /*  */
#define  MMEADC01B_REG_SP_7                      0x001F0000              /*  */
#define  MMEADC01B_REG_SP_8                      0x001F4000              /*  */
#define  MMEADC01B_REG_SP_9                      0x001F8000              /*  */
#define  MMEADC01B_REG_SP_10                     0x001FC000              /*  */

#define  MMEADC01B_REG_SRAM_SP(ch_msk)    (MMEADC01B_REG_SP_1 + (LEN_SP_DAT  * (ch_msk)))

#endif  /* MMEADC01B_REGS_H */
