#ifndef inputHandling_hpp
#define inputHandling_hpp

// /* === STANDARD === */
// /* Memeriksa apakah masukan user adalah inputBuffer >= 32 && inputBuffer <= 126 */
// bool isStandardChar(char myBuffer);

// /* === NONSTANDARD === */
// /* Memeriksa apakah masukan user adalah Enter  */
// bool isEnter(char myBuffer);

// /* Memeriksa apakah masukan user adalah CTRL + H */
// bool isBackspace(char myBuffer);

// /* Memeriksa apakah masukan user adalah CTRL + I */
// bool isTab(char myBuffer);

// /* Memeriksa apakah masukan user adalah CTRL + B */
// bool isHelp(char myBuffer);

// /* Memeriksa apakah masukan user adalah CTRL + G */
// bool isCursor(char myBuffer);

// /* Memeriksa apakah masukan user adalah CTRL + U */
// bool isEndWriting(char myBuffer);

// /* Memeriksa apakah masukan user adalah arrow key atas */
// bool isArrowUp(char myBuffer);

// /* Memeriksa apakah masukan user adalah arrow key bawah */
// bool isArrowDown(char myBuffer);

// /* Memeriksa apakah masukan user adalah arrow key kanan */
// bool isArrowRight(char myBuffer);

// /* Memeriksa apakah masukan user adalah arrow key kiri */
// bool isArrowLeft(char myBuffer);

// /* === VARIABLE RELATED === */
// /* Mengisi elemen dari array */
// void setArray(char *myArray, char myInput);

// /* Mengisi array penampung banyaknya kolom pada suatu baris */
// void setLastColumn(short int *myArray, short int myInput);

// /* Mengembalikan value suatu variabel menjadi 0 */
// void resetValue(short int *myVariable);

// /* Mengembalikan posisi cursor pada konsol menjadi [0, 0] */
// void resetConsoleCursor(short int *x, short int *y);

/* DESKRIPSI FUNGSI */

/* Aldrin */
void setArray(char *myArray, char myInput)
{
    *myArray = myInput;
}

/* Aldrin */
void setLastColumn(short int *myArray, short int myInput)
{
    *myArray = myInput;
}

/* Aldrin */
void resetValue(short int *myVariable)
{
    *myVariable = 0;
}

/* Aldrin */
void resetConsoleCursor(short int *x, short int *y)
{
    *x = 0;
    *y = 0;
}

/* Aldrin */
bool isStandardChar(char myBuffer)
{
    if (myBuffer >= 32 && myBuffer <= 126)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isEnter(char myBuffer)
{
    if (myBuffer == 0x0d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isBackspace(char myBuffer)
{
    if (myBuffer == 0x08)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isTab(char myBuffer)
{
    if (myBuffer == 0x09)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isHelp(char myBuffer)
{
    if (myBuffer == 0x02)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isEndWriting(char myBuffer)
{
    if (myBuffer == 0x15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isCursor(char myBuffer)
{
    if (myBuffer == 0x07)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowDown(char myBuffer)
{
    if (myBuffer == 0x50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowUp(char myBuffer)
{
    if (myBuffer == 0x48)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowLeft(char myBuffer)
{
    if (myBuffer == 0x4B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowRight(char myBuffer)
{
    if (myBuffer == 0x4D)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif