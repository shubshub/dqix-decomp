#include <globaldefs.h>
#include "Resource/GameResources.h"

void InitObj_021a7328(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a72f4  (semantic: CreateAndAppendNode_021a72f4)
extern "C" ARM void func_ov017_021a72f4(void* unused, int val) {
    GameResources* resources = GetGameResources();
    TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
    char* node = (char*)resources->fieldTasks_[38];
    InitObj_021a7328(node);
    *(int*)(node + 0xc) = val;
    AppendNodeToTail(list, (TailNode020469b4*)node);
}
