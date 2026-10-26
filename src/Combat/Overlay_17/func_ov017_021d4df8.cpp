#include <globaldefs.h>

struct Struct_ov017_021d4df8 {
    unsigned char pad0[0xc];
    int offset;
    int count;
};

// USA: func_ov017_021d4df8
extern "C" ARM int func_ov017_021d4df8(void* obj, int key) {
    char* entry;
    int i;
    struct Struct_ov017_021d4df8* header = *(struct Struct_ov017_021d4df8**)((char*)obj + 0x44);
    entry = (char*)header + header->offset;
    for (i = 0; i < header->count; i++, entry += 8) {
        if (*(int*)entry == key) return 1;
    }
    return 0;
}
