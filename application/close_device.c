#include"header.h"
#include"declare.h"

int close_Device(int rd)
{
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	close(rd);
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return 0;
}
