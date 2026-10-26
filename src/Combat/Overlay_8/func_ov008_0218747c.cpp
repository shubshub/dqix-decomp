#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov008_0218747c { char unknown_0_[0x3c]; Struct_020ac4f8 unknown_3c_[2]; };
#if defined(jpn)
enum { Enum_ov008_0218747c_29956 = 0x72c4, Enum_ov008_0218747c_24 = 0x14 };
#else
enum { Enum_ov008_0218747c_29956 = 0x7504, Enum_ov008_0218747c_24 = 0x18 };
#endif
struct Struct_01ff91ac_37 { char unknown_0_[Enum_ov008_0218747c_29956]; Struct_ov008_0218747c unknown_7504_; };
struct Struct_ov008_0218747c_2 {
    char unknown_0_[0xb10];
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    char unknown_b12_[6];
    unsigned int unknown_b18_;
    char unknown_b1c_[Enum_ov008_0218747c_24];
    int unknown_b34_;
    char unknown_b38_[8];
    Struct_020ac4f8 unknown_b40_[2];
};
struct SearchClock { char pad[0x100d]; unsigned char count; };
struct TimeStamp020103f0;
struct TimeStamp020104cc;
void GameState_GetTimeSinceMainTimestamp(TimeStamp020103f0*, unsigned short*, unsigned char*, unsigned char*);
extern "C" SearchClock* LinkSession_GetInstance();
int LinkSession_GetState(int*);
void ComputeElapsedPlayTimeHMS020104cc(TimeStamp020104cc*, unsigned short*, unsigned char*, unsigned char*);
void AddPlayClockHours020ac614(BattleRecordPlayClock*, int);
void AddPlayClockMinutes020ac644(BattleRecordPlayClock*, int);
static inline ClockTotals* GetTotals(GameState* game) { return &((GameClockTotals*)game)->totals; }

// USA: func_ov008_0218747c
extern "C" ARM void func_ov008_0218747c(PlayTimeDisplay* display, int mode) {
    if (display->disabled) return;
    if (display->state == 12 && display->phase < 6) return;
    GameState* game = GameState::GetInstance();
    BattleRecordPlayClock* output = 0;
    ClockTotals* totals = GetTotals(game);
    BattleRecordPlayClock* saved = 0;
    unsigned short hours = 0;
    unsigned char minutes = 0;
    unsigned char seconds = 0;
    BattleRecordPlayClock* singlePlayerSaved = &totals->clocks[0];
    BattleRecordPlayClock* multiplayerSaved = singlePlayerSaved + 1;
    if (mode == 0) {
        output = &display->clocks[0];
        saved = singlePlayerSaved;
        GameState_GetTimeSinceMainTimestamp((TimeStamp020103f0*)game, &hours, &minutes, &seconds);
    } else if (mode == 1) {
        output = &display->clocks[1];
        saved = multiplayerSaved;
        SearchClock* search = LinkSession_GetInstance();
        int state = LinkSession_GetState((int*)search);
        int count = search->count;
        if ((state == 5 && count > 1) || state == 6) {
            ComputeElapsedPlayTimeHMS020104cc((TimeStamp020104cc*)game, &hours, &minutes, &seconds);
        } else {
            var4 = 0;
            var5 = 0;
            var6 = 0;
        }
    }
    if (!var1 || !var3) return;
    unsigned char var12 = var1->unknown_2_;
    func_ov008_02184598(var1);
    func_020ac614(var1, (unsigned short)(var3->unknown_0_ + var4));
    func_020ac644(var1, (unsigned char)(var3->unknown_2_ + var5));
    var1->unknown_3_ += (unsigned char)(var3->unknown_3_ + var6);
    unsigned char var13 = var1->unknown_3_;
    if (var13 > 59) {
        unsigned char var14 = var13 / 60;
        if (var1->unknown_0_ == 9999 && var1->unknown_2_ + var14 > 59) {
            var1->unknown_0_ = 9999;
            var1->unknown_2_ = 59;
            var1->unknown_3_ = 59;
        } else {
            func_020ac644(var1, var14);
            var1->unknown_3_ %= 60;
        }
    }
    if (var1->unknown_2_ != var12) {
        if (arg1 == 0) arg0->unknown_b18_ |= 0x800;
        else if (arg1 == 1) arg0->unknown_b18_ |= 0x1000;
    }
}
