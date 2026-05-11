#include"header.h"
#include"declare.h"

int releaseDevice(struct inode *inodep, struct file *filep)
{
#ifdef DEBUG
        printk(KERN_INFO "%s: Begin.\n", __func__);
#endif



#ifdef DEBUG
        printk(KERN_INFO "%s: End.\n", __func__);
#endif

 return 0;
}
