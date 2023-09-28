
#ifndef __FUNCTION_Res
#define __FUNCTION_Res

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

#include "type_data_Restaurant.h"

using namespace std;
int Numof_Digits(int a);

// function of manager.

void setQuantityTable(vector<Table> & listofTable);

void addDishes(vector<Dishes> & menu);

void deleteDishes(vector<Dishes> & menu);

void changeNameofDish(vector<Dishes> & menu,int stt);

void changePriceofDish(vector<Dishes> & menu,int stt);

// function of staff.

void OrderTable(int numofTab,vector<Table> & listofTable,vector<Dishes> & menu,int Id);

void deleteOrder(int numofTab,vector<Table> & listofTable);

void changeQuantityofDish(int numofTab,vector<Table> & listofTable);

int purchaseTable(int numofTab,vector<Table> & listofTable);

//

void printSpace(int a);

//In các phần tử trong class dishes.
void printEleofDishes(Dishes dish);
//In tiêu đề của class dish.
void printTittleofDish();
//In menu của cửa hàng.
void printMenu(vector<Dishes> & menu);
//In các phần tử trong mỗi đơn gọi món.
void printEleofOrder(Order order);
//In tiêu đề của các đơn đặt hàng.
void printTittleofOrder(int numof_Tab);
//In đơn gọi món.
void printOrder(vector<Order> & table,int numof_Tab);
//In danh sách bàn.
void printTable(vector<Table> & listTable);
//Nhập một giá trị bất kỳ từ bàn phím.
int enter_choose();


#endif