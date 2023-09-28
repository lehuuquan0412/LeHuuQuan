// #include <stdio.h>
// #include <stdint.h> 
// #include <string.h>


// int main(int argc, char const *argv[])
// {
//     char Name[100];
//     uint32_t ID;
//     uint16_t YearOfBirth;
//     FILE * file = fopen("StudentInfo.csv", "r");
//     char buf[1000];
//     while (fgets(buf, sizeof(buf), file) != NULL)
//     {
//         int len = strlen(buf);
//          for (int i = 0; i < len; i++) {
//         if (buf[i] == ',') {
//             // Di chuyển các ký tự sau dấu ',' lên để che dấu ','
//             for (int j = i; j < len - 1; j++) {
//                 buf[j] = buf[j + 1];
//             }
//             len--; // Giảm độ dài của chuỗi đi 1
//             i--;
//                 }
//     }
//         //  sscanf(buf, "%f %s %f", &ID, Name, &YearOfBirth);
//          printf("%s", buf);
//     }
//     fclose(file);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Struct để lưu trữ một dòng dữ liệu CSV
typedef struct {
    char name[100]; // Điều chỉnh kích thước tên theo nhu cầu
} Record;

// Hàm so sánh cho qsort
int compare_names(const void *a, const void *b) {
    return strcoll(((Record *)a)->name, ((Record *)b)->name);
}

int main() {
    setlocale(LC_ALL, "C"); // Sử dụng ngôn ngữ C để sắp xếp

    FILE *input_file = fopen("StudentInfo.csv", "r");
    if (!input_file) {
        perror("Không thể mở file đầu vào"); //ghi lai loi va luu vao bien errno
        return 1;
    }

    FILE *output_file = fopen("StudentInfoAl.csv", "w");
    if (!output_file) {
        perror("Không thể tạo file đầu ra");
        fclose(input_file);
        return 1;
    }

    char line[1024]; // Điều chỉnh kích thước dòng theo nhu cầu
    Record records[100]; // Điều chỉnh số lượng bản ghi theo nhu cầu
    int record_count = 0;

    // Đọc dữ liệu từ file CSV và lưu vào mảng records
    while (fgets(line, sizeof(line), input_file)) {
        sscanf(line, "%99[^,\n]", records[record_count].name);
        record_count++;
    }

    // Sắp xếp mảng records theo thứ tự alphabet
    qsort(records, record_count, sizeof(Record), compare_names);

    // Ghi mảng records đã sắp xếp vào file CSV đầu ra
    for (int i = 1; i < record_count; i++) {
        fprintf(output_file, "%s\n", records[i].name);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Dữ liệu đã được sắp xếp và ghi vào sorted_output.csv.\n");

    return 0;
}
