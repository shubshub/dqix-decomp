#include <globaldefs.h>

struct Struct_ov023_021f86b8 {
    char pad[0x44];
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
    unsigned char flag : 1;
};

// USA: func_ov023_021f86b8
extern "C" ARM unsigned int func_ov023_021f86b8(struct Struct_ov023_021f86b8* obj) {
    unsigned char result;
    if (obj->flag) {
        result = 5;
    } else {
        result = obj->hiNibble;
    }
    return result & 0xff;
}
