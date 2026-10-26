#include <globaldefs.h>

struct Struct_020cf8e4;
extern "C" int func_020cf8e4(struct Struct_020cf8e4* d);
extern "C" int func_020cf978(unsigned char* obj);

// USA: func_020cf990
extern "C" ARM long long func_020cf990(int date, unsigned char* time) {
    int day, var1;
    day = func_020cf8e4((struct Struct_020cf8e4*)date);
    if (day == -1) {
        return -1;
    }
    var1 = func_020cf978(time);
    if (var1 == -1) {
        return -1;
    }
    return ((long long)day) * (60 * 60 * 24) + var1;
}
