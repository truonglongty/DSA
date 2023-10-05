#include <stdio.h>

#define MAX 50

struct LIST{
	int num; //so nut hien co
	int nodes[MAX]; //Moi nut cua list la mot ptu tren mang
};

void Initialize(LIST *list){
	list->num = 0;
}

int ListSize(LIST *list){
	return list->num;
}

int Empty(LIST *list){
	return (list->num==0?1:0);
}

int Full(LIST *list){
	return (list->num==MAX?1:0);
}

void Insert(LIST *list, int pos, int x){
	if(pos < 0 || pos > list->num)
		printf("Vi tri chen khong hop le");
	else if(Full(list))
		printf("List da day");
	else{
		for(int i=list->num-1; i>=pos; i--)
			list->nodes[i+1] = list->nodes[i];
		list->nodes[pos] = x;
		list->num++;
	}
}

void Delete(LIST *list, int pos){
	if(pos<0 || pos >= list->num)
		printf("Vi tri xoa khong hop le");
	else if(Empty(list))
		printf("List null");
	else{
		for(int i=pos; i<list->num; i++)
			list->nodes[i] = list->nodes[i+1];
		list->num--;
	}
}

int main(){
	struct LIST l;
	
}
