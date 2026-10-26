#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);

struct Struct_020ab9c0 {
    int hdr;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    char pad[14];
};

// USA: func_020ab9c0
extern "C" ARM int func_020ab9c0(int flag) {
    int id = flag ? 0x8010 : 0x10;
    if (g_keyManager.TestKeysHeld(0x2000)) {
        return 2;
    }

    struct Struct_020ab9c0 buf;
    if (!func_02075910(id, &buf, 0x14, 0)) {
        return 1;
    }
    void* p = &buf;
    if (func_01ff85b8((char*)p + 4, 0x10) != buf.hdr) {
        return 2;
    }
    if (buf.unknown_5_ == 0) {
        return 3;
    }
    return (buf.unknown_4_ == 1) ? 4 : 0;
}
