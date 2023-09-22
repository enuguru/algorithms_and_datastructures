#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
long int rem, num = x, s = 0;
while(num > 0)
{
  rem = num % 10;
  s = (s*10) + rem;
  num = num / 10;
}
if(x == s)
{
  return true;
}
return false;
}

int main()
{
	if (isPalindrome(343))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	return 0;
}
