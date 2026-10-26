#include <globaldefs.h>

struct Struct_020e38e4 {
    unsigned int val;
    unsigned char tag;
};

// USA: func_020e38e4
extern "C" ARM int func_020e38e4(struct Struct_020e38e4* entries, int tag, int val) {
    int i;
    for (i = 0; i < 4; i++, entries++) {
        if (entries->tag == tag) {
            if (entries->val == val || val == -1) {
                return i;
            }
        }
    }
    return -1;
}
