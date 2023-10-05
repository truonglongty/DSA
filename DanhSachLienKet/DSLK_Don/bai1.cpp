#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    char msv[20];
    char hoten[50];
    double gpa;
  struct node *next;
};

typedef struct node node;

node *makeNode(){
    node *newNode = (node*)malloc(sizeof(node));
    getchar();
    gets(newNode->msv);
    gets(newNode->hoten);
    scanf("%lf",&(newNode->gpa));
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        printf("%s %s %.2lf\n",head->msv,head->hoten,head->gpa);
        head = head->next;
    }
}

int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void pushFront(node **head){
    node *newNode = makeNode();
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head){
    node *newNode = makeNode();
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

void insert(node **head, int k){
    int n = size(*head);
    if(k<1 || k>n+1)
        return;
    if(k==1)
        pushFront(head);
    else if(k==1)
        pushBack(head);
    else{
        node *temp = *head;
        for(int i=1; i<k-1; i++)
            temp = temp->next;
        node *newNode = makeNode();
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main()
{
    node *head = NULL;
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        if(x==1){
            pushFront(&head);
        }
        else if(x==2){
            pushBack(&head);
        }
        else{
            int k; scanf("%d",&k);
            insert(&head,k);
        }
    }
    duyet(head);
    return 0;
}

