#include <globaldefs.h>

struct Struct_02098a84 {
    char pad[0x1b68];
    unsigned int arr[3];
};

// USA: func_02098e3c
extern "C" ARM int func_02098e3c(struct Struct_02098a84* s, int val) {
    int i;
    for (i = 0; i < 3; i++) {
        if (val == s->arr[i]) {
            return 1;
        }
    }
    return 0;
}
