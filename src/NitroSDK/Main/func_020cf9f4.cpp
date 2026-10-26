#include <globaldefs.h>

struct Struct_020cf9f4 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int unknown_c_;
};

extern int data_020f229c[12];

// USA: func_020cf9f4
extern "C" ARM void func_020cf9f4(Struct_020cf9f4* date, int day) {
    unsigned int year;
    int month;

    if (day < 0) {
        day = 0;
    }
    if (day > 36524) {
        day = 36524;
    }
    date->unknown_c_ = (day + 6) % 7;

    for (year = 0; year < 99; year++) {
        int prev = day;
        day -= (year & 3) == 0 ? 366 : 365;
        if (day < 0) {
            day = prev;
            break;
        }
    }
    date->year = year;
    if (day > 365) {
        day = 365;
    }

    if ((year & 3) == 0) {
        if (day < 31 + 29) {
            if (day < 31) {
                month = 1;
            } else {
                day -= 31;
                month = 2;
            }
            date->month = month;
            date->day = day + 1;
            return;
        }
        day--;
    }

    for (month = 11; month >= 0; month--) {
        if (day >= data_020f229c[month]) {
            date->month = month + 1;
            date->day = day - data_020f229c[month] + 1;
            return;
        }
    }
}
