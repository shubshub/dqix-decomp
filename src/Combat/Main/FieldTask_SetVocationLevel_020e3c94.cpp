#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct GameObject;
struct CombatState020e3c34;
extern "C" void func_020e3c34(CombatState020e3c34* p);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" int func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" int func_ov017_0218f5a4(char* self, int combatantId, int flag2, int arg3, int flag4);
extern char* data_020ee9cc[];
extern char data_020f2cbc;

struct CombatState020e3c34 {
    unsigned char header;
    unsigned char unknown_1_;
    unsigned char pad2[6];
    unsigned char byte8;
    signed char byte9;
    short unknown_a_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_[2];
    int unknown_1c_;
    int word_20;
    unsigned char unknown_24_;
};

// Main, originally func_020e3c94 (USA 0x020e3c94, EUR 0x020e3ca4, JPN 0x020e5834)
extern "C" ARM void FieldTask_SetVocationLevel(CombatState020e3c34* obj) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* combatant = func_0200ff1c(gs, obj->byte9);
    unsigned char* base = 0;

    if (combatant) {
        base = (unsigned char*)func_02053c6c((unsigned char*)combatant);
    }

    if (obj->unknown_1c_ == 0) {
        if (combatant == 0) {
            func_020e3c34(obj);
            obj->unknown_1_ = 1;
            return;
        }
        char buf[80];
        sprintf(buf, &data_020f2cbc, obj->unknown_c_);
        const char* names[2];
        names[0] = buf;
        names[1] = data_020ee9cc[1];
        for (int i = 0; i < 2; i++) {
            obj->unknown_14_[i] = loader->QueueLoadFile(names[i], 0);
        }
        obj->unknown_1c_ = 1;
    }

    if (obj->unknown_1c_ != 1) {
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (loader->GetTaskStatus(obj->unknown_14_[i]) == 0) {
            return;
        }
    }

    void* ptr0;
    void* var9;
    unsigned int var10;
    unsigned int len1;
    loader->GetLoadedFileByID(obj->unknown_14_[0], &ptr0, &var10);
    loader->GetLoadedFileByID(obj->unknown_14_[1], &var9, &len1);

    unsigned short v = 0;
    if (base) {
        if (obj->word_20 & 1) {
            v = *(unsigned short*)(base + 0x564);
        }
    }

    func_020897b4(obj->byte9, obj->unknown_a_, obj->unknown_c_, obj->byte8,
                 obj->unknown_24_, (int)ptr0, (int)var10, (int)var9, (int)len1);

    if (base) {
        if ((obj->word_20 & 1) && (obj->byte9 == GameState_GetProtagonistIndex(gs))) {
            *(unsigned short*)(base + 0x564) = v;
        }
        if (obj->word_20 & 2) {
            *(int*)((base + obj->unknown_c_ * 4) + 0x138) = obj->unknown_10_;
        }
        if (obj->word_20 & 4) {
            func_ov017_0218f5a4((char*)GetGameResources(), obj->byte9, 0, 0, 1);
        }
    }

    for (int i = 0; i < 2; i++) {
        loader->RemoveTask(obj->unknown_14_[i]);
    }

    func_020e3c34(obj);
    obj->unknown_1_ = 1;
}
