#include<stdio.h>
void print(int [],int );
main()
{
	int num,base,m,re[16],i=0,j,temp;
	printf("Enter decimal number: ");
	scanf("%d",&num);
	printf("Enter base: ");
	scanf("%d",&base);
	
	m=num;
	while(m!=0)
	{
		re[i++]=m % base;
		m=m/base;
	}
	//arranging the array
	for(j=0;j<i/2;j++)
	{
	    temp=re[j];
	    re[j]=re[i-1-j];
	    re[i-1-j]=temp;
	}
	print(re,i);
}
//printing array
void print(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]>9)
		{
			if(A[i]==10)
				printf("A");
			else if(A[i]==11)
				printf("B");
			else if(A[i]==12)
				printf("C");
			else if(A[i]==13)
				printf("D");
			else if(A[i]==14)
				printf("E");
			else if(A[i]==15)
				printf("F");
		}
		else
			printf("%d",A[i]);
			
	}
}
