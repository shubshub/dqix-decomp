#include <globaldefs.h>
#include "GameState/GameState.h"

struct U16Field0x6_020375f8;
extern "C" void* func_020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char arg6, unsigned char arg7);

struct Struct_ov017_021d18d8 {
    unsigned char pad0[4];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char pad1[2];
    int extra;
};

// USA: func_ov017_021d18d8
extern "C" ARM void* func_ov017_021d18d8(int id, struct Struct_ov017_021d18d8* evt, GameState* battleStruct, int arg3) {
    GameObject* self = battleStruct->GetGameObjectByIndex(id);
    int flag = 1;
    GameObject* other = battleStruct->GetLeader();
    if (((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06() != ((Object3D*)((struct U16Field0x6_020375f8*)other))->GetField06()) flag = 0;
    typedef void* (*Type_ov017_021d18d8)(int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int);
    return ((Type_ov017_021d18d8)func_020a86b8)(id, flag, evt->b0, evt->b1, evt->b2, evt->b3, evt->unknown_8_, evt->unknown_9_, evt->extra);
}
