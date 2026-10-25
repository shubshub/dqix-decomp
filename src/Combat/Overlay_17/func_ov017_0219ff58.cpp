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
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
void SetByte0x1c8_02039858(unsigned char*, int);
void SetByte0x1c9_0203986c(unsigned char* obj, int value);
void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
void InitStruct02070378(char* obj);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
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
                SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                if (c->status->flags & 1) {
                    SetByte0x1c8_02039858((unsigned char*)c, -1);
                    SetByte0x1c9_0203986c((unsigned char*)c, 0);
                    GameObject_EnableControl(c);
                }
                func_ov017_021cedf4(var1, 1, 0);
                func_ov017_021c9e00(var1, 0, 0, 1);
            }
            for (signed char var3 = 0; var3 < 4; var3++) {
                Struct_ov017_0219ff58_3* var4 = (Struct_ov017_0219ff58_3*)func_0200ff58(var0, var3);
                if (var4 != NULL && var1 == func_020546a8(var4)) {
                    func_02048150(var4, 0, 1);
                    func_02048260((struct Struct_02048260_2*)var4);
                    func_020482bc((struct Struct_02010604_3*)var4);
                    var4->unknown_18c_ &= ~1;
                    func_02033b88((struct Struct_02010604*)var4, 0);
                    func_ov017_021cedf4(var3, 1, 0);
                    func_ov017_021c9e00(var3, 0, 0, 1);
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

        if (arg2 != 0) {
            func_ov017_0219e310(*(unsigned char**)(arg0 + 0x3000 + Enum_ov017_0219ff58_1804), 0);
            func_020469b4(*(struct Struct_0201bdac_2**)(arg0 + 0x3000 + Enum_ov017_0219ff58_1788),
                             *(struct Struct_0201bdac**)(arg0 + 0x3000 + Enum_ov017_0219ff58_1804));
        }
        return 1;
    }
    return 0;
}
