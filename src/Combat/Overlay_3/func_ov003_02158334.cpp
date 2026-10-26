#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02158334_498 = 0x1ee };
#else
enum { Enum_ov003_02158334_498 = 0x1f2 };
#endif
#include "GameState/GameState.h"

struct Struct_020200c0 {
    unsigned int flags;
    unsigned short hp;
};

struct Struct_ov003_02158334 {
    char name[0x30];
    unsigned short maxHP;
};

struct Struct_ov000_0215ab88 {
    char unk_0[0x130];
    Struct_020200c0* status;
    Struct_ov003_02158334* profile;
};

struct Struct_ov003_02158334_2;

struct Struct_ov003_02158334_3 {
    char unk_0[0x18];
    Struct_ov003_02158334_2* entries;
    char unk_1c[Enum_ov003_02158334_498 - 0x1c];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

struct Container02080f8c;
extern "C" void func_02080f8c(Container02080f8c*, int, int);
struct Struct_02080cc0;
extern "C" void func_02080cc0(Struct_02080cc0*, int, int);
extern "C" void func_020813ec(Struct_ov003_02158334_2*, int);

// USA: func_ov003_02158334
extern "C" ARM void func_ov003_02158334(Struct_ov003_02158334_3* self) {
    GameState* gs = GameState::GetInstance();
    int rows = 3;
    int id = 10;

    switch (self->memberCount) {
    case 3:
        rows = 4;
        id = 0xc;
        break;
    case 4:
        rows = 5;
        id = 0xf;
        break;
    }

    Struct_ov003_02158334_2* entries = self->entries;
    for (unsigned char i = 0; i < self->memberCount; i++) {
        Struct_ov000_0215ab88* member = (Struct_ov000_0215ab88*)func_0200ff1c(gs, self->memberIds[i]);
        if (member != NULL) {
            int color = 0xf;
            func_02080f8c((Container02080f8c*)entries, id, (int)member->profile->name);

            int maxHP = member->profile->maxHP;
            float ratio;
            if (maxHP == 0.0f) {
                ratio = 0.0f;
            } else {
                int hp = member->status->hp;
                ratio = (float)hp / maxHP;
            }
            if (ratio <= 0.25f) color = 0xd;
            if (ratio <= 0.08f) color = 0xb;
            if (member->status->flags & 1) color = 9;

            func_02080cc0((Struct_02080cc0*)entries, id, color);
        }
        id = (short)(id + 1);
    }

    func_020813ec(entries, rows);
}
