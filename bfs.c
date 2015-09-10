#include<stdio.h>
//Q[]--FIFO Queue 
//visited[] Queue maintains what nodes are visited 
// a[][] takes the input of arrows from user 

int a[20][20],q[20],visited[20],f=0,r=-1,i,j,v,n; //f and r for q[]

void bfs(int v){
	for(i=0;i<n;i++)
		if(a[v][i] && visited[i]==0) // Checks the node which are connected with v and saves them in Q for future visits to them.
			q[++r]=i;
	if(f<=r){
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
int main(){
	printf("Enter the number of nodes (max 20)\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){//making all arrays zero
		q[i]=0;
		visited[i]=0;
	}
	printf("Enter the n*n matrix of arrows");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);//taking input
	printf("Enter the starting vertex \n");
	scanf("%d",&v);
	bfs(v);
	printf("The visited nodes are--");
	for(i=0;i<n;i++)
		if(visited[i])
			printf("%d\t",i);
	printf("\n");
	return 0;
}
