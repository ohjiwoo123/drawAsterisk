#include <stdio.h>

int main()
{
	char a = 'b';


	printf("STR = %c\n",a);
	//printf("STR = %s\n",a);
	printf("STR = %p\n",a);
	printf("STR = %p\n",&a);

	check(a);
	return 0;
}


void check(char* aa)
{

	printf("a= %c\n",aa);
}
