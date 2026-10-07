#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lib.hpp"

#define UNDERFLOW -1
#define OVERFLOW -2
#define SUCCESS 0

using namespace std;

Sheep randomSheep() {
    Sheep sh;
    sh.col = (color)(rand() % 5);
    return sh;
}

int main(void) {
    srand(time(nullptr));
    Sheepcote sc;
    cout << "Start: size = " << sc.get_size() 
         << ", max = " << Sheepcote::get_max_size() 
         << ", area = " << Sheepcote::area() << endl;
    
    for (int i = 0; i < 1000; ++i) {
        Sheep sh = randomSheep();
        int res = sc.addSheep(sh);
        if (i % 100 == 0) {
            cout << "Step " << i << ": sheep = " << sc.get_size()
                 << ", max = " << Sheepcote::get_max_size()
                 << ", area = " << Sheepcote::area()
                 << ", result = " << res << endl;
        }
    }
    cout << "\nFinal: sheeps = " << sc.get_size()
         << ", max = " << Sheepcote::get_max_size()
         << ", area = " << Sheepcote::area() << endl;
    
    return 0;
}