#include <globaldefs.h>

struct Struct_02053dd0_2 {
    char unk[0x14];
    int flags;
};

struct Struct_02053dd0_3 {
    char unk[0x8];
    int count;
};

struct Struct_02053dd0 {
    char unk[0x138];
    struct Struct_02053dd0_2* flagObj;
#if defined(jpn)
    char unk2[0x54];
#else
    char unk2[0x60];
#endif
    struct Struct_02053dd0_3* counter;
};

// USA: func_02053dd0
extern "C" ARM void func_02053dd0(struct Struct_02053dd0* obj) {
    struct Struct_02053dd0_3* counter = obj->counter;
    if (counter == 0 || (obj->flagObj->flags & 1) != 0) {
        return;
    }
    counter->count++;
}
