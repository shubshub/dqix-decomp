#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_ov004_0217052d data_ov004_02170deb
#endif

struct Struct_02013fb4;
struct Struct_ov004_02162dd8 { int unknown_0_; SafeAllocator unknown_4_; };

struct Struct_ov004_02162dd8_2 {
    Struct_02082064 unknown_0_[4];
    int unknown_10_[2];
};

struct Struct_ov004_021707e8_8 {
#if defined(jpn)
    char unknown_0_[0xa];
    unsigned char unknown_4_;
    unsigned char unknown1_0_;
    char unknown_c_[8];
#else
    unsigned char unknown1_0_;
    char unknown_1_[3];
    unsigned char unknown_4_;
    char unknown_5_[0xf];
#endif
    Struct_ov004_02162dd8_2* unknown_14_;
};

extern Struct_ov004_021707e8_8 data_ov004_021707e8;
extern int data_ov004_02170854[];
extern char data_ov004_0217052d[];
extern unsigned char g_fileLoadBuffer[0x30000];

extern "C" unsigned char func_020114ec(char* arg0, void* arg1);
extern "C" Struct_ov004_02162dd8* func_ov011_021845f8(void*, int);
extern "C" int func_02053c6c(unsigned char* arg0);
extern "C" int func_0208274c(void* arg0, Struct_02013fb4* arg1, int arg2, int arg3);

static inline Struct_ov004_02162dd8_2* inline_ov000_0217fa60_2(int arg0, Struct_ov004_02162dd8_2* arg1, int arg2) {
    int var0 = arg2 * 12;
    return &arg1[var0 + (arg0 - 1)];
}

static inline short inline_ov004_02162dd8(Struct_02082064* arg0) {
    return arg0->unknown_0_0_;
}

static inline short inline_ov004_02162dd8_2(Struct_02082064* arg0) {
    return arg0->unknown_1_2_;
}

static inline short inline_ov004_02162dd8_3(Struct_02082064* arg0) {
    return arg0->unknown_2_4_;
}

// USA: func_ov004_02162dd8
extern "C" ARM int func_ov004_02162dd8(void* arg0) {
    if (data_ov004_021707e8.unknown_4_ == 0) {
        return 0;
    }
    data_ov004_021707e8.unknown1_0_ = 1;
    GameState* var0 = GameState::GetInstance();
    unsigned char var1[4];
    int var2 = func_020114ec((char*)var0, var1);
    data_ov004_021707e8.unknown_14_ = 0;
    data_ov004_021707e8.unknown_14_ = (Struct_ov004_02162dd8_2*)func_ov011_021845f8(arg0, 4)->unknown_4_.Allocate(0x480);
    if (data_ov004_021707e8.unknown_14_ != 0) {
        memset(data_ov004_021707e8.unknown_14_, 0, 0x480);
        BackgroundLoader::AddLockGlobal();
        for (int var3 = 0; var3 < var2; var3++) {
            for (int var4 = 1; var4 < 13; var4++) {
                {
                    char path[0x20] = {0};
                    unsigned int size;
                    ResourceScriptEntry script;
                    sprintf(path, data_ov004_0217052d, data_ov004_02170854[j]);
                    if (LoadFileIntoMemory(path, &g_fileLoadBuffer, &size) != 0) {
                        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, ids[i]);
                        if (c != 0) {
                            unsigned char* f = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)c);
                            if (f != 0) {
                                InitAndRunScript0208274c(&script, (StreamHeader*)&g_fileLoadBuffer, size, *(unsigned short*)(f + data_ov004_02170854[j] * 2 + 0x16c));
                                Slot02162dd8* slot = GetSlot(data_ov004_02170854[j], data_ov004_021707e8.entries, ids[i]);
                                slot->t[0].low = GetLow(&script.initial.value8);
                                slot->t[0].middle = GetMiddle(&script.initial.value8) & 0x3ff;
                                slot->t[0].high = GetHigh(&script.initial.value8) & 0x3ff;
                                slot->t[1].low = GetLow(&script.initial.valueC);
                                slot->t[1].middle = GetMiddle(&script.initial.valueC) & 0x3ff;
                                slot->t[1].high = GetHigh(&script.initial.valueC) & 0x3ff;
                                slot->t[2].low = GetLow(&script.initial.value10);
                                slot->t[2].middle = GetMiddle(&script.initial.value10) & 0x3ff;
                                slot->t[2].high = GetHigh(&script.initial.value10) & 0x3ff;
                                slot->t[3].low = GetMiddle(&script.initial.valueC);
                            }
                        }
                    }
                }
            }
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    data_ov004_021707e8.unknown_4_ = 0;
    data_ov004_021707e8.unknown1_0_ = 0;
    return 0;
}
