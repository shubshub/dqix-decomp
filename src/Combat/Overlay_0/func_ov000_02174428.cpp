#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;
struct Struct_ov000_02174428;
extern "C" void func_ov000_02171d90(struct Struct_ov000_02174428* obj, int key);
extern "C" void func_ov000_02170db0(void* obj);

// USA: func_ov000_02174428
extern "C" ARM void func_ov000_02174428(void* obj, int id, int arg2, int param3,
                                          signed char param4, short arg5, signed char arg6, unsigned short param7) {
    void* r4 = func_ov000_02161318(obj, id);
    if (!r4) return;
    GameState* bs = GameState::GetInstance();
    int f3ac = GameState_GetProtagonistIndex(bs);
    if (id != f3ac && arg2 == 0x64) {
        signed char off = *(signed char*)((char*)r4 + 0x18);
        signed char var4 = *(signed char*)((char*)r4 + off + 0x10);
        if (arg2 != var4) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x19, 0);
        }
    }
#if defined(jpn)
    enum { Enum_ov000_02174428_1086 = 0x47e };
#else
    enum { Enum_ov000_02174428_1086 = 0x43e };
#endif
    if (*((unsigned char*)r4 + Enum_ov000_02174428_1086)) return;
    int var5 = 0;
    int var6 = *(int*)((char*)r4 + 0x4c);
    if (var6 >= 0 && var6 <= 3) var5 = 1;
    if (!var5) return;
    signed char var7 = *(signed char*)((char*)r4 + 0x18);
    signed char* p10 = (signed char*)((char*)r4 + var7 + 0x10);
    *p10 = (signed char)arg2;
    *((unsigned char*)r4 + 0x1c) = (unsigned char)param3;
    *((unsigned char*)r4 + 0x1d) = (unsigned char)param4;
    *(short*)((char*)r4 + 0x2c) = arg5;
    *((unsigned char*)r4 + 0x2e) = (unsigned char)arg6;
    *(unsigned short*)((char*)r4 + 0x26) = param7;
    func_ov000_02171d90((struct Struct_ov000_02174428*)r4, arg5);
    func_ov000_02170db0(r4);
}
