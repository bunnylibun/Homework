#include <iostream>
#include <cstring>
#include "lib.hpp"
using namespace std;

int main() {
    Duration d2(10);
    cout << "Tests for Duration: " << endl;
    int days_int = d2;
    const char* days_str = d2;
    cout << "d2 as int:    " << days_int << endl;
    cout << "d2 as char*:  " << days_str << endl;
    Duration d3 = -d2;              
    cout << "Unary minus -d2: " << d3 << endl;
    cout << "Binary operations: " << endl;
    Duration d4(5);
    Duration sum = d2 + d4;
    Duration diff = d2 - d4;
    Duration mul = d2 * 3;
    cout << "10 + 5 = " << sum << endl;
    cout << "10 - 5 = " << diff << endl;
    cout << "10 * 3 = " << mul << endl;
    cout << "Operator<< for d2: " << d2 << endl;
    cout << "Input duration: ";
    Duration d_input;
    cin >> d_input;
    cout << "You chose: " << d_input << endl;


    Date date2(31, 10, 2026);
    cout << "Tests for Date" << endl;
    int date_int = date2; 
    const char* date_str = date2;
    cout << "date2 as int:    " << date_int << " (days from 01.01.2000)" << endl;
    cout << "date2 as char*:  " << date_str << endl;
    Date date3(31, 10, 2026);
    cout << "Before ++: " << date3 << endl;
    ++date3;
    cout << "After ++: " << date3 << endl;
    Date date3b(28, 2, 2024);
    cout << "Before ++: " << date3b << " (leap year)" << endl;
    ++date3b;
    cout << "After ++: " << date3b << endl;
    Date date3c(31, 12, 2026);
    cout << "Before ++: " << date3c << endl;
    ++date3c;
    cout << "After ++: " << date3c << endl;
    cout << "Binary operations: " << endl;
    Date d_a(15, 10, 2026);
    Date d_b(25, 10, 2026);
    Duration dur(10);
    Date d_plus = d_a + dur; 
    Date d_minus = d_b - dur;
    Duration d_diff = d_b - d_a;
    cout << d_a << " + " << dur << " = " << d_plus << endl;
    cout << d_b << " - " << dur << " = " << d_minus << endl;
    cout << d_b << " - " << d_a << " = " << d_diff << endl;
    Duration d_diff2 = d_a - d_b;
    cout << d_a << " - " << d_b << " = " << d_diff2 << endl;
    cout << "Operator<< for date2: " << date2 << endl;
    cout << "Input date in format DD.MM.YYYY: ";
    Date date_input;
    cin >> date_input;
    cout << "You chose " << date_input << endl;
    return 0;
}
