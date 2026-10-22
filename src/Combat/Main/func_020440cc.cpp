#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "Combat/EntryGetterTypes.h"
#include "Input/Input.h"

struct EntryList_203dce4;
struct SePlayer;
extern SePlayer g_sePlayer;
void* GetGlobalPtr021075f4_0203cf4c();
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
extern "C" void func_0206b104(MessageSystem*);
void SePlayer_Play(SePlayer*, int, int);
void SetFlag0x2IfByte0xd4Not3_0208beb4(unsigned char*);
extern "C" void func_02043124(MessageSystem*);

#if defined(jpn)
extern "C" void func_0206cba0(Struct_02021b84*);
#else
extern "C" void func_0206b224(Struct_02021b84*);
#endif

// USA: func_020440cc
ARM int Struct_02021b84::func_020440cc() {
    if (!unknown_998_) return 1;
    if (!unknown_19c1_) {
        if (unknown_19c0_) return 0;
    }
    unsigned short var0 = 0x403;
    int var1 = 0;
    if (unknown_19bf_) var0 |= 0x200;
#if defined(jpn)
    if (unknown_17ff_.unknown_0_1_) var0 |= 0x100;
#else
    if (unknown_19cf_) var0 |= 0x100;
#endif
    if (g_keyManager.TestKeysPressed(var0)) var1 = 1;
    if (g_keyManager.TestKeysPressed(0xf0)) var1 = 1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 20) var1 = 1;
    if (func_020656d0() == 0xff0c) {
        unsigned int var2 = GameState::GetInstance()->GetTickCount();
        if (unknown_1961_) {
            if (unknown_1961_ <= var2) {
                unknown_1961_ = 0;
                var1 = 1;
            } else unknown_1961_ -= var2;
        }
    }
    if (!var1) return 0;
    switch (unknown_9a0_) {
    case 0:
        if (unknown_19be_) return 0;
        if (func_020656d0() == 0xff02) {
            Struct_0203dce4* var3 = func_0203dce4((Struct_0203dce4_2*)func_0203cf4c(), unknown_1838_);
            if (var3) func_02040af0(var3, unknown_183c_);
        }
        return 1;
    case 1:
        unknown_19ae_ = 0;
        unknown_19af_ = 0;
        unknown_19cd_ = 1;
        unknown_40_ = 0;
        unknown_44_ = 0;
        unknown_912_ = 0;
        func_0206b104(this);
#if defined(jpn)
        func_0206cba0(this);
        mode = 5;
        if (!flags17ff.flag5) SePlayer_Play(&g_sePlayer, 1, 0);
#else
        unknown_9a0_ = 5;
        func_0206b224(this);
        if (!b19d3) SePlayer_Play(&g_sePlayer, 1, 0);
#endif
        break;
    case 3:
        unknown_19bd_ = 0;
        break;
    case 2: {
        unsigned short var4 = func_020656d0();
#if defined(jpn)
        if (var4 == 0xff21) {
#else
        if (var4 == 0xff1f) {
#endif
            int var5 = 0xff01;
            int var6 = 0xff03;
#if defined(jpn)
            int var7 = 0xff2e;
#else
            int var7 = 0xff2c;
#endif
            int var8 = 0xff12;
            unsigned short var9;
            while (unknown_78_ < unknown_6c_) {
                var9 = unknown_4c_[unknown_78_];
#if defined(jpn)
                if (func_02069430(this, var9)) {
                    int var10 = func_02069444(this, var9);
#else
                if (func_02044494(this, &var9)) {
                    int var10 = func_02044420(this, &var9);
#endif
                    if (var10) {
                        unknown_78_ = unknown_78_ + var10 + 1;
                        continue;
                    }
                    if (var9 == var5 || var9 == var6) break;
                    if (var9 == var7) {
                        unknown_1844_ = unknown_183c_;
                        unknown_19b6_ = 1;
                        func_020656e4(1);
                    } else if (var9 == var8 && unknown_8c_) {
                        func_0208beb4(unknown_8c_);
                    }
                }
                ++unknown_78_;
            }
            func_02045688();
            unknown_9a0_ = 0;
            func_02043040(this);
            func_02043124(this);
            func_020430b0(this);
        } else {
#if defined(jpn)
            if (!flags17ff.flag5) SePlayer_Play(&g_sePlayer, 1, 0);
#else
            if (!b19d3) SePlayer_Play(&g_sePlayer, 1, 0);
#endif
            unknown_9a0_ = 5;
            ++unknown_78_;
            unknown_912_ = 0;
        }
        break;
    }
    }
    return 0;
}
