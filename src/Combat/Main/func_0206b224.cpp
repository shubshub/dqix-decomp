#include <globaldefs.h>

#if defined(jpn)
#define func_0206b224 func_0206cba0
enum { Enum_0206b224_76 = 0x18, Enum_0206b224_640 = 0x140 };
#else
enum { Enum_0206b224_76 = 0x4c, Enum_0206b224_640 = 0x280 };
#endif

#include "std_library_functions.h"

extern "C" void func_0206b104(void* obj);
extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);
extern "C" int STD_GetStringLength(const char* s);

struct Struct_0206b224 {
    char pad0[Enum_0206b224_76];
    void* field4c;
    void* unknown_50_;
    void* field54;
    unsigned char* unknown_58_;
    char unknown_5c_[4];
    void* field60;
};

// USA: func_0206b224
extern "C" ARM void func_0206b224(struct Struct_0206b224* obj) {
    func_0206b104(obj);
    memset(obj->field4c, 0, Enum_0206b224_640);
    memset(obj->unknown_50_, 0, Enum_0206b224_640);

#if defined(jpn)
    int var0 = 2;
    unsigned char* base = obj->unknown_58_;
#else
    int var0 = 1;
    unsigned char* base = obj->unknown_58_;
    if (base[1] == 0xff) {
        var0 = 2;
    }
#endif
    obj->field54 = base + var0;
    obj->unknown_58_ = base + var0;

    func_0206aa28(obj);
#if !defined(jpn)
    func_0206b974(obj, 1, obj->unknown_50_, obj->field60, 0xe3, 0, 1, 1);
    int len = STD_GetStringLength((const char*)obj->field60);
    memcpy(obj->unknown_50_, obj->field60, len);
#endif
}
