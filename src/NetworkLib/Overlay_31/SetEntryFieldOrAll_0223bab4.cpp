#include <globaldefs.h>

struct Struct_ov031_0223bab4_2 {
    unsigned int unknown_0_;
    unsigned int w1;
};

struct Struct_ov031_0223bab4 {
    unsigned char pad[0x8];
    Struct_ov031_0223bab4_2* entries;
    unsigned char count;
};

// USA: func_ov031_0223bab4
extern "C" ARM void func_ov031_0223bab4(void* obj, int idx, int value, int flag) {
    Struct_ov031_0223bab4* table = (Struct_ov031_0223bab4*)obj;
    Struct_ov031_0223bab4_2* arr = table->entries;
    unsigned int mask = 0xc1fffcff;
    if (idx >= 0) {
        if (value != 0x100 && value != 0x300) {
            unsigned int v = arr[idx].unknown_0_ & mask;
            arr[idx].unknown_0_ = v | value;
        } else {
            unsigned int v = arr[idx].unknown_0_ & mask;
            arr[idx].unknown_0_ = (v | value) | (flag << 0x19);
        }
        return;
    }
    for (idx = 0; idx < table->count; idx++) {
        if (value != 0x100 && value != 0x300) {
            unsigned int v = arr[idx].unknown_0_ & mask;
            arr[idx].unknown_0_ = v | value;
        } else {
            unsigned int v = arr[idx].unknown_0_ & mask;
            arr[idx].unknown_0_ = (v | value) | (flag << 0x19);
        }
    }
}
