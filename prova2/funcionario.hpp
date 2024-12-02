#include <sstream>
#include <string>

using namespace std;

class Funcionario {
protected:
     string nome;
     float salariobase, salario, bonus;
     int dependentes, vendas;

public:
    Funcionario(const string& n, float sb, int d): nome(n), salariobase(sb), dependentes(d){};

    virtual float salarioBruto() = 0;

    void setBonus(float bonus){ 
		this->bonus = bonus;
	}

    void setVendas(int vendas){
		this->vendas = vendas;
	}

    float salarioLiquido()
    {
		return this->salarioBruto() - this->calcularDescontos();
	}

    float calcularDescontos()
    {
		float sb = this->salarioBruto();
		if(sb > 20000){
			return (35 * this->vendas) / 100;
		}

		if(sb <= 20000 && sb > 10000){
			return (20 * this->vendas) / 100;
		}

		if(sb <= 10000 && sb > 5000){
			return (10 * this->vendas) / 100;
		}

		if(sb < 5000){
			return (5 * this->vendas) / 100;
		}
	}

    void calcularSalario()
    {
		this->salario = this->salarioBruto() + this->calcularDescontos() + this->salarioLiquido();
	}

   string imprimirFolhaPagamento() const {
		ostringstream oss;
		oss << "Funcionaro: " << this->nome;
		oss << " Salario bruto: " << this->salarioBruto();
		oss << " Descontos: " << this->calcularDescontos();
		oss << " Salario liquido: " << this->salarioLiquido();

		return oss.str();
   }

};

class Gerente : public Funcionario {
public:
    Gerente(const string& n, float sb, int d): Funcionario(n, sb, d){}

    float salarioBruto() {
		float salario = this->salariobase + this->bonus + (this->dependentes * 500);
		return salario;
	}

};

class Crediario : public Funcionario {
public:
    Crediario(const string& n, float sb, int d): Funcionario(n, sb, d){}

    float salarioBruto() {
		float salario = this->salariobase + this->bonus + (this->dependentes * 300);
		return salario;
	}

};

class Vendedor : public Funcionario {
public:
    Vendedor(const string& n, float sb, int d): Funcionario(n, sb, d){}

    float comissao(){
		return (this->vendas * 3) / 100;
	}

    float salarioBruto(){
		float salariobruto = this->salariobase + this->bonus + this->comissao() + (this->dependentes * 300);
		return salariobruto;
	}

};