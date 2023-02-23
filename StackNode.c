//
// Created by 南风知我意 on 2023/2/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct StackNode{
    E element;
    struct StackNode * next;
};

typedef struct StackNode * Node;

void  init(Node head){
    head->next=NULL;
}

_Bool push(Node head,E element){
    Node p= malloc(sizeof(struct StackNode));
    if(p == NULL)return 0;
    p->element=element;
    p->next=head->next;
    head->next=p;
    return 1;
}

_Bool isEmpty(Node head){
    return head->next==NULL;
}

int pop(Node head){
    if(isEmpty(head)){
        return 0;
    }else{
        int ele=head->next->element;
        Node temp=head->next;
        head->next=head->next->next;
        free(temp);
        return ele;
    }
}

void display(Node head){
    while (head->next){
        head=head->next;
        printf("%d\t",head->element);
    }
    printf("\n");
}

int main(){
    struct StackNode head;
    init(&head);
    for (int i = 1; i <= 5 ; ++i) {
        push(&head,i*100);
    }
    display(&head);
    printf("%d\n", pop(&head));
    display(&head);
}