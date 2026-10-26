#include <globaldefs.h>

struct Struct_ov031_02222ddc_3 {
    unsigned long unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov031_0222408c {
    unsigned char padding0[0x60];
    Struct_ov031_02222ddc_3* sprite;
    unsigned char unknown_64_[0xb9];
    unsigned char channel;
};
extern Struct_ov031_0222408c* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_02224120(void*);
static inline void inline_ov031_0222408c(const Struct_ov031_02222ddc_3* sprite, unsigned long* x, unsigned long* y) {
    unsigned long attributes = sprite->unknown_0_;
    *x = (attributes & 0x1ff0000) >> 16;
    *y = attributes & 0xff;
}

// USA: func_ov031_0222408c
extern "C" ARM void func_ov031_0222408c(void* object) {
    Struct_ov031_0222408c* state = data_ov031_02250bfc;
    int x, y;
    inline_ov031_0222408c(state->sprite, (unsigned long*)&x, (unsigned long*)&y);
    y -= 12;
    if (y > 0x67) {
        func_ov031_02224ca4(state->channel, 1, y);
        return;
    }
    func_ov031_02224ca4(state->channel, 1, 0x67);
    func_ov031_02224ca4(data_ov031_02250bfc->channel, 2, 0xc0);
    func_ov031_0223e2b8(object, (int)func_ov031_02224120);
}
