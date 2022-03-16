#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "headerMenu.hpp"


void optionMenu()
{
	char pil;
	splashScreen();
	do
	{
		system("cls");
		printf("What will you do?\n\n");
		printf("[1] New text file\n");
		printf("[2] Delete text file\n");
		printf("[3] Open existing file\n");
		printf("[4] Help\n");
		printf("[5] Exit\n\n");
		printf("=============================== By ELM JTK 2021");
		printf("\nOption : ");
		pil = getche();
	
		switch(pil)
		{
			case '1':
				{
					printf("\nbelum ada");
					getch();
					break;
				}
			case '2':
				{
					printf("\nbelum ada");
					getch();
					break;
				}
			case '3' :
				{
					printf("\nModul Fatur");
					getch();
					break;
				}
			case '4' :
				{
					printf("\nModul Help Devina");
					getch();
					break;
				}
			case '5' :
				{
					exit(0);
					break;
				}
		}
	}while(true);
}