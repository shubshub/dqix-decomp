#include <globaldefs.h>

struct Struct_02088514 {
    char unk[0x14];
    unsigned int flags;
    char unk2[0xa];
    unsigned short state : 2;
    unsigned short pad : 14;
};

// USA: func_02088514
extern "C" ARM int func_02088514(struct Struct_02088514* obj) {
    if (obj->flags & 0x2) {
        if (obj->state == 2) {
            return 1;
        }
    }
    return 0;
}
