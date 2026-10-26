#include <globaldefs.h>

struct Struct_02066cc0 {
    short x;
    short y;
};

struct Struct_02066a6c_2 {
    char pad0[0x440];
    struct Struct_02066cc0* unknown_440_;
};

// USA: func_02066cc0
extern "C" ARM void func_02066cc0(struct Struct_02066a6c_2* obj, short* outX, short* outY) {
    if (obj->unknown_440_ != NULL) {
        *outX = obj->unknown_440_->x;
        *outY = obj->unknown_440_->y;
    }
}
