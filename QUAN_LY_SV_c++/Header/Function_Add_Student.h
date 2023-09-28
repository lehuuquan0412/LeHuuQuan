#ifndef __FUNC_STU
#define __FUNC_STU

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include "data_Student.h"

int Numof_Digits(int a);

void printSpace(int n);

void printTittle();

void printInfo(SinhVien sv);

void printList(vector<SinhVien> & data);

bool compareTB(SinhVien a,SinhVien b);

string splitName(string str);

bool compareName(SinhVien a,SinhVien b);

void addSinhVien(vector<SinhVien> & data);

void changeInfo(vector<SinhVien> & data);

void eraseSinhVien(vector<SinhVien> & data);

void searchbyName(vector<SinhVien> & data);

void sortbyTrungBinh(vector<SinhVien> & data);

void sortbyName(vector<SinhVien> & data);

#endif