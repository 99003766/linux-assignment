#include <unistd.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
int main() 
{ 
    int FD; 
    char *myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char Input1[200], input2[200]; 
    while (1) 
    { 
     FD = open(myfifo,O_RDONLY); 
     read(FD, Input1, 100); 
     printf("Client2: %s \n", Input1); 
     close(FD); 
     FD = open(myfifo,O_WRONLY); 
     fgets(input2, 100, stdin); 
     write(FD, input2, strlen(input2)+1); 
     close(FD); 
    } 
    return 0; 
}