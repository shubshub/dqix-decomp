#include <globaldefs.h>

struct Struct_020800fc_3 {
    char pad0[0x18];
    struct Struct_020800fc_3* f18;
    struct Struct_020800fc_3* f1c;
    struct Struct_020800fc_3* f20;
    struct Struct_020800fc_3* f24;
    char pad1[0x2a - 0x28];
    unsigned char unknown_2a_;
};

struct Struct_020800fc {
    unsigned int f0;
};

// USA: func_0208036c
extern "C" ARM struct Struct_020800fc_3* func_0208036c(void* unused, struct Struct_020800fc_3* start, int mode, struct Struct_020800fc* flags, unsigned char arg4) {
    struct Struct_020800fc_3* cur;
    struct Struct_020800fc_3* next;
    if (start == NULL) {
        return NULL;
    }
    cur = start;
    switch (mode) {
    case 0x40:
        while ((next = cur->f1c) != NULL) {
            if (next->unknown_2a_ & 0x2) {
                break;
            }
            cur = next;
        }
        break;
    case 0x80:
        while ((next = cur->f18) != NULL) {
            if (next->unknown_2a_ & 0x2) {
                break;
            }
            cur = next;
        }
        break;
    case 0x20:
        if (arg4) {
            flags->f0 |= 0x20;
        } else {
            while ((next = cur->f24) != NULL) {
                if (next->unknown_2a_ & 0x2) {
                    break;
                }
                cur = next;
            }
        }
        break;
    case 0x10:
        if (arg4) {
            flags->f0 |= 0x10;
        } else {
            while ((next = cur->f20) != NULL) {
                if (next->unknown_2a_ & 0x2) {
                    break;
                }
                cur = next;
            }
        }
        break;
    }
    return cur;
}
