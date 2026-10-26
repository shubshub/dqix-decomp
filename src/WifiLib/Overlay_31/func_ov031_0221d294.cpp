#include <globaldefs.h>

struct Struct_ov031_0221d294_2 {
    int nameLength;
    char name[0x20];
    int active;
    unsigned int unknown_28_;
    char label[0x24];
    unsigned int flags;
};

struct Struct_ov031_0221d294 {
    unsigned int count;
    Struct_ov031_0221d294_2 entries[64];
};

extern "C" int func_ov031_0221e650(const char* text);
extern "C" int func_ov031_0221e4fc(unsigned char* a, unsigned char* b, int n);
extern char data_ov031_0224b0d0[];

// USA: func_ov031_0221d294
extern "C" THUMB int func_ov031_0221d294(Struct_ov031_0221d294* table) {
    int result = 0;
    int found = 0;
    int count = table->count;
    int i;
    if (table->count == 0) {
        return 5;
    }
    if (table->count > 64) {
        count = 64;
    }
    for (i = 0; i < count; i++) {
        if ((table->entries[i].flags & 1) != 0 &&
            table->entries[i].nameLength == func_ov031_0221e650(data_ov031_0224b0d0) &&
            func_ov031_0221e4fc((unsigned char*)table->entries[i].name, (unsigned char*)data_ov031_0224b0d0,
                                func_ov031_0221e650(data_ov031_0224b0d0)) == 0) {
            found++;
        }
    }
    if (found > 1) {
        result = 4;
    }
    if (found == 0) {
        result = 5;
    }
    return result;
}
