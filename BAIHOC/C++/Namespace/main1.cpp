#include <iostream>

using namespace std; //sử dụng trong suốt CT mà k cần gõ std::

template <typename varA, typename varB> //có cấu trúc gần giống nhau

varA tong(varA a, varB b){
    return a + (varA) b;
}

// int tong(int a, int b){
//     return a + b;
// }

// double tong(double a, double b){
//     return a + b;
// }


int main(int argc, char const *argv[])
{
    printf("Tong a va b: %d\n", tong(7, 8));
    printf("Tong a va b: %f\n", tong(7.6, 8));

    return 0;
}

