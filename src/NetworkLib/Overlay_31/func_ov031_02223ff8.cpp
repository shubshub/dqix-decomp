#include <globaldefs.h>

struct Struct_ov031_02222ddc_2 { unsigned int unknown_0_; unsigned short unknown_4_; unsigned short unknown_6_; };

struct Struct_ov031_02223ff8 {
    unsigned char pad0[0x30];
    Struct_ov031_02222ddc_2* unknown_30_;
    unsigned char pad1[0x11d - 0x34];
    unsigned char unknown_11d_;
};

extern Struct_ov031_02223ff8* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int a, int idx, int y);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_0222408c(void* obj);

static inline void inline_ov031_02223ff8(const Struct_ov031_02222ddc_2* oam, unsigned int* x, unsigned int* y) {
    *x = (oam->unknown_0_ & 0x1ff0000) >> 16;
    *y = oam->unknown_0_ & 0xff;
}

// USA: func_ov031_02223ff8
extern "C" ARM void func_ov031_02223ff8(void* obj) {
    int x, y;
    inline_ov031_02223ff8(data_ov031_02250bfc->unknown_30_, (unsigned int*)&x, (unsigned int*)&y);
    y -= 0xc;
    if (y > 0x51) {
        func_ov031_02224ca4(data_ov031_02250bfc->unknown_11d_, 0, y);
        return;
    }
    func_ov031_02224ca4(data_ov031_02250bfc->unknown_11d_, 0, 0x51);
    func_ov031_02224ca4(data_ov031_02250bfc->unknown_11d_, 1, 0xc0);
    func_ov031_0223e2b8(obj, (int)func_ov031_0222408c);
}
