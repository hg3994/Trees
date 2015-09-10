#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char a[1000];
    int alpha[27]; 
    alpha[0]=0;
    int n,i;
    gets(a);
    n=strlen(a);
    for(i=1;i<27;i++)
        alpha[i]=1;
    //printf("%d",alpha[20]);
    for(i=0;i<n;i++){
            printf("i= %d ",i);
        if(islower(a[i])){
            alpha[a[i]%96]=0;
        }
        if(isupper(a[i]))
            alpha[a[i]%64]=0;
    }
    //for(i=1;i<27;i++)
        //if(alpha[i]==1){
        //printf("not pangram");
        //return 0;
    //}    
    for(i=1;i<27;i++)
        printf("%d ",alpha[i]);
        //printf("%d",alpha[24]);
    printf("pangram");
    return 0;
}

