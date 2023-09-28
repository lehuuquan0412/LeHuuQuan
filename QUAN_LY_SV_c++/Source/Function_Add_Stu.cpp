#include "data_Student.h"
#include "Function_Add_Student.h"


int Numof_Digits(int a){
    int dem=0;
	while(a>=10){
		a/=10; 
		dem++;
	}
    return dem + 1;
}

void printSpace(int n){
    for (int i = 0; i < n; i++)
    {
        cout<<" ";
    } 
}


void printTittle(){
    cout<<"MSSV   ";
    cout<<"Ho va Ten";
    printSpace(15);
    cout<<"Nam sinh      ";
    cout<<"Gioi tinh      ";
    cout<<"Diem Toan      ";
    cout<<"Diem Ly        ";
    cout<<"Diem Hoa       ";
    cout<<"Trung binh"<<endl;
}

void printInfo(SinhVien sv){
    string Gender;
    typeGender gender = sv.getGender();
    if (gender)
    {
        Gender = "Nu";
    }else Gender = "Nam";
    
    cout<<sv.getId()<<"   "<<sv.getName()<<setw(30-(sv.getName()).length())<<sv.getBirth();
    printSpace(10);
    cout<<Gender;
    printSpace(15-Gender.length());
    cout<< setprecision(2) << fixed<<round(100*sv.getdiemToan())/100;
    cout<<setw(15)<< setprecision(2) << fixed <<round(100*sv.getdiemLy())/100;
    cout<<setw(15)<< setprecision(2) << fixed<<round(100*sv.getdiemHoa())/100;
    cout<<setw(15)<< setprecision(2) << fixed<<sv.getTrungbinh()<<endl;
}

void printList(vector<SinhVien> & data){
    if (data.empty())
    {
        cout<<"Danh sach khong ton tai!!!"<<endl;
    }else{
        cout<<"        DANH SACH SINH VIEN      "<<endl;
        printTittle();
        for (SinhVien x:data)
        {
            printInfo(x);
        }
    }
}

bool compareTB(SinhVien a,SinhVien b){
    return a.getTrungbinh() <= b.getTrungbinh();
}

string splitName(string str){
    string delimiter = " ";
    string test = str;
    size_t pos = 0;
    string token;
    while ((pos = test.find(delimiter)) != string::npos) {
        token = test.substr(0, pos);
        test.erase(0, pos + delimiter.length());
    }
    return test;
}


bool compareName(SinhVien a,SinhVien b){
    return splitName(a.getName()) < splitName(b.getName());
}

void addSinhVien(vector<SinhVien> & data){
    add:
    string name;
    cout<<"Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin,name);
    int birth;
    while (1)
    {
        cout<<"Nhap nam sinh: ";
        cin >> birth;
        if ( birth < 2005) break; 
        else printf("Nam sinh khong dung, vui long nhap lai!!!");
    }

    typeGender gender;
    int key = 0;
    a:
    cout<<"Nhap gioi tinh: ";
    cin >> key;
    switch (key)
    {
    case 0:
        gender = NAM;
        break;
    case 1:
        gender = NU;
        break;
    default:
        printf("\nNhap sai gioi tinh, vui long nhap lai!!!");
        goto a;
    }

    double Toan;
    while (1)
    {
        cout<<"Nhap diem toan: ";
        cin >> Toan;
        if (Toan >= 0 && Toan <= 10) break;
        else printf("\nSai diem, vui long nhap lai!!!"); 
    }
    double Ly;
    while (1)
    {
        cout <<"Nhap diem ly: ";
        cin >> Ly;
        if (Ly >= 0 && Ly <= 10) break;
        else printf("\nSai diem, vui long nhap lai!!!"); 
    }
    double Hoa;
    while (1)
    {
        cout<<"Nhap diem hoa: ";
        cin >> Hoa;
        if (Hoa >= 0 && Hoa <= 10) break;
        else printf("\nSai diem, vui long nhap lai!!!"); 
    }
    SinhVien sv(name,birth,gender,Toan,Ly,Hoa);
    data.push_back(sv);
    cout<<"Them sinh vien thanh cong!!!"<<endl;
    int i;

    b:
    cout<<"1.Them sinh vien \n2.Thoat."<<endl;
    cout<<"Vui long chon phim: ";
    cin>>i;
    switch (i)
    {
    case 1:
        goto add;
    case 2:
        break;
    
    default:
        printf("Nhap sai, vui long nhap lai!!!");
        goto b;
    }    
}

void changeInfo(vector<SinhVien> & data){
    int stt;
    cout<<"Nhap ma so sinh vien: ";
    cin>>stt;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].getId() == stt)
        {
            cout<<"\nThong tin sinh vien can thay doi: "<<endl<<endl;
            printTittle();
            printInfo(data[i]);
            int choice;
            cout<<"\n#Ban muon thay doi: "<<endl;
            cout<<"1.Ten sinh vien"<<endl;
            cout<<"2.Nam sinh"<<endl;
            cout<<"3.Gioi tinh"<<endl;
            cout<<"4.Diem Toan"<<endl;
            cout<<"5.Diem Ly"<<endl;
            cout<<"6.Diem Hoa"<<endl;
            cout<<"Nhap so ban chon: "; cin>>choice;

            chance:
            switch (choice)
            {
            case 1:
            {
                string ten;
                cout<<"Nhap ten sinh vien: ";
                cin.ignore();
                getline(cin,ten);
                data[i].setName(ten);
            }
                break;
            case 2:
            {
                int birth;
                while (1)
                {
                    cout<<"Nhap nam sinh: ";
                    cin >> birth;
                    if ( birth < 2005) break; 
                    else printf("Nam sinh khong dung, vui long nhap lai!!!");
                }
                data[i].setBirth(birth);
            }
                break;
            case 3:
            {
                typeGender gender;
                int k = 0;
                gender:
                cout<<"Nhap gioi tinh: ";
                cin >> k;
                switch (k)
                {
                    case 0:
                    gender = NAM;
                    break;
                    case 1:
                    gender = NU;
                    break;
                default:
                    printf("\nNhap sai gioi tinh, vui long nhap lai!!!");
                    goto gender;
                }
                data[i].setGender(gender);
            }
                break;
            case 4:
            {
                double Toan;
                while (1)
                {
                    cout<<"Nhap diem toan: ";
                    cin >> Toan;
                    if (Toan >= 0 && Toan <= 10) break;
                    else printf("\nSai diem, vui long nhap lai!!!"); 
                }
                data[i].set_diemToan(Toan);
            }
                break;
            case 5:
                double Ly;
                while(1){
                    cout <<"Nhap diem ly: ";
                    cin >> Ly;
                    if (Ly >= 0 && Ly <= 10) break;
                    else printf("\nSai diem, vui long nhap lai!!!");
                } 
                data[i].set_diemLy(Ly);
                break;
            case 6:
                double Hoa;
                while (1)
                {
                    cout<<"Nhap diem hoa: ";
                    cin >> Hoa;
                    if (Hoa >= 0 && Hoa <= 10) break;
                    else printf("\nSai diem, vui long nhap lai!!!"); 
                }
                data[i].set_diemHoa(Hoa);
                break;

            default:
                cout<<"\nNhap sai so, vui long nhap lai: ";
                goto chance;
            }
            cout<<"\nThay doi du lieu thanh cong!!!"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"Khong ton tai sinh vien!!!"<<endl;
    system("pause");
}

void eraseSinhVien(vector<SinhVien> & data){
    int stt;
    cout<<"\nNhap ma so sinh vien: ";
    cin >> stt;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].getId() == stt)
        {
            cout<<"Thong tin sinh vien can xoa: "<<endl;
            printTittle();
            printInfo(data[i]);
            data.erase(data.begin()+i);
            cout<<"Xoa du lieu thanh cong!!!"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"Khong tim duoc sinh vien!!!"<<endl;
    system("pause");
}  

void searchbyName(vector<SinhVien> & data){
    string searchName;
    cout<<"Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin,searchName);
    for (SinhVien x:data)
    {
        if(x.getName() == searchName){
            printTittle();
            printInfo(x);
            cout<<endl;
            system("pause");
            return;
        }
    }
    cout<<"Khong tim duoc sinh vien!!!"<<endl;
    system("pause");
}

void sortbyTrungBinh(vector<SinhVien> & data){
    sort(data.begin(),data.end(),compareTB);
    printList(data);
}

void sortbyName(vector<SinhVien> & data){
    sort(data.begin(),data.end(),compareName);
    printList(data);
}