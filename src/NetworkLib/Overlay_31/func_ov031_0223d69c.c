#include <globaldefs.h>

typedef struct Struct_ov031_0223d69c_2 {
    unsigned short x;
    unsigned short y;
} Struct_ov031_0223d69c_2;

typedef struct Struct_ov031_0223d69c {
    char padding[0x28];
    Struct_ov031_0223d69c_2 primary;
    Struct_ov031_0223d69c_2 unknown_2c_;
    char unknown_30_[8];
    unsigned char selected:1;
    unsigned char unknown_38_1_:7;
} Struct_ov031_0223d69c;

typedef struct Struct_ov031_02290d40_10 {
    int field0;
    Struct_ov031_0223d69c* inner;
} Struct_ov031_02290d40_10;

extern Struct_ov031_02290d40_10 data_ov031_02290d40;

static inline int inline_ov031_0223d69c(void) {
    return (*(unsigned short*)0x027fffa8 & 0x8000) >> 15;
}

// USA: func_ov031_0223d69c
ARM int func_ov031_0223d69c(Struct_ov031_0223d69c_2* pair) {
    Struct_ov031_0223d69c* input;
    if (inline_ov031_0223d69c()) return 0;
    input = data_ov031_02290d40.inner;
    if (!input->selected) {
        *pair = input->unknown_2c_;
        return 0;
    }
    *pair = input->primary;
    return 1;
}
