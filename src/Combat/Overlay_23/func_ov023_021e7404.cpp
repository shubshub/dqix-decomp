#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void Window_Update(void* obj, int val);
struct TimeStamp020103f0;
void ComputeElapsedPlayTimeHMS020103f0(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);
void AddPlayClockHours020ac614(struct BattleRecordPlayClock* clock, int amount);
void AddPlayClockMinutes020ac644(struct BattleRecordPlayClock* clock, int amount);
struct ShortBytePair021e71a0;
void ClearShortAndTwoBytes_021e71a0(struct ShortBytePair021e71a0* p);
class PMFObj021e7c58;
void DispatchEntryByIndex_021e7c58(PMFObj021e7c58* obj, unsigned int selector, int idx);

// USA: func_ov023_021e7404
extern "C" ARM void func_ov023_021e7404(char* arg0, int arg1) {
#if defined(jpn)
 enum {Enum_ov023_021e7404_260=0x2c4, Enum_ov023_021e7404_29696=0x7000, Enum_ov023_021e7404_1552=0x606, Enum_ov023_021e7404_1550=0x604, Enum_ov023_021e7404_1553=0x607};
#else
 enum {Enum_ov023_021e7404_260=0x104, Enum_ov023_021e7404_29696=0x7400, Enum_ov023_021e7404_1552=0x610, Enum_ov023_021e7404_1550=0x60e, Enum_ov023_021e7404_1553=0x611};
#endif
    int var0 = arg1;
    if (var0 == 0) var0 = 1;

    if (*(int*)(arg0 + 0x5dc) == 0) {
        return;
    }

    Window_Update(obj + 0x78, useAmount);
    *(int*)0x4001010 = 0;

    if (*(int*)(arg0 + 0x3c) == 0) {
        void* var1 = GameState::GetInstance();
        char* var2 = (char*)var1 + Enum_ov023_021e7404_260 + Enum_ov023_021e7404_29696;
        int var3 = 0;
        unsigned char var4 = *(unsigned char*)(arg0 + Enum_ov023_021e7404_1552);

        unsigned short var5;
        unsigned char var6;
        unsigned char var7;
        var5 = 0;
        var7 = 0;
        var6 = 0;

        if (*(unsigned short*)(arg0 + Enum_ov023_021e7404_1550) == 0 && *(unsigned char*)(arg0 + Enum_ov023_021e7404_1552) == 0) {
            var3 = 1;
        }

        var1 = GameState::GetInstance();
        func_020103f0((struct Struct_020103f0*)var1, &var5, &var7, &var6);

        func_ov023_021e71a0((struct Struct_ov023_021e71a0*)(arg0 + Enum_ov023_021e7404_1550));

        unsigned short var8 = *(unsigned short*)(var2 + 0x3c);
        func_020ac614((struct Struct_020ac4f8*)(arg0 + Enum_ov023_021e7404_1550), (unsigned short)(var8 + var5));

        unsigned char var9 = *(unsigned char*)(var2 + 0x3e);
        func_020ac644((struct Struct_020ac4f8*)(arg0 + Enum_ov023_021e7404_1550), (unsigned char)(var9 + var7));

        unsigned char var10 = *(unsigned char*)(var2 + 0x3f);
        *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) = *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) + (unsigned char)(var10 + var6);

        if (*(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) > 0x3b) {
            unsigned char var11 = *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) / 60;

            if (*(unsigned short*)(arg0 + Enum_ov023_021e7404_1550) == 0x270f) {
                int var12 = *(unsigned char*)(arg0 + Enum_ov023_021e7404_1552) + var11;
                if (var12 > 0x3b) {
                    *(short*)(arg0 + Enum_ov023_021e7404_1550) = 0x270f;
                    *(unsigned char*)(arg0 + Enum_ov023_021e7404_1552) = 0x3b;
                    *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) = 0x3b;
                    goto afterMinuteCarry;
                }
            }

            func_020ac644((struct Struct_020ac4f8*)(arg0 + Enum_ov023_021e7404_1550), var11);
            *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) = *(unsigned char*)(arg0 + Enum_ov023_021e7404_1553) % 60;
        }
afterMinuteCarry:

        int var13;
        if (var3 != 0) {
            var13 = 1;
        } else {
            var13 = (var4 != *(unsigned char*)(arg0 + Enum_ov023_021e7404_1552)) ? 1 : 0;
        }
        if (var13 != 0) {
            func_ov023_021e7c58((Struct_ov012_0218adac*)arg0, 0, 0);
        }
    }

    *(int*)(arg0 + 0x5e8) = *(int*)(arg0 + 0x5e8) - (var0 << 11);
    *(int*)(arg0 + 0x5ec) = *(int*)(arg0 + 0x5ec) + (var0 << 11);

    if (*(int*)(arg0 + 0x5e8) < -0x100000) {
        *(int*)(arg0 + 0x5e8) += 0x100000;
    }
    if (*(int*)(arg0 + 0x5ec) > 0x100000) {
        *(int*)(arg0 + 0x5ec) = *(int*)(arg0 + 0x5ec) - 0x100000;
    }

    int var14 = *(int*)(arg0 + 0x5ec) >> 12;
    *(int*)0x4001014 = ((*(int*)(arg0 + 0x5e8) >> 12) & 0x1ff) | ((0x1ff << 16) & (var14 << 16));
}
