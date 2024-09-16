#include <iostream>
#include <fstream>

using namespace std;

bool writeFile(string text,  string path){
	ofstream file (path);

	if(file.is_open()){
		file << text << endl;

		file.close();
		return true;
	}

	cout << "Ocorreu um erro" << endl;
	return false;
}

bool readFile(string path, string *text) {

	ifstream file (path);

	if(file.is_open()){

		file.close();
		return true;
	}

	cout << "Ocorreu um erro" << endl;
	return false;
}

int main() {

	bool status;
    status = writeFile("Ola Mundo, hoje fez um calorao do caramba !\n", "f1.txt");
    if(status == false)
        cout << "Error to write file" << endl;

    status = writeFile("Acho que a prova de calculo vai dar ruim !\n", "f2.txt");
    if(status == false)
        cout << "Error to write file" << endl;

	
	return 0;
}