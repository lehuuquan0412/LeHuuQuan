#ifndef __PURCHASE_H
#define __PURCHASE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<math.h>
#include "type_Data_Hotel.h"
#include "Function_Add.h"

using namespace std;


void Purchase(vector<RoomInfo> & listof_Room, ClientManager*manage_Client, vector<Pay_History> & listof_Pay);



#endif
