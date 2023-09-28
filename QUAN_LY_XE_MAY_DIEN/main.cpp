#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>


using namespace std;
// Mức max min của dung lượng pin và nhiệt độ pin.
typedef enum{
    MAX = 100,
    MIN = 20
}Bat_power_lever;

//Khai báo kiểu dữ liệu quản lý pin.
class Battery_management{
    private:
        int Bat_capacity;
        int Bat_temperatuer;
        bool status_Fan;
    public:
        Battery_management(int bat_capa, int bat_temp);
        void set_Bat_capacity(int bat_capa);
        void set_Bat_temperature(int bat_temp);
        void set_status_Fan(bool status);
        int get_Bat_capacity();
        int get_Bat_temperature();
        bool get_status_Fan();
};

Battery_management::Battery_management(int bat_capa, int bat_temp){
    this->Bat_capacity = bat_capa;
    this->Bat_temperatuer = bat_temp;
    if (this->Bat_temperatuer > 50)
    {
        this->status_Fan = true;
    }else this->status_Fan = false;  
};

void Battery_management::set_Bat_capacity(int bat_capa){
    this->Bat_capacity = bat_capa;
};

void Battery_management::set_Bat_temperature(int bat_temp){
    this->Bat_temperatuer = bat_temp;
    if (this->Bat_temperatuer > 50)
    {
        this->status_Fan = true;
    }else this->status_Fan = false; 
};

void Battery_management::set_status_Fan(bool status){
    this->status_Fan = status;
};

int Battery_management::get_Bat_capacity(){
    return this->Bat_capacity;
}

int Battery_management::get_Bat_temperature(){
    return this->Bat_temperatuer;
}

bool Battery_management::get_status_Fan(){
    return this->status_Fan;
}

//Hiển thị tín hiệu báo rẽ trái.
void dislay_turn_signal_Left(bool*turn_signal_left){
    if (*turn_signal_left)
    {
        cout<<"LEFT";
    }else cout<<"----";
}

//Hiển thị tín hiệu báo rẽ phải.
void dislay_turn_signal_Right(bool*turn_signal_right){
    if (*turn_signal_right)
    {
        cout<<"RIGHT";
    }else cout<<"-----";
}

//Hiển thị trạng thái quạt.
void display(bool status_fan){
    if (status_fan)
    {
        cout<<"ON.";
    }else cout<<"OFF.";
}

//Hàm thay đổi tín hiệu báo rẽ.
void change_turn_Signal(bool*status,bool*status_opposite){
    if (*status_opposite)
    {
        *status_opposite = false;
        *status = true;
    }else{
        if (*status)
        {
            *status = false;
        }else *status = true; 
    }
}

//Hàm thay đổi trạng thái hoạt động của xe.
void change_status_Car(bool*status_car){
    if (*status_car)
    {
        *status_car = false;
    }else *status_car = true;  
}

//Hàm hiển thị thông tin các tín hiệu báo rẽ trên bảng điều khiển.
void display_info_Signal(bool*left, bool*right, bool*status_car){
    cout<<"TURN SIGNAL: ";
    if (*status_car)
    {
        dislay_turn_signal_Left(left);
        cout<<"|";
        dislay_turn_signal_Right(right);
        cout<<endl;
    }else cout<<"----------"<<endl;  
}

//Hiển thị thông tin tốc độ trên bảng điều khiển.
void display_info_Speed(int*speed, bool*status_car){
    cout<<"SPEED: ";
    if (*status_car)
    {
        cout<<*speed<<" Km/h"<<endl;
    }else cout<<"----------------"<<endl;
}

//Hiển thị thông tin quạt trên bảng điều khiển.
void display_info_Fan(Battery_management*tram, bool*status_car){
    cout<<"COOLING FAN: ";
    if (*status_car)
    {
        display((tram->get_status_Fan()));
        cout<<endl;
    }else cout<<"----------"<<endl;
}

//Hiển thị trạng thái xe trên bảng điểu khiển.
void display_info_Car(bool*status_car){
    cout<<"START: ";
    display(*status_car);
    cout<<endl;
}

//Ghi nhận nhiệt độ của pin sau mỗi 3s và điều chỉnh trạng thái quạt cho phù hợp.
void fan_mode(Battery_management*tram){
    while (1)
    {
        int temp = MIN + rand()%(MAX + 1 - MIN);
        tram->set_Bat_temperature(temp);
        this_thread::sleep_for(chrono::seconds(3));
    }
}

//Điều chỉnh trạng thái của pin khi bth và khi xạc.
void bat_mode(Battery_management*tram, bool*charge, bool*status_car){
    while (1)
    {
        if (tram->get_Bat_capacity() == MAX)
        {
            *charge = false;
        }
        if (tram->get_Bat_capacity() == 0)
        {
            *status_car = false;
        }
        
        if (*status_car)
        {
            int temp = tram->get_Bat_capacity();
            temp--;
            this_thread::sleep_for(chrono::seconds(2));
            tram->set_Bat_capacity(temp);
        }else{
            if (*charge)
            {
                int temp = tram->get_Bat_capacity();
                temp++;
                this_thread::sleep_for(chrono::seconds(2));
                tram->set_Bat_capacity(temp);
            }
        }
    }
    if (tram->get_Bat_capacity() == 0)
    {
        *status_car = false;
    }
}

//Hiển thị trạng thái pin khi bình thường và khi xạc.
void display_Power_bat(Battery_management*temp,bool*charge_mode){
    if (*charge_mode)
    {
        cout<<"CHARGING:"<<temp->get_Bat_capacity()<<" %"<<endl;
    }else cout<<"BAT:"<<temp->get_Bat_capacity()<<" %"<<endl;  
}

/*
* Function: control_car
* Description: Hàm điểu khiển toàn bộ chức năng của xe.
* Input:
*   left - tín hiệu rẽ trái.
*   right - tín hiệu rẽ phải.
*   status_car - tình trạng hoạt động của xe.
*   charge - trạng thái xạc của xe.
*   speed - tốc độ của xe.
* Output:
*   điều chỉnh các thông số trên xe thông qua yêu cầu từ bàn phím.
*/

void control_Car(bool*left, bool*right, bool*status_car, bool*charge, int*speed){
    while (1)
    {
        int key;
        key = _getch();
        switch (key)
        {
        case 72:
            if (*status_car)
            {
                (*speed)++;
            }
            break;
        case 80:
            if (*status_car)
            {
                if ((*speed) > 0)
                {
                    (*speed)--;
                }
            }
            break;
        case 75:
            change_turn_Signal(left, right);
            break;
        case 77:
            change_turn_Signal(right, left);
            break;
        case 13:
            if (*status_car == false)
            {
                *charge = false;
            }
            change_status_Car(status_car);
            break;
        case 32:
            if (*status_car)
            {
                break;
            }else if (*charge)
            {
                *charge = false;
                break;
            }else *charge = true;
            break;
        case 27:
            exit(0);
        default:
            break;
        }
    }
}

//Hàm biểu diễn màn hình hiển thị.
void display_all(Battery_management*tram, bool*left, bool*right, bool*status_car, bool*charge, int*speed){
    while (1)
    {
        system("cls");
        display_Power_bat(tram, charge);
        display_info_Signal(left, right, status_car);
        display_info_Fan(tram, status_car);
        display_info_Speed(speed, status_car);
        cout<<"-----------------------"<<endl;
        display_info_Car(status_car);
        this_thread::sleep_for(chrono::seconds(1));
    }
}




int main(int argc, char const *argv[])
{
    int speed = 50;
    bool signal_turn_Left = false;
    bool signal_turn_Right = false;
    bool status_car = false;
    bool charge = false;
    Battery_management tram(70,(MIN + rand()%(MAX + 1-MIN)));


    thread display_info(display_all,&tram, &signal_turn_Left, &signal_turn_Right, &status_car, &charge, &speed);
    thread bat(bat_mode, &tram, &charge, &status_car);
    thread fan(fan_mode, &tram);
    thread control(control_Car, &signal_turn_Left, &signal_turn_Right, &status_car, &charge, &speed);

    display_info.join();
    bat.join();
    fan.join();
    control.join();
    

    return 0;
}
