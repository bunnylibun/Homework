#include <iostream>
#include "lib.hpp"
using namespace std;

#define UNDERFLOW -1
#define OVERFLOW -2
#define SUCCESS 0

double Sheepcote::width = 10.0;
double Sheepcote::length = 10.0;
const double Sheepcote::sheep_l = 1.1;
const double Sheepcote::sheep_w = 0.5;

double Sheepcote::area() {
    return width * length;
}

int Sheepcote::get_max_size() {
    return area() / (sheep_l * sheep_w);
}

Sheepcote::Sheepcote() : size(0), arr (new Sheep[get_max_size()]) {}

void Sheepcote::set_size(double w, double l) {
    width = w;
    length = l;
}

int Sheepcote::get_size() {
    return size;
}

int Sheepcote::clear() {
    if (size == 0) {
        return UNDERFLOW;
    }
    delete[] arr;
    arr = new Sheep[get_size()];
    size = 0;
    return SUCCESS;
}

Sheepcote::~Sheepcote() {
    clear();
}

int Sheepcote::addSheep(Sheep sh) {
    if (size >= get_max_size() && sh.col != white) {
        return OVERFLOW;
    }
    else if (sh.col == white) {
        if (width > 1000 || length > 1000) {
            return OVERFLOW;
        }
        width += sheep_w;
        length += sheep_l;
        Sheep* newarr = new Sheep[get_max_size()];
        for (int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        arr[size++] = sh;
    }
    else if (sh.col == 1){
        clear();
        arr[0] = sh;
        size = 1;
    }
    else {
        arr[size++] = sh;
    }
    return SUCCESS;
}
