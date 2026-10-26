#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define data_020f2838 g_itemDataFile
#define data_020ee678 data_020ee784
#endif

struct Struct020d9fc8;
void FieldTask_EndQuestCancel(struct Struct020d9fc8* p);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* word, unsigned int mask);

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

// Main, originally func_020d9e44 (USA 0x020d9e44, EUR 0x020d9e54, JPN 0x020db84c)
extern "C" ARM void FieldTask_QuestCancel(Self020d9e44* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        if (self->flags == 0) {
            FieldTask_EndQuestCancel((struct Struct020d9fc8*)self);
            return;
        }
        GameObject_DisableControl((struct Obj020397cc*)GameState::GetInstance()->GetLeader(), 1);
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x1e);
        if (self->flags & 1) {
            self->tasks[0] = loader->QueueLoadFile(data_020f2838, NULL);
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
