#include <iostream>
using namespace std;

class CelestialBody {
protected:
    const char* name;
    double mass;
    double radius;
    static constexpr double G = 6.674e-11;

public:
    CelestialBody(const char* n, double m, double r);
    virtual ~CelestialBody() = default;

    double gravitational_force(double m2, double distance) const;
    double surface_gravity() const;

    virtual void describe() const = 0;
    virtual double orbital_period() const { return 0.0; }

    const char* get_name() const;
};

class Planet : public CelestialBody {
protected:
    double axial_tilt;
    int moons_count;

public:
    Planet(const char* n, double mass, double r, double at, int moons);
    void describe() const override;
    virtual double orbital_period() const = 0;
};

class Earth : public Planet {
public:
    Earth(double mass, double r, double at, int moons);
    void describe() const override;
    double orbital_period() const override;
};

class Jupiter : public Planet {
public:
    Jupiter(double mass, double r, double at, int moons);
    void describe() const override;
    double orbital_period() const override;
};

class Moon : public CelestialBody {
private:
    double parent_distance;
    double phase;

public:
    Moon(double m, double r, double dist, double ph);
    void describe() const override;
    double orbital_period() const override;
    const char* get_phase() const;
};