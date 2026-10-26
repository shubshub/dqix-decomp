#include <globaldefs.h>

struct RingBuffer020457e8 {
    char unk0[0x186c];
    int slots[4];
    char unknown_187c_[0x131];
    signed char cursor;
};

// USA: func_020457e8
extern "C" ARM void func_020457e8(struct RingBuffer020457e8* arg0, int value) {
    arg0->slots[arg0->cursor] = value;
    arg0->cursor = arg0->cursor + 1;
    arg0->cursor = arg0->cursor % 4;
}
