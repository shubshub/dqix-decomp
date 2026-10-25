#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

int MessageSystem_GetInstance(void);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void* func_ov023_021fad18(void* obj);

struct Struct_ov023_021faed0;
extern "C" ARM void* func_ov023_021fa854(char* arg0, unsigned int arg1);

extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

extern "C" void func_ov011_02184a40(void* arg0, int arg1);

#if defined(jpn)
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be40(void);
#endif

struct Struct_ov023_021faed0 {
    unsigned short unknown_0_;
    char unknown_2_[0x14 - 0x2];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x25 - 0x23];
    signed char unknown_25_;
    signed char unknown_26_;
};

struct Struct_ov023_021faed0_2 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x20 - 0xd];
    unsigned short unknown_20_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    char unknown_26_[0x28 - 0x26];
    int unknown_28_;
    int unknown_2c_;
    signed short unknown_30_;
    signed short unknown_32_;
    signed short unknown_34_;
    signed short unknown_36_;
    signed char unknown_38_;
    signed char unknown_39_;
#if defined(jpn)
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown1_42_;
    char unknown_42_[2];
    int unknown_44_;
    int unknown_48_;
    signed short unknown1_48_;
    unsigned char unknown_4e_;

#else
    unsigned char unknown_3a_;
    char unknown_3b_[0x3c - 0x3b];
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown1_42_;
    unsigned short unknown1_44_;
    unsigned short unknown_46_;
    signed short unknown1_48_;
    unsigned char unknown_4a_;
    unsigned char unknown_4b_;

#endif
};

// USA: func_ov023_021faed0  (semantic: SyncEntryPositionAndDispatch_021faed0)
extern "C" ARM void func_ov023_021faed0(struct Obj021faed0* obj, void* arg1) {
    if ((obj->flags0xc & 8) == 0) {
        void** listHead = (void**)func_ov011_021849c8(arg1);
        void* node = func_ov023_021f6880(listHead, obj->f20);
        void* z = func_ov023_021fad18(node);
        struct Entry021faed0* entryPtr = (struct Entry021faed0*)GetEntryPtr_021fa854((char*)z, obj->f22);
        int* state = (int*)MessageSystem_GetInstance();

        if (var3 != 0) {
#if defined(jpn)
            int delta = 0;
            signed char saved25 = entryPtr->b25;
            signed char saved26 = entryPtr->b26;
            if (obj->f4a != 0) delta = 0x1000;
            entryPtr->b22 = (unsigned char)obj->f24;
            entryPtr->f14 = obj->f28 + delta;
            entryPtr->f18 = obj->f2c + delta;
            signed char v38 = obj->f38;
            if (v38 >= 0) entryPtr->b25 = v38 & 0xf;
            signed char v39 = obj->f39;
            if (v39 >= 0) entryPtr->b26 = v39 & 3;
            SpriteContext_DrawSprite(z, entryPtr);
            entryPtr->f14 = obj->f28;
            entryPtr->f18 = obj->f2c;
            obj->f4a = 0;
            entryPtr->b25 = saved25;
            entryPtr->b26 = saved26;
            int selected = obj->f44;
            if (obj->f46 != -1) {
                int cond = *(int*)((char*)state + 0x10c) >= 2;
                if (cond) selected = obj->f46;
            }
            if (var10 >= 0) {
                func_0203bd08();
                struct Struct_ov000_021700dc { unsigned int unknown_0_; unsigned int unknown_4_; };
                Struct_ov000_021700dc* var12 = (Struct_ov000_021700dc*)func_0203be40();
                unsigned int var13 = var12[arg0->unknown_24_].unknown_0_ & 0x3fff3fff;
                var13 |= var10;
                var12[arg0->unknown_24_].unknown_0_ = var13;
            }

#else
            int var14 = 0, var15 = 0;
            if (arg0->unknown_4a_ != 0) {
                var14 = 0x1000;
                var15 = 0x1000;
            } else if (arg0->unknown_4b_ != 0) {
                var14 = -0x1000;
                var15 = 0x1000;
            }

            signed char var16 = var3->unknown_25_;
            signed char var17 = var3->unknown_26_;
            var3->unknown_22_ = (unsigned char)arg0->unknown_24_;
            var3->unknown_14_ = arg0->unknown_28_ + var14;
            var3->unknown_18_ = arg0->unknown_2c_ + var15;
            signed char var18 = arg0->unknown_38_;
            if (var18 >= 0) var3->unknown_25_ = var18 & 0xf;
            signed char var19 = arg0->unknown_39_;
            if (var19 >= 0) var3->unknown_26_ = var19 & 3;

            unsigned short var20 = arg0->unknown1_44_;
            if (arg0->unknown_46_ != 0) {
                int var21 = *(int*)((char*)var4 + 0x14c) >= 2;
                if (var21) var20 = arg0->unknown_46_;
            }
            if (var20 != 0) var3->unknown_0_ = var20;

            int cond2 = *(int*)((char*)state + 0x14c) >= 2;
            if (cond2 && obj->f3a != 0) {
                unsigned short v0 = entryPtr->us0;
                if (v0 > 2) {
                    entryPtr->us0 = v0 - 2;
                    SpriteContext_DrawSprite(z, entryPtr);
                    entryPtr->us0 = v0;
                }
            } else {
                SpriteContext_DrawSprite(z, entryPtr);
            }

            var3->unknown_14_ = arg0->unknown_28_;
            var3->unknown_18_ = arg0->unknown_2c_;
            arg0->unknown_4a_ = 0;
            arg0->unknown_4b_ = 0;
            var3->unknown_25_ = var16;
            var3->unknown_26_ = var17;
#endif

        }
    }

    if ((arg0->unknown_c_ & 0x10) == 0) {
        unsigned char var24 = g_touchInput.pressed_;
        int var25 = 0;
        if (g_touchInput.isRepeatValid_ != 0 &&
            g_touchInput.currentReading_.isHeld != 0) {
            var25 = 1;
        }
        unsigned char var26 = g_touchInput.released_;
        GameState* var27 = GameState::GetInstance();
        int var28 = var27->GetEffectiveDeltaTime();
        int var29 = 0;

        if (var24 != 0 && (arg0->unknown_c_ & 0x20) == 0) {
            var29 = arg0->unknown_3c_;
            arg0->unknown_c_ |= 0x20;
            arg0->unknown1_48_ = 0x1f4;
            goto DONE;
        }
        if (var25 != 0 && (arg0->unknown_c_ & 0x20) != 0) {
            signed short var30 = arg0->unknown1_48_;
            var29 = arg0->unknown_3e_;
            if (var30 > 0) {
                arg0->unknown1_48_ = var30 - var28;
                goto DONE;
            }
            unsigned short var31 = arg0->unknown1_42_;
            if (var31 != 0) var29 = var31;
            goto DONE;
        }
        if (var26 != 0 && (arg0->unknown_c_ & 0x20) != 0) {
            var29 = arg0->unknown_40_;
            goto DONE;
        }
        arg0->unknown_c_ &= ~0x20;

DONE:
        if (var29 == 0) return;

        int var32, var33;
        g_touchInput.GetTouchPoint(&var32, &var33);
        int var34 = (arg0->unknown_28_ >> 12) + arg0->unknown_30_;
        int var35 = (arg0->unknown_2c_ >> 12) + arg0->unknown_32_;
        int var36 = var34 + arg0->unknown_34_;
        int var37 = var35 + arg0->unknown_36_;
        int var38 = var33;
        int var39 = 0;
        if (var34 <= var32 && var32 < var36 && var35 <= var38 && var38 < var37) var39 = 1;

        if (overlap != 0) {
            if (result == 0) return;
            if (obj->flags0xc & 0x40) {
                SePlayer_Play(&g_sePlayer, 1, 0);
            }
            func_ov011_02184a40(arg1, var29);
        } else {
            arg0->unknown_c_ &= ~0x20;
        }
    }
}
