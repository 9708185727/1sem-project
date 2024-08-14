#ifndef Time
#define Time
#include<stdio.h>
#include<time.h>
void timer(){
    time_t t;
    time(&t);
    printf("%s",ctime(&t));
}
#endif

