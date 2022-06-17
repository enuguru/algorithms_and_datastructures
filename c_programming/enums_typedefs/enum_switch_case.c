#include <stdio.h> 
enum day {sunday , monday, tuesday, 
          wednesday, thursday, friday, saturday}; 
  
int main() 
{
  // Enums can also take their integer equivalent values
  enum day today = 4;
  printf(" %s \n",day[today]);
  switch(today)
  {
    case sunday:
      printf("The day today is Sunday");
      break;
    case monday:
      printf("The day today is Monday");
      break;
    case tuesday:
      printf("The day today is Tuesday");
      break;
    case wednesday:
      printf("The day today is Wednesday");
      break;
    case thursday:
      printf("The day today is Thursday");
      break;
    case friday:
      printf("The day today is Friday");
      break;
    default:
      printf("The day today is Saturday");
  }
    return 0; 
} 