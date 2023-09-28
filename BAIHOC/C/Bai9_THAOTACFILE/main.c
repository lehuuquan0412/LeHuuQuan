#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
// Ghi vao file
    // FILE * file = fopen("text.txt" , "w");
    // if (file != NULL)       
    // {   
    //     fprintf(file, "Hello World!\n");
    //     fclose(file);
    //     printf("OK\n");
    // }else{
    //     printf("ERROR!!!");
    // }
//Doc file tung tu
    // FILE * file = fopen("text.txt","r");
    
    // if (file != NULL)
    // {
    //     char buffer[100];
    //     while (fscanf(file, "%s", buffer) != EOF)
    //     {
    //         printf("%s", buffer);
    //     }
    //     fclose(file);

    // }
    // else printf("Khong the mo file\n");
//Doc file tung dong
    FILE * file = fopen("text.txt","r");
    if (file != NULL)
    {
        char buffer[100];
        while (fgets(buffer,sizeof(buffer), file) != NULL)  
        {
            printf("%s", buffer);
        }
    }else printf("Khong the mo file\n");

    return 0;
}
