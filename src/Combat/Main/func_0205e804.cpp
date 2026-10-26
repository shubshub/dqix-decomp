#include <globaldefs.h>

struct BitArrayObj0205e804 {
    unsigned char pad[0x124];
    struct {
        unsigned char pad[0x1400];
        unsigned char bits[0x20];
    } sub;
};

// USA: func_0205e804
extern "C" ARM void func_0205e804(struct BitArrayObj0205e804* obj, int index) {
    obj->sub.bits[(unsigned int)index >> 3] &= ~(1 << (index % 8));
}
