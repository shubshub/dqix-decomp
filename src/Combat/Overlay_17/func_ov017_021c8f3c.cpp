#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c8f3c_2 {
    unsigned short a;
    unsigned short b;
    unsigned short slot : 4;
    short mode : 3;
    unsigned short level : 9;
    short d;
    unsigned char e;
    unsigned char f;
    unsigned short g;
    unsigned short h;
};

struct Struct_ov017_021c8f3c_3 {
    unsigned short a;
    short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    unsigned char f;
};

extern "C" void func_ov017_021c90b4(Struct_ov017_021c8f3c_2* dst, Struct_ov017_021c8f3c_2* src);
extern "C" void func_ov017_021c90f8(Struct_ov017_021c8f3c_3* dst, Struct_ov017_021c8f3c_3* src);

struct FieldMonster {
    Object3D obj3D_;
    unsigned char unknown_ac_[0xb8 - 0xac];
    unsigned short fieldB8;
    unsigned char unknown_ba_[0x130 - 0xba];
    int unknown_130_;
    unsigned char unknown_134_[0x164 - 0x134];
    unsigned short unknown_164_;
    unsigned short field166;
    unsigned short unknown_168_;
    unsigned short unknown_16a_;
    unsigned char pad16c[0x17d - 0x16c];
    unsigned char unknown_17d_;
};

struct Struct_ov017_021c8f3c {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char kind : 2;
    unsigned char pad5;
    union {
        Struct_ov017_021c8f3c_2 info;
        Struct_ov017_021c8f3c_3 pos;
    } payload;
};

// USA: func_ov017_021c8f3c
extern "C" ARM void func_ov017_021c8f3c(int index, int mode) {
    Struct_ov017_021c8f3c_2 info;
    Struct_ov017_021c8f3c_3 pos;
    struct Struct_ov017_021c8f3c msg;

    struct FieldMonster* m = (struct FieldMonster*)GameState::GetInstance()->GetFieldMonsterByIndex(index);
    if (m == NULL) {
        return;
    }
    info.a = m->unknown_16a_;
    info.mode = mode;
    info.b = m->obj3D_.GetField06();
    info.d = m->obj3D_.unknown_2_;
    info.slot = (unsigned short)((index - 0x70) % 12);
    info.level = m->unknown_168_;
    info.e = m->unknown_17d_;
    info.g = m->fieldB8;
    info.h = m->unknown_164_;
    info.f = m->field166;

    pos.a = m->unknown_16a_;
    Vector3i* p = &m->obj3D_.position_;
    pos.c = (short)(p->x >> 7);
    pos.d = (short)(p->y >> 7);
    pos.e = (short)(p->z >> 7);
    pos.b = m->obj3D_.rotation_.y;
    pos.f = m->unknown_130_;

    void* data = LinkMessageQueue_GetInstance();
    msg.tag = 0x83;
    msg.kind = 0;
    func_ov017_021c90b4(&msg.payload.info, &info);
    func_0205e330(data, &msg, 0);

    msg.tag = 0x83;
    msg.kind = 1;
    func_ov017_021c90f8(&msg.payload.pos, &pos);
    func_0205e330(data, &msg, 0);
}
