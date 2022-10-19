#include <stdio.h>
int main()
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;

    // 반 자르고 위에 부분
    for (i = 0; i < 5; i ++)
    {
	// 왼쪽 윗 부분 공백
        for (j = 0; j <= i; j++)
             printf(" ");
	// 왼쪽 별
        for (k = 0; k < 5 - i; k++)
            printf("*");
	// 오른쪽 별
        for (l = 0; l < 5 - i; l++)
            printf("*");
	// 오른쪽 공백
        for (m = 0; m <= i; m++)
            printf(" ");
        printf("\n");
    }

    // 반 자르고 아래 부분
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5 - i; j++)
            printf(" ");
        for (k = 0; k <= i; k++)
            printf("*");
        for (l = 0; l <= i; l++)
            printf("*");
        for (m = 0; m < 5 - i; m++)
            printf(" ");

        printf("\n");
    }
}


