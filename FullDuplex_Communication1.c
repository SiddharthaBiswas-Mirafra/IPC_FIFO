#include"header.h"

int main()
{
	int fdr,fdw;
	char S_data[100]={0},R_data[100]={0};
	mkfifo("f1",0666);
	perror("mkfifo");
	mkfifo("f2",066);
	perror("mkfifo");
	fdr=open("f1",O_RDWR);
	perror("open_1");
	fdw=open("f2",O_RDWR);
	perror("open_2");
	if(fork()==0)
	{
		while(1)
		{
		bzero(R_data,sizeof(R_data));
		read(fdr,R_data,sizeof(R_data));
		printf("\tFrom...\n\t\t%s\n",R_data);
		}


	}
	else
	{
		while(1)
		{
		__fpurge(stdin);
		scanf("%[^\n]s",S_data);
		write(fdw,S_data,strlen(S_data)+1);
		}

	}
}
