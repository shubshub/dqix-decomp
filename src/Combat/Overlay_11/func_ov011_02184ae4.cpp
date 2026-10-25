#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z19CharacterModel_InitPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int MessageSystem_GetInstance();
extern "C" int func_020457e0(char* obj);
extern "C" void* func_ov011_02184a40(void* obj, unsigned int idx);

struct Struct_ov011_02184ae4 {
    char unknown_0_[0xc0];
    unsigned short unknown_c0_;
    unsigned short unknown_c2_;
    unsigned short unknown_c4_;
    unsigned short unknown_c6_;
};

#define SUB(o) ((struct Struct_ov011_02184ae4*)((char*)(o) + 0x100))

// USA: func_ov011_02184ae4
extern "C" ARM void func_ov011_02184ae4(void* arg0) {
    if (SUB(arg0)->unknown_c4_ == 0 && SUB(arg0)->unknown_c6_ == 0 && SUB(arg0)->unknown_c0_ == 0 && SUB(arg0)->unknown_c2_ == 0) return;

    char* g = (char*)MessageSystem_GetInstance();
    if (*(int*)(g + R(0x868, 0x998)) != 0) return;

    int var1 = func_020457e0(var0);
    switch (var1) {
    case 0: {
        unsigned short var2 = SUB(arg0)->unknown_c4_;
        if (var2 != 0) {
            *(unsigned int*)((char*)arg0 + 0x10c) = var2;
            SUB(arg0)->unknown_c4_ = 0;
            SUB(arg0)->unknown_c6_ = 0;
        }
        if (SUB(arg0)->unknown_c0_ == 0) return;
        func_ov011_02184a40(arg0, SUB(arg0)->unknown_c0_);
        SUB(arg0)->unknown_c0_ = 0;
        SUB(arg0)->unknown_c2_ = 0;
        return;
    }
    case 1: {
        unsigned short var3 = SUB(arg0)->unknown_c6_;
        if (var3 != 0) {
            *(unsigned int*)((char*)arg0 + 0x10c) = var3;
            SUB(arg0)->unknown_c4_ = 0;
            SUB(arg0)->unknown_c6_ = 0;
        }
        if (SUB(arg0)->unknown_c2_ == 0) return;
        func_ov011_02184a40(arg0, SUB(arg0)->unknown_c2_);
        SUB(arg0)->unknown_c0_ = 0;
        SUB(arg0)->unknown_c2_ = 0;
        return;
    }
    }
}
