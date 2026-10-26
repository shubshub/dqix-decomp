#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021ca9bc_1816 = 0x508 };
#else
enum { Enum_ov017_021ca9bc_1816 = 0x718 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca9bc_5 {
    char unknown_0_[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov017_021ca9bc_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char unknown_2_[2];
    struct Struct_ov017_021ca9bc_5 unknown_4_[1];
};

struct Struct_ov017_021ca9bc_7 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov017_021ca9bc_8 {
    bool unknown_0_0_ : 1;
    bool unknown_0_1_ : 1;
    bool unknown_0_2_ : 1;
    bool unknown_0_3_ : 1;
    bool unknown_0_4_ : 1;
    bool unknown_0_5_ : 1;
    bool unknown_0_6_ : 1;
};

struct Struct_ov017_021ca9bc {
    char unknown_0_[0xc];
    unsigned short unknown_c_;
    char unknown_e_[0x30 - 0xe];
    unsigned short unknown_30_;
    short unknown_32_;
    short unknown_34_;
    char unknown_36_[0x38 - 0x36];
    unsigned char unknown_38_;
    char unknown_39_;
    char unknown_3a_;
    struct Struct_ov017_021ca9bc_7 unknown_3b_;
    struct Struct_ov017_021ca9bc_8 unknown_3c_;
    unsigned char unknown_3d_;
    char unknown_3e_[0xa4 - 0x3e];
};

struct Struct_ov017_021ca9bc_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    struct Struct_ov017_021ca9bc_7 unknown_d_;
    unsigned char unknown_e_;
    struct Struct_ov017_021ca9bc_8 unknown_f_;
};

struct Struct_ov017_021ca9bc_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021ca9bc_2 unknown_4_;
};

struct Struct_ov017_021ca9bc_4 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    char unknown_a_[0x158 - 0xa];
    struct Struct_ov017_021ca9bc unknown_158_[8];
};

// USA: func_ov017_021ca9bc
extern "C" ARM void func_ov017_021ca9bc(struct Struct_ov017_021ca9bc_6* arg0) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + RegionOffset718);
    struct Obj021ca9bc* obj = (struct Obj021ca9bc*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    for (int var3 = 0; var3 < arg0->unknown_1_4_; var3++) {
        struct Struct_ov017_021ca9bc_5* var4 = &arg0->unknown_4_[var3];
        struct Struct_ov017_021ca9bc_3 var5;
        for (int var6 = 0; var6 < var4->unknown_a_0_; var6++) {
            unsigned char var7 = var4->unknown_2_[var6];
            if (var7 >= 8) {
                continue;
            }
            struct Struct_ov017_021ca9bc* var8 = &var1->unknown_158_[var7];
            struct Struct_ov017_021ca9bc_2* var9 = &var5.unknown_4_;
            var5.unknown_0_ = 0x5f;
            var9->unknown_0_ = var1->unknown_8_;
            var9->unknown_2_ = (unsigned short)(var4->unknown_2_[var6] + 0xc0);
            var9->unknown_4_ = var8->unknown_32_;
            var9->unknown_6_ = var8->unknown_34_;
            var9->unknown_8_ = var8->unknown_c_;
            var9->unknown_a_ = var8->unknown_30_;
            var9->unknown_c_ = var8->unknown_38_;
            var9->unknown_d_.unknown_0_0_ = var8->unknown_3b_.unknown_0_0_ & 0xff;
            var9->unknown_d_.unknown_0_1_ = var8->unknown_3b_.unknown_0_1_ & 0xff;
            var9->unknown_d_.unknown_0_2_ = var8->unknown_3b_.unknown_0_2_ & 0xff;
            var9->unknown_d_.unknown_0_3_ = var8->unknown_3b_.unknown_0_3_ & 0xff;
            var9->unknown_d_.unknown_0_4_ = var8->unknown_3b_.unknown_0_4_ & 0xff;
            var9->unknown_f_.unknown_0_0_ = var8->unknown_3c_.unknown_0_0_ != 0;
            var9->unknown_f_.unknown_0_1_ = var8->unknown_3c_.unknown_0_1_ != 0;
            var9->unknown_f_.unknown_0_2_ = var8->unknown_3c_.unknown_0_2_ != 0;
            var9->unknown_f_.unknown_0_3_ = var8->unknown_3c_.unknown_0_3_ != 0;
            var9->unknown_f_.unknown_0_4_ = var8->unknown_3c_.unknown_0_4_ != 0;
            var9->unknown_f_.unknown_0_5_ = var8->unknown_3c_.unknown_0_5_ != 0;
            var9->unknown_f_.unknown_0_6_ = var8->unknown_3c_.unknown_0_6_ != 0;
            var9->unknown_e_ = var8->unknown_3d_;
            func_0205e330(var2, &var5, 0);
        }
    }
}
