#include"header.h"
#include"declare.h"

int exit_program(char* mode)
{
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	if(strncmp(mode,"success",7)==0)
	{
		printf("%s going to exit with Success\n",__func__);
		exit(EXIT_SUCCESS);
	}
	else if ( strncmp(mode,"failure",7)==0)
	{
		printf("%s going to exit with failure\n",__func__);
		exit(EXIT_FAILURE);
	}
	
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return 0;
}
