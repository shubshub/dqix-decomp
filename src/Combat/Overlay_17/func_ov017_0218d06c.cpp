#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" void func_ov017_0218e674(GameResources* ov);
extern "C" void func_ov017_021a1ad0(GameResources* ov);
void AdvanceCombatantsInRange_02197394(GameResources*);

struct Struct_ov017_0218d06c {
    unsigned char unknown_0_[0xb];
    unsigned char unknown_b_;
};

// USA: func_ov017_0218d06c
extern "C" ARM void func_ov017_0218d06c(GameResources* resources) {
    if (TestFlags00(resources, 0x800) != 0) return;
    int shouldAdvance = 0;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x26) {
        func_ov017_0218e674(resources);
        shouldAdvance = 1;
    }
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x26 ||
        ((EventAdvanceGate*)resources->fieldTasks_[13])->flag == 0) {
        func_ov017_021a1ad0(resources);
    }
    if (var0 != 0) {
        func_ov017_02197394(arg0);
    }
}
