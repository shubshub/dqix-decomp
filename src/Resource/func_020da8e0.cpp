#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020da8e0_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};
struct Struct_020da8e0 {
    char unknown_0_[8];
    int unknown_8_;
    char unknown_c_;
    unsigned char flags;
    unsigned char unknown_e_;
    char unknown_f_[5];
    Struct_020da8e0_2 slots[4];
};
extern "C" {
void func_020daa58(void*, void*, int, int);
void func_020dab68(void*, void*, unsigned int);
void func_020da2e4(void*);
}

extern "C" ARM int func_020da8e0(void* arg0)
{
    Struct_020da8e0* state = (Struct_020da8e0*)arg0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader)
        return 0;
    Struct_020da8e0_2* slot = state->slots;
    int var3 = 1;
    for (unsigned char index = 0; index < 4; ++index, ++slot) {
        int var5 = slot->unknown_8_;
        if (var5 != -1) {
            if (loader->GetTaskStatus(var5) == 0) {
                var3 = 0;
            } else {
                unsigned int length = 0;
                void* data = NULL;
                loader->GetLoadedFileByID(var5, &data, &length);
                switch (state->unknown_e_) {
                case 1:
                    func_020daa58(state, data, 3100, 3110);
                    break;
                case 2:
                    func_020daa58(state, data, 3200, 3210);
                    break;
                case 3:
                    func_020dab68(state, data, length);
                    break;
                }
                state->unknown_8_ = slot->unknown_0_;
                state->flags |= 4;
                loader->RemoveTask(var5);
                func_020da2e4(slot);
            }
        }
    }
    if (var3)
        state->flags &= ~1;
    return 1;
}
