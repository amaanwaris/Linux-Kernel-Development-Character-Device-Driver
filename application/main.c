#include"header.h"
#include"declare.h"

int main()
{
	int fd;
	int choise;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	while(1)
	{
		choise=main_menu();
		switch(choise)
		{

			case 0:
				exit_program("success");
				break;

			case 1:
				fd=open_Device();
				printf("%s : returned fd : %d\n",__func__, fd);

				break;

			
			case 2:
				close_Device(fd);
				break;
			case 3:
				writeDeviceFile(fd);
				break;
			case 4:
				readDeviceFile(fd);
				break;
			default:
				printf("%s not vaild option\n",__func__);
				break;
		}
	}
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return 0;
}
