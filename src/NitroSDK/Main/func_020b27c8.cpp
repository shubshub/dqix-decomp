#include <globaldefs.h>


typedef unsigned char Type_020b1300;
typedef unsigned short Type_020b0a1c;
typedef unsigned int Type_020b11c8;
typedef int Type_020b0a1c_2;
#define TRUE 1
#define FALSE 0

#define NNS_G2D_BINFILE_SIG_FONTDATA 0x4e465452
#define NNS_G2D_NFTR_VER 0x0101
#define NNS_G2D_NFTR_PREV_VER 0x0100
#define NNS_G2D_BINBLK_SIG_FINFDATA 0x46494e46

struct Struct_020b27c8_3 {
    Type_020b11c8 unknown_0_;
    Type_020b0a1c unknown_4_;
    Type_020b0a1c unknown_6_;
    Type_020b11c8 unknown_8_;
    Type_020b0a1c unknown_c_;
    Type_020b0a1c unknown_e_;
};

struct Struct_020b27c8_4 {
    Type_020b11c8 unknown_0_;
    Type_020b11c8 unknown_4_;
};

struct Struct_020b27c8_2 {
    Type_020b1300 unknown_0_;
    Type_020b1300 unknown_1_;
    Type_020b0a1c unknown_2_;
    signed char unknown_4_;
    Type_020b1300 unknown_5_;
    Type_020b1300 unknown_6_;
    Type_020b1300 unknown_7_;
};

struct Struct_020b27c8 {
    Type_020b1300 unknown_0_;
    signed char unknown_1_;
    Type_020b0a1c unknown_2_;
    Type_020b1300 unknown_4_[3];
    Type_020b1300 unknown_7_;
    Struct_020b27c8_2* unknown_8_;
};

struct Hdr02b0288;
extern "C" void HaltSystem(void);
void PatchFontResourceBlocks_020b291c(void* base);
NNSG2dBinaryBlockHeader* FindChunkById_020b0288(struct Hdr02b0288* h, unsigned int kind);

static inline Type_020b0a1c_2 inline_020b27c8(const Struct_020b27c8_3* arg0, Type_020b11c8 arg1) {
    if (arg0 != NULL) {
        if (arg0->unknown_0_ == arg1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline Type_020b0a1c_2 inline_020b27c8_2(const Struct_020b27c8_3* arg0, Type_020b0a1c arg1) {
    if (arg0 != NULL) {
        if (arg0->unknown_6_ >= arg1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline Type_020b0a1c_2 inline_020b27c8_3(const Struct_020b27c8_3* arg0, Type_020b11c8 arg1, Type_020b0a1c arg2) {
    if (arg0 != NULL) {
        return inline_020b27c8(arg0, arg1) && inline_020b27c8_2(arg0, arg2);
    }
    return FALSE;
}

// USA: func_020b27c8
extern "C" ARM Type_020b0a1c_2 func_020b27c8(void* arg0, Struct_020b27c8** arg1) {
    Type_020b0a1c_2 var0 = FALSE;

    if (!NNS_G2dIsBinFileValid((NNSG2dBinaryFileHeader*)pNftrFile, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_VER)) {
        if (!NNS_G2dIsBinFileValid((NNSG2dBinaryFileHeader*)pNftrFile, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_PREV_VER)) {
            HaltSystem();
        }
        var0 = TRUE;
    }

    {
        Struct_020b27c8_3* var1 = (Struct_020b27c8_3*)arg0;
        Struct_020b27c8_4* var2;

        func_020b291c(var1);

        var2 = func_020b0288((struct Struct_0205ab78*)var1, NNS_G2D_BINBLK_SIG_FINFDATA);

        if (var2 == NULL) {
            *arg1 = NULL;
            return FALSE;
        }

        *arg1 = (Struct_020b27c8*)((Type_020b1300*)var2 + sizeof(*var2));
        if (var0) {
            (*arg1)->unknown_8_->unknown_7_ = 0;
        }
    }

    return TRUE;
}
