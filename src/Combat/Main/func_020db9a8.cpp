#include <globaldefs.h>

struct Struct_020db264 {
    unsigned char pad[0x54];
    unsigned char unknown_54_;
};

// USA: func_020db9a8
extern "C" ARM int func_020db9a8(struct Struct_020db264* obj) {
    if (obj->unknown_54_ == 0) {
        return (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    }
    return 0;
}
