#include <iostream>
#include "lib.hpp"
using namespace std;

int main(void) {
    Glitter g1(pink, 5.0);
    Glitter g2(gold, 3.0);
    
    Glitter g3 = g1 + g2;
    cout << g3 << endl;
    
    if (g1 > g2) {
        cout << "g1 is in more amount than g2" << endl;
    }
    
    ++g1;
    
    if (g1) {
        cout << "g1 exists" << endl;
    }
    return 0;
}