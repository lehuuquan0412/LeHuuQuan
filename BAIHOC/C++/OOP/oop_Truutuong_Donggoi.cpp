#include<iostream>
#include<math.h>
#include<string>

using namespace std;

typedef struct{
    double x1;
    double x2;
}Result;

class giaiPtbac2
{
public:
    giaiPtbac2(double a,double b,double c): a(a),b(b),c(c){}
    double delta;
    Result ketqua(){
        Result ketqua;
        delta = tinhDelta();
        if(delta > 0){
            ketqua.x1 = (-b + sqrt(delta))/(2*a);
            ketqua.x2 = (-b - sqrt(delta))/(2*a);
        }else if (delta = 0)
        {
            ketqua.x1 = -b/(2*a);
            ketqua.x2 = -b/(2*a);
        }else printf("Phuong trinh vo nghiep!!!");
        return ketqua;
    }
private:
    double a;
    double b;
    double c;
    double tinhDelta(){
        return b*b-4*a*c;
    }
};


int main(int argc, char const *argv[])
{
    giaiPtbac2 example(1,-3,2);
    printf("Hai nghiem cua phuong trinh la: %f , %f",example.ketqua().x1,example.ketqua().x2);
    return 0;
}
