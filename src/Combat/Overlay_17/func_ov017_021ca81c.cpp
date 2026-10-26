#if defined(jpn)
enum { Enum_ov017_021ca81c_1816 = 0x508 };
#else
enum { Enum_ov017_021ca81c_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca81c_2 {
    char unknown_0_[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov017_021ca81c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char unknown_2_[2];
    struct Struct_ov017_021ca81c_2 unknown_4_[1];
};

struct Struct_ov017_021ca81c_4 {
    char unknown_0_[0x28];
    short unknown_28_;
    short unknown_2a_;
    short unknown_2c_;
    short unknown_2e_;
};

struct Struct_ov017_021ca81c_5 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    int unknown_4_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_ov017_021ca81c {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021ca81c_5 unknown_4_;
};

// USA: func_ov017_021ca81c
extern "C" ARM void func_ov017_021ca81c(struct Struct_ov017_021ca81c_3* arg0) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + RegionOffset718);
    unsigned char* fp = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    for (int var3 = 0; var3 < arg0->unknown_1_4_; var3++) {
        struct Struct_ov017_021ca81c_2* var4 = &arg0->unknown_4_[var3];
        struct Struct_ov017_021ca81c var5;
        for (int var6 = 0; var6 < var4->unknown_a_0_; var6++) {
            unsigned char var7 = var4->unknown_2_[var6];
            if (var7 >= 8) {
                continue;
            }
            struct Struct_ov017_021ca81c_4* var8 = (struct Struct_ov017_021ca81c_4*)(var1 + 0x158 + var7 * 0xa4);
            struct Struct_ov017_021ca81c_5* var9 = &var5.unknown_4_;
            var5.unknown_0_ = 0x5e;
            var9->unknown_0_ = *(unsigned short*)(var1 + 8);
            var9->unknown_2_ = (unsigned short)(var4->unknown_2_[var6] + 0xc0);
            memcpy(&var9->unknown_4_, (char*)var8 + 0x58, 4);
            var9->unknown_8_ = var8->unknown_28_;
            var9->unknown_a_ = var8->unknown_2a_;
            var9->unknown_c_ = var8->unknown_2c_;
            var9->unknown_e_ = var8->unknown_2e_;
            func_0205e330(var2, &var5, 0);
        }
    }
}
