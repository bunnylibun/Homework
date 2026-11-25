#include <iostream>
using namespace std;

class Movable {
public:
    virtual ~Movable() = default;
    virtual void move() = 0;
    virtual const char* name() const = 0;
    virtual void position() const = 0;
};

class Attacker {
protected:
    double x, y;
public:
    Attacker() : x(0), y(0) {}
    virtual ~Attacker() = default;
    virtual void attack(Movable* target) = 0;
    virtual int damage() const = 0;
};

class Healer {
public:
    virtual ~Healer() = default;
    virtual void heal(Movable* target, int hp) = 0;
};

class Pet : public Movable {
protected:
    double x, y;
public:
    Pet();
    void move() override;
    const char* name() const override;
    void position() const override;
};

class Player : public virtual Movable,
               public virtual Attacker,
               public Healer {
public:
    Player() : Attacker() {}
    void move() override;
    const char* name() const override;
    void position() const override;
    void attack(Movable* target) override;
    int damage() const override;
    void heal(Movable* target, int hp) override;
};

class Monster : public virtual Movable,
                public virtual Attacker {
public:
    Monster() : Attacker() {}
    void move() override;
    const char* name() const override;
    void position() const override;
    void attack(Movable* target) override;
    int damage() const override;
};

class Boss : public Player, public Monster {
public:
    Boss() : Attacker(), Player(), Monster() {}
    void move() override;
    const char* name() const override;
    void position() const override;
    void attack(Movable* target) override;
    int damage() const override;
};

class BattleSystem {
public:
    static void turn(Movable* unit, Attacker* atk, Movable* target);
};