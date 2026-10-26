#include <globaldefs.h>

struct Struct_020ee798 {
    short key;
    short val;
};

extern struct Struct_020ee798 data_020ee798[];
extern struct Struct_020ee798 data_020ee7c8[];

struct Obj020dee58 {
    unsigned char pad[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int rest : 23;
};

// USA: func_020dee58
extern "C" ARM short func_020dee58(struct Obj020dee58* obj) {
    struct Struct_020ee798* entry;
    short key;
    if (obj == NULL) {
        return 0x13;
    }
    key = obj->unknown_8_4_;
    entry = data_020ee7c8;
    if (obj->unknown_8_0_ != 0) {
        key = obj->unknown_8_0_;
        entry = data_020ee798;
    }
    while (entry->key >= 0) {
        if (entry->key == key) {
            return entry->val;
        }
        entry++;
    }
    return 0x13;
}
