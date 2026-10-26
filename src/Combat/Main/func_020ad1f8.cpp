#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void LinkSession_GetInstance();
extern "C" void func_0201bd04(void* obj, int a, int b);
extern "C" void func_0201bd3c(void* obj, int a, int b);
extern "C" int GameState_GetStoryChapter(char* obj);
struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4* obj, int a, int b, int c);

struct Struct_020ad1f8 {
#if defined(jpn)
    char pad[0xf4];
#else
    char pad[0xb4];
#endif
    unsigned short state;
};

struct Struct_020ad1f8_2 {
    unsigned short field0;
    char pad[0x2700 - 2];
    struct Struct_020ad1f8 sub;
};

// USA: func_020ad1f8
extern "C" ARM void func_020ad1f8(struct Struct_020ad1f8_2* obj) {
    GameState* battle = GameState::GetInstance();
    GetGameResources();
    LinkSession_GetInstance();
    battle->GetPartyMemberByIndex(0);
    GameObject* unk = battle->GetLeader();
    Vector3i pos = unk->obj3D_.position_;

    if (obj->field0 == 0x1198) {
        if (obj->sub.state == 1) {
            func_0201bd04(obj, 7, 0);
            func_0201bd04(obj, 8, 0);
            func_0201bd04(obj, 6, 0);
            func_0201bd3c(obj, 5, 0);
            return;
        }
        func_0201bd3c(obj, 7, 0);
        func_0201bd3c(obj, 8, 0);
        func_0201bd3c(obj, 6, 0);
        func_0201bd04(obj, 5, 0);
        if (pos.x < -0xc400 && pos.z < -0xf4cc) {
            func_020407b4((struct Fields020407b4*)unk, -0xc4cc, 0x42b8, -0xe385);
        }
        return;
    } else if (obj->field0 == 0x10cd) {
        if (obj->sub.state == 3) {
            func_0201bd04(obj, 2, 0);
            func_0201bd04(obj, 1, 0);
            func_0201bd3c(obj, 0xa, 0);
            return;
        }
        func_0201bd3c(obj, 2, 0);
        func_0201bd3c(obj, 1, 0);
        func_0201bd04(obj, 0xa, 0);
        if (pos.x > -0xa66 && pos.x < 0x999 && pos.z > 0x2999) {
            func_020407b4((struct Fields020407b4*)unk, 0, -0x5ccc, 0x2000);
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
        func_0201bd3c(obj, 0x17, 0);
        func_0201bd3c(obj, 1, 0);
        func_0201bd04(obj, 0x19, 0);
        if (pos.x > -0x2800 && pos.x < -0x1333 && pos.z > 0x2800) {
            func_020407b4((struct Fields020407b4*)unk, -0x1e66, -0x5ccc, 0x1ccc);
        }
    }
}
