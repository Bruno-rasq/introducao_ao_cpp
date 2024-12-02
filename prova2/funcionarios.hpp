#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <string>
#include <sstream>

using namespace std;

class Funcionario {
protected:
    string nome;
    float salariobase, salario, bonus;
    int dependentes, vendas;

public:
    Funcionario(const string& n, float sb, int d) 
        : nome(n), salariobase(sb), salario(0), bonus(0), dependentes(d), vendas(0) {}

    virtual ~Funcionario() = default;

    virtual float salarioBruto() const = 0;

    void setBonus(float b) {
        bonus = b;
    }

    void setVendas(int v) {
        vendas = v;
    }

    float salarioLiquido() {
        return salario - calcularDescontos();
    }

    float calcularDescontos() const {
        float sb = salarioBruto();
        if (sb > 20000) {
            return (0.35 * vendas);
        } else if (sb > 10000) {
            return (0.20 * vendas);
        } else if (sb > 5000) {
            return (0.10 * vendas);
        } else {
            return (0.05 * vendas);
        }
    }

    void calcularSalario() {
        salario = salarioBruto() - calcularDescontos();
    }

    string imprimirFolhaPagamento() const {
        ostringstream oss;
        oss << "Funcionário: " << nome
            << " Salário bruto: " << salarioBruto()
            << " Descontos: " << calcularDescontos()
            << " Salário líquido: " << salario;
        return oss.str();
    }
};

class Gerente : public Funcionario {
public:
    Gerente(const string& n, float sb, int d) : Funcionario(n, sb, d) {}

    float salarioBruto() const override {
        return salariobase + bonus + (dependentes * 500);
    }
};

class Crediario : public Funcionario {
public:
    Crediario(const string& n, float sb, int d) : Funcionario(n, sb, d) {}

    float salarioBruto() const override {
        return salariobase + bonus + (dependentes * 300);
    }
};

class Vendedor : public Funcionario {
public:
    Vendedor(const string& n, float sb, int d) : Funcionario(n, sb, d) {}

    float comissao() const {
        return vendas * 0.03f;
    }

    float salarioBruto() const override {
        return salariobase + bonus + comissao() + (dependentes * 300);
    }
};

#endif