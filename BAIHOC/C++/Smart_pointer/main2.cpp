#include <iostream>
#include <memory>

using namespace std;

void test(){
    unique_ptr<int[]> array(new int(10));

    for(int i = 0; i < 10; i++){
        array[i]= i;
    }

    for(int i = 0; i < 10; i++){
        cout<<"var: "<<array[i]<<endl;
    }
    
}

int main(){
    test();

    return 0;
}