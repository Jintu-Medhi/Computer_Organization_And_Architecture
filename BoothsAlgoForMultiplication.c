#include<stdio.h>
#include<math.h>
void bin(int [],int ,int );
void Print(int [],int );
void twosComp(int [],int );
void rShift(int [],int );
void Add(int [],int [],int );
void Sub(int [],int [],int );
int binTOdeci(int [],int [],int );
void booths(int [],int [],int [],int );
main()
{
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	int A[n]={0},Q[n]={0},M[n]={0},m,q;
	printf("Enter value of M:");
	scanf("%d",&m);
	bin(M,m,n);
	printf("Enter value of Q:");
	scanf("%d",&q);
	bin(Q,q,n);
	printf("M=");Print(M,n);
	printf("\n");
	printf("Q=");Print(Q,n);
	printf("\n");
	printf("A\tQ\tQ-1\tcount\n\n");
	booths(A,M,Q,n);
	printf("Product is %d",binTOdeci(A,Q,n));
}
void booths(int A[],int M[],int Q[],int i)
{
	int n=i-1,count=i,Qn=0;
	
		Print(A,i);
		printf("\t");
		Print(Q,i);
		printf("\t%d\t%d\n\n",Qn,count);
		
	while(count!=0)
	{
		if((Q[n]==1 && Qn==1) || (Q[n]==0 && Qn==0))
		{
			Qn=Q[n];
			rShift(Q,i);
			Q[0]=A[n];
			rShift(A,i);
			count--;
			Print(A,i);
			printf("\t");
			Print(Q,i);
			printf("\t%d\t%d\tRight Shift\n\n",Qn,count);
		}
		else if(Q[n]==1 && Qn==0)
		{
			Sub(A,M,i);
			Print(A,i);
			printf("\t");
			Print(Q,i);
			printf("\t%d",Qn);
			printf("\t\tA=A-M\n");
			Qn=Q[n];
			rShift(Q,i);
			Q[0]=A[n];
			rShift(A,i);
			count--;
			Print(A,i);
			printf("\t");
			Print(Q,i);
			printf("\t%d\t%d\tRight Shift\n\n",Qn,count);
		}
		else if(Q[n]==0 && Qn==1)
		{
			Add(A,M,i);
			Print(A,i);
			printf("\t");
			Print(Q,i);
			printf("\t%d",Qn);
			printf("\t\tA=A+M\n");
			Qn=Q[n];
			rShift(Q,i);
			Q[0]=A[n];
			rShift(A,i);
			count--;
			Print(A,i);
			printf("\t");
			Print(Q,i);
	 		printf("\t%d\t%d\tRight Shift\n\n",Qn,count);
		}
	}
}
void bin(int A[],int m,int n)
{
	int i;
	if(m<0)
	{
		m=-1*m;
		for(i=n-1;i>=0;i--)
		{
			A[i]=m%2;
			m=m/2;
		}
		twosComp(A,n);
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			A[i]=m%2;
			m=m/2;
		}
	}
}
void Print(int A[],int n)
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
void rShift(int A[],int n)
{
	int i;

	for(i=n-1;i>0;i--)
    {
		A[i]=A[i-1];
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
    	A[j]=S[j];//A=A+M, copying everything to A
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
int binTOdeci(int A[],int Q[],int n)
{
	int k,m=2*n,S[m];
	int i=m-1,j=0,sum=0;
	for(k=0;k<n;k++)//to combine the two arrays
	{
		S[k]=A[k];
		S[k+n]=Q[k];
	}
	if(S[0]==1)//if negative
	{
		twosComp(S,m);
		while(i>0)
		{
			sum=sum+S[i]*pow(2,j);//sum=sum+r*pow(base,i);
			j++;
			i--;
		}
	
	return sum*(-1);//since negative
   }
   else
   {
   	while(i>0)
		{
			sum=sum+S[i--]*pow(2,j);//sum=sum+r*pow(base,i);
			j++;
		//	i--;
		}
	
	return sum;
   }
}
