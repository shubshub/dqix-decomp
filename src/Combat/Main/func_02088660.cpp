#include <globaldefs.h>

struct Struct_02088660 {
    unsigned char pad0[0x18];
    unsigned int unknown_18_;
};

// USA: func_02088660
extern "C" ARM int func_02088660(struct Struct_02088660* obj) {
    return (obj->unknown_18_ & 0x80) != 0;
}
