#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> // Để sử dụng hàm tolower và toupper

#define MAX 100


typedef struct{
    int id;
    char * first_name;
    char * last_name;
    float salary;
}Info;

typedef struct Node{
    Info data;
    struct Node * next;
}Node;

typedef struct Count{
    char name[MAX];
    int freq;
    Info repeat_nv;
}Count;

void * createNode(int id, char * first_name, char * last_name, float salary){
    Node * temp =(Node * )malloc(sizeof(Node)*1);
    temp->data.id = id;
    temp->data.first_name = strdup(first_name);
    temp->data.last_name = strdup(last_name);
    temp->data.salary = salary;
    temp->next = NULL;
    return temp;  
}

//Them nhan vien
void add(Node ** ptp, char * first_name, char * last_name, float salary){
    if (*ptp == NULL)
    {
        *ptp = createNode(1, first_name, last_name, salary);
    }else{
        int temp_id = 1;
        Node * temp = *ptp;
        while (temp->next != NULL)
        {
            temp_id = temp->data.id + 1;
            temp = temp->next;
        }
        temp->next = createNode(temp_id + 1, first_name, last_name, salary);
    }    
}

//Hien thi danh sach nhan vien
void display(Node ** ptp){
    printf("Danh sach nhan vien:\n");
    printf("%-5s%-20s%-10s%-s\n","ID","Ho & ten dem","Ten","Muc Luong");
    if (*ptp == NULL)
    {
        printf("---Danh sach rong---\n");
        return;
    }else{
        Node * temp = *ptp;
        while (temp) {
        printf("%-5d%-20s%-10s%-.2f\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.salary);
        temp = temp->next;
        }
    }   
}
    
//Sua thong tin nhan vien
void edit(Node ** ptp, int id){
    Node * temp = *ptp;
    while (temp->data.id != id)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Khong tim thay nhan vien co ID %d\n", id);
            return;
        }  
    }
    printf("Nhap ho va ten dem moi: ");
    getchar();
    scanf("%[^\n]", temp->data.first_name);

    printf("Nhap ten moi: ");
    scanf("%s", temp->data.last_name);

    printf("Nhap muc luong moi: ");
    scanf("%.2f", &temp->data.salary);
    
    printf("Sua thong tin nhan vien thanh cong\n");
    
}    

//Xoa nhan vien
void delete(Node ** ptp, int id){
    Node * temp = *ptp;
    Node * prev = NULL;
    while (temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Khong tim thay nhan vien co ID: %d\n", id);
        return;
    }
    if (prev == NULL)
    {
        *ptp = temp->next;
    }else  prev->next = temp->next;
    // Giải phóng bộ nhớ cho first_name và last_name
    free(temp->data.first_name);
    free(temp->data.last_name);
    free(temp);
    printf("Da xoa nhan vien co ID: %d\n", id);
}

//Tim kiem nhan vien theo ten
void find_name(Node ** ptp, char * name){
    Node * temp = *ptp;
    while (temp != NULL)
    {   
        char  temp_name[MAX];
        for (int i = 0; i < MAX; i++)
        {
            temp_name [i] = temp->data.last_name[i];
        } 
        for (int i = 0; i < MAX; i++)
        {
            name[i] = tolower(name[i]);
            temp_name[i] = tolower(temp_name[i]);
        }
        
        if (strcmp(temp_name,name) == 0)
        {
            printf("%-5d%-20s%-10s%-f\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.salary);
        }
        temp = temp->next;
    }
}

//Loc va hien thi nhan vien co ten trung lap
void filter(Node ** ptp){
    //Dem so luong nhan vien
    Node * temp = *ptp;
    Node * temp1 = *ptp;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    printf("So luong nhan vien: %d\n", count);
    Count nv[MAX];
    for (int i = 0; i < count; i++)
    {   
        char last_name[MAX];
        for (int j = 0; j < MAX; j++)
        {
            last_name[j] = temp1->data.last_name[j];
        }
        for (int k = 0; k < i; k++)
        {
            if (strcmp(last_name,nv[k].name) == 0)
            {
                strcpy(nv[i].name, last_name);
                nv[i].repeat_nv = temp1->data;
                goto JUMP;
            }
        }
        nv[i].repeat_nv = temp1->data;
        strcpy(nv[i].name, last_name);
        nv[i].freq = 0;
        for (Node * p = *ptp; p != NULL; p = p->next)
        {   
            if (strcmp(p->data.last_name, temp1->data.last_name) == 0)
            {
                nv[i].freq ++; 
            }   
        }
        printf("So nhan vien co ten '%s': %d\n", nv[i].name, nv[i].freq);
        JUMP:
        temp1 = temp1->next;
    }
    for (int i = 0; i < count; i++)
    {
        for (int k = 0; k < i; k++)
            {
                if (strcmp(nv[i].name,nv[k].name) == 0)
                {
                    goto EXIT;
                }              
            }
        printf("Danh sach nhan vien co ten '%s':\n", nv[i].name);
        printf("%-5s%-20s%-10s%-s\n","ID","Ho & ten dem","Ten","Muc Luong");
        for (int j = i; j < count; j++)
        {   
            if (strcmp(nv[j].name,nv[i].name) == 0)
            {
                printf("%-5d%-20s%-10s%-f\n", nv[j].repeat_nv.id,nv[j].repeat_nv.first_name, nv[j].repeat_nv.last_name, nv[j].repeat_nv.salary);
                
            }
        }
    EXIT:
    }
    
    
    
}

// Lưu danh sách nhân viên vào tệp CSV
void save_to_csv(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Lỗi mở tệp để ghi.\n");
        return;
    }

    // Ghi tiêu đề cho file CSV (tùy vào cấu trúc của bạn)
    fprintf(file, "ID,FirstName,LastName,Salary\n");

    // Duyệt danh sách và ghi thông tin ra file
    Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d,%s,%s,%.2f\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.salary);
        temp = temp->next;
    }

    fclose(file);
}

// Tải dữ liệu từ tệp CSV vào danh sách liên kết
void load_from_csv(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở tệp %s để đọc\n", filename);
        return;
    }

    char first_name2[MAX], last_name2[MAX];
    int id;
    float salary;
    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &id, first_name2, last_name2, &salary) != EOF) {
        add(head, first_name2, last_name2, salary);
    }
}
//Giai phong cac node
void free_list(Node** head) 
{
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;  // lưu tham chiếu tới node kế tiếp
        free(current->data.first_name);  // giải phóng bộ nhớ của tên đầu
        free(current->data.last_name);  // giải phóng bộ nhớ của tên cuối
        free(current);  // giải phóng bộ nhớ của node hiện tại
        current = nextNode;  // chuyển tới node kế tiếp
    }

    *head = NULL;  // đặt lại head thành NULL
}

//In ra MENU
int Choice(){
    printf("/----------MENU---------/\n");
    printf("1. Thêm nhân viên\n");
    printf("2. Sửa nhân viên\n");
    printf("3. Xóa nhân viên\n");
    printf("4. Tìm kiếm nhân viên theo tên\n");
    printf("5. Lọc và hiển thị nhân viên có tên trùng lặp\n");
    printf("6. Hiển thị danh sách nhân viên\n");
    printf("7. Lưu và thoát\n");
    printf("Lựa chọn của bạn: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}


int main(int argc, char const *argv[])
{
    Node * head = NULL;
    // Tải dữ liệu từ tệp CSV vào danh sách liên kết
    load_from_csv(&head, "filename.csv");
    printf("Dữ liệu đã được tải từ tệp CSV:\n");
    display(&head);
    char first_name[MAX], last_name[MAX];
    float salary;
    do
    {
        int choice = Choice();
        switch (choice)
    {
    case 1:
        // Nhập dữ liệu nhân viên và thêm vào danh sách.
        printf("Nhập tên đầu: ");
        getchar();
        scanf("%[^\n]", first_name);
        printf("Nhập tên cuối: ");
        scanf("%s", last_name);
        printf("Nhập mức lương: ");
        scanf("%.2f", &salary); 
        add(&head, first_name, last_name, salary);
        break;
    case 2:
        display(&head);
        printf("Nhap ID nhan vien can sua thong tin: ");
        int id_edit;
        scanf("%d", &id_edit);
        edit(&head, id_edit);
        break;
    case 3:
        display(&head);
        printf("Nhap ID nhan vien can xoa: ");
        int id_delete;
        scanf("%d", &id_delete);
        delete(&head, id_delete);
        break;
    case 4:
        printf("Nhap ten nhan vien can tim: ");
        char name[MAX];
        scanf("%s", name);
        printf("Thong tin nhan vien co ten %s:\n", name);
        printf("%-5s%-20s%-10s%-s\n","ID","Ho & ten dem","Ten","Muc Luong");
        find_name(&head, name);
        break;
    case 5:
        filter(&head);
        break;
    case 6:
        display(&head);
        break;
    case 7:
        printf("Lưu thành công!!!.\n");
        // Lưu dữ liệu vào tệp CSV và thoát chương trình.
        save_to_csv(head, "filename.csv");
        free_list(&head);  // giải phóng bộ nhớ cho danh sách
        exit(1);
    default:
        printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        break;
    }
    } while (1);
    
    
    return 0;
}
