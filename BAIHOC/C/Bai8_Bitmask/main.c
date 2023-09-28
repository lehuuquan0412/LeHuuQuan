#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

uint8_t data1 = 48;
uint8_t data2 = 23;

typedef enum{
    AO = 1 << 0,
    QUAN = 1 << 1,
    VAY = 1 << 2,
    DAM = 1 << 3,
    NHAN = 1 << 4,
    VONG_TAY = 1 << 5,
    GIAY = 1 << 6,
    TUI = 1 << 7, 
}DO_DUNG_CA_NHAN;

uint8_t GioHang = 0;

void addItem(DO_DUNG_CA_NHAN item){
    GioHang |= item;
}

void checkItem(uint8_t Giatri,DO_DUNG_CA_NHAN item){
    if (Giatri & item)
    {
        printf("Co ");
    }else printf("Khong co ");
    
}


int main(int argc, char const *argv[])
{
    //printf("data = %d\n",data1|data2);
    //printf("data = %d\n",data1 & data2);
    //printf("data = %d\n",~(data1|data2));

    GioHang |= AO;
    GioHang |= TUI;
    printf("Gia tri = %d\n",GioHang);
    
    checkItem(GioHang,AO);


    return 0;
}
