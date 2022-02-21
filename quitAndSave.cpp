#include <stdio.h>
#include <conio.h>
#include <windows.h>

void quitAndSave(char text1[10])
{
	char copyText[10];
	FILE *text = fopen("text.txt", "a");
	
	strcpy(copyText,text1);
	
	fprintf(text," %s",copyText);
	
	fclose(text);
}
