#include <globaldefs.h>

extern "C" int func_ov017_021959b4(void);
extern "C" void func_020936b0(void* obj);
extern "C" void func_02092e0c(void* obj);
extern "C" void func_02092f00(void* obj);

struct Struct_020e6d5c {
    void* fn;
    int flags;
};

struct Struct_020e8d84 {
    unsigned int w[10];
};

union Struct_02092bcc {
    struct Struct_020e8d84 raw;
    struct Struct_020e6d5c e[5];
};

extern struct Struct_020e8d84 data_020e8d84;
extern struct Struct_020e6d5c __ptmf_null;

// USA: func_02092bcc
extern "C" ARM int func_02092bcc(unsigned char* obj, int delta) {
    union Struct_02092bcc table;
    unsigned char id;
    struct Struct_020e6d5c* e;
    short v;

    if (obj[0x3a] == 0) {
        if (func_ov017_021959b4() != 0) {
            obj[0x3a] = 1;
            func_020936b0(obj);
        }
    }

    v = *(short*)(obj + 0x32);
    if (v > 0) {
        *(short*)(obj + 0x32) = v - delta;
        if (*(short*)(obj + 0x32) < 0) {
            *(short*)(obj + 0x32) = 0;
        }
    }

    func_02092e0c(obj);
    func_02092f00(obj);

    if (obj[0x37] & 0x4) {
        return 0;
    }

    table.raw = data_020e8d84;
    {
        int var4 = __ptmf_null.flags;
        void* var5 = __ptmf_null.fn;
        ((struct Struct_020e6d5c*)&table)[4].flags = var4;
        ((struct Struct_020e6d5c*)&table)[4].fn = var5;
    }

    id = obj[0x34];
    if (table.e[id].fn == 0) {
        return 1;
    }
    {
        e = &table.e[id];
        void* var6 = obj + (e->flags >> 1);
        void* target;
        if (e->flags & 1) {
            void** var8 = (void**)*(void**)var6;
            target = *(void**)((char*)var8 + (int)e->fn);
        } else {
            target = e->fn;
        }
        ((void (*)(void*))target)(var6);
    }
    return 0;
}
