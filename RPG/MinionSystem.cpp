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
    inline static const MINION_DATA_ATTRIBUTES Meelee = {
            100,   // health
            0.5f,  // health_regen
            325,   // move_speed
            125,   // range
            0,     // armour
            0,     // magic_resist
            21,    // gold
            30,    // EXP
            30,    // attack_damage
            0.625f,// attack_speed
            "AD"   // type_damage
        };
        
    inline static const MINION_DATA_ATTRIBUTES Caster = {
            280,   // health
            0.5f,  // health_regen
            325,   // move_speed
            550,   // range
            0,     // armour
            0,     // magic_resist
            14,    // gold
            30,    // EXP
            20,    // attack_damage
            0.625f,// attack_speed
            "AP"   // type_damage
        };
        
    inline static const MINION_DATA_ATTRIBUTES Super = {
            1000,  // health
            1.0f,  // health_regen
            500,   // move_speed
            125,   // range
            0,     // armour
            0,     // magic_resist
            50,    // gold
            60,    // EXP
            40,    // attack_damage
            0.625f,// attack_speed
            "AD"   // type_damage
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
void createTeam(MINION_TEAM& team, const string& t) {
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
    
    createTeam(Blue, MINION_TEAM_BLUE);
    createTeam(Red, MINION_TEAM_RED);
    
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