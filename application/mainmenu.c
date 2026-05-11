#include"header.h"
#include"declare.h"

int main_menu()
{
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	int choise;
	printf(" __Application main menu\n");
	printf("1. open Device\n");
	printf("2. close device\n");
	printf("3. write into device\n");
	printf("4. read from device\n");
	printf("0.exit Application\n");
	printf("enter your choise\n");
	scanf("%d",&choise);
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return choise;
}
