#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int func_02053604(signed char* obj);
extern "C" void func_0205eabc(void* target, void* param, int arg);
extern "C" int GameObject_IsClimbingLadder(char* obj);
extern "C" int GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a2c8c(unsigned char* p);
extern "C" void* MessageSystem_GetInstance(void);

struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(struct Bytes02033b88* obj, int value);

extern "C" void func_ov017_021cc1f8(int id, const char* src, int len, int extra);

extern char g_sePlayer;

struct Struct_020531f0 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Struct_020531f0_2 {
    Object3D object;
    char unknown_ac_[0xb2 - 0xac];
    unsigned short fieldB2;
    char padB4[0xc1 - 0xb4];
    struct Struct_020531f0 unknown_c1_;
#if defined(jpn)
    char unknown_c2_[0x16c - 0xc2];
#else
    char unknown1_c2_[0x178 - 0xc2];
#endif
    signed char unknown_178_[4];
    signed char count;
    signed char cursor;
    signed char state;
    signed char unknown_17f_;
    int taskId;
    signed char delay;
    signed char unknown_185_;
    signed char unknown_186_;
    char unknown_187_[0x190 - 0x187];
    int unknown_190_;
    int unknown_194_;
};

// USA: func_020531f0
extern "C" ARM void func_020531f0(struct Struct_020531f0_2* obj) {
#if defined(jpn)
    enum { targetOffset = 0x18c, globalByteOffset = 0x17e1 };
#else
    enum { targetOffset = 0x198, globalByteOffset = 0x19b1 };
#endif
    BackgroundLoader* loader;
    GameState* battleStruct;
    signed char eventBuf[4];
    int target;
    int cid;

    loader = BackgroundLoader::GetInstance();
    if (obj->taskId > -1) {
        loader->RemoveTask(obj->taskId);
        obj->taskId = -1;
    }

    if (func_02053604((signed char*)obj) == 0x19) {
        func_0205eabc((void*)&g_sePlayer, (char*)obj + targetOffset, 0);
    }

    memset(obj->unknown_178_, 0, 4);
    obj->count = 0;
    obj->cursor = 0;
    obj->taskId = -1;
    obj->state = 0;
    obj->unknown_17f_ = 0;
    obj->delay = 0;

    if (obj->unknown_194_ > -1) {
        loader->RemoveTask(obj->unknown_194_);
        obj->unknown_194_ = -1;
    }

    obj->unknown_190_ = 0;
    obj->unknown_194_ = -1;
    obj->unknown_185_ = 0;
    obj->unknown_186_ = 0;

    if ((obj->object.unknown_0_ & 0x200) != 0) {
        if (GameObject_IsClimbingLadder((char*)obj) != 0) {
            return;
        }
    }

    obj->unknown_c1_.mode &= ~2;
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
                func_020a2c8c((unsigned char*)target);
            }
        }
    }

    func_ov017_021cc1f8(obj->object.actorIndex_, (const char*)eventBuf, 0, 1);
}
