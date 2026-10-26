#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" void func_ov017_0218e674(GameResources* ov);
extern "C" void func_ov017_021a1ad0(GameResources* ov);
extern "C" void func_ov017_02197394(GameResources*);

struct EventAdvanceGate {
    unsigned char unknown0[0xb];
    unsigned char flag;
};

// USA: func_ov017_0218d06c
extern "C" ARM void func_ov017_0218d06c(GameResources* resources) {
    if (TestFlags00(resources, 0x800) != 0) return;
    int var0 = 0;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x26) {
        func_ov017_0218e674(resources);
        var0 = 1;
    }
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x26 ||
        ((EventAdvanceGate*)resources->fieldTasks_[13])->flag == 0) {
        func_ov017_021a1ad0(resources);
    }
    if (var0 != 0) {
        func_ov017_02197394(resources);
    }
}
