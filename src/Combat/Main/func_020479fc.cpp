#include <globaldefs.h>

struct Struct_020479fc_2 {
    char unk0[8];
    int index;
};

struct Struct_020479fc_3 {
    int unk0;
    struct Struct_020479fc_2* entries;
};

struct Struct_020479fc {
    char unk0[8];
    unsigned char* unknown_8_;
    struct Struct_020479fc_3* tableA;
    char unk10[0x60];
    int unknown_70_;
    int unknown_74_;
    char unknown_78_[0xc];
    unsigned char flag : 1;
};

// USA: func_020479fc
extern "C" ARM int func_020479fc(struct Struct_020479fc* root) {
    struct Struct_020479fc_2* var0;
    if (!root->flag) {
        return 0;
    }
    var0 = &root->tableA[root->unknown_74_].entries[root->unknown_70_];
    return root->unknown_8_[var0->index * 8];
}
