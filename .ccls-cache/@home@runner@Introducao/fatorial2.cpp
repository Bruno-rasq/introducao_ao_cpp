#include <iostream>

using namespace std;

int fatorial(int n) {
	int resultado = 1;
	for (int i = 1; i <= n; i++){
		resultado *= i;
	}
	return resultado;
}

int main () {

	int i = 0;
	cout << "digite um valor: \n";
	cin >> i;

	cout << "Fatorial de " << i << " = " << fatorial(i);

	cout << "Precione Enter para terminar.";
	cin.get(); //captura o \n do cin anterior.
	cin.get(); //espera uma nova entrada do usuário.
	
	return 0;
}