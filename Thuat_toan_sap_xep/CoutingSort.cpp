#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Do phuc tap: O(N + K)
//Tu tuong: dem xem cac ptu xuat hien bao nhieu lan(tan suat) sau do in tu be den long
//dk: cac ptu deu > 0 va 0<=dem[]<10^7

int dem[10000001];

void coutingsort(int a[], int n){
    int k = -1e9;
    for(int i=0; i<n; i++)
        k = fmax(k,a[i]);
    for(int i=0; i<n; i++){
        dem[a[i]]++;
    }
    for(int i=0; i<=k; i++){
        for(int j=0; j<dem[i]; j++)
            printf("%d ", i);
    }
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    coutingsort(a,n);
    return 0;
}
