#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<math.h>
#include "type_Data_Hotel.h"
//Time


RoomInfo::RoomInfo(bool status){
    this->IdRoom = idRoom;
    idRoom++;
    this->statusRoom = status;
};

void RoomInfo::set_statusRoom(bool status){
    this->statusRoom = status;
}

int RoomInfo::get_idRoom(){
    return this->IdRoom;
}

bool RoomInfo::get_statusRoom(){
    return this->statusRoom;
}

//Set client infomation;

ClientInfo::ClientInfo(int Id, int phone, string name, string address){
    this->Address = address;
    this->idroom_Client = Id;
    this->name_Client = name;
    this->phone_Number = phone;
};

void ClientInfo::set_history_Client(historyClient temp){
    this->historyBookings.push_back(temp);
};


void ClientInfo::set_Idroom_client(int Id){
    this->idroom_Client = Id;
};

void ClientInfo::set_phoneNumber(int phone){
    this->phone_Number = phone;
};

void ClientInfo::set_nameClient(string name){
    this->name_Client = name;
};

void ClientInfo::set_address(string address){
    this->Address = address;
};

int ClientInfo::get_Idroom_client(){
    return this->idroom_Client;
}

int ClientInfo::get_phoneNumber(){
    return this->phone_Number;
}

string ClientInfo::get_nameClient(){
    return this->name_Client;
}

string ClientInfo::get_address(){
    return this->Address;
}

vector<historyClient> & ClientInfo::get_history_Booking(){
    return this->historyBookings;
}


vector<ClientInfo> & ClientManager::get_dataClient(){
    return this->dataClient;
}


void ClientManager::add_Client(ClientInfo x,vector<RoomInfo> & listofRoom){
    for (int i = 0; i < listofRoom.size(); i++)
    {
        if (listofRoom[i].get_idRoom() == x.get_Idroom_client())
        {
            listofRoom[i].set_statusRoom(true);
            this->dataClient.push_back(x);
            system("pause");
            break;
        }
    }
}


void ClientManager::adjust_nameClient(string name,int numOrder){
    dataClient[numOrder-1].set_nameClient(name);
};

void ClientManager::adjust_addressClient(string address,int numOrder){
    dataClient[numOrder-1].set_address(address);
};

void ClientManager::adjust_phoneClient(int phone,int numOrder){
    dataClient[numOrder-1].set_phoneNumber(phone);
};

void ClientManager::remove_Client(int numOrder,vector<RoomInfo> & listofRoom){
    int idTemp;
    idTemp =  dataClient[numOrder-1].get_Idroom_client();
    dataClient.erase(dataClient.begin()+numOrder-1);
    for (uint16_t i = 0; i < listofRoom.size(); i++)
    {
        if (listofRoom[i].get_idRoom() == idTemp)
        {
            listofRoom[i].set_statusRoom(false);
            break;
        } 
    }
};


//Information of staff.


Staff::Staff(string name, int phone, JobPosition job, Times On, Times Off, Status status){
    this->Id_Staff = idStaff;
    idStaff++;
    this->Name = name;
    this->phone_Number = phone;
    this->Job = job;
    this->time_Off = Off;
    this->time_On = On;
    this->Status_Today = status;
};

void Staff::set_Name_Staff(string name){
    this->Name = name;
};

void Staff::set_phoneNumber_Staff(int phone){
    this->phone_Number = phone;
}

void Staff::set_time_On(Times on){
    this->time_On = on;
}

void Staff::set_Job_Position(JobPosition job){
    this->Job = job;
}

void Staff::set_time_Off(Times off){
    this->time_Off = off;
}

void Staff::set_status(Status status){
    this->Status_Today = status;
}

int Staff::get_id_Staff(){
    return this->Id_Staff;
}

string Staff::get_Name_Staff(){
    return this->Name;
}

int Staff::get_phoneNumber_Staff(){
    return this->phone_Number;
}

Times Staff::get_time_On(){
    return this->time_On;
}

Times Staff::get_time_Off(){
    return this->time_Off;
}

Status Staff::get_status_Staff(){
    return this->Status_Today;
}

JobPosition Staff::get_Position_Staff(){
    return this->Job;
}
// Information of user.



User::User(string username, string password){
    this->Username = username;
    this->Password = password;
};

void User::set_Username(string username){
    this->Username = username;
};

void User::set_Password(string password){
    this->Password = password;
};

void User::set_Id_User(int id){
    this->id_User = id;
};

string User::get_Username(){
    return this->Username;
}

string User::get_Password(){
    return this->Password;
}

int User::get_Id_User(){
    return this->id_User;
}

bool User::identification(string input_Username, string input_Password){
    return (input_Username == this->Username)&&(input_Password == this->Password);
}
// Manage security.




void SecureManagement::add_User(int id_user, string input_username, string input_password){
    User user_temp;
    user_temp.set_Id_User(id_user);
    user_temp.set_Username(input_username);
    user_temp.set_Password(input_password);
    this->data_User.push_back(user_temp);
};

void SecureManagement::remove_User(int id_user){
    for (uint16_t i = 0; i < data_User.size(); i++)
    {
        if (data_User[i].get_Id_User() == id_user){
            data_User.erase(data_User.begin()+i);
            return;
        }
    }
    cout<<"User does not exist"<<endl;
};

void SecureManagement::change_Password_User(string input_username, string new_password){
    for (uint16_t i = 0; i < data_User.size(); i++)
    {
        if (data_User[i].get_Username() == input_username)
        {
            data_User[i].set_Password(new_password);
            return;
        }
    } 
};

void SecureManagement::edit_Pass_Addmin(string new_pass){
    user_Admin.set_Password(new_pass);
};

bool SecureManagement::get_Check_Signup_Admin(string input_username, string input_password){
    if(user_Admin.identification(input_username,input_password)) return true;
    else return false;
}

vector<User> & SecureManagement::get_database_User(){
    return this->data_User;
}

//History pay.



Pay_History::Pay_History(double charge, int Id, int phone, string name, string address ):ClientInfo(Id,phone,name,address){
    this->purchase = charge;
};

void Pay_History::set_Purchase(double charge){
    this->purchase = charge;
}

void Pay_History::get_Time_History(int id_Room_var,vector<ClientInfo> info_Custumer){
    for (auto x: info_Custumer)
    {
        if (x.get_Idroom_client() == id_Room_var)
        {
            for (auto y: x.get_history_Booking())
            {
                this->get_history_Booking().push_back(y);
            }
            return;
        }
    }
}

double Pay_History::get_Pay(){
    return this->purchase;
}


//Service.


Services::Services(string name_Serve, bool sta_Serve){
    this->name_Service = name_Serve;
    this->status_Service = sta_Serve;
};

void Services::set_Name_Service(string name){
    this->name_Service = name;
};

void Services::set_status_Service(bool sta_Serve){
    this->status_Service = sta_Serve;
};

string Services::get_Name_Service(){
    return this->name_Service;
}

string Services::get_Status_Service(){
    if (this->status_Service)
    {
        return "X";
    }else return "O";
}

// Feedback.

