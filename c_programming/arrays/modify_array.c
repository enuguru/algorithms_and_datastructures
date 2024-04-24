
#include <stdio.h>
void main()
{
	int myNumbers[] = {25, 50, 75, 100};
	myNumbers[0] = 33;

	printf("%d", myNumbers[0]);

	// Now outputs 33 instead of 25
}
