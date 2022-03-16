/* Nama Pembuat     : Adilla Rachmawati Pradana (211511002)  */
/*                    Aldrin Rayhan Putra       (211511003)  */
/*                    Devina Lusiana            (211511011)  */
/*                    M Fatur Maulidan Azzahra  (211511020)  */
/*                    Rofi Fauzan Al Habieb     (211511029)  */
/* Kelas            : 1A                                     */
/* Prodi            : D3 Teknik Informatika                  */

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iostream>
using namespace std;

#include "inputHandling.hpp"
// #include "openFile.hpp"
// #include "save.hpp"
// #include "saveAs.hpp"

void setCursorPosition(int x, int y);
void OpenFile(string fileName);
void helpFile();

#define totalLine 40
#define totalColumn 80
#define totalColumnMemory 40

int main()
{
    char mainBoard[totalLine][totalColumn];
    char inputBuffer;
    short int lastColumnMemory[totalColumnMemory];
    short int lineCount = 0;
    short int columnCount = 0;
    short int posX = 0;
    short int posY = 0;
    short int maxLine = 0;
    short int tabLeft = 0;
    short int i = 0;
    short int j = 0;
    bool endInput = false,
         cursorMode = false;
    FILE *myFile;

    char *openedFilename;

    system("cls");

    do
    {
        /* Checking if the line and column counter are working */
        // printf("[%d][%d]\n", lineCount, columnCount);

        inputBuffer = getch();

        /* === STANDARD INPUT === */
        /* Alphabet Number and Other Characters Handling */
        if (isStandardChar(inputBuffer))
        {
            if (lineCount <= 39 && columnCount < 79)
            {
                putchar(inputBuffer);
                setArray(&mainBoard[lineCount][columnCount], inputBuffer);
                columnCount++;
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
            else if (lineCount < 39 && columnCount == 79)
            {
                printf("\n");
                setArray(&mainBoard[lineCount][columnCount], '\n');
                resetValue(&columnCount);
                lineCount++;
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
            else if (lineCount == 39 && columnCount == 79)
            {
                setArray(&mainBoard[lineCount][columnCount], inputBuffer);
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
        }
        /* [BUG-FREE] */

        /* === NON-STANDARD INPUT === */
        /* New Line "Enter" Handling */
        if (isEnter(inputBuffer)) /* FUNCTION */
        {
            if (lineCount < 39 && columnCount <= 79)
            {
                putchar('\n');
                setArray(&mainBoard[lineCount][columnCount], '\n');
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
                resetValue(&columnCount);
                lineCount++;
            }
            else if (lineCount == 39 && columnCount < 79)
            {
                putchar(' ');
                setArray(&mainBoard[lineCount][columnCount], ' ');
                columnCount++;
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
            else if (lineCount == 39 && columnCount == 79)
            {
                setArray(&mainBoard[lineCount][columnCount], ' ');
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
        }
        /* [BUG-FREE] */

        /* "Backspace" Handling */
        if (isBackspace(inputBuffer))
        {
            if (lineCount == 0 && columnCount == 0)
            {
                setCursorPosition(columnCount, lineCount);
                setArray(&mainBoard[lineCount][columnCount], '\0');
            }
            else if ((lineCount >= 0 && lineCount <= 39) && (columnCount >= 1 && columnCount <= 79))
            {
                columnCount--;
                putchar(32);
                setCursorPosition(columnCount, lineCount);
                putchar(32);
                setCursorPosition(columnCount, lineCount);
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
            else if ((lineCount >= 1 && lineCount <= 39) && columnCount == 0)
            {
                lineCount--;
                columnCount = lastColumnMemory[lineCount];
                putchar(32);
                setCursorPosition(columnCount, lineCount);
                setLastColumn(&lastColumnMemory[lineCount], columnCount);
            }
        }
        /* [BUG-FREE] */

        /* Tab Handling */
        if (isTab(inputBuffer))
        {
            resetValue(&tabLeft);
            if ((totalColumn - columnCount) > 4)
            {
                tabLeft = columnCount;
                while (columnCount <= (tabLeft + 4))
                {
                    printf(" ");
                    setArray(&mainBoard[lineCount][columnCount], ' ');
                    columnCount++;
                }
                // printf("[%d | %d]", lineCount, columnCount);
            }
            else if ((totalColumn - columnCount) == 4)
            {
                tabLeft = columnCount;
                while (columnCount <= (tabLeft + 4))
                {
                    printf(" ");
                    setArray(&mainBoard[lineCount][columnCount], ' ');
                    columnCount++;
                    if (columnCount == 79)
                    {
                        printf("\n");
                        setArray(&mainBoard[lineCount][columnCount], '\n');
                        lineCount++;
                    }
                }
            }
            else if ((totalColumn - columnCount) < 4)
            {
                while (columnCount <= totalColumn)
                {
                    printf(" ");
                    setArray(&mainBoard[lineCount][columnCount], inputBuffer);
                    columnCount++;
                    tabLeft++;
                }

                lineCount++;
                resetValue(&columnCount);
                printf("\n");

                while (tabLeft <= 4)
                {
                    printf(" ");
                    setArray(&mainBoard[lineCount][columnCount], inputBuffer);
                    columnCount++;
                    tabLeft++;
                }
            }
        }
        /* [BUG-FREE] */

        /* HELP */
        if (isHelp(inputBuffer)) /* CTRL + B to open Help */
        {
            helpFile();
            printf("\n[Press CTRL + B again to close Help] ");
            inputBuffer = getche();
            if (inputBuffer == 0x02)
            {
                system("cls");
            }
        }
        /* [BUG-FREE] */

        /* Stop writing */
        if (isEndWriting(inputBuffer)) /* CTRL + U to end Input Mode */
        {
            // saveFile("save.txt", lastColumnMemory[], &(*mainBoard[lineCount][columnCount]), maxLine);
            columnCount--;
            endInput = true;
        }

        /* Cursor Mode */
        if (isCursor(inputBuffer)) /* CTRL + G to trigger Cursor Mode */
        {
            /* Reset all needed value */
            cursorMode = false;
            resetConsoleCursor(&posX, &posY);

            /* Temporary container values */
            maxLine = lineCount;
            while (!cursorMode)
            {
                /* Line and Column Position [DEBUG ONLY] */
                // system("cls");
                // printf("[%d,%d]", posY, posX);

                setCursorPosition(posX, posY);
                inputBuffer = getch();
                inputBuffer = toupper(inputBuffer);

                /* Stop Cursor Mode */
                if (isCursor(inputBuffer))
                {
                    fflush(stdin);
                    lineCount = posY;
                    columnCount = posX;
                    cursorMode = true;
                }

                /* Move cursor up */
                if (inputBuffer == 'I')
                {
                    if (posY <= 0)
                    {
                        posY = 0;
                        setCursorPosition(posX, posY);
                    }
                    else if (posY > 0)
                    {
                        if (posX >= lastColumnMemory[posY - 1])
                        {
                            posY--;
                            posX = lastColumnMemory[posY];
                            setCursorPosition(posX, posY);
                        }
                        else if (posX < lastColumnMemory[posY - 1])
                        {
                            posY--;
                            setCursorPosition(posX, posY);
                        }
                    }
                }

                /* Move cursor down */
                if (inputBuffer == 'K')
                {
                    if (posY == maxLine)
                    {
                        setCursorPosition(posX, posY);
                    }
                    else if (posY < maxLine)
                    {
                        if (posX <= lastColumnMemory[posY])
                        {
                            if (posX > lastColumnMemory[posY + 1])
                            {
                                posY++;
                                posX = lastColumnMemory[posY];
                                setCursorPosition(posX, posY);
                            }
                            else if (posX <= lastColumnMemory[posY + 1])
                            {
                                posY++;
                                setCursorPosition(posX, posY);
                            }
                        }
                    }
                }

                /* Move cursor to the left */
                if (inputBuffer == 'J')
                {
                    if (posX == 0)
                    {
                        if (posY > 0)
                        {
                            posY--;
                            posX = lastColumnMemory[posY];
                            setCursorPosition(posX, posY);
                        }
                        else if (posY == 0)
                        {
                            posX = 0;
                            setCursorPosition(posX, posY);
                        }
                    }
                    else if (posX <= lastColumnMemory[posY])
                    {
                        posX--;
                        setCursorPosition(posX, posY);
                    }
                }

                /* Move cursor to the right */
                if (inputBuffer == 'L')
                {
                    if (posX == lastColumnMemory[posY])
                    {
                        if (posY < maxLine)
                        {
                            posY++;
                            posX = 0;
                            setCursorPosition(posX, posY);
                        }
                    }
                    else if (posX < lastColumnMemory[posY])
                    {
                        posX++;
                        setCursorPosition(posX, posY);
                    }
                }

                if (inputBuffer == 'O')
                {
                    posX = 0;
                    setCursorPosition(posX, posY);
                }

                if (inputBuffer == 'P')
                {
                    posX = lastColumnMemory[posY];
                    setCursorPosition(posX, posY);
                }

                if (inputBuffer == 'N')
                {
                    posX = 0;
                    posY = 0;
                    setCursorPosition(posX, posY);
                }

                if (inputBuffer == 'M')
                {
                    posX = lastColumnMemory[maxLine];
                    posY = maxLine;
                    setCursorPosition(posX, posY);
                }
            }
        }
    } while (!endInput);

    myFile = fopen("TESTING.txt", "wt");
    for (i = 0; i <= lineCount; i++)
    {
        for (j = 0; j <= lastColumnMemory[i]; j++)
        {
            fprintf(myFile, "%c", mainBoard[i][j]);
        }
    }

    return 0;
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hOut, coord);
}
/* Devina */
void OpenFile(string fileName)
{
    fstream myFile;
    myFile.open(fileName);
    string line;

    // read file
    if (!myFile.is_open())
    {
        cout << "file cannot be found";
        exit(1);
    }
    while (getline(myFile, line))
    {
        cout << line << endl;
    }
    myFile.close();
}
/* Devina */
void helpFile()
{
    OpenFile("help.txt");
}