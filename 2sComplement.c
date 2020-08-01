#include<stdio.h>
void print(int [],int );
void comp(int [],int );
main()
{  
    int n,m,b[50],temp,i=0,j;
    
	printf("Enter a number ");
    scanf("%d",&n);
  
	//dividing the number by base(i.e., 2)
	m=n;
    while(m!=0)
    {
    	b[i]=m%2;
    	m=m/2;
    	//printf("%d",b[i]);
    	i++;
	}
    
    //arranging and prnting array
	for(j=0;j<i/2;j++)
	{
	    temp=b[j];
	    b[j]=b[i-1-j];
	    b[i-1-j]=temp;
	}
	printf("\nBnary number is ");
	print(b,i);
	comp(b,i);//2's complement operation
	
	printf("\n2's comp is ");
	print(b,i);
}
//printing array
void print(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",A[i]);
	}
}
//2's complement function
void comp(int b[],int i)
{
	int l,g;
	for(l=i-1;l>=0;l--)
	{
		if(b[l]==1)
		 break;
	}
	
	for(g=l-1;g>=0;g--)
	{
		if(b[g]==1)
		  b[g]=0;
		else
		  b[g]=1;
	}
	
}
