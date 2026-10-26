#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov017_021d4ce4_3 {
    int key;
    int offset;
};
struct Struct_ov017_021d4ce4 {
    int unk0;
    int unknown_4_;
    int unknown_8_;
    int entriesOffset;
    int unknown_10_;
};
struct Struct_ov017_021d4ce4_2 {
    int field0;
    int unk4;
    int field8;
    int fieldC;
};

extern "C" void func_ov017_021d4e38(void* obj, int arg1);

// USA: func_ov017_021d4ce4
extern "C" ARM int func_ov017_021d4ce4(void* objRaw, int key) {
    unsigned char* obj = (unsigned char*)objRaw;
    if (*(struct Struct_ov017_021d4ce4**)(obj + 0x44) == NULL) {
        return -1;
    }

    *(int*)(obj + 0x14) = *(int*)(obj + 0x10);
    *(int*)(obj + 0x28) = *(int*)(obj + 0x24);
    *(struct Struct_ov017_021d4ce4_2**)(obj + 0x34) = NULL;

    if (key < 0) {
        struct Struct_ov017_021d4ce4* table = *(struct Struct_ov017_021d4ce4**)(obj + 0x44);
        *(struct Struct_ov017_021d4ce4_2**)(obj + 0x34) = (struct Struct_ov017_021d4ce4_2*)((char*)table + table->unknown_4_);
    } else {
        struct Struct_ov017_021d4ce4_3* entry;
        int i;
        struct Struct_ov017_021d4ce4* table = *(struct Struct_ov017_021d4ce4**)(obj + 0x44);
        entry = (struct Struct_ov017_021d4ce4_3*)((char*)table + table->entriesOffset);
        for (i = 0; i < table->unknown_10_; i++, entry++) {
            if (entry->key == key) {
                *(struct Struct_ov017_021d4ce4_2**)(obj + 0x34) = (struct Struct_ov017_021d4ce4_2*)((char*)table + entry->offset);
                break;
            }
        }
    }

    if (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34) == NULL) {
        return -1;
    }

    int var5 = *(int*)(obj + 0x14) - (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->fieldC * 8;
    *(int*)(obj + 0x30) = var5;
    *(int*)(obj + 0x14) = var5 + (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->field8 * 8;

    int dst = *(int*)(obj + 0x30) + (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->fieldC * 8;
    int size = ((*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->field8 - (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->fieldC) * 8;
    memset((void*)dst, 0, size);

    int var8 = *(int*)(obj + 0x48) + (*(struct Struct_ov017_021d4ce4_2**)(obj + 0x34))->field0;
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x50) = 0;

    func_ov017_021d4e38(obj, var8);

    return (*(int*)(obj + 0x3c) == 0) ? 1 : 0;
}
