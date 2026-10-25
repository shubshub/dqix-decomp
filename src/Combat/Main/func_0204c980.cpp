#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"

struct Struct_0204c980_2 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

struct Struct_0204c980 {
    int unknown_0_;
    Struct_0204c980_2* unknown_4_;
    void* unknown_8_;
    short unknown_c_[4][18];
    int unknown_9c_;
    unsigned int unknown_a0_;
    unsigned int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    short unknown_b0_;
    char unknown_b2_[0xe];
    short unknown_c0_;
    short unknown_c2_;
    unsigned char unknown_c4_;
    unsigned char unknown_c5_;
    unsigned char unknown_c6_;
    unsigned char unknown_c7_;
    short unknown_c8_;
    short unknown_ca_;
    int unknown_cc_;
    int unknown_d0_;
    void* unknown_d4_;
};

void ClearFourRegions0204f0ec(char*);
void* MessageSystem_GetInstance();
int GetTableEntry0204a5e4(int, int);
#if defined(jpn)
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
extern "C" short func_0204f6a0(Struct_0204c980*, char*, int, unsigned char, unsigned char);
extern "C" void func_0204daf8(Struct_0204c980*, char*, short);
#else
extern "C" void MessageSystem_FormatText(void*, unsigned char, const char*, char*, int, int, unsigned char);
extern "C" short func_0204e3e0(Window0204c980*, char*, int, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204cd60(Window0204c980*, char*, short, short);
#endif
typedef void (*Type_0204c980)(const void*, unsigned int, unsigned int);

inline int inline_0204c980(int arg0, int arg1) { return func_0204a5e4(arg1, arg0); }

inline int inline_0204c980_2(Struct_0204c980_2* arg0) { return arg0->unknown_1c_4_; }

// USA: func_0204c980
#if defined(jpn)
extern "C" ARM void func_0204d790(Struct_0204c980* arg0, const char* arg1, unsigned int arg2, int arg3, unsigned char arg4, unsigned char arg5) {
#else
extern "C" ARM void func_0204c980(Struct_0204c980* arg0, const char* arg1, unsigned int arg2, int arg3, unsigned char arg4, unsigned char arg5, unsigned char arg6) {
#endif
    if (arg0->unknown_4_ && arg0->unknown_8_ && arg1) {
        func_0204f0ec((char*)arg0);
#if defined(jpn)
        char buffer[0x800] = {};
        func_020474a8(MessageSystem_GetInstance(), window->fontHeight, text, buffer);
        short padding = func_0204f6a0(window, buffer, mode, border, fullWidth);
        func_0204daf8(window, buffer, padding);
#else
        int width = window->width * 8;
        if (!(window->flags & 0x10)) width -= 4;
        if (fullWidth) width = 256;
        char buffer[0x800] = {};
        MessageSystem_FormatText(MessageSystem_GetInstance(), window->fontHeight, text, buffer, width, window->textX, font);
        short padding = func_0204e3e0(window, buffer, mode, border, fullWidth, font);
        func_0204cd60(window, buffer, padding, font);
#endif
        arg0->unknown_a0_ = arg2;
        Type_0204c980 var5 = (Type_0204c980)inline_0204c980(inline_0204c980_2(arg0->unknown_4_), arg0->unknown_4_->unknown_1c_0_);
        CleanInvalidateCacheRange(arg0->unknown_8_, arg0->unknown_a4_);
        var5(arg0->unknown_8_, arg0->unknown_a0_, arg0->unknown_a4_);
        if (arg0->unknown_c5_ & 1) {
            arg0->unknown_c0_ = 0;
            short var6 = arg0->unknown_aa_;
            short var7 = arg0->unknown_a8_;
            int var8 = var7 * var6 * 2;
            arg0->unknown_c8_ = var7;
            arg0->unknown_ca_ = var6;
            arg0->unknown_d0_ = var8;
            arg0->unknown_c2_ = 0;
            arg0->unknown_9c_ = 1;
        } else {
            arg0->unknown_c5_ |= 1;
            arg0->unknown_c0_ = 0;
            int var9 = arg0->unknown_a8_ * arg0->unknown_aa_ * 2;
            memset(arg0->unknown_d4_, 0, var9);
            short var10 = arg0->unknown_aa_;
            short var11 = arg0->unknown_a8_;
            arg0->unknown_c8_ = var11;
            arg0->unknown_ca_ = var10;
            arg0->unknown_d0_ = var9;
            arg0->unknown_c2_ = 0;
            arg0->unknown_9c_ = 1;
        }
    }
}
