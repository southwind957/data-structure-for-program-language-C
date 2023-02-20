//
// Created by 南风知我意 on 2023/2/20.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;


struct LinkNode{
    E element;
    struct LinkNode * next;
    struct LinkNode * prev;
};

typedef struct LinkNode * Node;

void init(Node node){
    node->next=NULL;
    node->prev=NULL;
}

_Bool insertLink(Node head,int index,E element){
    if (index < 1)return 0;
    while (--index){
        head = head->next;
        if (head == NULL)return 0;
    }
    Node node_ = malloc(sizeof (struct LinkNode));
    if (node_ == NULL)return 0;
    node_->element=element;
    if (head->next){
        node_->next=head->next;
        head->next->prev=node_;
    } else{
        node_->next=NULL;
    }
    head->next=node_;
    node_->prev=head;
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
    if (head->next->next){
        Node middle=head->next->next;
        head->next=middle;
        middle->prev=head;
    } else{
        head->next=NULL;
    }
    free(temp);
    return 1;
}

_Bool contain(Node head,E element){
    while (head->next){
        head=head->next;
        if (element==head->element){
            return 1;
        }
    }
    return 0;
}

E * getIndex(Node head,int index){
    int count=1;
    while (count <= index){
        head=head->next;
        count++;
    }
    return &head->element;
}

int getSize(Node head){
    while (head->next) head=head->next;
    int size=0;
    while (head->prev){
        size++;
        head=head->prev;
    }
    return size;
}

void displayNext(Node head){
    while (head->next){
        head=head->next;
        printf("%d\t",head->element);
    }
    printf("\n");
}

void displayPrev(Node head){
    while (head->next) head=head->next;
    while (head->prev){
        printf("%d\t",head->element);
        head=head->prev;
    }
    printf("\n");
}

int main(){
    struct LinkNode head;
    init(&head);
    for (int i = 0; i < 5; ++i) {
        insertLink(&head,i,i*2);
    }
//    displayNext(&head);
//    displayPrev(&head);
    removeLink(&head,2);
    displayNext(&head);
    printf("%d\n", *getIndex(&head,3));
    printf("%d\n", getSize(&head));
}
