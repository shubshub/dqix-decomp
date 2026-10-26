#include <globaldefs.h>

struct Struct_020687f8_2 {
    int unk[2];
    unsigned int lo : 26;
    unsigned int flag : 1;
    unsigned int hi : 5;
};

struct Struct_020687f8 {
    char pad[0x20];
    struct Struct_020687f8_2* unknown_20_;
};

// USA: func_020687f8
extern "C" ARM int func_020687f8(int unused, struct Struct_020687f8* holder) {
    struct Struct_020687f8_2* p = holder->unknown_20_;
    if (p != NULL) {
        return p->flag == 0;
    }
    return 0;
}
