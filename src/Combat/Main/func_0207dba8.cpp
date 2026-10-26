#include <globaldefs.h>

#include "GameState/GameState.h"

struct Struct_0202b2f0;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);
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
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo() == 0) return;
    int j;
    for (j = trueVal; j < 4; j++) {
        if (!LinkSession_IsSlotLost(search, j)) continue;
        struct Init0207d7c0* p = list;
        int k;
        for (k = resetVal; k < 4; p++, k++) {
            signed char* a = p->arr8;
            if (p->h0 == 0) continue;
            if (a[j] != negOne) continue;
            a[j] = (signed char)resetVal;
            func_0207dcf0(p->h0);
        }
    }
}
