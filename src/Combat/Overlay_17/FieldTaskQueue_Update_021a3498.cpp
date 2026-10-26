#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "World/FieldTask.h"

struct Struct_02046968;
extern "C" void func_02046968(struct Struct_02046968* list);
extern "C" void FieldTask_Update(void* queue, void* task);

struct FieldTaskQueueKindList {
    int kinds[18];  // field task kinds, ending in 0xffff
};
extern struct FieldTaskQueueKindList FieldTaskQueue_countdownKinds;

// Overlay 17, originally ClearIfMatchAndFinalize_021a3498 (USA/EUR 0x021a3498, JPN 0x021a3f0c)
extern "C" ARM void FieldTaskQueue_Update(FieldTaskQueue* self) {
#if defined(jpn)
 enum {regionalOffset0=0x134};
#else
 enum {regionalOffset0=0x354};
#endif
    void* head = self->head;
    if (head != NULL && *((unsigned char*)head + 1) != 0) {   // done
        int resources = (int)GetGameResources();
        if (resources != 0) {
            struct FieldTaskQueueKindList countdownKinds = FieldTaskQueue_countdownKinds;
            int* countdownKind = countdownKinds.kinds;
            while (*countdownKind != 0xffff) {
                signed char kind = *(signed char*)self->head;
                if (kind == *countdownKind) {
                    *((unsigned char*)(long)resources + 0x4000 + regionalOffset0) = 0xc;
                    break;
                }
                countdownKind++;
            }
        }
    }
    func_02046968((struct Struct_02046968*)self);
    FieldTask_Update(self, self->head);
}
