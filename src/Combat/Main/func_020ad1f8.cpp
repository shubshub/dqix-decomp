#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void LinkSession_GetInstance();
extern "C" void func_0201bd04(void* obj, int a, int b);
extern "C" void func_0201bd3c(void* obj, int a, int b);
int GameState_GetStoryChapter(char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* obj, int a, int b, int c);

struct Struct_020ad1f8 {
#if defined(jpn)
    char unknown_0_[0xf4];
#else
    char unknown1_0_[0xb4];
#endif
    unsigned short unknown_b4_;
};

struct Struct_020ad1f8_2 {
    unsigned short unknown_0_;
    char unknown_2_[0x2700 - 2];
    struct Struct_020ad1f8 unknown_2700_;
};

// USA: func_020ad1f8
extern "C" ARM void func_020ad1f8(struct Struct_020ad1f8_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    LinkSession_GetInstance();
    battle->GetPartyMemberByIndex(0);
    GameObject* unk = battle->GetLeader();
    Vector3i pos = unk->obj3D_.position_;

    if (arg0->unknown_0_ == 0x1198) {
        if (arg0->unknown_2700_.unknown_b4_ == 1) {
            func_0201bd04(arg0, 7, 0);
            func_0201bd04(arg0, 8, 0);
            func_0201bd04(arg0, 6, 0);
            func_0201bd3c(arg0, 5, 0);
            return;
        }
        func_0201bd3c(arg0, 7, 0);
        func_0201bd3c(arg0, 8, 0);
        func_0201bd3c(arg0, 6, 0);
        func_0201bd04(arg0, 5, 0);
        if (var2.x < -0xc400 && var2.z < -0xf4cc) {
            func_020407b4((struct Struct_02040774_2*)var1, -0xc4cc, 0x42b8, -0xe385);
        }
        return;
    } else if (arg0->unknown_0_ == 0x10cd) {
        if (arg0->unknown_2700_.unknown_b4_ == 3) {
            func_0201bd04(arg0, 2, 0);
            func_0201bd04(arg0, 1, 0);
            func_0201bd3c(arg0, 0xa, 0);
            return;
        }
        func_0201bd3c(arg0, 2, 0);
        func_0201bd3c(arg0, 1, 0);
        func_0201bd04(arg0, 0xa, 0);
        if (var2.x > -0xa66 && var2.x < 0x999 && var2.z > 0x2999) {
            func_020407b4((struct Struct_02040774_2*)var1, 0, -0x5ccc, 0x2000);
        }
        return;
    } else if (obj->field0 == 0x1130) {
        int v = GameState_GetStoryChapter((char*)battle);
        if (obj->sub.state == 5 || v >= 0x13) {
            func_0201bd04(obj, 0x17, 0);
            func_0201bd04(obj, 1, 0);
            func_0201bd3c(obj, 0x19, 0);
            return;
        }
        func_0201bd3c(arg0, 0x17, 0);
        func_0201bd3c(arg0, 1, 0);
        func_0201bd04(arg0, 0x19, 0);
        if (var2.x > -0x2800 && var2.x < -0x1333 && var2.z > 0x2800) {
            func_020407b4((struct Struct_02040774_2*)var1, -0x1e66, -0x5ccc, 0x1ccc);
        }
    }
}
