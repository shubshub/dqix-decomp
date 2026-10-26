#include <globaldefs.h>

struct Struct_02042c68_2 {
    char unk0[0x186c];
    int slots[4];
};

// USA: func_02045824
extern "C" ARM void func_02045824(struct Struct_02042c68_2* arg0, int value, int index) {
    int i;
    if (index == -1) {
        for (i = 0; i < 4; i++) {
            arg0->slots[i] = value;
        }
    } else {
        arg0->slots[index] = value;
    }
}
