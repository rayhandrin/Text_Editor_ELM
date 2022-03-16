// #include "inputHandling.hpp"

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