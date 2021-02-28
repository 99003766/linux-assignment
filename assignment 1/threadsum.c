#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data
{
    int* arr;
    int threadnum;
} data;
int Size = 10;
void* halfSum(void* p)
{
    data* ptr = (data*)p;
    int n = ptr->threadnum;
    int* threadsum = (int*) calloc(1, sizeof(int));
    if(n == 0)
    {
        for(int i = 0; i < Size/2; i++)
        {
            threadsum[0] = threadsum[0] + ptr->arr[i];
        }
    }
    else{
        for(int i = Size/2; i<Size; i++)
        {
            threadsum[0] = threadsum[0] + ptr->arr[i];
        }
    } 
    pthread_exit(threadsum);
}
int main(void)
{
    int* sum0;
    int* sum1;
    int* int_arr = (int*) calloc(Size, sizeof(int));
    for(int i = 0; i <Size; i++)
    {
        int_arr[i] = i + 1;
    }
    data thread_data[2];
    thread_data[0].threadnum = 0;
    thread_data[0].arr = int_arr;
    thread_data[1].threadnum = 1;
    thread_data[1].arr = int_arr;
    pthread_t tid[2];
    pthread_create(&tid[0], NULL, halfSum, &thread_data[0]);
    pthread_create(&tid[1], NULL, halfSum, &thread_data[1]);
    pthread_join(tid[0], (void**)&sum0);
    pthread_join(tid[1], (void**)&sum1);
    printf("Sum of whole array = %i\n", *sum0 + *sum1);
    return 0;
}
