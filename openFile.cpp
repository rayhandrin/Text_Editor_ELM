#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
using namespace std;
void OpenFile();
int main(){
    OpenFile();
}

void OpenFile(){
    string fileName;
    fstream myFile;
    cout<<"End writing : ||end"<<endl;
    cout<<"File name : ";
    cin>>fileName;
    myFile.open(fileName);
    string line, endWriting;
    endWriting = "||end";
    
    //read file
    if(!myFile.is_open()){
        cout<< "file cannot be found";
        exit(1);
    }
    while(getline(myFile, line)){
        cout<<line<<endl;
    }
    myFile.close();
    
    //write text into file
    myFile.open(fileName, ios::out|ios::app);
    while (!myFile.eof()){
        cin>>line;
        if (line.compare(endWriting) == 0){
            exit(0);
        }
        myFile<<line<<endl;
    }
myFile.close();  
}


