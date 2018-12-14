/**
 * @file     mmeadc01b_regs.h
 * @brief    MME-ADC01-B FPGA register map (2018-11-14 ver.)
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

#define  LEN_ADC_DAT                          (N_ADC_POINTS * 4)         /* length of ADC sampling data (unit: [B]) */
#define  LEN_DDC_DAT                          (N_DDC_POINTS * 4)         /* length of DDC sampling data (unit: [B]) */
#define  LEN_DAC_DAT                          (N_DAC_POINTS * 4)         /* length of DAC sampling data (unit: [B]) */

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
#define  DDC_CH_IQ_11                                    20 /* 10. MON_CAV_IIR */
#define  DDC_CH_IQ_12                                    21 /* 11. MON_CAV_MV  */
#define  DDC_CH_IQ_13                                    22 /* 12. MON_KLY_IIR */
#define  DDC_CH_IQ_14                                    23 /* 13. MON_KLY_MV  */
#define  DDC_CH_IQ_15                                    24 /* 14. MON_MV      */
#define  DDC_CH_IQ_16                                    25 /* 15. MON_FF_SV   */
#define  N_MMEADC01B_CH                                  26 /* total # of channels on MME-ADC01-B */

#define  N_ADC_CH                                        10 /* ADC: 5 devices x 2 ch      */
#define  N_DDC_CH                                        16 /* DDC: ADC 10ch + 6 extra ch */

/*  - INT source channels     */
/*
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-----------+---+-------+-------+-----------+---+---------------+
 *   |           | DDC extra |                   |                   |
 *   |_Reserved_ |  ch 15-11 | DDC ch 10-1/base  | ADC ch 10-1       |
 *   |           |  (I/Q)    |  (I/Q)            |  (RAW)            |
 *   +-----------+-----------+-------------------+-------------------+
 *             bit 31   : DMA
 *             bit 30   : Inter lock
 *             bit 29-26: _(_Reseved_)
 *             bit 25-20: DDC ch 16-11 (I/Q) extra-data (internally generated)
 *             bit 19-10: DDC ch 10-1  (I/Q)  base
 *             bit  9-0 : ADC ch 10-1
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

#define  DAT_CH_ADC                              0x000003FF /* bit  9-0  */
#define  DAT_CH_DDC                              0x03FFFC00 /* bit 25-10 */
#define  DAC_CH_ACQ                (DAT_CH_ADC | DAT_CH_DDC)

/*
 * INT_SRC:
 * INT_CLR:
 * INT_MSK:
 *    3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *   +-+-+-----------+---------------+---------------+-----------+-+-+
 *   |D|I|                                                       |D|A|
 *   |M|L|                      (_Reserved_)                     |D|D|
 *   |A|K|                                                       |C|C|
 *   +-+-+-------------------------------------------------------+-+-+
 *             bit 31   : DMA
 *             bit 30   : Inter lock
 *             bit 29-2 : (_Reserved_)
 *             bit  1   : any DDC ch
 *             bit  0   : any ADC ch
 */
#define  INT_SRC_NONE                                     0 /* no interrupt occured */

#define  INT_SRC_DMA                                  BIT31
#define  INT_SRC_INTL                                 BIT30
#define  INT_SRC_DDC                                   BIT1
#define  INT_SRC_ADC                                   BIT0

#define  INT_SRC_ACQ                           (INT_SRC_ADC | INT_SRC_DDC)
#define  INT_SRC_WFM                           (INT_SRC_ADC | INT_SRC_DDC)                                                          /* waveforms (ADC + I/Q + SP)            */
#define  INT_SRC_MISC                          (INT_SRC_ADC | INT_SRC_DDC)                                                          /* waveforms + CAL Tone + BPM[12] COD SA */

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
#define  MMEADC01B_REG_SHOW_WF_LIMIT             0x0000E088              /* SHOW_WF_LIMIT      */

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

/*  BAR 0: waveform > comparison > trigger select */
#define  MMEADC01B_REG_FORM_SOFTTRIG             0x0000F130              /* FORM_SOFTTRIG      */
#define  MMEADC01B_REG_FORM_EXTTRIG              0x0000F134              /* FORM_EXTTRIG       */
#define  MMEADC01B_REG_FORM_SELFTRIG_EN          0x0000F138              /* FORM_SELFTRIG_EN   */

/*  BAR 0: waveform > comparison > control */
#define  MMEADC01B_REG_FORM_PAT_STEP             0x0000F140              /* FORM_PAT_STEP      */
#define  MMEADC01B_REG_FORM_PAT_DELAY            0x0000F144              /* FORM_PAT_DELAY     */
#define  MMEADC01B_REG_FORM_PAT_REPEAT           0x0000F148              /* FORM_PAT_REPEAT    */
#define  MMEADC01B_REG_FORM_PAT_DEPTH            0x0000F14C              /* FORM_PAT_DEPTH     */

/* ************************************************************: BAR 2 */
#define  LEN_MMEADC01B_BAR_2                       (2 << 20)             /* BAR 2:   2 [MB]    */
/*   BAR 2: SRAM memory map */
#define  MMEADC01B_REG_ADC_1                     0x00000000              /* ADC_0     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_2                     0x00010000              /* ADC_1     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_3                     0x00020000              /* ADC_2     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_4                     0x00030000              /* ADC_3     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_5                     0x00040000              /* ADC_4     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_6                     0x00050000              /* ADC_5     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_7                     0x00060000              /* ADC_6     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_8                     0x00070000              /* ADC_7     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_9                     0x00080000              /* ADC_8     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_ADC_10                    0x00090000              /* ADC_9     [31-16]:fixed 0, [15:0]:ADC    */
#define  MMEADC01B_REG_DAC_2_1                   0x000A0000              /* DAC_1_0   [31-16]:theta  , [15:0]:R      */
#define  MMEADC01B_REG_DDC_IQ_1                  0x000C0000              /* DDC_IQ_0  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_2                  0x000C4000              /* DDC_IQ_1  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_3                  0x000C8000              /* DDC_IQ_2  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_4                  0x000CC000              /* DDC_IQ_3  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_5                  0x000D0000              /* DDC_IQ_4  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_6                  0x000D4000              /* DDC_IQ_5  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_7                  0x000D8000              /* DDC_IQ_6  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_8                  0x000DC000              /* DDC_IQ_7  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_9                  0x000E0000              /* DDC_IQ_4  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_10                 0x000E4000              /* DDC_IQ_5  [31-16]:Q      , [15:0]:I      */
#define  MMEADC01B_REG_DDC_IQ_11                 0x000E8000              /* DDC_IQ_6  [31-16]:theta  , [15:0]:R      */ /* MON_CAV_IIR */
#define  MMEADC01B_REG_DDC_IQ_12                 0x000EC000              /* DDC_IQ_7  [31-16]:theta  , [15:0]:R      */ /* MON_CAV_MV  */
#define  MMEADC01B_REG_DDC_IQ_13                 0x000F0000              /* DDC_IQ_4  [31-16]:theta  , [15:0]:R      */ /* MON_KLY_IIR */
#define  MMEADC01B_REG_DDC_IQ_14                 0x000F4000              /* DDC_IQ_5  [31-16]:theta  , [15:0]:R      */ /* MON_KLY_MV  */
#define  MMEADC01B_REG_DDC_IQ_15                 0x000F8000              /* DDC_IQ_6  [31-16]:Q      , [15:0]:I      */ /* MON_MV      */
#define  MMEADC01B_REG_DDC_IQ_16                 0x000FC000              /* DDC_IQ_7  [31-16]:theta  , [15:0]:R      */ /* MON_FF_SV   */

#define  MMEADC01B_REG_SRAM_ADC(   ch)   (MMEADC01B_REG_ADC_1    + (LEN_ADC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DAC(   ch)   (MMEADC01B_REG_DAC_2_1  + (LEN_DAC_DAT * (ch)))
#define  MMEADC01B_REG_SRAM_DDC_IQ(ch)   (MMEADC01B_REG_DDC_IQ_1 + (LEN_DDC_DAT * (ch)))

/* ************************************************************: BAR 4: added for LLRF */
#define  LEN_MMEADC01B_BAR_4                     (128 << 10)             /* BAR 4: 128 [kB]    */
/*  BAR 4: DDC coefficients */
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
 *   +---+-------------------+-------------------+-------------------+
 *   |(R)|       FORM        |        I/Q        |        ADC        |
 *   +---+-------------------+-------------------+-------------------+
 *             bit 31-30: (_Reserved_)
 *             bit 29-20: Wavefrom Limit      (I/Q ch 10-1)
 *             bit 19-10: ADC                 (ADC ch 10-1)
 *             bit  9-0 : I/Q                 (I/Q ch 10-1)
 */
#define  INTL_SRC_FRONT_AMC                      0xF0000000
#define  INTL_SRC_RTM                            0x0FFF0000
#define  INTL_SRC_P20_17_TX                      0x000000F0
#define  INTL_SRC_P20_17_RX                      0x0000000F

#define  INTL_SRC_ADC                            0x000003FF
#define  INTL_SRC_IQ                             0x000FFC00

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

#define  N_MMEADC01B_REG_FIR_COEFFS                      16
#define  MMEADC01B_REG_FIR_COEFF(id_coeff)      (MMEADC01B_REG_FIR_COEFF_0 + ((id_coeff) * 4))

/*  BAR 4: FIR filter coefficients for feedback of coherent synchrotron oscillation */
#define  MMEADC01B_REG_FSFB_FIR_ON               0x000010A0              /* FSFB_FIR_ON        */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_UPD        0x000010A8              /* FSFB_FIR_COEFF_UPD */

#define  MMEADC01B_REG_FSFB_FIR_COEFF_00         0x000010B0              /* FSFB_FIR_COEFF_00  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_01         0x000010B4              /* FSFB_FIR_COEFF_01  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_02         0x000010B8              /* FSFB_FIR_COEFF_02  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_03         0x000010BC              /* FSFB_FIR_COEFF_03  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_04         0x000010C0              /* FSFB_FIR_COEFF_04  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_05         0x000010C4              /* FSFB_FIR_COEFF_05  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_06         0x000010C8              /* FSFB_FIR_COEFF_06  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_07         0x000010CC              /* FSFB_FIR_COEFF_07  */
#define  MMEADC01B_REG_FSFB_FIR_COEFF_08         0x000010D0              /* FSFB_FIR_COEFF_08  */

#define  N_MMEADC01B_REG_FSFB_FIR_COEFFS                 10
#define  MMEADC01B_REG_FSFB_FIR_COEFF(id_coeff) (MMEADC01B_REG_FSFB_FIR_COEFF_00 + ((id_coeff) * 4))

/*  BAR 4: I/Q IIR filter coefficients */
#define  MMEADC01B_REG_IIR_ON                    0x000010E0              /* IIR_ON             */
#define  MMEADC01B_REG_IIR_COEFF                 0x000010E4              /* IIR_COEFF          */

/*  BAR 4: CIC filter coefficients for feedback of coherent synchrotron oscillation */
#define  MMEADC01B_REG_FSFB_CIC_RATE_UPD         0x000010F0              /* FSFB_CIC_RATE_UPD  */
#define  MMEADC01B_REG_FSFB_CIC_RATE             0x000010F4              /* FSFB_CIC_RATE      */

/*  BAR 4: feedback control */
#define  MMEADC01B_REG_CAV_IIR_COEFF             0x00002000              /* CAV_IIR_COEFF      */
#define  MMEADC01B_REG_CAV_IIR_COEFF_T           0x00002004              /* CAV_IIR_COEFF_T    */
#define  MMEADC01B_REG_KLY_IIR_COEFF             0x00002008              /* KLY_IIR_COEFF      */
#define  MMEADC01B_REG_KLY_IIR_COEFF_T           0x0000200C              /* KLY_IIR_COEFF_T    */
#define  MMEADC01B_REG_CAV_SV                    0x00002010              /* CAV_SV             */
#define  MMEADC01B_REG_KLY_SV                    0x00002014              /* KLY_SV             */
#define  MMEADC01B_REG_KLY_SV_SEL                0x00002018              /* KLY_SV_SEL         */
#define  MMEADC01B_REG_FB_ON                     0x0000201C              /* FB_ON              */
#define  MMEADC01B_REG_KLY_P_GAIN_R              0x00002020              /* KLY_P_GAIN_R       */
#define  MMEADC01B_REG_KLY_P_GAIN_T              0x00002024              /* KLY_P_GAIN_T       */
#define  MMEADC01B_REG_KLY_I_GAIN_R              0x00002028              /* KLY_I_GAIN_R       */
#define  MMEADC01B_REG_KLY_I_GAIN_T              0x0000202C              /* KLY_I_GAIN_T       */
#define  MMEADC01B_REG_CAV_P_GAIN_R              0x00002030              /* CAV_P_GAIN_R       */
#define  MMEADC01B_REG_CAV_P_GAIN_T              0x00002034              /* CAV_P_GAIN_T       */
#define  MMEADC01B_REG_CAV_I_GAIN_R              0x00002038              /* CAV_I_GAIN_R       */
#define  MMEADC01B_REG_CAV_I_GAIN_T              0x0000203C              /* CAV_I_GAIN_T       */
#define  MMEADC01B_REG_FF_SV                     0x00002040              /* FF_SV              */
#define  MMEADC01B_REG_FF_GAIN                   0x00002044              /* FF_GAIN            */
#define  MMEADC01B_REG_FF_NCO_FREQ_START         0x00002048              /* FF_NCO_FREQ_START  */
#define  MMEADC01B_REG_FF_NCO_FREQ_STOP          0x0000204C              /* FF_NCO_FREQ_STOP   */
#define  MMEADC01B_REG_FF_NCO_INC_FREQ           0x00002050              /* FF_NCO_INC_FREQ    */
#define  MMEADC01B_REG_FF_NCO_INC_CYCLE          0x00002054              /* FF_NCO_INC_CYCLE   */
#define  MMEADC01B_REG_FF_NCO_RST_REPEAT         0x00002058              /* FF_NCO_RST_REPEAT  */

#define  MMEADC01B_REG_FSFB_SFP_ADC_SEL          0x00002070              /* FSFB_SFP_ADC_SEL   */
#define  MMEADC01B_REG_FSFB_GAIN                 0x00002074              /* FSFB_GAIN          */
#define  MMEADC01B_REG_FSFB_LIMIT                0x00002078              /* FSFB_LIMIT         */

#define  MMEADC01B_REG_MV_CONST                  0x00002094              /* MV_CONST           */
#define  MMEADC01B_REG_MV_SEL                    0x00002098              /* MV_SEL             */

#define  MMEADC01B_REG_PI_STEP                   0x000020A4              /* PI_STEP            */

/*  BAR 4: real-time monitor */
#define  MMEADC01B_REG_MON_CAV_IIR               0x00002100              /* CAV_IIR            */
#define  MMEADC01B_REG_MON_KLY_IIR               0x00002104              /* KLY_IIR            */
#define  MMEADC01B_REG_MON_KLY_ERR               0x00002108              /* KLY_ERR            */
#define  MMEADC01B_REG_MON_KLY_PI_DIFF           0x0000210C              /* KLY_PI_DIFF        */
#define  MMEADC01B_REG_MON_CAV_ERR               0x00002110              /* CAV_ERR            */
#define  MMEADC01B_REG_MON_CAV_PI_DIFF           0x00002114              /* CAV_PI_DIFF        */
#define  MMEADC01B_REG_MON_CAV_MV                0x00002118              /* CAV_MV             */
#define  MMEADC01B_REG_MON_FF_SV                 0x0000211C              /* FF_SV              */
#define  MMEADC01B_REG_MON_MV_ROT                0x00002120              /* MV_ROT             */
#define  MMEADC01B_REG_MON_MV_RFSW               0x00002124              /* MV_RFSW            */
#define  MMEADC01B_REG_MON_MV_LIMIT              0x00002128              /* MV_LIMIT           */
#define  MMEADC01B_REG_MON_MV                    0x0000212C              /* MV                 */
#define  MMEADC01B_REG_MON_KLY_MV                0x00002130              /* KLY_MV             */

#endif  /* MMEADC01B_REGS_H */
