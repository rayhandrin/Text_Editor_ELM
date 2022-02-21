#include <cstdio>
#include <cstdlib>

void copyIsiFile(char filename[8]);

int main () {
    char newFileName[15];

    /* Memasukan nama baru untuk file (saveAs) */
    /* File harus sudah ada */
    printf ("File name (.txt) : ");
    scanf  ("%s", newFileName);

    copyIsiFile(newFileName);

    return 0;
}

/* Menyalin isi dari file lama ke dalam file dengan nama baru */
/* Akan dibuatkan file baru */
void copyIsiFile(char filename[8]) {
    char temporaryString[80];
    FILE *sourceFile;
    FILE *destinationFile;

    sourceFile      = fopen ("oldFile.txt", "rt+");
    if (sourceFile == NULL) {
        perror ("Source file doesn't exist in this directory!");
        exit(1);
    } else {
        destinationFile = fopen (filename, "wt+");
        rewind (sourceFile);
        while (!feof(sourceFile)) {
            fgets   (temporaryString, sizeof (temporaryString), sourceFile);
            fprintf (destinationFile, "%s", temporaryString);
        }
        fclose (destinationFile);
        fclose (sourceFile);
    }
}