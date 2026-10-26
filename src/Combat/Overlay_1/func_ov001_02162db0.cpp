#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct Struct_02000c9c_38 {
    char unk_0[0x20];
};

struct Struct_ov001_02162db0 {
    char unk_0[0x194];
    Struct_02000c9c_38 slots[1];
};

struct Struct_ov001_02162db0_2 {
    #if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif
    Struct_ov001_02162db0* record;
};

struct Struct_ov001_02162db0_3 {
    #if defined(jpn)
    char unk_0[0x17c];
#else
    char unk_0[0x180];
#endif
    signed char type;
    char unknown_181_;
    short value;
};

struct Struct_ov001_02165880_51 {
    char unk_0[0x18];
    unsigned int flags;
};

struct Struct_ov001_02164d14_3 {
    char unk_0[0x30];
    int combatantId;
    int ids[8];
};

extern "C" int func_ov017_021d60f4(void* args);
struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(Field150Holder02052e2c*);
struct Struct_02052df8;
extern "C" int func_02052df8(Struct_02052df8*, int);
extern "C" void func_02052d7c(Struct_ov001_02162db0_2* combatant, int index, short value);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" void func_ov017_0218f5a4(GameResources* resources, int combatantId, int a, int b, int c);

extern Struct_ov001_02165880_51 data_ov001_02165880;
extern Struct_ov001_02164d14_3 data_ov001_02164d14;
extern int data_ov001_02164a30[];
extern int data_ov001_02164d44[];

// USA: func_ov001_02162db0
extern "C" ARM int func_ov001_02162db0(void* args, int argc) {
    GameState* gameState;
    Struct_ov001_02162db0_2* combatant;
    int mode;
    GameResources* resources;
    Struct_ov001_02162db0_3* saved;
    int combatantId;
    int slot;
    short* values;

    gameState = GameState::GetInstance();
    combatantId = func_ov017_021d60f4(args);
    combatant = (Struct_ov001_02162db0_2*)func_0200ff1c(gameState, combatantId);
    if (combatant == NULL) {
        return 0;
    }
    slot = func_ov017_021d60f4((char*)args + 8);
    mode = 0;
    if (argc >= 3) {
        mode = func_ov017_021d60f4((char*)args + 0x10);
    }

    if (!(data_ov001_02165880.flags & 1)) {
        int base = combatantId * 0xc;
        data_ov001_02164d14.combatantId = combatantId;
        data_ov001_02164d14.ids[0] = base + 0x13;
        data_ov001_02164d14.ids[1] = base + 0x14;
        data_ov001_02164d14.ids[2] = base + 0x15;
        data_ov001_02164d14.ids[3] = base + 0x17;
        data_ov001_02164d14.ids[4] = base + 0x19;
        data_ov001_02164d14.ids[5] = base + 0x1b;
        data_ov001_02164d14.ids[6] = base + 0x1c;
        data_ov001_02164d14.ids[7] = base + 0x1d;
        data_ov001_02165880.flags |= 1;
    }

    if (&combatant->record->slots[(unsigned char)data_ov001_02164a30[slot]] == NULL) {
        return 0;
    }
    values = func_02052e2c((Field150Holder02052e2c*)combatant);
    if (values == NULL) {
        return 0;
    }

    resources = GetGameResources();
    saved = (Struct_ov001_02162db0_3*)resources->unknown_ptr_array_371c[6];
    GameState_GetParty(gameState);
    gameState->GetGameObjectByIndex(data_ov001_02164d44[slot]);

    if (mode == 0) {
        saved->value = -1;
        saved->type = -1;
        saved->value = values[slot];
        func_02052d7c(combatant, slot, -1);
    } else {
        int value = saved->value;
        signed char type = saved->type;
        saved->value = -1;
        saved->type = -1;
        if (func_02052df8((Struct_02052df8*)combatant, slot) < 0 && type != 6) {
            func_02052d7c(combatant, slot, value);
        }
    }

    ClearFlags00(resources, 0x10);
    BackgroundLoader::GetInstance();
    func_ov017_0218f5a4(resources, combatantId, 1, 0, 0);
    return 1;
}
