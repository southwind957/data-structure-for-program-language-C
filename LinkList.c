//
// Created by 南风知我意 on 2023/2/19.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct LinkNode{
    E element;
    struct LinkNode * next;
};

typedef struct LinkNode * Node;

void init(Node node){
    node->next=NULL;
}

_Bool insertLink(Node node,int index,E element){
    if (index < 1)return 0;
    while (--index){
        node = node->next;
        if (node == NULL)return 0;
    }
    Node node_ = malloc(sizeof (struct LinkNode));
    if (node_ == NULL)return 0;
    node_->element=element;
    node_->next=node->next;
    node->next=node_;
    return 1;
}

_Bool removeLink(Node head,int index){
    if(index < 1)return 0;
    while (--index){
        head = head->next;
        if (head == NULL)return 0;
    }
    if (head->next == NULL) return 0;
    Node temp = head->next;
    head->next=head->next->next;
    free(temp);
    return 1;
}

E * getList(Node head, int index){
    int  count=0;
    while (1){
        if (count>=index)break;
        if (head->next == NULL)return 0;
        head=head->next;
        count++;
    }
    return &head->element;
}

_Bool contain(Node head,E element){
    while (head->next){
        head=head->next;
        if (head->element == element)return 1;
    }
    return 0;
}

int getsize(Node head){
    int size=0;
    while (head->next){
        head=head->next;
        size++;
    }
    return size;
}

void display(Node node){
    while (node->next){
        node=node->next;
        printf("%d\t",node->element);
    }
    printf("\n");
}

int main(){
    struct LinkNode node;
    init(&node);
    for (int i = 1; i < 6; ++i) {
        insertLink(&node,i,i);
    }
    display(&node);
    removeLink(&node,2);
    display(&node);
    E * ans = getList(&node,4);
    printf("%d\n",*ans);
    _Bool a= contain(&node,6);
    printf("%d\n",a);
    printf("this linklist size is %d\n", getsize(&node));
//    display(&node);
}
