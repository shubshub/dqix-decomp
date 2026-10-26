#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
};

extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);

// USA: func_020e3ad0
extern "C" ARM int func_020e3ad0(struct TagValueEntry020e385c* entries, int tag, int val) {
    struct TagValueEntry020e385c* e = func_020e385c(entries, tag, val);
    if (e == NULL) {
        return 1;
    }
    if (e->unknown_5_ != 0) {
        if (e->unknown_5_ == e->unknown_6_) {
            return 1;
        }
    }
    return 0;
}
