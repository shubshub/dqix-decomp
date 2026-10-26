#include <globaldefs.h>
#include "std_library_functions.h"

struct BitArrayObj0205e854 {
    unsigned char pad[0x124];
    struct {
        unsigned char pad[0x1400];
        unsigned char bits[0x20];
    } sub;
};

// USA: func_0205e854
extern "C" ARM void* func_0205e854(struct BitArrayObj0205e854* obj) {
    return memset(obj->sub.bits, 0xff, 0x20);
}
