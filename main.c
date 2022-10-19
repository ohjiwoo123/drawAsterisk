#include <stdio.h>
#include <stdlib.h>

#define ASTERISK 0
#define CIRCLE 1
#define LETTER_A 2
#define LETTER_C 3

#define RHOMBUS 4
#define SANDGLASS 5
#define BOWTIE 6

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure);
void drawTopSidePyramid(int halfLineNumber,int lineCount, char* expression, int chooseFigure);
void drawDownsidePyramid(int halfLineNumber,int lineCount, char* expression, int chooseFigure);

int topBottomFlag = 1;
int downPyramidLineCount = 1;
int exitFlag = 1;
char expression;


int main()
{
    int input;
    int chooseLetter;
    int chooseFigure;
    int halfLineNumber;
    printf("마름모를 그릴지 모레 시계를 나비넥타이를 그릴지 선택하시오\n");
    printf("4번 = 마름모, 5번 = 모래 시계, 6번 = 나비넥타이\n");
    scanf("%d",&chooseFigure);

    printf("가로 총 길이 입력하시오\n");
    scanf("%d",&input);
    halfLineNumber = input/2;

    printf("표시 문자를 선택하세요\n");
    printf("0번 = '*' 1번 = 'o' 2번 'a' 3번 = 'c'\n");
    scanf("%d",&chooseLetter);
    switch(chooseLetter)
    {
	case ASTERISK:
		expression = '*';
		break;
	case CIRCLE:
		expression = 'o';
		break;
	case LETTER_A:
		expression = 'a';
		break;
	case LETTER_C:
		expression = 'c';
		break;
	default:
		break;
    }

    drawFigure(halfLineNumber,0,expression,chooseFigure);
    sleep(1);
    return 0;
}

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(flag==1)
	{
		drawTopSidePyramid(halfLineNumber,lineCount,expression,chooseFigure);
	}
	else
	{
		drawDownsidePyramid(num,downPyramidLineCount,expression,chooseFigure);
		downPyramidLineCount++;
	}
	lineCount = lineCount+1;
	if(exitflag == 0)
	{
		return;
	}
	drawFigure(halfLineNumber,lineCount,expression,chooseFigure);
}

// 위쪽 피라미드
void drawTopSidePyramid(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(lineCount==halfLineNumber)
	{
		topBottomFlag = 2;
		return;
	}

	// 라인 수만큼 for문으로 공백을 만든다
        for(int j=0;j<i;j++)
        {
		drawSpaceBar();
        }
	// 공백 제외하고 라인수에 비고, 홀수개 만큼 별을 찍는다. .
	for(int j=1; j<=((num*2)-(i*2+1));j++)
        {
		drawLetter();
        }
        printf("\n");
}

// 아래쪽 피라미드
void drawDownsidePyramid(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(lineCount==halfLineNumber)
	{
		exitFlag=0;
		return;
	}
	// 라인수 만큼 공백 만든다
	for(int j=1;j<num-i;j++)
        {
		drawSpaceBar();
        }
	// 1 3 5 7 9 라인수에 비례해서 홀수개로 별찍기
        for(int j=0;j<2*i+1;j++)
        {
		drawLetter();
        }
        printf("\n");
}

void drawSpaceBar()
{
	printf(" ");
}

void drawLetter(char* expression)
{
	printf("%c",expression);
}
