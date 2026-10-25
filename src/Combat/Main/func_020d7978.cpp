#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct SePlayer;
struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

void SePlayer_Play(SePlayer* obj, int a, int b);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_020f2334;

// USA: func_020d7978
extern "C" ARM void func_020d7978() {
    SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
    GameResources* res = GetGameResources();
    TailList020469b4* list;
    unsigned char* obj = static_cast<unsigned char*>(res->fieldTasks_[20]);
    list = (TailList020469b4*)res->fieldTaskQueue_;
    InitObjState_021b2174(obj);
    SetNameChecked_021b2ba0((S021b2ba0*)obj, &data_020f2334);
    SetFields30And34_021b2bd0(obj, (int)CopyGlobalBlockAndDispatch_02165df4, OVERLAY_ID(4));
    AppendNodeToTail(list, (TailNode020469b4*)obj);
}
