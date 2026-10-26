#include <globaldefs.h>

extern "C" int func_02098268(int a, int x);

struct Struct_0203d028_12 {
    char pad0[0xc];
    unsigned int lo : 24;
    unsigned int val : 6;
    unsigned int hi : 2;
    char pad10[0xe8 - 0x10];
};

// USA: func_0209854c
extern "C" ARM struct Struct_0203d028_12* func_0209854c(struct Struct_0203d028_12* list, int target) {
    int i;
    if (func_02098268((int)list, target) == 0) return 0;
    for (i = 0; i < 0x1e; i++) {
        if (target == list[i].val) return &list[i];
    }
    return 0;
}
