#include <stdio.h>

#define SIZE 10
//Kiem tra SIZE da duoc dinh nghia chua?
#ifndef SIZE
    void test();
#endif
#if SIZE > 10
//
void test4(){
    printf("SIZE > 10");
}
#elif SIZE == 10
//
void test4(){
    printf("SIZE = 10");
}
#elif SIZE < 10
//
void test4(){
    printf("SIZE < 10");
}
#endif

int main(int argc, char const *argv[]) {
    int array[SIZE];
    int var = SIZE;
return 0;
}