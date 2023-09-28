#ifndef __FUNCTION_H
#define __FUNCTION_H

#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<math.h>
#include "type_Data_Hotel.h"

using namespace std;

void Set_Numberof_Room(int numofRoom,vector<RoomInfo> & listof_Room);

int Numof_Digits(int a);
//Nhập thời gian từ bàn phím: giờ phút giây.
Times enter_Schedule_times(Times time_status);
//Nhập ngày từ bàn phím : ngày, tháng.
Dates enter_Schedule_dates(Dates time_status);

string get_status(Status time_status);
//In ngày
void print_Date(Dates date);
//In giờ.
void print_Time(Times time);

void printSpace(int n);
//In danh sách phòng.
void print_Listof_Room(vector<RoomInfo> & listofRoom);

int optionEnd();

void print_titleClient();

void print_InfoClient(ClientInfo client);

void print_dataClient(ClientManager client);

JobPosition enter_Position(int position);

string get_Job(JobPosition job_Position);

bool empty_User_staff(SecureManagement secure_manager);

bool log_in_Staff(string username, string password, SecureManagement secure_manager);

void delete_Staff(int id_temp, vector<Staff> & listof_Staff);

void print_Ele_Staff(Staff staff_temp);

void print_Tittle_Staff();

void print_List_Staff(vector<Staff> & listofStaff);

void print_Ele_User(User user_temp,vector<Staff> staff_temp);

void print_Tittle_User();

void print_List_User(vector<User> listofUser,vector<Staff> listofStaff);

int access_manage_Client(string username, string password, SecureManagement temp,vector<Staff> staff_temp);

double purchase(historyClient in, historyClient out);

Status enter_Schedule_status(Status time_status);

bool check_Status_Room(int Id_Room_var, vector<RoomInfo> & listof_Room);

int enter_Choose();

#endif