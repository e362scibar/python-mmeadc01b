#ifndef _PCIEDEV_IO_H
#define _PCIEDEV_IO_H

#include <linux/types.h>
#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */

#ifndef NUMBER_OF_BARS
#define NUMBER_OF_BARS 6
#endif

// maximum number of simultaneously-allocated DMA buffers
#define MAX_DMA_BUF 20

#define UPCIEDEV_SWAPL(x) ((((x) >> 24) & 0x000000FF) | (((x) >> 8) & 0x0000FF00) | (((x) << 8) & 0x00FF0000) | (((x) << 24) & 0xFF000000))
#define UPCIEDEV_SWAPS(x) ((((x) >> 8) & 0x00FF) | (((x) << 8) & 0xFF00))
#define UPCIEDEV_SWAP_TOT(size,x) ((size)==1) ? (x) : (((size)==2) ? UPCIEDEV_SWAPS((x)) : UPCIEDEV_SWAPL((x)))

#define     PRW_REG_SIZE_MASK   (int64_t)0xf000000000000000
#define     PRW_BAR_MASK        (int64_t)0x0f00000000000000
#define     PRW_OFFSET_MASK     (int64_t)0x00ffffffffffffff
#define     PRW_REG_SIZE_SHIFT  60
#define     PRW_BAR_SHIFT       56

// Register size
#define RW_D8                0x0
#define RW_D08              RW_D8
#define RW_D16              0x1
#define RW_D32              0x2
#define RW_DMA             0x3
#define RW_INFO            0x4
#define MTCA_MAX_RW 3

// DMA size
#define DMA_DATA_OFFSET            6 
#define DMA_DATA_OFFSET_BYTE  24
#define PCIEDEV_DMA_SYZE           4096
#define PCIEDEV_DMA_MIN_SYZE   128

#define IOCTRL_R      0x00
#define IOCTRL_W     0x01
#define IOCTRL_ALL  0x02

#define BAR0 0
#define BAR1 1
#define BAR2 2
#define BAR3 3
#define BAR4 4
#define BAR5 5

// All possible device access types
#define MTCA_SIMPLE_READ                 0
#define MTCA_LOCKED_READ                 1
#define MT_READ_TO_EXTRA_BUFFER 2
#define MTCA_SIMPLE_WRITE                5
#define MTCA_SET_BITS                    6
#define MTCA_SWAP_BITS          7

#define __GetRegisterSizeInBytes__(_a_value_)   (1<<(_a_value_))
#define CORRECT_REGISTER_SIZE(_a_rw_mode_,_a_default_rw_mode_) \
{ \
    if((_a_rw_mode_)<0 || (_a_rw_mode_)>= MTCA_MAX_RW){(_a_rw_mode_)=(_a_default_rw_mode_);}\
}

typedef uintptr_t pointer_type;

/*
 * GetRegisterSizeInBytes:  gets register size from RW mode
 *                          safe to call from interrupt contex
 *
 * Parameters:
 *   a_unMode:        register access mode (read or write and register len (8,16 or 32 bit))
 *
 * Return (int):
 *   WRONG_MODE:      error (not correct mode provided)
 *   other:           register length in Bytes
 */
static inline int   GetRegisterSizeInBytes(int16_t a_unMode, int16_t a_default_rw_mode)
{
    CORRECT_REGISTER_SIZE(a_unMode, a_default_rw_mode);
    return __GetRegisterSizeInBytes__(a_unMode);
}




/* generic register access */
struct device_rw  {
    uint32_t            offset_rw; /* offset in address                       */
    uint32_t            data_rw;   /* data to set or returned read data       */
    union
    {
        uint32_t            mode_rw;    /* mode of rw (RW_D8, RW_D16, RW_D32)      */
        uint32_t            register_size; /* (RW_D8, RW_D16, RW_D32)      */
    };
    uint32_t            barx_rw;   /* BARx (0, 1, 2, 3, 4, 5)                 */
    union
    {
        struct
        {
            uint32_t        size_rw;    // !!! transfer size should not be providefd by this field.
                                // This field is there for backward compatibility.
                                //
                                // Transfer size should be provided with read/write 3-rd
                                // argument (count)
                                // read(int fd, void *buf, size_t count);
                                // ssize_t write(int fd, const void *buf, size_t count);
            uint32_t        rsrvd_rw;
        };
        pointer_type        dataPtr;    // In the case of more than one register access
        // this fields shows pointer to user data
    };            
};
typedef struct device_rw device_rw;




/* object/property-based information access.
   This structure ties information access from DevAPI objects (and their properties)
   into registers defined by the driver */
typedef enum _TransferDirection
{
    EmPropertySet = 0,
    EmPropertyGet = 1,
    EmPropertyReset = 2,
	// other non-standard operations specified between [EmPropertyCustomOpMin/Max]
    EmPropertyCustomOpMin = 128, 
    EmPropertyCustomOpMax = 191 
} TransferDirection;

typedef struct _EmChildDriverDataTransfer
{
    TransferDirection direction;
    uint32_t objId;
    uint32_t propertyId;
    uint32_t data[2]; // default: 8 bytes for transfer
} EmChildDriverDataTransfer;


// address of element just after the array, used for custom data
static inline void *EmGetTransferUserData( EmChildDriverDataTransfer *pData )
{
    return (void *)(&(pData->data[ sizeof(pData->data)/sizeof(pData->data[0]) ]));
}



/* generic register access from ioctl system call*/
typedef struct device_ioc_rw 
{
    uint16_t        register_size;  /* (RW_D8, RW_D16, RW_D32)      */
    uint16_t        rw_access_mode; /* mode of rw (MTCA_SIMLE_READ,...)      */
    uint32_t        barx_rw;    /* BARx (0, 1, 2, 3, 4, 5)                 */
    uint32_t        offset_rw;  /* offset in address                       */
    uint32_t        count_rw;   /* number of register to read or write     */
    pointer_type    dataPtr;    // In the case of more than one register access
    pointer_type    maskPtr;    // mask for bitwise write operations
}device_ioc_rw;


/* generic vector register access from ioctl system call*/
typedef struct device_vector_rw
{
    uint64_t        number_of_rw;       /* Number of read or write operations to perform     */
    pointer_type    device_ioc_rw_ptr;  // User space pointer to read or write data    
                                // In kernel space this field should be casted to (device_ioc_rw* __user)
}device_vector_rw;

struct device_ioctrl_data  {
        uint32_t    offset;
        uint32_t    data;
        uint32_t    cmd;
        uint32_t    reserved;
};
typedef struct device_ioctrl_data device_ioctrl_data;

struct device_ioctrl_dma  {
        uint32_t    dma_offset;
        uint32_t    dma_size;
        uint32_t    dma_cmd;          // value to DMA Control register
        uint32_t    dma_pattern;     // DMA BAR num
        uint32_t    dma_reserved1; // DMA Control register offset (31:16) DMA Length register offset (15:0)
        uint32_t    dma_reserved2; // DMA Read/Write Source register offset (31:16) Destination register offset (15:0)
};
typedef struct device_ioctrl_dma device_ioctrl_dma;

struct device_ioctrl_time  {
        struct timeval   start_time;
        struct timeval   stop_time;
};
typedef struct device_ioctrl_time device_ioctrl_time;

struct device_i2c_rw  {
       uint32_t            busNum; /* I2C Bus num*/
       uint32_t            devAddr;   /* I2C device address on the current bus */
       uint32_t            regAddr;   /* I2C register address on the current device */
       uint32_t            size;   /* number of bytes to  read/write*/
       uint32_t            done;  /* read done*/
       uint32_t            timeout;   /* transfer timeout usec */             
       uint32_t            status;  /* status */
       uint32_t            data[256];  /* data */
};
typedef struct device_i2c_rw device_i2c_rw;


// --------- external DMA buffer addresses, for sharing with user-mode
typedef struct _BDDmaMapEntry
{
    uint32_t ref_offset;
    uint32_t sizeInBytes;
} BDDmaMapEntry;

typedef struct _BDDmaMap
{
    int nDMABuffers;
    BDDmaMapEntry entries[MAX_DMA_BUF];
} BDDmaMap;





/* Use 'o' as magic number */

#define BD_IOC_MINNR         1
#define BD_IOC_MAXNR         32

#define BD_USER_IOCTL_MINNR         33
#define BD_USER_IOCTL_MAXNR         255


#define BD_IOC_CODE                 '0'

#define PCIEDEV_PHYSICAL_SLOT       _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  1), int)
#define PCIEDEV_DRIVER_VERSION      _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  2), int)
#define PCIEDEV_FIRMWARE_VERSION    _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  3), int)
#define PCIEDEV_SCRATCH_REG         _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  4), int)
#define PCIEDEV_GET_STATUS          _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  5), int)
#define PCIEDEV_SET_SWAP            _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  6), int)
#define PCIEDEV_SET_BITS            _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  7), struct device_ioc_rw)
#define PCIEDEV_SWAP_BITS           _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  8), struct device_ioc_rw)
#define PCIEDEV_VECTOR_RW           _IOWR(BD_IOC_CODE, (BD_IOC_MINNR +  9), struct device_vector_rw) 

#define PCIEDEV_SINGLE_IOC_ACCESS   _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 10), struct device_ioc_rw)      //?

#define PCIEDEV_UDRIVER_VERSION     _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 11), int)
#define PCIEDEV_GET_SWAP            _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 12), int)

#define PCIEDEV_LOCK_DEVICE         _IO  (BD_IOC_CODE, (BD_IOC_MINNR + 13) )
#define PCIEDEV_UNLOCK_DEVICE       _IO  (BD_IOC_CODE, (BD_IOC_MINNR + 14) )
#define PCIEDEV_LOCKED_READ         _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 15), struct device_ioc_rw) //?

#define PCIEDEV_SET_REGISTER_SIZE   _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 16), int)
#define PCIEDEV_GET_REGISTER_SIZE   _IO  (BD_IOC_CODE, (BD_IOC_MINNR + 17) )


#define BD_IOCTL_GET_DMA_OFFSETS    _IOWR(BD_IOC_CODE, (BD_IOC_MINNR + 18),  BDDmaMap )


#endif
