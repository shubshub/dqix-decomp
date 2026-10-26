#include <globaldefs.h>

struct Struct_0207959c {
    unsigned char pad[0x17d];
    unsigned char flags;
};

// USA: func_0207959c
extern "C" ARM int func_0207959c(struct Struct_0207959c* obj, int mode) {
    unsigned char flags = obj->flags;
    if (flags & 8) {
        return ((unsigned char)(flags >> 4) & 3) == mode;
    }
    return 0;
}
