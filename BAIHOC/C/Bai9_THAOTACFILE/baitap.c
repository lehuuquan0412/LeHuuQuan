#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];  // Thay thế con trỏ bằng mảng ký tự để lưu tên
    uint16_t ID;
    uint32_t Year;
} Info;
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
int main() {
    FILE *file;
    file = fopen("StuInf.csv", "w");
    if (file == NULL) {
        printf("Không thể mở tệp StuInf.csv.\n");
        return 1;
    }
    fprintf(file,"NAME,ID,YEAROFBIRTH\n");
    int NUM;
    printf("Nhap so hoc sinh:");
    scanf("%d", &NUM);
    Info student[NUM];
    for (int i = 0; i < NUM; i++) {
        printf("Nhập tên hoc sinh thu %d: ", i + 1);
        scanf("%s", student[i].name);
        printf("Nhập ID hoc sinh thu %d: ", i + 1);
        scanf("%hu", &student[i].ID);
        printf("Nhập năm sinh hoc sinh thu %d: ", i + 1);
        scanf("%u", &student[i].Year);
        fprintf(file, "%s,%d,%d\n", student[i].name, student[i].ID, student[i].Year);
    }
    fclose(file);
    printf("Dữ liệu đã được lưu vào tệp StuInf.csv.\n");
    char buf[100];
    FILE * fp = fopen("StuInf.csv", "r");
    if (fp == NULL)
    {
        printf("Không thể mở tệp StuInf.csv.\n");
        return 1;
    }
    if (fgets(buf, sizeof(buf),fp) != NULL)
    {
        printf("s", buf);
    }
    
    qsort(buf, 10 , sizeof(Info *), compare_strings);
    for (int i = 0; i < 10; i++) {
        printf("%s\n", buf[i]);
    }    
    return 0;
}

