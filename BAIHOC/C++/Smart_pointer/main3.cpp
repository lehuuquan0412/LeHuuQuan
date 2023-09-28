#include <iostream>
#include <memory>

using namespace std;

void test(){
    shared_ptr<int> sptr1(new int(10));
    shared_ptr<int> sptr2 = sptr1;

    cout<<*sptr1<<endl;
    cout<<*sptr2<<endl;
}

int main(){
    test();

    return 0;
}