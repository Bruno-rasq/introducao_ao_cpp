#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

//declaração e estruturação de classes

class Pessoa {
private:
    // Propriedades privadas
    string name, adress, job;

public:
    // Métodos públicos
    void setName(const string& name);
    string getName() const;

    void setAdress(const string& adress);
    string getAdress() const;

    void setJob(const string& job);
    string getJob() const;
};

#endif