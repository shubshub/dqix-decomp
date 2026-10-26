#include <globaldefs.h>

struct ThreeByteStruct {
    char pad[0x224];
    unsigned char unknown_224_;
    unsigned char unknown_225_;
    unsigned char unknown_226_;
};

// USA: func_020966cc
extern "C" ARM void func_020966cc(struct ThreeByteStruct* s) {
    s->unknown_224_ = 0;
    s->unknown_225_ = 0;
    s->unknown_226_ = 0;
}
