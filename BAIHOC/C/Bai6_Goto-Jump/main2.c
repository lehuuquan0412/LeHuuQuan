#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
int main(int argc, char const *argv[])
{
    int var;
    jmp_buf env;
    var = setjmp(env);
    printf("Test: %d\n", var);
    if (var == 1)
    {
        exit(0);
    }
    longjmp(env,1);
    return 0;
}
