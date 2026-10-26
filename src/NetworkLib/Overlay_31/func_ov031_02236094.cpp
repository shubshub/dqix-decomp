#include <globaldefs.h>

extern "C" int memcmp(unsigned char* a, unsigned char* b, int len);
extern "C" void func_ov031_0221b19c(int val, unsigned char* out);

struct Struct_ov031_02236094 {
    unsigned char bytes[0xf0];
};

struct Struct_ov031_02236094_2 {
    Struct_ov031_02236094 data;
    unsigned char pad[0x10];
};

struct Struct_ov031_02236094_3 {
    Struct_ov031_02236094_2 slots[4];
    Struct_ov031_02236094 current;
    unsigned char mask[4];
    unsigned char index;
    unsigned char unknown_4f5_;
    unsigned char unknown_4f6_;
};

extern Struct_ov031_02236094_3* data_ov031_02290cfc;
extern unsigned char data_ov031_02249248;

// USA: func_ov031_02236094
extern "C" ARM void func_ov031_02236094(unsigned char param) {
    Struct_ov031_02236094_3* g = data_ov031_02290cfc;
    unsigned char* slot = g->slots[param].data.bytes;

    g->current = g->slots[param].data;
    g->index = param;

    if (memcmp(slot + 0xc0, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc->unknown_4f5_ = 0;
    } else {
        data_ov031_02290cfc->unknown_4f5_ = 1;
    }

    if (memcmp(slot + 0xc8, &data_ov031_02249248, 4) != 0 ||
        memcmp(slot + 0xcc, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc->unknown_4f6_ = 0;
    } else {
        data_ov031_02290cfc->unknown_4f6_ = 1;
    }

    func_ov031_0221b19c(slot[0xd0], data_ov031_02290cfc->mask);
}
