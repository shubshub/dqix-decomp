#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "Resource/GameResources.h"

struct Struct_02048260_2;
struct Struct_02010604_3;
struct Struct_02010604;
struct Struct_0201bdac_2;
struct Struct_0201bdac;

struct Struct_ov017_0219ff58 {
    short unknown_0_;
    char unknown_2_;
    char unknown_3_[4];
    char unknown_7_;
    char unknown_8_[8];
    int unknown_10_[3];
    short unknown_1c_;
    char unknown_1e_[0x70 - 0x1e];
};

struct Struct_ov017_0219ff58_2 {
    unsigned int unknown_0_;
};

struct Struct_ov017_0219ff58_3 {
    unsigned char unknown_0_[0x130];
    Struct_ov017_0219ff58_2* unknown_130_;
#if defined(jpn)
    unsigned char unknown_134_[0x180 - 0x134];
#else
    unsigned char unknown1_134_[0x18c - 0x134];
#endif
    unsigned int unknown_18c_;
};

int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void SetBitsInField0x63dc_02011b3c(void* obj, unsigned char mask);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_02048150(void* combatant, int a, int b);
int RestoreMaxHpToFull(struct Combatant02048260* c);
int RestoreMaxMpToFull(struct Combatant020482bc* c);
int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
void GameObject_SetFollowedMember(unsigned char*, int);
void GameObject_SetLinePosition(unsigned char* obj, int value);
void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
void InitStruct02070378(char* obj);
void FieldTask_InitEnterZone(unsigned char* obj, int flag);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0219ff58
extern "C" ARM int func_ov017_0219ff58(unsigned char* arg0, int arg1, int arg2, int arg3) {
#if defined(jpn)
 enum { Enum_ov017_0219ff58_1804=0x4fc, Enum_ov017_0219ff58_1788=0x4ec };
#else
 enum { Enum_ov017_0219ff58_1804=0x70c, Enum_ov017_0219ff58_1788=0x6fc };
#endif
    GameState* var0 = GameState::GetInstance();
    if (func_02011b50(var0, 1) != 0) {
        if (arg3 != 0) {
            GetGameResources();
            signed char leader = GameState_GetProtagonistIndex(battle);
            Combatant0219ff58* c = (Combatant0219ff58*)battle->GetPartyMemberByIndex(leader);
            if (c != NULL) {
                func_02048150(c, 0, 1);
                RestoreMaxHpToFull((struct Combatant02048260*)c);
                RestoreMaxMpToFull((struct Combatant020482bc*)c);
                c->flags18c &= ~1;
                GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                if (c->status->flags & 1) {
                    GameObject_SetFollowedMember((unsigned char*)c, -1);
                    GameObject_SetLinePosition((unsigned char*)c, 0);
                    GameObject_EnableControl(c);
                }
                func_ov017_021cedf4(var1, 1, 0);
                func_ov017_021c9e00(var1, 0, 0, 1);
            }
            for (signed char i = 0; i < 4; i++) {
                Combatant0219ff58* m = (Combatant0219ff58*)GetCombatantWithFlag0x1000_0200ff58(battle, i);
                if (m != NULL && leader == GetSignedByte0x2d0_020546a8(m)) {
                    func_02048150(m, 0, 1);
                    RestoreMaxHpToFull((struct Combatant02048260*)m);
                    RestoreMaxMpToFull((struct Combatant020482bc*)m);
                    m->flags18c &= ~1;
                    GameObject_ForceMotionState((struct Bytes02033b88*)m, 0);
                    func_ov017_021cedf4(i, 1, 0);
                    func_ov017_021c9e00(i, 0, 0, 1);
                }
            }
        }

        if (arg1 != 0) func_02011b3c(var0, 2);
        if (arg2 != 0) func_02011b3c(var0, 4);
        if (arg3 != 0) func_02011b3c(var0, 8);

        Struct_ov017_0219ff58 var5;
        func_02070378((char*)&var5);
        var5.unknown_0_ = 0x10d0;
        var5.unknown_2_ = arg3 == 0;
        var5.unknown_7_ = 1;
        var5.unknown_10_[0] = -0xf5;
        var5.unknown_10_[1] = 0x1199;
        var5.unknown_10_[2] = -0x30a3;
        var5.unknown_1c_ = 0x323d;
        func_0200fba4(var0, &var5);

        if (flagB != 0) {
            FieldTask_InitEnterZone(*(unsigned char**)(ov + 0x3000 + regionalNode), 0);
            AppendNodeToTail(*(struct TailList020469b4**)(ov + 0x3000 + regionalList),
                             *(struct TailNode020469b4**)(ov + 0x3000 + regionalNode));
        }
        return 1;
    }
    return 0;
}
