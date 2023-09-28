#include <stdio.h>

#define SIZE 10

void test(){
    printf("This is test \n");
}
#define PRINTF test()
#define TONG(a,b) a+b
#define INPUT_DISPLAY(var, cmd, cond)   \       
    int var;                            \                              
    do                                  \          
    {                                   \                                          
        printf(cmd);                    \                        
        scanf("%d", &var);              \                  
    }while (cond);                      \                                        
    printf(#var);                       \                         
    printf(" = %d\n", var);    
#define VARIABLE(name, test1)           \          
    int int_##name;                     \                   
    double double_##name;               \                 
    #test1;                                
#define TEST2(...)                      \
   _VA_ARGS_              



int main(int argc, char const *argv[])
{
    int array[SIZE];
    int var = SIZE;
    PRINTF;
    printf("Tong a va b: %d\n", TONG(5,9));
    /*Dung define de thay the*/
    // int i;
    // do
    // {
    //     printf("Nhap vao i (i >= 0 && i <= 10): ");
    //     scanf("%d", &i);
    // } while (i > 10);
    // printf("i = %d\n",i);
    INPUT_DISPLAY(i, "Nhap vao i (i >= 0 && i <= 10): ", i > 10);
    VARIABLE(lam, abc);
    TEST2(mnk);
    return 0;
}