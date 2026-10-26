#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020ac614(struct Struct_020ac4f8* arg0, int amount);

extern "C" void func_020ac644(struct Struct_020ac4f8* arg0, int amount);

extern "C" void func_020ac6b8(Struct_020ac4f8* arg0, int amount);

struct TimeStamp020103f0;
extern "C" void GameState_GetTimeSinceMainTimestamp(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

struct Struct_020104cc;
extern "C" void func_020104cc(struct Struct_020104cc* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020ac494(void* src);

unsigned long long GetCurrentTimestamp(void);

// Main, originally UpdatePlayClocks020ac4f8 (USA 0x020ac4f8, EUR 0x020ac508, JPN 0x020adfc4)
extern "C" ARM int GameState_UpdatePlayClocks(int commit) {
    GameState *battle;
    Struct_02061c04 record;
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned long long var5;
    Struct_02061c04_2* var6;

    battle = GameState::GetInstance();
    func_020ac4c0(&record);

    hours = 0;
    minutes = 0;
    seconds = 0;
    var6 = &record.unknown_68_;
    GameState_GetTimeSinceMainTimestamp((struct TimeStamp020103f0*)battle, &hours, &minutes, &seconds);

    func_020ac614(&record.unknown_0_.elapsed, hours);
    func_020ac644(&record.unknown_0_.elapsed, minutes);
    func_020ac6b8(&record.unknown_0_.elapsed, seconds);

    func_020ac614(&var6->elapsed, hours);
    func_020ac644(&var6->elapsed, minutes);
    func_020ac6b8(&var6->elapsed, seconds);

    var5 = GetCurrentTimestamp();
    battle->mainTimestamp_ = var5;

    if (commit != 0) {
        Struct_020ac4f8* var7;
        func_020104cc((struct Struct_020104cc*)battle, &hours, &minutes, &seconds);
        var7 = &record.unknown_0_.unknown_4_;

        func_020ac614(var7, hours);
        func_020ac644(var7, minutes);
        func_020ac6b8(var7, seconds);

        func_020ac614(&var6->unknown_4_, hours);
        func_020ac644(&var6->unknown_4_, minutes);
        func_020ac6b8(&var6->unknown_4_, seconds);

        var5 = GetCurrentTimestamp();
        battle->altTimestamp_ = var5;
    }

    return func_020ac494(&record);
}
