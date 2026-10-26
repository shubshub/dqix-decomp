#include <globaldefs.h>

#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

extern "C" void func_020ca408(void* dst, void* src, int size);
extern void* data_02110370;

struct Struct_020bd368 {
    int unknown_0_;    // +0x0
    char pad4[4];
    void* unknown_8_;   // +0x8
    char unknown_c_[4];
};

struct Struct_020bd368_2 {
    char pad0[8];
    unsigned int count;        // +0x8
    struct Struct_020bd368 entries[1]; // +0xc
};

struct Struct_020bd368_3 {
    char pad0[0x10];
    int f10;               // +0x10
    char unknown_14_[4];
    int f18;                // +0x18
    char unknown_1c_[4];
    int f20;                 // +0x20
    char pad24[0xc];
    int unknown_30_;                  // +0x30
    char unknown_34_[0x50];
    struct Struct_020bd368_2* f84; // +0x84
    void* unknown_88_;                      // +0x88
    void* unknown_8c_;                       // +0x8c
    int f90;                          // +0x90
};

// USA: func_020bd368
extern "C" ARM void func_020bd368(struct Struct_020bd368_3* obj, char* base) {
    func_020ca408(base, obj, 0x30);
    obj->unknown_8c_ = obj->f18 == 0 ? 0 : base + obj->f18;
    obj->f84 = (struct Struct_020bd368_2*)(obj->f20 == 0 ? 0 : base + obj->f20);
    obj->unknown_88_ = obj->f10 == 0 ? 0 : base + obj->f10;
    obj->f90 = 0;
    unsigned int i = 0;
    if (i < obj->f84->count) {
        int off = 0;
        do {
            struct Struct_020bd368* entry = (struct Struct_020bd368*)((char*)obj->f84 + 0xc + off);
            int raw = entry->unknown_0_;
            entry->unknown_8_ = raw == 0 ? 0 : base + raw;
            off += 0x10;
            i++;
        } while (i < obj->f84->count);
    }
    obj->unknown_30_ = 0;
    data_02110370 = obj;
}
