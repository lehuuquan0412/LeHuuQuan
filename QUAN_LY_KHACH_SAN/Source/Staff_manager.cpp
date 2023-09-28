/*
* File: Staff_manager.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện quản lý thông tin nhân viên.
*/
#include "Staff_manager.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Staff_manager
* Description: Hàm thực hiện chức năng quản lý thông tin nhân viên.
* Input:
*   listof_Staff: danh sách nhân viên.
*   Sec_Manage_hotel: biến quản lý quyền truy cập.
* Output:
*   Mô phỏng các chức năng như quản lý thông tin nhân viên như tên, số điện thoại, id, ca làm việc.
*/
void Staff_manager(SecureManagement*Sec_Manage_hotel, vector<Staff> & listof_Staff){
    int key;
    int key1;
    int opt;
    int id_Var;
    int choose;
    string name_Var;
    int phone_Var;
    string usernames_var;
    string password_var;
    string new_pass1;
    string new_pass2;
    int position_var;
    JobPosition position_temp;
    Times time_temp_On;
    Times time_temp_Off;
    Status status_temp;


    while (1)
    {
        system("cls");
        cout<<"====STAFF MANAGEMENT===="<<endl<<endl;
        cout<<"1. Administered."<<endl;
        cout<<"2. EMPLOYEE RIGHTS."<<endl;
        cout<<"0. Back."<<endl;
        cout<<"______________________"<<endl;
        
        do
        {
            cout<<"Enter your option: "; cin >> key;
            if (key == 0) return; 
        } while (key > 2);

        if (key == 1)
        {
            system("cls");
            cout<<"# ADMIN #"<<endl<<endl;
            while (1)
            {
                cout<<"Enter username: "; cin >> usernames_var;
                cout<<"Password: "; cin >> password_var;
                if (Sec_Manage_hotel->get_Check_Signup_Admin(usernames_var,password_var)) break;
                else cout<<"User account or password incorrect. Please re-enter!!!"<<endl<<endl;  
            }
            cout<<"Log in completely!!!"<<endl<<endl;
            system("pause");
            while (1)
            {
                cout<<endl<<"1. Edit staff information."<<endl;
                cout<<"2. Remove staff."<<endl;
                cout<<"3. Add staff."<<endl;
                cout<<"4. List of staff."<<endl;
                cout<<"0. Back."<<endl;
                cout<<"______________________"<<endl;
                cout<<"Enter your option: "; cin >> key1; cout<<endl;
                switch (key1)
                {
                case 1:
                    while (1)
                    {
                        system("cls");
                        cout<<"# EDIT STAFF INFORMATION #"<<endl<<endl;
                        print_List_Staff(listof_Staff);
                        if (listof_Staff.empty())
                        {
                            system("pause");
                            break;
                        }

                        opt = 0;
                        while (1)
                        {
                            cout<<"Enter id of staff: "; cin >> id_Var;
                            for (int i = 0; i < listof_Staff.size(); i++)
                            {
                                if (listof_Staff[i].get_id_Staff() == id_Var )
                                {
                                    opt = 1;
                                    break;
                                }   
                            }
                            if (opt == 1)
                            {
                                break;
                            }else cout<<"Wrong ID. Please pre-enter!!!"<<endl;      
                        }
                        do
                        {
                            cout<<"1. Name."<<endl;
                            cout<<"2. Phone number."<<endl;
                            cout<<"3. Position."<<endl;
                            cout<<"4. Shitf"<<endl;
                            cout<<"0. Back."<<endl;
                            cout<<"______________________"<<endl;
                            cout<<"Enter your choose: "; cin >> opt;
                            switch (opt)
                            {
                            case 1:
                                cout<<"Enter new name: "; cin.ignore(); getline(cin, name_Var);
                                for (int i = 0; i < (int)(listof_Staff.size()); i++)
                                {
                                    if (listof_Staff[i].get_id_Staff() == id_Var)
                                    {
                                        listof_Staff[i].set_Name_Staff(name_Var);
                                        break;
                                    } 
                                }
                                break;
                            case 2:
                                cout<<"Enter new phone number: "; cin >> phone_Var;
                                for (int i = 0; i < (int)(listof_Staff.size()); i++)
                                {
                                    if (listof_Staff[i].get_id_Staff() == id_Var)
                                    {
                                        listof_Staff[i].set_phoneNumber_Staff(phone_Var);
                                        break;
                                    } 
                                }
                                break;
                            case 3:
                                for (int i = 0; i < (int)(listof_Staff.size()); i++)
                                {
                                    if (listof_Staff[i].get_id_Staff() == id_Var)
                                    {
                                        listof_Staff[i].set_Job_Position(enter_Position(position_var));
                                        break;
                                    } 
                                }
                                break;

                            case 4:
                                choose = 0;
                                do
                                {
                                    cout<<"1. Change time on."<<endl;
                                    cout<<"2. Change time off."<<endl;
                                    cout<<"Enter your choose: "; cin >> choose;
                                } while (choose != 1 && choose != 2);
                                if (choose == 1)
                                {
                                    cout<<"Change time on:"<<endl<<endl;
                                    for (int i = 0; i < (int)(listof_Staff.size()); i++)
                                    {
                                        if (listof_Staff[i].get_id_Staff() == id_Var)
                                        {
                                            Times temp;
                                            listof_Staff[i].set_time_On(enter_Schedule_times(temp));
                                            break;
                                        } 
                                    }
                                }else{
                                    cout<<"Change time of:"<<endl<<endl;
                                    for (int i = 0; i < (int)(listof_Staff.size()); i++)
                                    {
                                        if (listof_Staff[i].get_id_Staff() == id_Var)
                                        {
                                            Times temp;
                                            listof_Staff[i].set_time_Off(enter_Schedule_times(temp));
                                            break;
                                        } 
                                    }
                                }
                                break;
                            
                            case 0:{
                                break;}
                            default:
                            {
                                cout<<"Syntax error.Please pre-enter!!!"<<endl;
                                system("cls");
                                break;
                            }
                            }
                        } while (opt > 4);
                        if(opt == 0) break;
                        
                        while (1)
                        {
                            cout<<"1. Continue changing."<<endl<<"0. Back."<<endl;
                            opt = enter_Choose();
                            if (opt <= 1)
                            {
                                break;
                            }  
                        }
                        if (opt == 0) break;
                    }
                    break;
                case 2:
                    while (1)
                    {
                        system("cls");
                        cout<<"# REMOVE STAFF #"<<endl<<endl;
                        print_List_Staff(listof_Staff);
                        if (listof_Staff.empty())
                        {
                            system("pause");
                            break;
                        }
                        cout<<"Enter id of staff: "; cin >> id_Var;
                        delete_Staff(id_Var,listof_Staff);
                        cout<<"Delete completely!!!"<<endl;
                        do
                        {
                            cout<<"1. Continued delete."<<endl<<"0. Back."<<endl;
                            choose = enter_Choose();
                        } while (choose > 1);
                        if(choose == 0) break;
                    }
                    break;
                case 3:{
                    while (1)
                    {
                        system("cls");
                        cout<<"# ADD STAFF #"<<endl<<endl;
                        cout<<"Enter name of staff: "; cin.ignore(); getline(cin,name_Var);
                        cout<<"Enter phone number of staff: "; cin.ignore(); cin >> phone_Var;
                        position_temp = enter_Position(position_var);
                        cout<<"Time on:"<<endl;
                        time_temp_On = enter_Schedule_times(time_temp_On);
                        cout<<"Time off:"<<endl;
                        time_temp_Off = enter_Schedule_times(time_temp_Off);
                        status_temp = enter_Schedule_status(status_temp);
                        
                        Staff staff_temp(name_Var, phone_Var, position_temp, time_temp_On, time_temp_Off, status_temp); 
                        listof_Staff.push_back(staff_temp);
                        cout<<"Add staff completely!!!"<<endl;
                        do
                        {
                            cout<<"1. Continued add."<<endl<<"0. Back."<<endl;
                            choose = enter_Choose();
                        } while (choose > 1);
                        if(choose == 0) break;
                    }  
                    }
                    break;
                
                case 4:
                    print_List_Staff(listof_Staff);
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    break;
                }
                if(key1 == 0) break;
            }
            
            
        }else{
            system("cls");
            if (Sec_Manage_hotel->get_database_User().empty())
            {
                cout<<"No user at here!!!"<<endl;
                system("pause");
            }else{
                while (1)
                {
                    cout<<"Enter username: "; cin >> usernames_var;
                    cout<<"Password: "; cin >> password_var;
                    if (log_in_Staff(usernames_var, password_var, *Sec_Manage_hotel))
                    {
                        break;
                    }else{
                        cout<<"Wrong account or password. Please log in again!!!"<<endl;
                    } 
                }
                
                for (int i = 0; i < Sec_Manage_hotel->get_database_User().size(); i++)
                {
                    if (usernames_var == Sec_Manage_hotel->get_database_User()[i].get_Username())
                    {
                        id_Var = Sec_Manage_hotel->get_database_User()[i].get_Id_User();
                        break;
                    } 
                }
                system("pause");
                    
                while (1)
                {
                    cout<<" # STAFF # "<<endl<<endl;
                    for (auto x: listof_Staff)
                    {
                        if (x.get_id_Staff() == id_Var)
                        {
                            print_Tittle_Staff(); cout << endl;
                            print_Ele_Staff(x);
                            cout<<endl;
                            break;
                        }
                    }
                    cout<<"1. Change name."<<endl;
                    cout<<"2. Change phone."<<endl;
                    cout<<"0. Back"<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Enter your option: "; cin >> opt;
                    switch (opt)
                    {
                    case 1:
                        cout<<"Enter new name: "; cin.ignore();  getline(cin, name_Var);
                        for (int i = 0; i < listof_Staff.size(); i++)
                        {
                            if (listof_Staff[i].get_id_Staff() == id_Var)
                            {
                                listof_Staff[i].set_Name_Staff(name_Var);
                                cout<<"Change completely!!!"<<endl;
                                break;
                            }     
                        }   
                        break;
                    case 2:
                        cout<<"Enter new phone number: "; cin >> phone_Var;
                        for (int i = 0; i < (int)(listof_Staff.size()); i++)
                        {
                            if (listof_Staff[i].get_id_Staff() == id_Var)
                            {
                                listof_Staff[i].set_phoneNumber_Staff(phone_Var);
                                cout<<"Change completely!!!"<<endl;
                                break;
                            }     
                        } 
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"Syntax error.Please pre-enter!!!"<<endl;
                        break;
                    }
                    if (opt == 0) break;
                }  
            }
        }
    }   
}