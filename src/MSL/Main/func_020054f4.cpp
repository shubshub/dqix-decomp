#include <globaldefs.h>

#define INT_MAX 0x7fffffff
#define ERANGE  34
#define LDBL_MIN 2.2250738585072014e-308
#define LDBL_MAX 1.7976931348623157e+308

typedef struct {
    char* unknown_0_;
    int unknown_4_;
} Struct_020054f4;

extern "C" int func_02003d58(void* arg0, int c, int action);
extern "C" long double func_020042a8(int arg0, int (*arg1)(void*, int, int), void* arg2,
                                     int* arg3, int* arg4);
extern "C" double func_02008f3c(double x);
extern int data_020f3390;

// USA: func_020054f4
extern "C" ARM long double func_020054f4(const char* str, char** end) {
    long double value, var1;
    int count, var3;
    Struct_020054f4 var4;

    var4.unknown_0_ = (char*)str;
    var4.unknown_4_ = 0;

    value = func_020042a8(INT_MAX, &func_02003d58, (void*)&var4, &count, &var3);

    if (end)
        *end = (char*)str + count;

    var1 = func_02008f3c(value);

    if (var3 || (value != 0.0 && (var1 < LDBL_MIN || var1 > LDBL_MAX)))
        data_020f3390 = ERANGE;

    return value;
}
