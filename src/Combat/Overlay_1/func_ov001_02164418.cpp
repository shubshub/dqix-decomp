#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

struct Struct_0203de84 : Vector3i {};
struct Node020406f8;
extern "C" void func_020406f8(Struct_0203de84* dst, Node020406f8* n);

struct Struct_ov001_02164418 { int type; char pad[8]; void* unknown_c_; };

// USA: func_ov001_02164418
extern "C" ARM int func_ov001_02164418(Struct_ov001_02164418* table, int index, Vector3i* dst) {
    Struct_ov001_02164418* entry;
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
            *dst = *(Vector3i*)((char*)member + 0x44);
            return 1;
        case 2:
        case 6: {
            Struct_0203de84 tmp;
            member = entry->unknown_c_;
            if (member == 0) return 0;
            func_020406f8(&tmp, (Node020406f8*)member);
            *dst = tmp;
            return 1;
        }
        default:
            return 0;
    }
}
