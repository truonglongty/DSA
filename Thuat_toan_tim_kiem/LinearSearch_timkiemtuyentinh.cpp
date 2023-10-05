#include <stdio.h>

int linearsearch(int a[], int n, int x){
	for(int i=0; i<n; i++){
		if(x==a[i])
			return 1;
	}
	return 0;
}

int main(){
	int n, x; scanf("%d%d",&n,&x);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	if(linearsearch(a,n,x))
		printf("YES");
	else
		printf("NO");
}
