#include <globaldefs.h>

struct Struct_0205b190 {
    char unk[0x4];
    unsigned short flag;
};

struct Struct_0205af18 {
    char unk[4];
    struct Struct_0205b190* inner;
};

// USA: func_0205b190
extern "C" ARM int func_0205b190(int unused, struct Struct_0205af18* obj) {
    if (obj == 0) {
        return 0;
    }
    return ((unsigned int)obj->inner->flag >> 12) & 0xf;
}
