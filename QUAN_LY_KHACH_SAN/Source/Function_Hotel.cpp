#include "type_Data_Hotel.h"
#include "Function_Add.h"

/*
* Function: Set_Numberof_Room
* Description: Thêm số phòng trong ngày.
* Input:
*   numofRoom: số lượng phòng.
*   listof_Room: vector danh sách phòng.
* Output:
*   tạo danh sách phòng với số lượng phần tử bằng số lượng phòng.
*/
void Set_Numberof_Room(int numofRoom,vector<RoomInfo> & listof_Room){
    listof_Room.clear();
    idRoom = 100;
    for (int i = 0; i < numofRoom; i++)
    {
        RoomInfo room(false);
        listof_Room.push_back(room);
    } 
}

/*
* Function: Numof_Digits
* Description: Tính số chữ số của 1 số nguyên.
* Input:
*   a : số nguyên cần tìm số chữ số.
* Output:
*   Trả về số chữ số kiểu integer.
*/
int Numof_Digits(int a){
    int dem=0;
	while(a>=10){
		a/=10; 
		dem++;
	}
    return dem + 1;
}

//Enter day and time from the keeyboard.

Times enter_Schedule_times(Times time_status){
    do
    {
        cout<<"Enter hour: ";  cin >> time_status.hour;
    } while (time_status.hour > 23);

    do
    {
        cout<<"Enter minute: ";  cin >> time_status.minute;
    } while (time_status.minute > 59);

    do
    {
        cout<<"Enter second: ";  cin >> time_status.second;
    } while (time_status.second > 59);
    return time_status;
}

Dates enter_Schedule_dates(Dates time_status){
    do
    {
        cout<<"Enter day: "; cin >> time_status.date;
    } while (time_status.date > 30);
    do
    {
        cout<<"Enter month: "; cin >> time_status.month;
    } while (time_status.month> 12);
    return time_status;
    
}
Status enter_Schedule_status(Status time_status){
    int status;
    do
    {
        cout<<"Enter status: "; cin >> status;
    } while (status > 1);
    if(status == 1) time_status = IN;
    else time_status = OUT;
    return time_status;
}

string get_status(Status time_status){
    if (time_status == IN)
    {
        return "In";
    }
    return "Out";
}

void print_Date(Dates date){
    if (date.date == 1)
    {
        cout<<"0"<<date.date;
    }else{
        cout<<date.date;
    }
    cout<<"/";
    if (date.month == 1)
    {
        cout<<"0"<<date.month;
    }else{
        cout<<date.month;
    }
    cout<<"/2023";
}

void print_Time(Times time){
    if (time.hour == 0)
    {
        cout<<"00";
    }else if (Numof_Digits(time.hour) == 1)
    {
        cout<<"0"<<time.hour;
    }else{
        cout<<time.hour;
    }
    cout<<":";
    if (time.minute == 0)
    {
        cout<<"00";
    }else if (Numof_Digits(time.minute) == 1)
    {
        cout<<"0"<<time.minute;
    }else{
        cout<<time.minute;
    }
    cout<<":";
    if (time.second == 0)
    {
        cout<<"00";
    }else if (Numof_Digits(time.second) == 1)
    {
        cout<<"0"<<time.second;
    }else{
        cout<<time.second;
    }
}

void printSpace(int n){
    for (int i = 0; i < n; i++)
    {
        cout<<" ";
    }
}

void print_Listof_Room(vector<RoomInfo> & listofRoom){
    cout<<"ID ROOM  ";
    for (int i = 0; i < (int)(listofRoom.size()); i++)
    {
        cout<<" "<<(listofRoom[i].get_idRoom())<<" ";
    }
    cout<<endl<<"STATUS   ";
    for (int i = 0; i < (int)(listofRoom.size()); i++)
    {
        cout<<"  ";
        if (listofRoom[i].get_statusRoom())
        {
            cout<<"X";
        }else{ cout<<"0";}
        cout<<"  ";
    }
    cout<<endl;
}

int optionEnd(){
    int n;
    cout<<"1. Continue."<<endl;
    cout<<"0. Back."<<endl<<endl;
    cout<<"Enter your choose: "; cin >> n;
    return n;
}

//Print information of client.

void print_titleClient(){
    cout<<"NAME";
    printSpace(16);
    cout<<"PHONE NUMBER"<<"   "<<"ADDRESS";
    printSpace(30);
    cout<<"ID ROOM  TIME      DATE       STATUS"<<endl;
}

void print_InfoClient(ClientInfo client){
    cout<<client.get_nameClient();
    printSpace(20-client.get_nameClient().length());
    cout<<"0"<<client.get_phoneNumber();
    printSpace(5);
    cout<<client.get_address();
    printSpace(37-client.get_address().length());
    cout<<client.get_Idroom_client()<<"      ";
    print_Time(client.get_history_Booking()[0].time_Book);
    cout<<"  ";
    print_Date(client.get_history_Booking()[0].date_Book);
    cout<<"  "<<get_status(client.get_history_Booking()[0].statusClient)<<endl;
}

void print_dataClient(ClientManager client){
    cout<<"NUM"<<"  ";
    print_titleClient();
    int id = 1;
    for (auto x:client.get_dataClient())
    {
        cout<<id;
        printSpace(5-Numof_Digits(id));
        id++;
        print_InfoClient(x);
    }
}
//Enter position from keyboard.
JobPosition enter_Position(int position){
    do
    {
        cout<<"Enter position of var: "; cin >> position;
    } while (position > 4);
    switch (position)
    {
    case 0:
        return JANITOR;
    case 1:
        return RECEIPTIONIST;
    case 2:
        return LAUNDRY_STAFF;
    case 3:
        return LAUGEGAGE_STAFF;
    default:
        return GRADENER;
    }
}

string get_Job(JobPosition job_Position){
    switch (job_Position)
    {
    case JANITOR:
        return "Janitor";
    case RECEIPTIONIST:
        return "Receiptionist";
    case LAUNDRY_STAFF:
        return "Laundry staff";
    case LAUGEGAGE_STAFF:
        return "Laugegage staff";
    default:
        return "Gradener";
    }
}



bool empty_User_staff(SecureManagement secure_manager){
    return secure_manager.get_database_User().empty();
}

/*
* Function: log_in_Staff
* Description: Trả về trạng thái đăng nhập.
* Input:
*   username: tên đăng nhập kiểu string.
*   password: mật khẩu kiểu string.
* Output:
*   trả về trạng thái false: đăng nhập thất bại. true: đăng nhập thành công.
*/
bool log_in_Staff(string username, string password, SecureManagement secure_manager){
    for (int i = 0; i < (secure_manager.get_database_User().size()); i++)
    {
        if (secure_manager.get_database_User()[i].identification(username, password))
        {
            cout<<"log-in completely!!!"<<endl;
            system("pause");
            return true;
        }    
    }
    return false;  
}

void delete_Staff(int id_temp, vector<Staff> & listof_Staff){
    for (int i = 0; i < (int)listof_Staff.size(); i++)
    {
        if (listof_Staff[i].get_id_Staff() == id_temp)
        {
            listof_Staff.erase(listof_Staff.begin()+i);
            return;
        }
    }
    cout<<"The staff does not exist or has been previously deleted!!!"<<endl;
}
//Print list of staff: id staff, name, phone number, Shift, status.
void print_Ele_Staff(Staff staff_temp){
    cout<<staff_temp.get_id_Staff()<<"  ";
    cout<<staff_temp.get_Name_Staff();
    printSpace(25-staff_temp.get_Name_Staff().length());
    cout<<"0"<<staff_temp.get_phoneNumber_Staff();
    printSpace(15-Numof_Digits(staff_temp.get_phoneNumber_Staff()));
    cout<<get_Job(staff_temp.get_Position_Staff());
    printSpace(20-get_Job(staff_temp.get_Position_Staff()).length());
    print_Time(staff_temp.get_time_On());
    cout<<"     ";
    print_Time(staff_temp.get_time_Off());
    cout<<"     "<<get_status(staff_temp.get_status_Staff());
}

void print_Tittle_Staff(){
    cout<<"ID   NAME";
    printSpace(21);
    cout<<"PHONE NUMBER    ";
    cout<<"POSITION";
    printSpace(12);
    cout<<"TIME ON      TIME OFF     STATUS";
}

void print_List_Staff(vector<Staff> & listofStaff){
    if (listofStaff.empty())
    {
        cout<<"No staff at here"<<endl;
        return;
    }
    print_Tittle_Staff(); cout<<endl;
    for (auto x: listofStaff)
    {
        print_Ele_Staff(x); cout<<endl;
    }
}

// Print information of user.

void print_Ele_User(User user_temp,vector<Staff> staff_temp){
    cout<<user_temp.get_Id_User()<<"  ";
    for (auto x: staff_temp)
    {
        if (x.get_id_Staff() == user_temp.get_Id_User())
        {
            cout<<x.get_Name_Staff();
            printSpace(25-x.get_Name_Staff().length());
            break;
        } 
    }
    cout<<user_temp.get_Username();
    printSpace(20-user_temp.get_Username().length());
    cout<<user_temp.get_Password();
    printSpace(20-user_temp.get_Password().length());
}

void print_Tittle_User(){
    cout<<"ID   NAME";
    printSpace(21);
    cout<<"USERNAME";
    printSpace(12);
    cout<<"PASSWORD";
    printSpace(12);
}

void print_List_User(vector<User> listofUser,vector<Staff> listofStaff){
    if (listofUser.empty())
    {
        cout<<"No uset at here!!!"<<endl;
        return;
    }
    print_Tittle_User();
    cout<<endl;
    for (auto x: listofUser)
    {
        print_Ele_User(x,listofStaff);
        cout<<endl;
    }
}

int access_manage_Client(string username, string password, SecureManagement temp,vector<Staff> staff_temp){
    int access;
    while (1)
    {
        cout<<"Enter username: "; cin >> username;
        cout<<"Password: "; cin >> password;
        if (temp.get_Check_Signup_Admin(username,password))
        {
            cout<<"Log in completely!!!"<<endl;
            cout<<"You are logged in with admin rights."<<endl;
            system("pause");
            access = 1;
            return access;
        }else{
            for (auto x: temp.get_database_User())
            {
                if (x.identification(username,password))
                {
                    cout<<"Log in complete!!!"<<endl;
                    for (auto y: staff_temp)
                    {
                        if (y.get_id_Staff() == x.get_Id_User())
                        {
                            if (y.get_Position_Staff() == JANITOR||y.get_Position_Staff() == RECEIPTIONIST)
                            {
                                cout<<"You have enough access rights!!!"<<endl;
                                system("pause");
                                access = 1;
                                return access;
                            }else{
                                cout<<"You don't have enough access rights!!!"<<endl;
                                system("pause");
                                access = 0;
                                return access;
                            }  
                        }   
                    }
                }   
            }
            cout<<"Incorrect account or password. Please re-enter!!!"<<endl;
        }  
    }
}

double purchase(historyClient in, historyClient out){
    double total = (out.date_Book.month - in.date_Book.month)*30*24+(out.date_Book.date-in.date_Book.date)*24+(out.time_Book.hour-in.time_Book.hour)+(out.time_Book.minute-in.time_Book.minute)/60+(out.time_Book.second-in.time_Book.second)/3600;
    return (round(total*50))*1000;
}

// Kiểm tra trạng thái của phòng trước khi đặt

bool check_Status_Room(int Id_Room_var, vector<RoomInfo> & listof_Room){
    for (uint16_t i = 0; i < listof_Room.size(); i++)
    {
        if (listof_Room[i].get_statusRoom() && listof_Room[i].get_idRoom() == Id_Room_var)
        {
            return true;
        }
    }
    return false;                          
}

//Nhập lựa chọn từ bàn phím.

int enter_Choose(){
    int n;
    cout<<"Enter your choose: "; cin >> n;
    return n;
}