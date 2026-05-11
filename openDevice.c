#include"header.h"
#include"declare.h"

int openDevice(struct inode *inodep, struct file *filep)
{
        Dev *ldev;
#ifdef DEBUG
        printk(KERN_INFO "%s: Begin.\n", __func__);
#endif

	ldev = container_of(inodep->i_cdev, Dev, c_dev);
        if(!ldev)
        {
                printk(KERN_ERR "%s: ERROR: container_of() Failure.\n", __func__);
                return -1;
        }

	filep->private_data= ldev;

	if( (filep->f_flags & O_ACCMODE) == O_WRONLY)
	{
		if( trimDevice(ldev) == -1)
		{
			printk(KERN_ERR "%s : ERROR: trimDevice() Failure\n");
			return -1;
		}
	}

#ifdef DEBUG
        printk(KERN_INFO "%s: Device Opened using container_of().\n", __func__);
#endif


#ifdef DEBUG
        printk(KERN_INFO "%s: End.\n", __func__);
#endif
        return 0;
}
