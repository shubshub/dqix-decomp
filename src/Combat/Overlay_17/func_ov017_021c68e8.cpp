#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" void* func_ov017_021b8478(void* arg0);
extern "C" void* func_ov017_021b8468(void* arg0);
extern "C" void* func_ov017_021b8470(void* arg0);
extern "C" void func_ov000_02162b70(void* arg0, int arg1, unsigned char arg2);
extern "C" GameObject* func_0200ff58(GameState* arg0, int arg1);
extern "C" int func_02053c6c(unsigned char* arg0);
extern "C" void func_ov000_02162c90(char* arg0, int arg1, int arg2);

struct Struct_ov000_02162aac {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_;
    char unknown_5_;
    short unknown_6_;
    unsigned short unknown_8_;
};

extern "C" void func_ov000_02162aac(void* arg0, int arg1, struct Struct_ov000_02162aac* arg2);

struct Struct_ov017_021c68e8 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c68e8_2 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    short unknown_8_;
    unsigned short unknown_a_;
    signed char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 6;
    signed char unknown_12_;
};

// USA: func_ov017_021c68e8
extern "C" ARM void func_ov017_021c68e8(int arg0, Struct_ov017_021c68e8_2* arg1, GameState* arg2, unsigned char* arg3, struct Struct_0202c1a4* arg4) {
#if defined(jpn)
    void* var0 = *(void**)(arg3 + 0x3000 + 0x508);
#else
    void* var0 = *(void**)(arg3 + 0x3000 + 0x718);
#endif
    Struct_ov017_021c68e8* var1 = (Struct_ov017_021c68e8*)func_ov017_021b8478(var0);
    if (!var1) return;
    void* var2 = func_ov017_021b8468(var0);
    if (!var2) return;
    void* var3 = func_ov017_021b8470(var0);
    if (!var3) return;
    if (var1->unknown_8_ != arg1->unknown_4_) return;

    if (evt->field12 > -1 && evt->field12 != LinkSession_GetOwnSlot(search)) {
        if (evt->flag1) {
            SetByteField0x43eOnEntry_ov000_02162b70(b, (signed char)evt->combatantId, 1);
        }
        return;
    }

    struct Struct_ov000_02162aac var4;
    int var5 = 1;
    var4.unknown_0_ = arg1->unknown_d_;
    var4.unknown_1_ = arg1->unknown_e_;
    var4.unknown_2_ = arg1->unknown_f_;
    var4.unknown_3_ = arg1->unknown_10_;
    var4.unknown_6_ = arg1->unknown_8_;
    var4.unknown_4_ = arg1->unknown_c_;
    var4.unknown_8_ = arg1->unknown_a_;

    if (var4.unknown_1_ != 6 && var4.unknown_0_ != 0xd) {
        if (func_0200ff58(arg2, arg1->unknown_6_) != NULL) {
            GameObject* var6 = func_0200ff1c(arg2, arg1->unknown_6_);
            if (var6 != NULL) {
                int var7 = func_02053c6c((unsigned char*)var6);
                if (var7 != 0) {
#if defined(jpn)
                    var5 = (signed char)*(int*)(var7 + 0x8b4) == 5;
#else
                    var5 = (signed char)*(int*)(var7 + 0x94c) == 5;
#endif
                }
            }
        }
    }

    if (var5) {
        func_ov000_02162aac(var2, arg1->unknown_6_, &var4);
    }
    func_ov000_02162c90((char*)var2, (signed char)arg1->unknown_11_2_, arg1->unknown_11_0_ ? 1 : 0);
    if (arg1->unknown_11_1_) {
        func_ov000_02162b70(var2, (signed char)arg1->unknown_6_, 1);
    }
}
