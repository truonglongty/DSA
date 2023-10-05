#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Tron 2 day tang dan tao thanh day tang dan
//Do phuc tap: O(N+M)

//C1: in ra luon
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int a[n], b[m];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<m; i++)
        scanf("%d",&b[i]);
    int i=0, j=0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            printf("%d ",a[i]);
            ++i;
        }
        else{
            printf("%d ",b[j]);
            ++j;
        }
    }
    while(i<n){
        printf("%d ",a[i]);
        ++i;
    }
    while(j<m){
        printf("%d ", b[j]);
        ++j;
    }
    return 0;
}

//C2: luu vao mang moi
//int main(){
//    int n,m; scanf("%d%d",&n,&m);
//    int a[n], b[m];
//    for(int i=0; i<n; i++)
//        scanf("%d",&a[i]);
//    for(int i=0; i<m; i++)
//        scanf("%d",&b[i]);
//        
//    int i=0, j=0;
//    int c[n+m];
//    int index=0;
//    
//    while(i<n && j<m){
//        if(a[i] <= b[j])
//            c[index++] = a[i++];
//        else
//            c[index++] = b[j++];
//    }
//    
//    while(i<n)
//        c[index++] = a[i++];
//    
//    
//    while(j<m)
//        c[index++] = b[j++];
//        
//        
//    for(int i=0; i<n+m; i++)
//        printf("%d ",c[i]);
//    return 0;
//}
