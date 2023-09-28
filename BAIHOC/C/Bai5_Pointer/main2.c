#include <stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}
void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a-b);
}
int tich(int a, int b){
    return a*b;
}
void tinhtoan(int a, int b, void (*ptr)(int, int)){
    printf("Tinh toan: \n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{
    void (*ptr)(int, int) = &tong;
    ptr(2,3);
    ptr = &hieu;
    ptr(5,3);
    int (*ptrtich)(int, int) = &tich;
    printf("Tich: %d\n", ptrtich(4,5));
    tinhtoan(7,5, &tong);
    return 0;
}
