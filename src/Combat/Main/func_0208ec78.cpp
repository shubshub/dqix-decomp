#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#include "GameState/GameState.h"


struct Struct_01ff91ac_7;

struct Struct_0204a054;
struct Struct_0204a054_2;

extern "C" void LootPointList_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0208f048(unsigned char* p0);
extern "C" int rand(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);

struct Struct_0208ec78_2 {
    char unknown_0_[0x10];
    int unknown_10_;
    struct Struct_0208ec78_2* unknown_14_;
};

struct Struct_0208ec78_3 {
    unsigned char unknown_0_;
    float unknown_4_;
    struct Struct_01ff91ac_7* unknown_8_;
    struct Struct_0208ec78_2* unknown_c_;
};

// USA: func_0208ec78
extern "C" ARM void func_0208ec78(struct Param0208ec78* p0) {
    GameState* bs = GameState::GetInstance();
    LootPointList_GetInstance();
    void* g;
    char* r;
#if defined(jpn)
    Struct_0208ec78* var3 = (Struct_0208ec78*)((char*)var0 + 0x5a7c);
#else
    Struct_0208ec78* var3 = (Struct_0208ec78*)((char*)var0 + 0x5cdc);
#endif
    g = LinkSession_GetInstance();

    if (arg0->unknown_8_ != 0) {
        void* var4 = ((Object3D*)arg0->unknown_8_)->GetCurrentAnimationConfig();
        if (var4 != 0) {
            Struct_0204a054_2* var5 = (Struct_0204a054_2*)((BCFG*)((Struct_0204a054*)var4))->GetAnimationRecord(0);
            if (var5 != 0) {
                var2 = (char*)var5;
                int var6 = (int)(4096.0f * ((float)(unsigned int)var0->GetEffectiveDeltaTime() / 16.666666f));
                int var7 = *(int*)(var2 + 0x18);
                int var8 = (int)(((long long)var7 * var6 + 0x800) >> 12);
                struct Struct_0208ec78_2* var9 = arg0->unknown_c_;
                while (var9 != 0) {
                    var9->unknown_10_ += var8;
                    if (*(int*)(var2 + 0x14) < var9->unknown_10_) {
                        var9->unknown_10_ = *(int*)(var2 + 0x10);
                    }
                    var9 = var9->unknown_14_;
                }
            }
        }
    }

    if (LinkSession_IsGuest(g) != 0) {
        return;
    }

    arg0->unknown_4_ = arg0->unknown_4_ + (float)(unsigned int)var0->GetEffectiveDeltaTime() / 1000.0f;
    if (arg0->unknown_4_ < 60.0f) {
        if (arg0->unknown_0_ == 0) return;
    }
    if (arg0->unknown_4_ >= 60.0f) {
        arg0->unknown_4_ = 0.0f;
    }

    unsigned char id0 = p0->id;
    LootPointState* e;
    int avail = 0;
    e = &arr[id0];
    if (e->fields.active == 0) avail = 1;
    unsigned int kind = e->fields.kind;
    if (kind != 1) {
        void* ctx = Scenario_GetInstance();
        if (e->fields.kind == 2 && Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 1944) == 0) {
            avail = 1;
        } else if (e->fields.kind == 3 && Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 1942) == 0) {
            avail = 1;
        }
    }

    if (var12 != 0) {
        arg0->unknown_0_ = (unsigned char)((arg0->unknown_0_ + 1) % 100);
        return;
    }

    unsigned char var15 = 0;
    {
        int var16;
        for (var16 = 0; var16 < 8; var16++) {
            if (((var11->unknown1_0_ << 7) >> 24) & (1u << var16)) var15++;
        }
    }

    unsigned int var17 = var15;
    if (var11->unknown_0_.unknown_0_0_ == 0) {
        unsigned char var18 = 0;
        if (var15 == 0) {
            var18 = rand() % (var11->unknown_0_.unknown_1_1_ + 1);
            if (var18 < var11->unknown_0_.unknown_1_5_) var18 = var11->unknown_0_.unknown_1_5_;
        } else if (var15 < var11->unknown_0_.unknown_1_1_) {
            var18 = rand() % (var11->unknown_0_.unknown_1_1_ - var15 + 1);
        }

        if (arg0->unknown_0_ < 0x62) {
            var17 = (var15 + var18) & 0xff;
            unsigned int var19 = rand() % var11->unknown_0_.unknown_1_1_;
            while (var18 != 0) {
                unsigned int var20 = 1u << var19;
                unsigned int var21 = (var11->unknown1_0_ << 7) >> 24;
                if ((var21 & var20) == 0) {
                    var11->unknown_0_.unknown_2_1_ = var21 | var20;
                    var18--;
                }
                var19++;
                if (var19 >= var11->unknown_0_.unknown_1_1_) var19 = 0;
            }
            func_ov017_021d38f8(0, 0, (unsigned char)((var11->unknown1_0_ << 7) >> 24), arg0->unknown_0_, var11);
        } else {
            func_0208f048((unsigned char*)arg0);
        }

        var11->unknown_0_.unknown_0_0_ = var11->unknown_0_.unknown_3_1_ * 30;
    }

    if (var17 != var11->unknown_0_.unknown_1_1_ || arg0->unknown_0_ >= 0x62) {
        var11->unknown_0_.unknown_0_0_ = var11->unknown_0_.unknown_0_0_ - 1;
    }
    arg0->unknown_0_ = (unsigned char)((arg0->unknown_0_ + 1) % 100);
}
