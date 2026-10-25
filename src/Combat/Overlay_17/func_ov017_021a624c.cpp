#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

#if defined(jpn)
#define GLOB1C_FLAG_021a624c 0x868
#else
#define GLOB1C_FLAG_021a624c 0x998
#endif

#if defined(jpn)
#define func_020daf90 func_020dc998
#endif

extern "C" void* func_0202ae18(void);
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" int func_0202c540(void* p);

int GetIntField0x260_02039750(void* obj);
int MessageSystem_GetInstance();
extern "C" void* func_020daf90(void);
extern "C" int func_02046b08(void** arg0);

struct Struct_02015a2c_2;
extern "C" int func_02015a2c(struct Struct_02015a2c_2* arg0);

extern "C" int func_020db2d4(void* arg0);

extern "C" void func_ov017_021a5bac(unsigned char* arg0);
extern "C" void func_ov017_021a5b48(unsigned char* arg0);
extern "C" void func_ov017_021a5cbc(GameResources* arg0);

typedef union {
    unsigned short unknown_0_;
    struct {
        unsigned short unknown_0_0_ : 2;
        unsigned short unknown_0_2_ : 4;
        unsigned short unknown_0_6_ : 1;
        unsigned short unknown_0_7_ : 1;
        unsigned short unknown_1_0_ : 5;
        unsigned short unknown_1_5_ : 1;
        unsigned short unknown_1_6_ : 2;
    };
} Struct_ov017_021a624c;

static inline Struct_ov017_021a624c inline_ov017_021a624c() {
    return *(volatile Struct_ov017_021a624c*)0x400000a;
}

static inline Struct_ov017_021a624c inline_ov017_021a624c_2() {
    volatile Struct_ov017_021a624c* var0 = (volatile Struct_ov017_021a624c*)0x400000c;
    return *var0;
}

// USA: func_ov017_021a624c
extern "C" ARM void func_ov017_021a624c(GameResources* arg0) {
    void* var0 = func_0202ae18();
    GameState* var1 = GameState::GetInstance();
    GameObject* var2 = var1->GetProtagonist();
    if (var2 == 0) return;

    int f260 = GetIntField0x260_02039750(protagonist);
    int glob1c = MessageSystem_GetInstance();
    GrottoStruct* grotto;
    Zone3D_StructPtr_8* info;
    Zone3D* zone = Zone3D_GetInstance();
    info = zone->pUnknownStruct_8_;
    grotto = gs->GetGrottoStruct();
    void* ctx = func_020daf90();

    if (gs->GetGrottoStruct()->unknown_0[0] == 0 ||
        self->unknown_4080 != 0 || f260 != -1 ||
        !IsField0Null_02046b08((void**)self->fieldTaskQueue_) ||
        func_0202c540(searchObj) ||
        IsGlobalU16InRange_020117f0(GameState::GetInstance()) != 0 ||
        *(int*)((char*)glob1c + GLOB1C_FLAG_021a624c) != 0 ||
        CheckSlotsForFlagState02015a2c((struct Something02015a2c*)zone) ||
        info == 0 || info->unknown_c_low_ != 0 ||
        GetField0x50_020db2d4(ctx)) {
        grotto->unknown_0[2] = 1;
        func_ov017_021a5bac((unsigned char*)self);
    } else if (*(int*)(self->unknown_4094 + 0x12c) == 0) {
        *(BgControl*)self->unknown_ptr_array_4088[0] = GetBg1Control();
        *(BgControl*)self->unknown_ptr_array_4088[1] = GetBg2Control();
        grotto->unknown_0[2] = 0;
        InitFieldArenaLists_021a5b48((unsigned char*)self);
        *(int*)(self->unknown_4094 + 0x12c) = 1;
    } else {
        func_ov017_021a5cbc(arg0);
    }
}
