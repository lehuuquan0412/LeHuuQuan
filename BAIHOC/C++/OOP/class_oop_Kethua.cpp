#include<iostream>
#include<string>

using namespace std;

class Doituong
{
protected:
    string Name;
    string Gender;
    int Old;
public:
    void setThongtin(string ten,string gioiTinh,int tuoi);
    void hienThi();
};

void Doituong::setThongtin(string ten,string gioiTinh,int tuoi){
    Name = ten;
    Gender = gioiTinh;
    Old = tuoi;
}

void Doituong::hienThi(){
    cout<<"Ten sinh vien: "<<Name<<endl;
    cout<<"Gioi tinh: "<<Gender<<endl;
    printf("Tuoi: %d\n",Old);
}

class SinhVien:public Doituong
{
private:
    int Mssv;
public:
    void setThongtin(string ten,string gioiTinh,int tuoi,int Id);
    void hienThi();
};

void SinhVien::setThongtin(string ten,string gioiTinh,int tuoi,int Id){
    Name = ten;
    Gender = gioiTinh;
    Old = tuoi;
    Mssv = Id;
}

void SinhVien::hienThi(){
    cout<<"Ten sinh vien: "<<Name<<endl;
    cout<<"Gioi tinh: "<<Gender<<endl;
    printf("Tuoi: %d\n",Old);
    printf("Ma so sinh vien: %d\n",Mssv);
}

int main(int argc, char const *argv[])
{
    Doituong sv1;
    sv1.setThongtin("Le Huu Quan","Nam",20);
    sv1.hienThi();

    SinhVien sv2;
    sv2.setThongtin("Le Huu Vinh","Nam",20,1260);
    sv2.hienThi();

    return 0;
}
