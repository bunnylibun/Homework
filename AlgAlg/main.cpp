#include "lib.hpp"
using namespace std;

int main() {
    Movable* m = static_cast<Movable*>(new Pet()); 
    Healer* h = dynamic_cast<Healer*>(new Player());

    Pet* pet = dynamic_cast<Pet*>(m);
    if (Player* p = static_cast<Player*>(h)) {
        cout << "Can downcast Healer to Player" << endl;
    }

    Monster* monst = dynamic_cast<Monster*>(new Player());

    Attacker* a = static_cast<Attacker*>(new Player());
    Movable* mov = dynamic_cast<Movable*>(new Monster());
    
    Attacker* atk = static_cast<Attacker*>(new Boss());
    if (Boss* boss = dynamic_cast<Boss*>(atk)) {
        cout << "Can downcast Attack to Boss" << endl;
    }
    return 0;
}