#include<stdio.h>


int main(){
	int m,n,r,i,j,x;
	scanf("%d %d %d",&m,&n,&r);
	x=r;
	//while(r>(2*(m+n-2)))
		//r=r%(2*(m+n-2));
	int a[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d ",&a[i][j]);
		}
		printf("\n");
	}
	printf("m=%d, n=%d, r=%d \n",m,n,r);
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	int l;
	l=(m<n?m:n);
	l=l/2;
	printf("l=%d\n\n",l);
	//x=x+8;
	for(j=0;j<l;j++){ //control the number of rotations needed in the matrix.
		if(x>(2*(m+n-2-(4*j))))
			x=(2*(m+n-2-(4*j)));
			//x=x-8;
			printf("r=%d\n",x);
		for(i=1;i<=x;i++){ //controls the number of times to be rotated
				//printf("J= %d \n\n",j);
				int temp,temp2,i;

				i=m-1-j;
				temp=a[i][j];
				for(i=m-1-j;i>j;i--){
					a[i][j]=a[i-1][j];
				}

				i=n-1-j;
				temp2=a[m-1-j][i];
				for(i=n-1-j;i>j;i--){
					if(i!=j+1)
						a[m-1-j][i]=a[m-1-j][i-1];
					else
						a[m-1-j][i]=temp;
				}

				i=j;
				temp=a[i][n-1-j];
				for(i=j;i<(m-1-j);i++){
					if(i!=m-1-j-1)
						a[i][n-1-j]=a[i+1][n-1-j];
					else
						a[i][n-1-j]=temp2;
				}

				for(i=j;i<(n-1-j);i++){
					if(i!=(n-1-j-1))
						a[j][i]=a[j][i+1];
					else
						a[j][i]=temp;
				}
			}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
