#include<stdio.h>
int poweroftwo(int x);
int retpow(int x);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long int a,b,x,c=0,i,j,k,p,m=0;
		scanf("%lld %lld",&a,&b);
		x=b;
		while(x>1){
			x=x/2;
			c++;
		}

		long long int arr[a+1][c+1];

		for(j=0;j<=c;j++)
			arr[1][j]=j;

		for(i=2;i<=a;i++){
			for(j=0;j<=c;j++){
				if(poweroftwo(i)){
					p=retpow(b);
					//printf("P=%d\n",p);
					m=m+1;
					for(k=m;k>=0;k--){
						//printf("k=%d\n",k);
						arr[i][j]=k;
						j++;
					}
					for(k=1;j<=c;k++){
						arr[i][j]=k;
						j++;
					}
				}
				else{
					if(i%2==1){
						//printf("ODD\n");
						arr[i][j]=arr[(i-1)/2][j]+1;
					}
					else{
						arr[i][j]=arr[(i)/2][j]+1;
					}
				}
			}
		}
		/*for(i=1;i<=a;i++){
			for(j=0;j<=b;j++){
					printf("%d ",arr[i][j]);
			}
			printf("\n");
		}*/
		printf("%lld \n",arr[a][c]);
	}
	return 0;
}

int poweroftwo(int x){
	int a;
		if(x==1)
			return 1;
		while(x>1){
			if(x==2)
				return 1;
			if(x%2==1)
				return 0;
			a=x/2;
			if(a%2!=0)
				return 0;
			x=x/2;
		}
}

int retpow(int x){
	int a=0;
	while(x>1){
		x=x/2;
		a++;
	}
	return a;
}
