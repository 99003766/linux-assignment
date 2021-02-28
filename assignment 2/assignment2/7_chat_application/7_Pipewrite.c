#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{
    int file_dr; 
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char Input1[200], Input2[200];
    while (1)
    {
    file_dr = open(myfifo, O_WRONLY);
    fgets(Input2, 100, stdin);
    write(file_dr, Input2, strlen(Input2)+1);
    close(file_dr);
    read(file_dr, Input1, sizeof(Input1));
    printf("client1: %s\n", Input1);
    close(file_dr);
    }
return 0;
}