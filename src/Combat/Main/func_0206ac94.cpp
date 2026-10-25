#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069430(void*, unsigned short);

// JPN: func_0206c730
extern "C" ARM unsigned short* func_0206c730(void* arg0, unsigned short arg1, unsigned short* arg2) {
    Struct_02021b84* var0 = static_cast<Struct_02021b84*>(arg0);
    if (!arg2) return NULL;
    if (!func_02069430(arg0, arg1)) return NULL;
    unsigned int var1 = 0;
    while (arg2) {
        if (*arg2 == arg1) return arg2;
        var1++;
        arg2++;
        if (var0->unknown_34_ < var1) break;
    }
    return NULL;
}
#else

struct Struct_0204254c {
    int unknown_0_;
    char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

extern bool IsHighByteFF02044494(void* obj, void* src);
extern bool IsHighByteFF0206ac6c(void* base, void* src);
extern "C" int memcmp(unsigned char* a, unsigned char* b, int n);
extern int Func0206abf8(void* obj, void* src);
struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);

// USA: func_0206ac94
extern "C" ARM int func_0206ac94(void* arg0, unsigned short arg1, unsigned char* arg2) {
    unsigned int var0;
    unsigned char* var1 = arg2;
    if (!var1) {
        return 0;
    }
    if (!func_02044494(arg0, &arg1)) {
        return 0;
    }
    var0 = 0;
    for (;;) {
        if (!*var1) {
            break;
        }
        if (IsHighByteFF0206ac6c(obj, q)) {
            int step;
            if (!memcmp((unsigned char*)&buf, q, 2)) {
                return (int)q;
            }
            var2 = func_0206abf8(arg0, var1) * 2 + 2;
            var1 += var2;
            var0 += var2;
        } else {
            struct Entry0204254c* e;
            int val = 1;
            e = Font_FindCharacter((int)q, *(unsigned char*)((char*)obj + 0x19dc));
            if (e) {
                val = e->field5;
            }
            var1 += var4;
            var0 += var4;
            if (*(unsigned int*)((char*)arg0 + 0x68) >= var0) {
                continue;
            }
            break;
        }
    }
    return 0;
}

#endif
