#if defined(jpn)
enum { Enum_ov017_021c46ec_14132 = 0x3524, Enum_ov017_021c46ec_257 = 0xfd };
#else
enum { Enum_ov017_021c46ec_14132 = 0x3734, Enum_ov017_021c46ec_257 = 0x101 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021c46ec {
    unsigned char pad0[4];
    unsigned short id;
    unsigned char pad6[0x10 - 0x6];
    int field10;
};

struct Struct_ov017_021c46ec_2 {
    unsigned char pad0[3];
    unsigned char active;
    unsigned char pad4[0x12 - 0x4];
    unsigned char field12;
    unsigned char unknown_13_[Enum_ov017_021c46ec_257 - 0x13];
    unsigned char unknown_101_;
};

struct Struct_ov017_021c46ec_3 {
    unsigned char pad0[Enum_ov017_021c46ec_14132];
    struct Struct_ov017_021c46ec_2* mode;
};

struct SearchStruct0202c1a4;
extern "C" int LinkSession_IsGuest(struct SearchStruct0202c1a4* search);
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct0202c1a4* search);
extern "C" void func_020103c8(GameState* battleStruct, int arg);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" signed char func_020546a8(void* obj);
extern "C" void func_ov017_0219dac4(struct Struct_ov017_021c46ec_3* ov, int idx, int id);
extern "C" void func_ov017_021c4fa0(int idx, int id);

// USA: func_ov017_021c46ec
extern "C" ARM void func_ov017_021c46ec(int idx, struct Struct_ov017_021c46ec* evt, GameState* battleStruct, struct Struct_ov017_021c46ec_3* ov, struct SearchStruct0202c1a4* search) {
    unsigned short id = evt->id;
    if (LinkSession_IsGuest(search) != 0 && idx == 0) {
        func_020103c8(battleStruct, evt->field10);
    }

    int active = 0;
    int i;
    struct Struct_ov017_021c46ec_2* mode = ov->mode;
    if (mode->active != 0) {
        active = 1;
    }

    GameObject* objs[4];
    GameObject* leader = battleStruct->GetPartyMemberByIndex(idx);
    if (!active || mode->unknown_101_ == 0) {
        int count = 0;
        objs[count++] = leader;
        for (i = 0; i < 4; i++) {
            GameObject* c = func_0200ff58(battleStruct, i);
            if (c != NULL && idx == func_020546a8(c)) {
                objs[count++] = c;
            }
        }

        if (!active || mode->unknown_101_ != 0 || mode->field12 == 0 || idx != 0) {
            for (i = 0; i < count; i++) {
                GameObject* c = objs[i];
                if (c != NULL) {
                    if (id != c->obj3D_.GetField06() || id == 0x170c) {
                        c->obj3D_.MakeHidden();
                    }
                }
            }
        }
    }

    func_ov017_0219dac4(ov, idx, id);
    if (LinkSession_IsHostOrSolo(search) != 0) {
        func_ov017_021c4fa0(idx, id);
    }
}
