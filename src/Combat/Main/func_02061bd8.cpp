#include <globaldefs.h>

struct Struct_02061bd8 {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};

struct Struct_0205faf4_11 {
#if defined(jpn)
    unsigned char pad[0x144];
#else
    unsigned char pad[0x150];
#endif
    struct Struct_02061bd8* sub;
};

// USA: func_02061bd8
extern "C" ARM int func_02061bd8(struct Struct_0205faf4_11* obj) {
    struct Struct_02061bd8* sub = obj->sub;
    if (sub != NULL) {
        return sub->nibble != 0;
    }
    return 0;
}
