#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create struct with person1 variable
struct Person {
  char name[50];
  int citNo;
  float salary;
};


// struct Person person2;

int main() 
{

struct Person *person1;
person1 = (struct Person *)malloc(sizeof(struct Person));
  // assign value to name of person1
  strcpy(person1->name, "George Orwell");

  // assign values to other person1 variables
  person1->citNo = 1984;
  person1->salary = 2500;

  // print struct variables
  printf("Name: %s\n", person1->name);
  printf("Citizenship No.: %d\n", person1->citNo);
  printf("Salary: %.2f", person1->salary);

  return 0;
}
