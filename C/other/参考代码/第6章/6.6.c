#include "stdio.h"
int isLower(char chChar);
int isLower(char chChar)
{
	if(chChar>='a'&&chChar<='z')
		return 1;
	else 
		return 0;
}

void main()
{
	int iCount=0,i;
	char chString[10];
	gets(chString);
	for(i=0;chString[i]!='\0';i++)
		iCount+=isLower(chString[i]);
	printf("The sum of lower character is %d",iCount);
}
