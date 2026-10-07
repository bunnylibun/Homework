#include <iostream>
using namespace std;

enum color {
    white = 0,
    black = 1,
    pink = 2,
    blue = 3,
    yellow = 4
};

struct Sheep {
    color col;
};

class Sheepcote {
private:
    int size;
    int capacity;
    static double width;
    static double length;
    static const double sheep_l;
    static const double sheep_w;
public:
    Sheep* arr;
    Sheepcote();
    ~Sheepcote();
    static double area();
    static void setsize(double w, double l);
    static int get_max_size();
    int get_size();
    int addSheep(Sheep sh);
    int clear();
};
