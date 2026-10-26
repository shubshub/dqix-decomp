#include <globaldefs.h>

struct Struct_02047a5c_2 {
    unsigned char value;
    char pad[7];
};

struct Struct_02047a5c {
    char pad0[0x8];
    struct Struct_02047a5c_2* entries;
    char pad2[0x78];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

// USA: func_02047a5c
extern "C" ARM unsigned char func_02047a5c(struct Struct_02047a5c* owner, int index) {
    if (owner->flag) {
        return owner->entries[index].value;
    }
    return 0;
}
