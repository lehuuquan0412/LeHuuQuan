#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct{
    uint8_t front;
    uint8_t rear;
    uint8_t size;
    uint8_t *array;
}Queues;

//Init queues
void InitQueue(Queues*queue,uint8_t size){
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    queue->array = (uint8_t*)malloc(sizeof(uint8_t)*size);
}

//To check if the queue is empty
bool isEmpty(Queues*queue){
    if (queue->front == queue->rear)
    {
        return true;
    }else return false;
    
}

//To check whether the queue is full or not
bool isFull(Queues*queue){
    if (queue->front== queue->size-1 && queue->rear == 0)
    {
        return true;
    }else return false;  
}

//Removes the element from the frontal side of the queue
void dequeue(Queues*queue){
    if (isEmpty(queue))
    {
        printf("Du lieu rong, khong the xoa!!!\n");
    }else{
        uint8_t*temp = (queue->array)+sizeof(uint8_t);
        queue->array = NULL;
        queue->array = temp;
        queue->rear++;
    }
}

//It inserts elements to the end of the queue
void enqueue(Queues*queue,uint8_t value){
    if (isFull(queue))
    {
        printf("Ham day du lieu!!!\n");
    }else{
        queue->array[queue->front-queue->rear] = value;
        if (queue->front != queue->size-1)
        {
            queue->front++;
        }else queue->rear--; 
    }
}

//Pointer element responsible for fetching the first element from the queue
void Front(){}

//Pointer element responsible for fetching the last element from the queue
void Rear(){}

//Return sizes of queue.
uint8_t size(Queues*queue){
    return (queue->front-queue->rear);
}
//Print all elements in queue.
void printQueue(Queues*queue){
    for (int i = 0; i < queue->front-queue->rear; i++)
    {
        printf("Phan tu thu %d: %d\n",i+1,queue->array[i]);
    }
}



int main(int argc, char const *argv[])
{
    Queues queue;
    InitQueue(&queue,10);
    enqueue(&queue,2);
    enqueue(&queue,3);
    enqueue(&queue,24);
    enqueue(&queue,54);
    enqueue(&queue,12);
    enqueue(&queue,6);

    dequeue(&queue);
    
    printf("Kich thuoc: %d\n",size(&queue));
    printQueue(&queue);
    return 0;
}
