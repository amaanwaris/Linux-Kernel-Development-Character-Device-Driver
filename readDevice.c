#include"header.h"
#include"declare.h"

ssize_t readDevice (struct file * filep, char __user * buff, size_t count , loff_t * f_pos)
{
#ifdef DEBUG
		printk(KERN_INFO "%s Begin !!\n",__func__);
#endif

#ifdef DEBUG
		printk(KERN_INFO "%s End !!\n",__func__);
#endif

	return 0;
}
