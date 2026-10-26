#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void*, int);
extern "C" void func_ov000_02170b0c(void*, int);

struct Struct021754fc { char pad[0x6c]; signed char unknown_6c_[4]; };

// USA: func_ov000_021754fc
extern "C" ARM void func_ov000_021754fc(struct Struct021754fc* obj, int b) {
    for (unsigned char i = 0; i < 4; i++) {
        void* node = func_ov000_02161318(obj, obj->unknown_6c_[i]);
        if (node) {
            func_ov000_02170b0c(node, b);
        }
    }
}
