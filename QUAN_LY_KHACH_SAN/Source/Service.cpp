/*
* File: Service.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện quản lý dịch vụ khách sách.
*/
#include "Service.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Service
* Description: Hàm thực hiện chức năng quản lý dịch vụ khách sạn.
* Input:
*   Service: vector danh sách quản lý dịch vụ khách sạn.
* Output:
*   Cho phép thêm cách dịch vụ khách sạn, thay đổi thông tin của dịch vụ.
*/
void Service_facility(vector<Services> & Service){
    int key;
    int opt;
    string name_Var;
    while (1)
    {
        system("cls");
        cout<<"====SERVICES AND FACILITIES===="<<endl<<endl;
        cout<<"Name    ";
        for (auto x: Service)
        {
            cout<<x.get_Name_Service();
            printSpace(10-x.get_Name_Service().length());
        }
        cout<<endl<<"Status  ";
        for (auto x: Service)
        {
            cout<<x.get_Status_Service();
            printSpace(10-x.get_Status_Service().length());
        }
        cout<<endl<<endl;
        cout<<"1. Add service."<<endl;
        cout<<"2. Change status of service."<<endl;
        cout<<"3. Delete service."<<endl;
        cout<<"0. Back."<<endl;
        cout<<"______________________"<<endl;
        do
        {
            cout<<"Enter your choose: "; cin >> key;
            switch (key)
            {
            case 1:{
                cout<<"Enter name of service: "; cin.ignore(); getline(cin,name_Var);
                Services temp_Service(name_Var,true);
                Service.push_back(temp_Service);
                cout<<"Add completely!!!"<<endl;
                break;
            }
            case 2:{
                cout<<"Enter name of service: "; cin.ignore(); getline(cin,name_Var);
                opt = 0;
                do
                {
                    if (name_Var == Service[opt].get_Name_Service())
                    {
                        if (Service[opt].get_Status_Service() == "O")
                        {
                            Service[opt].set_status_Service(true); 
                        }else Service[opt].set_status_Service(false);
                        
                        cout<<"Changing complete!!!"<<endl;
                        break;
                    }
                    opt++;
                } while (opt < (int)(Service.size()));
                if (opt == (int)(Service.size()))
                {
                    cout<<"Does not exist service!!!"<<endl;
                }
            }
                break;
            case 3:{
                cout<<"Enter name of service: "; cin.ignore(); getline(cin,name_Var);
                opt = 0;
                do
                {
                    if (name_Var == Service[opt].get_Name_Service())
                    {
                        Service.erase(Service.begin()+opt);
                        cout<<"Delete completely!!!"<<endl;
                        break;
                    }
                    opt++;
                } while (opt < (int)(Service.size()));
                if (opt == (int)(Service.size()))
                {
                    cout<<"Does not exist service!!!"<<endl;
                }
            }
                break;
            default:{
                return;}
            }
        }while(key > 3);
    }
}