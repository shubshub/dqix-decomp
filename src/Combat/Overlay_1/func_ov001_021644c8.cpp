#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_020407c4 { unsigned int v[3]; };
struct Struct_020407c4_2;
extern "C" void func_020407c4(Struct_020407c4* dst, Struct_020407c4_2* n);

struct Struct_ov001_021644c8 { int type; char pad[8]; void* unknown_c_; };

// USA: func_ov001_021644c8
extern "C" ARM int func_ov001_021644c8(Struct_ov001_021644c8* table, int index, Vector3i* dst) {
    Struct_ov001_021644c8* entry;
    void* member;
    if (index < 0 || index >= 0x20) return 0;
    entry = &table[index];
    switch (entry->type) {
        case 0:
        case 1:
        case 4:
        case 5:
            member = entry->unknown_c_;
            if (member == 0) return 0;
            *dst = *(Vector3i*)((char*)member + 0x50);
            return 1;
        case 2:
        case 6: {
            Struct_020407c4 tmp;
            member = entry->unknown_c_;
            if (member == 0) return 0;
            func_020407c4(&tmp, (Struct_020407c4_2*)member);
            *dst = *(Vector3i*)&tmp;
            return 1;
        }
        default:
            return 0;
    }
}
