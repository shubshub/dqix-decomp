#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

extern "C" int memcmp(const void*, const void*, unsigned int);
int ReadVarLenValue_02207dd4(unsigned char**);
void AppendCsv_02207e24(char*, const char*, int);
int ParseEncodedDate_02207e90(unsigned char*, int);

extern const char* data_ov031_02249704[];

struct Struct_ov031_02207f10 {
    char unknown_0_[0x458];
    int unknown_458_;
    int unknown_45c_;
    int unknown_460_;
    int unknown_464_;
    char unknown_468_[0x484 - 0x468];
    int unknown_484_;
    unsigned char* unknown_488_;
    int unknown_48c_;
    unsigned char* unknown_490_;
    char unknown_494_[0x100];
    int unknown_594_;
    char unknown_598_[8];
    int unknown_5a0_;
    unsigned char* unknown_5a4_;
    int unknown_5a8_;
    unsigned char unknown_5ac_;
    unsigned char unknown_5ad_;
    unsigned char unknown_5ae_;
    unsigned char unknown_5af_;
    char unknown_5b0_[0x100];
    char unknown_6b0_[0x100];
    char unknown_7b0_[0x5c];
    unsigned int unknown_80c_;
};

// USA: func_ov031_02207f10
extern "C" ARM int func_ov031_02207f10(Struct_ov031_02207f10* arg0, unsigned char** arg1, int arg2, int arg3, int arg4) {
    unsigned char* var0 = *arg1;
    unsigned char* var1 = var0 + 1;
    unsigned char var2 = *var0;
    int var3 = func_ov031_02207dd4(&var1);
    if (var3 < 0 || var3 > 2000) {
        return 1;
    }
    switch (var2 & 0x1f) {
    case 2:
        if (arg0->unknown_5ad_) {
            if (arg3 == 0) {
                if (*var1 == 0) {
                    do {
                        var1++;
                        var3--;
                    } while (*var1 == 0);
                }
                switch (arg4) {
                case 0:
                    if (var3 <= 0x100) {
                        VectorizedInvertedMemcpy(var1, arg0->unknown_494_, var3);
                        arg0->unknown_594_ = var3;
                    }
                    break;
                case 2:
                    arg0->unknown_484_ = var3;
                    arg0->unknown_488_ = var1;
                    break;
                }
            } else if (arg3 == 1) {
                if (*var1 == 0) {
                    do {
                        var1++;
                        var3--;
                    } while (*var1 == 0);
                }
                switch (arg4) {
                case 0:
                    if (var3 <= 8) {
                        VectorizedInvertedMemcpy(var1, arg0->unknown_598_, var3);
                        arg0->unknown_5a0_ = var3;
                    }
                    break;
                case 2:
                    arg0->unknown_48c_ = var3;
                    arg0->unknown_490_ = var1;
                    break;
                }
            }
        }
        var1 += var3;
        break;
    case 3:
        if (arg2 == 1 && arg4 != 2) {
            arg0->unknown_5a4_ = var1 + 1;
            arg0->unknown_5a8_ = var3 - 1;
        }
        if (arg0->unknown_5ad_) {
            var1++;
            if (func_ov031_02207f10(arg0, &var1, arg2, 0, arg4)) {
                return 1;
            }
            arg0->unknown_5ad_ = 0;
        } else {
            var1 += var3;
        }
        break;
    case 6: {
        int var4;
        unsigned char* var5 = var1;
        var4 = 0;
        do {
            const char* s = data_ov031_02249704[i];
            if (memcmp(q, s, strlen(s)) == 0) {
                switch (i) {
                case 1:
                case 2:
                    if (arg4 == 0) {
                        arg0->unknown_45c_ = var4;
                    }
                    arg0->unknown_5ad_ = var4;
                    break;
                case 3:
                case 4:
                    if (arg4 != 2) {
                        arg0->unknown_458_ = var4;
                    }
                    break;
                case 5:
                    if (arg4 != 2) {
                        arg0->unknown_5ae_ = var4;
                    }
                    break;
                }
                break;
            }
            var4++;
        } while (var4 < 6);
        var1 += var3;
        break;
    }
    case 12:
    case 19:
    case 20:
    case 22:
        if (arg4 != 2) {
            if (arg0->unknown_5ac_) {
                func_ov031_02207e24(arg0->unknown_6b0_, (const char*)var1, var3);
                if (arg0->unknown_5ae_ == 5 && var3 <= 0x4f) {
                    VectorizedInvertedMemcpy(var1, arg0->unknown_7b0_, var3);
                    arg0->unknown_7b0_[var3] = 0;
                }
            } else {
                func_ov031_02207e24(arg0->unknown_5b0_, (const char*)var1, var3);
            }
        }
        arg0->unknown_5ae_ = 0;
        var1 += var3;
        break;
    case 23:
    case 24:
        if (arg4 != 2) {
            unsigned int var7 = func_ov031_02207e90(var1, var2 & 0x1f);
            if (arg3 == 0) {
                if (arg0->unknown_80c_ >= var7) {
                    arg0->unknown_5af_ = 1;
                }
            } else {
                if (arg0->unknown_80c_ > var7) {
                    arg0->unknown_5af_ = 0;
                }
            }
        }
        var1 += var3;
        arg0->unknown_5ac_ = 1;
        break;
    case 16: {
        if (arg2 == 0 && arg3 == 0 && arg4 != 2) {
            arg0->unknown_460_ = (int)var1;
        }
        unsigned char* var8 = var1 + var3;
        int var9 = 0;
        if (var1 < var8) {
            do {
                int var10 = func_ov031_02207f10(arg0, &var1, arg2 + 1, var9, arg4);
                var9++;
                if (var10) {
                    return 1;
                }
            } while (var1 < var8);
        }
        if (arg2 == 1 && arg3 == 0 && arg4 != 2) {
            arg0->unknown_464_ = (int)var1;
        }
        break;
    }
    case 17: {
        unsigned char* var11 = var1 + var3;
        if (var1 < var11) {
            do {
                if (func_ov031_02207f10(arg0, &var1, arg2 + 1, 0, arg4)) {
                    return 1;
                }
            } while (var1 < var11);
        }
        break;
    }
    default:
        if (var2 == 0xa0) {
            unsigned char* var12 = var1 + var3;
            if (var1 < var12) {
                do {
                    if (func_ov031_02207f10(arg0, &var1, arg2 + 1, 0, arg4)) {
                        return 1;
                    }
                } while (var1 < var12);
            }
        } else {
            var1 += var3;
        }
        break;
    }
    *arg1 = var1;
    return 0;
}
