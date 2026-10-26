#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_022187a4(char* obj, void* out, int len);
extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);

struct Struct_ov031_02218468 {
    char* unknown_0_;
    char* current;
    char* end;
    int capacity;
};

extern char data_ov031_02249e5c[];
extern char data_ov031_02249eb0[];

// USA: func_ov031_02218468
extern "C" ARM int func_ov031_02218468(char* obj) {
    Struct_ov031_02218468* ctx = (Struct_ov031_02218468*)(obj + 0x1f8 + 0x1800);
    int flag = *(int*)(obj + 0x1008);
    char* fmt = (flag == 0) ? data_ov031_02249e5c : data_ov031_02249eb0;

    unsigned int var3 = strlen(*(char**)(obj + 0x1124));
    unsigned int var4 = strlen(fmt);
    unsigned int var5 = strlen(*(char**)(obj + 0x1128));
    unsigned int total = var3 + ((var4 - 4) + var5);
    total = total + 0x400;

    if (func_ov031_022187a4(obj, obj + 0x1f8 + 0x1800, total) != 1) {
        return 1;
    }

    int var7 = func_020c7170(ctx->current, ctx->capacity, fmt,
        *(char**)(obj + 0x1128), *(char**)(obj + 0x1124));
    ctx->current = ctx->current + var7;
    return 0;
}
