
#include "data_Student.h"

SinhVien::SinhVien(string name,int birth,typeGender gender,double diem_Toan,double diem_Ly,double diem_Hoa){
    this->Id = id;
    id++;
    this->NAME = name;
    this->BIRTH = birth;
    this->GENDER = gender;
    this->Diem_Toan = diem_Toan;
    this->Diem_Ly = diem_Ly;
    this->Diem_Hoa = diem_Hoa;
};

void SinhVien::setName(string name){
    NAME = name;
};

void SinhVien::setBirth(int birth){
    BIRTH = birth;
};

void SinhVien::setGender(typeGender gender){
    GENDER = gender;
};

void SinhVien::set_diemToan(double Toan){
    Diem_Toan = Toan;
};

void SinhVien::set_diemLy(double Ly){
    Diem_Ly = Ly;
};

void SinhVien::set_diemHoa(double Hoa){
    Diem_Hoa = Hoa;
};

string SinhVien::getName(){
    return NAME;
}

int SinhVien::getBirth(){
    return this->BIRTH;
}

int SinhVien::getId(){
    return this->Id;
}

typeGender SinhVien::getGender(){
    return this->GENDER;
}

double SinhVien::getdiemToan(){
    return this->Diem_Toan;
}

double SinhVien::getdiemHoa(){
    return this->Diem_Hoa;
}

double SinhVien::getdiemLy(){
    return this->Diem_Ly;
}

double SinhVien::getTrungbinh(){
    return (round((Diem_Toan+Diem_Ly+Diem_Hoa)*100)/300);
}