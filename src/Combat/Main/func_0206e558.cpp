#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int memcmp(void* a, void* b, int n);

struct Struct_0206e558 {
    unsigned char unknown_0_[3];
    unsigned char unknown_3_[4];
    unsigned short unknown_8_[4];
    unsigned char unknown_10_[4];
    unsigned short unknown_14_[4];
};

struct Struct_0206e558_2 {
    struct Struct_0206e558 unknown_0_[5];
    char unknown_8c_[0x42];
    char unknown_ce_[0x255];
    char unknown_323_[0xf];
    char unknown_332_;
    char unknown_333_;
    struct Struct_0206e558 unknown_334_[5];
    char unknown_3c0_[0x42];
    char unknown_402_[2];
    int unknown_404_;
    int unknown_408_;
    char unknown_40c_[0xf];
};

// USA: func_0206e558
extern "C" ARM int func_0206e558(struct Struct_0206e558_2* arg0) {
    int var0 = 0;
    int var1;

    if (arg0->unknown_404_ != 0 || arg0->unknown_408_ != 0) {
        for (var1 = 0; var1 < 5; var1++) {
            struct Struct_0206e558* var2 = &arg0->unknown_0_[var1];
            struct Struct_0206e558* var3 = &arg0->unknown_334_[var1];
            unsigned int var4 = var2->unknown_0_[0] * 10000 + var2->unknown_0_[1] * 100 + var2->unknown_0_[2];
            unsigned int var5 = var3->unknown_0_[0] * 10000 + var3->unknown_0_[1] * 100 + var3->unknown_0_[2];

            if (var4 > var5) {
                continue;
            }
            if (flag == 0 && memcmp(ea, eb, sizeof(struct Elem0206e558)) != 0) {
                flag = 1;
            }
            var2->unknown_0_[0] = var3->unknown_0_[0];
            var2->unknown_0_[1] = var3->unknown_0_[1];
            var2->unknown_0_[2] = var3->unknown_0_[2];
            {
                const unsigned char* var6 = var3->unknown_3_;
                int var7 = 4;
                unsigned char* var8 = var2->unknown_3_;
                do { *var8 = *var6++; var8++; } while (--var7);
            }
            {
                const unsigned short* var9 = var3->unknown_8_;
                int var10 = 4;
                unsigned short* var11 = var2->unknown_8_;
                do { *var11 = *var9++; var11++; } while (--var10);
            }
            {
                const unsigned char* var12 = var3->unknown_10_;
                int var13 = 4;
                unsigned char* var14 = var2->unknown_10_;
                do { *var14 = *var12++; var14++; } while (--var13);
            }
            {
                const unsigned short* var15 = var3->unknown_14_;
                int var16 = 4;
                unsigned short* var17 = var2->unknown_14_;
                do { *var17 = *var15++; var17++; } while (--var16);
            }
        }

        if (flag == 0) {
            if (memcmp(s->name1, s->name3, 0x42) != 0) {
                flag = s->f404;
            }
        }
        memcpy(arg0->unknown_8c_, arg0->unknown_3c0_, 0x42);

        if (flag == 0) {
            if (memcmp(s->name2, s->name4, 0xf) != 0) {
                flag = 1;
            }
        }
        memcpy(arg0->unknown_323_, arg0->unknown_40c_, 0xf);

        arg0->unknown_404_ = 0;
        arg0->unknown_408_ = 0;
    }
    return var0;
}
