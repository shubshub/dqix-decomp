#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void* func_ov023_021fad18(void* obj);

struct Struct_ov023_021faed0;
extern "C" ARM void* func_ov023_021fa854(char* obj, unsigned int idx);

extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

extern "C" void func_ov011_02184a40(void* a, int b);

#if defined(jpn)
extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetMainOamBuffer(void);
#endif

struct Struct_ov023_021faed0 {
    unsigned short unknown_0_;
    char pad1[0x14 - 0x2];
    int f14;
    int f18;
    char pad2[0x22 - 0x1c];
    unsigned char unknown_22_;
    char pad3[0x25 - 0x23];
    signed char unknown_25_;
    signed char unknown_26_;
};

struct Struct_ov023_021faed0_2 {
    char pad0[0xc];
    unsigned char unknown_c_;
    char pad1[0x20 - 0xd];
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    char pad2[0x28 - 0x26];
    int f28;
    int unknown_2c_;
    signed short unknown_30_;
    signed short unknown_32_;
    signed short f34;
    signed short unknown_36_;
    signed char unknown_38_;
    signed char unknown_39_;
#if defined(jpn)
    unsigned short f3c;
    unsigned short unknown_3e_;
    unsigned short f40;
    unsigned short unknown1_42_;
    char unknown_42_[2];
    int unknown_44_;
    int f46;
    signed short unknown1_48_;
    unsigned char unknown_4e_;

#else
    unsigned char unknown_3a_;
    char pad3[0x3c - 0x3b];
    unsigned short f3c;
    unsigned short unknown_3e_;
    unsigned short f40;
    unsigned short unknown1_42_;
    unsigned short unknown1_44_;
    unsigned short f46;
    signed short unknown1_48_;
    unsigned char unknown_4a_;
    unsigned char unknown_4b_;

#endif
};

// USA: func_ov023_021faed0
extern "C" ARM void func_ov023_021faed0(struct Struct_ov023_021faed0_2* obj, void* arg1) {
    if ((obj->unknown_c_ & 8) == 0) {
        void** listHead = (void**)func_ov011_021849c8(arg1);
        void* node = func_ov023_021f6880(listHead, obj->f20);
        void* z = func_ov023_021fad18(node);
        struct Struct_ov023_021faed0* entryPtr = (struct Struct_ov023_021faed0*)func_ov023_021fa854((char*)z, obj->f22);
        int* state = (int*)MessageSystem_GetInstance();

        if (entryPtr != 0) {
#if defined(jpn)
            int delta = 0;
            signed char var6 = entryPtr->unknown_25_;
            signed char var7 = entryPtr->unknown_26_;
            if (obj->unknown_4e_ != 0) delta = 0x1000;
            entryPtr->unknown_22_ = (unsigned char)obj->f24;
            entryPtr->f14 = obj->f28 + delta;
            entryPtr->f18 = obj->unknown_2c_ + delta;
            signed char v38 = obj->unknown_38_;
            if (v38 >= 0) entryPtr->unknown_25_ = v38 & 0xf;
            signed char var9 = obj->unknown_39_;
            if (var9 >= 0) entryPtr->unknown_26_ = var9 & 3;
            SpriteContext_DrawSprite(z, entryPtr);
            entryPtr->f14 = obj->f28;
            entryPtr->f18 = obj->unknown_2c_;
            obj->unknown_4e_ = 0;
            entryPtr->unknown_25_ = var6;
            entryPtr->unknown_26_ = var7;
            int selected = obj->unknown_44_;
            if (obj->f46 != -1) {
                int cond = *(int*)((char*)state + 0x10c) >= 2;
                if (cond) selected = obj->f46;
            }
            if (selected >= 0) {
                OamManager_GetInstance();
                struct Slot { unsigned int word; unsigned int next; };
                Slot* table = (Slot*)OamManager_GetMainOamBuffer();
                unsigned int word = table[obj->f24].word & 0x3fff3fff;
                word |= selected;
                table[obj->f24].word = word;
            }

#else
            int dx = 0, dy = 0;
            if (obj->unknown_4a_ != 0) {
                dx = 0x1000;
                dy = 0x1000;
            } else if (obj->unknown_4b_ != 0) {
                dx = -0x1000;
                dy = 0x1000;
            }

            signed char var16 = entryPtr->unknown_25_;
            signed char var17 = entryPtr->unknown_26_;
            entryPtr->unknown_22_ = (unsigned char)obj->f24;
            entryPtr->f14 = obj->f28 + dx;
            entryPtr->f18 = obj->unknown_2c_ + dy;
            signed char v38 = obj->unknown_38_;
            if (v38 >= 0) entryPtr->unknown_25_ = v38 & 0xf;
            signed char var19 = obj->unknown_39_;
            if (var19 >= 0) entryPtr->unknown_26_ = var19 & 3;

            unsigned short v44 = obj->unknown1_44_;
            if (obj->f46 != 0) {
                int cond = *(int*)((char*)state + 0x14c) >= 2;
                if (cond) v44 = obj->f46;
            }
            if (v44 != 0) entryPtr->unknown_0_ = v44;

            int var22 = *(int*)((char*)state + 0x14c) >= 2;
            if (var22 && obj->unknown_3a_ != 0) {
                unsigned short v0 = entryPtr->unknown_0_;
                if (v0 > 2) {
                    entryPtr->unknown_0_ = v0 - 2;
                    SpriteContext_DrawSprite(z, entryPtr);
                    entryPtr->unknown_0_ = v0;
                }
            } else {
                SpriteContext_DrawSprite(z, entryPtr);
            }

            entryPtr->f14 = obj->f28;
            entryPtr->f18 = obj->unknown_2c_;
            obj->unknown_4a_ = 0;
            obj->unknown_4b_ = 0;
            entryPtr->unknown_25_ = var16;
            entryPtr->unknown_26_ = var17;
#endif

        }
    }

    if ((obj->unknown_c_ & 0x10) == 0) {
        unsigned char var24 = g_touchInput.pressed_;
        int var25 = 0;
        if (g_touchInput.isRepeatValid_ != 0 &&
            g_touchInput.currentReading_.isHeld != 0) {
            var25 = 1;
        }
        unsigned char var26 = g_touchInput.released_;
        GameState* battleStruct = GameState::GetInstance();
        int var28 = battleStruct->GetEffectiveDeltaTime();
        int result = 0;

        if (var24 != 0 && (obj->unknown_c_ & 0x20) == 0) {
            result = obj->f3c;
            obj->unknown_c_ |= 0x20;
            obj->unknown1_48_ = 0x1f4;
            goto DONE;
        }
        if (var25 != 0 && (obj->unknown_c_ & 0x20) != 0) {
            signed short v48 = obj->unknown1_48_;
            result = obj->unknown_3e_;
            if (v48 > 0) {
                obj->unknown1_48_ = v48 - var28;
                goto DONE;
            }
            unsigned short var31 = obj->unknown1_42_;
            if (var31 != 0) result = var31;
            goto DONE;
        }
        if (var26 != 0 && (obj->unknown_c_ & 0x20) != 0) {
            result = obj->f40;
            goto DONE;
        }
        obj->unknown_c_ &= ~0x20;

DONE:
        if (result == 0) return;

        int px, var33;
        g_touchInput.GetTouchPoint(&px, &var33);
        int var34 = (obj->f28 >> 12) + obj->unknown_30_;
        int var35 = (obj->unknown_2c_ >> 12) + obj->unknown_32_;
        int var36 = var34 + obj->f34;
        int var37 = var35 + obj->unknown_36_;
        int var38 = var33;
        int var39 = 0;
        if (var34 <= px && px < var36 && var35 <= var38 && var38 < var37) var39 = 1;

        if (var39 != 0) {
            if (result == 0) return;
            if (obj->unknown_c_ & 0x40) {
                SePlayer_Play(&g_sePlayer, 1, 0);
            }
            func_ov011_02184a40(arg1, result);
        } else {
            obj->unknown_c_ &= ~0x20;
        }
    }
}
