#include <globaldefs.h>

extern "C" void* func_020bd4b8(int index);
extern "C" int func_020bd8ac(unsigned int index);

struct Struct_020be7a8 { int f0; int f4; int f8; };
struct Struct_020be7a8_2 { char pad[0x1c]; unsigned int count; struct Struct_020be7a8 elems[1]; };
extern "C" struct Struct_020be7a8 *func_020c01ac(struct Struct_020be7a8_2 *list, int index);

extern "C" int func_020be924(void *obj, unsigned char arg1, unsigned short h4, unsigned char b8,
    struct Struct_020be7a8 *entry, int val, int id, int index);

// Main, originally TrySetActionFromListEntry_020be7a8 (USA 0x020be7a8, EUR 0x020be7b8, JPN 0x020c0274)
extern "C" ARM int NNS_SndArcPlayerStartSeqArc(void *obj, int id, int index) {
    void *p = func_020bd4b8(id);
    if (p == NULL) {
        return 0;
    }
    int var1 = *(int*)p;
    int val = func_020bd8ac((unsigned int)var1);
    if (val == 0) {
        return 0;
    }
    struct Struct_020be7a8 *entry = func_020c01ac((struct Struct_020be7a8_2*)val, index);
    if (entry == NULL) {
        return 0;
    }
    return func_020be924(obj, *(unsigned char*)((char*)entry + 0x9), *(unsigned short*)((char*)entry + 0x4),
        *(unsigned char*)((char*)entry + 0x8), entry, val, id, index);
}
