#include <iostream>
#include "lib.hpp"
using namespace std;

Glitter::Glitter(colour c, double a) : col(c), amount(a) {}

Glitter::Glitter(const Glitter& g): col(g.col), amount(g.amount) {}

Glitter::Glitter(Glitter &&g) {
    amount = g.amount;
    col = g.col;
    g.amount = 0;
    g.col = unclear;
}

Glitter::~Glitter() {}

Glitter Glitter::operator+ (const Glitter& g) const {
    if (col == g.col) {
        return Glitter{col, amount + g.amount};
    }
    else if ((col == pink && g.col == gold) || (col == gold && g.col == pink)) {
        return Glitter{rose_gold, amount + g.amount};
    }
    else if ((col == silver && g.col == pink) || (col == pink && g.col == silver)) {
        return Glitter{steely_pink, amount + g.amount};
    }
    else if ((col == silver && g.col == gold) || (col == gold && g.col == silver)) {
        return Glitter{metallic, amount + g.amount};
    }
    else return Glitter{unclear, amount + g.amount};
}

bool Glitter::operator== (const Glitter& g) const {
    return (amount == g.amount && col == g.col);
}

bool Glitter::operator> (const Glitter& g) const {
    return (amount > g.amount);
}

const Glitter& Glitter::operator++ () {
    amount++;
    return *this;
}

Glitter::operator string() const {
    if (col == gold) return "Gold";
    else if (col == pink) return "Pink";
    else if (col == rose_gold) return "Rose gold";
    else if (col == silver) return "Silver";
    else if (col == steely_pink) return "Steely pink";
    else if (col == metallic) return "Metallic";
    else return "Unclear";
}

Glitter::operator bool() const {
    return amount > 0;
}

ostream& operator<<(ostream& out, const Glitter& g) {
    out << "Glitter: color - " << g.col << ", amount - " << g.amount;
    return out;
}

istream& operator>>(istream& in, Glitter& g) {
    int c;
    double a;
    in >> c >> a;
    g.col = static_cast<colour>(c);
    g.amount = a;
    return in;
}
