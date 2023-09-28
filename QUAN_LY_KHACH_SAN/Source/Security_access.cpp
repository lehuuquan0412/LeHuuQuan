/*
* File: Security_access.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện quản lý quyền truy cập.
*/

#include "Security_access.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Booking_room
* Description: Hàm thực hiện chức năng đặt phòng.
* Input:
*   listof_Staff: danh sách nhân viên.
*   Sec_Manage_hotel: biến quản lý quyền truy cập.
* Output:
*   Thực hiện quản lý quyền truy cập đối với quản trị viên và nhân viên.
*   Quản trị viên:
*       + Cho phép chỉnh sửa thông tin đăng nhập của quản trị viên.
*       + Cấp quyền truy cập cho nhân viên.
*       + Chỉnh sửa hoặc xóa thông tin đăng nhập của nhân viên.
*   Nhân viên: Cho phép thay đổi thông tin đăng nhập.
*/
void Security_access(SecureManagement*Sec_Manage_hotel, vector<Staff> & listof_Staff){
    int key;
    int id_Var;
    int key1;
    int key2;
    int opt;
    int choose;
    string usernames_var;
    string password_var;
    string new_pass1;
    string new_pass2;
    
    while (1)
    {
        system("cls");
        cout<<"====SECURITY AND ACCESS===="<<endl<<endl;
        cout<<"1. Administered."<<endl;
        cout<<"2. EMPLOYEE RIGHTS."<<endl;
        cout<<"0. Back."<<endl;
        cout<<"______________________"<<endl;
        
        do
        {
            cout<<"Enter your option: "; cin >> key;
            if (key == 0)
            {
                return;
            }   
        } while (key > 2);
        
        if (key == 1)
        {
            system("cls");
            cout<<"# ADMIN #"<<endl<<endl;
            //Thực hiện đăng nhập của quản trị viên.
            //Username: admin.
            //Pass: lehuuquan.
            while (1)
            {
                cout<<"Enter username: "; cin >> usernames_var;
                cout<<"Password: "; cin >> password_var;
                if (Sec_Manage_hotel->get_Check_Signup_Admin(usernames_var,password_var)) break;
                else cout<<"User account or password incorrect. Please re-enter!!!"<<endl<<endl;  
            }
            cout<<"Sign in completely!!!"<<endl<<endl;
            system("pause");
            
            while (1)
            {
                system("cls");
                cout<<"# ADMIN #"<<endl<<endl;
                cout<<"1. Edit user."<<endl;
                cout<<"2. Change admin password."<<endl;
                cout<<"0. Back."<<endl;
                cout<<"______________________"<<endl;
                cout<<"Enter your choose: "; cin >> key1;
                switch (key1)
                {
                case 1:
                    while (1)
                    {
                        cout<<"1. Add users."<<endl;
                        cout<<"2. Change users password."<<endl;
                        cout<<"3. Remove users."<<endl;
                        cout<<"4. List of users,"<<endl;
                        cout<<"0. Back."<<endl;
                        cout<<"______________________"<<endl;
                        cout<<"Enter your choose: "; cin >> key2;
                        switch (key2)
                        {
                        case 1:
                            while (1)
                            {
                                system("cls");
                                cout<<"1. Add users."<<endl;
                                if (listof_Staff.empty())
                                {
                                    cout<<"No staff at here!!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                
                                cout<<"Enter id of staff: "; cin >> id_Var;
                                for (auto x: listof_Staff)
                                {
                                    if (x.get_id_Staff() == id_Var)
                                    {
                                        cout<<"Enter username: "; cin >> usernames_var;                                            cout<<"Enter password: "; cin >> password_var;
                                        User user_temp(usernames_var,password_var);
                                        Sec_Manage_hotel->add_User(id_Var,usernames_var,password_var);
                                        cout<<"Create account completely!!!"<<endl;
                                        do
                                        {
                                            cout<<"1. Continued add."<<endl<<"0. Back."<<endl;
                                            choose = enter_Choose();
                                        } while (choose > 1);
                                        break;
                                    }
                                }
                                if (choose == 0) break;
                                if (choose > 1) cout<<"Incorrect Id of staff.Please pre-enter!!!"<<endl;   
                            }
                            break;
                        case 2:
                            while (1)
                            {
                                system("cls");
                                cout<<"2. Change users password."<<endl;
                                print_List_User(Sec_Manage_hotel->get_database_User(), listof_Staff);
                                if (empty_User_staff(*Sec_Manage_hotel))
                                {
                                    system("pause");
                                    break;
                                }
                        
                                cout<<"Enter username: "; cin >> usernames_var;
                                for (int i = 0; i < (int)(Sec_Manage_hotel->get_database_User().size()); i++)
                                {
                                    if (Sec_Manage_hotel->get_database_User()[i].get_Username() == usernames_var)
                                    {
                                        while (1)
                                        {
                                            cout<<"Enter new password: "; cin >> new_pass1;
                                            cout<<"Retype password: "; cin >> new_pass2;
                                            if (new_pass1 == new_pass2)
                                            {
                                                Sec_Manage_hotel->change_Password_User(usernames_var,new_pass1);
                                                cout<<"Change completely!!!"<<endl<<endl;
                                                do
                                                {
                                                    cout<<"1. Continued add."<<endl<<"0. Back."<<endl;
                                                    choose = enter_Choose();
                                                } while (choose > 1);
                                                break;
                                            }else cout<<"Password incorrect.Please pre-enter!!!"<<endl; 
                                        }
                                        break;              
                                    }
                                }
                                if(choose == 0) break;
                                if(choose > 1) cout<<"Incorrect username.Please pre-enter!!!"<<endl;
                            }
                            break;
                                
                        case 3:
                            while (1)
                            {
                                system("cls");
                                cout<<"3. Remove users."<<endl;
                                print_List_User(Sec_Manage_hotel->get_database_User(),listof_Staff);
                                if (Sec_Manage_hotel->get_database_User().empty())
                                {
                                    system("pause");
                                    break;
                                }
                                cout<<"Enter user id: "; cin >> id_Var;
                                for (int i = 0; i <(int)(Sec_Manage_hotel->get_database_User().size()); i++)
                                {
                                    if (Sec_Manage_hotel->get_database_User()[i].get_Id_User() == id_Var)
                                    {
                                        Sec_Manage_hotel->remove_User(id_Var);
                                        cout<<"Delete completely!!!"<<endl;
                                            
                                        do
                                        {
                                            cout<<"1. Continued add."<<endl<<"0. Back."<<endl;
                                            choose = enter_Choose();
                                        } while (choose > 1);
                                        break;                
                                    }
                                }
                                if (choose == 0) break;
                                if (choose > 1) cout<<"Incorrect username.Please pre-enter!!!"<<endl;
                            }
                            break;
                                
                        case 4:
                            print_List_User(Sec_Manage_hotel->get_database_User(), listof_Staff);
                            system("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"Syntax error.Please pre-enter!!!"<<endl;
                            system("pause");
                            break;
                        }
                        if (key2 == 0) break; 
                    }
                    break;
                    
                case 2:
                    while (1)
                    {
                        cout<<"Enter new password: "; cin >> new_pass1;
                        cout<<"Retype password: "; cin >> new_pass2;
                        if (new_pass1 == new_pass2)
                        {
                            cout<<"Change completely!!!"<<endl<<endl;
                            Sec_Manage_hotel->edit_Pass_Addmin(new_pass1);
                            break;
                        }else cout<<"Password incorrect.Please pre-enter!!!"<<endl; 
                    }
                    break;
                case 0:
                    break;
                default:
                    cout<<"Syntax error.Please pre-enter!!!"<<endl;
                    break;
                }
                if (key1 == 0) break;
            }     
        }else if (key == 2)
        {
            // Kiểm tra danh sách các user được cấp quyền.
            // Nếu không tồn tại thì phản hồi và thoát.
            if (Sec_Manage_hotel->get_database_User().empty())
            {
                cout<<"No user at here!!!"<<endl;
                system("pause");
            }else{
                system("cls");
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
                system("pause");
                while (1)
                {
                    cout<<"# STAFF #"<<endl<<endl;
                    for (auto x: Sec_Manage_hotel->get_database_User())
                    {
                        if (x.get_Username() == usernames_var)
                        {
                            print_Tittle_User();
                            cout<<endl;
                            print_Ele_User(x,listof_Staff);
                            cout<<endl;
                            break;
                        }
                    }
                    cout<<"1. Change the password."<<endl;
                    cout<<"0. Back."<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Enter your choose: "; cin >> key1;
                    if (key1 == 1)
                    {
                        while (1)
                        {
                            cout<<"Enter new password: "; cin >> new_pass1;
                            cout<<"Retype password: "; cin >> new_pass2;
                            if (new_pass1 == new_pass2)
                            {
                                Sec_Manage_hotel->change_Password_User(usernames_var,new_pass1);
                                cout<<"Change completely!!!"<<endl<<endl;
                                break;
                            }else cout<<"Password incorrect.Please pre-enter!!!"<<endl; 
                        }
                    }else if (key1 == 0)
                    {
                        break;
                    }else cout<<"Syntax error.Please pre-enter!!!"<<endl; 
                }   
            } 
        }    
    } 
}