#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov000_0216fd38 {
    int taskId;
    unsigned char pad[0xa0 - 0x4];
    unsigned char unknown_a0_;
};

// USA: func_ov000_0216fd38
extern "C" ARM int func_ov000_0216fd38(struct Struct_ov000_0216fd38* obj) {
    if (obj->unknown_a0_) return 1;
    if (obj->taskId < 0) return 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(obj->taskId) == 0) {
        return 0;
    }
    obj->unknown_a0_ = 1;
    return 1;
}
