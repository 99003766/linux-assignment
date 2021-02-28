#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
 int fname,s;
 char *ptr=(char *)calloc(100,sizeof(char));
 fname=open("file.txt",O_RDONLY|O_CREAT, 0666);
 int inword;
 if(fname<0)
    {
 perror("Error:");
 exit(1);
    }
 s=read(fname,ptr,100);
 ptr[s]="\0";
 int words=0,count=0,countLine=0,num;

 

for(num=0;num<strlen(ptr);num++)
{
      if(ptr ==' '|| ptr=='\t'|| ptr=='\0')
    {
       if(inword)
         {
         inword=0;
          words++;
         }
    }
 if(ptr[num]=='\n')
 {
     countLine++;
 }
 else
  {
      words=1;
  }
}
 printf("\nTotal lines %d\n Total words %d\n Total characters: %d\n",countLine,words,num);
 close(fname);
}