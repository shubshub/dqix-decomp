#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202b2f0;

extern "C" SearchStruct* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct* search, int index);
int GameState_GetProtagonistIndex(GameState* battleStruct);
unsigned char* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
void StoreByteList02026348(char* obj, unsigned char* src, int count);
void CopyInRegion0x571d_020114c0(char* obj, int len, void* src);
void WriteBlockWithSize02011468(void* obj, int size, void* src);

// USA: func_ov017_02191234
extern "C" ARM void func_ov017_02191234(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_02191234_722=0x2c6, Enum_ov017_02191234_14032=0x34c0};
#else
 enum {Enum_ov017_02191234_722=0x2d2, Enum_ov017_02191234_14032=0x36d0};
#endif
    GameState* var0 = GameState::GetInstance();
    Struct_0202b2f0* var1 = func_0202ae18();
    unsigned char var2 = 0;
    unsigned char var3 = 0;
    unsigned char var4[4];
    unsigned char var5[4];

    if (CheckField0NonZero_0202b7d8((int*)search)) {
        for (int group = 0; group < 4; group++) {
            if (!TestBitBySignedByteIndex_0202c1c0(search, group)) continue;
            list[count++] = group;
            int isCurrent = 0;
            if (group == GameState_GetProtagonistIndex(battle)) {
                subList[subCount++] = group;
                isCurrent = 1;
            }
            for (int var8 = 1; var8 < 4; var8++) {
                unsigned char* var9 = func_0200ff58(var0, var8);
                if (var9 == 0) continue;
                if (var6 != func_020546a8(var9)) continue;
                var4[var9[Enum_ov017_02191234_722]] = var8;
                var2++;
                if (var7) {
                    var5[var9[Enum_ov017_02191234_722]] = var8;
                    var3++;
                }
            }
        }
    } else {
        var4[var2++] = 0;
        var5[var3++] = 0;
        for (int var10 = 1; var10 < 4; var10++) {
            unsigned char* var11 = func_0200ff58(var0, var10);
            if (var11 != 0) {
                var4[var11[Enum_ov017_02191234_722]] = var10;
                var2++;
                var5[var11[Enum_ov017_02191234_722]] = var10;
                var3++;
            }
        }
    }
    func_02026348(*(char**)(arg0 + Enum_ov017_02191234_14032), var4, var2);
    func_020114c0((char*)var0, var2, var4);
    func_02011468(var0, var3, var5);
}
