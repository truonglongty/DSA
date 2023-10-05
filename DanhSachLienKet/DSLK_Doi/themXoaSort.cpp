#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

void duyet(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    if(*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp; 
}

void insert(node **head, int k, int x){
    int n = size(*head);
    if(k<1 || k>n+1){
        printf("Vi tri chen k hop le!\n");
        return;
    }
    if(k==1)
        pushFront(head, x);
    else if(k==n+1)
        pushBack(head, x);
    else{
        node *temp = *head;
        for(int i=1; i<k-1; i++)
            temp = temp->next;
        node *newNode = makeNode(x);
        newNode->next = temp->next;
        temp->next->prev = newNode; //temp->next: node thu k, temp->next->prev: truy cap vao prev
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void popFront(node **head){
    if(*head == NULL){
        printf("List rong!\n");
        return;
    }
    node *temp = *head;
    *head = temp->next;
    if(*head != NULL)   //truoc khi ngat ket noi phai check = temp->next != NULL
        (*head)->prev = NULL;//vi lo *head = NUll thi (*head)->prev loi vi truy cap vao vung nho k duoc phep; TH: list chi co 1 ptu
    free(temp);
}

void popBack(node **head){
    if(*head == NULL){
        printf("List rong!\n");
        return;
    }
    node *temp = *head;
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    //C1: tuong tu list don
    // while(temp->next->next != NULL)
    //     temp = temp->next;
    // node *last = temp->next;
    // temp->next = NULL;
    // free(last);
    
    //C2
    while(temp->next != NULL)//duyet toi node cuoi
        temp = temp->next;
    temp->prev->next = NULL;//temp->prev node ke cuoi, temp->prev->next dia chi node cuoi
    free(temp);
}

void erase(node **head, int k){
    int n = size(*head);
    if(k<1 || k>n){
        printf("Vi tri chen khong hop le!\n");
        return;
    }
    if(k==1)
        popFront(head);
    // else{
    //     node *temp = *head;
    //     for(int i=1; i<k-1; i++)
    //         temp = temp->next;
    //     node *del = temp->next;
    //     temp->next = del->next;
    //     if(del->next != NULL)
    //         del->next->prev = temp;
    //     free(del);
    // }
    else{
        node *temp = *head;
        for(int i=1; i<=k-1; i++)
            temp = temp->next;
        temp->prev->next = temp->next; //temp->prev: node k-1, temp->prev->next: phan next cua temp->prev
        if(temp->next != NULL)
            temp->next->prev = temp->prev; //temp->next: node k+1, temp->next->prev: phan prev cua temp->next
        free(temp);
    }
}

void duyetNguoc(node *head){
    if(head == NULL)
        return;
    while(head->next != NULL)
        head = head->next;
    while(head != NULL){
        printf("%d ",head->data);
        head = head->prev;
    }
}

void sort(node **head){
    for(node *i = *head; i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(min->data > j->data)
                min = j;
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

int main(){
    node *head = NULL;
    while(1){
		printf("------------Double Linked List Operation-------------\n");
		printf("1. Them vao cuoi: \n");
		printf("2. Them vao dau: \n");
		printf("3. Chen vao giua: \n");
		printf("4. Xoa dau: \n");
		printf("5. Xoa cuoi: \n");
		printf("6. Xoa giua: \n");
		printf("7. Sort: \n");
		printf("8. Show: \n");
		printf("9. Show nguoc: \n");
		printf("0. Thoat\n");
		printf("-----------------------------------------------------\n");
		printf("Nhap lua chon: ");
		int lc; scanf("%d",&lc);
		if(lc==1){
			printf("Nhap gia tri can them: ");
			int x; scanf("%d",&x);
			pushBack(&head,x);
		}
		else if(lc==2){
			printf("Nhap gia tri can them: ");
			int x; scanf("%d",&x);
			pushFront(&head,x);
		}
		else if(lc==3){
			printf("Nhap vi tri va gia tri can them: ");
			int k,x; scanf("%d%d",&k,&x);
			insert(&head,k,x);
		}
		else if(lc==4){
			popFront(&head);
		}
		else if(lc==5){
			popBack(&head);
		}
		else if(lc==6){
			printf("Nhap vi tri can xoa: ");
			int k; scanf("%d",&k);
			erase(&head,k);
		}
		else if(lc==7){
			sort(&head);
		}
 		else if(lc==8){
 			duyet(head);
 		}
 		else if(lc==9){
 		    duyetNguoc(head);
 		}
		else
			break;
	}
	return 0;
}
