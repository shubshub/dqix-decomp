#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Struct_0209c08c {
    unsigned short items[0xc];
    unsigned short count;
};
extern "C" void func_0209c08c(struct Struct_0209c08c* s, unsigned short value);

struct Struct_0209bed8 {
    struct Struct_0209c08c* text;
    unsigned short current;
    unsigned short unknown_6_;
    void* script;
};

extern struct Struct_0209bed8* data_02109bc8;

// USA: func_0209bed8
extern "C" ARM bool func_0209bed8(struct Variant02030b0c* args, int arg1) {
    if (data_02109bc8->script == 0) {
        return true;
    }
    int id = ((Script::Parameter*)args)->ToInt();
    if (id != data_02109bc8->unknown_6_) {
        return true;
    }

    struct Variant02030b0c* range = args + 1;
    args += 2;
    int packed = ((Script::Parameter*)range)->ToInt();
    int var3 = (packed >> 24) & 0xf;
    int var4 = (packed >> 16) & 0xf;
    int var5 = (packed >> 8) & 0xf;
    int var6 = packed & 0xf;
    int first = var3 * 100 + var4;
    int last = var5 * 100 + var6;

    int matched = 0;
    if (first <= data_02109bc8->current && data_02109bc8->current <= last) {
        data_02109bc8->script = 0;
        matched = 1;
    } else if (var3 == 0 && var4 == 0 && var5 == 0 && var6 == 0) {
        matched = 1;
    }
    if (matched != 0) {
        for (int i = 0; i < arg1 - 2; i++) {
            int value = ((Script::Parameter*)args)->ToInt();
            args++;
            unsigned short high = (unsigned short)(value >> 16);
            unsigned short low = (unsigned short)value;
            if (high != 0) {
                func_0209c08c(data_02109bc8->text, high);
            }
            if (low != 0) {
                func_0209c08c(data_02109bc8->text, low);
            }
        }
    }
    return true;
}
