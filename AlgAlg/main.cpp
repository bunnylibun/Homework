#include <iostream>
using namespace std;

class Colour {
protected:
    double arr[4];
public:
    Colour(double res_arr[]) : arr({res_arr[0], res_arr[1], res_arr[2], res_arr[3]}) {};
    virtual bool is_black() const {return false;}
    void get_components(double* res_arr) const {
        res_arr[0] = arr[0];
        res_arr[1] = arr[1];
        res_arr[2] = arr[2];
        res_arr[3] = arr[3];
    }
    Colour operator+(const Colour& col) const {
        double a = arr[0] + col.arr[0], b = arr[1] + col.arr[1], c = arr[2] + col.arr[2], d = arr[3] + col.arr[3];
        if (a > 1) a = 1;
        if (b > 1) b = 1;
        if (c > 1) c = 1;
        if (d > 1) d = 1;
        double res_arr[4];
        res_arr[0] = a;
        res_arr[1] = b;
        res_arr[2] = c;
        res_arr[3] = d;
        return Colour{res_arr};
    }
};

class RGB: public Colour {
public:
    bool is_black() const override {
        return (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 1);
    }

    double get_red() const {return arr[0];}
    double get_green() const {return arr[1];}
    double get_blue() const {return arr[2];}
    double get_alpha() const {return arr[3];}

    void set_red(double val) {arr[0] = val;}
    void set_green(double val) {arr[1] = val;}
    void set_blue(double val) {arr[2] = val;}
    void set_alpha(double val) {arr[3] = val;}
};

class CMYK: public Colour {
public:
    bool is_black() const override {
        return (arr[3] == 1);
    }

    double get_cyan() const {return arr[0];}
    double get_magenta() const {return arr[1];}
    double get_yellow() const {return arr[2];}
    double get_black() const {return arr[3];}

    void set_cyan(double val) {arr[0] = val;}
    void set_magenta(double val) {arr[1] = val;}
    void set_yellow(double val) {arr[2] = val;}
    void set_black(double val) {arr[3] = val;}

    virtual bool is_clear() const {return false;}
};

class warm_CMYK: public CMYK {
    bool is_clear() const override {
        return (((arr[0] != 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0) || 
                 (arr[0] == 0 && arr[1] != 0 && arr[2] == 0 && arr[3] == 0) ||
                 (arr[0] == 0 && arr[1] == 0 && arr[2] != 0 && arr[3] == 0)) ||
                ((arr[0] == arr[1] && arr[0] != 0 && arr[2] == 0 && arr[3] == 0) ||
                 (arr[1] == arr[2] && arr[1] != 0 && arr[0] == 0 && arr[3] == 0) ||
                 (arr[0] == arr[2] && arr[0] != 0 && arr[3] == 0 && arr[1] == 0)));
    }
};

int main() {
    double arr[4] = {0.0, 0.0, 0.0, 1.0};
    Colour col = Colour(arr);
    cout << col.is_black() << endl;
    return 0;
}