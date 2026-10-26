#if defined(jpn)
enum { Enum_ov017_021ca3c4_1816 = 0x508 };
#else
enum { Enum_ov017_021ca3c4_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca3c4_3 {
    unsigned short field0;
    unsigned short field2;
    unsigned char pad4[0x10];
    unsigned int field14;
    unsigned int field18;
    unsigned char unknown_1c_[0xa4 - 0x1c];
};

struct Struct_ov017_021ca3c4_4 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x158 - 0xa];
    Struct_ov017_021ca3c4_3 slots[8];
};

struct Struct_ov017_021ca3c4_5 {
    unsigned char pad0[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char pad3 : 4;
    unsigned char pad4[0x18 - 0xb];
};

struct Struct_ov017_021ca3c4_6 {
    unsigned char field0;
    unsigned char pad0 : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char pad1 : 2;
    unsigned char pad2[2];
    Struct_ov017_021ca3c4_5 entries[4];
};

struct Struct_ov017_021ca3c4 {
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned int fieldc;
    unsigned int field10;
};

struct Struct_ov017_021ca3c4_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021ca3c4 payload;
};

// USA: func_ov017_021ca3c4
extern "C" ARM void func_ov017_021ca3c4(Struct_ov017_021ca3c4_6* obj) {
    unsigned char* ov = (unsigned char*)GetGameResources();
    void* h = *(void**)(ov + 0x3000 + Enum_ov017_021ca3c4_1816);
    Struct_ov017_021ca3c4_4* c = (Struct_ov017_021ca3c4_4*)func_ov017_021b8478(h);
    void* p = LinkMessageQueue_GetInstance();

    for (int i = 0; i < obj->unknown_1_4_; i++) {
        Struct_ov017_021ca3c4_5* e = &obj->entries[i];
        Struct_ov017_021ca3c4_2 buf;
        for (int j = 0; j < e->unknown_a_0_; j++) {
            unsigned char v = e->unknown_2_[j];
            if (v >= 8) continue;
            Struct_ov017_021ca3c4_3* s = &c->slots[v];
            Struct_ov017_021ca3c4* var10 = &buf.payload;

            buf.tag = 0x5c;
            var10->field4 = c->field8;
            var10->field6 = e->unknown_2_[j] + 0xc0;
            var10->field8 = s->field0;
            var10->fielda = s->field2;
            var10->fieldc = s->field14;
            var10->field10 = s->field18;
            func_0205e330(p, &buf, 0);
        }
    }
}
