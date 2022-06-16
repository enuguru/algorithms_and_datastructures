
#include <stdio.h>

struct student {
    char name[50];
    int roll;
    float marks;
}s[3];

int main() 
{
    for(int index=0; index<3; index++)
    {
    printf("Enter information:\n");
    printf("Enter name: ");
    fflush(stdin);
    fgets(s[index].name, sizeof(s[index].name), stdin);

    printf("Enter roll number: ");
    scanf("%d", &s[index].roll);
    printf("Enter marks: ");
    scanf("%f", &s[index].marks);

    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s[index].name);
    printf("Roll number: %d\n", s[index].roll);
    printf("Marks: %.1f\n", s[index].marks);
    }

    return 0;
}
