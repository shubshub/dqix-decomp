#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
enum { Enum_ov004_02164c18_6388 = 0x19f4 };
#else
enum { Enum_ov004_02164c18_6388 = 0x18f4 };
#endif

struct Struct_ov004_02164c18 {
    TreasureMapMetadata unknown_0_[99];
    char unknown_ad4_[Enum_ov004_02164c18_6388 - 99 * 0x1c];
    unsigned char unknown_18f4_;
    char unknown_18f5_;
    short unknown_18f6_;
    short unknown_18f8_;
};

struct Struct_ov004_02164c18_2 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

extern "C" void Zone3D_GetInstance(GameState* state);
int GetScaledStat_021634dc_021634dc(void* a);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" struct Node02164c18* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f9ba8(void* obj, unsigned short v);
extern "C" void func_ov004_021636b0(void* a1, void* a2);
extern "C" int func_ov004_02163530(void* a);
extern "C" void func_ov004_02164084(void* a);

extern struct Struct_ov004_02164c18* data_ov004_02171010;
extern char data_ov004_02170598[];

// USA: func_ov004_02164c18
extern "C" ARM int func_ov004_02164c18(void* arg0) {
    if (data_ov004_02171010->unknown_18f4_ == 0) {
        return 0;
    }
    Zone3D_GetInstance(GameState::GetInstance());
    int index = GetScaledStat_021634dc_021634dc(a);
    if (data_ov004_02171010->maps[index].GetInitialByteUnknownBit()) {
        return 0;
    }

    int var1;
    for (var1 = var0; var1 < data_ov004_02171010->unknown_18f4_ - 1; var1++) {
        VectorizedInvertedMemcpy(&data_ov004_02171010->unknown_0_[var1 + 1], &data_ov004_02171010->unknown_0_[var1], sizeof(TreasureMapMetadata));
    }
    int var2;
    for (var2 = data_ov004_02171010->unknown_18f4_ - 1; var2 < 99; var2++) {
        VectorizedMemset(&data_ov004_02171010->unknown_0_[var2], 0, sizeof(TreasureMapMetadata));
    }

    if (var0 + 1 == data_ov004_02171010->unknown_18f4_ && var0 != 0) {
        struct Struct_ov004_02164c18_2* var3 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xa);
        if (var3 == 0) {
            return 0;
        }
        if (func_ov023_021f6f10(var3) != 7) {
            return 0;
        }
        data_ov004_02171010->unknown_18f6_ = (var0 - 1) / 8;
        short var4 = (var0 - 1) % 8;
        short var5 = data_ov004_02171010->unknown_18f8_;
        short var6 = data_ov004_02171010->unknown_18f6_;
        var3->unknown_5c_ = var6;
        var3->unknown_5e_ = var5;
        func_ov023_021f9ba8(var3, var4);
    }

    data_ov004_02171010->unknown_18f4_--;
    if (data_ov004_02171010->unknown_18f4_ == 0) {
        func_ov004_021636b0(arg0, data_ov004_02170598);
    }
    func_ov004_02163530(arg0);
    func_ov004_02164084(arg0);
    return 0;
}
