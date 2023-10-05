#include <stdio.h>

//Thuat toan: selection sort
//Do phuc tap: O(N^2)
//Tu tuong: O moi buoc se dua cac gia tri nho nhat chua duoc sap xep ra dau mang (tim index)

void SelectionSort(int a[], int n){
	for(int i=0; i<n-1; i++){
	//tim phan tu nho nhat
		int min_pos = i;	//coi i la thang nho nhat
		for(int j=i+1; j<n; j++){
			if(a[j] < a[min_pos])
				min_pos = j;
		}
		// hoan vi
		int tmp = a[i];
		a[i] = a[min_pos];
		a[min_pos] = tmp;
	}
}

int main(){
	int n; scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	SelectionSort(a,n);
	for(int i=0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}
