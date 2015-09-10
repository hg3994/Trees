#include<stdio.h>
#include<string.h>


long long int min(long long int *h,long long int f,long long int r){
	long long int i,m=h[f];
	for(i=f+1;i<=r;i++){
		if(h[i]<m)
			m=h[i];
	}
	return m;
}
	

int main(){
	long long int i,j,k,l,n,x=0;
	scanf("%lld",&n);

	long long int h[n],arr[(n*(n-1))/2];
	
	for(i=0;i<n;i++)
		scanf("%lld",&h[i]);

	for(j=2;j<=n;j++){
		for(k=0;k<=(n-j);k=k+1){
			arr[x]=min(h,k,k+j-1)*j;
			x++;
		}
	}
	long long int max;
	max=arr[0];

	for(i=1;i<(n*(n-1))/2;i++)
		if(arr[i]>max)
			max=arr[i];
	printf("%lld",max);

}


