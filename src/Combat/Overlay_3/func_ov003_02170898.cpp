#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02170898_2112 = 0x860 };
#else
enum { Enum_ov003_02170898_2112 = 0x840 };
#endif

extern "C" void* Zone3D_GetInstance(void);

struct Struct_020985ec {
    unsigned char unknown_0_[0x10];
    unsigned int unknown_10_;
    unsigned char unknown_14_[0xd4];
};

struct Struct_ov003_02170898 {
    unsigned char unknown_0_[0x1b38];
    int unknown_1b38_;
};

// USA: func_ov003_02170898
extern "C" ARM void func_ov003_02170898(unsigned char* self) {
    struct Elem020985ec* arr = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + kRegionValue840_860);
    int count = (*(struct Ctx020985ec**)(self + 0x170))->count;

    int var2;
    for (var2 = 0; var2 < 0x1e; var2++) {
        *(int*)(arg0 + var2 * 4 + 0xf4) = 0;
    }

    int var3;
    int var4 = 0;
    for (var3 = 0; var3 < 0x1e; var3++) {
        struct Struct_020985ec* var5 = &var0[var3];
        if ((var5->unknown_10_ >> 2) != 0) {
            *(struct Struct_020985ec**)(arg0 + var4 * 4 + 0xf4) = var5;
            var4++;
        }
    }

    int var6 = (var1 - 1) / 8 + 1;
    arg0[4] = var6;
    if (arg0[0] > arg0[4]) arg0[0] = arg0[4];

    if (arg0[0] == arg0[4]) {
        int var7 = var1 % 8;
        if (var7 != 0) {
            arg0[5] = (unsigned char)var7;
            return;
        }
    }
    arg0[5] = 8;
}
