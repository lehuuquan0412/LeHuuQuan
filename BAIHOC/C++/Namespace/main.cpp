#include <iostream>
#include "test.cpp"

using namespace std;

namespace ConOngA{
    int Teo = 20;
    char array[] = "Hello World\n";

class SinhVien{
    public:
    int a;
};
}
namespace ConOngB{
    int Teo = 40;
}
using namespace ConOngA;

int main(int argc, char const *argv[])
{
    ConOngA::Teo = 70;
    cout<<"Teo: "<<ConOngA::Teo<<endl;
    cout<<"Teo: "<<ConOngB::Teo<<endl;
    ConOngA::Tuan;
    cout<<"Teo: "<<Teo<<endl;
    SinhVien sv;
    sv.a = 30;
    return 0;
}

