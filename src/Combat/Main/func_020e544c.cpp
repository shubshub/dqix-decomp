#include <globaldefs.h>

struct Struct_020e53bc_3 {
    unsigned int field0;
};

// USA: func_020e544c
extern "C" ARM unsigned int func_020e544c(struct Struct_020e53bc_3* header) {
    return (header->field0 & 0xFFF) << 4;
}
