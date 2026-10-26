#include <globaldefs.h>

struct Struct_020cfc00 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int unknown_c_;
};

// USA: func_020cfc00  (NitroSDK: RTC_GetDayOfWeek)
extern "C" ARM int func_020cfc00(struct Struct_020cfc00* date) {
    int var0;
    int year = (int)(2000 + date->year);
    int month = (int)date->month;
    int day = (int)date->day;

    month -= 2;

    if (month < 1) {
        month += 12;
        --year;
    }

    var0 = year / 100;
    year %= 100;
    return ((26 * month - 2) / 10 + day + year + year / 4 + var0 / 4 + 5 * var0) % 7;
}
