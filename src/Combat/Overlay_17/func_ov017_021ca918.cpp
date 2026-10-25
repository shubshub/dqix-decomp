#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetField6b0_021b8470(void* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021ca918 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_[4];
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
};

// USA: func_ov017_021ca918
extern "C" ARM void func_ov017_021ca918(int arg0, struct Struct_ov017_021ca918* arg1, GameState* arg2, unsigned char* arg3) {
#if defined(jpn)
 enum {Enum_ov017_021ca918_1816=0x508};
#else
 enum {Enum_ov017_021ca918_1816=0x718};
#endif
    void* var0 = *(void**)(arg3 + 0x3000 + Enum_ov017_021ca918_1816);
    void* var1 = func_ov017_021b8470(var0);
    if (var1 == NULL) return;
    unsigned char* var2 = *(unsigned char**)((char*)var1 + 0x8000 + 0xe18);
    if (var2 == NULL) return;

    if (*(signed char*)(obj + 0x2a) == GameState_GetProtagonistIndex(battleStruct)) return;
    if (*(unsigned short*)(obj + 8) != src->field4) return;

    int var3 = arg1->unknown_6_ - 0xc0;
    if (var3 < 0) return;
    if (var3 >= 8) return;

    unsigned char* var4 = var2 + 0x158 + var3 * 0xa4;
    memcpy(var4 + 0x58, arg1->unknown_8_, 4);
    *(short*)(var4 + 0x28) = arg1->unknown_c_;
    *(short*)(var4 + 0x2a) = arg1->unknown_e_;
    *(short*)(var4 + 0x2c) = arg1->unknown_10_;
    *(short*)(var4 + 0x2e) = arg1->unknown_12_;
}
