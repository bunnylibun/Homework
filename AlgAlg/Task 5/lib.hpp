#include <iostream>
#include <string>
using namespace std;

enum colour {
    pink,
    gold,
    rose_gold,
    neutral
};

class Paint {
private:
    colour col;
    double intensity;
public:
    Paint(const Paint& p);
    Paint(colour c, double i);
    Paint(Paint &&p);
    ~Paint();
    
    Paint operator+(const Paint& p) const;
    bool operator==(const Paint& p) const;
    bool operator>(const Paint& p) const;
    const Paint& operator++();
    
    friend ostream& operator<<(ostream& out, const Paint& p);
    friend istream& operator>>(istream& in, Paint& p);
    
    explicit operator string() const;
    explicit operator bool() const;

    friend class Bunny;
};

class Bunny {
private:
    colour fur;
    double intensity;
public:
    Bunny(const Bunny& b);
    Bunny();
    Bunny(Bunny &&b);
    ~Bunny();
    
    void paint(const Paint& p);
    void wash();               
    
    Bunny operator+(const Paint& p) const;
    bool operator==(const Bunny& b) const;
    bool operator>(const Bunny& b) const;
    const Bunny& operator++();
    
    friend ostream& operator<<(ostream& out, const Bunny& b);
    friend istream& operator>>(istream& in, Bunny& b);
    
    explicit operator string() const;
    explicit operator bool() const;
};
