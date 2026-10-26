#include <globaldefs.h>

struct Struct_ov012_0218558c_2 {
    int field0;
    int field4;
    char* base;
};

struct Struct_ov012_0218558c {
    char* entries[7];
    unsigned char field1c;
    unsigned char unknown_1d_;
    unsigned char count;
};

// USA: func_ov012_0218558c
extern "C" ARM int func_ov012_0218558c(struct Struct_ov012_0218558c_2* owner, struct Struct_ov012_0218558c* table) {
    int i = 0;
    while (i < table->count) {
        int var1 = 1;
        int offset = (int)(table->entries[i] - (char*)0);
        char* value;
        if (offset != -1 && owner->base != 0) {
            var1 = 0;
        }
        if (var1) {
            value = 0;
        } else {
            value = owner->base + offset;
        }
        table->entries[i] = value;
        i++;
    }
    return 1;
}
