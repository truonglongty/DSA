#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *left, *right;
};

typedef struct node node;
typedef struct node* tree;

node* makeNode(char x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* makeTree(node* p){
    char x;
    printf("Nhap Node: "); scanf("%c",&x);
    fflush(stdin);
    if(x == '0'){
        return NULL;
    }
    p = makeNode(x);
    printf("Nhap con trai cua %c: ",x);
    p->left = makeTree(p->left);
    printf("Nhap con phai cua %c: ",x);
    p->right = makeTree(p->right);
    return p;
}

void NLR(node* t){
    if(t != NULL){
        printf("%c ",t->data);
        NLR(t->left);
        NLR(t->right);
    }
}

int demNode(node* t){
    if(t == NULL)
        return 0;
    return 1 + demNode(t->left)+demNode(t->right); //1 la node root
}

int demNodeLa(node* t){
    if(t == NULL)
        return 0;
    else if(t->left == NULL && t->right == NULL)
        return 1;
    return  demNodeLa(t->left)+demNodeLa(t->right);
}

int max(int a, int b){
    return (a>b)?a:b;
}

void demNode2con(node* t){
    if(t == NULL)
        return;
    else if(t->left != NULL && t->right != NULL){
        printf("%c ",t->data);
    }
    demNode2con(t->left);
    demNode2con(t->right);
}

int height(node* t){
    if(t == NULL)
        return -1;
    return 1 + max(height(t->left),height(t->right));
}

int main()
{
    tree t = NULL;
    node* p = NULL;
    t = makeTree(p);
    printf("Duyet cay theo preOrder (NLR): \n");
    NLR(t);
    printf("\nSo node cua cay: %d\n",demNode(t));
    printf("So node la cua cay: %d\n",demNodeLa(t));
    printf("So node co 2 con : ");
	demNode2con(t);
    printf("\NChieu cao cua cay: %d",height(t));
    return 0;
}

