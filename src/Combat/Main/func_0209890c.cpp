#include <globaldefs.h>

extern "C" int memcmp(void* a, void* b, int n);

struct Struct_0209890c {
    unsigned char unknown0[0x14];
    unsigned char identity[6];
    unsigned char unknown_1a_[0x6c - 0x1a];
    unsigned int unknown_6c_0_ : 26;
    unsigned int unknown_6f_2_ : 1;
    unsigned int unknown_6f_3_ : 5;
    unsigned char unknown_70_[0xe8 - 0x70];
};

// USA: func_0209890c
extern "C" ARM int func_0209890c(void* arr, void* obj) {
    Struct_0209890c* records = static_cast<Struct_0209890c*>(arr);
    Struct_0209890c* candidate = static_cast<Struct_0209890c*>(obj);
    int i;
    if (!candidate->unknown_6f_2_) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        if (memcmp(records[i].identity, candidate->identity, sizeof(candidate->identity)) == 0) {
            return 0;
        }
    }
    return 1;
}
