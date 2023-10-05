#include <stdio.h>
#include <math.h>

//Do phuc tap: O(N^2)
//Tu tuong: O moi buoc se chen phan tu dang xet vao day da duoc xep truoc do

void InsertionSort(int a[], int n){
    for(int i=1; i<n; i++){ //duyet tu i=1 vi neu i=0 thi k co ptu dung truoc no de so sanh
        int pos = i-1, value = a[i]; //pos=i-1 de tim vitri chen cho i dang xet coi nhu i-1 la vitri dau
        while(pos >= 0 && value < a[pos]){
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = value; //chen vao dang sau thang nho hon value
    }
}

int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    InsertionSort(a,n);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}

