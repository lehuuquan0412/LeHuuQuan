#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Nodes{
    uint8_t value;
    struct Nodes *next;
}Nodes;

Nodes*createNode(uint8_t value){
    Nodes*node = (Nodes*)malloc(sizeof(Nodes));
    node->value = value;
    node->next = NULL;
    return node;
}


//Returns the value of the first element in the list.
uint8_t front(Nodes*ptr){
    return ptr->value;
}

//Returns the value of the last element in the list.
uint8_t back(Nodes*ptr){
    Nodes*temp = ptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->value;
}

//Adds a new element ‘g’ at the beginning of the list.
void push_front(Nodes**ptp,uint8_t value){
    Nodes*temp = *ptp;
    Nodes*new = temp;
    temp = createNode(value);
    temp->next = new;
    *ptp = temp;
}

//Adds a new element ‘g’ at the end of the list.
void push_back(Nodes**ptp,uint8_t value){
    if (*ptp == NULL)
    {
        *ptp = createNode(value);
    }else{
        Nodes*temp = *ptp;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Nodes*new = createNode(value);
        temp->next = new;
    }
    
}

//Removes the first element of the list, and reduces the size of the list by 1.
void pop_front(Nodes**ptp){
    Nodes*temp = *ptp;
    Nodes*new = temp->next;
    *ptp = new;
    free(temp);

}

//Removes the last element of the list, and reduces the size of the list by 1.
void pop_back(Nodes**ptp){
    Nodes*temp = *ptp;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

//Inserts new elements in the list before the element at a specified position.
void insert(Nodes**ptp,uint8_t locat,uint8_t value){
    Nodes*temp = *ptp;
    uint8_t i = 0;
    if (locat = 1)
    {
        push_front(ptp,value);
    }else{
        while (i < locat-2)
        {
            if (temp->next == NULL)
            {
                printf("Du lieu chua duoc khoi tao!!!!");
                temp = createNode(value);
            }else if(temp->next->next == NULL)
            {
                push_back(ptp,value);     
            }else{
            temp = temp->next;
            i++;
            }
        } 
        Nodes*new = temp->next;
        temp->next = createNode(value);
        temp->next->next = new;
    }
}

//Returns the number of elements in the list.
int size(Nodes**ptp){
    Nodes*temp =*ptp;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    } 
    return size;
}

//Returns an iterator pointing to the first element of the list.
void begin(){}

//returns an iterator pointing to the theoretical last element which follows the last element.
void end(){}

//Print all elements of list.
void printNode(Nodes**node){
    Nodes*temp = *node;
    int i = 1;
    if(size(node) == 0)
    printf("Invalid list!!!");
    while (temp != NULL)
    {
        printf("Gia tri thu %d la: %d\n",i,temp->value);
        temp = temp->next;
        i++;
    }
}

//Removes a single element or a range of elements from the list.
void erase(Nodes**ptp,uint8_t locat){
    Nodes*temp = *ptp;
    int i = 0;
    if (locat > size(ptp))
    {
        printf("Khong thoa dieu kien!!!");
    }
    

    while (i < locat-2)
    {
        temp = temp->next;
        i++;        
    }
    temp->next = temp->next->next;
}

//Assigns new elements to the list by replacing current elements and resizing the list.
void assign(Nodes**ptp,uint8_t locat,uint8_t value){
    Nodes*temp = *ptp;
    if (locat > size(ptp))
    {
        printf("Oversize of struct!!!");
    }
    
    if (locat == 1)
    {
        Nodes*new = temp->next;
        temp = createNode(value);
        temp->next = new;
        *ptp = temp;
    }else{
        int i = 0;
        while (i< locat-2)
        {
            temp = temp->next;
            i++;
        }
        Nodes*new1 = temp->next->next;
        temp->next = createNode(value);
        temp->next->next = new1;
    }
    
    
}
//Reverses the list.
void reverse(Nodes**ptp){
    Nodes*temp = *ptp;
    Nodes*head;
    Nodes*new = NULL;
    while (temp != NULL)
    {
        head = temp;
        temp = temp->next;
        head->next = new;
        new = head;
    }
    *ptp = head;

}

//Used to remove all the values from the list that correspond true to the predicate or condition given as a parameter to the function.
void clear(Nodes**ptp){
    printf("Delete datas...\n");
    Nodes*temp = *ptp;
    temp = NULL;
    *ptp = temp;
}

//Returns the data value stored in the node at that index position. 
uint8_t get_Data(Nodes**ptp,uint8_t index){
    int i = 0;
    if (index > size(ptp))
    {
        printf("Khong ton tai gia tri tai vi tri thu %d!!!\n",index);
    }else{
        Nodes*temp = *ptp;
        while (i<(index-1))
        {
            temp = temp->next;
            i++;
        }
        return temp->value;
    }  
}



int main(int argc, char const *argv[])
{
    Nodes*node;
    node = createNode(8);
    push_back(&node,56);
    push_back(&node,11);
    push_back(&node,24);
    push_back(&node,15);
    push_front(&node,28);
    push_back(&node,2);
    push_front(&node,2);
    pop_front(&node);
    pop_back(&node);
    insert(&node,1,6);
    erase(&node,3);
    assign(&node,4,16);
    assign(&node,1,32);

    printf("Kich thuoc mang: %d\n",size(&node));
    printNode(&node);
    
    reverse(&node);


    printf("Kich thuoc mang: %d\n",size(&node));
    printNode(&node);

    for (uint8_t i = 0; i < size(&node); i++)
    {
        printf("Gia tri thu %d la: %d\n",i+1,get_Data(&node,i));
    }
    
    return 0;
}
