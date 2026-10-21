#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define FIRST_SHIFT 0x118
#define SECOND_SHIFT 0x1d8
#define CURSOR_OFFSET 0x2a
#define data_ov003_0217f484 data_ov003_0217e12c
#else
#define FIRST_SHIFT 0
#define SECOND_SHIFT 0
#define CURSOR_OFFSET 0x36
#endif
struct Struct_020e28dc;

struct Struct_ov003_02160854 {
    char unknown_0_[CURSOR_OFFSET];
    short unknown_36_;
};

struct Struct_ov003_02160854_2 {
    char unknown_0_[0x324 - FIRST_SHIFT];
    Struct_ov003_02160854* unknown_324_;
    char unknown_328_[0x390 - 0x328];
    Struct_020e28dc* unknown_390_;
    char unknown_394_[0x470 - SECOND_SHIFT - (0x394 - FIRST_SHIFT)];
    short* unknown_470_;
    short unknown_474_;
    char unknown_476_[0x488 - 0x476];
    short unknown_488_;
};

int IsFieldNotPositive_021a4e70(unsigned char* base);
int GetInnerFlagBit0020e28dc(Outer020e28dc* o);
int GetField0x15UnlessInactive_020e2918(signed char* obj);
int RunAndCheckFlagBit02080dd4(void* obj, int p1, int p2, int p3, unsigned char* outFlag, unsigned char extra);

extern "C" {
extern short data_ov003_0217f484[];
extern short data_ov003_0217f426[];
void func_02080558(void* arg0, int arg1, int arg2, int arg3, unsigned char arg4);
void func_020813ec(Struct_ov003_02160854* arg0, int arg1);
void func_ov003_02160794(void* arg0);
}

// USA: func_ov003_02160854
extern "C" ARM unsigned char func_ov003_02160854(Ctx02160854* self) {
    unsigned char confirmed = 0;
    unsigned char* battleWord = (unsigned char*)(int)GameState::GetInstance()->GetResources();
    if (g_keyManager.TestKeysPressed(0x401)) {
        if (func_ov017_021a4e70(var1)) {
            var0 = 1;
        }
    }

    if (func_020e28dc(arg0->unknown_390_)) {
        int var2 = func_020e2918((signed char*)arg0->unknown_390_);
        if (var2 >= 0) {
            var0 = 1;
            *arg0->unknown_470_ = var2 + 0x2c;
        }
    } else if (g_touchInput.pressed_ && arg0->unknown_470_ != 0) {
        int var3;
        int var4;
        Struct_ov003_02160854* var5 = arg0->unknown_324_;
        g_touchInput.GetTouchPoint(&var3, &var4);
        int var6 = func_02080dd4(var5, arg0->unknown_488_, (short)var3, (short)var4, &var0, 0);
        if (var6 < 0)
            return 0;

        int var7 = 0;
#if defined(jpn)
        while (data_ov003_0217f484[var7] >= 0) {
#else
        for (;;) {
#endif
#if defined(jpn)
            short var8 = data_ov003_0217f484[var7++];
#else
            short var8 = data_ov003_0217f484[var7];
#endif
#if !defined(jpn)
            if (var8 < 0)
                break;
#endif
#if !defined(jpn)
            var7++;
#endif
            if (var8 > var6 || var6 > data_ov003_0217f484[var7++])
                continue;
            func_02080558(var5, arg0->unknown_488_, (short)(var6 + 4), 0, 0);
            func_02080558(var5, arg0->unknown_488_, (short)(var6 + 8), 0, 0);
#if !defined(jpn)
            short var9 = data_ov003_0217f426[(var7 >> 1) - 1];
            if (var9 < 0)
                continue;
            func_02080558(var5, arg0->unknown_488_, (short)(var9 + (var6 - var8)), 0, 0);
#endif
        }

        *arg0->unknown_470_ = var6;
        short var10 = *arg0->unknown_470_;
        if (arg0->unknown_474_ != var10)
            var5->unknown_36_ = var10;
        func_020813ec(var5, arg0->unknown_488_);
        func_ov003_02160794(arg0);
    }
    return var0;
}
