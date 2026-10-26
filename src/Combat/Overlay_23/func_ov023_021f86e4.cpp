#include <globaldefs.h>

struct Struct_ov023_021f86e4 {
    char pad[0x3a];
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
};

// USA: func_ov023_021f86e4
extern "C" ARM unsigned int func_ov023_021f86e4(struct Struct_ov023_021f86e4 *obj) {
    return obj->hiNibble;
}
