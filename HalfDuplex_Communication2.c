#include"header.h"

int main()
{
	int fdr,fdw;
	char S_data[100]={0},R_data[100]={0};
	fdr=open("fifohd2",O_RDWR);
	fdw=open("fifohd1",O_RDWR);
	while(1)
	{
		bzero(R_data,sizeof(R_data));
		read(fdr,R_data,sizeof(R_data));
		printf("\tFrom...\n\t\t%s\n",R_data);
		printf("You...\n");
		__fpurge(stdin);
		scanf("%[^\n]s",S_data);
		write(fdw,S_data,strlen(S_data)+1);


	}
}
