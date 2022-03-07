#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Check Apakah file yang terdapat didalam folder sudah dibuat atau masih belum dibuat
void isFileExist(string namaFileSave, bool *check){
	fstream File_A;
	string path = namaFileSave+".txt";
	File_A.open(path.c_str(), ios::in);
	if(File_A){
		cout<<"File sudah ada didalam folder"<<endl;
		*check = false;
	} else {
		*check = true;
	}
}

//modul untuk save file
void saveFile(string namaFileSave){
	fstream File_A;
	bool check;
	isFileExist(namaFileSave, &check);
	if(check==false){
		cout<<"Gunakan nama yang lain";
	} else {
		string path = namaFileSave+".txt";
		if(File_A.is_open()){
			cout<<"File Sudah Dibuka";
		} else {
			File_A.open(path.c_str(), ios::out);	
		}
		cout<<"File berhasil dibuat";
	}
	
	File_A.close();
};

//modul untuk memberikan nama file yang sesuai ketika di save
void inputNamaFile(){
	string inputNamaFile;
	
	cout<<"Masukkan Nama File yang akan disimpan : ";
	getline(cin,inputNamaFile);
	
	saveFile(inputNamaFile);
	
}

int main(){
	inputNamaFile();
}
