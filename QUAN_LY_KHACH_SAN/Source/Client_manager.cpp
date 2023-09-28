/*
* File: Client_manager.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện chức năng quản lý thông tin khách hàng.
*/
#include "Client_manager.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Client_manager
* Description: Hàm thực hiện chức năng quản lý thông tin khách hàng.
* Input:
*   listof_Room: vector danh sách phòng.
*   manage_Client: biến quản lý dữ liệu khách hàng.
* Output:
*   Thực hiện các chức năng như sửa thông tin khách hàng hoặc xóa thông tin khách hàng thông qua ID phòng.
*/
void Client_manager(ClientManager*manage_Client, vector<RoomInfo> & listof_Room){
    int key;
    int opt;
    int choose_temp;
    int choose_temp_case2;
    int choose_temp_case3;
    int stt_Var;
    string name_Var;
    string address_Var;
    int phone_Var;

    while (1)
    {
        system("cls");
        cout<<"====CLIENT MANAGER===="<<endl<<endl;
        if (manage_Client->get_dataClient().empty())
        {
            cout<<"No client use service!!!"<<endl;
            system("pause");
            return;
        }
        print_dataClient(*manage_Client);
        cout<<"______________________"<<endl;
        
        cout<<" 1. Edit client information."<<endl;
        cout<<" 2. Remove client information."<<endl;
        cout<<" 0. Back."<<endl;
        cout<<"______________________"<<endl;
        cout<<"Enter your choose: "; cin >> key; cout<<endl;
        choose_temp = 1;
        choose_temp_case2 = 1;
        choose_temp_case3 = 2;

        switch (key)
        {
        case 1:
            do
            {
                if(choose_temp == 0) break;
                while (1)
                {
                    cout<<"Enter customer order number: "; cin >> stt_Var;
                    cout<<endl;
                    if (stt_Var < 1 && stt_Var > (int)(manage_Client->get_dataClient().size()))
                    {
                        cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    }else break;
                }
                cout<<"1 .Change name."<<endl;
                cout<<"2 .Change phone number."<<endl;
                cout<<"3 .Change address."<<endl;
                cout<<"0 .Back."<<endl;
                cout<<"______________________"<<endl;
                cout<<"Enter your choose: "; cin >> opt;
                switch (opt)
                {
                case 1:
                    cout<<"______________________"<<endl;
                    cout<<"Enter new name: "; cin.ignore(); getline(cin,name_Var);
                    manage_Client->adjust_nameClient(name_Var,stt_Var);
                    cout<<"Changing completely!!!"<<endl;
                    break;
                case 2:
                    cout<<"______________________"<<endl;
                    while (1)
                    {
                        cout<<"Enter new phone number: "; cin >> phone_Var;
                        if (Numof_Digits(phone_Var) == 9) break;
                        else cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    } 
                    manage_Client->adjust_phoneClient(phone_Var,stt_Var);
                    cout<<"Changing completely!!!"<<endl;
                    break;
                case 3:
                    cout<<"______________________"<<endl;
                    cout<<"Enter new address: "; cin.ignore(); getline(cin,address_Var);
                    manage_Client->adjust_addressClient(address_Var,stt_Var);
                    cout<<"Changing completely!!!"<<endl;
                    break;
                case 0:
                    break;
                default:
                    cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    system("pause");
                    break;
                }
                if (opt == 0) break;
                do
                {
                    if(opt > 3) break;
                    cout<<"1. Continue changing."<<endl<<"0. Back."<<endl;
                    choose_temp = enter_Choose();    
                } while (choose_temp > 1);
            } while (opt > 3);
            break;
        case 2:
            if(choose_temp_case3 == 0) break;
            while (1)
            {
                cout<<"______________________"<<endl;
                while (1)
                {
                    cout<<"Enter customer order number: "; cin >> stt_Var;
                    cout<<endl;
                    if (stt_Var < 1 && stt_Var >(int)(manage_Client->get_dataClient().size()))
                    {
                        cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    }else break;
                }
                print_titleClient();
                print_InfoClient(manage_Client->get_dataClient()[stt_Var-1]);
                do
                {
                    cout<<endl<<"Are you sure you want to delete??? "<<endl;
                    cout<<"1. Yes."<<endl<<"0. No"<<endl;
                    choose_temp_case2 = enter_Choose();
                } while (choose_temp_case2 > 1);
                if (choose_temp_case2 == 0) break;
                manage_Client->remove_Client(stt_Var,listof_Room);
                cout<<"Processing....."<<endl;
                cout<<"Delete completely!!!"<<endl;
                do
                {
                    cout<<"1. Continue changing."<<endl<<"0. Back."<<endl;
                    choose_temp = enter_Choose();    
                } while (choose_temp > 1);
                break;
            }
            break;   
        case 0:
            return;
        default:
            cout<<"Syntax error.Please pre-enter!!!"<<endl;
            system("pause");
            break;
        }
    }
        
}