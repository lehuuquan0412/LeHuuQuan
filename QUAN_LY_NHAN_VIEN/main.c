#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _MAX_LENGHT 100

//Khai báo kiểu dữ liệu của nhân viên.
typedef struct {
    int Id_employee;
    char* first_name;
    char* last_name;
    int salary;
}typeEmployee;

typedef struct Nodes{
    typeEmployee Employee;
    struct Nodes* next;
}Nodes;

// Tìm kiếm nhị phân
typedef struct Center_point{
    typeEmployee Employee;
    struct Center_point* left;
    struct Center_point* right;
}Center_point;

//Tạo mới 1 linked list.
Nodes* node_Init(int id, char* first_name, char* last_name, int salary){
    Nodes* temp = (Nodes*)malloc(sizeof(Nodes));
    temp->Employee.Id_employee = id;
    temp->Employee.first_name = strdup(first_name);
    temp->Employee.last_name = strdup(last_name);
    temp->Employee.salary = salary;
    temp->next = NULL;
    return temp;
}

void print_Space(int n){
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
    
}
//Trả về kích thước của list
int size_of_list(Nodes* ptr){
    int size_temp = 0;
    Nodes* temp = ptr;
    while (temp)
    {
        size_temp++;
        temp = temp->next;
    }
    return size_temp;
}
//Hàm hoán đổi vị trí giữa 2 node.
Nodes* swap(Nodes* a, Nodes* b){
    Nodes* temp = b->next;
    b->next = a;
    a->next = temp;
    return b;
}
//Xây dựng tìm kiếm nhị phân
Center_point *buildTree(Nodes *head, int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Nodes *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    Center_point *root = (Center_point *) malloc(sizeof(Center_point));
    root->Employee = node->Employee;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

Center_point *centerPoint(Nodes *head) {
    int size_list = size_of_list(head);
    return buildTree(head, 0, size_list - 1);
}

//Hàm thêm nhân viên vào list.
void add_employee(Nodes** ptp, char* first_name, char* last_name, int salary ){
    Nodes* temp = *ptp;
    int id = 1000;
    while (temp)
    {
        id++;
        temp = temp->next;
    }
    Nodes* new_Emp = node_Init(id, first_name, last_name, salary);

    if (!(*ptp))
    {
        *ptp = new_Emp;
        return;
    }

    temp = *ptp;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = new_Emp; 
}
//Hàm chỉnh sửa thông tin.
void edit_employee(Nodes* ptr, int id){
    Nodes* temp = ptr;
    while (temp)
    {
        if (temp->Employee.Id_employee == id)
        {
            printf("Enter first name: ");
            char first_name[_MAX_LENGHT];
            getchar();
            scanf("%[^\n]", first_name);
            free(temp->Employee.first_name);
            temp->Employee.first_name = strdup(first_name);

            printf("Enter last name: ");
            char last_name[_MAX_LENGHT];
            getchar();
            scanf("%[^\n]", last_name);
            free(temp->Employee.last_name);
            temp->Employee.last_name = strdup(last_name);

            printf("Enter salary: ");
            scanf("%d", &(temp->Employee.salary));
            return;
        }
        temp = temp->next;   
    }
    printf("No employee found!!!");    
}
//Hàm xóa nhân viên.
void delete_employee(Nodes** ptp, int id){
    Nodes* temp = *ptp;
    Nodes* prev = NULL;
    //Xóa nhân viên ở đầu danh sách.
    if (temp != NULL && temp->Employee.Id_employee == id)
    {
        *ptp = temp->next;
        free(temp->Employee.first_name);
        free(temp->Employee.last_name);
        free(temp);
        return;
    }

    while (temp != NULL && temp->Employee.Id_employee != id )
    {
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("No employee found!!!");
        return;
    }
    
    // Xóa node.
    prev->next = temp->next;
    free(temp->Employee.first_name);
    free(temp->Employee.last_name);
    free(temp);
}
//Hiển thị menu.
void display_list(Nodes* ptr){
    Nodes* temp = ptr;
    printf("\n       _____EMPLOYEE______\n\n");
    printf("ID          NAME                 SALARY\n");
    while (temp)
    {
        printf("%d",temp->Employee.Id_employee);
        print_Space(8);
        printf("%s %s",temp->Employee.first_name, temp->Employee.last_name);
        print_Space(20-strlen(temp->Employee.first_name) - strlen(temp->Employee.last_name));
        printf("%d\n", temp->Employee.salary);
        temp = temp->next;
    }
}

int display_menu() {
    printf("\n---- MENU ----\n");
    printf("1. ADD EMPLOYEES.\n");
    printf("2. ADJUST INFOMATION.\n");
    printf("3. DELETE EMPLOYEE.\n");
    printf("4. SEARCH EMPLOYEES BY NAME.\n");
    printf("5. FILTER AND SHOW EMPLOYEES WITH DUPLICATE NAMES.\n");
    printf("6. SHOW LIST OF EMPLOYEES.\n");
    printf("7. EXIT.\n");
    printf("ENTER YOUR CHOICE: ");
    
    int choice;
    scanf("%d", &choice);
    return choice;
}
//Lưu dữ liệu sau khi thao tác vào cơ sở dữ liệu csv.
void save_to_csv(Nodes* ptr, const char* filename){
    FILE*file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing!!!");
        return;
    }
    //Ghi tiêu đề cho file csv.
    fprintf(file,"ID,FirstName,LastName,Salary\n");

    // Ghi thông tin vào file csv.
    Nodes* temp = ptr;
    while (temp != NULL)
    {
        fprintf(file, "%d,%s,%s,%d\n",temp->Employee.Id_employee,temp->Employee.first_name,temp->Employee.last_name,temp->Employee.salary);
        temp = temp->next;
    }
    fclose(file);
}
//Tải dữ liệu từ file csv lên linked list.
void load_from_csv(Nodes** ptp, const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file for writing!!!");
        return;
    }

    char fisrtname_var[_MAX_LENGHT], lastname_var[_MAX_LENGHT];
    int id, salary;
    char tittle_csv[_MAX_LENGHT];
    if (fscanf(file, "%s\n",tittle_csv) == EOF)
    {
        printf("No data at here!!!");
        fclose(file);
        return;
    }
    while (fscanf(file, "\n%d,%[^,],%[^,],%d\n", &id, fisrtname_var, lastname_var, &salary) != EOF)
    {
        add_employee(ptp, fisrtname_var, lastname_var, salary);
    }
    fclose(file);
}
//Sắp xếp danh sách theo tên
void sort_employee_by_Name(Nodes** ptp){
    Nodes** temp = ptp;
    int count = size_of_list(*ptp);
    int i, j, swapped;
    char fullname_i[_MAX_LENGHT], fullname_j[_MAX_LENGHT];
 
    for (i = 0; i <= count; i++) {
 
        temp = ptp;
        swapped = 0;
 
        for (j = 0; j < count - i - 1; j++) {
 
            Nodes* p1 = *temp;
            Nodes* p2 = p1->next;
            sprintf(fullname_i,"%s%s",p1->Employee.last_name, p1->Employee.first_name);
            sprintf(fullname_j,"%s%s",p2->Employee.last_name, p2->Employee.first_name);

            if (strcmp(fullname_i, fullname_j) > 0)
            {
                *temp = swap(p1, p2);
                swapped = 1;
            }
 
            temp = &(*temp)->next;
        }
        if (swapped == 0)
            break;
    }
}


// Hàm tìm kiếm nhị phân.
Center_point *binarySearch(Center_point *root, const char*findname) {
    int vol = strlen(findname);
    int i = vol-1;
    while ((findname[i]) != ' ')
    {
        i--;
    }
    char last_name[_MAX_LENGHT], first_name[_MAX_LENGHT], full_name[_MAX_LENGHT], name_var[_MAX_LENGHT];
    strcpy(last_name, findname + i+1);
    strncpy(first_name, findname, i); 
    sprintf(full_name, "%s%s", last_name, first_name);
    sprintf(name_var, "%s%s", root->Employee.last_name, root->Employee.first_name);

    if (root == NULL) {
        return NULL;
    }

    if (strcmp(name_var, full_name) == 0) {
        return root;
    }

    if (strcmp(name_var, full_name) > 0) {
        return binarySearch(root->left, findname);
    }else {
        return binarySearch(root->right, findname);
    }
}
//Hàm lọc các nhân viên trùng tên.
void filter_duplicate_names(Nodes* head){
    Nodes* outer = head;
    while (outer) {
        Nodes* inner = outer->next;
        while (inner) {
            if (strcmp(outer->Employee.first_name, inner->Employee.first_name) == 0 && strcmp(outer->Employee.last_name, inner->Employee.last_name) == 0) {
                printf("ID: %d, First Name: %s, Last Name: %s, Salary: %d\n", inner->Employee.Id_employee, inner->Employee.first_name, inner->Employee.last_name, inner->Employee.salary);
            }
            inner = inner->next;
        }
        outer = outer->next;
    }
}
//Xóa mọi dữ liệu.
void free_list(Nodes** head){
    Nodes* current = *head;
    Nodes* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;  
        free(current->Employee.first_name);  
        free(current->Employee.last_name); 
        free(current); 
        current = nextNode; 
    }
    *head = NULL;
}

int main(int argc, char const *argv[])
{
    Nodes* list_staff = NULL;
    char first_name[_MAX_LENGHT], last_name[_MAX_LENGHT];
    int salary;
    int id_var;



    load_from_csv(&list_staff,"employee.csv");
    printf("size: %d\n", size_of_list(list_staff));
    display_list(list_staff);
    int choice;
    do
    {
        choice = display_menu();
        system("cls");
        switch (choice)
        {
        case 1:
            printf("Nhap ten dau nhan vien: ");
            scanf("%s",first_name);
            printf("Nhap ten cuoi cua nhan vien: ");
            scanf("%s",last_name);
            printf("Nhap muc luong cua nhan vien: ");
            scanf("%d", &salary);
            add_employee(&list_staff, first_name, last_name, salary);
            break;
        case 2:
            printf("Nhap ID cua nhan vien can sua: ");
            scanf("%d", &id_var);
            edit_employee(list_staff, id_var);
            break;
        case 3:
            printf("Nhap ID cua nhan vien can xoa: ");
            scanf("%d", &id_var);
            delete_employee(&list_staff, id_var);
            break;
        case 4:
        {
            char name_search[_MAX_LENGHT];
            printf("Nhap ten cua nhan vien can tim: ");
            getchar();
            scanf("%[^\n]", name_search);
            sort_employee_by_Name(&list_staff);
            Center_point* center = centerPoint(list_staff);
            Center_point* result = binarySearch(center, name_search);
            if (result)
            {
                printf("Result:\n");
                printf("ID: %d\nName: %s %s\nSalary: %d\n",result->Employee.Id_employee,result->Employee.first_name,result->Employee.last_name,result->Employee.salary);
            }else printf("Result: No employee.");
        }   
            break;
        case 5:{
            filter_duplicate_names(list_staff);
        } 
            break;
        case 6:{
            display_list(list_staff);
        }
            break;
        case 7:
            printf("Luu thay doi thanh cong!!!");
            save_to_csv(list_staff, "employee.csv");
            free_list(&list_staff);
            return 0;
        default:
            printf("Nhap sai, vui long nhap lai.");
            break;
        }
        system("pause");
    } while (1);
    
    return 0;
}
