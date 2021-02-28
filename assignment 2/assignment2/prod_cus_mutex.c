#include<stdio.h>
#include<stdlib.h>
 
int mutexNo=1,full=0,empty_=3,x=0;

int main()
{
int n;
void producer();
void consumer();
int wait();
int signal();
printf("\n1.Producer\n2.Consumer\n3.Exit");
while(1)
{
	printf("\nEnter your choice:");
	scanf("%d",&n);
	switch(n)
	{
	case 1:	
    if((mutexNo==1)&&(empty_!=0))
    {
		producer();
    }
	else
    {
		printf("Buffer is full!!!");
    }
	break;
	case 2:	
    if((mutexNo==1)&&(full!=0))
    {
	consumer();
    }
	else
    {
	printf("Buffer is empty!!!");
    }
	break;
    case 3:
	exit(0);
	break;
	}
}
return 0;
}
int wait(int s)
{
	return --s;
}
 
int signal(int s)
{
	return ++s;
}
 
void producer()
{
	mutexNo=wait(mutexNo);
	full=signal(full);
	empty_=wait(empty_);
	x++;
	printf("\nProducer produces the item %d",x);
	mutexNo=signal(mutexNo);
}
void consumer()
{
	mutexNo=wait(mutexNo);
	full=wait(full);
	empty_=signal(empty_);
	printf("\nConsumer consumes item %d",x);
	x--;
	mutexNo=signal(mutexNo);
}