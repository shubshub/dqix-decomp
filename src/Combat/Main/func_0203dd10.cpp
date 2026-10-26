#include <globaldefs.h>

struct Struct_0203dd10 {
    unsigned char pad[0xc];
    int slots[0x20];
};

// USA: func_0203dd10
extern "C" ARM void func_0203dd10(Struct_0203dd10* obj, unsigned int index, int value) {
    if (index < 0x20) obj->slots[index] = value;
}
