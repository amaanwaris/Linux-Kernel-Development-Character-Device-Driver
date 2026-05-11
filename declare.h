#include "header.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Implementing Open Routine");
MODULE_AUTHOR("Batch-B.540.005");
MODULE_VERSION("1.1");

#ifndef DEBUG
#define DEBUG
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif


#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 1
#endif


#ifndef CDDNAME
#define CDDNAME "test_driver"
#endif

#ifndef DEVSIZE
#define DEVSIZE 256
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef REGSIZE
#define REGSIZE 2
#endif


#ifndef NOFREGS
#define NOFREGS 4
#endif

extern dev_t dvid,devno;
extern int majorNo,minorNo,nod;
extern int devsize,datasize,regsize,nofregs;

typedef struct Qset
{
	struct Qset * next;
	void ** data;	
	int count; // to know how many quantums of data (prev specified) are filled
}Qset;

typedef struct dev
{
	int devsize;
	int datasize;
	int regsize;
	int nofregs;
	struct cdev c_dev;
	Qset* first; // Quantum set for SCULL
}Dev;

extern Dev *dev;
int openDevice(struct inode *, struct file *);
int releaseDevice(struct inode *, struct file *);

int trimDevice(Dev*);
ssize_t writeDevice (struct file * filep, const char __user * buff, size_t count , loff_t * f_pos);
ssize_t readDevice (struct file * filep, char __user * buff, size_t count , loff_t * f_pos);

Qset* createScull (size_t size);


