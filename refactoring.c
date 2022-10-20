#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ASTERISK 0
#define CIRCLE 1
#define LETTER_A 2
#define LETTER_C 3

#define RHOMBUS 4
#define SANDGLASS 5
#define BOWTIE 6

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure);
void drawTopSide(int halfLineNumber,int lineCount, char* expression, int chooseFigure);
void drawDownSide(int halfLineNumber,int lineCount, char* expression, int chooseFigure);
void drawSpacebar();
void drawLetter();

int topBottomFlag = 1;
int exitFlag = 1;
int downSideLineCount = 1;

int main()
{
    char expression;
    int input;
    int chooseLetter;
    int chooseFigure;
    double halfLineNumber;
    printf("마름모를 그릴지 모레 시계를 나비넥타이를 그릴지 선택하시오\n");
    printf("4번 = 마름모, 5번 = 모래 시계, 6번 = 나비넥타이\n");
    scanf("%d",&chooseFigure);

    printf("가장 긴 길이를 입력하시오\n");
    scanf("%d",&input);
    if(input < 3)
    {
	printf("3보다 작은 값을 입력하였습니다.\n");
	printf("프로그램을 종료합니다..\n");
	return 0;
    }

    halfLineNumber = (double)input/(double)2.0;
    //printf("half : %f\n",halfLineNumber);
    halfLineNumber = ceil(halfLineNumber);
    //printf("half : %f\n",halfLineNumber);

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

    drawFigure((int)halfLineNumber,0,expression,chooseFigure);
    return 0;
}

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(topBottomFlag==1)
	{
		drawTopSide(halfLineNumber,lineCount,expression,chooseFigure);
	}
	else
	{
		drawDownSide(halfLineNumber,downSideLineCount,expression,chooseFigure);
		downSideLineCount++;
	}
	lineCount = lineCount+1;
	if(exitFlag == 0)
	{
		return;
	}
	drawFigure(halfLineNumber,lineCount,expression,chooseFigure);
}

// 위쪽 피라미드
void drawTopSide(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(lineCount==halfLineNumber)
	{
		topBottomFlag = 2;
		return;
	}

	// 마름모
	if(chooseFigure == RHOMBUS)
	{
		// 공백은 점진적으로 줄어들게 만든다
        	for(int startLine=0;startLine < halfLineNumber-lineCount-1;startLine++)
        	{
        	        drawSpacebar();
        	}
        	// 별은 점진적으로 늘어나게 만든다 && 홀수개로 늘어난다
        	for(int startLine=0; startLine<lineCount*2+1;startLine++)
        	{
        	        drawLetter(expression);
        	}
	}

	// 모래시계
	else if(chooseFigure == SANDGLASS)
	{
		// 공백은 점진적으로 늘어난다
		for(int startLine=0; startLine<lineCount;startLine++)
		{
			drawSpacebar();
		}
		// 별은 점진적으로 줄어든다 && 홀수개로 줄어든다
		for(int startLine=1; startLine <= ((halfLineNumber*2)-(lineCount*2+1)); startLine++)
		{
			drawLetter(expression);
		}
	}

	// 나비넥타이
	else if(chooseFigure == BOWTIE)
	{
		// 좌측 별, 점진적으로 늘어난다
		for(int startLine=0;startLine<lineCount+1;startLine++)
		{
			drawLetter(expression);
		}

		// 중간 공백, 점진적으로 줄어든다
		for(int startLine=0;startLine<halfLineNumber*2 - (lineCount+1)*2;startLine++)
		{
			drawSpacebar();
		}

		// 우측 별, 점진적으로 늘어난다
		for(int startLine=0;startLine<lineCount+1;startLine++)
		{
			drawLetter(expression);
		}
	}
	printf("\n");
}

// 아래쪽 부분
void drawDownSide(int halfLineNumber,int lineCount, char* expression, int chooseFigure)
{
	if(lineCount==halfLineNumber)
	{
		exitFlag=0;
		return;
	}

	if(chooseFigure == RHOMBUS)
        {
		// 공백은 점진적으로 늘어나게 만든다
        	for(int startLine=0;startLine<lineCount;startLine++)
        	{
        	        drawSpacebar();
        	}
        	// 별은 점진적으로 줄어들게 만든다 && 홀수개로 줄어든다
        	for(int startLine=0;startLine<halfLineNumber*2 -lineCount*2-1;startLine++)
        	{
        	        drawLetter(expression);
        	}
        }

        else if(chooseFigure == SANDGLASS)
        {
		// 공백은 점진적으로 줄어든다
		for(int startLine=1;startLine<halfLineNumber-lineCount;startLine++)
		{
			drawSpacebar();
		}
		// 별은 점진적으로 늘어난다 && 홀수개로 늘어난다
		for(int startLine=1;startLine<=lineCount*2+1;startLine++)
		{
			drawLetter(expression);
		}
        }

        else if(chooseFigure == BOWTIE)
        {
		// 좌측 별, 점진적으로 줄어든다
                for(int startLine=0; startLine < halfLineNumber - lineCount; startLine++)
                {
			drawLetter(expression);
                }

                // 중간 공백, 점진적으로 늘어든다
                for(int startLine=0; startLine<lineCount*2;startLine++)
                {
			drawSpacebar();
                }

                // 우측 별, 점진적으로 줄어든다
                for(int startLine=0; startLine < halfLineNumber - lineCount; startLine++)
                {
			drawLetter(expression);
                }
        }
	printf("\n");
}

void drawSpacebar()
{
	printf(" ");
}

void drawLetter(char* expression)
{
	printf("%c",expression);
}
