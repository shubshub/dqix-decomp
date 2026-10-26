#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, Enum_ov017_0219fc88_1844 = 0x524, RegionOffset6d0 = 0x4c0, Enum_ov017_0219fc88_266 = 0x106 };
#else
enum { RegionOffset6fc = 0x6fc, Enum_ov017_0219fc88_1844 = 0x734, RegionOffset6d0 = 0x6d0, Enum_ov017_0219fc88_266 = 0x10a };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);

struct Struct_02071488 {
    char pad0[0x46];
    short f46;
    char unknown_48_[0x68 - 0x48];
};
extern "C" struct Struct_02071488* func_02071574(unsigned int value, struct Struct_02071488* obj);

extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

extern "C" void func_ov017_021baedc(void* self, int flag);

struct SetFlagStruct;
extern "C" void MapDisplay_SetHoldSubScreenDark(struct SetFlagStruct* p, int value);

struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void func_ov017_021bd398(void* obj);

extern "C" int func_020649f4(void* a, void* b);
extern "C" void EventQuery_RunQueuedCommands(void* p);

struct Struct_ov017_0219fc88 {
    char pad0[2];
    unsigned char f2;
    unsigned char f3;
    char pad4[8 - 4];
    unsigned short f8;
    char pad10[Enum_ov017_0219fc88_266 - 0xa];
    unsigned char unknown_10a_;
};

struct Struct_ov017_0219fc88_2 {
    char pad0[0xc];
    int f0xc;
    char pad1[0x34 - 0x10];
};

// USA: func_ov017_0219fc88
extern "C" ARM int func_ov017_0219fc88(void* unusedSelf, int scriptId) {
    GameState* battle = GameState::GetInstance();
    unsigned short* g = (unsigned short*)Zone3D_GetInstance();
    void* ctx;
    int var3;
    void* self = GetGameResources();
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)self + 0x3000 + RegionOffset6fc);
    ctx = GameState_GetZoneTransition(battle);

    struct Struct_02071488 objBuf;
    var3 = 0;

    if (func_02071574((unsigned short)scriptId, &objBuf) != NULL) {
        void* work = Scenario_GetInstance();
        if (Scenario_TestFlag((int)work, (unsigned char*)work + 0x8c, objBuf.f46 + 0x38e) == 0) {
            struct Struct_ov017_0219fc88* entry = *(struct Struct_ov017_0219fc88**)((char*)self + 0x3000 + Enum_ov017_0219fc88_1844);

            if (entry->f2 != 0) {
                entry->f8 = scriptId;
            } else if (entry->f3 == 0) {
                func_ov017_021baedc(entry, 1);
                entry->f8 = scriptId;
                MapDisplay_SetHoldSubScreenDark(*(struct SetFlagStruct**)((char*)self + 0x3000 + RegionOffset6d0), 1);
                func_020469b4(list, (struct TailNode020469b4*)entry);
            }

            func_ov017_021bd398(entry);

            if (*((unsigned char*)ctx + 0xd) != 0) entry->unknown_10a_ = 1;
            var3 = 1;
        }
    }

    if (!var3) {
        void* work2 = Scenario_GetInstance();
        struct Struct_ov017_0219fc88_2 d;
        d.f0xc = *g;
        if (func_020649f4(work2, &d)) {
            EventQuery_RunQueuedCommands(&d);
        }
    }

    return var3;
}
