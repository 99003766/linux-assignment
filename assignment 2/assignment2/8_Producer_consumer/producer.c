#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/mman.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
 
int main() 
{ 
 const int Size = 4096; 
 const char* Name = "OS"; 
 const char* message_0 = "Hello"; 
 const char* message_1 = "From Jayasimha"; 
 int shm_file_dr; 
 void* ptr; 
 shm_file_dr = shm_open(Name, O_CREAT | O_RDWR, 0666); 
 ftruncate(shm_file_dr, Size); 
 ptr = mmap(0, Size, PROT_WRITE, MAP_SHARED, shm_file_dr, 0); 
 sprintf(ptr, "%s", message_0); 
 ptr += strlen(message_0); 
 sprintf(ptr, "%s", message_1); 
 ptr += strlen(message_1); 
 return 0; 
}