#include "lib.hpp"
using namespace std;

int main() {
    Movable* m = static_cast<Movable*>(new Pet()); 
    Healer* h = dynamic_cast<Healer*>(new Player(10));

    Attacker* a = static_cast<Attacker*>(new Player(10));
    Movable* mov = dynamic_cast<Movable*>(new Monster(30));

    Monster* monst = dynamic_cast<Monster*>(new Player(10));

    Pet* pet = dynamic_cast<Pet*>(m);
    Player* p = dynamic_cast<Player*>(h);
    if (p!=nullptr) {
        cout << "Can downcast Healer to Player" << endl;
    }
    
    Monster* monster = new Monster(30);
    Player* player = new Player(10);
    player->attack(monster);

    Attacker* atk = static_cast<Attacker*>(new Boss(100));
    if (Boss* boss = dynamic_cast<Boss*>(atk)) {
        cout << "Can downcast Attack to Boss" << endl;
    }

    delete m;
    delete h;
    delete a;
    delete mov;
    delete monst;
    dekete monster;
    delete player;
    delete atk;
    return 0;
}
