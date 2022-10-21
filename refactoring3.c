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

#define TOP 7
#define BOTTOM 8

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag);
void drawRhombus(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag);
void drawSandglass(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag);
void drawBowtie(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag);

void drawSpacebar();
void drawLetter(char* expression);

int exitFlag = 1;

int main()
{
	int topBottomFlag = 7;  // top = 7, bottom = 8
	char expression;
	int input;
	int chooseLetter;
	int chooseFigure;
	int lineCount = 0;

	// 가장 긴 변의 길이의 중간 값, 기준점이 된다.
	// 기준점을 기준으로 ----기준점---- 양방향의 길이가 같다.
	double halfLineNumber;
	printf("마름모를 그릴지 모레 시계를 나비넥타이를 그릴지 선택하시오\n");
	printf("4번 = 마름모, 5번 = 모래 시계, 6번 = 나비넥타이\n");
	scanf("%d",&chooseFigure);

	printf("가장 긴 길이를 입력하시오\n");
	scanf("%d",&input);
	if (input < 2)
	{
	        printf("2보다 작은 값을 입력하였습니다\n");
	        printf("프로그램을 종료합니다\n");
        	return 0;
    	}
    	halfLineNumber = (double)input/(double)2.0;
    	// 모든 값을 올림하여 계산 ex) input 11, halfLineNumber = 5.5, 올림 후 halfLineNumber = 6
    	halfLineNumber = ceil(halfLineNumber);

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

    	drawFigure((int)halfLineNumber,lineCount,expression,chooseFigure,topBottomFlag);
    	return 0;
}

void drawFigure(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag)
{
 	if(lineCount==halfLineNumber && topBottomFlag == TOP)
	{
	        // 아랫부분 그리기로 전환
		topBottomFlag = 8;
	        lineCount=1;
	}
	if(lineCount==halfLineNumber && topBottomFlag == BOTTOM)
	{
		exitFlag=0;
		return;
	}

    	switch(chooseFigure)
    	{
        	case RHOMBUS:
        		drawRhombus(halfLineNumber,lineCount,expression,chooseFigure, topBottomFlag);
        		break;
        	case SANDGLASS:
            		drawSandglass(halfLineNumber,lineCount,expression,chooseFigure, topBottomFlag);
        		break;
        	case BOWTIE:
        		drawBowtie(halfLineNumber,lineCount,expression,chooseFigure, topBottomFlag);
        		break;
        	default:
        		break;
	}

	lineCount = lineCount+1;
	if(exitFlag == 0)
	{
		return;
	}
	drawFigure(halfLineNumber,lineCount,expression,chooseFigure,topBottomFlag);
}

void drawSpacebar()
{
	printf(" ");
	return;
}

void drawLetter(char* expression)
{
	printf("%c",expression);
	return;
}

// 마름모
void drawRhombus(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag)
{
	if(topBottomFlag == TOP)
	{
	        // 공백은 점진적으로 줄어들게 만든다
	        for(int start=0;start < halfLineNumber-lineCount+1;start++)
	        {
	            drawSpacebar();
	        }
	        // 별은 점진적으로 늘어나게 만든다 && 홀수개로 늘어난다
	        for(int start=0; start<lineCount*2+1;start++)
	        {
	            drawLetter(expression);
	        }
	}
	else if(topBottomFlag == BOTTOM)
	{
	    // 공백은 점진                                                                                                                                                                                                                           적으로 늘어나게 만든다
	    for(int start=0;start<lineCount;start++)
	    {
	        drawSpacebar();
	    }
	    // 별은 점진적으로 줄어들게 만든다 && 홀수개로 줄어든다
	    for(int start=0;start<halfLineNumber*2 -lineCount*2-1;start++)
	    {
	        drawLetter(expression);
	    }
	}
	printf("\n");
	return;
}

// 모래시계
void drawSandglass(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag)
{
	int countSpacebar = 0;

	if(topBottomFlag == TOP)
	{
	        // 공백은 점진적으로 늘어난다
		for(int start=0; start<lineCount;start++)
		{
			drawSpacebar();
			countSpacebar = countSpacebar + 1;
		}
		// 별은 점진적으로 줄어든다 && 홀수개로 줄어든다
		//for(int start=0; start < ((halfLineNumber*2)-(lineCount*2+1)); start++)
		for(int start=0; start < ((halfLineNumber*2)-(countSpacebar*2+1)); start++)
		{
			drawLetter(expression);
		}
		}
	else if(topBottomFlag == BOTTOM)
	{
	        // 공백은 점진적으로 줄어든다
		for(int start=0;start<halfLineNumber-lineCount-1;start++)
		{
			drawSpacebar();
		}
		// 별은 점진적으로 늘어난다 && 홀수개로 늘어난다
		for(int start=0;start<lineCount*2+1;start++)
		{
			drawLetter(expression);
		}
	}
	printf("\n");
	return;
}

// 나비넥타이
void drawBowtie(int halfLineNumber,int lineCount, char* expression, int chooseFigure,int topBottomFlag)
{
	int countLetter = 0;
	if(topBottomFlag == TOP)
	{
        	// 좌측 별, 점진적으로 늘어난다
		for(int start=0;start<lineCount+1;start++)
		{
			drawLetter(expression);
			countLetter = countLetter + 1;
		}

		// 중간 공백, 점진적으로 줄어든다
		//for(int start=1;start<halfLineNumber*2 -(lineCount+1)*2;start++)
		for(int start=0;start<halfLineNumber*2 - countLetter*2 -1;start++)
		{
			drawSpacebar();
		}

	        // 가장 긴 변에 속하는 Line에서는 우측 별을 하나를 덜 그리게 만든다.
		if((lineCount+1)!=halfLineNumber)
		{
			// 우측 별, 점진적으로 늘어난다
			for(int start=0;start<countLetter;start++)
			{
				drawLetter(expression);
			}
		}
		else
		{
        		// 우측 별, 점진적으로 늘어난다
        		// start을 1부터 시작함으로서 별 하나를 덜 그린다
			for(int start=0; start<countLetter-1;start++)
			{
				drawLetter(expression);
			}
		}
    	}
	else if(topBottomFlag == BOTTOM)
	{
	        // 좌측 별, 점진적으로 줄어든다
	        for(int start=0; start < halfLineNumber - lineCount; start++)
	        {
	            drawLetter(expression);
	        }

	        // 중간 공백, 점진적으로 늘어든다
	        for(int start=0; start<lineCount*2-1;start++)
	        {
       			drawSpacebar();
 		}

        	// 우측 별, 점진적으로 줄어든다
        	for(int start=0; start < halfLineNumber - lineCount; start++)
        	{
        		drawLetter(expression);
    		}
    	}
	printf("\n");
	return;
}
