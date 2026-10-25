#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_0208e0a8(void);
extern "C" void* func_02057924(void);
extern "C" int rand(void);
extern "C" int _s32_div_f(int a, int b);
extern "C" int Zone3D_GetGroundHeight(int seed, void* v);
int LootPointList_AppliesToMap(void* unused, char* str);

struct Struct_0208f168_2 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 4;
    unsigned int unknown_1_5_ : 4;
    unsigned int unknown_2_1_ : 8;
    unsigned int unknown_3_1_ : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_0208f168_3 {
    unsigned int unknown_0_0_ : 21;
    unsigned int unknown_2_5_ : 8;
    unsigned int unknown_3_5_ : 3;
};

struct Struct_0208f168_4 {
    unsigned int unknown_0_;
    struct Struct_0208f168_3 unknown_4_;
    struct Struct_0208f168_2* unknown_8_;
    Vector3i unknown_c_[8];
    struct Struct_0208f168_4* unknown_6c_;
};

struct Struct_0208f168_5 {
    char unknown_0_[4];
    struct Struct_0208f168_4* unknown_4_;
};

struct Struct_0208f168_6 {
    int unknown_0_;
    Vector3i unknown_4_;
    int unknown_10_;
    struct Struct_0208f168_6* unknown_14_;
};

struct Struct_0208f168 {
    char unknown_0_[8];
    void* unknown_8_;
    struct Struct_0208f168_6* unknown_c_;
};

// USA: func_0208f168
extern "C" ARM void func_0208f168(struct Struct_0208f168* arg0, void* arg1) {
    if (arg1 == 0) {
        return;
    }

    void* g = Zone3D_GetInstance();
    char* name = *(char**)((char*)g + 8);
    struct Head0208f168* h = (struct Head0208f168*)func_0208e0a8();

    if (var1 == 0) {
        return;
    }
    if (LootPointList_AppliesToMap(h, name + 5) == 0) {
        return;
    }

    if (self->obj != 0) {
        ((Object3D*)self->obj)->SetAnimationByIndex(0, 0);
        void* cfg = ((Object3D*)self->obj)->GetCurrentAnimationConfig();
        if (cfg == 0) {
            return;
        }
        BCFG::AnimationRecord* var4 = ((BCFG*)var3)->GetAnimationRecord(0);
        if (var4 == 0) {
            return;
        }

        GameState* var5 = GameState::GetInstance();
#if defined(jpn)
        struct Struct_0208f168_2* var6 = (struct Struct_0208f168_2*)((char*)var5 + 0x27c + 0x5800);
#else
        struct Struct_0208f168_2* var6 = (struct Struct_0208f168_2*)((char*)var5 + 0xdc + 0x5c00);
#endif
        struct Struct_0208f168_4* var7 = var2->unknown_4_;
        func_02057924();
        var5->GetProtagonist();

        unsigned int var8 = 0;
        while (var7 != 0) {
            int var9 = (var7->unknown_0_ << 9) >> 25;
            struct Struct_0208f168_2* var10 = &var6[var9];
            if (var10->unknown_3_7_) {
                var7->unknown_8_ = var10;
                var7->unknown_4_.unknown_2_5_ = ((*(unsigned int*)var10 << 7) >> 24);
                int var11 = var10->unknown_1_1_;
                if (var9 >= 0x62) {
                    var11 = 8;
                }
                int var12 = 0;
                for (; var12 < var11; var12++) {
                    Vector3i* var13 = var7->unknown_c_;
                    if (((*(unsigned int*)var10 << 7) >> 24) & (1 << var12)) {
                        struct Struct_0208f168_6* var14 = (struct Struct_0208f168_6*)((SafeAllocator*)arg1)->Allocate(0x18);
                        if (var14 == 0) {
                            return;
                        }
                        item->index = j + (counter << 3);
                        int base = rec->startTime;
                        item->frame = base + (rand() % (rec->endTime - base));
                        node->vec[j].y = Zone3D_GetGroundHeight((int)g, (void*)&v[j]);
                        *(Vector3i*)((int*)&item->vec) = *(Vector3i const*)((int*)&v[j]);
                        struct Item0208f168* n = self->head;
                        if (n == 0) {
                            self->head = item;
                            item->link = 0;
                        } else {
                            while (var16->unknown_14_ != 0) {
                                var16 = var16->unknown_14_;
                            }
                            var16->unknown_14_ = var14;
                            var14->unknown_14_ = 0;
                        }
                    }
                }
            }
            var8 = (var8 + 1) & 0xff;
            var7 = var7->unknown_6c_;
        }
    } else {
        return;
    }
}
