#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);

struct Struct_ov017_021c62e4 {
    unsigned char pad0[8];
    unsigned short id;
};

struct Struct_ov017_021c62e4_2 {
    unsigned char pad0[2];
    unsigned char values[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    unsigned char unknown_b_[0xd];
};

struct Struct_ov017_021c62e4_3 {
    unsigned char pad0[4];
    Struct_ov017_021c62e4_2 slots[1];
};

struct Struct_ov017_021c62e4_4 {
    unsigned short id;
    short slotIndex;
    unsigned char values[8];
};

struct Struct_ov017_021c62e4_5 {
    unsigned char tag;
    unsigned char pad1[3];
    Struct_ov017_021c62e4_4 payload;
};

// USA: func_ov017_021c62e4
extern "C" ARM void func_ov017_021c62e4(int unused0, Struct_ov017_021c62e4_5* src, void* arg2, char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    Struct_ov017_021c62e4_2* slot;
    int i;
    void* table = *(void**)(base + 0x3000 + regionalOffset0);

    char* state = (char*)func_ov017_021b8470(table);
    if (!state) return;

    Struct_ov017_021c62e4* owner = (Struct_ov017_021c62e4*)func_ov017_021b8478(table);
    if (!owner) return;

    Struct_ov017_021c62e4_4* p = &src->payload;
    if (owner->id != p->id) return;

    slot = &((Struct_ov017_021c62e4_3*)(state + 0x1b0 + 0x8000))->slots[p->slotIndex];
    for (i = 0; i < slot->count; i++) {
        slot->values[i] = 0;
        slot->values[i] = p->values[i];
    }
}
