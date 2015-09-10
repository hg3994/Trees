#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int matrix[1001][1001]={0};
int visited[1001]={0};
int q[1001],f=0,r=-1;
int reach[1001]={0};
void bfs(int s,int n,int c,int p);

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,i,j,x,y,s;
        scanf("%d %d",&n,&m);
        
        for(i=0;i<m;i++){
            scanf("%d %d\n",&x,&y);
            matrix[x-1][y-1]=1;
            matrix[y-1][x-1]=1;
        }//INPUT
        scanf("%d",&s);
        reach[s-1]=999999;
        bfs(s-1,n,1,s-1);
        for(i=0;i<n;i++){
            if(reach[i]==0)
                printf("-1 ");
            else if(reach[i]!=999999)
                printf("%d ",reach[i]);
        }
    }
    return 0;
}

void bfs(int s,int n,int c,int p){
    int i;
    for(i=0;i<n;i++){
        if(matrix[s][i] && visited[i]==0 && i!=p){
            if((c*6)<reach[i] || reach[i]==0)
                reach[i]=c*6;
            q[++r]=i;
        }
    }
    if(f<=r){
        visited[q[f]]=1;
        bfs(q[f++],n,c+1,p);
    }
}

