#include <globaldefs.h>

#include "Resource/Script.h"

struct Struct_02072398 {
    short f0;
    short f2;
    short v[18];
    unsigned short f28;
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
};

struct Struct_02072560 {
    struct Struct_02072398* entries;
    short capacity;
    short count;
};

struct Struct_02108da8_2 {
    int f0;
    struct Struct_02072560* list;
};

extern "C" void func_02072560(struct Struct_02072560* list, struct Struct_02072398* src);

extern Struct_02108da8_2 data_02108da8;

// USA: func_02072398
extern "C" ARM int func_02072398(Script::Parameter* params, int count) {
    struct Struct_02072398 e;
    e.f0 = -1;
    e.f2 = -1;
    unsigned char i = 0;
    while (i < 18) {
        e.v[i] = -1;
        i++;
    }
    e.f28 = 100;
    e.unknown_2a_ = 0;
    e.f0 = (params++)->ToInt();
    e.f2 = (params++)->ToInt();
    count -= 2;
    for (int j = 0; j < 18; j++) {
        e.v[j] = params[0].ToInt();
        params++;
        count--;
    }
    if (count != 0) {
        e.f28 = params[0].ToInt();
        params++;
        count--;
    }
    if (count != 0) {
        e.unknown_2a_ = params[0].ToInt();
    }
    func_02072560(data_02108da8.list, &e);
    return 1;
}
