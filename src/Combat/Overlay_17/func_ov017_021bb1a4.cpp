#if defined(jpn)
enum { RegionOffsetff = 0xfb, RegionOffset100 = 0xfc, RegionOffset120 = 0x11c };
#else
enum { RegionOffsetff = 0xff, RegionOffset100 = 0x100, RegionOffset120 = 0x120 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

class StateMachine021bb1a4 {
public:
    char unk_0[0xa];
    unsigned short state_;
    char unk_c[RegionOffsetff - 0xc];
    unsigned char checkExit_;
    char unk_100[RegionOffset120 - RegionOffset100];
    void* timer_;
};

typedef unsigned short (StateMachine021bb1a4::*StateFn021bb1a4)(int);

extern StateFn021bb1a4 data_ov017_021d7ccc[20];
extern unsigned int data_ov017_021d845c;
extern StateFn021bb1a4 __ptmf_null;

extern "C" void func_0208bb78(void* timer, unsigned int ticks);
int PopStack0AndTrigger_020a1e54(int flag);
extern "C" void func_020a0c0c(void);

// USA: func_ov017_021bb1a4
extern "C" ARM void func_ov017_021bb1a4(StateMachine021bb1a4* self, int arg) {
    if (!(data_ov017_021d845c & 1)) {
        data_ov017_021d7ccc[19] = __ptmf_null;
        data_ov017_021d845c |= 1;
    }

    if (self->timer_ != 0) {
        func_0208bb78(self->timer_, GameState::GetInstance()->GetTickCount());
    }

    if (data_ov017_021d7ccc[self->state_] != 0) {
        self->state_ = (self->*data_ov017_021d7ccc[self->state_])(arg);
    }

    if (self->checkExit_ != 0) {
        if (TestFlags00(GetGameResources(), 0x1000) == 0) {
            PopStack0AndTrigger_020a1e54(1);
            func_020a0c0c();
        }
    }
}
