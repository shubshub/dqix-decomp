#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "Combat/EntryGetterTypes.h"
#include "Input/Input.h"

struct Struct_0203dce4_2;
struct SePlayer;
extern SePlayer g_sePlayer;
extern "C" void* func_0203cf4c();
extern "C" Struct_0203dce4* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" void func_0206b104(MessageSystem*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_0208beb4(unsigned char*);
extern "C" void MessageSystem_Stop(MessageSystem*);

#if defined(jpn)
extern "C" void func_0206cba0(MessageSystem*);
#else
extern "C" void func_0206b224(MessageSystem*);
#endif

// USA: func_020440cc
ARM int MessageSystem::func_020440cc() {
    if (!active) return 1;
    if (!b19c1) {
        if (unknown_19c0_) return 0;
    }
    unsigned short mask = 0x403;
    int triggered = 0;
    if (unknown_19bf_) mask |= 0x200;
#if defined(jpn)
    if (flags17ff.flag1) mask |= 0x100;
#else
    if (unknown_19cf_) mask |= 0x100;
#endif
    if (g_keyManager.TestKeysPressed(mask)) triggered = 1;
    if (g_keyManager.TestKeysPressed(KEY_DPAD)) triggered = 1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 20) triggered = 1;
    if (func_020656d0() == 0xff0c) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (unknown_1961_) {
            if (unknown_1961_ <= ticks) {
                unknown_1961_ = 0;
                triggered = 1;
            } else unknown_1961_ -= ticks;
        }
    }
    if (!triggered) return 0;
    switch (mode) {
    case 0:
        if (unknown_19be_) return 0;
        if (func_020656d0() == 0xff02) {
            Struct_0203dce4* entry = func_0203dce4((Struct_0203dce4_2*)func_0203cf4c(), selectedEntry);
            if (entry) func_02040af0(entry, unknown_183c_);
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
        mode = 5;
        func_0206b224(this);
        if (!b19d3) SePlayer_Play(&g_sePlayer, 1, 0);
#endif
        break;
    case 3:
        unknown_19bd_ = 0;
        break;
    case 2: {
        unsigned short command = func_020656d0();
#if defined(jpn)
        if (command == 0xff21) {
#else
        if (command == 0xff1f) {
#endif
            int var5 = 0xff01;
            int var6 = 0xff03;
#if defined(jpn)
            int store = 0xff2e;
#else
            int store = 0xff2c;
#endif
            int var8 = 0xff12;
            unsigned short token;
            while (unknown_78_ < unknown_6c_) {
                token = unknown_4c_[unknown_78_];
#if defined(jpn)
                if (func_02069430(this, token)) {
                    int var10 = func_02069444(this, token);
#else
                if (func_02044494(this, &token)) {
                    int var10 = func_02044420(this, &token);
#endif
                    if (var10) {
                        unknown_78_ = unknown_78_ + var10 + 1;
                        continue;
                    }
                    if (token == var5 || token == var6) break;
                    if (token == store) {
                        unknown_1844_ = unknown_183c_;
                        unknown_19b6_ = 1;
                        func_020656e4(1);
                    } else if (token == var8 && child) {
                        func_0208beb4(child);
                    }
                }
                ++unknown_78_;
            }
            func_02045688();
            mode = 0;
            func_02043040(this);
            MessageSystem_Stop(this);
            func_020430b0(this);
        } else {
#if defined(jpn)
            if (!flags17ff.flag5) SePlayer_Play(&g_sePlayer, 1, 0);
#else
            if (!b19d3) SePlayer_Play(&g_sePlayer, 1, 0);
#endif
            mode = 5;
            ++unknown_78_;
            unknown_912_ = 0;
        }
        break;
    }
    }
    return 0;
}
