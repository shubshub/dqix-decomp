#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define data_020f2838 g_itemDataFile
#define data_020ee678 data_020ee784
#endif

struct Struct_020d9e44;
extern "C" void func_020d9fc8(struct Struct_020d9e44* arg0);

struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);

extern "C" void* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);

extern const char data_020f2838[];

struct Struct_020d9e44_2 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    int unknown_c_[1];
};

typedef void (Self020d9e44::*Handler020d9e44)();
struct HandlerTable020d9e44 { Handler020d9e44 e[2]; };
extern HandlerTable020d9e44 data_020ee678;
extern Handler020d9e44 __ptmf_null;

// USA: func_020d9e44
extern "C" ARM void func_020d9e44(Struct_020d9e44_2* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_a_ == 0) {
        if (arg0->unknown_8_ == 0) {
            func_020d9fc8((struct Struct_020d9e44*)arg0);
            return;
        }
        func_020397cc((struct Struct_02018300_3*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        func_020466e4((unsigned int*)func_020d6c00(), 0x1e);
        if (arg0->unknown_8_ & 1) {
            arg0->unknown_c_[0] = var0->QueueLoadFile(data_020f2838, NULL);
        }
        arg0->unknown_a_++;
    } else if (arg0->unknown_a_ == 1) {
        int var1;
        int var2 = 0;
        for (var1 = 0; var1 < 1; var1++) {
            if (arg0->unknown_c_[var1] == -1) { var2++; continue; }
            if (var0->GetTaskStatus(arg0->unknown_c_[var1]) == 0) continue;
            if (var0->GetDetailedTaskStatus(arg0->unknown_c_[var1]) == 2) break;
            var0->RemoveTask(arg0->unknown_c_[var1]);
            arg0->unknown_c_[var1] = -1;
        }
        if (done == 1) { self->state = 0; return; }
        if (i == 1) return;
        HandlerTable020d9e44 table;
        table = data_020ee678;
        table.e[1] = __ptmf_null;
        (self->*table.e[i])();
    }
}
