#include <globaldefs.h>

#if defined(jpn)
#define func_0205cc50 func_0205dfa8
#endif

extern "C" int MessageSystem_GetInstance();
struct Struct_0205bd58;
extern "C" void func_0205bd58(Struct_0205bd58 *fields, int count, int a, int b, int c, int d);

struct Struct_0205cc50 {
    unsigned char unknown_0[0x58];
    short unknown_58_;
    short unknown_5a_;
    unsigned char unknown_5c_[0x20];
    int pairCount;
    unsigned char unknown_80_[0x34];
    short unknown_b4_;
    short unknown_b6_;
    short width;
    short height;
    unsigned char unknown_bc_[0x14];
    int unknown_d0_;
    int unknown_d4_;
    int unknown_d8_;
    int unknown_dc_;
    unsigned short widths[8];
    unsigned short offsets[8];
    unsigned short unknown_100_[8];
    unsigned short unknown_110_[8];
};

// USA: func_0205cc50
#if defined(jpn)
extern "C" ARM void func_0205cc50(void *object) {
#else
extern "C" ARM void func_0205cc50(void *object, int arg1, int arg2) {
#endif
    Struct_0205cc50 *pair = static_cast<Struct_0205cc50 *>(object);
    MessageSystem_GetInstance();

    int count       = pair->pairCount;
    int var2 = count * 12 + 16;
    pair->width     = pair->unknown_d0_ + 24;
    pair->height    = var2 + (count - 1) * (pair->unknown_d8_ - 12);
#if !defined(jpn)
    if (arg1 != 0) {
        short var3 = (short) ((pair->width + 7) & ~7);
        pair->width        = var3 + arg2;
    }
#endif
    for (int index = 0; index < pair->unknown_dc_; ++index) {
        pair->widths[index]  = 12;
        pair->offsets[index] = pair->unknown_d8_ * index + 8;
    }
    short x      = pair->unknown_b4_;
    short y      = pair->unknown_b6_;
    pair->unknown_58_ = x;
    pair->unknown_5a_ = y;
    func_0205bd58(reinterpret_cast<Struct_0205bd58 *>(static_cast<unsigned char *>(object) + 0x20), pair->unknown_dc_,
                      (int) pair->widths, (int) pair->offsets, (int) pair->unknown_100_, (int) pair->unknown_110_);
}
