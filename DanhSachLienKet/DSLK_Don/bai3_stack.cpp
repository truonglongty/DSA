#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(node **head, int x){ //pushFront
    node* newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pop(node **head){ //popFront
    if(*head == NULL)
        return;
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

void show(node *head){
    if(head == NULL){
        printf("EMPTY\n");
    }
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

// Hàm lay phan tu ma khong loai bo no
int top(node *head) {
    if (head == NULL) {
        printf("Stack rong.\n");
        return -1; // Giá tri mac dinh khi stack rong
    }
    return head->data;
}

int main(){
    node *head = NULL;
    int n; scanf("%d",&n);
    while(n--){
        char tt[100];  scanf("%s",tt);
        if(strcmp(tt,"push")==0){
            int x; scanf("%d",&x);
            push(&head,x);
        }
        else if(strcmp(tt,"pop")==0)
            pop(&head);
        else if (strcmp(tt, "top") == 0) {
		    int topElement = top(head);
		    if (topElement != -1) {
		        printf("Ph?n t? d?nh c?a stack: %d\n", topElement);
		    }
		}		
        else {
            show(head);
            printf("\n");
        }
    }
}
