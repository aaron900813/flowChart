#ifndef _CPCI5125DRIVERLNX_H_
#define _CPCI5125DRIVERLNX_H_

#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>

#define DDEBUG
#ifdef  DDEBUG
#define LOG(string...) printk(KERN_ALERT string)
#else
#define LOG(string...)
#endif

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

typedef unsigned int		u_int32;
typedef int					int32;
typedef unsigned short		u_int16;
typedef short				int16;
typedef unsigned char		u_int8;
typedef	char				int8;
typedef unsigned long long	u_int64;
typedef signed long long	int64;

#define DRIVER_NAME  	"cPCI5125"

#define PLX_VENDOR_ID 	0x6432
#define PLX_DEVICE_ID 	0x5125

#define IO_TYPE_MEMORY          0
#define IO_TYPE_PORT            1

#define ReadBAR2 0xc
#define WRITEBAR2 0xd

typedef struct _pci_device_location
{
	u_int32					bus;
	u_int16					function;
	u_int16					device;
} pci_device_location, * ppci_device_location;

typedef struct _bar_descriptor
{
	u_int8*				vir_address;
	unsigned long       phy_address;
	unsigned long		size;
	u_int8				flag;
}bar_descriptor, *pbar_descriptor;

typedef struct _io_memory
{
	bar_descriptor bar[6];
}io_memory, *pio_memory;

typedef struct _dma_buffer_item
{
	void*		        vir_address;
	unsigned long		length;
	unsigned long		phy_address;
	unsigned long		bus_address;
}dma_buffer_item, *ptr_buffer_item;

typedef struct ioctl_data
{
    unsigned int data;
    unsigned int offset;
} TY_IOCTL_DATA;

struct pci_device
{
    struct pci_device*   next;
    struct cdev          cdev;
    struct pci_dev*      pci_dev;
    io_memory            memory;
    u_int32              minor;
    pci_device_location  location;
    int32                irq;
    u_int32				 write_offset;
    u_int32				 read_offset ;
    u_int32              intcount;
};
#endif /* _DATATYPES_H_ */
