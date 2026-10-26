#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void CharacterModel_GetBody(void* p);
struct Words021e60c4 { unsigned int v[3]; };
extern "C" void CharacterModel_GetRotation(Words021e60c4* dst, char* src);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void CharacterModel_SetAngle(void* obj, unsigned int val);
extern "C" void CharacterModel_SetRotation(void* obj, Words021e60c4* src);
extern "C" int func_ov023_021e29d0(char* obj);

// USA: func_ov023_021e463c
extern "C" ARM void func_ov023_021e463c(void* objRaw, unsigned int count) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x56c};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x634};
#endif
    char* obj = (char*)objRaw;
    Words021e60c4 var1;
    Words021e60c4 s18;
    Words021e60c4 s0c;
    Words021e60c4 s00;
    CharacterModel_GetBody(*(void**)(obj + regionalOffset0));
    unsigned short flags = *(unsigned short*)(obj + regionalOffset1);
    if (flags & 2) {
        int var6 = 0;
        CharacterModel_GetRotation(&s0c, *(char**)(obj + regionalOffset0));
        var1 = s0c;
        int var7 = var1.v[1];
        int base = 0x1eb;
        int var9 = 12;
        int d = fix32ReduceAngle0To2Pi(base - var7);
        int pos;
        if (d >= 0 && d < 0x3244) {
            pos = var7 + d / var9;
            unsigned int i;
            for (i = 0; i < count - 1; i++) {
                int var13 = fix32ReduceAngle0To2Pi(base - pos);
                pos += var13 / var9;
            }
        } else if (d >= 0x3244 && d < 0x6488) {
            int span = 0x6488;
            pos = var7 - (span - d) / var9;
            unsigned int i;
            for (i = 0; i < count - 1; i++) {
                int var16 = fix32ReduceAngle0To2Pi(base - pos);
                pos -= (span - var16) / var9;
            }
        }
        int normalized = fix32ReduceAngle0To2Pi(pos);
        CharacterModel_SetAngle(*(void**)(obj + regionalOffset0), normalized);
        int diff = fix32ReduceAngle0To2Pi(0x1eb - pos);
        int var19 = diff < 0 ? -diff : diff;
        if (var19 < 0x28) {
            var6 = 1;
        } else {
            int var20 = 0x6488 - diff;
            int var21 = var20 < 0 ? -var20 : var20;
            if (var21 < 0x28) var6 = 1;
        }
        if (var6) {
            int n2 = fix32ReduceAngle0To2Pi(0x1eb);
            CharacterModel_SetAngle(*(void**)(obj + regionalOffset0), n2);
            *(unsigned short*)(obj + regionalOffset1) &= ~2;
        }
    } else if (flags & 1) {
        int flag5 = 0, var24 = 0, var25 = 0;
        if (g_touchInput.pressed_) {
            int v = func_ov023_021e29d0(obj + 0xd4);
            if (v == 0x22) flag5 = 1;
            if (v == 0x23) var24 = 1;
            var25 = 1;
        } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
            if (flags & 0x100) flag5 = 1;
            if (flags & 0x200) var24 = 1;
            var25 = 1;
        } else if (g_touchInput.released_) {
            var25 = 1;
        }
        if (!var25) {
            if (g_keyManager.TestKeysHeld(0x200)) flag5 = 1;
            if (g_keyManager.TestKeysHeld(0x100)) var24 = 1;
        }
        if (flag5 && var24) {
            *(unsigned short*)(obj + regionalOffset1) |= 2;
        } else if (flag5 || var24) {
            CharacterModel_GetRotation(&s00, *(char**)(obj + regionalOffset0));
            s18 = s00;
            if (flag5) {
                s18.v[1] += (int)((float)count * 0.08f * 4096.0f);
            }
            if (var24) {
                s18.v[1] -= (int)((float)count * 0.08f * 4096.0f);
            }
            s18.v[1] = fix32ReduceAngle0To2Pi(s18.v[1]);
            CharacterModel_SetRotation(*(void**)(obj + regionalOffset0), &s18);
        }
        if (flag5) {
            *(unsigned short*)(obj + regionalOffset1) |= 0x100;
        } else {
            *(unsigned short*)(obj + regionalOffset1) &= ~0x100;
        }
        if (var24) {
            *(unsigned short*)(obj + regionalOffset1) |= 0x200;
        } else {
            *(unsigned short*)(obj + regionalOffset1) &= ~0x200;
        }
    }
}
