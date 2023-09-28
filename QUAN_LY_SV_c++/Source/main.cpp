#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>

#include "data_Student.h"
#include "Function_Add_Student.h"

int main(int argc, char const *argv[])
{
    int opt;
    vector<SinhVien> dataBaseSV;
    SinhVien sv1("Le Huu Quan",2002,NAM,9.5,6.1,8.3);
    SinhVien sv2("Le Thu Ha",2003,NU,8.1,7.3,9.2);
    dataBaseSV.push_back(sv1);
    dataBaseSV.push_back(sv2);
    while (1)
    {
        system("cls");
        cout<<"     QUAN LY SINH VIEN"<<endl<<endl;
        cout<<"1.Them sinh vien."<<endl;
        cout<<"2.Cap nhat thong tin sinh vien."<<endl;
        cout<<"3.Xoa sinh vien."<<endl;
        cout<<"4.Tim kiem sinh vien bang ten."<<endl;
        cout<<"5.Sap xep theo diem trung binh."<<endl;
        cout<<"6.Sap xep theo ten."<<endl;
        cout<<"7.Hien thi danh sach sinh vien"<<endl;
        cout<<"0.Thoat chuong trinh."<<endl;
        cout<<"Nhap so: "; cin >> opt;

        switch (opt)
        {
        case 1:
            system("cls");
            cout<<"#Khoi tao thong tin sinh vien:"<<endl;
            addSinhVien(dataBaseSV);
            break;
        case 2:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#Thay doi thong tin sinh vien:"<<endl<<endl;
                changeInfo(dataBaseSV);
            }
            break;
        case 3:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#Xoa thong tin sinh vien:"<<endl<<endl;
                eraseSinhVien(dataBaseSV);
            }
            break;
        case 4:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#Tim kiem thong tin sinh vien:"<<endl<<endl;
                searchbyName(dataBaseSV);
            }
            break;
        case 5:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#Sap xep thong tin sinh vien theo diem trung binh:"<<endl<<endl;
                sortbyTrungBinh(dataBaseSV);
                system("pause");
            }
            break;
        case 6:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#Sap xep thong tin sinh vien theo ten:"<<endl<<endl;
                sortbyName(dataBaseSV);
                system("pause");
            }
            break;
        case 7:
            if(dataBaseSV.empty()){
                cout<<"Danh sach sinh vien khong ton tai!!!"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<<"#In danh sach sinh vien:"<<endl<<endl;
                printList(dataBaseSV);
                system("pause");
            }
            break;
        case 0:
            cout<<"Dang thoat chuong trinh!!!"<<endl;
            return 0;
        default:
            cout<<"Nhap sai, vui long nhap lai: "<<endl;
            break;
        }
    }
}
