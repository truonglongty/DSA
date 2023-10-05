#include <stdio.h>
#include <stdlib.h>

//void qsort(arr, soluongptu, kich thuoc, int (* comparator)(const void *, const void *))

int tongchuso(int n){
	int s=0;
	while(n){
		s += n%10;
		n /= 10;
	}
	return s;
}

int comp(const void *a, const void *b){ //mong muon sort nhu nao
	int *x = (int *)a; //ep ve int phu hop voi mang
	int *y = (int *)b;
	// neu mang co so am thi dung if else
//	if(*x < *y)
//		return -1; //dung thu tu a dung truoc nho hon b
//	else
//		return 1; //sai thu tu
	return *x -*y; //tang dan; giam dan: *y - *x; tri tuyet doi tang dan: abs(*x) - abs(*y); tong chu so tang dan: tongchuso(*x) - tongchuso(*y)
}

//sap xep theo tong chu so tang dan, neu cung tong thi in so nho truoc
//vd: 6
//111 30 21 9 45 13
//output: 21 30 111 13 9 45

//int comp(const void *a, const void *b){
//	int *x = (int *)a;
//	int *y = (int *)b;
//	if(tongchuso(*x) != tongchuso(*y))
//		return tongchuso(*x) - tongchuso(*y);
//	else
//		return *x - *y;
//}

int main(){
	int n; scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	for(int i=0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}
