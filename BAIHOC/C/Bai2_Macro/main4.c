#include <stdio.h>
#define VARIABLE(var1, test1)           \
    int int_##var1;                     \
    double double_##var1;               \
    int test1;
int main(int argc, char const *argv[])
{
    VARIABLE(lam, abc);
    return 0;
}
