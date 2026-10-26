#include <globaldefs.h>

struct Struct_ov025_021ed344 {
    char pad[0x160];
    unsigned short unknown_160_;
};

// USA: func_ov025_021ed344
extern "C" ARM void func_ov025_021ed344(struct Struct_ov025_021ed344* obj, int val) {
    obj->unknown_160_ = val;
}
