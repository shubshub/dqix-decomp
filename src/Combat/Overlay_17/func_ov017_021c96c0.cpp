#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov017_021c96c0_3 {
    unsigned char pad0[0x44];
    Vector3i pos;
    unsigned char unknown_50_[0x130 - 0x50];
    int state;
    unsigned char unknown_134_[0x154 - 0x134];
    int unknown_154_;
    unsigned char unknown_158_[0x166 - 0x158];
    short unknown_166_;
    unsigned char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
};

struct Struct_ov017_021c96c0 {
    int field_0;
    int unknown_4_;
    Struct_ov017_021c96c0_3* actor;
};

struct Player021c96c0 {
    unsigned short id;
#if defined(jpn)
    unsigned char pad2[0x444 - 2];
#else
    unsigned char pad2[0x424 - 2];
#endif
    int unknown_424_;
};

struct Struct_ov017_021c96c0_4 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short id;
    unsigned char kind : 6;
    unsigned char unknown_6_6_ : 1;
    unsigned char flag7 : 1;
    unsigned char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

struct BitFlag02033f44;

extern "C" Player021c96c0* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d446c(void* key, Struct_ov017_021c96c0* out, int kind);
extern "C" int LinkSession_IsGuest(void* search);
extern "C" int Zone3D_GetGroundHeight(Player021c96c0* player, Vector3i* v);
extern "C" int* GameObject_GetWallHit(BitFlag02033f44* obj);
struct Obj02033834;
extern "C" void GameObject_SetFacing(Obj02033834* obj, int arg);
extern "C" void func_02076ccc(void*, int);

// USA: func_ov017_021c96c0
extern "C" ARM void func_ov017_021c96c0(int unused0, Struct_ov017_021c96c0_4* evt, int arg2, int arg3, void* search) {
    Player021c96c0* player = Zone3D_GetInstance();
    Struct_ov017_021c96c0 found;
    if (!func_ov017_021d446c(&evt->id, &found, evt->kind)) return;

    if (evt->kind == 10) {
        found.actor->unknown_166_ = evt->unknown_7_4_;
    }

    if (evt->kind == 1) {
        Vector3i v;
        v.x = evt->fieldC;
        v.y = evt->fieldA << 4;
        v.z = evt->field10;
        short angle = evt->field8;
        int var4 = evt->unknown_6_6_ ? 1 : 0;
        int var5 = evt->flag7 ? 1 : 0;

        if (!(evt->id == player->id && found.actor->state == 1) && !(v.x == 0 && v.y == 0 && v.z == 0)) {
            if (LinkSession_IsGuest(search)) {
                if (GameObject_GetWallHit((BitFlag02033f44*)found.actor) == 0) {
                    found.actor->pos = v;
                } else {
                    const Vector3i& src = v;
                    found.actor->pos = src;
                }
            } else {
                found.actor->pos = v;
            }
        }

        if (evt->id == player->id && player->unknown_424_ == 0 && found.actor->state != 1 &&
            !(v.x == 0 && v.y == 0 && v.z == 0)) {
            if (GameObject_GetWallHit((BitFlag02033f44*)found.actor)) {
                v = found.actor->pos;
            }
            v.y = Zone3D_GetGroundHeight(player, &v);
            found.actor->pos = v;
        }

        if (angle != 0) {
            GameObject_SetFacing((Obj02033834*)found.actor, angle);
        }
        if (var4) {
            found.actor->unknown_17b_ = 1;
        }
        if (var5) {
            found.actor->unknown_17c_ = 1;
        }
        if (found.actor->state == 4 || found.actor->state == 5 || found.actor->state == 6) {
            found.actor->unknown_154_ = 0;
        }
    }

    func_02076ccc(found.actor, evt->kind);
}
