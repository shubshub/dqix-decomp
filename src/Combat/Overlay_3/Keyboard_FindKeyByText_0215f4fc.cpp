#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02001aec(const char* arg0, const char* arg1, unsigned int arg2);

struct Struct_ov003_0215f4fc {
    int unknown_0_;
    const char* unknown_4_;
    char unknown_8_[0xc];
};

struct Struct_ov003_0215f4fc_2 {
    Struct_ov003_0215f4fc* unknown_0_;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_ov003_0215f4fc_3 {
    int unknown_0_;
    Struct_ov003_0215f4fc_2* unknown_4_;
};

// Overlay 3, originally func_ov003_0215f4fc (USA/EUR 0x0215f4fc; JPN not identified)
extern "C" ARM NamedEntry* Keyboard_FindKeyByText(NamedEntryOwner* self, const char* name) {
    unsigned int len;
    NamedEntry* entry;
    short i;
    short count;
    len = strlen(name);
    count = self->table->count;
    entry = self->table->entries;
    for (i = 0; i < count; i++, entry++) {
        if (entry->name != 0 && func_02001aec(entry->name, name, len) == 0) {
            return entry;
        }
    }
    return 0;
}
