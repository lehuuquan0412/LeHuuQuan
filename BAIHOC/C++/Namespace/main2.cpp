#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>


using namespace std;
typedef struct{
    string ten;
    int tuoi;
    string lop;
}ThongTin;


int main(int argc, char const *argv[])
{
    list <int>  array = {2, 4, 7, 9, 3};
    vector <int> test = {6, 7, 4};
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("i = %d\n", test[i]);
    // }
    // for (vector <int> :: iterator it = test.begin(); it != test.end(); it++)
    // {
    //     cout<<"test = "<<*it<<endl;
    // }
    // for (list <int> :: iterator it = array.begin(); it != array.end(); it++)
    // {
    //         cout<<"test = "<<*it<<endl;
    // }
    map <int, ThongTin> SinhVien;
    SinhVien[100] = {"Hoang", 20, "CDT12"};
    SinhVien[101] = {"Tuan", 21, "CK13"};
    for (auto item : SinhVien)
    {
        cout<<"id = "<<item.first<<endl;
        cout<<"Ten: "<<item.second.ten<<", tuoi: "<<item.second.tuoi<<", lop: "<<item.second.lop<<endl;
    }
    
    
    
    return 0;
}
