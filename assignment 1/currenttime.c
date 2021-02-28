#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int hours, minutes, seconds, day, month, year;
    time_t now;
    time(&now);
    printf("Today is : %s", ctime(&now));
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;          
    minutes = local->tm_min;         
    seconds = local->tm_sec;
    if (hours<12)
    {  
        printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);
    }
    else 
    { 
        printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    }
    return 0;
}