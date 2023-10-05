#include <stdio.h>

//Thuat toan: Bubble Sort
//Do phuc tap: O(N^2)
//Tu tuong: O moi buoc se dua phan tu lon nhat chua duoc sap xep ra cuoi mang:
//O moi buoc se xet tu dau day va so sanh 2 phan tu lien ke neu ptu truoc lon hon thi hoan vi

void BubbleSort(int a[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    BubbleSort(a,n);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}

