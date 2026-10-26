#include <globaldefs.h>
#include "std_library_functions.h"
struct Struct_0209e7a4_3 { char data[0x40]; };
struct Struct_0209e7a4 { char pad0[0x5c60]; Struct_0209e7a4_3 entries[16]; char unknown_6060_[0x8e07-0x6060]; unsigned char count; };
struct Struct_0209e7a4_2 { int field_0x0; Struct_0209e7a4* source; char pad8[0x90]; int count; Struct_0209e7a4_3 entries[16]; int unknown_49c_; Struct_0209e7a4_3 unknown_4a0_[16]; };
extern "C" int func_0209dcdc(Struct_0209e7a4_2*, Struct_0209e7a4_3*, int, int);
// USA: func_0209e7a4
extern "C" ARM void func_0209e7a4(Struct_0209e7a4_2* mgr, int arg1, int arg) {
    int limit;
    int i;
    Struct_0209e7a4_3* source;
    Struct_0209e7a4_3* entry;
    i = 0;
    if (!arg1) {
        mgr->count = 0;
        limit = mgr->source->count;
        for (i = 0; i < limit; i++) {
            entry = &mgr->source->entries[i];
            if (entry && func_0209dcdc(mgr, entry, 0, arg)) {
                memcpy(&mgr->entries[mgr->count++], entry, 0x40);
            }
        }
    } else {
        mgr->unknown_49c_ = 0;
        memset(mgr->unknown_4a0_, 0, 0x400);
        source = mgr->entries;
        for (i = 0; i < mgr->count; i++) {
            entry = &source[i];
            if (func_0209dcdc(mgr, entry, 0, arg)) {
                int count = mgr->unknown_49c_;
                mgr->unknown_49c_ = mgr->unknown_49c_ + 1;
                memcpy(&mgr->unknown_4a0_[count], entry, 0x40);
            }
        }
        mgr->count = mgr->unknown_49c_;
        memcpy(mgr->entries, mgr->unknown_4a0_, 0x400);
    }
}
