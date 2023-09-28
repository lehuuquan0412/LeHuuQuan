#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int taiKhoan = 100;
mutex taiKhoanMutex;

void napTien(int soTien){
    while(1){
        this_thread::sleep_for(chrono::seconds(3));
        look_guard<mutex> look(taiKhoanMutex);
        taiKhoan += soTien;
        cout<<"Tai khoan: "<<soTien<<endl;
    }
}

void rutTien(int soTien){
    while(1){
        this_thread::sleep_for(chrono::seconds(1));
        look_guard<mutex> look(taiKhoanMutex);
        taiKhoan -= soTien;
        cout<<"Tai khoan: "<<soTien<<endl;
    }
}

int main(){
    thread t1(napTien, 20);
    thread t2(rutTien, 10);

    t1.join();
    t2.join();

    return 0;
}