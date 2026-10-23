#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02086e9c;
struct Struct_02086e50;
struct Struct_02086a04;
struct Struct_02087574;
struct Struct_0201099c_16;
struct Struct_020dcd40 { unsigned char unknown_0_[0x30]; };

extern "C" unsigned short* func_02012fe4(void* p);
int GetFirstFlaggedValue02086e9c(FlaggedEntryContainer02086e9c* p);
FindEntryContainer02086e50* FindEntryBySignedId02086e50(FindEntryContainer02086e50* p, int idx);
void* FindRecordByShortField020108f0(void* state, int slot);
char* FindSlotWithNegShort02010954(char* state);
void ResetShortFields02086380(unsigned char* rec);
extern "C" void func_02082d6c(void* rec, void* entry);
extern "C" void func_ov017_0218f064(void* v, int slot, int flags, int a, int b);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* state, int id);
void ArchiveEntryToCombatantField0x150_020875c4(EntryTable02087574* p, int idx, int slot);
unsigned char GetField0x3acValue_020100a8(GameState* state);
void SetField0x2d0_020546a0(void* obj, int value);
int GetSignedByte0x2d0_020546a8(void* obj);
void SetField0x2d1_020546b4(void*, int);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void __clear(void* p, int size);
extern "C" void func_02042764(void* dst, void* src, int n);
int GetFieldAt0x50(Struct020865b0* entry);
void PartyMember_SetVocation(unsigned char* p, int idx);
extern "C" void func_ov017_02191108(void* v, int a, int b, int c, int d);
void RemoveOrShiftMarkedEntry02086a04(FindEntryContainer02086a04* p, int idx);

// USA: func_020dcd40
extern "C" ARM int func_020dcd40() {
    int var0 = 0;
    GameResources* var1 = GetGameResources();
    GameState* var2 = GameState::GetInstance();
    void* var3 = func_02010828(var2);
    unsigned short* var4 = func_02012fe4(var3);
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
        void* var9 = func_020108f0(var2, var7);
        if (var9 == NULL) {
            var9 = func_02010954((char*)var2);
        }
        *(short*)((char*)var9 + 0x568) = var7;
        func_02086380((unsigned char*)var9);
        func_02082d6c(var9, var6);
        func_ov017_0218f064(var1, var7, 0x1000, 1, 0);
        GameObject* var10 = func_0200ff58(var2, var7);
        if (var10 == NULL) {
            break;
        }
        void* var11 = func_02010828(var2);
        func_020875c4((Struct_02087574*)var11, var5, (signed char)var7);
        var10->obj3D_.SetField06(*var4);
        var2->GetProtagonist();
        unsigned char var12 = func_020100a8(var2);
        func_020546a0(var10, var12);
        int var13 = 0;
        for (int var14 = 0; var14 < 4; var14++) {
            GameObject* var15 = func_0200ff58(var2, var14);
            if (var15 != NULL && var14 != var7 && var12 == func_020546a8(var15)) {
                var13++;
            }
        }
        func_020546b4(var10, var13);
        func_02010828(var2);
        unsigned char* var16 = func_02053c6c((unsigned char*)var10);
#if defined(jpn)
        strcpy((char*)var10->baseStats_, (const char*)var6 + 0x140);
#else
        Struct_020dcd40 var17;
        __clear(&var17, 0x30);
        func_02042764((char*)var6 + 0x140, &var17, 1);
        strcpy((char*)var10->baseStats_, (const char*)&var17);
#endif
        int a = GetFieldAt0x50((Struct020865b0*)entry);
        unsigned char* p = (unsigned char*)entry + GetFieldAt0x50((Struct020865b0*)entry);
        *(unsigned short*)(v7 + a * 2 + 0x16c) = p[2];
        PartyMember_SetVocation(v7, GetFieldAt0x50((Struct020865b0*)entry));
        func_ov017_02191108(v14, 1, 1, 1, 1);
        RemoveOrShiftMarkedEntry02086a04((FindEntryContainer02086a04*)p8, idx);
        count++;
    }
    return var0;
}
