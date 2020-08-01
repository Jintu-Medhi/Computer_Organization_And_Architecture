/* For any base less than 10. */
#include<stdio.h>
#include<math.h>
main()
{
	int r,num,base,m,sum=0,i=0,flag=0;

	printf("Enter the base:");
	scanf("%d",&base);
	printf("Enter the number:");
	scanf("%d",&num);

	m=num;
	while(m>0)
	{
		r=m%10;
		if(r>base)
		{
		  flag=1;
		  break;
		}
		else
		{
			sum=sum+r*pow(base,i);
			m=m/10;
			i++;
		}
	}
	if(flag==0)
	  printf("The decimal number is %d",sum);
	else
    printf("invalid number!!!");
}
