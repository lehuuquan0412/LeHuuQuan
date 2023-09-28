#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int key = 0;
    MENU:
    do {
        printf("Chuong trinh abc:\n");
        printf("Nhan 1: Chuong trinh 1\n");
        printf("Nhan 2: Chuong trinh 2\n");
        printf("Nhan 3: Chuong trinh 3\n");
        printf("Nhan 0: Thoat\n");
        printf("Vui long nhap phim:...\n");
        scanf("%d", &key);
        if (key > 3)
        {
            system("cls");
            printf("Ban da nhap sai, vui long nhap lai...\n");
        }
    } while(key > 3);
    system("cls");
    switch (key)
    {
    case 0:
        exit(0);
        break;
    case 1:
        printf("Dang chay chuong trinh 1..\n");
        //Chuong trinh 1
        printf("Nhan 1: Quay lai\n");
        printf("Nhan 0: Thoat\n");
        printf("Vui long nhap phim:...\n");
        scanf("%d", &key);
        if (key == 1)
        {
            system("cls");
            goto MENU;
        }
        else if (key == 0)
        {
            exit(0);
        }
        break;
    case 2:
        printf("Dang chay chuong trinh 2..\n");
        //Chuong trinh 1
        printf("Nhan 1: Quay lai\n");
        printf("Nhan 0: Thoat\n");
        printf("Vui long nhap phim:...\n");
        scanf("%d", &key);
        if (key == 1)
        {
            system("cls");

            goto MENU;
        }
        else if (key == 0)
        {
            exit(0);
        }
        break;
    case 3:
        printf("Dang chay chuong trinh 3..\n");
        //Chuong trinh 1
        printf("Nhan 1: Quay lai\n");
        printf("Nhan 0: Thoat\n");
        printf("Vui long nhap phim:...\n");
        scanf("%d", &key);
        if (key == 1)
        {
            system("cls");

            goto MENU;
        }
        else if (key == 0)
        {
            exit(0);
        }
        break;
    default:
        break;
    }

    return 0;
}
