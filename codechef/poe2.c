#include<stdio.h>
int poweroftwo(int x);
int main()
{
	int tl,x;
	printf("Enter\n");
	scanf("%d",&tl);
	x=poweroftwo(tl);
	if(x==1)
		printf("YES\n");
	else{
		printf("0\n");
	}
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