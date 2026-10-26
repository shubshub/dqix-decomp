#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202b2f0;
struct Struct_0207d798;

struct Struct_0207d7f4 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    signed char unknown_4_;
    unsigned char unknown_5_;
    char unknown_6_[2];
    signed char unknown_8_[4];
};

void* FindEntryByFlagByte_0207d9f4(unsigned char* arr, int offset);
void InitStruct0207d7c0(struct Init0207d7c0* o);
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
int CheckEntryBytes0207d978(struct Entry0207d9bc* arr, unsigned short key);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);

// USA: func_0207d7f4
extern "C" ARM int func_0207d7f4(struct Struct_0207d7f4* arg0, unsigned short arg1, int arg2, int arg3,
                      signed char arg4, unsigned short arg5, unsigned char arg6) {
    signed char var0;
    GameState* var1 = GameState::GetInstance();
    struct Struct_0207d7f4* var2;
    struct Struct_0202b2f0* var3;
    GameObject* var4;
    int var5;

    if (arg3 != 0) {
        var2 = (struct Struct_0207d7f4*)func_0207d9f4((unsigned char*)arg0, arg2);
        if (var2 != NULL && var2->unknown_0_ != arg1) {
            func_0207d7c0((struct Struct_0207d798*)var2);
        }
    }
    entry = FindEntryByHalfword(entries, id);
    if (entry == NULL) {
        entry = FindEntryByHalfword(entries, 0);
        if (entry == NULL) return 0;
        InitStruct0207d7c0((struct Init0207d7c0*)entry);
        entry->id = id;
        search = (struct SearchStruct*)LinkSession_GetInstance();
        for (i = 0; i < 4; i++) {
            if (!LinkSession_IsSlotMember(search, i) || game->GetPartyMemberByIndex(i) == NULL)
                entry->bytes[i] = 0;
        }
    } else if (var1->GetGameObjectByIndex(arg2) == NULL) {
        var2->unknown_8_[arg2] = 0;
        return func_0207d978(arg0, arg1);
    }
    var0 = (signed char)arg3;
    var2->unknown_8_[arg2] = var0;
    for (var5 = 0; var5 < 4; var5++) {
        var4 = func_0200ff58(var1, var5);
        if (var4 != NULL && func_020546a8(var4) == arg2)
            var2->unknown_8_[var5] = var0;
    }
    if (arg3 != 0 && var2->unknown_4_ < 0 && arg4 >= 0) {
        var2->unknown_4_ = arg4;
        var2->unknown_2_ = arg5;
        var2->unknown_5_ = arg6;
    }
    return func_0207d978(arg0, arg1);
}
