#include <iostream>
#include <string>
using namespace std;

class Duration {
private:
    int days;
    char str_buf[32];
public:
    Duration();
    Duration(int d);

    operator int() const;
    operator const char*() const;

    Duration operator-();
    Duration operator+(const Duration& dur) const;
    Duration operator-(const Duration& dur) const;
    Duration operator*(int k) const;
    friend ostream& operator<<(ostream& out, const Duration& d);
    friend istream& operator>>(istream& in, Duration& d);
};

class Date {
private:
    int day, month, year;
    char str_buf[32];
    
public:
    static bool is_leap(int y);
    int to_days() const;
    void from_days(int total);

    Date();
    Date(int d, int m, int y);
    
    operator int() const;
    operator const char*() const;

    const Date& operator++();
    friend Date operator+(const Date& d, const Duration& dur);
    friend Date operator-(const Date& d, const Duration& dur);
    friend Duration operator-(const Date& d1, const Date& d2);
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
};
