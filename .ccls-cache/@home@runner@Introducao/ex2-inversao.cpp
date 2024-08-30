#include <iostream>

using namespace std;

int main()
{
    int num, reverso=0, resto=0;

    cout << "Insira um valor inteiro positivo que será invertido:\n ";
    cin >> num;
    
    int temp = num;
    
    while(temp != 0) {
    
        resto = temp % 10;
        temp /= 10;
        reverso = reverso*10 + resto;
    }

    cout << "-------------------------------------------------- \n";
    cout << "Número: " << num << "\t" << "Reverso: " << reverso << endl;
    cout << "-------------------------------------------------- \n";
    cout << "precione 'ENTER' parar sair. \n";
    cin.get();
    cin.get();
    return 0;
}