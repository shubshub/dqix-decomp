#include <globaldefs.h>

struct Struct_ov031_02222ddc_5 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov031_022241b4 {
    unsigned char field_0[0xc0];
    Struct_ov031_02222ddc_5* sprite;
    unsigned char field_c4[0x59];
    unsigned char channel;
};

extern Struct_ov031_022241b4* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int channel, int index, int length);
extern "C" void func_ov031_0223e2b8(void* object, int callback);
extern "C" void func_ov031_02224248(void* object);

static inline void inline_ov031_022241b4(const Struct_ov031_02222ddc_5* sprite, unsigned int* x, unsigned int* y) {
    *x = (sprite->unknown_0_ & 0x1ff0000) >> 16;
    *y = sprite->unknown_0_ & 0xff;
}

// USA: func_ov031_022241b4
extern "C" ARM void func_ov031_022241b4(void* object) {
    Struct_ov031_022241b4* state = data_ov031_02250bfc;
    int x, y;
    inline_ov031_022241b4(state->sprite, (unsigned int*)&x, (unsigned int*)&y);
    y -= 12;
    if (y > 0x93) {
        func_ov031_02224ca4(state->channel, 3, y);
        return;
    }
    func_ov031_02224ca4(state->channel, 3, 0x93);
    func_ov031_02224ca4(data_ov031_02250bfc->channel, 4, 0xc0);
    func_ov031_0223e2b8(object, (int)func_ov031_02224248);
}
