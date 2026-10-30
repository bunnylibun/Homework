#include "lib.hpp"
using namespace std;

CelestialBody::CelestialBody(const char* n, double m, double r)
    : name(n), mass(m), radius(r) {}

double CelestialBody::gravitational_force(double m2, double distance) const {
    return G * mass * m2 / (distance * distance);
}

double CelestialBody::surface_gravity() const {
    return G * mass / (radius * radius);
}

const char* CelestialBody::get_name() const {
    return name;
}


Planet::Planet(const char* n, double mass, double r, double at, int moons)
    : CelestialBody(n, mass, r), axial_tilt(at), moons_count(moons) {}

void Planet::describe() const {
    cout << name << " is a planet." << endl;
    cout << "  Axial tilt: " << axial_tilt << " degrees" << endl;
    cout << "  Moons: " << moons_count << endl;
}


Earth::Earth(double mass, double r, double at, int moons)
    : Planet("Earth", mass, r, at, moons) {}

void Earth::describe() const {
    Planet::describe();
    cout << "  Type: terrestrial" << endl;
    cout << "  Has liquid water: yes" << endl;
}

double Earth::orbital_period() const {
    return 1.0;
}


Jupiter::Jupiter(double mass, double r, double at, int moons)
    : Planet("Jupiter", mass, r, at, moons) {}

void Jupiter::describe() const {
    Planet::describe();
    cout << "  Type: gas giant (H/He)" << endl;
    cout << "  Has ring system: yes (faint)" << endl;
}

double Jupiter::orbital_period() const {
    return 11.86;
}


Moon::Moon(double m, double r, double dist, double ph)
    : CelestialBody("Moon", m, r), parent_distance(dist), phase(ph) {}

void Moon::describe() const {
    cout << name << " is a satellite." << endl;
    cout << "  Distance from parent: " << parent_distance / 1000 << " km" << endl;
}

double Moon::orbital_period() const {
    return 27.3 / 365.25;
}

const char* Moon::get_phase() const {
    if (phase < 0.125) return "New Moon";
    if (phase < 0.375) return "Waxing Crescent";
    if (phase < 0.625) return "Full Moon";
    if (phase < 0.875) return "Waning Crescent";
    return "New Moon";
}