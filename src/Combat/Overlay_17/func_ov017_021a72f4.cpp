#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021a7328(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a72f4
extern "C" ARM void func_ov017_021a72f4(void* unused, int val) {
    GameResources* resources = GetGameResources();
    TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
    char* node = (char*)resources->fieldTasks_[38];
    func_ov017_021a7328(node);
    *(int*)(node + 0xc) = val;
    func_020469b4(list, (TailNode020469b4*)node);
}
