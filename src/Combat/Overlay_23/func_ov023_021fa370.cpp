#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* obj);

struct Struct_021f6bb8 { int unk0; int field4; };
extern "C" int func_ov023_021f6bb8(struct Struct_021f6bb8* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

extern "C" void* __clear(void* dst, int count);

extern char data_ov023_021feb30[];

struct Struct_ov023_021fa370 {
    char pad[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov023_021fa370_2 {
    char pad0[0x10];
    char* unknown_10_;
    char pad1[0x28 - 0x14];
#if defined(jpn)

#else
    char* unknown_28_;
#endif

    char pad2[0x2c - 0x2c];
    unsigned char kind;
};

struct Struct_ov023_021fa370_3 {
    char pad[0x1c];
    int field1c;
};

struct Struct_ov023_021fa370_4 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif

    struct Struct_ov023_021fa370* inner;
};

// USA: func_ov023_021fa370
extern "C" ARM int func_ov023_021fa370(struct Struct_ov023_021fa370_2* obj, void* param1) {
    void* var0;
    int query;
    int handle;
    int var3;
    char buf40[0x20];
    char var5[0x40];

    var0 = func_ov011_021849c8(param1);
    query = func_ov023_021f6bb8((struct Struct_021f6bb8*)var0);
    if (query >= 0) goto earlyOut;

    handle = (int)BackgroundLoader::GetInstance();
    var3 = 0;
    if (obj->kind == 1) {
        GameState* bs = GameState::GetInstance();
        int id = GameState_GetProtagonistIndex(bs);
        struct Struct_ov023_021fa370_4* combatant = (struct Struct_ov023_021fa370_4*)bs->GetPartyMemberByIndex(id);
        if (combatant != 0) {
            var3 = combatant->inner->unknown_49c_0_;
        }
    } else if (obj->kind == 2) {
    } else if (obj->kind == 3) {
        var3 = 1;
    }

#if defined(jpn)
    sprintf(buf40, obj->unknown_10_, var3);

#else
    if (obj->unknown_28_ != 0) {
        sprintf(buf40, obj->unknown_28_, var3);
    } else {
        sprintf(buf40, obj->unknown_10_, var3);
    }

#endif
    __clear(var5, 0x40);
    if (strncmp(var5, data_ov023_021feb30, 5) != 0) {
        strcpy(var5, data_ov023_021feb30);
    }
    strcat(var5, buf40);

    {
        int result;
#if defined(jpn)
        result = ((BackgroundLoader*)(handle))->QueueLoadFile(var5, (SafeAllocator*)0);

#else
        if (obj->unknown_28_ != 0) {
            memset(buf40, 0, 0x20);
            sprintf(buf40, obj->unknown_10_, var3);
            result = ((BackgroundLoader*)(handle))->QueueLoadFileInGP2((const char*)((int)var5), (const char*)((int)buf40), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)((int)var5), (SafeAllocator*)(0));
        }

#endif
        func_ov023_021f6bb0(var0, result);
    }
    return 1;

earlyOut:
    return ((struct Struct_ov023_021fa370_3*)obj)->field1c;
}
