#include <stdio.h>
#include <stdlib.h>

void reculsiveFunc(int num, int i);
void drawupside(int num, int i);
void drawdownside(int num, int i);

int flag = 1;
int count =1;
int exitflag = 1;

int main()
{
    int input;
    printf("세로 총 길이의 반을 입력하시오\n");
    scanf("%d",&input);
    reculsiveFunc(input,0);
    sleep(1);
    return 0;
}

void reculsiveFunc(int num,int i)
{
	if(flag==1)
	{
		drawupside(num,i);
	}
	else
	{
		drawdownside(num,count);
		count++;
	}
	i = i+1;
	if(exitflag == 0)
	{
		return;
	}
	reculsiveFunc(num,i);
}

void drawupside(int num, int i)
{
	if(i==num)
	{
		flag=2;
		return;
	}
	// 공백을 line수(세로 중간값임) -1만큼 만든다
	for(int j=num-1;j>i;j--)
        {
            printf(" ");
        }
	// 
        for(int j=0;j<2*i+1;j++)
        {
            printf("*");
        }
//        sleep(1);
        printf("\n");
}

void drawdownside(int num, int i)
{
	if(i==num)
	{
		exitflag=0;
		return;
	}
	for(int j=0;j<i;j++)
        {
            printf(" ");
        }

        for(int j=2*num-1;j>2*i;j--)
        {
            printf("*");
        }
  //      sleep(1);
        printf("\n");
}

