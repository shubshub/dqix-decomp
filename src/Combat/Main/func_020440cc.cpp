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
extern "C" void func_0206cba0(MessageSystem*);
#else
extern "C" void func_0206b224(MessageSystem*);
#endif

// USA: func_020440cc
ARM int MessageSystem::func_020440cc() {
    if (!active) return 1;
    if (!b19c1) {
        if (b19c0) return 0;
    }
    unsigned short mask = 0x403;
    int triggered = 0;
    if (b19bf) mask |= 0x200;
#if defined(jpn)
    if (flags17ff.flag1) mask |= 0x100;
#else
    if (b19cf) mask |= 0x100;
#endif
    if (g_keyManager.TestKeysPressed(mask)) triggered = 1;
    if (g_keyManager.TestKeysPressed(0xf0)) triggered = 1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 20) triggered = 1;
    if (GetIndexedHalfword_020656d0() == 0xff0c) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (inputDelay) {
            if (inputDelay <= ticks) {
                inputDelay = 0;
                triggered = 1;
            } else inputDelay -= ticks;
        }
    }
    if (!triggered) return 0;
    switch (mode) {
    case 0:
        if (b19be) return 0;
        if (GetIndexedHalfword_020656d0() == 0xff02) {
            Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)GetGlobalPtr021075f4_0203cf4c(), selectedEntry);
            if (entry) SetValueOnActiveChild02040af0(entry, selectedValue);
        }
        return 1;
    case 1:
        b19ae = 0;
        b19af = 0;
        b19cd = 1;
        stream40 = 0;
        stream44 = 0;
        b912 = 0;
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
        b19bd = 0;
        break;
    case 2: {
        unsigned short command = GetIndexedHalfword_020656d0();
#if defined(jpn)
        if (command == 0xff21) {
#else
        if (command == 0xff1f) {
#endif
            int stopA = 0xff01;
            int stopB = 0xff03;
#if defined(jpn)
            int store = 0xff2e;
#else
            int store = 0xff2c;
#endif
            int childFlag = 0xff12;
            unsigned short token;
            while (tokenIndex < tokenCount) {
                token = firstLineBuffer[tokenIndex];
#if defined(jpn)
                if (func_02069430(this, token)) {
                    int skip = func_02069444(this, token);
#else
                if (IsHighByteFF02044494(this, &token)) {
                    int skip = Dispatch02044420(this, &token);
#endif
                    if (skip) {
                        tokenIndex = tokenIndex + skip + 1;
                        continue;
                    }
                    if (token == stopA || token == stopB) break;
                    if (token == store) {
                        pendingValue = selectedValue;
                        pendingValueActive = 1;
                        CheckAndClearFlag020656e4(1);
                    } else if (token == childFlag && child) {
                        SetFlag0x2IfByte0xd4Not3_0208beb4(child);
                    }
                }
                ++tokenIndex;
            }
            ProcessPendingFlag02045688();
            mode = 0;
            InitCombatSlots02043040(this);
            func_02043124(this);
            ResetControllerState020430b0(this);
        } else {
#if defined(jpn)
            if (!flags17ff.flag5) SePlayer_Play(&g_sePlayer, 1, 0);
#else
            if (!b19d3) SePlayer_Play(&g_sePlayer, 1, 0);
#endif
            mode = 5;
            ++tokenIndex;
            b912 = 0;
        }
        break;
    }
    }
    return 0;
}
