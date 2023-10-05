#include <stdio.h>

//Tim vi tri dau tien cua ptu X mang da sort
int first(int a[], int n, int x){
    int res = -1, l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x){
            res = m;
            r = m-1; //tim them o ben trai xem con k
        }
        else if(a[m]<x)
            l = m+1;
        else
            r = m-1;
    }
    return res;
}

//Tim vitri cuoi cung cua ptu X mang da sort
int last(int a[], int n, int x){
    int res = -1, l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x){
            res = m;
            l = m+1; //tim them o ben phai xem con k
        }
        else if(a[m]<x)
            l = m+1;
        else
            r = m-1;
    }
    return res;
}

//tim vitri dau tien cua ptu dau tien lon hon bang x trong mang sort
int first1(int a[], int n, int x){
	int res = -1, l=0, r=n-1;
	while(l<=r){
		int m = (l+r)/2;
		if(a[m]>=x){
			res = m;
			r = m-1; //tim them o ban trai xem con k
		}
		else
			l = m+1;
	}
	return res;
}

//tim vitri cuoi cung cua ptu nho hon bang x trong mang sort
int last1(int a[], int n, int x){
	int res = -1, 0, r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]<=x){
			res = m;
			l = m+1;
		}
		else
			r = m-1;
	}
	return res;
}

int main()
{
    int n,x; scanf("%d%d",&n,&x);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("%d %d",first(a,n,x),last(a,n,x));
    return 0;
}

