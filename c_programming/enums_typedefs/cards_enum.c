#include<stdio.h>

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 30
};

int main() 
{
    // Initializing a variable that will hold the enums
    enum suit current_card = club;
	printf("Value of club = %d \n", current_card);	

	current_card = hearts;
	printf("Value of hearts = %d \n", current_card);	
	return 0;
}