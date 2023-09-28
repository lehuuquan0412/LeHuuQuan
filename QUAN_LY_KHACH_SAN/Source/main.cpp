#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<math.h>
#include "Client_manager.h"
#include "Feedback.h"
#include "Purchase.h"
#include "Security_access.h"
#include "Service.h"
#include "Staff_manager.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"
#include "Booking_room.h"



int main(int argc, char const *argv[])
{
    
    //Khai báo các biến tạm thời trong chương trình.
    int key;
    string name_Var;
    string address_Var;
    string usernames_var;
    string password_var;
    string new_pass1;
    string new_pass2;
    //Các cơ sở dữ liệu quản lý hotel
    vector<Services> Service ;
    Services temp1("Pool",true);
    Services temp2("Bar",true);
    Services temp3("Fitness",true);
    Services temp4("Order",true);
    
    Service.push_back(temp1);
    Service.push_back(temp2);
    Service.push_back(temp3);
    Service.push_back(temp4);
    
    
    vector<RoomInfo> listof_Room;
    vector<Staff> listof_Staff;
    vector<Pay_History> listof_Pay;
    vector<Feedback_info> listof_Feedback;
    SecureManagement Sec_Manage_hotel;
    ClientManager manage_Client;
    
    while (1)
    {
        system("cls");
        cout<<"__________WELCOME__________"<<endl<<endl;
        cout<<" 1. BOOKING ROOM."<<endl;
        cout<<" 2. CLIENT MANAGEMENT."<<endl;
        cout<<" 3. STAFF MANAGEMENT."<<endl;
        cout<<" 4. PURCHASE."<<endl;
        cout<<" 5. SECURITY AND ACCESS"<<endl;
        cout<<" 6. STATISTICS AND REPORTS"<<endl;
        cout<<" 7. SERVICES AND FACILITIES"<<endl;
        cout<<" 8. FEEDBACK AND EVALUATION"<<endl;
        cout<<" 0. EXIT."<<endl<<endl;
        cout<<"______________________"<<endl;
        cout<<" Enter your choose: "; cin >> key;
        cout<<endl;
        switch (key)
        {
        case 1:
            if (access_manage_Client(usernames_var,password_var,Sec_Manage_hotel,listof_Staff) != 1) break;
            Booking_room(listof_Room,&manage_Client);
            break;
        case 2:
            if (access_manage_Client(usernames_var,password_var,Sec_Manage_hotel,listof_Staff) != 1) break;
            Client_manager(&manage_Client, listof_Room);
            break;
        case 3:
            Staff_manager(&Sec_Manage_hotel, listof_Staff);
            break;
        case 4:
            if (access_manage_Client(usernames_var,password_var,Sec_Manage_hotel,listof_Staff) != 1) break;
            Purchase(listof_Room,&manage_Client, listof_Pay);
            break;
        case 5:
            Security_access(&Sec_Manage_hotel, listof_Staff);
            break;
        case 6:
            system("cls");
            cout<<"====STATISTICS AND REPORTS===="<<endl;
            cout<<"No report or statistic at recent."<<endl;
            system("pause");
            break;
        case 7:
            if (access_manage_Client(usernames_var,password_var,Sec_Manage_hotel,listof_Staff) != 1) break;
            Service_facility(Service);
            break;
        case 8:
            Feedback(listof_Feedback);
            break;
        case 0:
            return 0;
        default:
            cout<<"Syntax error.Please pre-enter!!!"<<endl;
            break;
        }
    }  
}
