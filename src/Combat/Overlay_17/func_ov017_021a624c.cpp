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


extern "C" void* LinkSession_GetInstance(void);
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);

extern "C" int GameObject_GetGestureSlot(void* obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void* ObjLoading_GetInstance(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);

struct Struct_02015a2c_2;
extern "C" int func_02015a2c(struct Struct_02015a2c_2* obj);

extern "C" int func_020db2d4(void* obj);

extern "C" void func_ov017_021a5bac(unsigned char* base);
extern "C" void func_ov017_021a5b48(unsigned char* base);
extern "C" void func_ov017_021a5cbc(GameResources* self);

typedef union {
    unsigned short raw;
    struct {
        unsigned short priority : 2;
        unsigned short charBase : 4;
        unsigned short unknown_0_6_ : 1;
        unsigned short colorMode : 1;
        unsigned short screenBase : 5;
        unsigned short unknown_1_5_ : 1;
        unsigned short screenSize : 2;
    };
} Struct_ov017_021a624c;

static inline Struct_ov017_021a624c inline_ov017_021a624c() {
    return *(volatile Struct_ov017_021a624c*)0x400000a;
}

static inline Struct_ov017_021a624c inline_ov017_021a624c_2() {
    volatile Struct_ov017_021a624c* reg = (volatile Struct_ov017_021a624c*)0x400000c;
    return *reg;
}

// USA: func_ov017_021a624c
extern "C" ARM void func_ov017_021a624c(GameResources* self) {
    void* searchObj = LinkSession_GetInstance();
    GameState* gs = GameState::GetInstance();
    GameObject* protagonist = gs->GetProtagonist();
    if (protagonist == 0) return;

    int f260 = GameObject_GetGestureSlot(protagonist);
    int glob1c = MessageSystem_GetInstance();
    GrottoStruct* grotto;
    Zone3D_StructPtr_8* info;
    Zone3D* zone = Zone3D_GetInstance();
    info = zone->pUnknownStruct_8_;
    grotto = gs->GetGrottoStruct();
    void* ctx = ObjLoading_GetInstance();

    if (gs->GetGrottoStruct()->unknown_0[0] == 0 ||
        self->unknown_4080 != 0 || f260 != -1 ||
        !FieldTaskQueue_IsEmpty((void**)self->fieldTaskQueue_) ||
        LinkSession_IsGuest(searchObj) ||
        GameState_IsInGrotto(GameState::GetInstance()) != 0 ||
        *(int*)((char*)glob1c + GLOB1C_FLAG_021a624c) != 0 ||
        func_02015a2c((struct Struct_02015a2c_2*)zone) ||
        info == 0 || info->unknown_c_low_ != 0 ||
        func_020db2d4(ctx)) {
        grotto->unknown_0[2] = 1;
        func_ov017_021a5bac((unsigned char*)self);
    } else if (*(int*)(self->unknown_4094 + 0x12c) == 0) {
        *(Struct_ov017_021a624c*)self->unknown_ptr_array_4088[0] = inline_ov017_021a624c();
        *(Struct_ov017_021a624c*)self->unknown_ptr_array_4088[1] = inline_ov017_021a624c_2();
        grotto->unknown_0[2] = 0;
        func_ov017_021a5b48((unsigned char*)self);
        *(int*)(self->unknown_4094 + 0x12c) = 1;
    } else {
        func_ov017_021a5cbc(self);
    }
}
