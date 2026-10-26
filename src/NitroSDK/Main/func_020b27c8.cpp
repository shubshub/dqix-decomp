#include <globaldefs.h>


typedef unsigned char Type_020b1300;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int Type_020b0a1c_2;
#define TRUE 1
#define FALSE 0

#define NNS_G2D_BINFILE_SIG_FONTDATA 0x4e465452
#define NNS_G2D_NFTR_VER 0x0101
#define NNS_G2D_NFTR_PREV_VER 0x0100
#define NNS_G2D_BINBLK_SIG_FINFDATA 0x46494e46

struct Struct_020b27c8_3 {
    u32 signature;
    u16 unknown_4_;
    u16 unknown_6_;
    u32 fileSize;
    u16 headerSize;
    u16 unknown_e_;
};

struct Struct_020b27c8_4 {
    u32 kind;
    u32 size;
};

struct Struct_020b27c8_2 {
    Type_020b1300 unknown_0_;
    Type_020b1300 unknown_1_;
    u16 unknown_2_;
    signed char unknown_4_;
    Type_020b1300 unknown_5_;
    Type_020b1300 bpp;
    Type_020b1300 flags;
};

struct Struct_020b27c8 {
    Type_020b1300 fontType;
    signed char unknown_1_;
    u16 unknown_2_;
    Type_020b1300 defaultWidth[3];
    Type_020b1300 unknown_7_;
    Struct_020b27c8_2* unknown_8_;
};

struct Hdr02b0288;
extern "C" void HaltSystem(void);
extern "C" void func_020b291c(void* base);
extern "C" Struct_020b27c8_4* func_020b0288(struct Hdr02b0288* h, unsigned int kind);

static inline Type_020b0a1c_2 inline_020b27c8(const Struct_020b27c8_3* arg0, u32 arg1) {
    if (arg0 != NULL) {
        if (arg0->signature == arg1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline Type_020b0a1c_2 inline_020b27c8_2(const Struct_020b27c8_3* arg0, u16 arg1) {
    if (arg0 != NULL) {
        if (arg0->unknown_6_ >= arg1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline Type_020b0a1c_2 inline_020b27c8_3(const Struct_020b27c8_3* arg0, u32 arg1, u16 arg2) {
    if (arg0 != NULL) {
        return inline_020b27c8(arg0, arg1) && inline_020b27c8_2(arg0, arg2);
    }
    return FALSE;
}

// USA: func_020b27c8
extern "C" ARM Type_020b0a1c_2 func_020b27c8(void* arg0, Struct_020b27c8** arg1) {
    Type_020b0a1c_2 var0 = FALSE;

    if (!inline_020b27c8_3((Struct_020b27c8_3*)arg0, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_VER)) {
        if (!inline_020b27c8_3((Struct_020b27c8_3*)arg0, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_PREV_VER)) {
            HaltSystem();
        }
        var0 = TRUE;
    }

    {
        Struct_020b27c8_3* var1 = (Struct_020b27c8_3*)arg0;
        Struct_020b27c8_4* var2;

        func_020b291c(var1);

        var2 = func_020b0288((struct Hdr02b0288*)var1, NNS_G2D_BINBLK_SIG_FINFDATA);

        if (var2 == NULL) {
            *arg1 = NULL;
            return FALSE;
        }

        *arg1 = (Struct_020b27c8*)((Type_020b1300*)var2 + sizeof(*var2));
        if (var0) {
            (*arg1)->unknown_8_->flags = 0;
        }
    }

    return TRUE;
}
