#include <globaldefs.h>

struct Struct_ov014_02188d48 {
    unsigned short key_;
    unsigned short unknown_2_0_ : 12;
    unsigned short unknown_3_4_ : 4;
};

struct Struct_ov014_02188d48_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 11;
    unsigned short unknown_3_4_ : 4;
};

struct Struct_ov014_02188d48_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned int unknown_8_0_ : 31;
    unsigned int relocated_ : 1;
    Struct_ov014_02188d48* entries_;
    char* unknown_10_;
};

static inline unsigned int inline_ov014_0218934c(unsigned int size) {
    return (size + 3) & ~3;
}

// USA: func_ov014_0218934c
extern "C" ARM unsigned int func_ov014_0218934c(Struct_ov014_02188d48_3* self) {
    unsigned int entriesSize = self->unknown_0_ * sizeof(Struct_ov014_02188d48);
    unsigned int size = self->unknown_2_ * sizeof(Struct_ov014_02188d48_2) + self->unknown_4_ * sizeof(unsigned short) + entriesSize;
    return inline_ov014_0218934c(size) - entriesSize + self->unknown_6_ * sizeof(char*) + entriesSize;
}
