#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02179f34_4096 = 0xf7c };
enum { Enum_ov003_02179f34_2204 = 0x818 };
#else
enum { Enum_ov003_02179f34_4096 = 0x1000 };
enum { Enum_ov003_02179f34_2204 = 0x89c };
#endif

void* GameState_GetParty(GameState* battleStruct);
short FindMappedMemberId02080468(void* obj, int id);
unsigned char GetTableByte0207ca94(int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960* s);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

// USA: func_ov003_02179f34
extern "C" ARM int func_ov003_02179f34(char* obj) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    void* ptr = GameState_GetParty(battle);
    short val = *(short*)(obj + kRegionValue1000_F7C + 0xc);
    void* field89c = *(void**)(obj + kRegionValue89C_818);

    if (var3 == 0x77) {
        short var5 = func_02080468(var4, 0x1d);
        short var6 = (short)(*(short*)(arg0 + Enum_ov003_02179f34_4096 + 0x12) - var5);
        unsigned char var7 = func_0207ca94(var6);
        var0 = func_0207c638((char*)var2 + 0x1d4, var7);
    } else {
        signed char var8 = *(signed char*)(arg0 + Enum_ov003_02179f34_4096 + 0x43);
        int var9 = var0;
        if (var8 >= 0) {
            var9 = (var8 <= 3) ? 1 : 0;
        }
        if (var9) {
            GameObject* var10 = var1->GetPartyMemberByIndex(var8);
            if (var10 != 0) {
                int var11 = func_02053c6c((unsigned char*)var10);
                var0 = (short)func_02083960((struct Struct_0207d300*)var11);
            }
        } else {
            var0 = func_020a0b8c((struct Struct_020a0b8c*)var2);
        }
    }
    return var0;
}
