#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,i,len,x;
    scanf("%d",&n);
    char a[101];
    int alpha[27];
    for(i=0;i<27;i++)
      alpha[i]=0;
    while(n--){
            scanf("%s",a);
            len=strlen(a);

            for(i=0;i<len;i++){
                x=a[i];
                alpha[x%96]=alpha[x%96]+1;
            }
            for(i=0;i<27;i++)
                printf("%d ",alpha[i]);
    }
    return 0;
}
