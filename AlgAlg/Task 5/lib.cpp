#include <iostream>
#include "lib.hpp"
using namespace std;

Bunny::Bunny() : fur(neutral), intensity(0) {}

Bunny::Bunny(const Bunny& b) : fur(b.fur), intensity(b.intensity) {}

Bunny::~Bunny() {}

Bunny::Bunny(Bunny &&b) {
    intensity = b.intensity;
    fur = b.fur;
    b.intensity = 0;
    b.fur = neutral;
}

void Bunny::paint(const Paint& p) {
    if (intensity == 0) {
        fur = p.col;
        intensity = p.intensity;
    } 
    else {
        if (fur == p.col) {
            intensity = (intensity + p.intensity)/2;
        } 
        else if ((fur == pink && p.col == gold) || (fur == gold && p.col == pink)) {
            fur = rose_gold;
            intensity = (intensity + p.intensity)/2;
        } 
        else {
            fur = neutral;
            intensity = 0;
        }
    }
}

void Bunny::wash() {
    fur = neutral;
    intensity = 0;
}

Bunny::operator bool() const {
    return intensity > 0;
}

Bunny::operator string() const {
    if (fur == gold) return "Gold";
    else if (fur == pink) return "Pink";
    else if (fur == rose_gold) return "Rose gold";
    else return "Neutral";
}

bool Bunny::operator==(const Bunny& b) const {
    return (b.fur == fur && b.intensity == intensity);
}

bool Bunny::operator> (const Bunny& b) const {
    return (intensity > b.intensity);
}

ostream& operator<<(ostream& out, const Bunny& b) {
    out << "Bunny: " << "fur color - " << static_cast<string>(b)
        << ", intensity - " << b.intensity;
    return out;
}

istream& operator>>(istream& in, Bunny& b) {
    int c;
    double i;

    if (c < 0 || c > 3) {
        cerr << "Invalid colour value for bunny!" << endl;
        return in;
    }
    
    if (i < 0.0 || i > 1.0) {
        cerr << "Intensity must be between 0.0 and 1.0!" << endl;
        return in;
    }
    
    b.fur = static_cast<colour>(c);
    b.intensity = i;
    return in;
}

const Bunny& Bunny::operator++() {
    intensity += 0.1;
    if (intensity > 1.0) intensity = 1.0;
    return *this;
}

Bunny Bunny::operator+ (const Paint& p) const {
    Bunny result = *this;
    result.paint(p);
    return result;
}

Paint::Paint(colour c, double i) : col(c), intensity(i) {}

Paint::Paint(const Paint& g) : col(g.col), intensity(g.intensity) {}

Paint::Paint(Paint &&g) {
    intensity = g.intensity;
    col = g.col;
    g.intensity = 0;
    g.col = neutral;
}

Paint::~Paint() {}

Paint Paint::operator+ (const Paint& g) const {
    if (col == g.col) {
        return Paint{col, (intensity + g.intensity)/2};
    }
    else if ((col == pink && g.col == gold) || (col == gold && g.col == pink)) {
        return Paint{rose_gold, (intensity + g.intensity)/2};
    }
    else {
        return Paint{neutral, 0};
    }
}

bool Paint::operator== (const Paint& g) const {
    return (intensity == g.intensity && col == g.col);
}

bool Paint::operator> (const Paint& g) const {
    return (intensity > g.intensity);
}

const Paint& Paint::operator++() {
    intensity += 0.1;
    if (intensity > 1.0) intensity = 1.0;
    return *this;
}

Paint::operator string() const {
    if (col == gold) return "Gold";
    else if (col == pink) return "Pink";
    else if (col == rose_gold) return "Rose gold";
    else return "Neutral";
}

Paint::operator bool() const {
    return intensity > 0;
}

ostream& operator<<(ostream& out, const Paint& g) {
    out << "Paint: color - " << static_cast<string>(g) 
        << ", intensity - " << g.intensity;
    return out;
}

istream& operator>>(istream& in, Paint& g) {
    int c;
    double i;
    in >> c >> i;

    if (c < 0 || c > 3) {
        cerr << "Invalid colour value!" << endl;
        return in;
    }
    
    if (i < 0.0 || i > 1.0) {
        cerr << "Intensity must be between 0.0 and 1.0!" << endl;
        return in;
    }
    
    g.col = static_cast<colour>(c);
    g.intensity = i;
    return in;
}
