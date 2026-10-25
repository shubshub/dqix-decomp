#include <globaldefs.h>

#if defined(jpn)
#define func_02026f34 func_02026898
#endif
#include "GameState/GameState.h"

struct Struct_02012de8;

void* GlobalFlags_GetInstance();
int TestFlags02046708(FlagWord02046708* flags, unsigned int mask);

struct Struct_020fdc60_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    char unknown_6_[0x14 - 6];
};

struct Struct_0201fc40 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    char unknown_6_[0x14 - 6];
};

struct Struct_0201fbac {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    char unknown_6_[0x14 - 6];
};

struct Struct_020fdcb0_5 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
};

struct Struct_02026f34 {
#if defined(jpn)
    char unknown1_0_[0x1a6];
#else
    char unknown_0_[0x1b2];
#endif
    unsigned short unknown_1b2_;
};

extern Struct_020fdc60_4 data_020fdc60[4];
extern Struct_020fdcb0_5 data_020fdcb0[4];

extern "C" void func_0201fbac(struct Struct_0201fbac* arg0);
extern "C" void func_0201fc40(struct Struct_0201fc40* arg0, int arg1);
extern "C" void func_0201fa2c(Struct_020fdc60_4* arg0, unsigned int arg1);
extern "C" void func_020200c0(int arg0, void* arg1);

typedef void (*Type_02026f34)(Struct_020fdc60_4* obj, unsigned int arg, unsigned char id);

#if defined(jpn)
enum { Enum_02026f34_1880 = 0x6ac, Enum_02026f34_1884 = 0x6b0 };
#else
enum { Enum_02026f34_1880 = 0x758, Enum_02026f34_1884 = 0x75c };
#endif

// USA: func_02026f34
extern "C" ARM void func_02026f34(void* objv) {
    unsigned char* obj = (unsigned char*)objv;
    if (TestFlags02046708((FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) return;

    GameState* var1 = GameState::GetInstance();
    unsigned int var2 = var1->GetEffectiveDeltaTime();

    for (int var3 = 0; var3 < var0[Enum_02026f34_1884]; var3++) {
        unsigned char* var4 = var0 + var3;
        unsigned char var5 = var4[Enum_02026f34_1880];
        Struct_020fdc60_4* var6;
        Struct_020fdcb0_5* var7;
        unsigned int var8 = (unsigned char)(1 << var5);

        if (!(var0[0x55d] & var8)) continue;

        var6 = (Struct_020fdc60_4*)((char*)data_020fdc60 + var3 * 0x14);
        var7 = (Struct_020fdcb0_5*)((char*)data_020fdcb0 + (var5 << 5));
        void* var9 = var1->GetPartyMemberByIndex(var5);
        if (var9 == NULL) continue;

        int var10 = 0;
        if (var7->unknown_1c_) var10 = 0x7d0;

        if (var7->unknown_1d_ || (var0[0x55e] & var8)) {
            func_020200c0((signed char)var5, (char*)var0 + 0xe8 + var5 * 0x28);
            var0[0x55e] &= ~var8;
        }

        if (data_020fdc60[0].unknown_2_ & 2) {
            func_0201fbac((struct Struct_0201fbac*)var6);
        } else {
            if ((var6->unknown_2_ & 1) && ((Struct_02026f34*)var9)->unknown_1b2_ == 0) {
                var6->unknown_2_ &= ~1;
                var6->unknown_4_ = 0x7d0;
            } else if (((Struct_02026f34*)var9)->unknown_1b2_ != 0) {
                func_0201fbac((struct Struct_0201fbac*)var6);
                var6->unknown_2_ |= 1;
            } else if (var10 > 0 && (var0 + var5)[0x558]) {
                func_0201fc40((struct Struct_0201fc40*)var6, var10);
            }
        }
        ((Type_02026f34)func_0201fa2c)(var6, var2, var5);

        if (var7->unknown_1c_) {
            (var0 + var5)[0x558] = 1;
        }
        var7->unknown_1d_ = 0;
        var7->unknown_1c_ = 0;
    }
}
