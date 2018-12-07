/*! \file mmeadc01b_defs.h
\brief Definition for MMEADC01B object IDs, property IDs and IOCTL codes,
       shared between the Child Driver and the DevAPI layers of the
       device driver stack.\n
       Notice that this file defines IDs for each object instance
       (not type). See object type definitions in EmStdIdTypeDefs.h.
*/

//
// (History)
//    Jan-11-2017      A.Gimenez/Riken          created.


#ifndef __MMEADC01B_DEFS_H__
#define __MMEADC01B_DEFS_H__

#include <linux/ioctl.h>      // needed for the _IOW definitions
#include <pciedev_io.h>       // universal driver definitions

#include "./mmeadc01b_regs.h"   /* FPGA register map */

#define  N_DMA_BUF         N_MMEADC01B_CH /* share one chunk of DMA xfer buf with all CHs. */

/**
 * @struct mmeadc01b_dinfo_t
 * @struct DMA xfer buffer info.
 */
typedef struct {
    int         id_dev;               /* PCIe device driver ID                */
    int         nch;                  /* # of DMA channels                    */
    int         ndbuf;                /* # of DMA Xfer buffers per PCIe card  */
    uint64_t    dbuf_phys[N_DMA_BUF]; /* physical address for DMA Xfer buffer */
    uint32_t    len_dbuf;             /*          length  for DMA Xfer buffer */
} mmeadc01b_dinfo_t;

/**
 * @struct mmeadc01b_req_dma_t
 * @brief  
 */
typedef struct {
    uint32_t    req_acq;              /* DMA xfer request                           */
    int         idx_ring;             /* where data stored to be xfered in the Ring */
} mmeadc01b_req_dma_t;

/*
 * DMA xfer data request
 *  5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 * +-+-+-+-+-+-+-+-+------+-+-+-+-+
 * |      B|      B|      |C|   |W|
 * |      P|      P|   R  |A| R |a|
 * |      M|      M|   S  |L| S |v|
 * |      2|      1|   V  | | V |e|
 * +-+-+-+-+-+-+-+-+   D  |T| D |f|
 * |S|S|F|T|S|S|F|T|      |o|   |o|
 * |P|A|A|b|P|A|A|b|      |n|   |r|
 * | | | |T| | | |T|      |e|   |m|
 * +-+-+-+-+-+-+-+-+------+-+-+-+-+
 */
#define  MMEADC01B_REQ_BPM2            BIT12 /* DMA xfer completion: BPM  2                */
#define  MMEADC01B_REQ_BPM1             BIT8 /* DMA xfer completion: BPM 1                 */
#define  MMEADC01B_REQ_TONE             BIT3 /* DMA xfer completion: CAL Tone              */
#define  MMEADC01B_REQ_WFM              BIT0 /* DMA xfer completion: Wabeforms (AD,I/Q,SP) */

#define  MMEADC01B_RING_NO_DATA           -1 /* no data available in the Ring */

/*
 * DMA xfer completion
 *  5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 * +-+-+-+-+-+-+-+-+------+-+-+-+-+
 * |      B|      B|      |C|S|I|A|
 * |      P|      P|   R  |A|P|/|D|
 * |      M|      M|   S  |L| |Q| |
 * |      2|      1|   V  | | | | |
 * +-+-+-+-+-+-+-+-+   D  |T| | | |
 * |S|S|F|T|S|S|F|T|      |o| | | |
 * |P|A|A|b|P|A|A|b|      |n| | | |
 * | | | |T| | | |T|      |e| | | |
 * +-+-+-+-+-+-+-+-+------+-+-+-+-+
 */
#define  MMEADC01B_CMPLT_BPM2_SP_PROC  BIT15 /* DMA xfer completion: BPM  2 SP  Process */
#define  MMEADC01B_CMPLT_BPM2_COD_SA   BIT14 /* DMA xfer completion: BPM  2 COD SA      */
#define  MMEADC01B_CMPLT_BPM2_COD_FA   BIT13 /* DMA xfer completion: BPM  2 COD FA      */
#define  MMEADC01B_CMPLT_BPM2_COD_TBT  BIT12 /* DMA xfer completion: BPM  2 COD TBT     */
#define  MMEADC01B_CMPLT_BPM1_SP_PROC  BIT11 /* DMA xfer completion: BPM 1  SP  Process */
#define  MMEADC01B_CMPLT_BPM1_COD_SA   BIT10 /* DMA xfer completion: BPM 1  COD SA      */
#define  MMEADC01B_CMPLT_BPM1_COD_FA    BIT9 /* DMA xfer completion: BPM 1  COD FA      */
#define  MMEADC01B_CMPLT_BPM1_COD_TBT   BIT8 /* DMA xfer completion: BPM 1  COD TBT     */
#define  MMEADC01B_CMPLT_TONE           BIT3 /* DMA xfer completion: CAL Tone           */
#define  MMEADC01B_CMPLT_SP             BIT2 /* DMA xfer completion: SP                 */
#define  MMEADC01B_CMPLT_IO             BIT1 /* DMA xfer completion: IO                 */
#define  MMEADC01B_CMPLT_AD             BIT0 /* DMA xfer completion: AD                 */

/**
 * @struct mmeadc01b_xfer_meta_t
 * @brief  DMA xfer data META info
 */
typedef struct {
    int        wrapped;            /* ring buffer is wrap around or not ?     */
    int        npt;                /* # of points of ACQed data               */
} mmeadc01b_xfer_meta_t;

#define  MMEADC01B_META_ID_ADC            0 /* META ID for ADC               */
#define  MMEADC01B_META_ID_IQ             1 /* META ID for I/Q               */
#define  MMEADC01B_META_ID_TONE           2 /* META ID for CAL Tone          */
#define  MMEADC01B_META_ID_SP             3 /* META ID for SP                */
#define  MMEADC01B_META_ID_BPM_COD_TBT    4 /* META ID for BPM > COD TbT     */
#define  MMEADC01B_META_ID_BPM_COD_FA     5 /* META ID for BPM > COD FA      */
#define  MMEADC01B_META_ID_BPM_COD_SA     6 /* META ID for BPM > COD SA      */
#define  MMEADC01B_META_ID_BPM_SP_PROC    7 /* META ID for BPM > SP_ Process */
#define  N_MMEADC01B_META_IDS             8 /* # of META IDs                 */

/**
 * @struct mmeadc01b_reg_rw
 * @brief  data structure to access PCI regsters (MMEADC01B_REG_READ|_WRITE)
 */
typedef struct {
    int         id_bar;         /* PCI BAR[0-5]             */
    uint32_t    ofs;            /* offset address to be R/W */
    uint32_t   *buf;            /* R/W  data                */
    int         num;            /* # of regs to be R/W      */
} mmeadc01b_reg_rw_t;

/**
 * @struct mmeadc01b_dev_rw
 * @brief  data structure to access PCI regsters (MMEADC01B_REG_READ|_WRITE)
 */
typedef struct {
    int         id_dev;         /* device ID                */
    uint32_t    addr;           /* register addr to be R/W  */
    uint32_t   *buf;            /* R/W  data                */
    int         num;            /* # of regs to be R/W      */
} mmeadc01b_dev_rw_t;

/**
 * @struct i2c_fmt_t
 * @brief  data format to read/write from/to slave device.
 */
typedef struct {
    int         slv;            /* Slave address to communicate with     */
    int         rw;             /* direction           (I2C_READ|_WRITE) */
    uint8_t    *wbuf;           /* buffer to be written                  */
    int         wlen;           /* data length to be written (unit: [B]) */
    int         repeated;       /* repeated START or not    (TRUE|FALSE) */
    uint8_t    *rbuf;           /* buffer to be read                     */
    int         rlen;           /* data length to be read    (unit: [B]) */
} i2c_fmt_t;

/* I2C data direction */
#define  I2C_WRITE           0  /* data direction: data from master to slave  */
#define  I2C_READ            1  /* data direction: data from slave  to master */

/**
 * @struct mmeadc01b_bpm_cod_tbt_t
 * @brief  BPM > COD TbT steram data structure.
 */
typedef struct {
    uint32_t   bp_4p_x;         /* BP  quad-pole X       */
    uint32_t   bp_4p_y;         /* BP  quad-pole  Y      */
    uint32_t   bpm_amp_v1;      /* BPM ammplitude V1     */
    uint32_t   bpm_amp_v2;      /* BPM ammplitude  V2    */
    uint32_t   bpm_amp_v3;      /* BPM ammplitude   V3   */
    uint32_t   bpm_amp_v4;      /* BPM ammplitude    V4  */
    uint32_t   vecsum_i;        /* Vector sum for   I    */
    uint32_t   vecsum_q;        /* Vector sum for    Q   */
    uint32_t   ref_i;           /* reference signal I    */
    uint32_t   req_q;           /* reference signal  Q   */
    uint32_t   rsvd[ 6];        /* (_Reserved_)          */
} mmeadc01b_bpm_cod_tbt_t;

/**
 * @struct mmeadc01b_bpm_cod_fa_t
 * @brief  BPM > COD FA  steram data structure.
 */
typedef struct {
    uint32_t   bp_4p_x;         /* BP  quad-pole X       */
    uint32_t   bp_4p_y;         /* BP  quad-pole  Y      */
    uint32_t   bpm_amp_v1;      /* BPM ammplitude V1     */
    uint32_t   bpm_amp_v2;      /* BPM ammplitude  V2    */
    uint32_t   bpm_amp_v3;      /* BPM ammplitude   V3   */
    uint32_t   bpm_amp_v4;      /* BPM ammplitude    V4  */
    uint32_t   vecsum_i;        /* Vector sum for   I    */
    uint32_t   vecsum_q;        /* Vector sum for    Q   */
    uint32_t   ref_i;           /* reference signal I    */
    uint32_t   req_q;           /* reference signal  Q   */
    uint32_t   bp_3p_x;         /* BP   tri-pole X       */
    uint32_t   bp_3p_y;         /* BP   tri-pole  Y      */
    uint32_t   rsvd[ 4];        /* (_Reserved_)          */
} mmeadc01b_bpm_cod_fa_t;

/**
 * @struct mmeadc01b_bpm_cod_sa_t
 * @brief  BPM > COD SA  steram data structure.
 */
typedef struct {
    uint32_t   bp_4p_x;         /* BP  quad-pole X       */
    uint32_t   bp_4p_y;         /* BP  quad-pole  Y      */
    uint32_t   bpm_amp_v1;      /* BPM ammplitude V1     */
    uint32_t   bpm_amp_v2;      /* BPM ammplitude  V2    */
    uint32_t   bpm_amp_v3;      /* BPM ammplitude   V3   */
    uint32_t   bpm_amp_v4;      /* BPM ammplitude    V4  */
    uint32_t   vecsum_i;        /* Vector sum for   I    */
    uint32_t   vecsum_q;        /* Vector sum for    Q   */
    uint32_t   ref_i;           /* reference signal I    */
    uint32_t   req_q;           /* reference signal  Q   */
    uint32_t   bp_3p_x1;        /* BP   tri-pole X  1    */
    uint32_t   bp_3p_y1;        /* BP   tri-pole  Y 1    */
    uint32_t   bp_3p_x2;        /* BP   tri-pole X   2   */
    uint32_t   bp_3p_y2;        /* BP   tri-pole  Y  2   */
    uint32_t   bp_3p_x3;        /* BP   tri-pole X    3  */
    uint32_t   bp_3p_y3;        /* BP   tri-pole  Y   3  */
    uint32_t   bp_3p_x4;        /* BP   tri-pole X     4 */
    uint32_t   bp_3p_y4;        /* BP   tri-pole  Y    4 */
    uint32_t   rsvd[ 4];        /* (_Reserved_)          */
} mmeadc01b_bpm_cod_sa_t;

/**
 * @struct mmeadc01b_bpm_sp_proc_msk_t
 * @brief  BPM > SP Process     data structre.
 */
typedef struct {
    uint32_t   bp_4p_x;         /* BP  quad-pole X       */
    uint32_t   bp_4p_y;         /* BP  quad-pole  Y      */
    uint32_t   bpm_amp_v1;      /* BPM ammplitude V1     */
    uint32_t   bpm_amp_v2;      /* BPM ammplitude  V2    */
    uint32_t   bpm_amp_v3;      /* BPM ammplitude   V3   */
    uint32_t   bpm_amp_v4;      /* BPM ammplitude    V4  */
    uint32_t   vecsum_i;        /* Vector sum for   I    */
    uint32_t   vecsum_q;        /* Vector sum for    Q   */
} mmeadc01b_bpm_sp_proc_msk_t;
#define  N_MMEADC01B_SP_MASK         8 /* mask 1 to 8    */

typedef struct {
    mmeadc01b_bpm_sp_proc_msk_t  msk[N_MMEADC01B_SP_MASK];
} mmeadc01b_bpm_sp_proc_t;


// -------------------------------------------------------------------------------
// IOCTL codes /  interface defs
// -------------------------------------------------------------------------------
#define  MMEADC01B_IOC                          BD_IOC_CODE

#define  MMEADC01B_PHYSICAL_SLOT          _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   1), int)
#define  MMEADC01B_REG_READ               _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   2), int)
#define  MMEADC01B_REG_WRITE              _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   3), int)
#define  MMEADC01B_ADC_READ               _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   4), int)
#define  MMEADC01B_ADC_WRITE              _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   5), int)
#define  MMEADC01B_DAC_READ               _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   6), int)
#define  MMEADC01B_DAC_WRITE              _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   7), int)
#define  MMEADC01B_LMK_WRITE              _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   8), int)
#define  MMEADC01B_USER_I2C_READ          _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +   9), int)
#define  MMEADC01B_USER_I2C_WRITE         _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  10), int)
#define  MMEADC01B_SET_PID                _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  11), int)
#define  MMEADC01B_CLR_PID                _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  12), int)
#define  MMEADC01B_PREP_DMA_BUF           _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  13), int)
#define  MMEADC01B_REUSE_DMA_BUF          _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  14), int)
#define  MMEADC01B_CLEAN_DMA_BUF          _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  15), int)
#define  MMEADC01B_SET_CLK_SRC            _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  16), int)
#define  MMEADC01B_GET_CLK_SRC            _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  17), int)
#define  MMEADC01B_GET_META               _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  18), int)
#define  MMEADC01B_START_DMA_XFER         _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  19), int)

#define  MMEADC01B_TEST_DMA               _IOWR(MMEADC01B_IOC, (BD_USER_IOCTL_MINNR +  99), int)

#endif  // __MMEADC01B_DEFS_H__
