#include <globaldefs.h>

struct Struct_02052df8_2 {
    char pad[0x488];
    short entries[1];
};
struct Struct_02052df8 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Struct_02052df8_2* table;
};

// USA: func_02052df8
extern "C" ARM int func_02052df8(struct Struct_02052df8* obj, int index) {
    struct Struct_02052df8_2* table = obj->table;
    return table ? table->entries[index] : -1;
}
