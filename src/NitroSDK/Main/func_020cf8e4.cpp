#include <globaldefs.h>

extern int data_020f2298[13];

struct Struct_020cf8e4 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int unknown_c_;
};

// USA: func_020cf8e4
extern "C" ARM int func_020cf8e4(struct Struct_020cf8e4* d) {
    unsigned int year, month, day;
    int var3;
    if ((year = d->year) >= 100 || (month = d->month) < 1 || month > 12 ||
        (day = d->day) < 1 || day > 31 || (var3 = d->unknown_c_) >= 7 ||
        month < 1 || month > 12) {
        return -1;
    }
    int var4 = (day - 1) + data_020f2298[month];
    if (month >= 3 && (year & 3) == 0) var4++;
    return year * 365 + var4 + (year + 3) / 4;
}
