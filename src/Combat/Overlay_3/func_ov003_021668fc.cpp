#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_021668fc_1152 = 0x2a8 };
#else
enum { Enum_ov003_021668fc_1152 = 0x480 };
#endif

extern "C" void* func_ov003_02160bf8(void* obj, int key);

struct Struct_020732cc;
extern "C" int func_0207c378(struct Struct_020732cc* obj, int value, int amount, int key);

struct Struct_02086a04;
extern "C" int func_02086a04(struct Struct_02086a04* c, int id);

extern unsigned short data_ov003_0217f494[9];
extern unsigned short data_ov003_0217f4a6[9];

// USA: func_ov003_021668fc
extern "C" ARM void func_ov003_021668fc(char* self) {
    if (*(short*)(self + Enum_ov003_021668fc_1152) < 0) return;

    GameState* bs = GameState::GetInstance();
    void* p2a04 = GameState_GetParty(bs);
    void* found = func_ov003_02160bf8(self, *(short*)(self + Enum_ov003_021668fc_1152));
    if (found == 0) return;

    char* base = (char*)found + 0x160;

    short arrB[9];
    short arrA[9];

    unsigned int var6 = 9;
    char* var7 = (char*)arrB;
    char* var8 = (char*)data_ov003_0217f494;
    do {
        *(unsigned short*)var7 = *(unsigned short*)var8;
        var7 += 2;
        var8 += 2;
    } while (--var6);

    unsigned int var9 = 9;
    char* var10 = (char*)arrA;
    char* var11 = (char*)data_ov003_0217f4a6;
    do {
        *(unsigned short*)var10 = *(unsigned short*)var11;
        var10 += 2;
        var11 += 2;
    } while (--var9);

    unsigned char idx = 0;
    short key;
    while ((key = arrB[idx]) >= 0) {
        short v = *(short*)(base + key * 2);
        if (v >= 0) {
            func_0207c378((struct Struct_020732cc*)((char*)p2a04 + 0x1d4), v, 1, arrA[idx]);
        }
        idx = (unsigned char)(idx + 1);
    }

    func_02086a04((struct Struct_02086a04*)p2a04, (signed char)*(short*)(self + Enum_ov003_021668fc_1152));
}
