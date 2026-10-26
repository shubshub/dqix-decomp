#if defined(jpn)
enum { Enum_ov017_021bb1a4_255 = 0xfb, Enum_ov017_021bb1a4_256 = 0xfc, Enum_ov017_021bb1a4_288 = 0x11c };
#else
enum { Enum_ov017_021bb1a4_255 = 0xff, Enum_ov017_021bb1a4_256 = 0x100, Enum_ov017_021bb1a4_288 = 0x120 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

class Struct_ov017_021bb1a4 {
public:
    char unknown_0_[0xa];
    unsigned short unknown_a_;
    char unknown_c_[Enum_ov017_021bb1a4_255 - 0xc];
    unsigned char unknown_ff_;
    char unknown_100_[Enum_ov017_021bb1a4_288 - Enum_ov017_021bb1a4_256];
    void* unknown_120_;
};

typedef unsigned short (Struct_ov017_021bb1a4::*Type_02000c9c_19)(int);

extern Type_02000c9c_19 data_ov017_021d7ccc[20];
extern unsigned int data_ov017_021d845c;
extern StateFn021bb1a4 __ptmf_null;

extern "C" void func_0208bb78(void* timer, unsigned int ticks);
int PopStack0AndTrigger_020a1e54(int flag);
extern "C" void ROMFilesystem_InitFileTables(void);

// Overlay 17, originally func_ov017_021bb1a4 (USA/EUR 0x021bb1a4, JPN 0x021bb79c)
extern "C" ARM void FieldTask_ScriptedEvent(StateMachine021bb1a4* self, int arg) {
    if (!(data_ov017_021d845c & 1)) {
        data_ov017_021d7ccc[19] = __ptmf_null;
        data_ov017_021d845c |= 1;
    }

    if (arg0->unknown_120_ != 0) {
        func_0208bb78(arg0->unknown_120_, GameState::GetInstance()->GetTickCount());
    }

    if (data_ov017_021d7ccc[arg0->unknown_a_] != 0) {
        arg0->unknown_a_ = (arg0->*data_ov017_021d7ccc[arg0->unknown_a_])(arg1);
    }

    if (arg0->unknown_ff_ != 0) {
        if (TestFlags00(GetGameResources(), 0x1000) == 0) {
            PopStack0AndTrigger_020a1e54(1);
            ROMFilesystem_InitFileTables();
        }
    }
}
