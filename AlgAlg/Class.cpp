#include <iostream>
using namespace std;

class Colour {
protected:
    double arr[4];
public:
    Colour(double res_arr[]) : arr{res_arr[0], res_arr[1], res_arr[2], res_arr[3]} {};
    virtual ~Colour() = default;

    virtual bool is_black() const = 0;
    void get_components(double* res_arr) const {
        res_arr[0] = arr[0];
        res_arr[1] = arr[1];
        res_arr[2] = arr[2];
        res_arr[3] = arr[3];
    }
    virtual Colour* operator+(const Colour& col) const = 0;
};

class RGB: public Colour {
public:
    using Colour::Colour;
    bool is_black() const override {
        return (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 1);
    }

    Colour* operator+ (const Colour& col) const override {
        double other[4];
        col.get_components(other);
        double a = arr[0] + other[0], b = arr[1] + other[1], c = arr[2] + other[2], d = arr[3] + other[3];
        if (a > 1) a = 1;
        if (b > 1) b = 1;
        if (c > 1) c = 1;
        if (d > 1) d = 1;
        double res_arr[4] = {a, b, c, d};
        return new RGB{res_arr};
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
    using Colour::Colour;
    bool is_black() const override {
        return (arr[3] == 1);
    }

    Colour* operator+ (const Colour& col) const override {
        double other[4];
        col.get_components(other);
        double a = arr[0] + other[0], b = arr[1] + other[1], c = arr[2] + other[2], d = arr[3] + other[3];
        if (a > 1) a = 1;
        if (b > 1) b = 1;
        if (c > 1) c = 1;
        if (d > 1) d = 1;
        double res_arr[4] = {a, b, c, d};
        return new CMYK{res_arr};
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
public:
    using CMYK::CMYK;
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
    double ex_1[4] = {0.0, 0.0, 0.5, 1.0};
    cout << "Colour 1: " << ex_1[0] << ", " << ex_1[1] << ", " << ex_1[2] << ", " << ex_1[3] << endl;
    Colour* rgb1 = new RGB(ex_1);
    cout << "Blackness in RGB: " << rgb1->is_black() << endl;
    Colour* cmyk1 = new CMYK(ex_1);
    cout << "Blackness in CMYK: " << cmyk1->is_black() << endl;


    double ex_2[4] = {0.1, 0.75, 0.66, 0.8};
    cout << "Colour 2: " << ex_2[0] << ", " << ex_2[1] << ", " << ex_2[2] << ", " << ex_2[3] << endl;
    Colour* rgb2 = new RGB(ex_2);
    Colour* sum = *rgb2 + *rgb1;
    double res[4];
    sum->get_components(res);
    cout << "Sum of 2 rgbs: " << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << endl;
    RGB* rgb_sum = dynamic_cast<RGB*>(sum);
    cout << "Red: " << rgb_sum->get_red() << endl;
    cout << "Green: " << rgb_sum->get_green() << endl;
    cout << "Blue: " << rgb_sum->get_blue() << endl;
    cout << "Alpha: " << rgb_sum->get_alpha() << endl;

    double ex_3[4] = {0.2, 0.34, 0.7, 0.9};
    cout << "Colour 3: " << ex_3[0] << ", " << ex_3[1] << ", " << ex_3[2] << ", " << ex_3[3] << endl;
    Colour* cmyk2 = new CMYK(ex_3);
    sum = *cmyk1 + *cmyk2;
    sum->get_components(res);
    cout << "Sum of 2 cmyks: " << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << endl;
    CMYK* cmyk_sum = dynamic_cast<CMYK*>(sum);
    cout << "Cyan: " << cmyk_sum->get_cyan() << endl;
    cout << "Magenta: " << cmyk_sum->get_magenta() << endl;
    cout << "Yellow: " << cmyk_sum->get_yellow() << endl;
    cout << "Black: " << cmyk_sum->get_black() << endl;


    double ex_4[4] = {0.0, 0.0, 0.0, 0.0};
    cout << "Colour 4: " << ex_4[0] << ", " << ex_4[1] << ", " << ex_4[2] << ", " << ex_4[3] << endl;
    Colour* rgb3 = new RGB(ex_4);
    RGB* rgb_setter = dynamic_cast<RGB*>(rgb3);
    rgb_setter->set_red(0.5);
    rgb_setter->set_green(0.37);
    rgb_setter->set_blue(0.9);
    rgb_setter->set_alpha(1.0);
    rgb_setter->get_components(res);
    cout << "Result of setting in RGB: " << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << endl;

    Colour* cmyk3 = new CMYK(ex_4);
    CMYK* cmyk_setter = dynamic_cast<CMYK*>(cmyk3);
    cmyk_setter->set_cyan(0);
    cmyk_setter->set_magenta(0.67);
    cmyk_setter->set_yellow(0.3);
    cmyk_setter->set_black(0);
    cmyk_setter->get_components(res);
    cout << "Result of setting in CMYK: " << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << endl;

    Colour* warm_cmyk = new warm_CMYK(ex_3);
    warm_CMYK* cmyk_checker = dynamic_cast<warm_CMYK*>(warm_cmyk);
    cout << "CMYK clearness: " << cmyk_checker->is_clear() << endl;
    return 0;
}