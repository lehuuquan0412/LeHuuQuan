/*
* File: Booking_room.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện chức năng đặt phòng.
*/
#include "Booking_room.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"
/*
* Function: Booking_room
* Description: Hàm thực hiện chức năng đặt phòng.
* Input:
*   listof_Room: vector danh sách phòng.
*   manage_Client: biến quản lý dữ liệu khách hàng.
* Output:
*   Mô phỏng các chức năng như quản lý đặt phòng, quản lý phòng trong ngày.
*   Cho phép thực hiện ghi nhận thông tin đặt phòng của khách hàng như: Tên, Địa chỉ, Số điện thoại, Thời gian.
*   Cung cấp số phòng trong ngày.
*/
void Booking_room(vector<RoomInfo> & listof_Room,ClientManager*manage_Client){
    int key;
    int opt;
    int choose_Temp;
    int id_Var;
    string name_Var;
    string address_Var; 
    int phone_Var;
    string usernames_var;
    string password_var;
    string new_pass1;
    string new_pass2;
    Times time_temp_On;
    Dates date_temp;
    historyClient history_temp;

    

    while (1)
    {
        system("cls");
        cout<<" ====BOOKING ROOM===="<<endl<<endl;
        cout<<"1.Set the number of rooms."<<endl;
        cout<<"2.Booking."<<endl;
        cout<<"0.Back."<<endl;
        cout<<"______________________"<<endl;
        cout<<"Enter your choose: "; cin >> key; cout<<endl;
        
        switch (key)
        {
        case 1:
            cout<<"______________________"<<endl;
            int numof_Room;
            cout<<"Enter the number of rooms: "; cin >> numof_Room;
            Set_Numberof_Room(numof_Room,listof_Room);
            cout<<"Setting successful!!!"<<endl;
            system("pause");
            break;
        
        case 2:
            while (1)
            {
                cout<<"______________________"<<endl;
                if (listof_Room.empty())
                {
                    cout<<"No room available!!!"<<endl;
                    system("pause");
                    break;
                }else{
                    print_Listof_Room(listof_Room);
                    cout<<endl;
                    cout<<" 1. Enter number of room. "<<endl;
                    cout<<" 0. Back."<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Enter your choose: "; cin >> opt; cout<<endl;
                    switch (opt)
                    {
                    case 1:
                    {    
                        while (1)
                        {
                            while (1)
                            {
                                cout<<"Enter number of room: "; cin >> id_Var;
                                if (check_Status_Room(id_Var,listof_Room))
                                {
                                    cout<<"The room is not exist or booked previous!!!"<<endl;
                                }else break;   
                            }
                            cout<<"Enter name: ";
                            cin.ignore();
                            getline(cin,name_Var);
                            while (1)
                            {
                                cout<<"Enter phone number: ";
                                cin>>phone_Var;
                                if (Numof_Digits(phone_Var) == 9)
                                {
                                    break;
                                }
                                else cout<<"Phone is incorrect.Please pre-enter!!!"<<endl;   
                            }
                            cout<<"Enter address: ";
                            cin.ignore();
                            getline(cin,address_Var);
                            cout<<endl;
                        
                            ClientInfo temp(id_Var,phone_Var,name_Var,address_Var);
                            cout<<"Booking time:"<<endl;
                            history_temp.time_Book = enter_Schedule_times(time_temp_On);
                            history_temp.date_Book = enter_Schedule_dates(date_temp);
                            history_temp.statusClient = enter_Schedule_status(history_temp.statusClient);
                            temp.set_history_Client(history_temp);
                            manage_Client->add_Client(temp,listof_Room);
                            cout<<"Adding completely!!!"<<endl<<endl;
                            do
                            {
                                cout<<"1. Continue booking."<<endl<<"0. Back."<<endl;
                                choose_Temp = enter_Choose();    
                            } while (choose_Temp > 1);
                            if(choose_Temp == 0) break;
                        } 
                        break;
                    }
                    
                    case 0:{
                        break;}
                    default:{
                        cout<<"Syntax error.Please pre-enter!!!"<<endl;
                        system("pause");}
                    }
                }
                if (opt == 0) break;
            }
            break;

        case 0:{
            return;}
        
        default:{
            cout<<"Syntax error.Please pre-enter!!!"<<endl;
            system("pause");
            break;}
        }
    }
}