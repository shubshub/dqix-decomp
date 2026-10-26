#include <globaldefs.h>

struct Struct_020886f8 {
    char unk[0x18];
    unsigned int flags;
    char unk2[6];
    unsigned short pad0 : 9;
    unsigned short kind : 3;
    unsigned short pad1 : 4;
};

// USA: func_020886f8
extern "C" ARM int func_020886f8(struct Struct_020886f8* obj) {
    if (obj->flags & 0x80) {
        if (obj->kind == 2) {
            return 1;
        }
    }
    return 0;
}
