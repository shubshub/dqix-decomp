#include <globaldefs.h>

struct Struct_ov031_0223ede0_2 {
    int flag;
    char pad[0x30];
};

extern "C" {
    int func_ov031_0223fe20(void*, void*, const char*, int);
}

// USA: func_ov031_02240050
extern "C" ARM int func_ov031_02240050(Struct_ov031_0223ede0_2* self, int b, int c) {
    if (self->flag != 0) {
        return 0;
    }
    return func_ov031_0223fe20((char*)self + 0x34, (void*)b, (const char*)c, 0x18);
}
