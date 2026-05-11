#include"header.h"
#include"declare.h"

#define DEBUG

Qset* createScull (size_t fsize)
{
	int itemSize, noOfItems;
	Qset* first, *last;

#ifdef DEBUG
		printk(KERN_INFO "%s: Begin !!\n",__func__);
#endif
		// 1. calculate item size
		itemSize = regsize * nofregs;

		// 2. calculate no of items
		noOfItems = fsize / itemSize;

		if( (fsize % itemSize) > 0 )
		{
			noOfItems++;
		}
#ifdef DEBUG
		printk(KERN_INFO "%s : noOfItems : %d\n",__func__, noOfItems);
#endif

		first = last = (Qset*)kmalloc(sizeof(Qset), GFP_KERNEL);
		if(last == NULL)
		{
			printk(KERN_ERR "%s ERROR: kmalloc() fialure !\n",__func__);
			goto OUT;

		}
		//memset(last, 0, sizeof(Qset));
		last->next = NULL;
		last->data = NULL;

#ifdef DEBUG
		printk(KERN_INFO "%s : first Qset allocated. \n",__func__);
#endif

		// 3. create link list
		for(int i = 1 ; i < noOfItems; i++)
		{
			last -> next = (Qset*)kmalloc(sizeof(Qset), GFP_KERNEL);
			if(last->next == NULL)
			{
				printk(KERN_ERR "%s ERROR: kmalloc() fialure !\n",__func__);
				goto OUT;
			}
			//memset(last->next, 0, sizeof(Qset)); // next node

			last = last->next;
			last->next = NULL;
			last->data = NULL;
			printk(KERN_ERR "%s: %dth Qset allocated.\n",__func__, i);
		}

		// to iterate from the beg
		last = first;

		// 4. Create memory pool
		for( int i = 0; i < noOfItems; i++)
		{
			last -> data = kmalloc(sizeof(char*) * nofregs , GFP_KERNEL);
			if(!last->data)
			{
				printk(KERN_ERR "%s ERROR: kmalloc() fialure !\n",__func__);
				goto OUT;
			}
			memset(last->data, 0, sizeof(char*) * nofregs);
			last = last->next;
			
		}

		// to iterate from the beg
		last = first;

		// 6. Quantums ? 
		int noq = fsize  / regsize;

		if(fsize % regsize > 0)
		{	
			noq++;
		}

		for( int i = 0, j = 0; j<noq;  j++)
		{
			last -> data[i] = kmalloc(sizeof(char) * regsize , GFP_KERNEL);
			if(!last->data[i])
			{
				printk(KERN_ERR "%s ERROR: kmalloc() fialure !\n",__func__);
				goto OUT;
			}

			printk("%s : Item: %d ; Quantum : %d, Allocated\n", __func__, j, i);

			//memset(last->data, 0, sizeof(char*) * nofregs);
			if(i == (nofregs -1) )
			{
				last = last-> next;
				i = 0;
				// in++;
			}
			else
				i++;
		}
			

#ifdef DEBUG
		printk(KERN_INFO "%s End !!\n",__func__);
#endif

	return first;

OUT:
	printk(KERN_ERR  "%s : Error while writing in device" , __func__);
	return NULL;
}
