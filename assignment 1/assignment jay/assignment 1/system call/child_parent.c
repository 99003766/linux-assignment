include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
 
void sighup(); 
void sigint(); 
void sigquit(); 
void main() 
{ 
 int pid; 
 if ((pid = fork()) < 0)
 { 
 perror("fork"); 
 exit(1); 
 } 
 if (pid == 0) 
 { 
 signal(SIGHUP, sighup); 
 signal(SIGINT, sigint); 
 signal(SIGQUIT, sigquit); 
 for (;;) 
 ;
 } 
 else
 { 
 printf("\nPARENT: parent is sending msg\n\n"); 
 kill(pid, SIGHUP); 
 
 sleep(1); // pause for 1 secs
 printf("\nPARENT:parent is sending msg\n\n"); 
 kill(pid, SIGINT); 
 
 sleep(2); // pause for 2 secs
 printf("\nPARENT: parent is sending msg\n\n"); 
 kill(pid, SIGQUIT); 
 sleep(3); 
 } 
}  
void sighup() 
{ 
 signal(SIGHUP, sighup);
 printf("CHILD: child is received the msg\n"); 
} 
void sigint() 
{ 
 signal(SIGINT, sigint);
 printf("CHILD:child is  received the msgT\n"); 
} 
void sigquit() 
{ 
 printf("Child is been killed\n"); 
 exit(0); 
}