#include <globaldefs.h>

extern "C" void func_020891cc(void* obj);

struct Struct_02048b0c_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[0x10];
    unsigned int unknown_14_;
    char pad18[0xc];
    unsigned char unknown_24_;
};

struct Struct_02048b0c {
    unsigned int f0;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned char f8;
};

struct Struct_02048b0c_2 {
    char pad[0x130];
    struct Struct_02048b0c* status;
    unsigned int unknown_134_;
    struct Struct_02048b0c_3* stats;
};

// USA: func_02048b0c
extern "C" ARM void func_02048b0c(struct Struct_02048b0c_2* self, int flag) {
    self->status->f4 = self->stats->unknown_0_;
    self->status->unknown_6_ = self->stats->unknown_2_;

    int count;
    count = self->stats->unknown_24_;
    count = count - 1;
    if (count < 0) {
        count = 0;
    }
    if (flag != 0)
        self->status->f8 = count;
    else
        self->status->f8 = 0;

    self->status->f0 = 0;

    if ((self->stats->unknown_14_ & 2) != 0) {
        self->status->f0 |= 2;
    }
    if ((self->stats->unknown_14_ & 1) != 0) {
        self->status->f0 = 1;
    }
    if ((self->stats->unknown_14_ & 4) != 0) {
        self->status->f0 |= 4;
    }

    func_020891cc(self->stats);
}