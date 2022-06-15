
#include <stdio.h>

int main()
{
union
{
  int i;
  float f;
} u;

// Convert floating-point bits to integer:
u.f = 3.14159f;
printf("As integer: %08x\n", u.i);
return 0;
}
