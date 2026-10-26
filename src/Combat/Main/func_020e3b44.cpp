#include <globaldefs.h>

struct Struct_020e3b44 {
    unsigned int val;
    unsigned char tag;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char pad;
};

// USA: func_020e3b44
extern "C" ARM void func_020e3b44(struct Struct_020e3b44* entries, int index, struct Struct_020e3b44 entry) {
    if (index >= 0 && index < 4) {
        entries[index].val = entry.val;
        entries[index].tag = entry.tag;
        entries[index].unknown_5_ = entry.unknown_5_;
        entries[index].unknown_6_ = entry.unknown_6_;
    }
}
