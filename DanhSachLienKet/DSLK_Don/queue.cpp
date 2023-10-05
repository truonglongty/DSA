#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

//FIFO: them cuoi ra dau

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushBack(node **head, int x){ //node head nam ben trai khi dat queue nam ngang
    node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void popFront(node **head){
    if(*head == NULL)
        return;
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

void front(node *head){
    if(head == NULL){
        printf("EMPTY");
        return;
    }
    printf("%d",head->data);
}

int main() {
    node* head = NULL;
    int n; scanf("%d",&n);
    while(n--){
        char tt[100]; scanf("%s",tt); 
        if(strcmp(tt,"push")==0){
            int x; scanf("%d",&x);
            pushBack(&head,x);
        }
        else if(strcmp(tt,"pop")==0)
            popFront(&head);
        else if(strcmp(tt,"front")==0){
            front(head);
            printf("\n");
        }   
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

