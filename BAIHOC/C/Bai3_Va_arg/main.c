#include<stdio.h>
#include<stdarg.h>

int tong(int so_tham_so,...){
    va_list var;
    int bien_tong;

    va_start(var,so_tham_so);

    for (int i = 0; i < so_tham_so; i++)
    {
        bien_tong += va_arg(var,int);
    }
    
    va_end(var);
    return bien_tong;
}




int main(int argc, char const *argv[])
{
    printf("Tong: %d",tong(5,1,2,3,4,5));
    return 0;
}
