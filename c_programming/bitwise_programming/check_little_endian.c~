/* 
   Function check_for_endianness() returns 1, if architecture 
   is little endian, 0 in case of big endian.
 */

#include <stdio.h>
 
int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

int main()
{
	if (check_for_endianness())
		printf("The machine is little endian\n");
	else
		printf("The machine is big endian\n");
	return 0;
}
