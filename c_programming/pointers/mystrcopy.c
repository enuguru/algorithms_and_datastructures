
#include <stdio.h>

void mystrcopy(char *str1, char *str2)
{
	while(*str1 != '\0')
	{
		*str2 = *str1;
		str1++; str2++;
	}
}

int main()
{
	char str1[15] = "Ravikumar";
	char str2[15] = "Premkumar";
	mystrcopy(str1,str2);
	printf("%s\n",str1);
	printf("%s\n",str2);
	return 0;
}
