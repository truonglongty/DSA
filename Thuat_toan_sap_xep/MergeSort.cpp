#include <stdio.h>

//Do phuc tap: O(NLogN)

//merge
//Tron cac ptu tu chi so left >= mid va cac ptu tu chi so mid + 1 >= right
//thanh mang tang dan
void merge(int a[], int l, int m, int r){
    //tam thoi luu cac ptu tu l -> m vao 1 mang
    // luu cac otu tu m+1 -> r vao 1 mang
    int n1 = m-l+1, n2 = r-m; //n1,n2 la so luong phan tu cua 2 mang tang dan
    int x[n1], y[n2];
    
    for(int i=0; i<n1; i++) //dua cac ptu tu chi so l->m vao mang x giong thao tac scanf
        x[i] = a[l+i];
    for(int i=0; i<n2; i++) //dua cac ptu tu chi so m+1->r vao mang y
        y[i] = a[m+1 + i];
        
    int index = l;
    int i=0, j=0;
    //tron 2 mang x,y gan lai cho mang a[l,r]
    while(i<n1 && j<n2){
        if(x[i]<=y[j])
            a[index++] = x[i++];
        else
            a[index++] = y[j++];
    }
    while(i<n1) a[index++] = x[i++];
    while(j<n2) a[index++] = y[j++];
}

void MergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        MergeSort(a,l,m); //goi de quy ben trai
        MergeSort(a,m+1,r); //goi de quy ben phai
        merge(a,l,m,r);
    }
}

int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    MergeSort(a,0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}

