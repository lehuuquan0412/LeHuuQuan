#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct{
    char name[30];
    char gender[10];
    uint16_t yearofBirth;
    uint16_t Id;
}Students;

typedef struct node{
    Students student;
    struct node *next;
}Nodes;

static Nodes*node;

Nodes*createNodes(Students stu){
    node =(Nodes*)malloc(sizeof(Nodes));
    node->student = stu;
    node->next = NULL;
    return node;
}

void pushBack(Nodes**ptp,Students stu){
    Nodes*temp = *ptp;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Nodes*new = (Nodes*)malloc(sizeof(Nodes));
    new->student = stu;
    new->next = NULL;
    temp->next = new;
}

void deleteT(char *x){
    int n = 0;
    for (int i = 0; x[i] !='\0'; i++)
    {
        n++;
    }

    if (x[n-1] == '\n')
    {
        x[n-1] = '\0';
    }
}

void newDatabase(){
    FILE*file = fopen("sinhvien.csv","w");
    fprintf(file,"Name,Gender,Year of birth,Student ID\n");
    fclose(file);
}

void Insert(){
    int n;
    printf("Nhap so sinh vien:");
    scanf("%d",&n);

    Students *students = (Students*)malloc(n*sizeof(Students));
    if (students == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cua sinh vien %d\n", i + 1);
        getchar();

        printf("Nhap ten cua sinh vien:");
        fgets(students[i].name,sizeof(students[i].name),stdin);
        deleteT(students[i].name);
        
        printf("Nhap gioi tinh cua sinh vien:");
        scanf("%s",students[i].gender);
        getchar();

        printf("Nhap nam sinh cua sinh vien:");
        scanf("%d", &students[i].yearofBirth);

        printf("Nhap MSSV cua sinh vien:");
        scanf("%d", &students[i].Id);

    }
    
    

    FILE *file = fopen("sinhvien.csv", "a");
    if (file == NULL) {
        printf("Khong the mo file!!!");
        free(students);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file,"%s,%s,%d,%d\n", students[i].name, students[i].gender, students[i].yearofBirth, students[i].Id);
    }

    fclose(file);
    free(students);
}

void InitDatabase(){
    FILE*file = fopen("sinhvien.csv","r");
    char title1[20];
    char title2[10];
    char title3[15];
    char title4[10];

    fscanf(file,"%[^,],%[^,],%[^,],%[^\n]",title1,title2,title3,title4);
    Students stu;
    fscanf(file,"\n%[^,],%[^,],%d,%d",stu.name,stu.gender,&stu.yearofBirth,&stu.Id);
    createNodes(stu);
    
    while(fscanf(file,"%[^,],%[^,],%d,%d",stu.name,stu.gender,&stu.yearofBirth,&stu.Id) != EOF){
        pushBack(&node,stu);
    }
}

void Update(uint8_t Id,Students studentCharge){
    Nodes*temp = node;
    while((temp)-> next && temp->student.Id != Id){
        (temp) =(temp)->next;
    }
    if((temp)->next = NULL){
        printf("KHONG TON TAI SINH VIEN!");
    }
    (temp)->student = studentCharge;
}

void Delete(uint8_t Id){
    Nodes*temp = node;
    while((temp)-> next && (temp)->next->student.Id != Id){
        (temp) =(temp)->next;
    }
    if((temp)->next = NULL){
        printf("KHONG TON TAI SINH VIEN!");
    }
    (temp)->next = (temp)->next->next;
}

int main(int argc, char const *argv[])
{
    InitDatabase();
    return 0;
}
