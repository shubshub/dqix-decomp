#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca534_4 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned char unknown_c_[0x22 - 0xc];
    unsigned short unknown_22_0_ : 2;
    unsigned short unknown_22_2_ : 4;
    unsigned short unknown_22_6_ : 3;
    unsigned short unknown_23_1_ : 3;
    unsigned short unknown_23_4_ : 2;
    unsigned short unknown_23_6_ : 2;
    unsigned char field24;
    unsigned char field25;
    unsigned char unknown_26_[0xa4 - 0x26];
};

struct Struct_ov017_021ca534_5 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x158 - 0xa];
    Struct_ov017_021ca534_4 slots[8];
};

struct Struct_ov017_021ca534_6 {
    unsigned char pad0[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char pad3 : 4;
    unsigned char pad4[0x18 - 0xb];
};

struct Struct_ov017_021ca534 {
    unsigned char field0;
    unsigned char pad0 : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char pad1 : 2;
    unsigned char pad2[2];
    Struct_ov017_021ca534_6 entries[4];
};

struct Struct_ov017_021ca534_2 {
    unsigned short field4;
    unsigned short field6;
    unsigned short unknown_4_0_ : 2;
    unsigned short unknown_4_2_ : 4;
    unsigned short unknown_4_6_ : 3;
    unsigned short unknown_5_1_ : 3;
    unsigned short unknown_5_4_ : 2;
    unsigned short unknown_5_6_ : 2;
    unsigned char fielda;
    unsigned char unknown_7_;
    unsigned short fieldc;
    unsigned short unknown_a_;
    unsigned short field10;
    unsigned short field12;
};

struct Struct_ov017_021ca534_3 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021ca534_2 payload;
};

// USA: func_ov017_021ca534
extern "C" ARM void func_ov017_021ca534(Struct_ov017_021ca534* obj) {
#if defined(jpn)
 enum { regionalOffset = 0x508 };
#else
 enum { regionalOffset = 0x718 };
#endif
    GameState::GetInstance();
    unsigned char* ov = (unsigned char*)GetGameResources();
    void* h = *(void**)(ov + 0x3000 + regionalOffset);
    Struct_ov017_021ca534_5* c = (Struct_ov017_021ca534_5*)func_ov017_021b8478(h);
    void* p = LinkMessageQueue_GetInstance();

    for (int i = 0; i < obj->unknown_1_4_; i++) {
        Struct_ov017_021ca534_6* e = &obj->entries[i];
        Struct_ov017_021ca534_3 buf;
        for (int j = 0; j < e->unknown_a_0_; j++) {
            unsigned char v = e->unknown_2_[j];
            if (v >= 8) continue;
            Struct_ov017_021ca534_4* s = &c->slots[v];
            Struct_ov017_021ca534_2* var10 = &buf.payload;

            buf.tag = 0x5d;
            var10->field4 = c->field8;
            var10->field6 = e->unknown_2_[j] + 0xc0;
            var10->unknown_4_0_ = (unsigned char)s->unknown_22_0_;
            var10->unknown_4_2_ = (unsigned char)s->unknown_22_2_;
            var10->unknown_4_6_ = (unsigned char)s->unknown_22_6_;
            var10->unknown_5_1_ = (unsigned char)s->unknown_23_1_;
            var10->unknown_5_4_ = (unsigned char)s->unknown_23_4_;
            var10->fielda = s->field24;
            var10->unknown_7_ = s->field25;
            var10->fieldc = s->field4;
            var10->unknown_a_ = s->field6;
            var10->field10 = s->field8;
            var10->field12 = s->fielda;
            func_0205e330(p, &buf, 0);
        }
    }
}
