
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
}p;

struct student *s = &p;
//struct student *s = (struct student *)malloc(sizeof(struct student));


int main() 
{

    printf("Enter information:\n");
    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);

    printf("Enter roll number: ");
    scanf("%d", &s->roll);
    printf("Enter marks: ");
    scanf("%f", &s->marks);

    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s->name);
    printf("Roll number: %d\n", s->roll);
    printf("Marks: %.1f\n", s->marks);
    fflush(stdin);
    fflush(stdout);
    return 0;
}