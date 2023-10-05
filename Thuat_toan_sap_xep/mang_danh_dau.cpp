#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//khai bao mang toan cuc thi cac ptu cua no =0 con khai bao trong main cac ptu co the la gtri rac
// luu y dieu kien cua mang danh dau: 0<=a[i]<=10^7;

int dem[10000001];

int main() {
    int n; scanf("%d",&n);
    int a[n];
    int max = -1e9;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]); 
        dem[a[i]]++;
        if(a[i]>max) max = a[i];
    }
    for(int i=0; i<=max; i++){
        if(dem[i]!=0)
            printf("%d %d\n",i,dem[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        if(dem[a[i]]!=0){
            printf("%d %d\n",a[i],dem[a[i]]);
            dem[a[i]]=0;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
