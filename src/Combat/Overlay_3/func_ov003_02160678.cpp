#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02160678_804 = 0x20c };
enum { Enum_ov003_02160678_1128 = 0x290 };
enum { Enum_ov003_02160678_808 = 0x210 };
#else
enum { Enum_ov003_02160678_804 = 0x324 };
enum { Enum_ov003_02160678_1128 = 0x468 };
enum { Enum_ov003_02160678_808 = 0x328 };
#endif

struct Struct_0207fdcc_2;
extern "C" int func_020811d0(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020809c4(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void func_ov003_021604f4(char* obj, int valA, int valB, short index, unsigned char flag);

extern const short data_ov003_0217f400[];
extern const short data_ov003_0217f41a[];

struct Struct_ov003_02160678 {
    char pad0[Enum_ov003_02160678_804];
    struct Struct_0207fdcc_2* list;
    char unknown_328_[Enum_ov003_02160678_1128 - Enum_ov003_02160678_808];
    unsigned char slots[4];
};

// USA: func_ov003_02160678
extern "C" ARM void func_ov003_02160678(struct Struct_ov003_02160678* self) {
    struct Struct_0207fdcc_2* list = self->list;
    if (list == NULL) {
        return;
    }
    long i = 0;
    int found = 0;
    while (data_ov003_0217f41a[i] >= 0) {
        if (func_020811d0(list, data_ov003_0217f41a[i])) {
            found = 1;
            break;
        }
        i = (short)(i + 1);
    }
    if (!found) {
        return;
    }
    short id = data_ov003_0217f400[i];
    unsigned char flag = 3;
    for (unsigned char k = 0; k < 4; k++) {
        if (self->slots[k] != 0) {
            short x;
            short y;
            func_020809c4(list, data_ov003_0217f41a[i], id, &x, &y);
            func_ov003_021604f4((char*)self, (short)(x + 0x38), (short)(y - 2), self->slots[k] + 8, flag++);
        }
        id++;
    }
}
