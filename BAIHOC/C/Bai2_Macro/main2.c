#include <stdio.h>
#define TONG(a, b) a + b
void test() {
    printf("This is test \n");
}
#define PRINTF test()
int main(int argc, char const *argv[]) {
    printf("Tong a va b: %d\n", TONG(5, 9));
    PRINTF;
    return 0;
}