#include <stdio.h>

int main(void)
{
	int a[100]={0},b[100]={0};
	a[0]=1;
	int i,j,k=1,n,c,x=0;
	scanf("%d",&n);

	while(--n) //Loop for the number of times we want to carry on the calculations, i.e, 'n' number of times. / 'n'th number of the sequence.
	{
		i=0; k=0;
		while(a[i]!=0) //Loop to check the end of array A[]
		{
			c=1;
			while(a[i+1]==a[i]){ //Loop till the end of nect digit, like in 111221, 1st it will end at 2 and then at the last 1
				c++; //c is the number of time a digit is occuring, like 3 for(111), 2 for(22), 1 for(1)
				i++; // Moving the pointer ahead in the 1st array
			}

			b[k++]=c; //Updating the 2nd array B[] with number of times a digit occured. like 3 for(111) 
			b[k++]=a[i]; //and then the digit which has occured 'c' number of times.
			
			i++; //Increment the pointer in 1st array A[].

		}
		
		for(j=0;j<k;j++) //Copying the contents of B[] to A[]. So that the same thing can be done again and again.
			a[j]=b[j];
	}
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	return 0;
}