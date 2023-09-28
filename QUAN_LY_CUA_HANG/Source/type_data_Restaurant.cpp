#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "type_data_Restaurant.h"

//Dishes.
Dishes::Dishes(string name,int price){
    this->Id = IdMenu;
    this->dishNAME = name;
    this->PRICE = price;
    IdMenu++;
};

void Dishes::setName(string name){
    this->dishNAME = name;
};

void Dishes::setPrice(int price){
    this->PRICE = price;
};

void Dishes::setId(int ID){
    this->Id = ID;
};

string Dishes::getName(){
    return this->dishNAME;
}

int Dishes::getPrice(){
    return this->PRICE;
}

int Dishes::getId(){
    return this->Id;
}

//Order.
Order::Order(string Name,int Price,int quan):Dishes(Name,Price){
    this->Quantity = quan;
};

void Order::setQuantity(int quan){
    this->Quantity = quan;
};

int Order::getQuantity(){
    return this->Quantity;
}

//Table.

Table::Table(int table){
    this->NumTable = table;
    this->status = EMPTY;
};

void Table::setNumTable(int num){
    NumTable = num;
};

void Table::setStatus(statusTable Status){
    status = Status;
};


void Table::setdataOrder(int num,int quan,vector<Dishes> & menu){
    for (int i = 0; i < menu.size(); i++)
    {
        if(menu[i].getId() == num)
        {
            Order dish1(menu[i].getName(),menu[i].getPrice(),quan);
            dish1.setId(menu[i].getId());
            IdMenu--;
            this->dataOrder.push_back(dish1);
        }
    }  
};

int Table::getNumTale(){
    return this->NumTable;
}

statusTable Table::getstatus(){
    return this->status;
}

vector<Order> & Table::getdataOrder(){
    return this->dataOrder;
}
