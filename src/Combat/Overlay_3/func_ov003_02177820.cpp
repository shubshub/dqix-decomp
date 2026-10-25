#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02177820_4144 = 0xfac };
enum { Enum_ov003_02177820_4124 = 0xf98 };
enum { Enum_ov003_02177820_2204 = 0x818 };
#else
enum { Enum_ov003_02177820_4144 = 0x1030 };
enum { Enum_ov003_02177820_4124 = 0x101c };
enum { Enum_ov003_02177820_2204 = 0x89c };
#endif

#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void ClearSublistEntriesFlag1_02080bac(void* obj, int id);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_020813ec(void* obj, int key);
void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov003_02177820
#pragma opt_common_subs off
extern "C" ARM void func_ov003_02177820(char* self) {
    struct Obj2081* elemObj = *(struct Obj2081**)(self + kRegion89c);
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);

    int var2 = *(int*)(arg0 + Enum_ov003_02177820_4144);
    int var3 = 0x11, var4 = 0x79;
    switch (var2) {
    case 2: var3 = 0x12; var4 = 0x7c; break;
    case 3: var3 = 0x13; var4 = 0x80; break;
    case 4: var3 = 0x14; var4 = 0x85; break;
    }

    func_02080c20(var0, var3);
    func_02080c68(var0, var3, 0);
    func_02080bac(var0, var3);

    int var5;
    unsigned char var6;
    for (var6 = 0; var6 < *(int*)(arg0 + Enum_ov003_02177820_4144); var6++) {
        var5 = 0;
        GameObject* var7 = var1->GetPartyMemberByIndex(*(int*)(arg0 + Enum_ov003_02177820_4124 + var6 * 4));
        if (var7 != 0) {
            var5 = *(int*)((char*)var7 + 0x134);
        }
        func_02080f8c((struct Struct_02080f8c*)var0, var4, var5);

        int var8 = func_020dcc98((signed char)*(int*)(arg0 + Enum_ov003_02177820_4124 + var6 * 4));
        func_02080cc0((struct Struct_02080cc0*)var0, var4, var8);

        var4 = (short)(var4 + 1);
    }

    func_020813ec(var0, var3);
}
