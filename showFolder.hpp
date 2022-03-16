/* Fatur */
#include <dirent.h>
#include <conio.h>
#include <sys\stat.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main()
{
    struct dirent *d;
    struct stat dst;

    DIR *dr;

    cout << "You are Here :" << endl;
    string path = "F:\\School\\Polban\\Teknik Komputer dan Informatika\\Matkul\\Semester 2\\Workshop\\Proyek 2\\Proyek 2 ELM";
    cout << path << endl;

    cout << "===================================================================================================================" << endl;

    dr = opendir(path.c_str());
    if (dr != NULL)
    {
        for (d = readdir(dr); d != NULL; d = readdir(dr))
        {
            string type = d->d_name;
            type = path + type;

            if (stat(type.c_str(), &dst) == 0)
            {
                if (dst.st_mode & S_IFDIR)
                {
                    type = "is a Folder";
                }
                else if (dst.st_mode & S_IFREG)
                {
                    type = "is a File";
                }
            }
            cout << "- " << d->d_name << endl;
        }
        closedir(dr);
        cout << "===================================================================================================================" << endl;
    }
    else
    {
        cout << "error";
    }
    getch();
}