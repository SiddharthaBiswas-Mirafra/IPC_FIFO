#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/resource.h>
int main(int c,char **v)
{
	int fd;
	char str[20];
	mkfifo(v[1],0666);
	if(fork()==0)
	{
		printf("in child\n");
		fd=open(v[1],O_RDWR);
		printf("fd %d enter the data: ",fd);
		__fpurge(stdin);
		scanf("%[^\n]s",str);
		write(fd,str,sizeof(str));
		close(fd);
	}
	else
	{
		printf("in parent\n");
		sleep(5);
		fd=open(v[1],O_RDWR);
		read(fd,str,sizeof(str));
		printf("\n%d data recive==%s\n",fd,str);
		close(fd);
	}
}


