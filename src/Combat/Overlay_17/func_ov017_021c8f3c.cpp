#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c8f3c_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_0_ : 4;
    short unknown_4_4_ : 3;
    unsigned short unknown_4_7_ : 9;
    short unknown_6_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
};

struct Struct_ov017_021c8f3c_3 {
    unsigned short unknown_0_;
    short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char unknown_a_;
};

extern "C" void func_ov017_021c90b4(Struct_ov017_021c8f3c_2* arg0, Struct_ov017_021c8f3c_2* arg1);
extern "C" void func_ov017_021c90f8(Struct_ov017_021c8f3c_3* arg0, Struct_ov017_021c8f3c_3* arg1);

struct Struct_ov017_021a1d98_3 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0xb8 - 0xac];
    unsigned short unknown_b8_;
    unsigned char unknown_ba_[0x130 - 0xba];
    int unknown_130_;
    unsigned char unknown_134_[0x164 - 0x134];
    unsigned short unknown_164_;
    unsigned short unknown_166_;
    unsigned short unknown_168_;
    unsigned short unknown_16a_;
    unsigned char unknown_16c_[0x17d - 0x16c];
    unsigned char unknown_17d_;
};

struct Struct_ov017_021c8f3c {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_0_ : 2;
    unsigned char unknown_5_;
    union {
        Struct_ov017_021c8f3c_2 unknown_0_;
        Struct_ov017_021c8f3c_3 unknown1_0_;
    } unknown_6_;
};

// USA: func_ov017_021c8f3c
extern "C" ARM void func_ov017_021c8f3c(int arg0, int arg1) {
    Struct_ov017_021c8f3c_2 var0;
    Struct_ov017_021c8f3c_3 var1;
    struct Struct_ov017_021c8f3c var2;

    struct FieldMonster* m = (struct FieldMonster*)GameState::GetInstance()->GetFieldMonsterByIndex(index);
    if (m == NULL) {
        return;
    }
    var0.unknown_0_ = var3->unknown_16a_;
    var0.unknown_4_4_ = arg1;
    var0.unknown_2_ = var3->unknown_0_.GetField06();
    var0.unknown_6_ = var3->unknown_0_.unknown_2_;
    var0.unknown_4_0_ = (unsigned short)((arg0 - 0x70) % 12);
    var0.unknown_4_7_ = var3->unknown_168_;
    var0.unknown_8_ = var3->unknown_17d_;
    var0.unknown_a_ = var3->unknown_b8_;
    var0.unknown_c_ = var3->unknown_164_;
    var0.unknown_9_ = var3->unknown_166_;

    var1.unknown_0_ = var3->unknown_16a_;
    Vector3i* var4 = &var3->unknown_0_.position_;
    var1.unknown_4_ = (short)(var4->x >> 7);
    var1.unknown_6_ = (short)(var4->y >> 7);
    var1.unknown_8_ = (short)(var4->z >> 7);
    var1.unknown_2_ = var3->unknown_0_.rotation_.y;
    var1.unknown_a_ = var3->unknown_130_;

    void* data = LinkMessageQueue_GetInstance();
    msg.tag = 0x83;
    msg.kind = 0;
    CopyStruct021c90b4(&msg.payload.info, &info);
    func_0205e330(data, &msg, 0);

    var2.unknown_0_ = 0x83;
    var2.unknown_4_0_ = 1;
    func_ov017_021c90f8(&var2.unknown_6_.unknown1_0_, &var1);
    func_0205e330(var5, &var2, 0);
}
