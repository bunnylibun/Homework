#include <iostream>
#include "lib.hpp"
using namespace std;

int main() {
    Earth earth(5.972e24, 6371000.0, 23.44, 1);
    Jupiter jupiter(1.898e27, 69911000.0, 3.13, 95);
    Moon moon(7.342e22, 1737000.0, 384400000.0, 0.5);

    CelestialBody* bodies[3] = { &earth, &jupiter, &moon };

    for (int i = 0; i < 3; i++) {
        cout << bodies[i]->get_name() << ": g = "
             << bodies[i]->surface_gravity() << " m/s²" << endl;
    }

    cout << "\nEarth" << endl;
    earth.describe();
    cout << "  Orbital period: " << earth.orbital_period() << " years" << endl;

    cout << "\nJupiter" << endl;
    jupiter.describe();
    cout << "  Orbital period: " << jupiter.orbital_period() << " years" << endl;

    cout << "Moon phase: " << moon.get_phase() << endl;
    cout << "(this method exists only for Moon)" << endl;

    return 0;
}