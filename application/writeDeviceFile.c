#include"header.h"
#include"declare.h"

int writeDeviceFile(int fd)
{
	int len, ret; 
	char buff[] = "abcdefghijklmnopqrstuvwxyz012345";
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	len = strlen(buff);
	ret = write(fd, buff, len);

	if (ret == -1)
	{
		perror("write");
		return -1;
	}


#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return 0;
}
