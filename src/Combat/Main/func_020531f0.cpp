#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

int GetIndexedEntryField0x178_02053604(signed char* obj);
void ForwardToTargetOrDefault0205eabc(void* target, void* param, int arg);
int GameObject_IsClimbingLadder(char* obj);
int GameState_GetLeaderIndex(GameState* battleStruct);
int GameState_GetFollowCamera(char* obj);
void SetByte0x2c4To2IfByte0x2c5Set_020a2c8c(unsigned char* p);
void* MessageSystem_GetInstance(void);

struct Bytes02033b88;
void GameObject_ForceMotionState(struct Bytes02033b88* obj, int value);

extern "C" void func_ov017_021cc1f8(int arg0, const char* arg1, int arg2, int arg3);

extern char g_sePlayer;

struct Struct_020531f0 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

struct Struct_020531f0_2 {
    Object3D unknown_0_;
    char unknown_ac_[0xb2 - 0xac];
    unsigned short unknown_b2_;
    char unknown_b4_[0xc1 - 0xb4];
    struct Struct_020531f0 unknown_c1_;
#if defined(jpn)
    char unknown_c2_[0x16c - 0xc2];
#else
    char unknown1_c2_[0x178 - 0xc2];
#endif
    signed char unknown_178_[4];
    signed char unknown_17c_;
    signed char unknown_17d_;
    signed char unknown_17e_;
    signed char unknown_17f_;
    int unknown_180_;
    signed char unknown_184_;
    signed char unknown_185_;
    signed char unknown_186_;
    char unknown_187_[0x190 - 0x187];
    int unknown_190_;
    int unknown_194_;
};

// USA: func_020531f0
extern "C" ARM void func_020531f0(struct Struct_020531f0_2* arg0) {
#if defined(jpn)
    enum { Enum_020531f0_408 = 0x18c, Enum_020531f0_6577 = 0x17e1 };
#else
    enum { Enum_020531f0_408 = 0x198, Enum_020531f0_6577 = 0x19b1 };
#endif
    BackgroundLoader* var0;
    GameState* var1;
    signed char var2[4];
    int var3;
    int var4;

    var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_180_ > -1) {
        var0->RemoveTask(arg0->unknown_180_);
        arg0->unknown_180_ = -1;
    }

    if (GetIndexedEntryField0x178_02053604((signed char*)obj) == 0x19) {
        ForwardToTargetOrDefault0205eabc((void*)&g_sePlayer, (char*)obj + targetOffset, 0);
    }

    memset(arg0->unknown_178_, 0, 4);
    arg0->unknown_17c_ = 0;
    arg0->unknown_17d_ = 0;
    arg0->unknown_180_ = -1;
    arg0->unknown_17e_ = 0;
    arg0->unknown_17f_ = 0;
    arg0->unknown_184_ = 0;

    if (arg0->unknown_194_ > -1) {
        var0->RemoveTask(arg0->unknown_194_);
        arg0->unknown_194_ = -1;
    }

    arg0->unknown_190_ = 0;
    arg0->unknown_194_ = -1;
    arg0->unknown_185_ = 0;
    arg0->unknown_186_ = 0;

    if ((obj->object.unknown_0_ & 0x200) != 0) {
        if (GameObject_IsClimbingLadder((char*)obj) != 0) {
            return;
        }
    }

    obj->entryFlags.mode &= ~2;
    obj->object.RemoveAnimationPackageByID(2);
    obj->fieldB2 = 0;
    GameObject_ForceMotionState((struct Bytes02033b88*)obj, 0);

    battleStruct = GameState::GetInstance();
    cid = obj->object.actorIndex_;
    int activeId = GameState_GetLeaderIndex(battleStruct);
    if (activeId == cid) {
        target = GameState_GetFollowCamera((char*)battleStruct);
        if (target != 0) {
            if (g_keyManager.TestKeysHeld(2) == 0
                || ((unsigned char*)MessageSystem_GetInstance())[globalByteOffset] != 0) {
                SetByte0x2c4To2IfByte0x2c5Set_020a2c8c((unsigned char*)target);
            }
        }
    }

    func_ov017_021cc1f8(obj->object.actorIndex_, (const char*)eventBuf, 0, 1);
}
