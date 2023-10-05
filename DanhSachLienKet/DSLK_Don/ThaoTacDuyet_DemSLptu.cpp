#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

void duyet(node *head){
	while(head != NULL){
		printf("%d ",head->data);
		//duyet head sang node ben phai
		head = head->next; //quan trong
		//phan tham chieu cua node hien tai la dia chi cua node tiep theo sau no
		// -> dem dia chi cua node tiep theo gang cho no
	}
}

//dem so luong ptu trong dslk
int size(node *head){
	int cnt=0;
	while(head != NULL){
		++cnt;
		head = head->next;
	}
	return cnt;
}

int main(){
	
}
