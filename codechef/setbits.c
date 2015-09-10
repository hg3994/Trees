#include<stdio.h>
//#define n 12
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int i,si,ei;

		long long int a[1001]={0};
		long long int hex[16]={0};
		long long int change;
		scanf("%lld",&change);
		while(change--){
			scanf("%lld %lld",&si,&ei);
			for(i=si-1;i<ei;i++)
				a[i]=1;
		}
		//for(i=0;i<n;i++)
			//printf("%d ",a[i]);
		for(i=0;i<1000;i=i+4)
		{
			if(a[i]==0)
			{
				if(a[i+1]==0)
				{
					if(a[i+2]==0)
					{
						if(a[i+3]==0)//0000
							hex[0]++;
						else
							hex[1]++;//0001
					}
					else
					{
						if(a[i+3]==0)//0010
							hex[2]++;
						else
							hex[3]++;//0011
					}
				}
				else
				{
					if(a[i+2]==0){
						if(a[i+3]==0)//0100
							hex[4]++;
						else
							hex[5]++;//0101
					}
					else{
						if(a[i+3]==0)//0110
							hex[6]++;
						else
							hex[7]++;//0111
					}
				}
			}
			else
			{
				if(a[i+1]==0)
				{
					if(a[i+2]==0)
					{
						if(a[i+3]==0)//1000
							hex[8]++;
						else
							hex[9]++;//1001
					}
					else
					{
						if(a[i+3]==0)//1010
							hex[10]++;
						else
							hex[11]++;//1011
					}
				}
				else
				{
					if(a[i+2]==0){
						if(a[i+3]==0)//1100
							hex[12]++;
						else
							hex[13]++;//1101
					}
					else{
						if(a[i+3]==0)//1110
							hex[14]++;
						else
							hex[15]++;//1111
					}
				}
			}
		}
		for(i=0;i<16;i++)
			printf("%lld ",hex[i]);		

	}

}