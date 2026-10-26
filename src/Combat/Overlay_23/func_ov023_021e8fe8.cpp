#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020ac614(struct Struct_020ac4f8* arg0, int amount);

extern "C" void func_020ac644(struct Struct_020ac4f8* arg0, int amount);

struct TimeStamp020103f0;
extern "C" void GameState_GetTimeSinceMainTimestamp(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

struct Struct_020104cc;
extern "C" void func_020104cc(struct Struct_020104cc* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_GetState(int* obj);

extern "C" int _s32_div_f(int a, int b);

// USA: func_ov023_021e8fe8
extern "C" ARM struct Struct_020ac4f8 func_ov023_021e8fe8(struct Struct_020ac4f8 arg0, int flag) {
    GameState* battle = GameState::GetInstance();
    struct Struct_020ac4f8 result;
    unsigned short tHours;
    unsigned char tMinutes;
    unsigned char tSeconds;

    tHours = 0;
    tMinutes = 0;
    tSeconds = 0;
    result.hours = 0;
    result.minutes = 0;
    result.seconds = 0;

    if (flag == 0) {
        GameState_GetTimeSinceMainTimestamp((struct TimeStamp020103f0*)battle, &tHours, &tMinutes, &tSeconds);
    } else {
        void* ptr = LinkSession_GetInstance();
        int val = LinkSession_GetState((int*)ptr);
        int byteVal = *((unsigned char*)ptr + 0x100d);
        if ((val == 5 && byteVal > 1) || val == 6) {
            func_020104cc((struct Struct_020104cc*)battle, &tHours, &tMinutes, &tSeconds);
        } else {
            tHours = 0;
            tMinutes = 0;
            tSeconds = 0;
        }
    }

    func_020ac614(&result, (unsigned short)(arg0.hours + tHours));
    func_020ac644(&result, (unsigned char)(arg0.minutes + tMinutes));

    result.seconds = result.seconds + (unsigned char)(arg0.seconds + tSeconds);
    unsigned char var8 = result.seconds;
    if (var8 > 0x3b) {
        unsigned char var9 = var8 / 0x3c;
        if (result.hours == 0x270f) {
            int m = result.minutes + var9;
            if (m > 0x3b) {
                result.hours = 0x270f;
                result.minutes = 0x3b;
                result.seconds = 0x3b;
                goto done;
            }
        }
        func_020ac644(&result, var9);
        result.seconds = result.seconds % 0x3c;
    }
done:
    return result;
}
