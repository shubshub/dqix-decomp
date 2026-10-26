#include <globaldefs.h>

struct Struct_0200173c {
    unsigned int unknown_0_0_ : 2;
    unsigned int unknown_0_2_ : 3;
    unsigned int unknown_0_5_ : 2;
    unsigned int unknown_0_7_ : 3;
    unsigned int unknown_1_2_ : 2;
    unsigned int unknown_1_4_ : 1;
};

struct Struct_020eebe0 {
    unsigned long handle;
    Struct_0200173c mode;
    unsigned char rest[0x44];
};

extern Struct_020eebe0 data_020eebe0[];
extern "C" int func_02001878(Struct_020eebe0* file);

// USA: func_0200173c
extern "C" ARM int func_0200173c(void) {
    int result = 0;
    Struct_020eebe0* file = &data_020eebe0[0];
    int var2 = 1;

    do {
        if (file->mode.unknown_0_7_ != 0) {
            if (func_02001878(file) != 0) {
                result = -1;
            }
        }
        if (var2 < 3) {
            file = &data_020eebe0[var2++];
        } else {
            file = 0;
        }
    } while (file != 0);

    return result;
}
