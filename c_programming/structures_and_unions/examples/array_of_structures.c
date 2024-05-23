

#include <stdio.h>

int main()
{
	struct account
	{
		char name[10];
		int type;
		flat balance;
	};

	struct account bankaccount[3];
	bankaccount[0].type = 5;
	bankaccount[0].balance = 890;
	bankaccount[1].type = 10;
	bankaccount[2].type = 3;
	return 0;
}
