#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021cf024_30536 = 0x7938 };
#else
enum { Enum_ov017_021cf024_30536 = 0x7748 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_02163338(unsigned char* obj, unsigned char val);

struct Struct_ov017_021cf024 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6;
    unsigned char unknown_7_;
};

struct Struct_ov017_021cf024_2 {
    unsigned char unknown0[8];
    unsigned short key;
};

struct Struct_ov017_021cf024_3 {
    unsigned char unknown0[Enum_ov017_021cf024_30536];
    unsigned char unknown_7748_;
};

// USA: func_ov017_021cf024
extern "C" ARM void func_ov017_021cf024(int unused0, Struct_ov017_021cf024* evt, int arg2, GameResources* base) {
    void* table = base->unknown_ptr_3718;
    Struct_ov017_021cf024_2* record = (Struct_ov017_021cf024_2*)func_ov017_021b8478(table);
    Struct_ov017_021cf024_3* work = (Struct_ov017_021cf024_3*)func_ov017_021b8468(table);
    if (work == NULL) {
        return;
    }
    if (record->key != evt->field4) {
        return;
    }
    func_ov000_02163338((unsigned char*)work, evt->field6);
    work->unknown_7748_ = evt->unknown_7_;
}
