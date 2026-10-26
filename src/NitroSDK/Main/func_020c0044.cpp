#include <globaldefs.h>

extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);

#include "NitroSDK/Filesystem/NitroVM.h"
bool NitroVM_PrepareReadFileByID(NitroVM* vm, NitroFileAccessor accessor);
extern "C" NitroFileAccessor func_020bd88c(void);

extern "C" int func_020bd774(unsigned int index);

struct Struct_020c0044 { char pad[0xa4]; int unknown_a4_; };

// USA: func_020c0044
extern "C" ARM int func_020c0044(struct Struct_020c0044* obj, unsigned int index) {
    if (func_020bd7c4(index, (char*)obj + 0xa8, 0x40, 0) != 0x40) {
        return 0;
    }
    if (NitroVM_PrepareReadFileByID((NitroVM*)((char*)obj + 0x5c), func_020bd88c()) == 0) {
        return 0;
    }
    obj->unknown_a4_ = func_020bd774(index);
    return 1;
}
