#ifndef __DATA_STU
#define __DATA_STU
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

typedef enum{
    NAM = 0,
    NU = 1,
}typeGender;

static int id = 1000;

using namespace std;

class SinhVien {
    private:
        int Id;
        string NAME;
        int BIRTH;
        typeGender GENDER;
        double Diem_Toan;
        double Diem_Ly;
        double Diem_Hoa;
    public:
        SinhVien(string name,int birth,typeGender gender,double diem_Toan,double diem_Ly,double diem_Hoa);
        void setName(string name);
        void setBirth(int birth);
        void setGender(typeGender gender);
        void set_diemToan(double diem_Toan);
        void set_diemLy(double diem_Ly);
        void set_diemHoa(double diem_Hoa);

        string getName();
        int getBirth();
        typeGender getGender();
        int getId();
        double getdiemToan();
        double getdiemLy();
        double getdiemHoa();
        double getTrungbinh();
};




#endif
