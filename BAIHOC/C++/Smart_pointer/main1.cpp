#include <iostream>

using namespace std;


int main(){
    int *ptr = new int;

    *ptr = 20;

    cout<<"ptr: "<<*ptr<<endl;

    int *array = new int[10];
    
    for(int i = 0; i < 10; i++){
        *array[i]= 2*i;
    }

    for(int i = 0; i < 10; i++){
        cout<<"i: "<<i<<endl;
    }

    delete []ptr;

    delete []array;

    return 0;
}