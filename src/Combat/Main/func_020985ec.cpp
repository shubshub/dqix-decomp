#include <globaldefs.h>

struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};

// USA: func_020985ec
extern "C" ARM struct Elem020985ec* func_020985ec(struct Elem020985ec* arr, int val) {
    int i;
    if (val < 0) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        if ((arr[i].key >> 2) == val) {
            return &arr[i];
        }
    }
    return 0;
}
