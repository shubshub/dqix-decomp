#include <globaldefs.h>

struct Struct_02003d58 {
    char* cursor;
    int field4;
};

extern "C" int func_02003d58(Struct_02003d58* obj, int val, int cmd);
extern "C" unsigned long func_020055e4(int base, int arg1,
                                       int (*arg2)(Struct_02003d58*, int, int),
                                       Struct_02003d58* arg, int* count,
                                       int* arg5, int* arg6);

extern int data_020f3390;

// USA: func_020059cc
extern "C" ARM long func_020059cc(const char* str, char** end, int base) {
    unsigned long value;
    int count, var2, var3;
    Struct_02003d58 var4;

    var4.cursor = (char*)str;
    var4.field4 = 0;

    value = func_020055e4(base, 0x7fffffff, func_02003d58, &var4, &count, &var2, &var3);

    if (end)
        *end = (char*)str + count;

    if (var3 || (!var2 && value > 0x7fffffff) || (var2 && value > 0x80000000)) {
        value = var2 ? 0x80000000 : 0x7fffffff;
        data_020f3390 = 0x22;
    } else if (var2) {
        value = -value;
    }

    return value;
}
