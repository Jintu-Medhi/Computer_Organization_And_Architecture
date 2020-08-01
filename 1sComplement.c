#include<stdio.h>
void print(int [],int );
void onesComp(int [],int );
int bin(int [],int );

main()
{
	int num,A[16],i;
	printf("Enter the number(decimal): ");
    scanf("%d",&num);  
    i=bin(A,num);
    printf("In binary:");
    print(A,i);
    onesComp(A,i);
    printf("\n1's complement: ");
    print(A,i);    
}
//1's complement
void onesComp(int b[],int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		if(b[i]==1)
		  b[i]=0;
		else
		  b[i]=1;
	}	
}

//decimal to binary conversion
int bin(int A[],int num)
{
	int i=0,j,temp;
	while(num!=0)
	{
		A[i++]=num % 2;
		num=num/2;
	}
	for(j=0;j<i/2;j++)
	{
	    temp=A[j];
	    A[j]=A[i-1-j];
	    A[i-1-j]=temp;
	}
	return i;
}
//for printing the number
void print(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",A[i]);
	}
}
