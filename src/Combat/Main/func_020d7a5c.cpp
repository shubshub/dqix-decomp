#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct ResetObj020d7a5c {
    unsigned char pad[(IS_JPN ? 0xf0 : 0x150)];
    unsigned char flags;
    unsigned char pad2;
    unsigned short unknown_152_;
};

// USA: func_020d7a5c
extern "C" ARM void func_020d7a5c(struct ResetObj020d7a5c* o) {
    memset(o, 0, (IS_JPN ? 0xf0 : 0x150));
    o->flags &= ~0x3f;
    o->unknown_152_ = 0;
    o->flags &= ~0x40;
    o->flags &= ~0x80;
}
