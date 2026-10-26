#include <globaldefs.h>

struct Struct_020687cc_2 {
    int unk[2];
    unsigned int lo : 26;
    unsigned int flag : 1;
    unsigned int hi : 5;
};

struct Struct_020687cc {
    char pad[0x18];
    struct Struct_020687cc_2* unknown_18_;
};

// USA: func_020687cc
extern "C" ARM int func_020687cc(int unused, struct Struct_020687cc* holder) {
    struct Struct_020687cc_2* p = holder->unknown_18_;
    if (p != NULL) {
        return p->flag == 0;
    }
    return 0;
}
