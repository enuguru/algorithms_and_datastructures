

#include <stdio.h>

void main()
{
	int m1[10][10],m2[10][10];
	int r,c,i,j;
	printf("\nEnter r & c : ");
	scanf("%d %d",&r,&c);
	printf("\nEnter first matrix of size %d X %d\n",r,c);
	for(i=0;i< r ; i ++)
	{
		for(j=0;j < c;j++)
		{
			scanf("%d",&m1[i][j]);
		}			
	}
	for(i=0;i < r ; i ++)
	{
		for(j=0;j < c;j++)
		{
			m2[j][i] = m1[i][j];
		}			
	}
	printf("\nthe original matrix is\n");
	for(i=0;i < r;i++)
	{
		for(j=0;j < c;j++)
		{
			printf("%4d",m1[i][j]);
			printf("\n");
		}			
	} // for
	printf("\nThe resultane matrix is\n");
	for(i=0;i< c;i++)
	{
		for(j=0;j < r;j++)
		{
			printf("%4d",m2[i][j]);
		}
		printf("\n");
	} // for
} // main

		
