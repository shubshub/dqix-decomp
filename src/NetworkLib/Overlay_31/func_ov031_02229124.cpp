#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"
struct Struct_ov031_02229124 { unsigned char unknown_0_[16][0x20]; };
struct Struct_ov031_02290c5c_2 { void* field0; Struct_ov031_02229124* palette; int field8; };
typedef void (*Type_01ff8b48_7)(const void*, unsigned int, unsigned int);
extern "C" void func_ov031_022234d8(const char*, Type_01ff8b48_7);
extern "C" int func_ov031_02223478(const char*);
extern "C" Struct_ov031_02229124* func_ov031_0223b61c(int, int, int);
extern "C" void func_ov031_0221ae00(unsigned int*);
extern "C" void func_ov031_0223b710(void*);
struct Struct_ov031_02248dcc { char name[22]; };
struct Struct_ov031_02248de2 { char name[23]; };
extern Struct_ov031_02248dcc data_ov031_02248dcc;
extern Struct_ov031_02248de2 data_ov031_02248de2;
extern char data_ov031_0224b8f4[];
extern char data_ov031_0224b90c[];
extern Struct_ov031_02290c5c_2 data_ov031_02290c5c;
// USA: func_ov031_02229124
extern "C" ARM void func_ov031_02229124() {
    unsigned char* var0;
    unsigned char* var1;
    int index;
    Struct_ov031_02229124* palette;
    Struct_ov031_02248dcc var4 = data_ov031_02248dcc;
    Struct_ov031_02248de2 var5 = data_ov031_02248de2;
    unsigned int settings[5];
    func_ov031_022234d8(data_ov031_0224b8f4, LoadToMainBG2CharacterData);
    func_ov031_022234d8(data_ov031_0224b90c, LoadToMainBG2ScreenData);
    data_ov031_02290c5c.palette = func_ov031_0223b61c(func_ov031_02223478(var5.name), 0, 4);
    palette = func_ov031_0223b61c(func_ov031_02223478(var4.name), 0, 4);
    func_ov031_0221ae00(settings);
    unsigned int high = settings[1];
    unsigned int low = settings[0];
    index = 0;
    if (high == 0 && low == 0) {
        var0 = palette->unknown_0_[6];
        var1 = palette->unknown_0_[2];
        do {
            VectorizedInvertedMemcpy(var0, var1, 0x20);
            ++index;
            var0 += 0x20;
            var1 += 0x20;
        } while (index < 2);
    }
    CleanInvalidateCacheRange(palette, 0x200);
    LoadToMainBGStandardPalette(palette, 0, 0x200);
    func_ov031_0223b710(palette);
    BG0CNTSUB = (BG0CNTSUB & ~3) | 3;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 3;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 3;
}
