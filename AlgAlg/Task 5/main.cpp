#include <iostream>
#include "lib.hpp"
using namespace std;

int main() {
    Paint p1(pink, 0.5);
    Paint p2(gold, 0.7);
    
    Bunny bunny;
    bunny.paint(p1);
    cout << "After first paint: " << bunny << endl;
    
    bunny.paint(p2);
    cout << "After second paint: " << bunny << endl;
    
    Bunny bunny2 = bunny + p1;
    cout << "Bunny2: " << bunny2 << endl;
    
    ++bunny;
    cout << "After ++: " << bunny << endl;
    
    if (bunny2 > bunny) {
        cout << "The second bunny has more intensive colour than the first one" << endl;
    }
    
    if (bunny) {
        cout << "Bunny is painted!" << endl;
    }
    
    bunny.wash();
    cout << "After wash: " << bunny << endl;
    
    string bunnyStr = static_cast<string>(bunny2);
    cout << "String: " << bunnyStr << endl;
    
    return 0;
}
