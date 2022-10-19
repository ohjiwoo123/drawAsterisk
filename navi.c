#include <stdio.h>

int flag = 1;
int count =1;
int exitflag=1;
void reculsiveFunc(int num, int i);
void drawUpside(int num, int i);
void drawDownSide(int num, int i);

int main()
{
	int input;
	printf("세로의 길이의 반 값을 입력하시오.\n");
	scanf("%d",&input);
	reculsiveFunc(input,0);
	return 0;
}


void reculsiveFunc(int num, int i)
{

	if(flag==1)
		drawUpside(num,i);
	else if(flag==2)
	{
		drawDownSide(num,count);
		count++;
	}
	i = i+1;
	if(exitflag==0)
		return;
	reculsiveFunc(num,i);
}

void drawUpside(int num, int i)
{
	if(i==num)
	{
		flag=2;
		return;
	}
	// 왼쪽 별
        for (int j = 1; j <= i; j++)
             printf("*");
        // 왼쪽 공백
        for (int k = 1; k < num-i; k++)
            printf(" ");
	for (int l = 1; l < num-i; l++)
            printf(" ");
        // 오른쪽 별
        for (int m = 1; m <= i; m++)
            printf("*");
        printf("\n");
}

void drawDownSide(int num, int i)
{
	if(i==num)
	{
		exitflag=0;
		return;
	}
	for (int j = 1; j < num - i; j++)
		printf("*");
        for (int k = 1; k <= i; k++)
            printf(" ");
	for (int l = 1; l <= i; l++)
            printf(" ");
        for (int m = 1; m < num - i; m++)
            printf("*");
        printf("\n");
}
