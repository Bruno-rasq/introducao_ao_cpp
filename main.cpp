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
                //inserir uma nova palavra na lista.
                string palavra;
                cout << "Insira um palavra"<< endl;
                cin >> palavra;
                lista.push_back(palavra);
                
                break;
            }   
            
            case 2:
            {
                //exibindo as palavras da lista.
                for(int i=0; i<lista.size(); i++)
                {
                    cout << i << " -> " << lista[i] << endl;
                }
                
                break;
            }

            case 3:
            {
                /*
                    encontrando e imprimindo todas os indices e palavras da lista
                    com base em uma palavra recebida.
                */
                string palavra;
                
                cout << "Digite a palavra:" << endl;
                cin >> palavra;

                cout << "ocorrencias encontradas: " << endl;
                for(int i=0; i<lista.size(); i++){

                    // se a palavra corrente for igual a palavra desejada, exiba.
                    if(lista[i] == palavra){
                        cout << "Index " << i << " -> " << lista[i] << endl;
                    }
                }
                
                break;
            }

            case 4: 
            {
                /*
                    buscando todas as ocorrencias de palavras da lista
                    que contenham uma substring recebida.
                */
                string substring;
                
                cout << "insira a substring: " << endl;
                cin >> substring;
                
                int sublength = substring.length(); // tamanho da substring

                cout << "Ocorrencias da substrig (" << substring << "):" << endl;
                for(int i= 0; i<lista.size(); i++){
                    
                    string palavra = lista[i]; // palavra corrente
                    bool found = false;
                    
                    for(int j = 0; j <= palavra.length() - sublength; j++){
                        int count = 0;
                        while(count < sublength && palavra[j + count] == substring[count]){
                            count++;
                        }
                        if(count == sublength){
                            found = true;
                            break;
                        }
                    }
                    if(found == true){
                        cout << palavra << endl;
                    }
                }

                break;
            }

            case 5: 
            {
                //remove um elemento da lista pelo indice.
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
                
                int tamanho_da_subtring = substring.size();

                //iterando sobre cada palavra da lista.
                for(int i = 0; i<lista.size(); i++){
                    
                    string palavra = lista[i]; // palavra da vez.
                    bool encontrou = false; // indica se a palavra contem a substring.

                    //itero sobre cada caracter da palavra menos o tamanho da substring.
                    for(int j = 0; j<=palavra.length() - tamanho_da_subtring; j++){

                        /*
                            para cada caracter da palavra verifique se o tamanho 
                            é menor que o tamanho da substring & se a proxima caracter
                            da palavra é igual
                        */
                        int contador = 0; 
                        while(contador < tamanho_da_subtring && palavra[j + contador] == substring[contador]){
                            contador++;
                        }
                        if(contador == tamanho_da_subtring){
                            encontrou = true;
                            break;
                        }
                    }

                    //verifico se a substring foi encontrada nesta palavra, caso sim deleto.
                    if(encontrou == true){
                        lista.erase(lista.begin() + i);
                    }
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