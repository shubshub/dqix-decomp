#include <globaldefs.h>

struct Struct_0205d304_3 {
    short unknown_0_;
    short unknown_2_;
    inline void inline_0205d304(short arg0, short arg1) { unknown_0_ = arg0; unknown_2_ = arg1; }
};

struct Struct_0205d81c;
struct GridCursor;
struct Obj5d594;
struct ScaledElementList0204aa28;

extern "C" void* func_0205d81c(struct Struct_0205d81c*, int);
extern "C" void func_0204c770(char*, void*);
extern "C" void func_0205d594(struct Struct_0205d304_2*, unsigned char*, unsigned char*);
#if defined(jpn)
extern "C" void func_0204d790(void* arg0, const char* arg1, unsigned int arg2, int arg3, unsigned char arg4, unsigned char arg5);
#else
extern "C" void func_0204c980(void* arg0, const char* arg1, unsigned int arg2, int arg3, unsigned char arg4, unsigned char arg5, unsigned char arg6);
#endif
unsigned int GetScaledElementPtr(struct ScaledElementList0204aa28*);
void GridCursor_ResetKeyRepeat(struct GridCursor*);
void ApplyElemFields0205d904(unsigned char*);

struct Struct_0205d304_4 {
    char unknown_0_[0x4];
    void* unknown_4_;
    char unknown_8_[0x98];
    unsigned int unknown_a0_;
    int unknown_a4_;
    struct Struct_0205d304_3 unknown_a8_[4];
    char unknown_b8_[0xa];
    short unknown_c2_;
    unsigned char unknown_c4_;
    unsigned char unknown_c5_;
    char unknown_c6_;
    unsigned char unknown_c7_;
    char unknown_c8_[0x18];
};

struct Struct_0205d304 {
    char unknown_0_[0x54];
    char unknown_54_[0x44];
    void* unknown_98_;
    struct Struct_0205d304_4* unknown_9c_;
    struct Struct_0205d304_3 unknown_a0_[4];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
};

// Main, originally func_0205d304 (USA 0x0205d304, EUR 0x0205d314, JPN 0x0205e634)
extern "C" ARM void Window_OpenPane(struct Ctx0205d304* renderer, const char* text, int mode, unsigned char border,
#if defined(jpn)
                                       unsigned char arg4, unsigned char arg5, void* arg6) {
#else
                                       unsigned char arg4, unsigned char arg5, void* arg6, unsigned char arg7) {
#endif
    struct Struct_0205d304_4* var0;
    struct Struct_0205d304_4* var1;
    unsigned char var2, var3, var4, var5;
    int var6;
    int var7;
    unsigned char var8;
    unsigned int var9;

    if (arg1 == 0 || arg0->unknown_98_ == NULL || arg0->unknown_9c_ == NULL) return;
    if (arg0->unknown_b3_ <= arg0->unknown_b4_) return;
    if (func_0205d81c((struct Struct_0205d81c*)arg0, arg0->unknown_b1_) != 0) return;

    var0 = &arg0->unknown_9c_[arg0->unknown_b4_];
    var0->unknown_a8_[0].inline_0205d304(arg0->unknown_a0_[0].unknown_0_, arg0->unknown_a0_[0].unknown_2_);
    var0->unknown_a8_[1].inline_0205d304(arg0->unknown_a0_[1].unknown_0_, arg0->unknown_a0_[1].unknown_2_);
    var0->unknown_a8_[2].inline_0205d304(arg0->unknown_a0_[2].unknown_0_, arg0->unknown_a0_[2].unknown_2_);
    var0->unknown_a8_[3].inline_0205d304(arg0->unknown_a0_[3].unknown_0_, arg0->unknown_a0_[3].unknown_2_);
    if (arg4) {
        var0->unknown_c5_ |= 8;
    } else {
        var0->unknown_c5_ &= ~8;
    }
    var0->unknown_c4_ = arg0->unknown_b1_;
    if (arg0->unknown_b5_) {
        var0->unknown_c5_ |= 4;
    } else {
        var0->unknown_c5_ &= ~4;
    }
    if (arg0->unknown_b6_) {
        var0->unknown_c5_ |= 0x10;
    } else {
        var0->unknown_c5_ &= ~0x10;
    }
    var0->unknown_c7_ = arg0->unknown_b7_;
    func_0204c770((char*)var0, arg6);

    if (arg0->unknown_b4_ != 0) {
        var6 = 0;
        func_0205d594((struct Struct_0205d304_2*)var0->unknown_4_, &var2, &var3);
        for (var7 = arg0->unknown_b4_ - 1; var7 >= 0; var7--) {
            var1 = &arg0->unknown_9c_[var7];
            func_0205d594((struct Struct_0205d304_2*)var1->unknown_4_, &var4, &var5);
            if (var2 == var4 && var3 == var5) {
                var1 = &arg0->unknown_9c_[var7];
                var9 = var1->unknown_a0_ + var1->unknown_a4_;
#if defined(jpn)
                func_0204d790(var0, arg1, var9, arg2, arg3, arg5);
#else
                func_0204c980(var0, arg1, var9, arg2, arg3, arg5, arg7);
#endif
                var6 = 1;
                break;
            }
        }
        if (!var6) {
            var9 = func_0204aa28((struct Struct_0204aa28*)var0->unknown_4_);
#if defined(jpn)
            func_0204d790(var0, arg1, var9, arg2, arg3, arg5);
#else
            func_0204c980(var0, arg1, var9, arg2, arg3, arg5, arg7);
#endif
        }
        var0->unknown_c5_ &= ~0x20;
        for (var8 = 0; var8 < arg0->unknown_b4_; var8++) {
            var1 = &arg0->unknown_9c_[var8];
            var1->unknown_c2_ = 1;
        }
    } else {
        var9 = func_0204aa28((struct Struct_0204aa28*)var0->unknown_4_);
#if defined(jpn)
        func_0204d790(var0, arg1, var9, arg2, arg3, arg5);
#else
        func_0204c980(var0, arg1, var9, arg2, arg3, arg5, arg7);
#endif
        var0->unknown_c5_ &= ~0x20;
    }

    renderer->windowCount++;
    GridCursor_ResetKeyRepeat((struct GridCursor*)renderer->resetState);
    renderer->activeWindowId = renderer->nextWindowId;
    ApplyElemFields0205d904((unsigned char*)renderer);
}
