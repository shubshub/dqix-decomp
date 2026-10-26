#include <globaldefs.h>

void VCountIrq_PushDisable();
void WH_Reset();
extern "C" int LinkSession_WaitForIdle(int* session, int unused);
extern "C" void LinkSession_Reset(void* session);
extern "C" void VCountIrq_PopDisable(void);
void SleepCurrentContext(unsigned int);
int WH_GetSystemState(void);
extern "C" void WH_Finalize(void);
int WH_End();

// NitroSDK wh library system state (WH_GetSystemState).
enum { WH_SYSSTATE_BUSY = 3 };
// LinkSession_WaitForIdle: the link-failed GlobalFlags bit (0x1000000) is set, or it just set it and returned the party to solo.
enum { kWaitResult_LinkFailed = 3 };

// Main, originally func_0202b0f4 (USA 0x0202b0f4, EUR 0x0202b104, JPN 0x0202aca4)
extern "C" ARM unsigned char LinkSession_End(int* session) {
    int result = 0;
    VCountIrq_PushDisable();
    if (*session != 0) {
        int busyFrames = 0;
        while (WH_GetSystemState() == WH_SYSSTATE_BUSY) {
            busyFrames++;
            if (busyFrames > 5000) {
                WH_Reset();
                result = LinkSession_WaitForIdle(session, 1);
                if (result == kWaitResult_LinkFailed) {
                    LinkSession_Reset(session);
                    VCountIrq_PopDisable();
                    return (unsigned char)result;
                }
                break;
            }
            SleepCurrentContext(1);
        }

        WH_Finalize();
        result = LinkSession_WaitForIdle(session, 1);
        if (result == kWaitResult_LinkFailed) {
            LinkSession_Reset(session);
            VCountIrq_PopDisable();
            return (unsigned char)result;
        }
        if (result != 0) {
            WH_Reset();
            result = LinkSession_WaitForIdle(session, 1);
            if (result == kWaitResult_LinkFailed) {
                LinkSession_Reset(session);
                VCountIrq_PopDisable();
                return (unsigned char)result;
            }
        }
        WH_End();
    }
    LinkSession_Reset(session);
    VCountIrq_PopDisable();
    return (unsigned char)result;
}
