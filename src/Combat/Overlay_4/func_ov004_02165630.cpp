#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct Struct_ov004_021549e4_2;
struct Struct_02011930;

struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" void* func_ov023_021f6880(void* arg0, int arg1);
extern "C" int func_ov023_021f6f10(void* arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern "C" void func_ov004_02165a1c(void* arg0);
extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c540(void* arg0);
extern "C" unsigned char func_02011930(void* arg0, struct Struct_02011930* arg1, void* arg2, void* arg3);
extern "C" int func_ov004_021634dc(void* arg0);
extern "C" unsigned char func_020119f8(char* arg0, void* arg1);
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* arg0);
extern "C" unsigned int func_ov023_021f9ba0(void* arg0);
extern "C" int func_020117f0(GameState* arg0);

extern char* data_ov004_02171010;

struct Struct_ov004_02165630 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
    char unknown_60_;
    unsigned char unknown_61_;
};

// USA: func_ov004_02165630
extern "C" ARM int func_ov004_02165630(void* arg0) {
#if defined(jpn)
 enum { Enum_ov004_02165630_2292 = 0x9f4, Enum_ov004_02165630_452 = 0x1e4, Enum_ov004_02165630_2301 = 0x9fd };
#else
 enum { Enum_ov004_02165630_2292 = 0x8f4, Enum_ov004_02165630_452 = 0x1c4, Enum_ov004_02165630_2301 = 0x8fd };
#endif
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02165630_2292) == 0) return 0;

    Struct_ov004_02165630* var0 = (Struct_ov004_02165630*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0xa);
    if (!var0 || func_ov023_021f6f10(var0) != 7) return 0;

    GameState* state = GameState::GetInstance();
    if (IsBrightnessTransitionActive((GameResources*)((int*)state->GetResources())) != 0) {
        node->active = 0;
        return 0;
    }
    var0->unknown_61_ = 1;

    Struct_ov004_02165630* var2 = (Struct_ov004_02165630*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0xa);
    if (!var2) return 0;
    if (func_ov023_021f6f10(var2) != 7) return 0;

    if (func_02011930(var1, NULL, NULL, NULL) != 0) {
        int var3 = func_ov004_021634dc(arg0);
        if (((TreasureMapMetadata*)(data_ov004_02171010 + var3 * 0x1c))->GetInitialByteUnknownBit()) {
            var0->unknown_61_ = 0;
            return 0;
        }
        func_ov011_021848a0(arg0, 0x68);
    } else if (func_020119f8((char*)var1, NULL) != 0) {
        unsigned int var4 = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)var2);
        if (*(unsigned char*)(data_ov004_02171010 + var4 * Enum_ov004_02165630_452 + 0xad4) != 3) {
            var0->unknown_61_ = 0;
        } else {
            func_ov004_02165a1c(arg0);
        }
    } else {
        void* var5 = func_0202ae18();
        func_02012fe4();
        if (func_0202c540(var5)) {
            func_ov011_021848a0(arg0, 0x6e);
        } else if (func_020117f0(var1)) {
            func_ov011_021848a0(arg0, 0x76);
        } else {
            short var6 = var2->unknown_5c_;
            unsigned int var7 = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)var2);
            unsigned short var8 = var6 * func_ov023_021f9ba0(var2) + var7;
            if (((TreasureMapMetadata*)(data_ov004_02171010 + var8 * 0x1c))->GetInitialByteUnknownBit()) {
                func_ov011_021848a0(arg0, 0x74);
            } else {
                *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02165630_2301) = 1;
                func_ov011_021848a0(arg0, 0x66);
            }
        }
    }
    return 0;
}
