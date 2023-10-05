#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
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
		cnt++;
		head = head->next;
	}
	return cnt;
}

node* makeNode(int x){
	//cap phat dong 1 node->cho con tro newNode quan ly cai cap phat do
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//tuonng tuong: moi node trong dslk da duoc quan ly boi con tro kieu head roi
//nen muon thay doi dlsk truyen vao con tro cap 2
void pushFront(node **head, int x){ //ham nay lam thay doi dslk -> dung con tro cap 2
	node *newNode = makeNode(x);
	newNode->next = (*head);//*head: toan tu giai tham chieu; truy cap vao cai node ma head dang quan ly(node dau tien)
	// lay noi dung cua no tuc la dia chi gang cho newNode->next
	(*head) = newNode;//sau do cap nhat noi dung cho node moi (node head); hien tai la node dau tien trong dslk
}

void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	node *temp = *head; //neu list null thi temp = head = null -> null k co data hay next -> temp->next sai
	if(temp == NULL){ 
		*head = newNode;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode; //cho next cua node cuoi tro vao newNode
}

void insert(node **head, int k, int x){
	int n = size(*head);
	if(k<1 || k>n+1){
		printf("Vi tri chen khong hop le");
		return;
	}
	if(k==1)
		pushFront(head,x);
	else if(k==n+1)
		pushBack(head,x);
	else{
		node *temp = *head;
		for(int i=1; i<k-1; i++){
			temp = temp->next;
		}
		node *newNode = makeNode(x);
		//b1: phan next cua newNode luu dia chi cua node thu k
		newNode->next = temp->next; //temp->next dia chi cua node thu k, temp dang la node thu k-1
		//b2: phan next cua node thu k-1 luu dia chi cua newNode
		temp->next = newNode;
		//thuc hien b2 truoc b1: mat dau k
	}
}

void popFront(node **head){
    if(*head == NULL){
        printf("Danh sach rong!\n");
        return;
    }
    node *temp = *head;//tao cai node temp de xiu giai phong node dau
    *head = (*head)->next; //or: *head = temp->next;
    free(temp);
}

void popBack(node **head){
    if(*head == NULL){
        printf("Danh sach rong!\n");
        return;
    }
    node *temp = *head;
    //TH: dslk chi co 1 node
    if(temp->next == NULL){ //tuc la dslk chi co 1 ptu
        *head = NULL;		//khi do ban than temp->next da la null roi, khi truy cap vao temp->next->next 
        free(temp);			//thi se truy cap vao vung nho khong hop le -> loi.
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next; //luu node cuoi de free
    temp->next = NULL;//b1: cho node ke cuoi tro vao NULL
    free(last);//b2: free node cuoi cung
}

void erase(node **head, int k){
    if(k<1 || k>size(*head)){
        printf("Vi tri xoa khong hop le!\n");
        return;
    }
    if(k==1)
        popFront(head);
    else{
        node *temp = *head;
        for(int i=1; i<k-1; i++){
            temp = temp->next;
        }
        //temp: k-1
        node *del = temp->next; //node thu k
        temp->next = del->next; //cho node temp nhay qua node del
        free(del);
    }
}

//dung thuat toan selectionSort
void sort(node **head){
    for(node *i = *head; i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j!= NULL; j = j->next){
            if(min->data > j->data)
                min = j;
        }
        //chu y: ta chi can hoan vi data cua 2 node k can hoan vi next
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

int main(){
	node *head = NULL;
//	pushFront(&head,1);	
//	pushFront(&head,2);	
//	pushFront(&head,3);	
//	pushFront(&head,4);	
//	pushFront(&head,5);	
//	duyet(head);
	while(1){
		printf("--------------------------------------\n");
		printf("1. Them vao cuoi: \n");
		printf("2. Them vao dau: \n");
		printf("3. Chen vao giua: \n");
		printf("4. Xoa dau: \n");
		printf("5. Xoa cuoi: \n");
		printf("6. Xoa giua: \n");
		printf("7. Sort: \n");
		printf("8. Show: \n");
		printf("0. Thoat\n");
		printf("--------------------------------------\n");
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
		else
			break;
	}
	return 0;
}
//chu y: 
//head != NULL : duyet qua node cuoi cung toi thang null
//head->next != NULL : duyet toi node cuoi cung chu k toi null 
//head->next->next != NULL: duyet toi node sat node cuoi cung (node thu 2 tu sau ve)
