#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

mutex mtx;
condition_variable cond_var;
bool check = false;
vector<int> products;

void producer(){
    for(int i = 0; i < 10; i++){
        look_guard<mutex> look(mtx);
        products.push_back(i);
    }
    for(int item : products){
        cout<<"item: "<<item<<endl;
    }
    check = true;
    this_thread::sleep_for(chrono::seconds(10));
    cond_var.notify_one();
}

void consumer(){
    unique_look<mutex> look(mtx);
    cond_var.wait(lock, []{return check;});

    for(int item : products){
        cout<<"consumer: "<<item<<endl;
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}