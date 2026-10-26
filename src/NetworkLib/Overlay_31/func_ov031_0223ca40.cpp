#include <globaldefs.h>

struct Struct_ov031_0223ca40_2 {
    void* unknown_0_;
    void (*unknown_4_)(void*, int);
};

struct Struct_ov031_0223ca40 {
    char padding[0x14];
    Struct_ov031_0223ca40_2* dispatch;
};

// USA: func_ov031_0223ca40
extern "C" ARM void func_ov031_0223ca40(void* obj, int unused) {
    ((Struct_ov031_0223ca40*)obj)->dispatch->unknown_4_(obj, unused);
}
