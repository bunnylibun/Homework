#include <iostream>
#include "lib.hpp"
#include <cstdio>
using namespace std;

Duration::Duration() : days(0) {}
Duration::Duration(int d) : days(d) {}

Duration::operator int() const {
    return days;
}
Duration::operator const char*() const {
    sprintf((char*)str_buf, "%d days", days);
    return str_buf;
}

Duration Duration::operator-() {
    return Duration(-days);
}
Duration Duration::operator+(const Duration& dur) const {
    return Duration(days + dur.days);
}
Duration Duration::operator-(const Duration& dur) const {
    return Duration(days - dur.days);
}
Duration Duration::operator*(int k) const {
    return Duration(days * k);
}
ostream& operator<<(ostream& out, const Duration& d) {
    out << d.days << " days";
    return out;
}
istream& operator>>(istream& in, Duration& d) {
    in >> d.days;
    return in;
}



bool Date::is_leap(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
int Date::to_days() const {
    int days = 0;
    for (int y = 2000; y < year; y++)
        days += is_leap(y) ? 366 : 365;
    int mdays[] = {31, 28 + is_leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 0; m < month - 1; m++)
        days += mdays[m];
    days += day - 1;
    return days;
}
void Date::from_days(int total) {
    year = 2000;
    int fl1 = 1;
    while (fl1) {
        int yd = is_leap(year) ? 366 : 365;
        if (total < yd) fl1 = 0;
        total -= yd;
        year++;
    }
    int fl2 = 1;
    int mdays[] = {31, 28 + is_leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    month = 1;
    for (int m = 0; m < 12 && fl2; m++) {
        if (total < mdays[m]) fl2 = 0;
        total -= mdays[m];
        month++;
    }
    day = total + 1;
}

Date::Date() : day(1), month(1), year(2000) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::operator int() const {
    return to_days();
}
Date::operator const char*() const {
    sprintf((char*)str_buf, "%02d.%02d.%04d", day, month, year);
    return str_buf;
}
const Date& Date::operator++() {
    from_days(to_days() + 1);
    return *this;
}
Date operator+(const Date& d, const Duration& dur) {
    Date res = d;
    res.from_days(d.to_days() + (int)dur);
    return res;
}
Date operator-(const Date& d, const Duration& dur) {
    Date res = d;
    res.from_days(d.to_days() - (int)dur);
    return res;
}
Duration operator-(const Date& d1, const Date& d2) {
    return Duration((int)d1 - (int)d2);
}
ostream& operator<<(ostream& out, const Date& d) {
    out << d.day << "." << d.month << "." << d.year;
    return out;
}
istream& operator>>(istream& in, Date& d) {
    char dot;
    in >> d.day >> dot >> d.month >> dot >> d.year;
    return in;
}
