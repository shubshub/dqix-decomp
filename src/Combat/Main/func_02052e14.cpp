#include <globaldefs.h>

struct Struct_02052e14_2 {
    char pad[0x488];
    short entries[1];
};
struct Field150Holder02052e14 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Struct_02052e14_2* table;
};

// USA: func_02052e14
extern "C" ARM short* func_02052e14(struct Field150Holder02052e14* obj) {
    struct Struct_02052e14_2* table = obj->table;
    return table ? &table->entries[0] : NULL;
}
