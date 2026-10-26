#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void Window_Update(void* obj, int val);
struct TimeStamp020103f0;
extern "C" void GameState_GetTimeSinceMainTimestamp(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);
extern "C" void func_020ac614(struct Struct_020ac4f8* arg0, int amount);
extern "C" void func_020ac644(struct Struct_020ac4f8* arg0, int amount);
struct Struct_ov023_021e71a0;
extern "C" void func_ov023_021e71a0(struct Struct_ov023_021e71a0* p);
class Struct_ov012_0218adac;
extern "C" void func_ov023_021e7c58(Struct_ov012_0218adac* obj, unsigned int selector, int idx);

// USA: func_ov023_021e7404
extern "C" ARM void func_ov023_021e7404(char* obj, int amount) {
#if defined(jpn)
 enum {regionalOffset0=0x2c4, regionalOffset1=0x7000, regionalOffset2=0x606, regionalOffset3=0x604, regionalOffset4=0x607};
#else
 enum {regionalOffset0=0x104, regionalOffset1=0x7400, regionalOffset2=0x610, regionalOffset3=0x60e, regionalOffset4=0x611};
#endif
    int useAmount = amount;
    if (useAmount == 0) useAmount = 1;

    if (*(int*)(obj + 0x5dc) == 0) {
        return;
    }

    Window_Update(obj + 0x78, useAmount);
    *(int*)0x4001010 = 0;

    if (*(int*)(obj + 0x3c) == 0) {
        void* battleStruct = GameState::GetInstance();
        char* var2 = (char*)battleStruct + regionalOffset0 + regionalOffset1;
        int var3 = 0;
        unsigned char var4 = *(unsigned char*)(obj + regionalOffset2);

        unsigned short hoursOut;
        unsigned char secondsOut;
        unsigned char minutesOut;
        hoursOut = 0;
        minutesOut = 0;
        secondsOut = 0;

        if (*(unsigned short*)(obj + regionalOffset3) == 0 && *(unsigned char*)(obj + regionalOffset2) == 0) {
            var3 = 1;
        }

        battleStruct = GameState::GetInstance();
        GameState_GetTimeSinceMainTimestamp((struct TimeStamp020103f0*)battleStruct, &hoursOut, &minutesOut, &secondsOut);

        func_ov023_021e71a0((struct Struct_ov023_021e71a0*)(obj + regionalOffset3));

        unsigned short var8 = *(unsigned short*)(var2 + 0x3c);
        func_020ac614((struct Struct_020ac4f8*)(obj + regionalOffset3), (unsigned short)(var8 + hoursOut));

        unsigned char var9 = *(unsigned char*)(var2 + 0x3e);
        func_020ac644((struct Struct_020ac4f8*)(obj + regionalOffset3), (unsigned char)(var9 + minutesOut));

        unsigned char var10 = *(unsigned char*)(var2 + 0x3f);
        *(unsigned char*)(obj + regionalOffset4) = *(unsigned char*)(obj + regionalOffset4) + (unsigned char)(var10 + secondsOut);

        if (*(unsigned char*)(obj + regionalOffset4) > 0x3b) {
            unsigned char var11 = *(unsigned char*)(obj + regionalOffset4) / 60;

            if (*(unsigned short*)(obj + regionalOffset3) == 0x270f) {
                int var12 = *(unsigned char*)(obj + regionalOffset2) + var11;
                if (var12 > 0x3b) {
                    *(short*)(obj + regionalOffset3) = 0x270f;
                    *(unsigned char*)(obj + regionalOffset2) = 0x3b;
                    *(unsigned char*)(obj + regionalOffset4) = 0x3b;
                    goto afterMinuteCarry;
                }
            }

            func_020ac644((struct Struct_020ac4f8*)(obj + regionalOffset3), var11);
            *(unsigned char*)(obj + regionalOffset4) = *(unsigned char*)(obj + regionalOffset4) % 60;
        }
afterMinuteCarry:

        int cond;
        if (var3 != 0) {
            cond = 1;
        } else {
            cond = (var4 != *(unsigned char*)(obj + regionalOffset2)) ? 1 : 0;
        }
        if (cond != 0) {
            func_ov023_021e7c58((Struct_ov012_0218adac*)obj, 0, 0);
        }
    }

    *(int*)(obj + 0x5e8) = *(int*)(obj + 0x5e8) - (useAmount << 11);
    *(int*)(obj + 0x5ec) = *(int*)(obj + 0x5ec) + (useAmount << 11);

    if (*(int*)(obj + 0x5e8) < -0x100000) {
        *(int*)(obj + 0x5e8) += 0x100000;
    }
    if (*(int*)(obj + 0x5ec) > 0x100000) {
        *(int*)(obj + 0x5ec) = *(int*)(obj + 0x5ec) - 0x100000;
    }

    int var14 = *(int*)(obj + 0x5ec) >> 12;
    *(int*)0x4001014 = ((*(int*)(obj + 0x5e8) >> 12) & 0x1ff) | ((0x1ff << 16) & (var14 << 16));
}
