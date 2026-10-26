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
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

struct Struct_0208ec78_2 {
    char pad[0x10];
    int val;
    struct Struct_0208ec78_2* next;
};

struct Struct_0208ec78_3 {
    unsigned char id;
    float accum;
    struct Struct_01ff91ac_7* field8;
    struct Struct_0208ec78_2* fieldC;
};

// USA: func_0208ec78
extern "C" ARM void func_0208ec78(struct Struct_0208ec78_3* p0) {
    GameState* bs = GameState::GetInstance();
    LootPointList_GetInstance();
    void* g;
    char* r;
#if defined(jpn)
    Struct_0208ec78* arr = (Struct_0208ec78*)((char*)bs + 0x5a7c);
#else
    Struct_0208ec78* arr = (Struct_0208ec78*)((char*)bs + 0x5cdc);
#endif
    g = LinkSession_GetInstance();

    if (p0->field8 != 0) {
        void* field4 = ((Object3D*)p0->field8)->GetCurrentAnimationConfig();
        if (field4 != 0) {
            Struct_0204a054_2* rate = (Struct_0204a054_2*)((BCFG*)((Struct_0204a054*)field4))->GetAnimationRecord(0);
            if (rate != 0) {
                r = (char*)rate;
                int var6 = (int)(4096.0f * ((float)(unsigned int)bs->GetEffectiveDeltaTime() / 16.666666f));
                int var7 = *(int*)(r + 0x18);
                int delta = (int)(((long long)var7 * var6 + 0x800) >> 12);
                struct Struct_0208ec78_2* node = p0->fieldC;
                while (node != 0) {
                    node->val += delta;
                    if (*(int*)(r + 0x14) < node->val) {
                        node->val = *(int*)(r + 0x10);
                    }
                    node = node->next;
                }
            }
        }
    }

    if (LinkSession_IsGuest(g) != 0) {
        return;
    }

    p0->accum = p0->accum + (float)(unsigned int)bs->GetEffectiveDeltaTime() / 1000.0f;
    if (p0->accum < 60.0f) {
        if (p0->id == 0) return;
    }
    if (p0->accum >= 60.0f) {
        p0->accum = 0.0f;
    }

    unsigned char var10 = p0->id;
    Struct_0208ec78* e;
    int var12 = 0;
    e = &arr[var10];
    if (e->fields.active == 0) var12 = 1;
    unsigned int kind = e->fields.kind;
    if (kind != 1) {
        void* ctx = Scenario_GetInstance();
        if (e->fields.kind == 2 && Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 1944) == 0) {
            var12 = 1;
        } else if (e->fields.kind == 3 && Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 1942) == 0) {
            var12 = 1;
        }
    }

    if (var12 != 0) {
        p0->id = (unsigned char)((p0->id + 1) % 100);
        return;
    }

    unsigned char var15 = 0;
    {
        int i;
        for (i = 0; i < 8; i++) {
            if (((e->word << 7) >> 24) & (1u << i)) var15++;
        }
    }

    unsigned int sel = var15;
    if (e->fields.timer == 0) {
        unsigned char var18 = 0;
        if (var15 == 0) {
            var18 = rand() % (e->fields.unknown_1_1_ + 1);
            if (var18 < e->fields.unknown_1_5_) var18 = e->fields.unknown_1_5_;
        } else if (var15 < e->fields.unknown_1_1_) {
            var18 = rand() % (e->fields.unknown_1_1_ - var15 + 1);
        }

        if (p0->id < 0x62) {
            sel = (var15 + var18) & 0xff;
            unsigned int j = rand() % e->fields.unknown_1_1_;
            while (var18 != 0) {
                unsigned int mask = 1u << j;
                unsigned int var21 = (e->word << 7) >> 24;
                if ((var21 & mask) == 0) {
                    e->fields.flags = var21 | mask;
                    var18--;
                }
                j++;
                if (j >= e->fields.unknown_1_1_) j = 0;
            }
            func_ov017_021d38f8(0, 0, (unsigned char)((e->word << 7) >> 24), p0->id, e);
        } else {
            func_0208f048((unsigned char*)p0);
        }

        e->fields.timer = e->fields.count * 30;
    }

    if (sel != e->fields.unknown_1_1_ || p0->id >= 0x62) {
        e->fields.timer = e->fields.timer - 1;
    }
    p0->id = (unsigned char)((p0->id + 1) % 100);
}
