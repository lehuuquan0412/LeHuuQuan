#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    uint8_t capacity;
    uint8_t *array;
    uint8_t size;
}Stacks;

//Begin a new stack.
void InitStack(Stacks*stack,uint8_t size){
    stack->capacity = -1;
    stack->size = size;
    stack->array = (uint8_t*)malloc(sizeof(uint8_t)*size);
}

//Returns whether the stack is empty.
bool empty(Stacks*stack){
    if (stack->capacity == -1)
    {
        return true;
    }else return false;
}
////Returns whether the stack is full.
bool full(Stacks*stack){
    if(stack->size == stack->capacity+1){
        return true;
    }else return false;
}

//Returns the size of the stack.
uint8_t size(Stacks stack){
    return (stack.capacity + 1);
}

//Returns a reference to the top most element of the stack.
uint8_t top(Stacks*stack){
    return stack->array[stack->capacity];
}

//Adds the element ‘g’ at the top of the stack.
void push(Stacks*stack,uint8_t value){
    if (full(stack))
    {
        printf("Day du lieu, khong the them!!!\n");
    }else{
        stack->array[++(stack->capacity)] = value;
    }
}

//Deletes the most recent entered element of the stack.
void pop(Stacks*stack){
    if (empty(stack))
    {
        printf("Du lieu rong, khong the xoa!!!\n");
    }else{
        stack->array[(stack->capacity)--] = '\0';
    }
}

//Clear memory stack.
void clear(Stacks*stack){
    free(stack->array);
}

int main(int argc, char const *argv[])
{
    Stacks stack;
    InitStack(&stack,10);
    push(&stack,2);
    push(&stack,3);
    pop(&stack);
    push(&stack,5);
    push(&stack,8);
    push(&stack,1);

    printf("Kich thuoc: %d\n",size(stack));
    return 0;
}
