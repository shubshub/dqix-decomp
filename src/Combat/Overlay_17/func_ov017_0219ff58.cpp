#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "Resource/GameResources.h"

struct Struct_02048260_2;
struct Struct_02010604_3;
struct Bytes02033b88;
struct TailList020469b4;
struct TailNode020469b4;

struct Struct_ov017_0219ff58 {
    short mapId;
    char field2;
    char pad3[4];
    char unknown_7_;
    char pad8[8];
    int pos[3];
    short angle;
    char pad1e[0x70 - 0x1e];
};

struct Struct_ov017_0219ff58_2 {
    unsigned int flags;
};

struct Struct_ov017_0219ff58_3 {
    unsigned char pad0[0x130];
    Struct_ov017_0219ff58_2* status;
#if defined(jpn)
    unsigned char unknown_134_[0x180 - 0x134];
#else
    unsigned char unknown1_134_[0x18c - 0x134];
#endif
    unsigned int unknown_18c_;
};

extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_02011b3c(void* obj, unsigned char mask);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_02048150(void* combatant, int a, int b);
extern "C" int func_02048260(struct Struct_02048260_2* c);
extern "C" int func_020482bc(struct Struct_02010604_3* c);
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
extern "C" void GameObject_SetFollowedMember(unsigned char*, int);
extern "C" void GameObject_SetLinePosition(unsigned char* obj, int value);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" void func_02070378(char* obj);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int flag);
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0219ff58
extern "C" ARM int func_ov017_0219ff58(unsigned char* ov, int flagA, int arg2, int arg3) {
#if defined(jpn)
 enum { regionalNode=0x4fc, regionalList=0x4ec };
#else
 enum { regionalNode=0x70c, regionalList=0x6fc };
#endif
    GameState* battle = GameState::GetInstance();
    if (func_02011b50(battle, 1) != 0) {
        if (arg3 != 0) {
            GetGameResources();
            signed char leader = GameState_GetProtagonistIndex(battle);
            Struct_ov017_0219ff58_3* c = (Struct_ov017_0219ff58_3*)battle->GetPartyMemberByIndex(leader);
            if (c != NULL) {
                func_02048150(c, 0, 1);
                func_02048260((struct Struct_02048260_2*)c);
                func_020482bc((struct Struct_02010604_3*)c);
                c->unknown_18c_ &= ~1;
                GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                if (c->status->flags & 1) {
                    GameObject_SetFollowedMember((unsigned char*)c, -1);
                    GameObject_SetLinePosition((unsigned char*)c, 0);
                    GameObject_EnableControl(c);
                }
                func_ov017_021cedf4(leader, 1, 0);
                func_ov017_021c9e00(leader, 0, 0, 1);
            }
            for (signed char i = 0; i < 4; i++) {
                Struct_ov017_0219ff58_3* m = (Struct_ov017_0219ff58_3*)func_0200ff58(battle, i);
                if (m != NULL && leader == func_020546a8(m)) {
                    func_02048150(m, 0, 1);
                    func_02048260((struct Struct_02048260_2*)m);
                    func_020482bc((struct Struct_02010604_3*)m);
                    m->unknown_18c_ &= ~1;
                    GameObject_ForceMotionState((struct Bytes02033b88*)m, 0);
                    func_ov017_021cedf4(i, 1, 0);
                    func_ov017_021c9e00(i, 0, 0, 1);
                }
            }
        }

        if (flagA != 0) func_02011b3c(battle, 2);
        if (arg2 != 0) func_02011b3c(battle, 4);
        if (arg3 != 0) func_02011b3c(battle, 8);

        Struct_ov017_0219ff58 warp;
        func_02070378((char*)&warp);
        warp.mapId = 0x10d0;
        warp.field2 = arg3 == 0;
        warp.unknown_7_ = 1;
        warp.pos[0] = -0xf5;
        warp.pos[1] = 0x1199;
        warp.pos[2] = -0x30a3;
        warp.angle = 0x323d;
        func_0200fba4(battle, &warp);

        if (arg2 != 0) {
            FieldTask_InitEnterZone(*(unsigned char**)(ov + 0x3000 + regionalNode), 0);
            func_020469b4(*(struct TailList020469b4**)(ov + 0x3000 + regionalList),
                             *(struct TailNode020469b4**)(ov + 0x3000 + regionalNode));
        }
        return 1;
    }
    return 0;
}
