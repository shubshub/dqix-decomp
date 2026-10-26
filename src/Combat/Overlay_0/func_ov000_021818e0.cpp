#include <globaldefs.h>

struct Struct_ov000_021600f8 { char pad[0x20]; struct Struct_ov000_021600f8* next; };
struct Struct_ov000_0215440c { char pad0[9]; unsigned char count; char pad1[10]; struct Struct_ov000_021600f8* head; };
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);

struct Struct_ov000_02160094 { char pad[0x30]; struct Struct_ov000_02160094* next; };
struct Struct_ov000_0215440c_2 { char pad0[8]; unsigned char count; char pad1[7]; struct Struct_ov000_02160094* head; };
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);

extern "C" int func_ov000_0215ffa0(struct Struct_ov000_021600f8* node);

// USA: func_ov000_021818e0
extern "C" ARM int func_ov000_021818e0(int selector, int index, void* list, int* out) {
    switch (selector) {
    case 0: {
        struct Struct_ov000_0215440c* l = (struct Struct_ov000_0215440c*)list;
        if (l->count < index + 1) return 0;
        struct Struct_ov000_021600f8* node = func_ov000_021600f8(l, index);
        *out = *(short*)((char*)node + 0xe);
        return 1;
    }
    case 1: {
        struct Struct_ov000_0215440c_2* l = (struct Struct_ov000_0215440c_2*)list;
        if (l->count < index + 1) return 0;
        struct Struct_ov000_02160094* node = func_ov000_02160094(l, index);
        *out = *(unsigned short*)((char*)node + 0x20);
        return 1;
    }
    case 2: {
        struct Struct_ov000_0215440c* l = (struct Struct_ov000_0215440c*)list;
        if (l->count < index + 1) return 0;
        struct Struct_ov000_021600f8* node = func_ov000_021600f8(l, index);
        *out = func_ov000_0215ffa0(node);
        return 1;
    }
    }
    return 0;
}
