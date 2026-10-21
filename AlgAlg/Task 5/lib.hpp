#include <iostream>
#include <string>
using namespace std;

enum colour {
    pink = 0,
    gold = 1,
    silver = 2,
    rose_gold = 3,
    steely_pink = 4,
    metallic = 5,
    unclear = 6
};

class Glitter {
private:
    colour col;
    double amount;
public:
    Glitter();
    Glitter(colour c, double a);
    ~Glitter();
    
    Glitter operator+(const Glitter& g) const;
    bool operator==(const Glitter& g) const;
    bool operator>(const Glitter& g) const;
    const Glitter& operator++();
    
    friend ostream& operator<<(ostream& out, const Glitter& g);
    friend istream& operator>>(istream& in, Glitter& g);
    
    explicit operator string() const;
    explicit operator bool() const;
};