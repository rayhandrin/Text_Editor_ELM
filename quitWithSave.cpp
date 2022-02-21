#include <stdio.h>
#include <conio.h>
#include <windows.h>

void quitAndSave(char text1[10])
{
	char copyText[10];
	
	//Membuka dan membuat file dengan format file txt
	FILE *text = fopen("text.txt", "a");
	
	//Meng copy kan text yang sudah di inputkan ke dalam variabel copyText bertipe char 
	strcpy(copyText,text1);
	
	//Memasukan text kedalam file 
	fprintf(text," %s",copyText);
	
	//Menutup file
	fclose(text);
}
