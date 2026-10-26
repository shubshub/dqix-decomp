#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02220390(void*);

struct Struct_ov031_022203f0 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
};

// USA: func_ov031_022203f0
extern "C" THUMB int func_ov031_022203f0(struct Struct_ov031_022203f0* self) {
    self->unknown_0_ = 0;
    self->unknown_1_ = 0;
    self->unknown_2_ = 0;
    self->unknown_3_ = 0;
    self->unknown_4_ = 0;
    self->unknown_5_ = 0;
    self->unknown_6_ = 0;
    self->unknown_7_ = 0;

    int size = (int)func_ov031_02220390((unsigned char*)self + 8) - (int)self;
    ((unsigned short*)self)[0] = (unsigned short)(size - 8);
    return size;
}
