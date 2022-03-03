#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort(triangle *a,triangle *b)
{
	triangle temp=*a;
	*a=*b;
	*b=temp;
}
int cmp_area(triangle *t)
{
	int p;
	p=(t->a+t->b+t->c)/2;
	int a,b,c;
	a=t->a;
	b=t->b;
	c=t->c;
	return(sqrt(p*(p-a)*(p-b)*(p-c)));
	
}

int main()
{
	int i,j,n;
	printf("Enter the number of triangles");
	scanf("%d",&n);
	triangle *tr=malloc(n*sizeof(triangle));
	printf("Enter the sides");
	for(i=0;i<n;i++)
		scanf("%d%d%d",&tr[i].a,&tr[i].b,&tr[i].c);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(cmp_area(&tr[j])>cmp_area(&tr[j+1]))
				sort(&tr[j],&tr[j+1]);
			
		}
		
	}

	printf("The sorted triangle based on area\n");
	for(i=0;i<n;i++)
		printf("%d %d %d\n",tr[i].a,tr[i].b,tr[i].c);
}
