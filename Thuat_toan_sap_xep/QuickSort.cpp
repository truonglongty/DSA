#include <stdio.h>

//Do phuc tap: O(NLogN) -> thuat toan kinh dien, phu hop voi bo du lieu thuc te, duoc dung rong rai
//Dung giai thuat chi va tri,

//Phan hoach lomuto: chon pivot (khoa) (chon ptu cuoi) chia nua truoc nho hon pivot va nua sau lon hon pivot 
// va goi dequy 2 ben den khi chi con 1 ptu.
//Duy tri chi so i=l-1. lam vong for j=l -> r-1 (k xet pivot)
//xet tung ptu neu lon hon pivot thi skip, nho hon bang thi tang i va swap(a[i],a[j])
//Cuoi cung tang i len va swap(a[i],a[r]) -> muc dich: tra ve chi so cua pivot
//de goi dequy trai phai tu chi so do

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int l, int r){
    int i = l-1;
    int pivot = a[r];
    for(int j=l; j<r; j++){
        if(a[j]<=pivot){
            ++i;
            swap(&a[i],&a[j]);
        }
    }
    ++i;
    swap(&a[i],&a[r]);
    return i;
}

void QuickSort(int a[], int l, int r){
    if(l<r){
        int pos = partition(a,l,r);
        QuickSort(a,l,pos-1);
        QuickSort(a,pos+1,r);
    }
}

int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    QuickSort(a,0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}

