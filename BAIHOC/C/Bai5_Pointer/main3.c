#include <stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}

int main(int argc, char const *argv[])
{
    int i = 10;
    void * ptr = &i;
    printf("Gia tri cua i: %d, dia chi: %p\n",*(int*)ptr, ptr);
    double d = 10.3;
    ptr = &d;
    printf("Gia tri cua d: %f, dia chi: %p\n",*(double*)ptr, ptr);
    ptr = &tong;
    ((void(*)(int, int))ptr)(9,7);
    void * array[] = {&i, &d, &tong};
    printf("Gia tri cua d: %f, dia chi: %p\n", *(double*)array[1], array[1]);
    ((void(*)(int, int))array[2])(8,6);
    ptr = NULL;
    
    return 0;
}
