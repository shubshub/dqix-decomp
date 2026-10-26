#include <globaldefs.h>

extern int g_stringFormat;
extern "C" void sprintf(void* dst, void* fmt, void* src);

struct Struct_0204887c {
    char pad0[0x148];
    char* field148;
};

// USA: func_0204887c
extern "C" ARM void func_0204887c(struct Struct_0204887c* obj, char* newVal) {
    char* old = obj->field148;
    obj->field148 = newVal;
    if (old == NULL) return;
    sprintf(obj->field148 + 0x2c, &g_stringFormat, old + 0x2c);
}
