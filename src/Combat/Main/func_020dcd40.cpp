#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02086e9c;
struct Struct_02086e50;
struct Struct_02086a04;
struct Struct_02087574;
struct Struct_0201099c_16;
struct Struct_020dcd40 { unsigned char unknown_0_[0x30]; };

extern "C" unsigned short* Zone3D_GetInstance(void* p);
int GetFirstFlaggedValue02086e9c(FlaggedEntryContainer02086e9c* p);
FindEntryContainer02086e50* FindEntryBySignedId02086e50(FindEntryContainer02086e50* p, int idx);
void* GameState_FindPartyMemberData(void* state, int slot);
char* GameState_FindFreePartyMemberData(char* state);
void ResetShortFields02086380(unsigned char* rec);
extern "C" void func_02082d6c(void* rec, void* entry);
extern "C" void func_ov017_0218f064(void* v, int slot, int flags, int a, int b);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* state, int id);
void ArchiveEntryToCombatantField0x150_020875c4(EntryTable02087574* p, int idx, int slot);
unsigned char GameState_GetProtagonistIndex(GameState* state);
void SetField0x2d0_020546a0(void* obj, int value);
int GetSignedByte0x2d0_020546a8(void* obj);
void SetField0x2d1_020546b4(void*, int);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void __clear(void* p, int size);
extern "C" void Font_DecodeText(void* dst, void* src, int n);
int PartyMemberRecord_GetVocation(Struct020865b0* entry);
void PartyMember_SetVocation(unsigned char* p, int idx);
extern "C" void Party_ReformLine(void* v, int a, int b, int c, int d);
void RemoveOrShiftMarkedEntry02086a04(FindEntryContainer02086a04* p, int idx);

// USA: func_020dcd40
extern "C" ARM int func_020dcd40() {
    int count = 0;
    GameResources* v14 = GetGameResources();
    GameState* battle = GameState::GetInstance();
    void* p10 = GameState_GetParty(battle);
    unsigned short* v0c = Zone3D_GetInstance(p10);
    while (true) {
        int var5 = func_02086e9c((Struct_02086e9c*)var3);
        if (var5 < 0) {
            break;
        }
        Struct_02086e50* var6 = func_02086e50((Struct_02086e50*)var3, var5);
        if (var6 == NULL) {
            break;
        }
        int var7 = -1;
        for (int var8 = 3; var8 >= 0; var8--) {
            if (var2->GetGameObjectByIndex(var8) == NULL) {
                var7 = var8;
                break;
            }
        }
        if (var7 < 0) {
            break;
        }
        void* rec = GameState_FindPartyMemberData(battle, slot);
        if (rec == NULL) {
            rec = GameState_FindFreePartyMemberData((char*)battle);
        }
        *(short*)((char*)var9 + 0x568) = var7;
        func_02086380((unsigned char*)var9);
        func_02082d6c(var9, var6);
        func_ov017_0218f064(var1, var7, 0x1000, 1, 0);
        GameObject* var10 = func_0200ff58(var2, var7);
        if (var10 == NULL) {
            break;
        }
        void* p8 = GameState_GetParty(battle);
        ArchiveEntryToCombatantField0x150_020875c4((EntryTable02087574*)p8, idx, (signed char)slot);
        c->obj3D_.SetField06(*v0c);
        battle->GetProtagonist();
        unsigned char v4 = GameState_GetProtagonistIndex(battle);
        SetField0x2d0_020546a0(c, v4);
        int n = 0;
        for (int j = 0; j < 4; j++) {
            GameObject* other = GetCombatantWithFlag0x1000_0200ff58(battle, j);
            if (other != NULL && j != slot && v4 == GetSignedByte0x2d0_020546a8(other)) {
                n++;
            }
        }
        SetField0x2d1_020546b4(c, n);
        GameState_GetParty(battle);
        unsigned char* v7 = GetFieldAt0x150_02053c6c((unsigned char*)c);
#if defined(jpn)
        strcpy((char*)var10->baseStats_, (const char*)var6 + 0x140);
#else
        LocalBuf020dcd40 local;
        __clear(&local, 0x30);
        Font_DecodeText((char*)entry + 0x140, &local, 1);
        strcpy((char*)c->baseStats_, (const char*)&local);
#endif
        int a = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
        unsigned char* p = (unsigned char*)entry + PartyMemberRecord_GetVocation((Struct020865b0*)entry);
        *(unsigned short*)(v7 + a * 2 + 0x16c) = p[2];
        PartyMember_SetVocation(v7, PartyMemberRecord_GetVocation((Struct020865b0*)entry));
        Party_ReformLine(v14, 1, 1, 1, 1);
        RemoveOrShiftMarkedEntry02086a04((FindEntryContainer02086a04*)p8, idx);
        count++;
    }
    return var0;
}
