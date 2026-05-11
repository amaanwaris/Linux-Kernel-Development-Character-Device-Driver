#include"header.h"
#include"declare.h"

static void __exit cleanupFunc(void)
{
#ifdef DEBUG
		printk(KERN_INFO "%s Begin !!\n",__func__);
#endif
	int i;
	for(i=0;i<nod;i++)
	cdev_del(&dev[i].c_dev);
	kfree(dev);
	unregister_chrdev_region(dvid,nod);
#ifdef DEBUG
		printk(KERN_INFO "%s End !!\n",__func__);
#endif

//	return 0;

}

module_exit(cleanupFunc);
