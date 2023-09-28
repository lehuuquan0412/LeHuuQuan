/*
* File: Manager_Res_func.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm chức năng của quản lý trong quản lý cửa hàng.
*/
#include "type_data_Restaurant.h"
#include "Function_Add_Restaurant.h"
#include "Manager_Restaurant_function.h"


/*
* Function: Manager_function_restaurant
* Description: Mô phỏng chức năng của quản lý với quản lý nhà hàng.
* Input:
*   listofTable: danh sách các bàn ăn tồn tại trong ngày.
*   menu: menu của nhà hàng.
* Output:
*   Cho phép quản lý được thức hiện các chức năng như chỉnh sửa menu, chỉnh sửa số lượng bàn.
*/
void Manager_function_restaurant(vector<Table> & listofTable, vector<Dishes> & menu){
    int key;
    int key1;
    int opt;
    int choose;
    int id_var;
    ////
    while (1)
    {
        system("cls");
        cout<<"MANAGER"<<endl;
        cout<<"_________________________"<<endl<<endl;
        cout<<"  1: TABLE OF TODAY."<<endl;
        cout<<"  2: ADD DISHES."<<endl;
        cout<<"  3: CHANGE INFORMATION."<<endl;
        cout<<"  4: DELETE DISHES."<<endl;
        cout<<"  5: MENU."<<endl;
        cout<<"  0: BACK."<<endl<<endl;
        cout<<"_________________________"<<endl<<endl;
        cout<<"Nhap su lua chon: "; cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout<<"  1: Add all table today."<<endl<<endl;
            cout<<"_________________________"<<endl<<endl;
            setQuantityTable(listofTable);
            cout<<"_________________________"<<endl<<endl;
            system("pause");
            break;
        case 2:
            while (1)
            {
                system("cls");
                int n;
                cout<<"  2: Add dishes to menu."<<endl<<endl;
                cout<<"_________________________"<<endl<<endl;
                addDishes(menu);
                cout<<endl<<"__Successful add__"<<endl;
                cout<<"_________________________"<<endl<<endl;
                printMenu(menu);
                do
                {
                    cout<<"_________________________"<<endl<<endl;
                    cout<<"  1. Continue add dishes."<<endl;
                    cout<<"  0. Back."<<endl;
                    cout<<"_________________________"<<endl<<endl;
                    cout<<"Enter your choose: "; cin >> key1;
                } while (key1 > 1);
                if (key1 == 0) break;    
            }
            break;
        case 3:
            while (1)
            {
                system("cls");
                cout<<" 3.Change information of dishes."<<endl<<endl;
                printMenu(menu);
                cout<<"_________________________"<<endl<<endl;
                cout<<"Enter Id of dish: "; cin >> id_var;
                choose = 0;
                for (Dishes x:menu)
                {
                    if (x.getId() == id_var)
                    {
                        while (1)
                        {
                            choose = 1;
                            cout<<endl<<"1.Change the name."<<endl;
                            cout<<"2.Change the price."<<endl;
                            cout<<"0.Back."<<endl;
                            cout<<"_________________________"<<endl<<endl;
                            cout<<"Enter your choose: "; cin >> opt;
                            switch (opt)
                            {
                            case 1:
                                changeNameofDish(menu,id_var);
                                printMenu(menu);
                                break;
                            case 2:
                                changePriceofDish(menu,id_var);
                                printMenu(menu);
                                break;
                            case 0:
                                break;
                            default:
                                cout<<"Input error. Please re-enter!!!"<<endl;
                                break;
                            }
                            if (opt == 0) break;
                        }
                        break;
                    }  
                }
                if (opt == 0) break;
                if (choose == 1){
                    cout<<"Id error.Please pre-enter Id!!!"<<endl;
                    system("pause");
                }
            }
            break;
        case 4:
            while (1)
            {
                system("cls");
                cout<<" 4.Delete dishes of menu."<<endl<<endl;
                printMenu(menu);
                cout<<"_________________________"<<endl<<endl;
                cout<<"Enter Id of dish: "; cin >> id_var;
                choose = 0;
                for (Dishes x:menu)
                {
                    if (x.getId() == id_var)
                    {
                        choose = 1;
                        while (1)
                        {
                            cout<<"_________________________"<<endl<<endl;
                            cout<<"1.Delete dish."<<endl;
                            cout<<"0.Back."<<endl;
                            cout<<"_________________________"<<endl<<endl;
                            cout<<"Enter your choose: "; cin >> key1;
                            cout<<endl;
                            if (key1 == 1)
                            {
                                cout<<"Delete complete!!!"<<endl<<endl;
                                cout<<"Information of deleted dish:"<<endl<<endl;
                                for (int i = 0; i < menu.size(); i++)
                                {
                                    if (menu[i].getId() == id_var)
                                    {
                                        printTittleofDish();
                                        cout<<(i+1);
                                        printSpace(5-Numof_Digits(i+1));
                                        printEleofDishes(menu[i]);
                                        menu.erase(menu.begin()+i);
                                        break;
                                    }   
                                }
                                do
                                {
                                    cout<<endl<<"1 .Continue delete."<<endl<<"0. Back"<<endl;
                                    opt = enter_choose();
                                } while (opt > 1);
                                break;
                            }else if (key1 = 0) {
                                do
                                {
                                    cout<<endl<<"1 .Continue delete."<<endl<<"0. Back"<<endl;
                                    opt = enter_choose();
                                } while (opt > 1);
                                break;
                            }
                            else cout<<"Syntax error. Please pre-enter!!!"<<endl;
                        }
                        break;  
                    }
                }
                if (choose == 0) cout<<"Id error.Please pre-enter Id!!!"<<endl;
                else{
                    if (opt == 0)
                    {
                        break;
                    } 
                }
            }
            break;
            
        case 5:
            system("cls");
            cout<<" 5.Menu today"<<endl<<endl;
            printMenu(menu);
            system("pause");
            break;
        case 0:
            break;
        default:
            cout<<"Choose incorrectly.Please pre-enter!!!"<<endl;
            system("pause");
            cout<<endl;
            break;
        }
        if(key == 0) return;
    }
}