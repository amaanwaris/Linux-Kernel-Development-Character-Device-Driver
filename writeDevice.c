#include"header.h"
#include"declare.h"

ssize_t writeDevice (struct file * filep, const char __user * ubuff, size_t size , loff_t * f_pos)
{
#ifdef DEBUG
		printk(KERN_INFO "%s Begin !!\n",__func__);
#endif

	Dev * ldev;
	Qset * curr;
	size_t lsize;
	int i;
	int noctw, nocsw;
// 1. Fetch the alredy opened device from struct filep
	ldev = (Dev*)  filep->private_data; 
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: Device not found for writing", __func__);
		goto OUT;
	}

// 2. Setup size - no. of total bytes to write
	if(size < 0)
	{
		printk(KERN_ERR "%s: ERROR: Invalid write attempt", __func__);
		goto OUT;
	}
	if(size == 0)
	{
		printk(KERN_ERR "%s: ERROR: Nothing to write", __func__);
		goto OUT;
	}

	if(size > ldev->devsize)
	{
		printk(KERN_ERR "%s: Data size too Big. Partial write. ", __func__);
		printk(KERN_INFO "%s : INFO : ldev->devsize = %d", __func__, ldev->devsize);
		noctw = lsize = ldev->devsize;
		goto OUT;
	}
	else
	{
		printk(KERN_INFO "%s : INFO : ldev->devsize = %d", __func__, size);
		noctw = lsize = size;
	}


// 3. call createScull() to create appropriate nember of quantums , depending on size of data to write
	if ( (ldev->first = createScull(lsize) ) == 0 )
	{
		printk(KERN_ERR "%s : ERROR: createScull() Failed \n ", __func__);
		goto OUT;
	}

	printk(KERN_INFO "%s : createScull() success\n ", __func__);

// 4. Copy from user
	int ret = 0;
	nocsw = i = 0;
	curr = ldev->first;

	while(lsize > 0)
	{
		if(noctw > ldev->regsize)
		{	
			noctw = ldev->regsize;
		}

		if(curr->data[i])
		{
			ret = copy_from_user( curr->data[i]  , ubuff+nocsw, noctw);
			if(ret > 0)
			{
				printk(KERN_INFO "%s : Partial write \n",__func__);
			}
		}
		else
		{
			printk(KERN_ERR "%s : %d : ERROR : Destination pointer not found for write\n",__func__, __LINE__);
			goto OUT;
		}
		nocsw = nocsw + (noctw - ret);
		lsize = lsize - (noctw - ret);
		noctw = lsize;
		i++;

	}
	//printk(KERN_ERR "%s : Written by user application : %s \n",__func__, (char*)curr->data[0]);
	//printk(KERN_ERR "%s : Written by user application : %s \n",__func__, (char*)curr->data[1]);


#ifdef DEBUG
		printk(KERN_INFO "%s End !!\n",__func__);
#endif

	return nocsw;
	//return lsize;
OUT:
	printk(KERN_ERR  "%s : Error while writing in device" , __func__);
	return -1;
}
