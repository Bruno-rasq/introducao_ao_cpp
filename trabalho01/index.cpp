#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


bool ReadFile(string filename, vector<string>* lista){

	string path = "trabalho01/", extension = ".txt";
	path += filename + extension;

	ifstream file(path);

	if(file.is_open()){

		string line;
		while(getline(file, line)){
			lista->push_back(line);
		}

		file.close();
		return true;
	}
	return false;
}


int main(){

	vector <vector<string>> memoria;

	while(true){

		cout << "----------------------------" << endl;
		cout << "FILE MANIPULATOR HACK" << endl;
		cout << "select an option:" << endl << endl;
		cout << "1. Load a file. Enter filename" << endl;
		cout << "2. Remove words containing a substring" << endl;
		cout << "3. Remove all repeated words(keep the first one only)" << endl;
		cout << "4. Show statistics" << endl;
		cout << "5. Exit" << endl << endl;
		cout << "----------------------------" << endl << endl;

		cout << "option: ";

		int option;
		cin >> option;

		switch (option){
			
			case 1: {

				bool status;
				string filename;
				vector<string> lista;
				
				cout << "Enter a file to open: ";
				cin >> filename;

				status = ReadFile(filename, &lista);
				if(status == false){
					cout << "Error to read file" << endl;
					break;
				}

				memoria.push_back(lista);
				
				break;
			}
			
			case 2: {
				
				string substring;
				cout << "Enter a substring to remove all occurrences: ";
				cin >> substring;

				for(vector<string>& vetorCorrente : memoria){
					int j = vetorCorrente.size() - 1;
					while(j >= 0){
						string palavra = vetorCorrente[j];
						if(palavra.find(substring) != string::npos){
							vetorCorrente.erase(vetorCorrente.begin() + j);
						}
						j--;
					}
				}
				
				break;
			}
			
			case 3: {
				cout << "option choosed 3" << endl;
				break;
			}
			
			case 4: {
				cout << "Statistics:" << endl << endl;
				for(int i=0; i<memoria.size(); i++){
					cout << "File" << (i + 1) << ".txt has " << memoria[i].size() << " word(s)" << endl;
				}
				break;
			}
			
			case 5: 
				return 0;  // exit.

			default: 
				break;
		}
	}
	
	return 0;
}