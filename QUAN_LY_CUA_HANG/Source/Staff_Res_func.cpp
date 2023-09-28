/*
* File: Staff_Res_func.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm chức năng của nhân viên trong quản lý cửa hàng.
*/
#include "type_data_Restaurant.h"
#include "Function_Add_Restaurant.h"
#include "Staff_Restaurant_function.h"

/*
* Function: Staff_function_restaurant
* Description: Mô phỏng chức năng của nhân viên với quản lý nhà hàng.
* Input:
*   listofTable: danh sách các bàn ăn tồn tại trong ngày.
*   menu: menu của nhà hàng.
* Output:
*   Cho phép quản lý được thức hiện các chức năng như chỉnh sửa đơn đặt món, thanh toán.
*/
void Staff_function_restaurant(vector<Table> & listofTable, vector<Dishes> & menu){
    while (1)
    {
        system("cls");
        int number_ofTable;
        int key;
        int key1;
        int opt;
        int choose;
        int id_var;
        
        while (1)
        {
            cout<<"STAFF"<<endl;
            cout<<"_________________________"<<endl<<endl;
            printTable(listofTable);
            cout<<endl<<"Enter the table number: "; cin >> number_ofTable;
            choose = 0;
            for (Table x:listofTable)
            {  
                if (x.getNumTale() == number_ofTable)
                {
                    while (1)
                    {
                        choose = 1;
                        cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                        cout<<"  1: ORDER."<<endl;
                        cout<<"  2: ADJUST DISHES."<<endl;
                        cout<<"  3: REMOVE DISHES."<<endl;
                        cout<<"  4: ORDER LIST."<<endl;
                        cout<<"  5: RECEIPT."<<endl;
                        cout<<"  0: BACK."<<endl<<endl;
                        cout<<"_________________________"<<endl;
                        cout<<"Enter your option: "; cin >> key;
                        switch (key)
                        {
                        case 1:
                            while (1)
                            {
                                system("cls");
                                cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                                cout<<"  1: ORDER."<<endl<<endl;
                                printMenu(menu);
                                cout<<"Enter a Id of dish: "; cin >> id_var;
                                opt = 0;
                                for (Dishes x: menu)
                                {
                                    if (x.getId() == id_var)
                                    {
                                        opt = 1;
                                        OrderTable(number_ofTable,listofTable,menu,id_var);
                                        cout<<"_________________________"<<endl<<endl;
                                        listofTable[number_ofTable-1].setStatus(FULL);
                                        printOrder(listofTable[number_ofTable-1].getdataOrder(),number_ofTable);
                                        break;
                                    }  
                                }
                                if (opt == 0) cout<<"Incorrect ID!!!"<<endl;
                                do
                                {
                                    cout<<endl<<"1. Continue."<<endl<<"0. Back."<<endl;
                                    key1 = enter_choose();
                                } while (key1 > 1);
                                if(key1 == 0) break; 
                            }
                            break;
                        case 2:
                            while (1)
                            {
                                system("cls");
                                cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                                cout<<"  2: ADJUST DISHES."<<endl<<endl;
                                if (listofTable[number_ofTable-1].getdataOrder().empty())
                                {
                                    cout<<endl<<"Empty table. Please order!!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                printOrder(listofTable[number_ofTable-1].getdataOrder(),number_ofTable);
                                changeQuantityofDish(number_ofTable,listofTable);
                                do
                                {
                                    cout<<"1. Continue."<<endl<<"0. Back"<<endl;
                                    opt = enter_choose();
                                } while (opt > 1);
                                if (opt == 0) break;
                            }
                            break;

                        case 3:
                            while (1)
                            {
                                system("cls");
                                cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                                cout<<"  3: REMOVE DISHES."<<endl<<endl;
                                if (listofTable[number_ofTable-1].getdataOrder().empty())
                                {
                                    cout<<endl<<"Empty table. Please order!!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                printOrder(listofTable[number_ofTable-1].getdataOrder(),number_ofTable);
                                deleteOrder(number_ofTable,listofTable);    
                                int optDelete;
                                do
                                {
                                    cout<<"1. Continue."<<endl<<"0. Back"<<endl;
                                    opt = enter_choose();
                                } while (opt > 1);
                                if (opt == 0) break;
                            }
                            break;
                            
                        case 4:
                            system("cls");
                            cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                            cout<<"  4.ORDER LIST."<<endl<<endl;
                            if (listofTable[number_ofTable-1].getdataOrder().empty())
                            {
                                cout<<endl<<"Empty table. Please order!!!"<<endl;
                                system("pause");
                                break;
                            }
                            printOrder(listofTable[number_ofTable-1].getdataOrder(),number_ofTable);
                            system("pause");
                            break;
                        case 5:
                            while (1)
                            {
                                system("cls");
                                cout<<"__TABLE "<<number_ofTable<<"__"<<endl<<endl;
                                cout<<"  5.RECEIPT."<<endl<<endl;
                                if (listofTable[number_ofTable-1].getdataOrder().empty())
                                {
                                    cout<<endl<<"Empty table.Unable to export receipt!!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                printOrder(listofTable[number_ofTable-1].getdataOrder(),number_ofTable);
                                cout<<"_________________________"<<endl;
                                cout<<"TOTAL: "<<purchaseTable(number_ofTable,listofTable)<<endl<<endl;
                                
                                do
                                {
                                    cout<<"1. Purchase."<<endl<<"0. Back. "<<endl;
                                    opt == enter_choose();
                                } while (opt > 1);

                                if(opt == 1){
                                    listofTable[number_ofTable-1].getdataOrder().clear();
                                    listofTable[number_ofTable-1].setStatus(EMPTY);
                                    cout<<"......."<<endl;
                                    cout<<"PURCHASE SUCCESSFUL!!!"<<endl<<"THANK YOU VERY MUCH!!!"<<endl;
                                    system("pause");
                                    break;
                                }else break;
                            }
                            break;
                            
                        case 0:
                            break;
                        default:
                            cout<<"Syntax error. Please re-enter!!!"<<endl;
                            system("pause");
                            break;

                        }
                        if (key == 0) break;
                    }
                    
                }
            }
            if (choose == 0){
                cout<<"Wrong table number. Please re-enter!!!"<<endl;
                system("pause");
            }else return;
            
        }
    }
}