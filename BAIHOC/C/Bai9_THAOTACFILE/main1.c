#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100

typedef struct {        
    int id;  // giả định mỗi nhân viên có ID duy nhất
    char* first_name;
    char* last_name;
    float salary;
} Employee;

typedef struct Node {
    Employee data;
    struct Node* next;
} Node;

// Khởi tạo một node mới
Node* new_node(int id, char* first_name, char* last_name, float salary) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data.id = id;
    temp->data.first_name = strdup(first_name); // Cấp phát động cho chuỗi
    temp->data.last_name = strdup(last_name);
    temp->data.salary = salary;
    temp->next = NULL;
    return temp;
}

// Thêm một nhân viên vào cuối danh sách
void add_employee(Node** head, char* first_name, char* last_name, float salary) {
    Node* temp = *head;

    // Tạo một ID duy nhất giả định cho nhân viên (tăng dần từ 1)
    int id = 1;
    while (temp) {
        id = temp->data.id + 1;
        temp = temp->next;
    }

    Node* newEmp = new_node(id, first_name, last_name, salary);
    
    if (!(*head)) {
        *head = newEmp;
        return;
    }

    temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newEmp;
}

// Sửa thông tin nhân viên
void edit_employee(Node* head, int id) {
    Node* temp = head;
    while (temp) {
        if (temp->data.id == id) {
            printf("Nhập tên đầu mới: ");
            char first_name[MAX_NAME_LEN];
            scanf("%s", first_name);
            free(temp->data.first_name);
            temp->data.first_name = strdup(first_name);

            printf("Nhập tên cuối mới: ");
            char last_name[MAX_NAME_LEN];
            scanf("%s", last_name);
            free(temp->data.last_name);
            temp->data.last_name = strdup(last_name);

            printf("Nhập mức lương mới: ");
            scanf("%f", &(temp->data.salary));
            return;
        }
        temp = temp->next;
    }
    printf("Không tìm thấy nhân viên với ID: %d\n", id);
}

// Xóa một nhân viên
void delete_employee(Node** head, int id) {
    Node* temp = *head;
    Node* prev = NULL;

    // Nếu nhân viên cần xóa ở đầu danh sách
    if (temp != NULL && temp->data.id == id) {
        *head = temp->next;
        free(temp->data.first_name);
        free(temp->data.last_name);
        free(temp);
        return;
    }

    // Tìm nhân viên cần xóa
    while (temp != NULL && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Không tìm thấy nhân viên với ID: %d\n", id);
        return;
    }

    // Xóa node
    prev->next = temp->next;
    free(temp->data.first_name);
    free(temp->data.last_name);
    free(temp);
}

// Hiển thị danh sách nhân viên
void display_list(Node* head) {
    Node* temp = head;
    printf("\nDanh sách nhân viên:\n");
    while (temp) {
        printf("ID: %d, Tên đầu: %s, Tên cuối: %s, Lương: %.2f\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.salary);
        temp = temp->next;
    }
}

// Hiển thị menu và trả về lựa chọn
int display_menu() {
    printf("\n---- MENU ----\n");
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

    char first_name2[MAX_NAME_LEN], last_name2[MAX_NAME_LEN];
    int id;
    float salary;
    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &id, first_name2, last_name2, &salary) != EOF) {
        add_employee(head, first_name2, last_name2, salary);
    }

    fclose(file);
}

// Tìm kiếm nhân viên theo tên và hiển thị kết quả
void search_employee_by_name(Node* head, const char* name) {
    printf("\nKết quả tìm kiếm cho \"%s\":\n", name);
    Node* temp = head;
    while (temp) {
        for (int i = 0; i < strcmp; i++)
        {
            /* code */
        }
        
        if (strstr(temp->data.first_name, name) || strstr(temp->data.last_name, name)) {
            printf("ID: %d, Tên đầu: %s, Tên cuối: %s, Lương: %.2f\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.salary);
        }
        temp = temp->next;
    }
}

// Lọc và hiển thị những nhân viên có tên trùng lặp
// Chú ý: Chỉ sử dụng cho danh sách nhỏ vì phức tạp của nó là O(n^2)
void filter_duplicate_names(Node* head) {
    Node* outer = head;
    while (outer) {
        Node* inner = outer->next;
        while (inner) {
            if (strcmp(outer->data.first_name, inner->data.first_name) == 0 || strcmp(outer->data.last_name, inner->data.last_name) == 0) {
                printf("ID: %d, Tên đầu: %s, Tên cuối: %s, Lương: %.2f\n", inner->data.id, inner->data.first_name, inner->data.last_name, inner->data.salary);
            }
            inner = inner->next;
        }
        outer = outer->next;
    }
}

void free_list(Node** head) {
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

int main() {
    Node* head = NULL; // Khởi tạo đỉnh của danh sách liên kết

    // Tải dữ liệu từ tệp CSV vào danh sách liên kết
    load_from_csv(&head, "filename.csv");
    printf("Dữ liệu đã được tải từ tệp CSV:\n");
    display_list(head);
    char first_name[MAX_NAME_LEN], last_name[MAX_NAME_LEN];
    float salary;
    int choice;
    do {
        choice = display_menu();
        switch (choice) {
            case 1:
                // Nhập dữ liệu nhân viên và thêm vào danh sách.
                printf("Nhập tên đầu: ");
                scanf("%s", first_name);
                printf("Nhập tên cuối: ");
                scanf("%s", last_name);
                printf("Nhập mức lương: ");
                scanf("%f", &salary);
                add_employee(&head, first_name, last_name, salary);
                break;
            case 2:
                // Chọn nhân viên theo ID và chỉnh sửa thông tin.
                printf("Nhập ID của nhân viên cần sửa: ");
                int id_to_edit;
                scanf("%d", &id_to_edit);
                edit_employee(head, id_to_edit);
                break;
            case 3:
                // Chọn nhân viên theo ID và xóa khỏi danh sách.
                printf("Nhập ID của nhân viên cần xóa: ");
                int id_to_delete;
                scanf("%d", &id_to_delete);
                delete_employee(&head, id_to_delete);
                break;
            case 4:
            {
                // Tìm nhân viên theo tên.
                char name_search[MAX_NAME_LEN];
                printf("Nhập tên nhân viên cần tìm: ");
                scanf("%s", name_search);
                search_employee_by_name(head, name_search);
                break;
            }
            case 5:
            {
                // Lọc và hiển thị nhân viên có tên trùng lặp.
                filter_duplicate_names(head);
                break;
            }
            case 6:
            {
                // Hiển thị danh sách nhân viên.
                display_list(head);
                break;
            }
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
    }while(1);

    //return 0;
}