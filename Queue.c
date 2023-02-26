//
// Created by 南风知我意 on 2023/2/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Queue{
    E * array;
    int capicity;
    int font,rear;
};

typedef struct Queue *Arrayqueue;

_Bool init(Arrayqueue queue){
    queue->array= malloc(sizeof(E)*10);
    if(queue->array == NULL)return 0;
    queue->capicity=10;
    queue->font=queue->rear=0;
    return 1;
}

_Bool reSize(Arrayqueue queue){
    int size=queue->capicity+(queue->capicity>>1);
    E * array_= realloc(queue->array,size);
    if(array_ == NULL)return 0;
    queue->array=array_;
    queue->capicity=size;
    return 1;
}

_Bool enqueue(Arrayqueue queue,E element){
    if(queue->rear == queue->capicity) reSize(queue);
    queue->array[queue->rear]=element;
    queue->rear++;
    return 1;
}

int outqueue(Arrayqueue queue){
    if(queue->font==queue->rear)return 0;
    int ans=queue->array[queue->font];
    queue->font++;
    return ans;
}

_Bool isEmpty(Arrayqueue queue){
    return  queue->rear==queue->font;
}

void display(Arrayqueue queue){
    int temp=queue->font;
    while (temp < queue->rear){
        printf("%d\t",queue->array[temp]);
        temp++;
    }
    printf("\n");
}

int main(){
    struct Queue queue;
    init(&queue);
    for (int i = 0; i < 13; ++i) {
        enqueue(&queue,i*100);
    }
    display(&queue);
    for (int i = 0; i < 10; ++i) {
        outqueue(&queue);
    }
    display(&queue);
    printf("%d", isEmpty(&queue));
}