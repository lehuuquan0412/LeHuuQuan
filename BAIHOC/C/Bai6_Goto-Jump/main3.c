#include <stdio.h>
#include <setjmp.h>
jmp_buf env;
void checkDelay(int mDelay){
    mDelay = mDelay - 10;
    for (int i = 0; i < mDelay; i++)
    {
        btn1();
        btn2();
        btnExit;
        delay(10)
    }  
}
void btn1(){
    if (digitalRead(PIN1) == 1)
    {
        longjmp(env, 1);
    }    
}
void btn2(){
    if (digitalRead(PIN2) == 2)
    {
        longjmp(env, 2);
    } 
}
void btnExit(){
    if (digitalRead(PIN3) == 3)
    {
        longjmp(env, 3);
    }
}
void test1(){
    printf("Chuong trinh 1:\n");
    for (int i = 0; i < 5; i++)
    {
        LED1 ~= LED1;
        checkDelay(1000);
    }   
}
void test2(){
    printf("Chuong trinh 2:\n");
    for (int i = 0; i < 3; i++)
    {
        LED2 ~= LED2;
        checkDelay(500);
    }   
}
void test3(){
    exit(0);
}
int main(int argc, char const *argv[])
{
    int var = setjmp(env);
    while (1)
    {
        btn1();
        btn2();
        btnExit();
        switch (var)
        {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        default:
            break;
        }
        var = 0;
    }  
    return 0;
}
