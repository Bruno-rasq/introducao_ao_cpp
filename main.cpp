#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<string> lista;
    
    while(true)
    {
        
        //exibindo o menu
        cout << "------------------------" << endl;
        cout << "UfxC String Store v.1" << endl;
        cout << "1. Insert String." << endl;
        cout << "2. Print Index and string."<< endl;
        cout << "3. Search string(literal)."<< endl;
        cout << "4. Search substring." << endl;
        cout << "5. Remove string by index."<< endl;
        cout << "6. Remove by substring (all occorences)." << endl;
        cout << "0. quit." << endl;
        cout << "------------------------" << endl;

        // capturando a opcao escolhida
        cout << "Digite uma opcao: " << endl;
        
        int op;
        cin >> op;
        
        switch(op)
        {
            case 1:
            {
                string palavra;
                cout << "Insira um palavra"<< endl;
                cin >> palavra;
                lista.push_back(palavra);
                
                break;
            }   
            
            case 2:
            {
                for(int i=0; i<lista.size(); i++)
                {
                    cout << "index[" << i << "] = " << lista[i] << endl;
                }
                
                break;
            }

            case 3:
            {
                
                string palavra;
                int ocorrencias = 0;
                
                cout << "Digite a palavra:" << endl;
                cin >> palavra;

                for(int i=0; i<lista.size(); i++){

                    if(lista[i] == palavra){
                        cout << "index[" << i << "] = " << lista[i] << endl;
                        ocorrencias++;
                    }
                }
                cout << "ocorrencias encontradas: "  << ocorrencias << endl;
                
                break;
            }

            case 4: 
            {
                string substring;
                
                cout << "digite a substring: " << endl;
                cin >> substring;

                int i = 0;
                while(i < lista.size()){
                    string curr = lista[i];
                    size_t pos = curr.find(substring);

                    if(pos != string::npos){
                        cout << curr << endl;
                    }
                    
                    i++;
                }

                break;
            }

            case 5: 
            {
                int index;
                cout << "insira o indice do elemento que deseja remover: " << endl;
                cin >> index;

                if(index > lista.size()  || index < 0){
                    cout << "indice invalido!" << endl;
                    break;
                }

                lista.erase(lista.begin() + index);
                cout << "elemento removido!" << endl;
                break;
            }

            case 6:
            {
                string substring;
                cout << "Digite a substring: " << endl;
                cin >> substring;
                
                int i = substring.size() - 1;
                while (i >= 0){
                    string curr = lista[i];
                    size_t pos = curr.find(substring);
                    if(pos != string::npos){
                        lista.erase(lista.begin() + i);
                    }
                    i--;
                }

                break; 
            }
                
            case 0: 
            {
                return 0;
            }
                
            default: 
            {
                break;
            }
        }
        
    }
}