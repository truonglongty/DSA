#include <stdio.h>

//Dieu kien: mang da duoc sort
//Do phuc tap: O(Log2N) ~ O(LogN)
//Tu tuong: O moi buoc tim ptu dung giua vs ss

int BinarySearch(int a[], int n, int x){
    int l=0, r=n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m]==x)
            return 1;
        else if(a[m]>x)
            r = m-1;
        else
            l = m+1;
    }
    return 0;
}

int main()
{
    int n,x; scanf("%d%d",&n,&x);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("%d",BinarySearch(a,n,x));
    return 0;
}

