/*
    Autor: Bruno Rasq.
    Data: 21/12/2024.
    Objetivo: Simular o sistema de Minions do
    jogo League of Legends da Riot Games.
    
    Disclaimer: Esse código é apenas para estudo
    e foi completamente baseado em como eu (autor)
    entendo sobre como o sistema de minions foi
    desenvolvido.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

#define MINION_TEAM_BLUE "Team BLUE "
#define MINION_TEAM_RED  "Team RED "

// Forward declaration da classe Minion
class Minion;

// type aliasing
using namespace std;
using MINION_FARM = pair<int, int>;
using MINION_TEAM = vector<Minion*>;
using MINION_DATA_ATTRIBUTES = tuple<
    int, float, int, int, int, 
    int, int, int, int, float, string
>;

// Estrutura que contém os atributos das classes
struct MINIONATTRIBUTES {
    
    string type_damage;
    float attack_speed, health_regen;
    int health, move_speed, range, 
        armour, magic_resist,
        gold, EXP, attack_damage;
    
    MINIONATTRIBUTES(const MINION_DATA_ATTRIBUTES& ATTR)
        : health(get<0>(ATTR)),
          health_regen(get<1>(ATTR)),
          move_speed(get<2>(ATTR)),
          range(get<3>(ATTR)),
          armour(get<4>(ATTR)),
          magic_resist(get<5>(ATTR)),
          gold(get<6>(ATTR)),
          EXP(get<7>(ATTR)),
          attack_damage(get<8>(ATTR)),
          attack_speed(get<9>(ATTR)),
          type_damage(get<10>(ATTR)) {}
};

// Base de dados para alimentar os atributos
struct MINIONDATAATTRIBUTES {
    inline static const MINION_DATA_ATTRIBUTES 
    Meelee = {
        //Health   //Health_regen   //Move_speed    //range
        100,       0.5f,            325,            125,
        //armour   //magic_resist   //gold          //EXP
        0,         0,               21              30
        //damage   //atk_speed      //type_damage
        30,        0.625f,          "AD"
    },
        
    Caster = {
        //Health   //Health_regen   //Move_speed    //range
        280,       0.5f,            325,            550, 
        //armour   //magic_resist   //gold          //EXP
        0,         0,               14,             30,
        //damage   //atk_speed      //type_damage
        20,        0.6f,            "AP"
    },
        
    Super = {
        //Health   //Health_regen   //Move_speed    //range
        1000,      1.0f,            500,            125,
        //armour   //magic_resist   //gold          //EXP
        0,         0,               50,             60,
        //damage   //atk_speed      //type_damage
        40,        0.6f,            "AD"
    };
};

// Classe base Minion
class Minion {
protected:
    string description;
    MINIONATTRIBUTES attr;
    
public:
    Minion(
        const string& descrip, 
        const MINIONATTRIBUTES& attr
    ): description(descrip), attr(attr) {}
    
    virtual ~Minion() {}
    
    bool isAlive() const {
        return this->attr.health > 0;
    }
    
    int getHP() const { 
        return this->attr.health;
    }
    
    int getDamage() const {
        return this->attr.attack_damage;
    }
    
    float getAttackSpeed() const {
        return this->attr.attack_speed;
    }
    
    int getRange() const {
        return this->attr.range;
    }
    
    string getDescription() const {
        return this->description;
    }
    
    void Attack(Minion& enemy) const {
        enemy.takeDamage(
            this->attr.attack_damage
        );
    } 
    
    void takeDamage(int damage) {
        
        this->attr.type_damage == "AD" ?
        damage -= this->attr.armour :
        damage -= this->attr.magic_resist;
        
        if (damage < 0) damage = 0; // Dano não pode ser negativo
        
        this->attr.health -= damage;
        if (this->attr.health < 0) this->attr.health = 0;
    }
    
    MINION_FARM getGoldExp() const {
        return {this->attr.gold, this->attr.EXP};
    }
};

// Classes derivadas dos tipos de Minions
class MeeleeMinion : public Minion {
public:
    MeeleeMinion(const string& team): Minion(
        team + "Meelee Minion",
        MINIONATTRIBUTES(MINIONDATAATTRIBUTES::Meelee)
    ) {}
};

class SuperMinion : public Minion {
public:
    SuperMinion(const string& team): Minion(
        team + "Super Minion",
        MINIONATTRIBUTES(MINIONDATAATTRIBUTES::Super)
    ) {}
};

class CasterMinion : public Minion {
public:
    CasterMinion(const string& team): Minion(
        team + "Caster Minion",
        MINIONATTRIBUTES(MINIONDATAATTRIBUTES::Caster)
    ) {}
};

// Funções para gerenciar os times
void createWave(MINION_TEAM& team, const string& t) {
    team.push_back(new MeeleeMinion(t));
    team.push_back(new MeeleeMinion(t));
    team.push_back(new MeeleeMinion(t));
    team.push_back(new CasterMinion(t));
    team.push_back(new CasterMinion(t));
    team.push_back(new SuperMinion(t));
}

void clearTeam(MINION_TEAM& team) {
    for (auto minion : team) {
        delete minion;
    }
    team.clear(); // Limpa o vetor após liberar a memória
}

int main() {
    
    MINION_TEAM Blue, Red;
    
    createWave(Blue, MINION_TEAM_BLUE);
    createWave(Red,  MINION_TEAM_RED);
    
    cout << "Team BLUE:" << endl;
    for (auto& minion : Blue) {
        cout << minion->getDescription() << endl;
    }
    cout << "______________________" << endl;
    
    cout << "Team RED:" << endl;
    for (auto& minion : Red) {
        cout << minion->getDescription() << endl;
    }
    
    clearTeam(Blue);
    clearTeam(Red);
    
    return 0;
}