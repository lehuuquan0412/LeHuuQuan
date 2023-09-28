#include<iostream>
#include<string>

using namespace std;

class ToanHoc
{   
public:
    void tong(int a, int b);
    void tong(int a,int b,int c);
    int tong(double a,int b);
};

void ToanHoc::tong(int a,int b){
    cout<<"Tong: "<<a+b<<endl;
}

void ToanHoc::tong(int a,int b,int c){
    cout<<"Tong: "<<a+b+c<<endl;
}

int ToanHoc::tong(double a,int b){
    return (int)a + b;
}

template<typename var>

var tong(var a,var b){
    return var(a+b);
}

int main(int argc, char const *argv[])
{
    ToanHoc sum;
    sum.tong(1,2);
    sum.tong(1,2,3);
    printf("Tong: %d\n",sum.tong(2.5,6));

    cout<<"Tong 2 so: "<<tong(6,5)<<endl;
    cout<<"Tong 2 so: "<<tong(2.5,3.1)<<endl;
    return 0;
}
