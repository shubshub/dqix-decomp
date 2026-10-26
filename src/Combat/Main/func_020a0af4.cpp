#include <globaldefs.h>

struct S_a0af4 {
    short* keys;
    signed char* values;
    short count;
};

// USA: func_020a0af4
extern "C" ARM int func_020a0af4(struct S_a0af4* p, int key) {
    short* keys = p->keys;
    short count = p->count;
    short i;
    if (key < 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (key == keys[i]) {
            return i;
        }
    }
    return -1;
}
