#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
#define maxisize 16 
#define Th_maxisize 4 
int a[maxisize] = { 1,4,8,12,16,20,24,28,32,36,40}; 
int maxi_num[Th_maxisize] = {0}; 
int thread_no = 0; 
void maximum(void* arg) 
{ 
    int i, num = thread_no++; 
    int maxs = 0; 
  
    for (i = num * (maxisize / 4); i < (num + 1) * (maxisize/4); ++i) 
    { 
        if (a[i] > maxs) 
        {
            maxs = a[i];
        } 
    } 
  
    maxi_num[num] = maxs; 
} 
int main() 
{ 
    int maxs = 0; 
    int i; 
    pthread_t threads[Th_maxisize];
    for (i = 0; i<Th_maxisize; i++)
    {
        pthread_create(&threads[i], NULL, maximum, (void*)NULL); 
    }
    for (i = 0; i < Th_maxisize; i++)
    {
        pthread_join(threads[i], NULL); 
    }
    for (i = 0; i < Th_maxisize; i++) 
    { 
        if (maxi_num[i] > maxs)
             {
                 maxs = maxi_num[i];
             } 
    } 
    printf("Maximum Element: %d", maxs); 
    return 0; 
} 