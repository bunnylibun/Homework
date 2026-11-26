#include <iostream>
using namespace std;

class Movable {
protected:
    double x, y;
public:
    Movable() : x(0), y(0) {}
    virtual ~Movable() = default;
    virtual void move() = 0;
    virtual const char* name() const = 0;
    void position() const;
};

class Attacker {
protected:
    int damage;
public:
    Attacker(int d) : damage(d) {}
    virtual ~Attacker() = default;
    virtual void attack(Movable* target) = 0;
};

class Healer {
public:
    virtual ~Healer() = default;
    virtual void heal(Movable* target, int hp) = 0;
};

class Pet : public Movable {
public:
    Pet() : Movable() {}
    void move() override;
    const char* name() const override;
};

class Player : public virtual Movable,
               public virtual Attacker,
               public Healer {
public:
    Player(int d) : Movable(), Attacker(d) {}
    void move() override;
    const char* name() const override;
    void attack(Movable* target) override;
    void heal(Movable* target, int hp) override;
};

class Monster : public virtual Movable,
                public virtual Attacker {
public:
    Monster(int d) : Movable(), Attacker(d) {}
    void move() override;
    const char* name() const override;
    void attack(Movable* target) override;
};

class Boss : public Player, public Monster {
public:
    Boss(int d) : Attacker(d), Movable(), Player(d), Monster(d) {}
    void move() override;
    const char* name() const override;
    void attack(Movable* target) override;
};

class BattleSystem {
public:
    static void turn(Movable* unit, Attacker* atk, Movable* target);
};
