#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020da034 {
    unsigned char pad[8];
    unsigned short unknown_8_;
    unsigned char pad2[2];
    int slots[1];
};

// USA: func_020da034
extern "C" ARM void func_020da034(Struct_020da034* mgr, int index) {
    ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(mgr->slots[index]));
    mgr->slots[index] = -1;
    mgr->unknown_8_ &= ~(1 << index);
}
