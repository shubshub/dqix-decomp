#include <globaldefs.h>

struct Struct_02098eac {
    char pad[0xc];
    unsigned int field0 : 4;
    unsigned int nibble : 4;
    char pad2[0xe8 - 0x10];
};

// USA: func_02098eac
extern "C" ARM int func_02098eac(struct Struct_02098eac* arr) {
    int count = 0;
    int i;
    for (i = 0; i < 30; i++) {
        if (arr[i].nibble == 0xa) {
            count++;
        }
    }
    return count;
}
