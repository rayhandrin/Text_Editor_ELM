/* Nama Pembuat     : Adilla Rachmawati Pradana (211511002)  /
/                    Aldrin Rayhan Putra       (211511003)   /
/                    Devina Lusiana            (211511011)   /
/                    M Fatur Maulidan Azzahra  (211511020)   /
/                    Rofi Fauzan Al Habieb     (211511029)   /
/ Kelas            : 1A                                      /
/ Prodi            : D3 Teknik Informatika                  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "extrafeatures.h"
#include "helpFile.h"
#include "showFolder.h"
#include "mainfunctions.h"
#include "texteditor.h"

int main()
{
    char pil;
    char chooseDelete[25];
    char duplikatRename[25], chooseDuplikat[25];

splashScreen();
    do
    {
        system("cls");
        printf("What will you do?\n\n");
        printf("[1] New text file\n");
        printf("[2] Delete text file\n");
        printf("[3] Duplikat File\n");
        printf("[4] Help\n");
        printf("[5] Exit\n\n");
        printf("=============================== By ELM JTK 2021\n");
        printf("Option : ");
        pil = getche();

	switch (pil)
    {
        case '1':
        {
            text_editor();
            break;
        }
        case '2':
        {
            system("cls");
            splashScreen();
            showFolder();
            printf("\n\nChoose file you want to delete [include with extension file]\n");
            printf("Name File : ");
            gets(chooseDelete);
            if (is_same_filename_exits(chooseDelete) == true)
            {
                delete_file(chooseDelete);
                printf("File berhasil dihapus\n");
            }
            else
            {
                printf("File tidak ada!\n");
            }
            system("Pause");
            break;
        }
        case '3':
        {
            system("cls");
            showFolder();
            printf("Pilih File untuk diduplikasi : ");
            gets(chooseDuplikat);
            if (is_same_filename_exits(chooseDuplikat) == true)
            {
                printf("\nSilahkan ganti nama File untuk diduplikasi : ");
                gets(duplikatRename);
                copy_file(chooseDuplikat, duplikatRename);
            }
            else
            {
                printf("File tidak ada!\n");
            }
            system("Pause");
            break;
        }
        case '4':
        {
            system("cls");
            splashScreen();
            helpFile();
            system("Pause");
            break;
        }
        case '5':
        {
            exit(0);
            break;
        }
    }

} while (true);

return 0;
}