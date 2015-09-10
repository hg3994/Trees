#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long int i,j,k,n;
    scanf("%lld",&n);
    long long int a[n],temp[n];
    for(i=0;i<n;i++)
        temp[i]=1;
    for(i=0;i<n;i++)
        scanf("%lld\n",&a[i]);
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]<a[i]){
                if(temp[j]+1>temp[i])
                    temp[i]=temp[j]+1;
            }
        }
    }
    long long int max=a[0];
    for(i=1;i<n;i++){
        //printf("%d ",temp[i]);
        if(temp[i]>max)
            max=temp[i];
    }
    printf("%lld",max);
    return 0;
}

