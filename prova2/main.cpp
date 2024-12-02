#include "funcionario.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<Funcionario*> qpessoal;

	qpessoal.push_back(new Gerente("tobias", 10000, 2));
	qpessoal.push_back(new Crediario("Anelise", 6700, 3));
	qpessoal.push_back(new Vendedor("Andre", 2500, 2));
	qpessoal.push_back(new Vendedor("Roberto", 2500, 2));
	qpessoal.push_back(new Vendedor("Pedro", 2500, 2));

	qpessoal.at(4)->setVendas(134500);
	qpessoal.at(3)->setVendas(13450);
	qpessoal.at(2)->setVendas(25500);

	qpessoal.at(4)->setBonus(350);
	qpessoal.at(2)->setBonus(450);
	qpessoal.at(1)->setBonus(450.0 * 0.0025);
	qpessoal.at(0)->setBonus(350 * 0.01);

	for(size_t i = 0; i < qpessoal.size(); i++)
		qpessoal.at(i)->calcularSalario();

	for(size_t i = 0; i < qpessoal.size(); i++)
		qpessoal.at(i)->imprimirFolhaPagamento();

	for(size_t i = 0; i < qpessoal.size(); i++)
		delete qpessoal.at(i);
	
	return 0;
}