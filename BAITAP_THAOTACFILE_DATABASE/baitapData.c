#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

#define SWAP(type,x,y) do{type temp = x;x=y;y = temp;}while(0)

bool isEqual(const char arr1[],const char arr2[]){
    while(*arr1 == *arr2){
        if (*arr1 == '\0')
        {
            return true;
        }
        arr1++;
        arr2++;
    }
    if (*arr1 > *arr2)
    {
        return true;
    }
    return false;
}

typedef struct 
{
    char *ptr;
    uint8_t length;
}words;

typedef struct 
{
    char *ten;
}finalName;


void *splitString(char *string){
    uint8_t size = 1;
    char *ptr = string;
    while (*ptr != '\0')
    {
        if (*ptr == ' ')size++;
        ptr++;
    }

    words *array = (words*)malloc(sizeof(words)*size);
    uint8_t index = 0;
    uint8_t count = 1;
    array[index].ptr = string;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            array[index].length = count;
            count = 1;
            string++;
            array[++index].ptr = string;
        }else{
            count++;
            string++;
        }
        
    }
    array[index].length = count;

    char*y = array[size-1].ptr;
    return y;
}

typedef struct{
    char name[20];
    char gender[10];
    uint16_t yearofBirth;
    uint16_t ID;
}typeStudent;

int dodaiString(char *x){
    int dodai = 0;
    for (int i = 0; x[i] !='\0'; i++)
    {
        dodai++;
    }
    return dodai;
}

int dodaiNum(int x){
    int dodai;
    double f = x/10 ;
    do
    {
        dodai++;
        f = f/10;
    } while (f > 1);
    
    return dodai;
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

void inputInfo() {
    int n;
    printf("Nhap so sinh vien:");
    scanf("%d",&n);

    typeStudent *students = (typeStudent *)malloc(n * sizeof(typeStudent));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
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
        scanf("%d", &students[i].ID);

    }
    
    

    FILE *file = fopen("sinhvien.csv", "w");
    if (file == NULL) {
        printf("Khong the mo file!!!");
        free(students);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%s,%d,%d\n", students[i].name, students[i].gender, students[i].yearofBirth, students[i].ID);
    }

    fclose(file);
    free(students);
}

void outputInfo(){
    FILE*file = fopen("sinhvien.csv","r");
    if (file == NULL)
    {
        printf("Khong doc duoc du lieu!!!");
    }

    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d",&n);

    typeStudent *students = (typeStudent *)malloc(n * sizeof(typeStudent));
    char title1[20];
    char title2[10];
    char title3[15];
    char title4[10];

    fscanf(file,"%[^,],%[^,],%[^,],%[^\n]",title1,title2,title3,title4);

    printf("%s",title1);

    printf("%*s",30-dodaiString(title1),title2);
    
    printf("%*s",30-dodaiString(title2),title3);
    
    printf("%*s",30-dodaiString(title3),title4);

    for (int i = 0; i < n; i++)
    {
        fscanf(file,"\n%[^,],%[^,],%d,%d",&students[i].name,students[i].gender,&students[i].yearofBirth,&students[i].ID);
       
    }

    //Sap xep lai thu tu theo ten.
    

    for (int i = 0; i < n-1; i++)
    {
        
        for (int j = i+1; j < n; j++)
        {
            
            if (isEqual(splitString(students[i].name),splitString(students[j].name)))
            {
                
                SWAP(typeStudent,students[i],students[j]);
                
            }
            
        }
        
    }
     

    for (int i = 0; i < n; i++)
    {
        printf("\n%s",students[i].name);
        printf("%*s",30-dodaiString(students[i].name),students[i].gender);
        printf("%*d",20-dodaiString(students[i].gender),students[i].yearofBirth);
        printf("%*d",24-dodaiNum(students[i].yearofBirth),students[i].ID);
    }
    
    free(students);
    fclose(file);
}

int main(int argc, char const *argv[])
{
    outputInfo();
    return 0;
}
