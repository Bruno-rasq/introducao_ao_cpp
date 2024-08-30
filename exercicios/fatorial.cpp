#include <iostream>

using namespace std;

int main () 
{
	int resultado = 1;
	int numero = 5;

	for (int i = 1; i <= numero; i++)
	{
		resultado *= i;
	}

	cout << "resultado = " << resultado << endl;
}