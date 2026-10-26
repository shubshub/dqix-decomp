#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define data_020f2838 g_itemDataFile
#define data_020ee678 data_020ee784
#endif

struct Struct020d9fc8;
extern "C" void FieldTask_EndQuestCancel(struct Struct020d9fc8* p);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int mask);

extern const char data_020f2838[];

struct Self020d9e44 {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char state;
    unsigned char pad1;
    int tasks[1];
};

typedef void (Self020d9e44::*Type_02000c9c_13)();
struct Struct_020ee678 { Type_02000c9c_13 e[2]; };
extern Struct_020ee678 data_020ee678;
extern Type_02000c9c_13 __ptmf_null;

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
        self->state++;
    } else if (self->state == 1) {
        int i;
        int done = 0;
        for (i = 0; i < 1; i++) {
            if (self->tasks[i] == -1) { done++; continue; }
            if (loader->GetTaskStatus(self->tasks[i]) == 0) continue;
            if (loader->GetDetailedTaskStatus(self->tasks[i]) == 2) break;
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
        }
        if (done == 1) { self->state = 0; return; }
        if (i == 1) return;
        Struct_020ee678 table;
        table = data_020ee678;
        table.e[1] = __ptmf_null;
        (self->*table.e[i])();
    }
}
