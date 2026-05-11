#include"header.h"
//#include"fileop.h"
#include"declare.h"
#include"fileop.h"
int majorNo,minorNo,nod;
int devsize,datasize,regsize,nofregs;
dev_t dvid,devno;
Dev *dev;


module_param(nod, int, S_IRUGO);
module_param(devsize, int, S_IRUGO);
module_param(datasize, int, S_IRUGO);
module_param(regsize, int, S_IRUGO);
module_param(nofregs, int, S_IRUGO);

static int __init initFunc(void)
{
#ifdef DEBUG
		printk(KERN_INFO "%s Begin !!\n",__func__);
		printk(KERN_INFO "%s NOD:%d!!\n",__func__,nod);
		printk(KERN_INFO "%s devsize:%d!!\n",__func__,devsize);
		printk(KERN_INFO "%s datasize:%d!!\n",__func__,datasize);
		printk(KERN_INFO "%s regsize:%d!!\n",__func__,regsize);
		printk(KERN_INFO "%s nofregs:%d!!\n",__func__,nofregs);
#endif
	int ret;
	majorNo=MAJORNO;
	minorNo=MINORNO;
//	nod=NOD;
//	devsize=DEVSIZE;
//	datasize=DATASIZE;
//	regsize=REGSIZE;
//	nofregs=NOFREGS;
	ret=alloc_chrdev_region(&dvid,minorNo,nod,CDDNAME);	
	if(ret == -1)
	{
		printk(KERN_ERR "%s: ERROR: register_chrdev() Failure.\n",__func__);
		goto OUT;
	}
#ifdef DEBUG
	majorNo=MAJOR(dvid);
	minorNo=MINOR(dvid);
	printk(KERN_INFO "%s:MajorNo:%d ; MinorNo:%d\n",__func__,majorNo,minorNo);
	dev=kmalloc(sizeof(Dev)*nod,GFP_KERNEL);
	if(!dev)
	{
		printk(KERN_ERR "%s ERROR kmalloc Failure\n",__func__);
		goto OUT;
	}
	int i;
	for (i=0; i<nod; i++)
	{
		cdev_init(&dev[i].c_dev,&fops);
		dev[i].c_dev.ops=&fops;
		dev[i].devsize=devsize;
		dev[i].datasize=datasize;
		dev[i].regsize=regsize;
		dev[i].nofregs=nofregs;
		devno=MKDEV(majorNo,i);
		ret=cdev_add(&dev[i].c_dev,devno,1);
		if(ret<0)
		{
			printk(KERN_ERR "%s cdev_add Failed\n",__func__);
			kfree(dev);
			goto OUT;
		}
	}	
#endif
	return 0;

#ifdef DEBUG
		printk(KERN_INFO "%s END.\n",__func__);
#endif	

OUT:
#ifdef DEBUG
		printk(KERN_ERR "%s ERROR !!\n",__func__);
#endif
		return -1;

}

module_init(initFunc);
