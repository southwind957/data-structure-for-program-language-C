//
// Created by 南风知我意 on 2023/2/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack{
    E * array;
    int capacity;
    int  top;
};

typedef struct Stack *stack;

_Bool init(stack stack_){
    stack_->array= malloc(sizeof(int)*10);
    if(stack_->array == NULL)return 0;
    stack_->capacity=10;
    stack_->top=-1;
    return 1;
}

_Bool reStackSize(stack stack_){
    int capacity_ = stack_->capacity+(stack_->capacity>>1);
    E * array_ = realloc(stack_->array,sizeof(int)*capacity_);
    if(array_ == NULL)return 0;
    stack_->array=array_;
    stack_->capacity=capacity_;
    return 1;
}

_Bool push(stack stack_,E element){
    if(stack_->top+1==stack_->capacity)reStackSize(stack_);
    stack_->top++;
    stack_->array[stack_->top]=element;
    return 1;
}

_Bool isEmpty(stack stack_){
    return stack_->top==-1;
}

int pop(stack stack_){
    if(isEmpty(stack_)){
        return 0;
    }else{
        int ans=stack_->array[stack_->top];
        stack_->top--;
        return  ans;
    }
}

void display(stack stack_){
    int index=0;
    while (index <= stack_->top){
        printf("%d\t",stack_->array[index]);
        index++;
    }
    printf("\n");
}

int main(){
    struct Stack stack1;
    init(&stack1);
    for (int i = 1; i <= 3; ++i) {
        push(&stack1,i*100);
    }
    display(&stack1);
    printf("%d\n",pop(&stack1));
    display(&stack1);
}