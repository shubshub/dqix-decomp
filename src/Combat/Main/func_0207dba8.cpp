#include <globaldefs.h>

#include "GameState/GameState.h"

struct Struct_0202b2f0;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void);
int TestFlagBitAt0xe_0202c578(struct SearchStruct* obj, int value);
extern "C" void func_0207dcf0(int a);
extern "C" int memcmp(void* a, void* b, int c);
extern "C" void func_ov017_021c9c64(int a, int b);

struct Struct_0207d798 {
    unsigned short unknown_0_;
    short unknown_2_;
    signed char unknown_4_;
    char unknown_5_;
    unsigned short unknown_6_;
    signed char unknown_8_[4];
};
extern "C" void func_0207d7c0(struct Struct_0207d798* arg0);

extern int data_020e8a4c;

// USA: func_0207dba8
extern "C" ARM void func_0207dba8(struct Struct_0207d798* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_0207d798* var1 = arg0;
    int var2 = 0;
    int var3 = var2;
    int var4 = 1;
    int var5 = var2;
    int var6 = -1;
    for (; var2 < 4; var2++, var1++) {
        unsigned short var7 = var1->unknown_0_;
        if (var7 != 0 && var1->unknown_4_ < 0) {
            if (var1->unknown_6_ < 0x3e8) {
                var1->unknown_6_ = var1->unknown_6_ + var0->GetEffectiveDeltaTime();
            } else {
                int found = (memcmp(e->arr8, &data_020e8a4c, 4) == 0);
                if (found) {
                    func_ov017_021c9c64(h0, 0);
                    InitStruct0207d7c0(e);
                }
            }
        } else {
            var1->unknown_6_ = (unsigned short)var3;
        }
    }
    struct Struct_0202b2f0* var9 = (struct Struct_0202b2f0*)func_0202ae18();
    if (func_0202c508() == 0) return;
    int var10;
    for (var10 = var4; var10 < 4; var10++) {
        if (!func_0202c578(var9, var10)) continue;
        struct Struct_0207d798* var11 = arg0;
        int var12;
        for (var12 = var5; var12 < 4; var11++, var12++) {
            signed char* var13 = var11->unknown_8_;
            if (var11->unknown_0_ == 0) continue;
            if (var13[var10] != var6) continue;
            var13[var10] = (signed char)var5;
            func_0207dcf0(var11->unknown_0_);
        }
    }
}
