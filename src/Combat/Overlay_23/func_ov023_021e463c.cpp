#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void CharacterModel_GetBody(void* p);
struct Words021e60c4 { unsigned int v[3]; };
extern "C" void CharacterModel_GetRotation(Words021e60c4* dst, char* src);
int fix32ReduceAngle0To2Pi(int angle);
void CharacterModel_SetAngle(void* obj, unsigned int val);
void CharacterModel_SetRotation(void* obj, Words021e60c4* src);
extern "C" int func_ov023_021e29d0(char* obj);

// USA: func_ov023_021e463c
extern "C" ARM void func_ov023_021e463c(void* arg0, unsigned int arg1) {
#if defined(jpn)
 enum {Enum_ov023_021e463c_296=0x124, Enum_ov023_021e463c_1588=0x56c};
#else
 enum {Enum_ov023_021e463c_296=0x128, Enum_ov023_021e463c_1588=0x634};
#endif
    char* obj = (char*)objRaw;
    Words021e60c4 s24;
    Words021e60c4 s18;
    Words021e60c4 s0c;
    Words021e60c4 s00;
    CharacterModel_GetBody(*(void**)(obj + regionalOffset0));
    unsigned short flags = *(unsigned short*)(obj + regionalOffset1);
    if (flags & 2) {
        int within = 0;
        CharacterModel_GetRotation(&s0c, *(char**)(obj + regionalOffset0));
        s24 = s0c;
        int origPos = s24.v[1];
        int base = 0x1eb;
        int divisor = 12;
        int d = fix32ReduceAngle0To2Pi(base - origPos);
        int pos;
        if (d >= 0 && d < 0x3244) {
            pos = origPos + d / divisor;
            unsigned int i;
            for (i = 0; i < count - 1; i++) {
                int dd = fix32ReduceAngle0To2Pi(base - pos);
                pos += dd / divisor;
            }
        } else if (var10 >= 0x3244 && var10 < 0x6488) {
            int var14 = 0x6488;
            var11 = var7 - (var14 - var10) / var9;
            unsigned int var15;
            for (var15 = 0; var15 < arg1 - 1; var15++) {
                int var16 = fix32ReduceAngle0To2Pi(var8 - var11);
                var11 -= (var14 - var16) / var9;
            }
        }
        int normalized = fix32ReduceAngle0To2Pi(pos);
        CharacterModel_SetAngle(*(void**)(obj + regionalOffset0), normalized);
        int diff = fix32ReduceAngle0To2Pi(0x1eb - pos);
        int absDiff = diff < 0 ? -diff : diff;
        if (absDiff < 0x28) {
            within = 1;
        } else {
            int var20 = 0x6488 - var18;
            int var21 = var20 < 0 ? -var20 : var20;
            if (var21 < 0x28) var6 = 1;
        }
        if (within) {
            int n2 = fix32ReduceAngle0To2Pi(0x1eb);
            CharacterModel_SetAngle(*(void**)(obj + regionalOffset0), n2);
            *(unsigned short*)(obj + regionalOffset1) &= ~2;
        }
    } else if (var5 & 1) {
        int var23 = 0, var24 = 0, var25 = 0;
        if (g_touchInput.pressed_) {
            int var26 = func_ov023_021e29d0(var0 + 0xd4);
            if (var26 == 0x22) var23 = 1;
            if (var26 == 0x23) var24 = 1;
            var25 = 1;
        } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
            if (var5 & 0x100) var23 = 1;
            if (var5 & 0x200) var24 = 1;
            var25 = 1;
        } else if (g_touchInput.released_) {
            var25 = 1;
        }
        if (!var25) {
            if (g_keyManager.TestKeysHeld(0x200)) var23 = 1;
            if (g_keyManager.TestKeysHeld(0x100)) var24 = 1;
        }
        if (flag5 && flag6) {
            *(unsigned short*)(obj + regionalOffset1) |= 2;
        } else if (flag5 || flag6) {
            CharacterModel_GetRotation(&s00, *(char**)(obj + regionalOffset0));
            s18 = s00;
            if (flag5) {
                s18.v[1] += (int)((float)count * 0.08f * 4096.0f);
            }
            if (var24) {
                var2.unknown_0_[1] -= (int)((float)arg1 * 0.08f * 4096.0f);
            }
            s18.v[1] = fix32ReduceAngle0To2Pi(s18.v[1]);
            CharacterModel_SetRotation(*(void**)(obj + regionalOffset0), &s18);
        }
        if (var23) {
            *(unsigned short*)(var0 + Enum_ov023_021e463c_1588) |= 0x100;
        } else {
            *(unsigned short*)(var0 + Enum_ov023_021e463c_1588) &= ~0x100;
        }
        if (var24) {
            *(unsigned short*)(var0 + Enum_ov023_021e463c_1588) |= 0x200;
        } else {
            *(unsigned short*)(var0 + Enum_ov023_021e463c_1588) &= ~0x200;
        }
    }
}
