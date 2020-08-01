#include<stdio.h>
#include<math.h>
void bin(int [],int ,int );
void print(int [],int );
void twosComp(int [],int );
void Add(int [],int [],int );
void Sub(int [],int [],int );
void leftShift(int [],int ,int );
int binTOdeci(int [],int );
void DIV(int [],int [],int [],int );
main()
{
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	int A[n]={0},Q[n]={0},M[n]={0},m,q;
	printf("Enter value of Q:");
	scanf("%d",&q);
	bin(Q,q,n);
	printf("Enter value of M:");
	scanf("%d",&m);
	bin(M,m,n);
	printf("Q=");print(Q,n);
	printf("\n");
	printf("M=");print(M,n);
	printf("\n\n");
	printf("A\tQ\tcount\n");
	DIV(A,M,Q,n);
	    if(q<=0&&m>=0)
		{
			printf("Quotient=-%d\n",binTOdeci(Q,n));
			printf("Remender=-%d",binTOdeci(A,n));
		}
		else if(q>=0&&m<=0)
		{
			printf("Quotient=-%d\n",binTOdeci(Q,n));
			printf("Remender=%d",binTOdeci(A,n));
		}
		else if(q<=0&&m<=0)
		{
			printf("Quotient=%d\n",binTOdeci(Q,n));
			printf("Remender=-%d",binTOdeci(A,n));
		}
		else
		{
			printf("Quotient=%d\n",binTOdeci(Q,n));
			printf("Remender=%d",binTOdeci(A,n));
		}
}
void DIV(int A[],int M[],int Q[],int n)
{
	int count=n;
		print(A,n);
		printf("\t");
		print(Q,n);
        printf("\t");
		printf("%d\t",count);
		printf("initial\n\n");
		
		while(count!=0)
		{
			leftShift(A,n,0);
			A[n-1]=Q[0];
			leftShift(Q,n,1);
			print(A,n);
			printf("\t");
			print(Q,n);
			printf("\t\tleft shift\n");
			
			Sub(A,M,n);
			print(A,n);
			printf("\t");
			print(Q,n);
			printf("\t\tA=A-M\n");
			if(A[0]==1)//means A is negative
			{
				Q[n-1]=0;
				Add(A,M,n);
				count--;
				print(A,n);
				printf("\t");
				print(Q,n);
		        printf("\t");
				printf("%d\n\n",count);
			}
			else
			{
				Q[n-1]=1;
				count--;
				print(A,n);
				printf("\t");
				print(Q,n);
		        printf("\t");
				printf("%d\n\n",count);
			}
		}
}
int binTOdeci(int A[],int n)
{
	int i=n-1,j=0,sum=0;
	while(i>0)
	{
		sum=sum+A[i]*pow(2,j);//sum=sum+r*pow(base,i);
		j++;
		i--;
	}
	return sum;
}
void leftShift(int A[],int n,int s)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		A[i]=A[i+1];
	}
	
}
void bin(int A[],int m,int n)
{
	int i=n-1;
	if(m<0)
	m=-1*m;
	while(m!=0)
	{
		A[i]=m%2;
		m=m/2;
		i--;
	}
}
void print(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d",A[i]);
}
void twosComp(int b[],int i)
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
void Add(int A[],int B[],int n)
{
	int i=n-1,j,C=0,S[n];
	do{
		if(A[i]+B[i]+C==0)
	    {
	    	S[i]=0;
	        C=0;
		}
	    else if(A[i]+B[i]+C==1)
	   	{
	    	S[i]=1;
	       	C=0;
		}
	    else if(A[i]+B[i]+C==2)
	    {
	    	S[i]=0;
	    	C=1;
    	    }
    	    else if(A[i]+B[i]+C==3)
	    {
	    	S[i]=1;
	    	C=1;
    	    }
    	    i--;
          } while(i>=0);
    
	for(j=0;j<n;j++)
        {
    	A[j]=S[j];
	}
}
void Sub(int A[],int B[],int n)
{
	int i=n-1,j,C=0,S[n],Mn[n];
	for(j=0;j<=n;j++)
        {
    	Mn[j]=B[j];
	}
	twosComp(Mn,n);
	do{
	   if(A[i]+Mn[i]+C==0)
	   {
	     S[i]=0;
	     C=0;
           }
	   else if(A[i]+Mn[i]+C==1)
	   {
	     S[i]=1;
	     C=0;
	   }
	   else if(A[i]+Mn[i]+C==2)
	   {
	     S[i]=0;
	     C=1;
    	   }
    	   else if(A[i]+Mn[i]+C==3)
	   {
	     S[i]=1;
	     C=1;
    	   }
    	   i--;
        } while(i>=0);
    
	for(j=0;j<n;j++)
        {
    	 A[j]=S[j];
	}
}
