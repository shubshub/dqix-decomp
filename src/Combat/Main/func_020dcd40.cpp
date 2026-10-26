#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02086e9c;
struct FindEntryContainer02086e50;
struct Struct_02086a04;
struct Struct_02087574;
struct Struct020865b0;
struct Struct_020dcd40 { unsigned char pad[0x30]; };

extern "C" unsigned short* Zone3D_GetInstance(void* p);
extern "C" int func_02086e9c(Struct_02086e9c* p);
extern "C" FindEntryContainer02086e50* func_02086e50(FindEntryContainer02086e50* p, int idx);
extern "C" void* GameState_FindPartyMemberData(void* state, int slot);
extern "C" char* GameState_FindFreePartyMemberData(char* state);
extern "C" void func_02086380(unsigned char* rec);
extern "C" void func_02082d6c(void* rec, void* entry);
extern "C" void func_ov017_0218f064(void* v, int slot, int flags, int a, int b);
extern "C" GameObject* func_0200ff58(GameState* state, int id);
extern "C" void func_020875c4(Struct_02087574* p, int idx, int slot);
extern "C" unsigned char GameState_GetProtagonistIndex(GameState* state);
extern "C" void func_020546a0(void* obj, int value);
extern "C" int func_020546a8(void* obj);
extern "C" void func_020546b4(void*, int);
extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" void __clear(void* p, int size);
extern "C" void Font_DecodeText(void* dst, void* src, int n);
extern "C" int PartyMemberRecord_GetVocation(Struct020865b0* entry);
extern "C" void PartyMember_SetVocation(unsigned char* p, int idx);
extern "C" void Party_ReformLine(void* v, int a, int b, int c, int d);
extern "C" void func_02086a04(Struct_02086a04* p, int idx);

// USA: func_020dcd40
extern "C" ARM int func_020dcd40() {
    int count = 0;
    GameResources* v14 = GetGameResources();
    GameState* battle = GameState::GetInstance();
    void* p10 = GameState_GetParty(battle);
    unsigned short* v0c = Zone3D_GetInstance(p10);
    while (true) {
        int idx = func_02086e9c((Struct_02086e9c*)p10);
        if (idx < 0) {
            break;
        }
        FindEntryContainer02086e50* entry = func_02086e50((FindEntryContainer02086e50*)p10, idx);
        if (entry == NULL) {
            break;
        }
        int slot = -1;
        for (int i = 3; i >= 0; i--) {
            if (battle->GetGameObjectByIndex(i) == NULL) {
                slot = i;
                break;
            }
        }
        if (slot < 0) {
            break;
        }
        void* rec = GameState_FindPartyMemberData(battle, slot);
        if (rec == NULL) {
            rec = GameState_FindFreePartyMemberData((char*)battle);
        }
        *(short*)((char*)rec + 0x568) = slot;
        func_02086380((unsigned char*)rec);
        func_02082d6c(rec, entry);
        func_ov017_0218f064(v14, slot, 0x1000, 1, 0);
        GameObject* c = func_0200ff58(battle, slot);
        if (c == NULL) {
            break;
        }
        void* p8 = GameState_GetParty(battle);
        func_020875c4((Struct_02087574*)p8, idx, (signed char)slot);
        c->obj3D_.SetField06(*v0c);
        battle->GetProtagonist();
        unsigned char v4 = GameState_GetProtagonistIndex(battle);
        func_020546a0(c, v4);
        int n = 0;
        for (int j = 0; j < 4; j++) {
            GameObject* other = func_0200ff58(battle, j);
            if (other != NULL && j != slot && v4 == func_020546a8(other)) {
                n++;
            }
        }
        func_020546b4(c, n);
        GameState_GetParty(battle);
        unsigned char* v7 = func_02053c6c((unsigned char*)c);
#if defined(jpn)
        strcpy((char*)c->baseStats_, (const char*)entry + 0x140);
#else
        Struct_020dcd40 local;
        __clear(&local, 0x30);
        Font_DecodeText((char*)entry + 0x140, &local, 1);
        strcpy((char*)c->baseStats_, (const char*)&local);
#endif
        int a = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
        unsigned char* p = (unsigned char*)entry + PartyMemberRecord_GetVocation((Struct020865b0*)entry);
        *(unsigned short*)(v7 + a * 2 + 0x16c) = p[2];
        PartyMember_SetVocation(v7, PartyMemberRecord_GetVocation((Struct020865b0*)entry));
        Party_ReformLine(v14, 1, 1, 1, 1);
        func_02086a04((Struct_02086a04*)p8, idx);
        count++;
    }
    return count;
}
