//
// Created by 南风知我意 on 2023/2/16.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

//设置顺序表
struct List{
    E * array;
    int capacity;
    int size;
};

typedef struct  List * ArrayList;

//初始化顺序表
int initList(ArrayList list){
    list->array = malloc(sizeof (E) * 10);
    if (list->array==NULL) return 0;
    list->capacity = 10;
    list->size=0;
    return 1;
}

//扩充容量
_Bool reArrraySize(ArrayList list,E element,int size){
    int capacity_=list->size+(list->size*size);
    E * Array_= realloc(list->array,capacity_ * sizeof(E));
    if (Array_ == NULL) return 0;
    list->array = Array_;
    list->capacity=capacity_;
    return 1;
}

//在某个位置插入
_Bool insertArray(ArrayList list,E element,int index){
    if(index < 1 || index > list->size + 1) return 0;
    if (list->size == list->capacity) reArrraySize(list,element,2);

    for (int i = list->size; i > index-1 ; --i)
        list->array[i]=list->array[i-1];
    list->array[index-1]=element;
    list->size+=1;
    return 1;
}

//删除某个位置的数据
_Bool reduceArray(ArrayList list,int index){
    if (index < 1 || index > list->size) return 0;
    for (int i = index-1; i < list->size-1; ++i) {
        list->array[i]=list->array[i+1];
    }
    list->size-=1;
    return 1;
}

//获取长度
int getsize(ArrayList list){
    return list->size;
}

//获取某个位置上的数值
E * getIndex(ArrayList list,int index){
    if(index < 1 || index > list->size) return  NULL;
    return &list->array[index-1];
}

//在顺序表中查找某个数
int findIndex(ArrayList list,E element){
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i;
    }
    return  -1;

}

//打印显示整个线性表
void disPlay(ArrayList list){
    for (int i = 0; i < list->size; ++i) {
        printf("%d\t",list->array[i]);
    }
    printf("\n");
}

int main(){
    struct List list;
    if (initList(&list)){
        for (int i = 0; i < 30; ++i) {
            insertArray(&list, 555+i, 1);
            disPlay(&list);
        }
        printf("The numbers capacity is  %d\n",list.capacity);
        for (int i = 0; i < 10; ++i) {
            reduceArray(&list,1);
            disPlay(&list);
        }
    }else{
        printf("初始化失败!");
    }
}