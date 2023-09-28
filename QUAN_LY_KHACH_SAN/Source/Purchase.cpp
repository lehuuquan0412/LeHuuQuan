/*
* File: Purchase.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện chức năng thanh toán.
*/
#include "Purchase.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Purchase
* Description: Hàm thực hiện chức năng thanh toán.
* Input:
*   listof_Room: vector danh sách phòng.
*   manage_Client: biến quản lý dữ liệu khách hàng.
*   listof_Pay: vector lịch sử thanh toán.
* Output:
*   Cho phép kiểm tra thông tin của từng phòng.
*   Thực hiện thanh toán và ghi nhận vào lịch sử thanh toán.
*/
void Purchase(vector<RoomInfo> & listof_Room, ClientManager*manage_Client, vector<Pay_History> & listof_Pay){
    int key = 0;
    int opt;
    int choose;
    int id_Var;
    string name_Var;
    string address_Var;
    string usernames_var;
    string password_var;
    string new_pass1;
    string new_pass2;
    bool status_Room_choose;
    historyClient history_temp;
    double charge;

    while (1)
    {
        system("cls");
        cout<<"====PURCHASE===="<<endl<<endl;
        //Kiểm tra số phòng hôm nay. Nếu chưa đặt số phòng thì thoát.
        if (listof_Room.empty())
        {
            cout<<"No room at here!!!"<<endl;
            system("pause");
            return;
        }
        //Kiểm tra tình trạng các phòng.
        key = 0;
        for (auto x: listof_Room)
        {
            if (x.get_statusRoom())
            {
                break;//Nếu có phòng được đặt thì có thể thanh toán được.
            }else key++; 
        }
        // Nếu tất cả các phòng chưa được đặt thì ngay lập tức thoát.
        if (key == listof_Room.size())
        {
            cout<<"All room have not been booked yet!!!"<<endl;
            system("pause");
            return;
        }
        //In danh sách phòng.
        print_Listof_Room(listof_Room);
        //Nhập số phòng cần thanh toán.
        while (1)
        {
            cout<<"Enter number of room: "; cin >> id_Var;
            if (check_Status_Room(id_Var,listof_Room))
            {
                break;
                
            }else cout<<"The room is empty!!!"<<endl;  
        }
        //In thông tin khách hàng ở phòng.
        for (auto x: manage_Client->get_dataClient())
        {
            if (x.get_Idroom_client() == id_Var)
            {
                print_titleClient();
                print_InfoClient(x);
                break;
            }
        }
        cout<<endl;
        cout<<"1. Purchase."<<endl;
        cout<<"0. Back."<<endl;
        cout<<"______________________"<<endl;
        while (1)
        {
            cout<<"Enter your choose: "; cin >> key;
            if (key == 1)
            {
                //Nhập thời gian trả phòng.
                cout<<" # CHECK-OUT TIME # "<<endl;
                history_temp.time_Book = enter_Schedule_times(history_temp.time_Book);
                history_temp.date_Book = enter_Schedule_dates(history_temp.date_Book);
                history_temp.statusClient = OUT;
                for (int i = 0; i < (int)(manage_Client->get_dataClient().size()); i++)
                {
                    if (id_Var == manage_Client->get_dataClient()[i].get_Idroom_client())
                    {
                        manage_Client->get_dataClient()[i].set_history_Client(history_temp);
                        Pay_History pay_temp(0,manage_Client->get_dataClient()[i].get_Idroom_client(),manage_Client->get_dataClient()[i].get_phoneNumber(),manage_Client->get_dataClient()[i].get_nameClient(),manage_Client->get_dataClient()[i].get_address());
                        pay_temp.get_Time_History(id_Var,manage_Client->get_dataClient());
                        listof_Pay.push_back(pay_temp);
                        break;
                    }  
                }
                system("cls");
                //Xuất hóa đơn.
                cout<<"# RECEIPT #"<<endl<<endl;
                cout<<"1. Name: "<<listof_Pay[listof_Pay.size()-1].get_nameClient()<<endl;
                cout<<"2. Phone number: 0"<<listof_Pay[listof_Pay.size()-1].get_phoneNumber()<<endl;
                cout<<"3. Address: "<<listof_Pay[listof_Pay.size()-1].get_address()<<endl;
                cout<<"4. Booking time: ";
                print_Time(listof_Pay[listof_Pay.size()-1].get_history_Booking()[0].time_Book);
                cout<<"   ";
                print_Date(listof_Pay[listof_Pay.size()-1].get_history_Booking()[0].date_Book);
                cout<<endl<<"5. Check-out timee: ";
                print_Time(listof_Pay[listof_Pay.size()-1].get_history_Booking()[listof_Pay[listof_Pay.size()-1].get_history_Booking().size()-1].time_Book);
                cout<<"   ";
                print_Date(listof_Pay[listof_Pay.size()-1].get_history_Booking()[listof_Pay[listof_Pay.size()-1].get_history_Booking().size()-1].date_Book);
                cout<<endl<<"Price: 50000 VND/h ";
                cout<<endl<<"______________________"<<endl;
                charge = purchase(listof_Pay[listof_Pay.size()-1].get_history_Booking()[0],listof_Pay[listof_Pay.size()-1].get_history_Booking()[listof_Pay[listof_Pay.size()-1].get_history_Booking().size()-1]);
                listof_Pay[listof_Pay.size()-1].set_Purchase(charge);
                cout<<"# TOTAL: "<<charge<<" VND"<<endl<<endl;
                //Thanh toán.
                cout<<"Do you want to purchase ?"<<endl;
                cout<<"1. Yes."<<endl;
                cout<<"0. No."<<endl<<endl;
                do
                {
                    cout<<"Enter your choose: "; cin >> key;
                    if (key == 0)
                    {
                        listof_Pay.pop_back();
                        break;
                    }
                } while (key > 1);

                if (key == 1)
                {
                    do
                    {
                        cout<<endl<<"Choose your payment method:"<<endl;
                        cout<<"1. Cash."<<endl<<"2. Credit card."<<endl<<"3. Internet Banking."<<endl<<"0. Back"<<endl<<endl;
                        cout<<"Enter your choose: "; cin >> opt;
                        if (opt == 0)
                        {
                            listof_Pay.pop_back();
                            break;
                        }
                    } while (opt > 3);
                    if (opt == 1 || opt == 2 || opt == 3)
                    {
                        cout<<" Pay processing.... "<<endl;
                        system("pause");
                        for (int i = 0; i < (int)(manage_Client->get_dataClient().size()); i++)
                        {
                            if (id_Var == manage_Client->get_dataClient()[i].get_Idroom_client())
                            {
                                manage_Client->get_dataClient().erase(manage_Client->get_dataClient().begin()+i);
                                break;
                            }
                        }

                        for (int i = 0; i < (int)(listof_Room.size()); i++)
                        {
                            if (id_Var == listof_Room[i].get_idRoom())
                            {
                                listof_Room[i].set_statusRoom(false);
                                break;
                            }
                        }
                        cout<<"Pay successful!!!"<<endl;
                        break;
                    }else break;
                }else break;
            }else if (key == 0)
            {
                return;
            }else cout<<"Syntax error.Please pre-enter!!!"<<endl;
        }
        if (key == 1)
        do
        {
            cout<<"Do you want continue to purchase?"<<endl;
            cout<<"1. Yes."<<endl<<"0. No"<<endl;
            choose = enter_Choose();
        } while (choose > 1);
        if (choose == 0) break;   
    }
    return;
}