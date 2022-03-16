#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "headerMenu.hpp"

void quitProgram()
{
	char pil2, pil3;
	bool status = true;
	do
	{
		system("cls");
		printf("=== Quit Program ==\n");
		printf("[1] YES\n");
		printf("[2] NO\n\n");
		printf("Option : ");
		pil2 = getche();
		
		switch(pil2)
		{
			case '1':
				{
					system("cls");
					while(status == false)
					{
						printf("Do you want save this File\n\n");
						printf("Press 1 to Save or 2 to Quit Without Save : ");
						pil3 = getche();
			
						switch(pil3)
						{
							case '1':
								{
									printf("\nModul Save/SaveAs");
									getch();
									exit(0);
									break;
								}
							case '2':
								{
									exit(0);
									break;
								}
						}
					}
					if (status == true)
					{
						printf("berhasil");
						exit(0);
					}
					break;
				}
			case '2':
				{
					printf("Back to program");
					getch();
					break;
				}
		}
	}while(true);
}