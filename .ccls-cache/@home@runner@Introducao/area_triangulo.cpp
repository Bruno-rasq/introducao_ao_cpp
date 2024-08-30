#include <iostream>
#include <iomanip>

using namespace std;

double area_triangulo(int base, int altura){
	return (base * altura) / 2;
}

int main() {

	double area;
	int base, altura;

	cout << "Insera a base: \n";
	cin >> base;
	
	cout << "Insera a altura: \n";
	cin >> altura;

	area = area_triangulo(base, altura);

	cout << "Area do triangulo = " << setprecision(2) << fixed << area << "cm^2\n";
	
	return 0;
}