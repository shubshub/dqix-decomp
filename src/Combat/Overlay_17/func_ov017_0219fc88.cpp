#if defined(jpn)
enum { Enum_ov017_0219fc88_1788 = 0x4ec, Enum_ov017_0219fc88_1844 = 0x524, Enum_ov017_0219fc88_1744 = 0x4c0, Enum_ov017_0219fc88_266 = 0x106 };
#else
enum { Enum_ov017_0219fc88_1788 = 0x6fc, Enum_ov017_0219fc88_1844 = 0x734, Enum_ov017_0219fc88_1744 = 0x6d0, Enum_ov017_0219fc88_266 = 0x10a };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


extern "C" void* Zone3D_GetInstance(void);
void* GameState_GetZoneTransition(GameState* battleStruct);

struct Struct_02071488 {
    char unknown_0_[0x46];
    short unknown_46_;
    char unknown_48_[0x68 - 0x48];
};
extern "C" struct Struct_02071488* func_02071574(unsigned int arg0, struct Struct_02071488* arg1);

extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);

extern "C" void func_ov017_021baedc(void* arg0, int arg1);

struct SetFlagStruct;
void MapDisplay_SetHoldSubScreenDark(struct SetFlagStruct* p, int value);

struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

extern "C" void func_ov017_021bd398(void* arg0);

int Dispatch020649f4(void* a, void* b);
extern "C" void EventQuery_RunQueuedCommands(void* p);

struct Struct_ov017_0219fc88 {
    char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    char unknown_4_[8 - 4];
    unsigned short unknown_8_;
    char unknown_a_[Enum_ov017_0219fc88_266 - 0xa];
    unsigned char unknown_10a_;
};

struct Struct_ov017_0219fc88_2 {
    char unknown_0_[0xc];
    int unknown_c_;
    char unknown_10_[0x34 - 0x10];
};

// USA: func_ov017_0219fc88  (semantic: RunScriptAndRegisterEntryNode_0219fc88)
extern "C" ARM int func_ov017_0219fc88(void* unusedSelf, int scriptId) {
    GameState* battle = GameState::GetInstance();
    unsigned short* g = (unsigned short*)Zone3D_GetInstance();
    void* ctx;
    int success;
    void* self = GetGameResources();
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)self + 0x3000 + RegionOffset6fc);
    ctx = GameState_GetZoneTransition(battle);

    struct Struct_02071488 var6;
    var3 = 0;

    if (RunScriptByValueRange02071574((unsigned short)scriptId, &objBuf) != NULL) {
        void* work = Scenario_GetInstance();
        if (Scenario_TestFlag((int)work, (unsigned char*)work + 0x8c, objBuf.f46 + 0x38e) == 0) {
            struct Entry021baedc* entry = *(struct Entry021baedc**)((char*)self + 0x3000 + RegionOffset734);

            if (entry->f2 != 0) {
                entry->f8 = scriptId;
            } else if (entry->f3 == 0) {
                func_ov017_021baedc(entry, 1);
                entry->f8 = scriptId;
                MapDisplay_SetHoldSubScreenDark(*(struct SetFlagStruct**)((char*)self + 0x3000 + RegionOffset6d0), 1);
                AppendNodeToTail(list, (struct TailNode020469b4*)entry);
            }

            func_ov017_021bd398(var8);

            if (*((unsigned char*)var2 + 0xd) != 0) var8->unknown_10a_ = 1;
            var3 = 1;
        }
    }

    if (!success) {
        void* work2 = Scenario_GetInstance();
        struct DispatchLocal0219fc88 d;
        d.f0xc = *g;
        if (Dispatch020649f4(work2, &d)) {
            EventQuery_RunQueuedCommands(&d);
        }
    }

    return var3;
}
