#include <iostream>
#include <string>
using namespace std;

enum colour {
    pink,
    gold,
    silver,
    rose_gold,
    steely_pink,
    metallic,
    unclear
};

class Glitter {
private:
    colour col;
    double amount;
public:
    Glitter(const Glitter& g);
    Glitter(colour c, double a);
    Glitter(Glitter &&g);
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
