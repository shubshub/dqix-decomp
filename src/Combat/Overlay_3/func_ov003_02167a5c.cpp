#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02167a5c_112 = 0x40 };
#else
enum { Enum_ov003_02167a5c_112 = 0x70 };
#endif


struct Struct_0207fe44;
extern "C" void func_0207fe44(struct Struct_0207fe44* arg0);

struct Pair02167a5c { unsigned int a; unsigned int b; };
extern struct Pair02167a5c __ptmf_null;
struct Inner02167a5c { unsigned int v[2]; };

struct Struct_ov003_02167a5c_2 { unsigned int unknown_0_; unsigned int unknown_4_; };
struct Struct_ov003_0217f4f0 { struct Struct_ov003_02167a5c_2 unknown_0_[7]; };
extern struct Struct_ov003_0217f4f0 data_ov003_0217f4f0;

struct Struct_ov003_02167a5c_3 {
    char unknown_0_[0x10];
    struct Struct_0207fe44* unknown_10_;
    char unknown_14_[Enum_ov003_02167a5c_112 - 0x14];
    int unknown_70_;
    unsigned char unknown_74_;
    char unknown_75_;
    signed char unknown_76_;
};

// USA: func_ov003_02167a5c
extern "C" ARM void func_ov003_02167a5c(struct Struct_ov003_02167a5c_3* arg0, int arg1, int arg2) {
    if (arg0->unknown_74_ == 0 || arg0->unknown_10_ == 0) return;
    if (arg0->unknown_70_ == arg1 && arg0->unknown_76_ == arg2) return;

    if (arg0->unknown_70_ != arg1 || arg2 < 0) {
        func_0207fe44(arg0->unknown_10_);
    }
    arg0->unknown_70_ = arg1;
    arg0->unknown_76_ = (signed char)arg2;

    struct Table02167a5c buf;
    buf = data_ov003_0217f4f0;
    *(struct Inner02167a5c*)&buf.entries[0] = *(struct Inner02167a5c*)&__ptmf_null;

    if (var0.unknown_0_[arg1].unknown_0_ == 0) return;
    struct Struct_ov003_02167a5c_2* var1 = &var0.unknown_0_[arg1];
    void* var2 = (char*)arg0 + ((int)var1->unknown_4_ >> 1);
    void* var3;
    if (var1->unknown_4_ & 1) {
        var3 = *(void**)((char*)*(void**)var2 + var1->unknown_0_);
    } else {
        var3 = (void*)var1->unknown_0_;
    }
    ((void(*)(void*))var3)(var2);
}
