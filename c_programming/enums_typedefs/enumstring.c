
#include <stdio.h>

int main()
{

enum Days{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
	const char *DayNames[] = { "Sunday", "Monday", "Tuesday", /* etc */ };

  Days TheDay;

  int j = 0;

  printf("Please enter the day of the week (0 to 6)\n");

  scanf("%d",&j);

  TheDay = Days(j);

  //how to PRINT THE VALUES stored in TheDay

  //printf("%s",TheDay);  //   isnt working

	printf("%s", DayNames[Sunday]); // prints "Sunday"
	return 0;
}
