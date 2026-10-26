#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double _dflt(int);
extern "C" double _ddiv(double, double);
extern "C" int _dfix(double);

// Main, originally func_02032370 (USA 0x02032370, EUR 0x02032380, JPN 0x02031ea8)
extern "C" ARM int RandomIntBelow(int limit) {
    int roll = rand();
    double range = _dflt(limit);
    double fraction = _ddiv(_dflt(roll - 1), 32767.0);
    return _dfix(((range) * (fraction)));
}
