
#include<stdio.h>  
int main()
{    
	int n,i,flag=0;    
	printf("Enter the number to check prime:");    
	scanf("%d",&n);    
	if(n==2)
	{
		printf("THe given number is a prime");
		return 0;
	}
	if(n==0 || n==1)
	{
		printf("THe given number is not a prime");
		return 0;
	}	
	for(i=2;i<n;i++)    
	{    
		if(n%i==0)    
		{    
			printf("Number is not prime");    
			flag=1;    
			break;    
		}
	}    
	if(flag==0)    
		printf("Number is prime");     
	return 0;  
}
