#include <globaldefs.h>

struct Struct_02001878_2 {
    unsigned int unknown_0_0_ : 2;
    unsigned int unknown_0_2_ : 3;
    unsigned int unknown_0_5_ : 2;
    unsigned int unknown_0_7_ : 3;
    unsigned int unknown_1_2_ : 2;
    unsigned int unknown_1_4_ : 1;
};

struct Struct_02001878 {
    unsigned int unknown_0_0_ : 3;
    unsigned int unknown_0_3_ : 1;
    unsigned char unknown_1_;
    unsigned char error;
};

struct Struct_02001878_3 {
    unsigned long handle;
    Struct_02001878_2 mode;
    Struct_02001878 state;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_[2];
    unsigned short unknown_10_[2];
    unsigned int position;
    unsigned char* buffer;
    unsigned int unknown_1c_;
    unsigned char* unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_;
    unsigned int unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    void* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
};

extern "C" int func_0200173c(void);
extern "C" int func_020017f0(Struct_02001878_3* file, unsigned int* length);

// USA: func_02001878
extern "C" ARM int func_02001878(Struct_02001878_3* file) {
    if (file == 0) {
        return func_0200173c();
    }

    if (file->state.error != 0 || file->mode.unknown_0_7_ == 0) {
        return -1;
    }

    if (file->mode.unknown_0_2_ == 1) {
        return 0;
    }

    if (file->state.unknown_0_0_ >= 3) {
        file->state.unknown_0_0_ = 2;
    }

    if (file->state.unknown_0_0_ == 2) {
        file->unknown_24_ = 0;
    }

    if (file->state.unknown_0_0_ != 1) {
        file->state.unknown_0_0_ = 0;
        return 0;
    }

    if (func_020017f0(file, 0) != 0) {
        file->state.error = 1;
        file->unknown_24_ = 0;
        return -1;
    }

    file->state.unknown_0_0_ = 0;
    file->position = 0;
    file->unknown_24_ = 0;
    return 0;
}
