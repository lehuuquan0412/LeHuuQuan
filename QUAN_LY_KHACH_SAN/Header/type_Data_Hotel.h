
#ifndef __DATA_H
#define __DATA_H

#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<math.h>

static int idRoom = 100;
static int idStaff = 100;

using namespace std;

//Time
typedef struct{
    int hour;
    int minute;
    int second;
}Times;

//Date
typedef struct{
    int date;
    int month;
}Dates;

//status

typedef enum{
    IN,
    OUT
}Status;
//////////////////////////////////////////////////
typedef enum{
    JANITOR,
    RECEIPTIONIST,
    LAUNDRY_STAFF,
    LAUGEGAGE_STAFF,
    GRADENER
}JobPosition;

typedef struct{
    Times time_Work;
    Dates date_Work;
    bool statusWork;
}Schedule;

//struct history bookingl

typedef struct{
    Times time_Book;
    Dates date_Book;
    Status statusClient;
}historyClient;

//Set room infomation.

class RoomInfo{
    private:
        int IdRoom;
        bool statusRoom;
    public:
        RoomInfo(bool status);
        void set_statusRoom(bool status);
        int get_idRoom();
        bool get_statusRoom();
};



//Set client infomation;
class ClientInfo{
    private:
        int idroom_Client;
        int phone_Number;
        string name_Client;
        string Address;
        vector<historyClient> historyBookings;
    public:
        ClientInfo(int Id, int phone, string name, string address);
        void set_Idroom_client(int Id);
        void set_phoneNumber(int phoneNumber);
        void set_nameClient(string name);
        void set_address(string address);
        void set_history_Client(historyClient temp);
        int get_Idroom_client();
        int get_phoneNumber();
        string get_nameClient();
        string get_address();
        vector<historyClient> & get_history_Booking();
};



class ClientManager{
    private:
        vector<ClientInfo> dataClient;
    public:
        void add_Client(ClientInfo x,vector<RoomInfo> & listofRoom);
        void adjust_nameClient(string name,int numOrder);
        void adjust_addressClient(string address,int numOrder);
        void adjust_phoneClient(int phone,int numOrder);
        void remove_Client(int numOrder,vector<RoomInfo> & listofRoom);
        vector<ClientInfo> & get_dataClient();
};



//Information of staff.
class Staff{
    private:
        private:
        int Id_Staff;
        string Name;
        int phone_Number;
        JobPosition Job;
        Times time_On;
        Times time_Off;
        Status Status_Today;
    public:
        Staff(string name, int phone, JobPosition job, Times On, Times Off, Status status);
        void set_Name_Staff(string name);
        void set_phoneNumber_Staff(int phone);
        void set_Job_Position(JobPosition job);
        void set_time_On(Times on);
        void set_time_Off(Times off);
        void set_status(Status status);
        int get_id_Staff();
        string get_Name_Staff();
        int get_phoneNumber_Staff();
        Times get_time_On();
        Times get_time_Off();
        Status get_status_Staff();
        JobPosition get_Position_Staff();
};

// Information of user
class User{
    private:
        int id_User;
        string Username;
        string Password;
    public:
        User(string username = " ", string password = " ");
        void set_Username(string username);
        void set_Password(string password);
        void set_Id_User(int id);
        string get_Username();
        string get_Password();
        int get_Id_User();
        bool identification(string input_Username, string inputPassword);
};


// Manage security.

class SecureManagement{
    private:
        User user_Admin;
        vector<User> data_User;      
    public:
        SecureManagement(){
            user_Admin.set_Username("admin");
            user_Admin.set_Password("lehuuquan");
        }
        void add_User(int id_user, string input_username, string input_password);
        void remove_User(int id_user);
        void change_Password_User(string input_username, string new_password);
        void edit_Pass_Addmin(string new_pass);
        bool get_Check_Signup_Admin(string input_username, string input_password);
        vector<User> & get_database_User();
};



//History pay.

class Pay_History:public ClientInfo{
    private:
        double purchase;
    public:
        Pay_History(double charge,int Id, int phone, string name, string address );
        void set_Purchase(double charge);
        void get_Time_History(int id_Room_var,vector<ClientInfo> info_Custumer);
        double get_Pay();
        ClientInfo get_Info_Pay();
};


//Service.
class Services{
    private:
        string name_Service;
        bool status_Service;
    public:
        Services(string name_Serve, bool sta_Serve);
        void set_status_Service(bool sta_Serve);
        void set_Name_Service(string name);
        string get_Status_Service();
        string get_Name_Service();
};


// Feedback.

class Feedback_info{
    private:
        string name_Client;
        string feedback;
        double rate;
    public:
        Feedback_info(string name, string review, double mark){
            this->name_Client = name;
            this->feedback = review;
            this->rate = mark;
        } 
};



#endif