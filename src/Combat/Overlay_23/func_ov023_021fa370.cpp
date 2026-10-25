#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* arg0);

struct Struct_021f6bb8 { int unknown_0_; int unknown_4_; };
extern "C" int func_ov023_021f6bb8(struct Struct_021f6bb8* arg0);
extern "C" void func_ov023_021f6bb0(void* arg0, int arg1);

extern int GameState_GetProtagonistIndex(GameState* battleStruct);

extern "C" void* __clear(void* arg0, int arg1);

extern char data_ov023_021feb30[];

struct Struct_ov023_021fa370 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov023_021fa370_2 {
    char unknown_0_[0x10];
    char* unknown_10_;
    char unknown_14_[0x28 - 0x14];
#if defined(jpn)

#else
    char* unknown_28_;
#endif

    char unknown_2c_[0x2c - 0x2c];
    unsigned char unknown1_2c_;
};

struct Struct_ov023_021fa370_3 {
    char unknown_0_[0x1c];
    int unknown_1c_;
};

struct Struct_ov023_021fa370_4 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif

    struct Struct_ov023_021fa370* unknown_150_;
};

// USA: func_ov023_021fa370
extern "C" ARM int func_ov023_021fa370(struct Struct_ov023_021fa370_2* arg0, void* arg1) {
    void* var0;
    int var1;
    int var2;
    int var3;
    char var4[0x20];
    char var5[0x40];

    var0 = func_ov011_021849c8(arg1);
    var1 = func_ov023_021f6bb8((struct Struct_021f6bb8*)var0);
    if (var1 >= 0) goto earlyOut;

    handle = (int)BackgroundLoader::GetInstance();
    zeroPad = 0;
    if (obj->kind == 1) {
        GameState* bs = GameState::GetInstance();
        int id = GameState_GetProtagonistIndex(bs);
        struct Combatant021fa370* combatant = (struct Combatant021fa370*)bs->GetPartyMemberByIndex(id);
        if (combatant != 0) {
            zeroPad = combatant->inner->flagBit;
        }
    } else if (arg0->unknown1_2c_ == 2) {
    } else if (arg0->unknown1_2c_ == 3) {
        var3 = 1;
    }

#if defined(jpn)
    sprintf(var4, arg0->unknown_10_, var3);

#else
    if (arg0->unknown_28_ != 0) {
        sprintf(var4, arg0->unknown_28_, var3);
    } else {
        sprintf(var4, arg0->unknown_10_, var3);
    }

#endif
    __clear(var5, 0x40);
    if (strncmp(var5, data_ov023_021feb30, 5) != 0) {
        strcpy(var5, data_ov023_021feb30);
    }
    strcat(var5, var4);

    {
        int var9;
#if defined(jpn)
        var9 = ((BackgroundLoader*)(var2))->QueueLoadFile(var5, (SafeAllocator*)0);

#else
        if (arg0->unknown_28_ != 0) {
            memset(var4, 0, 0x20);
            sprintf(var4, arg0->unknown_10_, var3);
            var9 = ((BackgroundLoader*)(var2))->QueueLoadFileInGP2((const char*)((int)var5), (const char*)((int)var4), (SafeAllocator*)(0));
        } else {
            var9 = ((BackgroundLoader*)(var2))->QueueLoadFile((const char*)((int)var5), (SafeAllocator*)(0));
        }

#endif
        func_ov023_021f6bb0(var0, var9);
    }
    return 1;

earlyOut:
    return ((struct Struct_ov023_021fa370_3*)arg0)->unknown_1c_;
}
