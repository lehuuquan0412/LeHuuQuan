#include <stdio.h>
#define INPUT_DISPLAY(var, cmd, cond)   \
    int var;                            \
    do                                  \
    {                                   \
        printf(cmd);                    \
        scanf("%d", &var);              \
    } while (cond);                     \
    printf(#var);                       \
    printf(" = %d\n", var);
int main(int argc, char const *argv[]) {
    /*Dung define de thay the*/
    // int i;
    // do
    // {
    //     printf("Nhap vao i (i >= 0 && i <= 10): ");
    //     scanf("%d", &i);
    // } while (i > 10);
    // printf("i = %d\n",i);
    INPUT_DISPLAY(i, "Nhap vao i (i >= 0 && i <= 10): ", i > 10);
    return 0;
}