#include <stdio.h>

int main(int argc, char const *argv[])
{
    int var = 10;
    printf("Gia tri cua var: %d, dia chi: %p\n", var, &var);
    int * ptr = &var;
    printf("Gia tri cua var: %d, dia chi: %p\n", *ptr, ptr);
    return 0;
}
