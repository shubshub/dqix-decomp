#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217193c_1841 = 0x62d };
enum { Enum_ov003_0217193c_1843 = 0x62f };
enum { Enum_ov003_0217193c_1848 = 0x634 };
#else
enum { Enum_ov003_0217193c_1841 = 0x731 };
enum { Enum_ov003_0217193c_1843 = 0x733 };
enum { Enum_ov003_0217193c_1848 = 0x738 };
#endif
#include "GameState/GameState.h"

struct Struct_0202bad4;
struct Struct_0202bad4_2;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void* ptr);
extern "C" int func_ov003_02171d78(void* list, unsigned char* key);
int GetField0xc_0202bae4(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
int StartBattleTransition0202b840(int* state, int id);

struct Struct_ov003_0217193c_2 { unsigned char unknown_0_[0x14]; };
struct Struct_ov003_0217193c_3 { unsigned char unknown_0_[6]; };

struct Struct_ov003_0217193c_4 {
    unsigned char unknown_0_0_ : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov003_0217193c_5 {
    char unknown_0_[0x50];
    Struct_ov003_0217193c_2 unknown_50_;
    unsigned char unknown_64_;
    Struct_ov003_0217193c_4 unknown_65_;
    unsigned short unknown_66_;
    Struct_ov003_0217193c_3 unknown_68_;
    char unknown_6e_[2];
    int unknown_70_;
};

struct Struct_ov003_0217193c {
    unsigned char unknown_0_;
    char unknown_1_[3];
    unsigned int unknown_4_;
    char unknown_8_[0x199 - 8];
    signed char unknown_199_;
    char unknown_19a_[2];
    Struct_ov003_0217193c_2 unknown_19c_;
    unsigned char unknown_1b0_;
    Struct_ov003_0217193c_4 unknown_1b1_;
    unsigned short unknown_1b2_;
    Struct_ov003_0217193c_3 unknown_1b4_;
    char unknown_1ba_[2];
    int unknown_1bc_;
    char unknown_1c0_[Enum_ov003_0217193c_1841 - 0x1c0];
    signed char unknown_731_;
    signed char unknown_732_;
    char unknown_733_[Enum_ov003_0217193c_1848 - Enum_ov003_0217193c_1843];
    int unknown_738_;
};

// USA: func_ov003_0217193c
extern "C" ARM void func_ov003_0217193c(struct Struct_ov003_0217193c* arg0) {
    Struct_ov003_0217193c_5* var0;
    GameState* var1;
    void* var2;
    unsigned int var3;
    unsigned int var4;
    int var5;
    unsigned int var6;

    battle = GameState::GetInstance();
    search = LinkSession_GetInstance();
    dt = battle->GetEffectiveDeltaTime();

    if (var3 < arg0->unknown_4_ && arg0->unknown_732_ > 0) {
        arg0->unknown_4_ -= var3;
        var4 = func_0202bae4(var2);
        if (var4 == 0) return;
        var5 = 0;
        for (var6 = 0; var6 < var4; var6++) {
            var0 = (Struct_ov003_0217193c_5*)func_0202bad4((struct Struct_0202bad4_2*)var2, var6);
            if (func_ov003_02171d78(arg0, var0->unknown_68_.unknown_0_) == 0 && var0->unknown_65_.unknown_0_3_) {
#if !defined(jpn)
                if (var5 > 0 && arg0->unknown_1b1_.unknown_0_6_ != var0->unknown_65_.unknown_0_6_) break;
#endif
                func_0202b840((int*)var2, var6);
                arg0->unknown_199_ = 0;
#if !defined(jpn)
                arg0->unknown_19c_ = var0->unknown_50_;
                arg0->unknown_1b0_ = var0->unknown_64_;
                arg0->unknown_1b1_ = var0->unknown_65_;
                arg0->unknown_1b2_ = var0->unknown_66_;
                arg0->unknown_1b4_ = var0->unknown_68_;
                arg0->unknown_1bc_ = var0->unknown_70_;
#endif
                arg0->unknown_0_ = 6;
                var5++;
            } else if (var0->unknown_65_.unknown_0_4_) {
                arg0->unknown_738_ = var0->unknown_70_;
            }
        }
        if (var5 <= 0) return;
        arg0->unknown_4_ = 0;
        arg0->unknown_732_ = arg0->unknown_732_ - 1;
    } else {
        obj->timer = 0;
        LinkSession_End(search);
        obj->retries--;
        if (obj->retries > 0) {
            obj->state = 0;
        } else {
            arg0->unknown_0_ = 8;
        }
    }
}
