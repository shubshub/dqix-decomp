#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

#if defined(jpn)
#define data_ov000_02183198 data_ov000_02184244
#define data_ov000_021831d8 data_ov000_02184284
#define data_ov000_021830d8 data_ov000_02184184
#endif
extern "C" int func_ov000_02153e40(void* arg0, short* arg1, int arg2, int arg3);
extern "C" void func_ov000_02167b54(int* arg0, int arg1, int arg2, int arg3);
extern "C" int func_020493a4(unsigned char* arg0);
extern "C" void func_02049390(unsigned char* arg0, unsigned char arg1);
extern "C" void func_02049bd4(unsigned char* arg0, int* arg1);
extern "C" void func_02049c60(unsigned char* arg0, int* arg1);

struct Struct_ov000_021830d8 { int unknown_0_[3]; };
extern struct Struct_ov000_021830d8 data_ov000_021830d8;
extern int data_ov000_02183198[16];
extern int data_ov000_021831d8[16];

struct Struct_ov000_02167fb0 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    void* unknown_29c_;
};

// USA: func_ov000_02167fb0
extern "C" ARM void func_ov000_02167fb0(struct Struct_ov000_02167fb0* arg0, GameObject* arg1) {
    if (arg1 == NULL) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    short ids[0x10];
    int count = func_ov000_02153e40(battle->combatants, ids, 0x10, 0);
    int rotation[3];
    int* cells;
    int isParty = (target->obj3D_.actorIndex_ >= 0 && target->obj3D_.actorIndex_ <= 3) ? 1 : 0;
    if (isParty) {
        cells = data_ov000_02183198;
        StoreThreeFields02167b54(rotation, 0, 0x3244, 0);
    } else {
        int isGuest = (target->obj3D_.actorIndex_ >= 0xc0 && target->obj3D_.actorIndex_ <= 0xc7) ? 1 : 0;
        if (!isGuest) {
            return;
        }
        var4 = data_ov000_021831d8;
        func_ov000_02167b54(var3, 0, 0, 0);
    }
    for (int var7 = 0; var7 < 0x10; var7++) {
        int var8 = var4[var7];
        int var9 = 0;
        for (int var10 = 0; var10 < var2; var10++) {
            GameObject* var11 = var0->GetCombatantByIndex(var1[var10]);
            if (var11 != NULL && var8 == func_020493a4((unsigned char*)var11)) {
                var9 = 1;
                break;
            }
        }
        if (!var9) {
            struct Struct_02048cf0 var12 = func_ov000_0216f74c(&var8);
            func_02049390((unsigned char*)arg1, var8 & 0xff);
            struct Struct_ov000_021830d8 var13 = data_ov000_021830d8;
            var13.unknown_0_[0] = var12.unknown_0_;
            var13.unknown_0_[2] = var12.unknown_4_;
            func_02049bd4((unsigned char*)arg1, var13.unknown_0_);
            func_02049c60((unsigned char*)arg1, var3);
            return;
        }
    }
}
