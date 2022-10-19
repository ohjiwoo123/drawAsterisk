#include <stdio.h>

void printSomething();

int count = 0;

int main()
{
	printSomething(10);
	return 0;
}



void printSomething(int count)
{
	if (count ==0)
	{
		return;
	}
	printf("*");
	printSomething(count-1);
}
