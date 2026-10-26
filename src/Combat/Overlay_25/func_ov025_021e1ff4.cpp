#include <globaldefs.h>

extern "C" int func_020493ec(unsigned char* obj);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_020493dc(unsigned char* obj, unsigned char value);

struct Struct_ov025_021e1ff4 {
    char pad0[4];
    short id;
};

struct Struct_ov025_021e1ff4_2 {
    unsigned char id;
    char pad1[3];
    int matched;
    unsigned char* obj;
};

// USA: func_ov025_021e1ff4
extern "C" ARM void func_ov025_021e1ff4(unsigned char* ids, int idCount, unsigned char* out, Struct_ov025_021e1ff4* a,
                                        Struct_ov025_021e1ff4* b, Struct_ov025_021e1ff4_2* entries, int arg6) {
    if (a == 0 || b == 0) {
        return;
    }
    for (int i = 0; i < idCount; i++) {
        if (ids[i] >= 0x51) {
            continue;
        }
        if (ids[i] < 0x51) {
            out[ids[i]] = 0xff;
        }
        for (int j = 0; j < arg6; j++) {
            unsigned char* obj = entries[j].obj;
            int id = entries[j].id;
            if (id == a->id || id == b->id) {
                continue;
            }
            int v = func_020493ec(obj);
            if (v >= 0x51) {
                v = func_020493a4(obj);
            }
            if (v == ids[i]) {
                entries[j].matched = 1;
                func_020493dc(obj, 0xff);
            }
        }
    }
}
