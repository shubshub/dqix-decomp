#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Filesystem/FSInnerDefs.h"
#include "NitroSDK/Input.h"

struct FlagWord02046708 { unsigned int flags; };

void* GlobalFlags_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
int NNS_SndSetMasterVolume(int a);
extern "C" int EnterSleepMode(int a, int b, int c);
int SetLcdPower(int a);
void CancelActionIfHeadIdMatches_02199e98(void* obj);
int IsLcdPowerOn(void);

// EnterSleepMode's wake triggers (it names PM_TRIGGER_CARD 0x8 itself): the lid opening, or the game card coming out
enum { PM_TRIGGER_COVER_OPEN = 0x4, PM_TRIGGER_CARD = 0x8 };

// NNS_SndSetMasterVolume queues sound command 0x17 with this level: 0 before sleeping, the 7-bit maximum after waking
enum { kSoundVolumeMuted = 0, kSoundVolumeFull = 0x7f };

// SetLcdPower's argument: 1 powers the LCDs on (IsLcdPowerOn then reads 1), 0 off
enum { kLcdPowerOff = 0, kLcdPowerOn = 1 };

// Main, originally func_02012de8 (USA 0x02012de8, EUR 0x02012df8, JPN 0x02012bb0)
extern "C" ARM void Main_HandleLid(void) {
    struct FlagWord02046708* globalFlags = (struct FlagWord02046708*)GlobalFlags_GetInstance();
    int* p2 = (int*)LinkSession_GetInstance();

    int lidDown = IsLidDown();
    if (lidDown) {
        if (LinkSession_IsActive(p2) && !FlagWord_TestBits(globalFlags, 0x1000000)) {
            goto stayAwake;
        }
        if (!FlagWord_TestBits(globalFlags, 0x80)) {
            NNS_SndSetMasterVolume(kSoundVolumeMuted);
            EnterSleepMode(PM_TRIGGER_COVER_OPEN | PM_TRIGGER_CARD, 0, 0);
            if (Card_IsPulledOut() == 0) {
                NNS_SndSetMasterVolume(kSoundVolumeFull);
            }
            return;
        }
    stayAwake:
        if (!FlagWord_TestBits(globalFlags, 0x400000)) {
            SetLcdPower(kLcdPowerOff);
        }
        if (!LinkSession_IsActive(p2)) return;
        if (FlagWord_TestBits(globalFlags, 0x1000000)) return;
        {
            int resources = (int)GameState::GetInstance()->GetResources();
            if (resources == 0) return;
            CancelActionIfHeadIdMatches_02199e98((void*)resources);
        }
        return;
    }

    if (IsLcdPowerOn()) return;
    SetLcdPower(kLcdPowerOn);
    {
        int resources = (int)GameState::GetInstance()->GetResources();
        if (resources == 0) return;
        WriteBrightnessToHardware((GameResources*)resources);
    }
}
