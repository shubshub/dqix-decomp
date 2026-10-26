#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);

struct Struct_ov017_021c8e70 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Struct_ov017_021c8e70_2 {
    unsigned short id;
    unsigned char pad2[6];
    unsigned char values[3];
    unsigned char count;
};

struct Struct_ov017_021c8e70_3 {
    unsigned char pad0[4];
    Struct_ov017_021c8e70_2 body;
};

struct Struct_ov017_021c8e70_4 {
    unsigned char pad0[0xa];
    unsigned char low : 4;
    unsigned char value : 4;
    unsigned char unknown_b_[0x18 - 0xb];
};

struct Struct_ov017_021c8e70_5 {
    unsigned char field0;
    unsigned char total : 4;
    unsigned char high : 4;
    unsigned char pad2[2];
    Struct_ov017_021c8e70_4 entries[1];
};

struct Struct_ov017_021c8e70_6 {
    unsigned char pad0[0x81b0];
    Struct_ov017_021c8e70_5 table;
};

// USA: func_ov017_021c8e70
extern "C" ARM void func_ov017_021c8e70(int unused0, Struct_ov017_021c8e70_3* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset=0x508};
#else
 enum {regionalOffset=0x718};
#endif
    Struct_ov017_021c8e70_2* body;
    int total;
    int i;
    Struct_ov017_021c8e70_5* table;
    void* h = *(void**)(obj + 0x3000 + regionalOffset);
    Struct_ov017_021c8e70* r = (Struct_ov017_021c8e70*)func_ov017_021b8478(h);
    if (!r) return;
    if (!func_ov017_021b8468(h)) return;
    Struct_ov017_021c8e70_6* owner = (Struct_ov017_021c8e70_6*)func_ov017_021b8470(h);
    if (!owner) return;
    if (r->field8 != src->body.id) return;
    table = &owner->table;
    body = &src->body;
    total = 0;
    for (i = 0; i < body->count; i++) {
        Struct_ov017_021c8e70_4* e = &table->entries[i];
        e->value = body->values[i];
        total += e->value;
    }
    table->total = (unsigned char)total;
}
