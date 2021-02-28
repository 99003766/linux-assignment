#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int NEWFILE,UPDATEFILE,Nbytes;
	NEWFILE=open("file.txt",O_RDONLY);
	if(NEWFILE<0)
	{
		perror("open");
		exit(1);
	}
	int strlength=500;
	char arr[strlength];
	Nbytes=read(NEWFILE,arr,strlength); // using system call to read from the file 
	if(Nbytes<0)
	{
		perror("Read");
		exit(2);
	}
	UPDATEFILE=open("Write.txt",O_WRONLY|O_CREAT, 0666); //using system call to open new file and if file not found than create new file.
	if(UPDATEFILE<0)
	{
		perror("Open");
		exit(1);
	}
	int len=strlen(arr);
	Nbytes=	write(UPDATEFILE, arr, len);
	if(Nbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("Content Copied, Nbytes= %d\n",Nbytes);
    close(NEWFILE);
    close(UPDATEFILE);
	return 0;	
}