#include <globaldefs.h>

struct Struct_02052e2c_2 {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052e2c {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Struct_02052e2c_2* table;
};

// USA: func_02052e2c
extern "C" ARM short* func_02052e2c(struct Field150Holder02052e2c* obj) {
    struct Struct_02052e2c_2* table = obj->table;
    return table ? &table->entries[0] : NULL;
}
