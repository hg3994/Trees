#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define row 4

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int i,j,k,l,p,ind=0,ind2=0,q;
	int a[row][row];
	int b[row+1]={0,1,2,3,4};
	int temp[row+1];
	int input[row];
	
       		for(j=0;j<row;j++)//COLUMN
        	{
        	    	scanf("%d",&input[j]);
			printf("\n");
        	}
		//Disintegration into array[][]
		for(i=0;i<row;i++)//ROW
		{
			q=input[i];
       			for(j=3;j>=0;j--)//COLUMN
        		{
        			a[i][j]=(q%10);
				q=q/10;
        		}
    		}

	for(k=0;k<row;k++)
	{
		ind=0;
		ind2=0;
		for(i=0;i<row+1;i++)//Filling temp again
		{
			temp[i]=b[i];
		}
		for(l=0;l<row;l++)//Inserting x in the temp[] and getin the missin element which wil be replaced with 0 in the origl array
		{
			p=a[k][l];
			temp[p]='x';
		}
		
		while(temp[ind]=='x')
		{
			ind++;
		}
		while(a[k][ind2]!=0)
		{
			ind2++;
		}
		a[k][ind2]=ind;
	}

		for(i=0;i<row;i++)//ROW
		{
       			for(j=0;j<row;j++)//COLUMN
        		{
        		   printf("%d",a[i][j]);
        		}
       		 printf("\n");
    		}
    return 0;
}

