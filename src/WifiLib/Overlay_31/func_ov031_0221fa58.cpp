#include <globaldefs.h>

struct Struct_ov031_0224f670_11 {
    char pad[0x68];
    int unknown_68_;
    int unknown_6c_;
};
extern Struct_ov031_0224f670_11 data_ov031_0224f670;
extern void* data_ov031_0224f6f4[4];

// USA: func_ov031_0221fa58
extern "C" THUMB void func_ov031_0221fa58(int event, int) {
    Struct_ov031_0224f670_11* state = &data_ov031_0224f670;
    int index = state->unknown_68_;
    int next = index + 1;
    int var3 = state->unknown_6c_;
    if (next != var3 && index != var3 + 3) {
        data_ov031_0224f6f4[index] = (void*)event;
        state->unknown_68_ = next;
        if (next >= 4) state->unknown_68_ = 0;
    }
}
