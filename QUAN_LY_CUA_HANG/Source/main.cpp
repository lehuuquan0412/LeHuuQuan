#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

#include "type_data_Restaurant.h"
#include "Manager_Restaurant_function.h"
#include "Staff_Restaurant_function.h"

int main(int argc, char const *argv[])
{
    Dishes dish1("com ga",50000);
    Dishes dish2("coca",12000);
    Dishes dish3("com chien duong chau",25000);
    vector<Dishes> menu;
    menu.push_back(dish1);
    menu.push_back(dish2);
    menu.push_back(dish3);
    vector<Table> listofTable;
    int key;
    
    while (1)
    {
        system("cls");
        cout<<"_______ABC RESTAURANT_______"<<endl<<endl;
        cout<<"1.MANAGER."<<endl;
        cout<<"2.STAFF."<<endl;
        cout<<"0.EXIT."<<endl<<endl;
        cout<<"Enter your position: ";
        cin >> key;

        switch (key)
        {
        case 1:
            Manager_function_restaurant(listofTable, menu);
            break;
        case 2:
            cout<<"Checking table today..."<<endl<<endl;
            if (listofTable.empty())
            {
                cout<<"No tables added today!!!"<<endl;
                system("pause");
                break;
            }else{
                Staff_function_restaurant(listofTable, menu);
                break;
            }
        case 0:
            return 0;
        default:
            cout<<"SYNTAX ERROR.PLEASE PRE ENTER!!!"<<endl;
            system("pause");
            break;
        }
    } 
}
