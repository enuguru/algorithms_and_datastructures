
#include <stdio.h>

int main()
{
	int num;
	int flag = 0;
	scanf("%d",&num);

	for(int val=1; val < num; val++)
	{
		if(val*val == num)
		{
			printf("The given number %d is a perfect square\n",num);
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		printf("The given number %d is not a perfect square\n",num);
	return 0;
}
