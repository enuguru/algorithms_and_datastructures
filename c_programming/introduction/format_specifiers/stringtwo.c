#include <stdio.h>
int main()
{
	char str[] = "Early to rise and early to bed";
	printf("%20s\n", str);
	printf("%-20s\n", str);
	printf("%20.5s\n", str);
	printf("%-20.5s\n", str);
	return 0;
}
