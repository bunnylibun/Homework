#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Legendre_error {
public:
    int error_code;
    string message;

    Legendre_error(int code, const string& msg) : error_code(code), message(msg) {}
    virtual ~Legendre_error() = default;
};

class NegativeOrderError : public Legendre_error {
public:
    int bad_n;
    NegativeOrderError(int n) : 
        Legendre_error(1, "Order of the polynomial can't be negative"), bad_n(n) {}
};

class MaxOrderError : public Legendre_error {
public:
    int bad_n;
    MaxOrderError(int n) :
        Legendre_error(2, "You have a limit for order: 1000"), bad_n(n) {}
};

class FileOpenError : public Legendre_error {
public:
    string filename;
    FileOpenError(const string& name) :
        Legendre_error(3, "Failed to open file: " + name), filename(name) {}
};

class InvalidInputError : public Legendre_error {
public:
    InvalidInputError() : Legendre_error(4, "You have to input two digits: n and x") {}
};

const int MAX_N = 1000;
const double EPS = 1e-16;

class Legendre_calc {
private:
    int last_cached_i;
    double last_cached_x;
    double cache[MAX_N + 1];
    bool isempty;

public:
    int getsize() const { return last_cached_i + 1; }
    
    Legendre_calc() : last_cached_i(-1), last_cached_x(0.0), isempty(true) {}

    double calculate(int n, double x) {
        if (n < 0) throw NegativeOrderError(n);
        if (n > MAX_N) throw MaxOrderError(n);

        if (isempty || std::abs(x - last_cached_x) > EPS) {
            last_cached_x = x;
            cache[0] = 1.0;
            cache[1] = x;
            last_cached_i = 1;
            isempty = false;
        }

        if (n <= last_cached_i) return cache[n];

        for (int i = last_cached_i + 1; i <= n; i++) {
            cache[i] = ((2.0 * i - 1.0) / i) * x * cache[i - 1] - ((i - 1.0) / i) * cache[i - 2];
        }
        
        last_cached_i = n;
        return cache[n];
    }
};

int main() {
    ifstream infile("input.txt");
    if (!infile.is_open()) throw FileOpenError("input.txt");
    
    ofstream outfile("output.txt");
    if (!outfile.is_open()) throw FileOpenError("output.txt");

    Legendre_calc calc;
    int n;
    double x;
    
    try {
        while (infile >> n >> x) {
            try {
                double res = calc.calculate(n, x);
                outfile << "P_" << n << "(" << x << ") = " << res << " (cache size: " << calc.getsize() << ")\n";
            }
            catch (const NegativeOrderError& e) {
                outfile << "ERROR: " << e.message << " (got n = " << e.bad_n << ")\n";
            }
            catch (const MaxOrderError& e) {
                outfile << "ERROR: " << e.message << " (got n = " << e.bad_n << ")\n";
            }
            catch (const Legendre_error& e) {
                outfile << "ERROR: " << e.message << "\n";
            }
        }
        
        if (infile.fail() && !infile.eof()) {
            throw InvalidInputError();
        }
    }
    catch (const InvalidInputError& e) {
        cerr << "Critical error: " << e.message << "\n";
        return 1;
    }
    catch (const FileOpenError& e) {
        cerr << "Critical error: " << e.message << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Unknown critical error happened.\n";
        return 1;
    }
    
    infile.close();
    outfile.close();
    return 0;
}
