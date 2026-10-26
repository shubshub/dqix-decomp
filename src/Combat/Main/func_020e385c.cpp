#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};

// USA: func_020e385c
extern "C" ARM struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val) {
    int i;
    for (i = 0; i < 4; i++, entries++) {
        if (entries->tag == tag) {
            if (entries->val == val || val == -1) {
                return entries;
            }
        }
    }
    return NULL;
}
