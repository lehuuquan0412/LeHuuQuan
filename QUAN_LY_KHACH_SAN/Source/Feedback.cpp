/*
* File: Feedback.cpp
* Author: Lê Hữu Quân
* Date: 28/9/2023
* Description: định nghĩa hàm thực hiện chức năng ghi nhận phản hồi của khách hàng.
*/
#include "Feedback.h"
#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Feedback
* Description: Hàm thực hiện chức năng ghi nhận phản hồi.
* Input:
*   listof_Feedback: vector dữ liệu phản hồi.
* Output:
*   Ghi nhận phản hồi của khách hàng.
*/
void Feedback(vector<Feedback_info> & listof_Feedback){
    int key;
    string name_Var;
    while (1)
    {
        system("cls");
        cout<<"====FEEDBACK AND EVALUATION===="<<endl<<endl;
        cout<<"Enter your name: "; cin.ignore(); getline(cin,name_Var);
        string feedback;
        cout<<"Enter your feeddback: "; cin.ignore(); getline(cin,feedback);
        double mark;
        do
        {
            cout<<"Enter your rating: "; cin >> mark;
        } while (mark > 10);
        Feedback_info temp(name_Var,feedback,mark);
        listof_Feedback.push_back(temp);
        cout<<"Your response has been noted. Thank you for using our service!!!"<<endl;
        do
        {
            cout<<"1. Continue."<<endl<<"0. Back."<<endl;
            key = enter_Choose();
        } while (key > 1);
        if(key == 0) return;
    }
}