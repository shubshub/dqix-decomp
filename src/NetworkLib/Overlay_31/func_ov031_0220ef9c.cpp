#include <globaldefs.h>

typedef void (*Type_ov031_0220ef9c)(void*, void*, void*, unsigned short);

struct Struct_ov031_0224e540_2 {
    char pad0[0x28];
    Type_ov031_0220ef9c unknown_28_;
};

extern struct Struct_ov031_0224e540_2 data_ov031_0224e540;

// USA: func_ov031_0220ef9c
extern "C" ARM void func_ov031_0220ef9c(char *arg) {
    Type_ov031_0220ef9c cb = data_ov031_0224e540.unknown_28_;
    if (cb == 0) {
        return;
    }
    unsigned short v = *(unsigned short*)(arg + 0x6);
    cb(arg + 0x1e, arg + 0x18, arg + 0x2c, v);
}
