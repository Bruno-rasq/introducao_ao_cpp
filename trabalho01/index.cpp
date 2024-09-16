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

void Concatenation(vector<vector<string>>* memoria){

	ofstream file ("trabalho01/concatenation.txt");

	if(file.is_open()){
		int len = memoria->size();
		for(int i = 0; i < len; i++){
			vector<string> vetorCorrente = memoria->at(i);
			for(string palavra: vetorCorrente){
				file << palavra << endl;
			}
		}

		file.close();
	}
}

int main(){

	vector <string> files;
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

				files.push_back(filename);
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
				
				string palavra;
				cout << "Enter the word to remove duplicates: ";
				cin >> palavra;

				for(vector<string>& vetorCorrente : memoria){
					int i = vetorCorrente.size() - 1;
					bool primeira = true;
					while(i >= 0){
						string palavraVetor = vetorCorrente[i];
						
						if(palavraVetor == palavra && !primeira)
							vetorCorrente.erase(vetorCorrente.begin() + i);

						if(palavraVetor == palavra && primeira)
							primeira = false;
						
						i--;
					}
				}

				break;
			}
			
			case 4: {
				cout << "Statistics:" << endl << endl;
				for(int i=0; i<memoria.size(); i++){
					cout << files[i] << ".txt has " << memoria[i].size() << " word(s)" << endl;
				}
				break;
			}
			
			case 5: {
				Concatenation(&memoria);
				return 0;
			}

			default: 
				break;
		}
	}
	
	return 0;
}