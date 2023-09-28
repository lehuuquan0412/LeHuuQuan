#include<stdio.h>

//static
int *ptr;

void test(){
    static int i = 0;
    ptr = &i;
    printf("i = %d\n",i++);
}

void print(){
    int i = 0;
    printf("i2 = %d",i);
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
