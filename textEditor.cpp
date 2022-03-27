#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

#include "mainfunctions.h"
#include "inputhandling.h"
#include "cursorcontrol.h"
#include "arrayutils.h"
#include "extrafeatures.h"
#include "texteditor.h"
#include "setCursorPosition.h"

#define totalLine 40
#define totalColumn 80
#define totalColumnMemory 40

void text_editor()
{
    /* Kamus Lokal */
    typedef struct
    {
        short int line = 0;
        short int column = 0;
    } array_var;

    char mainBoard[totalLine][totalColumn],
        nama_file_save_as[25],
        nama_file_baru[25],
        nama_file_open[25],
        inputBuffer,
        konfirmasi_timpa;

    short int lastColumnMemory[totalColumnMemory],
        lastLineMemory = 0,
        maxLine = 0,
        tabLeft = 0;

    bool inputMode = false,
         cursorMode = false,
         newFile = true,
         same_filename_detected,
         adding_input_deteced = false,
         removing_input_detected = false,
         new_line_changed = false;

    array_var elementIndicator,
        access,
        element,
        cursor;

    elementIndicator.line = 7;
    elementIndicator.column = 0;

    /* Algoritma */
    clear_1d_array(lastColumnMemory);
    clear_2d_array((char *)mainBoard);

    system("cls");
    upperRibbon(&element.column, &element.line);

    /* Show working line */
    show_working_line(&element.line);

    do
    {
        inputBuffer = getch();

        /* === STANDARD INPUT === */
        /* Alphabet Number and Other Characters Handling */
        if (isprint(inputBuffer))
        {
            if (element.line <= 39 && element.column < 78)
            {
                standard_input_kondisi1(&inputBuffer, &access.column, &access.line, &element.column, &element.line, &elementIndicator.column, &elementIndicator.line, &mainBoard[element.line][element.column], lastColumnMemory, &maxLine);
            }
            else if (element.line < 39 && element.column == 78)
            {
                standard_input_kondisi2(&inputBuffer, &access.column, &access.line, &element.column, &element.line, &elementIndicator.column, &elementIndicator.line, &mainBoard[element.line][element.column], lastColumnMemory, &lastLineMemory, &maxLine);
            }
            else if (element.line == 39 && element.column == 79)
            {
                standard_input_kondisi3(&mainBoard[element.line][element.column], &inputBuffer, &element.line, &element.column, lastColumnMemory);
            }
        }
        /* [BUG-FREE] */

        /* === NON-STANDARD INPUT === */
        /* Still containing bug */
        if (isEnter(inputBuffer)) /* FUNCTION */
        {
            if (element.line < 39 && element.column < 79)
            {
                if (element.line < maxLine)
                {
                    maxLine++;
                    lastColumnMemory[maxLine] = 0;
                    if (element.column < lastColumnMemory[element.line])
                    {
                        putchar('\n');
                        setArray(&mainBoard[element.line][element.column], '\n');

                        for (access.line = maxLine; access.line > element.line + 1; access.line--)
                        {
                            lastColumnMemory[access.line] = lastColumnMemory[access.line - 1];
                            for (access.column = lastColumnMemory[access.line]; access.column <= lastColumnMemory[access.line - 1]; access.column--)
                            {
                                mainBoard[access.line][access.column] = mainBoard[access.line - 1][access.column];
                                mainBoard[access.line - 1][access.column] = '\0';

                                setCursorPosition(element.column, (element.line + (maxLine) + 9));

                                putchar(mainBoard[element.line][access.column]);
                            }
                        }
                        setLastColumn(&lastColumnMemory[element.line + 1], lastColumnMemory[element.line] - element.column);
                        setLastColumn(&lastColumnMemory[element.line], lastColumnMemory[element.line] - (lastColumnMemory[element.line] - element.column));

                        for (; element.column <= lastColumnMemory[element.line]; element.column++)
                        {
                            access.column = 0;
                            mainBoard[element.line + 1][access.column] = mainBoard[element.line][element.column];
                            putchar(mainBoard[element.line + 1][access.column]);
                            mainBoard[element.line][element.column] = '\0';
                            access.column++;
                        }
                    }
                    element.line++;
                    resetValue(&element.column);

                    setCursorPosition(elementIndicator.column, elementIndicator.line);
                    printf("Ln %2d, Col %2d", element.line, element.column);

                    setCursorPosition(element.column, (element.line + (maxLine - 1) + 9));
                    printf("%2d |  ", maxLine);
                }
                else
                {
                    putchar('\n');
                    setArray(&mainBoard[element.line][element.column], '\n');
                    setLastColumn(&lastColumnMemory[element.line], element.column);

                    element.line++;
                    resetValue(&element.column);

                    setCursorPosition(elementIndicator.column, elementIndicator.line);
                    printf("Ln %2d, Col %2d", element.line, element.column);

                    setCursorPosition(element.column, (element.line + 9));
                    printf("%2d |  ", element.line);
                }
            }
            else if (element.line == 39 && element.column < 79)
            {
                putchar(' ');
                setArray(&mainBoard[element.line][element.column], ' ');
                element.column++;
                setLastColumn(&lastColumnMemory[element.line], element.column);
            }
            else if (element.line == 39 && element.column == 79)
            {
                setArray(&mainBoard[element.line][element.column], ' ');
                setLastColumn(&lastColumnMemory[element.line], element.column);
            }
        }
        /* [BUG-FREE] */
        /* Still Bug */

        /* "Backspace" Handling */
        if (isBackspace(inputBuffer))
        {
            if (element.line == 0 && element.column == 0) /* Kondisi 1 */
            {
                backspace_kondisi1(&element.column, &element.line, (char *)mainBoard);
            }
            else if ((element.line >= 0 && element.line <= 39) && (element.column >= 1 && element.column <= 79)) /* Kondisi 2 */
            {
                backspace_kondisi2(&element.column, &element.line, &mainBoard[element.line][element.column], &lastColumnMemory[element.line], &elementIndicator.column, &elementIndicator.line);
            }
            else if ((element.line >= 1 && element.line <= 39) && element.column == 0) /* Kondisi 3 */
            {
                backspace_kondisi3(&element.column, &element.line, (char *)mainBoard, lastColumnMemory, &elementIndicator.column, &elementIndicator.line, &maxLine);
            }
        }
        /* [BUG-FREE] */

        /* Tab Handling */
        if (isTab(inputBuffer))
        {
            resetValue(&tabLeft);
            if ((totalColumn - element.column) > 4) /* Kondisi 1 */
            {
                tabLeft = element.column;
                while (element.column <= (tabLeft + 4))
                {
                    printf(" ");
                    setArray(&mainBoard[element.line][element.column], ' ');
                    element.column++;
                }
            }
            else if ((totalColumn - element.column) == 4) /* Kondisi 2 */
            {
                tabLeft = element.column;
                while (element.column <= (tabLeft + 4))
                {
                    printf(" ");
                    setArray(&mainBoard[element.line][element.column], ' ');
                    element.column++;
                    if (element.column == 79)
                    {
                        printf("\n");
                        setArray(&mainBoard[element.line][element.column], '\n');
                        element.line++;
                    }
                }
            }
            else if ((totalColumn - element.column) < 4) /* Kondisi 3 */
            {
                while (element.column <= totalColumn)
                {
                    printf(" ");
                    setArray(&mainBoard[element.line][element.column], inputBuffer);
                    element.column++;
                    tabLeft++;
                }

                element.line++;
                resetValue(&element.column);
                printf("\n");

                while (tabLeft <= 4)
                {
                    printf(" ");
                    setArray(&mainBoard[element.line][element.column], inputBuffer);
                    element.column++;
                    tabLeft++;
                }
            }
        }
        /* [BUG-FREE] */

        /* Save File */
        if (isSave(inputBuffer))
        {
            if (newFile == true)
            {
                do
                {
                    print_save_info();
                    gets(nama_file_baru);
                    same_filename_detected = is_same_filename_exits(nama_file_baru);

                    if (same_filename_detected == true)
                    {
                        print_save_confirmation();

                        konfirmasi_timpa = getche();
                        konfirmasi_timpa = toupper(konfirmasi_timpa);

                        if (konfirmasi_timpa == 'Y')
                        {
                            same_filename_detected = true;
                        }
                        else if (konfirmasi_timpa != 'Y')
                        {
                            same_filename_detected = false;
                        }
                    }
                    else
                    {
                        same_filename_detected = true;
                    }
                } while (same_filename_detected == false);

                clear_first_line();
                save_file(lastColumnMemory, (char *)mainBoard, maxLine, nama_file_baru);

                /* Mencetak informasi bahwa file sudah disimpan */
                printf("[%20s] - SAVED", nama_file_baru);

                /* Mengubah isi dari variabel boolean ini agar */
                /* tidak perlu meminta nama kembali setelahnya */
                newFile = false;

                /* Kursor pindah ke tempat terakhir mengetik */
                printf("\u001b[%d;%dH", (element.line + 10), (element.column + 7));
            }
            else
            {
                clear_first_line();
                save_file(lastColumnMemory, (char *)mainBoard, maxLine, nama_file_baru);

                /* Mencetak informasi bahwa file sudah disimpan */
                printf("[%20s] - SAVED", nama_file_baru);

                /* Kursor pindah ke tempat terakhir mengetik */
                printf("\u001b[%d;%dH", (element.line + 10), (element.column + 7));
            }
        }

        if (isSaveAs(inputBuffer))
        {
            if (newFile == true)
            {
                do
                {
                    print_save_info();
                    gets(nama_file_baru);
                    same_filename_detected = is_same_filename_exits(nama_file_baru);

                    if (same_filename_detected == true)
                    {
                        print_save_confirmation();

                        konfirmasi_timpa = getche();
                        konfirmasi_timpa = toupper(konfirmasi_timpa);

                        if (konfirmasi_timpa == 'Y')
                        {
                            same_filename_detected = true;
                        }
                        else if (konfirmasi_timpa != 'Y')
                        {
                            same_filename_detected = false;
                        }
                    }
                    else
                    {
                        same_filename_detected = true;
                    }
                } while (same_filename_detected == false);

                clear_first_line();

                /* Mencetak informasi bahwa file sudah disimpan */
                printf("[%20s] - SAVED", nama_file_baru);

                save_file(lastColumnMemory, (char *)mainBoard, maxLine, nama_file_baru);

                /* Mengubah isi dari variabel boolean ini agar */
                /* tidak perlu meminta nama kembali setelahnya */
                newFile = false;

                /* Kursor pindah ke tempat terakhir mengetik */
                printf("\u001b[%d;%dH", (element.line + 10), (element.column + 7));
            }
            else
            {
                clear_first_line();

                /* Mencetak bagian pengisian nama file baru */
                printf("SAVE AS - Masukan nama file (termasuk .txt) [                         ]");

                /* Memosisikan kursor supaya berada pada awal kotak (pengisian nama file) */
                printf("\u001b[0;46H");

                gets(nama_file_save_as);

                save_as(nama_file_save_as, nama_file_baru);

                clear_first_line();

                /* Mencetak informasi bahwa file sudah disimpan */
                printf("[%20s] - SAVED", nama_file_save_as);

                /* Nama file yang baru disalin ke variabel save supaya */
                strcpy(nama_file_baru, nama_file_save_as);

                /* Mengubah isi dari variabel boolean ini agar */
                /* tidak perlu meminta nama kembali setelahnya */
                newFile = false;

                /* Kursor pindah ke tempat terakhir mengetik */
                printf("\u001b[%d;%dH", (element.line + 10), (element.column + 7));
            }
        }

        /* Stop writing */
        if (isEndWriting(inputBuffer)) /* CTRL + U to end Input Mode */
        {
            inputMode = true;
        }

        /* Membuka file */
        if (isOpen(inputBuffer)) /* CTRL + O to end Input Mode */
        {
            open_file(&inputBuffer, &access.column, &access.line, &element.column, &element.line, &elementIndicator.column, &elementIndicator.line, (char *)mainBoard, &maxLine, lastColumnMemory, nama_file_open, nama_file_baru, &newFile);
        }

        /* Cursor Mode */
        if (isCursor(inputBuffer)) /* CTRL + G to trigger Cursor Mode */
        {
            reset_all_curvars_to_default(&cursor.column, &cursor.line, &cursorMode);

            maximum_line_picker(&element.line, &lastLineMemory, &maxLine);

            while (!cursorMode)
            {
                inputBuffer = getch();
                inputBuffer = toupper(inputBuffer);

                if (isCursor(inputBuffer))
                {
                    stop_cursor(&element.column, &element.line, &cursor.column, &cursor.line, &cursorMode);
                }

                if (is_move_cursor_up(inputBuffer) == true)
                {
                    move_cursor_up(&cursor.column, &cursor.line, lastColumnMemory);
                }

                if (is_move_cursor_down(inputBuffer) == true)
                {
                    move_cursor_down(&cursor.column, &cursor.line, lastColumnMemory, &maxLine);
                }

                if (is_move_cursor_left(inputBuffer) == true)
                {
                    move_cursor_left(&cursor.column, &cursor.line, lastColumnMemory);
                }

                if (is_move_cursor_right(inputBuffer) == true)
                {
                    move_cursor_right(&cursor.column, &cursor.line, lastColumnMemory, &maxLine);
                }

                if (is_begining_of_line(inputBuffer) == true)
                {
                    begining_of_line(&cursor.column, &cursor.line);
                }

                if (is_end_of_line(inputBuffer) == true)
                {
                    end_of_line(&cursor.column, &cursor.line, lastColumnMemory);
                }

                if (is_begining_of_text(inputBuffer) == true)
                {
                    begining_of_text(&cursor.column, &cursor.line);
                }

                if (is_end_of_text(inputBuffer) == true)
                {
                    end_of_text(&cursor.column, &cursor.line, lastColumnMemory, &maxLine);
                }
            }
        }
    } while (!inputMode);
}
