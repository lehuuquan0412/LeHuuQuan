#include <stdio.h>
#define ARG(var2 , ...)                 \
    __VA_ARGS__;                        \
    int var2;
#define DISPLAY(var3, ...)                    \
    __VA_ARGS__;
    int var3;
#define VALUE(cmd)                      \
    printf(cmd);                        \
    printf("\n");
int main(int argc, char const *argv[])
{
    ARG(xyz,"mnk");
    DISPLAY(
        ten,
        VALUE("TEST1")
        VALUE("TEST2")
        VALUE("TEST3")
    )
    return 0;
}

