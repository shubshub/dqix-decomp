#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020dbdc0 {
    char pad[0xc];
    int unknown_c_;
    int unknown_10_;
};

static inline void inline_020dbf70(int& taskId) {
    BackgroundLoader::GetInstance()->RemoveTask(taskId);
    taskId = -1;
}

// USA: func_020dbf70
extern "C" ARM void func_020dbf70(struct Struct_020dbdc0* o) {
    if (o->unknown_c_ < 0) return;
    inline_020dbf70(o->unknown_c_);
    o->unknown_10_ = 0;
}
