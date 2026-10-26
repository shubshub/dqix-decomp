#include <globaldefs.h>

struct Struct_ov025_021e110c_2 {
    char pad[0x10];
    unsigned int flags;
};

struct Struct_ov025_021e110c {
    unsigned char id;
    unsigned char val;
    char pad[6];
    unsigned char* obj;
};

extern "C" int func_020493a4(unsigned char*);
extern "C" int func_020493c8(unsigned char*);
extern "C" int func_020493ec(unsigned char*);
extern "C" void func_ov025_021e12f8(unsigned char* map, int id, int val, int extra, int a, int b);

static inline void inline_ov025_021e110c(unsigned char* map, unsigned int id, unsigned char val) {
    if (id < 0x51) {
        map[id] = val;
    }
}

// USA: func_ov025_021e110c
extern "C" ARM void func_ov025_021e110c(unsigned char* map, Struct_ov025_021e110c* ents, int n) {
    for (int i = 0; i < 0x51; i++) {
        if (map[i] < 0xff) {
            map[i] = 0;
        }
    }
    for (int j = 0; j < n; j++) {
        unsigned int id = func_020493c8(ents[j].obj);
        if (id >= 0x51) {
            id = func_020493a4(ents[j].obj);
        }
        if (id < 0x51) {
            inline_ov025_021e110c(map, id, ents[j].val);
        }
        unsigned char* c = ents[j].obj;
        Struct_ov025_021e110c_2* sub;
        if ((*(unsigned short*)c & 0x400) && (sub = *(Struct_ov025_021e110c_2**)(c + 0x148)) != 0) {
            unsigned int extra = (sub->flags << 1) >> 0x1e;
            if (extra != 0) {
                func_ov025_021e12f8(map, id, ents[j].val, extra & 0xff, 0, 0);
            }
        }
        unsigned int id2 = func_020493ec(ents[j].obj);
        if (id2 < 0x51) {
            inline_ov025_021e110c(map, id2, ents[j].val);
        }
    }
}
