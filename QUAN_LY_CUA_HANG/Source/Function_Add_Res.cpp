/*
* File: Function_Add_Res.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm được thêm vào phục vụ thiết kế giao diện quản lý nhà hàng.
*/
#include "type_data_Restaurant.h"
#include "Function_Add_Restaurant.h"

/*
* Function: Numof_Digits
* Description: Tính toán số chữ số của 1 dãy số nguyên bất kỳ.
* Input:
*   a: dãy số nguyên cần tính số chữ số.
* Output:
*   Trả về số chữ số dưới kiểu dữ liệu int.
*/
int Numof_Digits(int a){
    int dem=0;
	while(a>=10){
		a/=10; 
		dem++;
	}
    return dem + 1;
}
/*
* Function: setQuantityTable
* Description: Là hàm đặt số lượng bàn có trong ngày.
* Input:
*   listofTable: danh sách bàn trong ngày.
* Output:
*   Cho phép nhập số lượng bàn vào, sau đó chương trình tạo ra số phần tử của vector listofTable đúng với số lượng nhập vào.
*/
void setQuantityTable(vector<Table> & listofTable){
    int quantity;
    cout<<"Enter the number of tables: ";
    cin >> quantity;
    listofTable.clear();
    for (int i = 0; i < quantity; i++)
    {
        Table x(i+1);
        listofTable.push_back(x);
    }
    //in thong tin bàn
    cout<<"Successful change!"<<endl<<endl;
}
/*
* Function: addDishes
* Description: Thêm món ăn vào menu.
* Input:
*   menu: danh sách món ăn của cửa hàng.
* Output:
*   Thêm món ăn mới vào menu với các thông tin ID, tên, giá.
*/
void addDishes(vector<Dishes> & menu){
    string name;
    cout<<"Enter a name of dish: ";
    cin.ignore();
    getline(cin,name);
    int price;
    cout<<"Enter prices of dish: ";
    cin>> price;
    Dishes dish(name,price);
    menu.push_back(dish);
}
/*
* Function: deleteDishes
* Description: Cho phép xóa 1 món ăn được chỉ định
* Input:
*   menu: danh sách món ăn của cửa hàng.
* Output:
*   Cho phép xóa toàn bộ thông tin món ăn thông qua ID.
*/
void deleteDishes(vector<Dishes> & menu){
    int stt;
    cout<<"Enter a ID of dish: ";
    cin >> stt;
    cout << endl;
    for (int i = 0;i < menu.size();i++)
    {
        if(menu[i].getId() == stt)
        {
            menu.erase(menu.begin()+i);
            cout<<"Delete completely!"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No dish found!"<<endl;
    system("pause");
}
/*
* Function: changeNameofDish
* Description: Cho phép sửa tên 1 món ăn được chỉ định
* Input:
*   menu: danh sách món ăn của cửa hàng.
*   stt: ID của món ăn cần sửa tên.
* Output:
*   Cho phép sửa tên món ăn thông qua ID.
*/
void changeNameofDish(vector<Dishes> & menu,int stt){
    string name;
    cout<<"Enter name of dish to change: ";
    cin.ignore();
    getline(cin,name);
    for (int i = 0; i<menu.size();i++)
    {
        if (menu[i].getId() == stt)
        {
            menu[i].setName(name);
            system("cls");
            cout<<"Successful change!"<<endl;
            cout<<"_________________________"<<endl<<endl;

            break;
        }  
    }
}
/*
* Function: changePriceofDish
* Description: Cho phép sửa giá 1 món ăn được chỉ định
* Input:
*   menu: danh sách món ăn của cửa hàng.
*   stt: ID của món ăn cần sửa.
* Output:
*   Cho phép sửa giá món ăn thông qua ID.
*/
void changePriceofDish(vector<Dishes> & menu,int stt){
    int price;
    cout<<"Enter price of dish to change: ";
    cin >> price;
    for (int i = 0; i < menu.size(); i++)
    {
        if (menu[i].getId() == stt)
        {
            menu[i].setPrice(price);
            system("cls");
            cout<<"Successful change!"<<endl;
            cout<<"_________________________"<<endl<<endl;
            break;
        }  
    }
}

//function of staff
/*
* Function: OrderTable
* Description: Cho phép thực hiện gọi món ở 1 bàn ăn bất kỳ.
* Input:
*   numofTab: số thứ tự của bàn.
*   listofTable: danh sách bàn ăn.
*   menu: danh sách món ăn.
*   Id: ID của món ăn.
* Output:
*   Thực hiện thêm món ăn với các thông tin trên menu và số lượng đã gọi vào danh sách order.
*   Nếu món đã tồn tại thì cộng thêm số lượng vào.
*/
void OrderTable(int numofTab,vector<Table> & listofTable,vector<Dishes> & menu,int Id){
    int quantity;//Số lượng cần gọi.
    //Kiểm tra danh sách order của bàn ăn.
    if (listofTable[numofTab-1].getdataOrder().empty())
    {
        goto order;
    }
    //Kiểm tra món ăn đã tồn tại trong bàn.
    for (int i = 0; i < listofTable.size(); i++)
    {
        if (listofTable[numofTab-1].getdataOrder()[i].getId() == Id)
        {
            cout<<"Dish is order in advance."<<endl;
            cout<<"Enter the quantity to add: ";
            cin >> quantity;

            listofTable[numofTab-1].getdataOrder()[i].setQuantity(listofTable[numofTab-1].getdataOrder()[i].getQuantity()+quantity);

            cout<<"The quantity of dish is increased!!!"<<endl;
            return;
        }  
    }
    order:
    cout<<"Enter quantity of dish: ";
    cin >> quantity;

    listofTable[numofTab-1].setdataOrder(Id,quantity,menu);
    cout<<"Successful ordering!!!"<<endl;
}

/*
* Function: deleteOrder
* Description: Xóa món ăn đã được gọi trong danh sách order.
* Input:
*   numofTab: số thứ tự của bàn.
*   listofTable: danh sách bàn ăn.
* Output:
*   Thực hiện xóa món ăn đã được gọi.
*/
void deleteOrder(int numofTab,vector<Table> & listofTable){
    int IdDish;
    cout<<"Enter a Id of dish: ";
    cin >> IdDish;
    for (int i = 0;i < listofTable[numofTab-1].getdataOrder().size();i++)
    {
        if (listofTable[numofTab-1].getdataOrder()[i].getId() == IdDish)
        {
            listofTable[numofTab-1].getdataOrder().erase(listofTable[numofTab-1].getdataOrder().begin()+i);
            cout<<"Delete complete!!!";
            system("pause");
            return;
        } 
    }
    cout<<"The dish does not exist or has been previously deleted!!!"<<endl;
    system("pause");
}

/*
* Function: changeQuantityofDish
* Description: Thay đổi số lượng món ăn trong đơn đặt hàng.
* Input:
*   numofTab: số thứ tự của bàn.
*   listofTable: danh sách bàn ăn.
* Output:
*   Thực hiện thay đổi số lượng của món ăn đã được gọi.
*/
void changeQuantityofDish(int numofTab,vector<Table> & listofTable){
    int IdDish;
    cout<<"Enter Id of dish: "; cin >> IdDish; cout<<endl;
    int quantity;
    for (int i = 0;i < listofTable[numofTab-1].getdataOrder().size();i++)
    {
        if (listofTable[numofTab-1].getdataOrder()[i].getId() == IdDish)
        {
            cout<<"Enter new quantity: ";
            cin >> quantity;
            listofTable[numofTab-1].getdataOrder()[i].setQuantity(quantity);
            cout<<"Change complete!!!"<<endl;

            return;
        } 
    }
    cout<<"The dish does not exist or has been previously deleted!!!"<<endl;
    system("pause");
}

/*
* Function: purchaseTable
* Description: Tính toán giá trị của đơn gọi món.
* Input:
*   numofTab: số thứ tự của bàn.
*   listofTable: danh sách bàn ăn.
* Output:
*   Trả về số tiền cần thanh toán của bàn ăn.
*/
int purchaseTable(int numofTab,vector<Table> & listofTable){
    int total = 0;
    for (Order x:listofTable[numofTab-1].getdataOrder())
    {
        total += x.getPrice()*x.getQuantity();
    }
    return total;
}
    
//
void printSpace(int a){
    for (int i = 0; i < a; i++)
    {
        cout<<" ";
    }  
}
// print function of class Dishes and vector of Dishes element.
void printEleofDishes(Dishes dish){
    cout<<dish.getId();
    printSpace(9-Numof_Digits(dish.getId()));
    cout<<dish.getName()<<setw(30-dish.getName().length());
    cout<<dish.getPrice()<<endl;
}

void printTittleofDish(){
    cout<<"STT"<<"  ";
    cout<<"ID"<<"       ";
    cout<<"NAME OF DISH"<<"             ";
    cout<<"PRICE"<<endl;
}

void printMenu(vector<Dishes> & menu){
    cout<<"_______MENU_______"<<endl<<endl;
    printTittleofDish();
    for (int i = 0; i < menu.size(); i++)
    {
        cout<<(i+1);
        printSpace(5-Numof_Digits(i+1));
        printEleofDishes(menu[i]);
    }
}


//Print function of class Order and vector of Order element.

void printEleofOrder(Order order){
    cout<<order.getId();
    printSpace(9-Numof_Digits(order.getId()));
    cout<<order.getName()<<setw(30-order.getName().length());
    cout<<order.getPrice();
    printSpace(20-Numof_Digits(order.getPrice()));
    cout<<order.getQuantity()<<endl;
}

void printTittleofOrder(int numof_Tab){
    cout<<"_______ORDER TABLE "<<numof_Tab<<"_______"<<endl<<endl;
    cout<<"STT"<<"  ";
    cout<<"ID"<<"       ";
    cout<<"NAME OF DISH"<<"             ";
    cout<<"PRICE";
    cout<<"           "<<"QUANTITY"<<endl;
}

void printOrder(vector<Order> & table,int numof_Tab){
    printTittleofOrder(numof_Tab);
    for (int i = 0; i < table.size(); i++)
    {
        cout<<(i+1);
        printSpace(5-Numof_Digits(i+1));
        printEleofOrder(table[i]);
    }
}
//Print table.
void printTable(vector<Table> & listTable){
    cout<<"_______LIST OF TABLE_______"<<endl<<endl;
    cout<<"NUMBER"<<"  |";
    for(Table x:listTable)
    {
        printSpace(3);
        cout<<x.getNumTale();
        printSpace(4-Numof_Digits(x.getNumTale()));
        cout<<"|";
    }
    cout<<endl;
    cout<<"STATUS"<<"  |";
    for(Table x:listTable)
    {
        printSpace(3);
        if (x.getstatus() == FULL)
        {
            cout<<"X";
        }else cout<<"0";
        printSpace(3);
        cout<<"|";
    }
    cout<<endl;
}

int enter_choose(){
    int n;
    cout<<"Enter your choose: "; cin >> n;
    return n;
}