#include <stdio.h>

#define STM32 1
#define PIC16f887 2
#define AVR 3
#define MCU STM32

#if MCU == STM32
    //SLC = 0xc8
#elif MCU == PIC16f887
    //SLC = 0xb2
#elif MCU == AVR
    //SLC = 0x88
#endif

int main(int argc, char const *argv[])
{
    /* SLC */
    return 0;
}


