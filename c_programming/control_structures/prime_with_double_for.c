
#include<stdio.h>  
int main()
{    
	int n,i;int flag;    
	printf("Enter the number for range:");    
	scanf("%d",&n); 
        for(int j =2; j<=n; j++)
	{		
		flag=0;
	for(i=2;i<j;i++)    
	{    
		if(j%i==0)    
		{    
			flag=1;    
			break;    
		}
	}    
	if(flag==0)    
		printf("%d ",j);    
	}
	return 0;  
}
