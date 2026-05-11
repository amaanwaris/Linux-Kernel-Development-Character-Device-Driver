#include"header.h"
#include"declare.h"

int open_Device()
{
	char mode;
	int fd;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	printf("%s give the file open mode\n",__func__);
	getchar();
	printf("%s r for (read), w for (write)\n",__func__);
	mode=getchar();
	if(mode=='w')
		fd=open("/dev/myDev",O_WRONLY);
	else if(mode=='r')
		fd=open("/dev/myDev",O_RDONLY);
	if (fd==-1)
	{
		perror("open");
		exit_program("failure");
	}

		
	printf("%s Device FD = %d\n",__func__, fd);
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return fd;
}
