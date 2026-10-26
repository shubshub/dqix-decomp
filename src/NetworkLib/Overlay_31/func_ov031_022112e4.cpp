#include <globaldefs.h>

struct Struct_ov031_0224e590 {
    int* state;
};

extern Struct_ov031_0224e590 data_ov031_0224e590;

// USA: func_ov031_022112e4
extern "C" ARM void* func_ov031_022112e4(void) {
    int* state = data_ov031_0224e590.state;
    if (state != NULL) {
        if (*(int*)((char*)state + 0x30) == 0) {
            return *(void**)((char*)state + 0x2c);
        }
    }
    return NULL;
}
