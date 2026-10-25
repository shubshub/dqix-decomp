#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_021668fc_1152 = 0x2a8 };
#else
enum { Enum_ov003_021668fc_1152 = 0x480 };
#endif

extern "C" void* func_ov003_02160bf8(void* arg0, int arg1);

struct Struct_020732cc;
extern "C" int func_0207c378(struct Struct_020732cc* arg0, int arg1, int arg2, int arg3);

struct Struct_02086a04;
extern "C" int func_02086a04(struct Struct_02086a04* arg0, int arg1);

extern unsigned short data_ov003_0217f494[9];
extern unsigned short data_ov003_0217f4a6[9];

// USA: func_ov003_021668fc
extern "C" ARM void func_ov003_021668fc(char* arg0) {
    if (*(short*)(arg0 + Enum_ov003_021668fc_1152) < 0) return;

    GameState* bs = GameState::GetInstance();
    void* p2a04 = GameState_GetParty(bs);
    void* found = func_ov003_02160bf8(self, *(short*)(self + kRegionValue480_2A8));
    if (found == 0) return;

    char* var3 = (char*)var2 + 0x160;

    short var4[9];
    short var5[9];

    unsigned int var6 = 9;
    char* var7 = (char*)var4;
    char* var8 = (char*)data_ov003_0217f494;
    do {
        *(unsigned short*)var7 = *(unsigned short*)var8;
        var7 += 2;
        var8 += 2;
    } while (--var6);

    unsigned int var9 = 9;
    char* var10 = (char*)var5;
    char* var11 = (char*)data_ov003_0217f4a6;
    do {
        *(unsigned short*)var10 = *(unsigned short*)var11;
        var10 += 2;
        var11 += 2;
    } while (--var9);

    unsigned char var12 = 0;
    short var13;
    while ((var13 = var4[var12]) >= 0) {
        short var14 = *(short*)(var3 + var13 * 2);
        if (var14 >= 0) {
            func_0207c378((struct Struct_020732cc*)((char*)var1 + 0x1d4), var14, 1, var5[var12]);
        }
        var12 = (unsigned char)(var12 + 1);
    }

    func_02086a04((struct Struct_02086a04*)var1, (signed char)*(short*)(arg0 + Enum_ov003_021668fc_1152));
}
