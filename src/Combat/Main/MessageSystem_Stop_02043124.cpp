#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>
#include <NitroSDK/BGBases.h>
struct Struct_020e1cb8;
extern "C" void func_020e1cb8(Struct_020e1cb8*);
#if defined(jpn)
struct Struct_02107800_3 { char pad[0x30]; void* pointer; };
extern Struct_02107800_3 data_02107800;
#else
extern void* data_02107800;
#endif
struct Object02043124 {
    char unknown_0_[IS_JPN ? 4 : 0x38];
    Struct_020e1cb8* owner;
    char unknown_3c_[IS_JPN ? 0x860 : 0x95c];
    int field_0x998, unknown_99c_, unknown_9a0_;
    char unknown_9a4_[IS_JPN ? 0xf89 : 0x1028];
    unsigned char unknown_19cc_;
};
#define REG_BG_OFFSET (*(volatile unsigned int*)0x04000018)
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
// Main, originally func_02043124 (USA 0x02043124, EUR 0x02043134, JPN 0x02043898)
extern "C" ARM void MessageSystem_Stop(Object02043124* object) {
    object->unknown_9a0_ = 0;
    object->field_0x998 = 0;
    if (object->unknown_19cc_) {
        object->unknown_19cc_ = 0;
        #if defined(jpn)
        void* storage = data_02107800.pointer;
#else
        void* storage = data_02107800;
#endif
        memset(storage, 0, 0x1000);
        StageMemoryToVRAM((VRAMSubregion)7, storage, 0, 0x800, true, false);
        StageMemoryToVRAM((VRAMSubregion)9, storage, 0, 0x800, true, false);
        void* screen = (void*)GetMainBG1ScreenBase();
        if (screen) memset(screen, 0, 0x800);
        REG_BG_OFFSET = 0;
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1300;
    }
    if (object->owner) {
        func_020e1cb8(object->owner);
    }
    object->owner = 0;
}
