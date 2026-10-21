#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int val);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int val);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(unsigned char* arg0, int arg1);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" ARM void func_ov009_021855dc(unsigned char* arg0, int arg1);
#endif

extern "C" int func_0202ee38(char* arg0, int arg1, int arg2);
extern "C" void func_0202ee58(char* arg0, int arg1, int arg2);

#if defined(jpn)
#define data_ov009_0218a9c8 data_ov009_0218b9a4
#endif
extern Vector3fix data_ov009_0218a9c8;
#if defined(jpn)
#define data_ov009_0218a9d4 data_ov009_0218b9b0
#endif
extern Vector3fix data_ov009_0218a9d4;
#if defined(jpn)
#define data_ov009_0218a9e0 data_ov009_0218b9bc
#endif
extern Vector3fix data_ov009_0218a9e0;
#if defined(jpn)
#define data_ov009_0218a9ec data_ov009_0218b9c8
#endif
extern Vector3fix data_ov009_0218a9ec;

// USA: func_ov009_021866f0  (semantic: AdvanceStatStep_021866f0)
extern "C" ARM void func_ov009_021866f0(CharacterCreationUI* self) {
    unsigned char step = self->step;
    if (step == 0) {
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        int idx = self->sex;
        unsigned char val = self->faceStyle[idx];
        CharacterCreationUI_MoveCursorToSlot(self, val);

        Vector3fix var3 = data_ov009_0218a9c8;
        Vector3fix var4 = data_ov009_0218a9d4;
        func_0202ee38((char*)arg0->unknown_924_, (int)&var3, 0x1e000);
        func_0202ee58((char*)arg0->unknown_924_, (int)&var4, 0x1e000);

        arg0->unknown_d9c_ |= 1;
        arg0->unknown_c59_ = arg0->unknown_c59_ + 1;
        return;
    }
    if (var0 == 1) {
        if (arg0->unknown_d9c_ & 0x80) {
            return;
        }
        int idx = self->sex;
        unsigned char val = self->faceStyle[idx];
        CharacterCreationUI_ApplyChoice(self, val);
        self->step = self->step + 1;
        return;
    }
    if (var0 != 2) {
        return;
    }

    int result = CharacterCreationUI_HandleInput(self);
    int flag = 0;
    if (result == -2) {
        SetStatValue021855dc((unsigned char*)self, 6);
        flag = 1;
    } else if (result == -3) {
        SetStatValue021855dc((unsigned char*)self, 4);
        flag = 1;
    } else if (result >= 0x65 && result <= 0x6c) {
        int idx = self->sex;
        int v = result - 0x64;
        signed char arrv = self->furthestState[idx];
        if (v <= arrv) {
            signed char cur = self->state;
            if (v != cur) {
                SetStatValue021855dc((unsigned char*)self, v & 0xff);
                flag = 1;
            }
        }
    }

    if (var8 != 0) {
        Vector3fix var13 = data_ov009_0218a9e0;
        Vector3fix var14 = data_ov009_0218a9ec;
        func_0202ee38((char*)arg0->unknown_924_, (int)&var13, 0x1e000);
        func_0202ee58((char*)arg0->unknown_924_, (int)&var14, 0x1e000);
    }
}
