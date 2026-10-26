#include <globaldefs.h>

struct Struct_0205e57c_6 {
    unsigned char pad[0x124];
    struct {
        unsigned char pad[0x1400];
        unsigned char bits[0x20];
    } sub;
};

// USA: func_0205e830
extern "C" ARM int func_0205e830(struct Struct_0205e57c_6* obj, int index) {
    return (1 << (index % 8)) & obj->sub.bits[(unsigned int)index >> 3];
}
