#include "lib.hpp"
using namespace std;

Pet::Pet() : x(0), y(0) {}

void Pet::move() {
    x += 1;
    y += 1;
    cout << "Pet moves to (" << x << ", " << y << ")" << endl;
}

const char* Pet::name() const {
    return "Pet";
}

void Pet::position() const {
    cout << "Pet is at (" << x << ", " << y << ")" << endl;
}


void Player::move() {
    x += 3;
    y += 3;
    cout << "Player moves to (" << x << ", " << y << ")" << endl;
}

const char* Player::name() const {
    return "Player";
}

void Player::position() const {
    cout << "Player is at (" << x << ", " << y << ")" << endl;
}

void Player::attack(Movable* target) {
    cout << "Player attacks " << target->name() << " for " << damage() << " damage\n";
}

int Player::damage() const {
    return 10;
}

void Player::heal(Movable* target, int hp) {
    cout << "Player heals " << target->name() << " for +" << hp << " HP\n";
}


void Monster::move() {
    x += 5;
    y += 5;
    cout << "Monster moves to (" << x << ", " << y << ")\n";
}

const char* Monster::name() const {
    return "Monster";
}

void Monster::position() const {
    cout << "Monster is at (" << x << ", " << y << ")\n";
}

void Monster::attack(Movable* target) {
    cout << "Monster attacks " << target->name() 
         << " for " << damage() << " damage\n";
}

int Monster::damage() const {
    return 30;
}


void Boss::move() {
    x += 10;
    y += 10;
    cout << "Boss moves to (" << x << ", " << y << ")\n";
}

const char* Boss::name() const {
    return "Boss";
}

void Boss::position() const {
    cout << "Boss is at (" << x << ", " << y << ")\n";
}

void Boss::attack(Movable* target) {
    cout << "Boss attacks " << target->name() << " for " << damage() << " damage\n";
}

int Boss::damage() const {
    return 100;
}


void BattleSystem::turn(Movable* unit, Attacker* atk, Movable* target) {
    unit->move();
    if (atk) atk->attack(target);
}