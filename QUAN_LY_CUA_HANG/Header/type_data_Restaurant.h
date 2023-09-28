#ifndef __DATA_Res
#define __DATA_Res

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

static int IdMenu = 100;

typedef enum{
    EMPTY = 0,
    FULL = 1
}statusTable;

class Dishes 
{
    protected:
        int Id;
        string dishNAME;
        int PRICE;
    public:
        Dishes(string name,int price);
        void setName(string name);
        void setPrice(int price);
        void setId(int ID);
        string getName();
        int getPrice();
        int getId();
};

class Order:public Dishes
{
    private:
        int Quantity;
    public:
        Order(string Name,int Price,int quan);
        void setQuantity(int quan);
        int getQuantity();
};

class Table
{
    private:
        vector<Order> dataOrder;
        int NumTable;
        statusTable status;
    public:
        Table(int table);
        void setNumTable(int num);
        void setStatus(statusTable Status);
        void setdataOrder(int num,int quan,vector<Dishes> & menu);
        int getNumTale();
        statusTable getstatus();
        vector<Order> & getdataOrder();
};

#endif