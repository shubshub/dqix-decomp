#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov008_0218747c { char pad[0x3c]; Struct_020ac4f8 unknown_3c_[2]; };
#if defined(jpn)
enum { Enum_ov008_0218747c_29956 = 0x72c4, Enum_ov008_0218747c_24 = 0x14 };
#else
enum { Enum_ov008_0218747c_29956 = 0x7504, Enum_ov008_0218747c_24 = 0x18 };
#endif
struct Struct_01ff91ac_37 { char pad[Enum_ov008_0218747c_29956]; Struct_ov008_0218747c totals; };
struct Struct_ov008_0218747c_2 {
    char pad0[0xb10];
    signed char state;
    unsigned char phase;
    char pad1[6];
    unsigned int unknown_b18_;
    char pad2[Enum_ov008_0218747c_24];
    int disabled;
    char pad3[8];
    Struct_020ac4f8 unknown_b40_[2];
};
struct SearchClock { char pad[0x100d]; unsigned char count; };
struct TimeStamp020103f0;
struct Struct_020104cc;
extern "C" void GameState_GetTimeSinceMainTimestamp(TimeStamp020103f0*, unsigned short*, unsigned char*, unsigned char*);
extern "C" SearchClock* LinkSession_GetInstance();
extern "C" int LinkSession_GetState(int*);
extern "C" void func_020104cc(Struct_020104cc*, unsigned short*, unsigned char*, unsigned char*);
extern "C" void func_020ac614(Struct_020ac4f8*, int);
extern "C" void func_020ac644(Struct_020ac4f8*, int);
static inline Struct_ov008_0218747c* inline_ov008_0218747c(GameState* game) { return &((Struct_01ff91ac_37*)game)->totals; }

// USA: func_ov008_0218747c
extern "C" ARM void func_ov008_0218747c(Struct_ov008_0218747c_2* display, int mode) {
    if (display->disabled) return;
    if (display->state == 12 && display->phase < 6) return;
    GameState* game = GameState::GetInstance();
    Struct_020ac4f8* output = 0;
    Struct_ov008_0218747c* totals = inline_ov008_0218747c(game);
    Struct_020ac4f8* saved = 0;
    unsigned short hours = 0;
    unsigned char minutes = 0;
    unsigned char seconds = 0;
    Struct_020ac4f8* var7 = &totals->unknown_3c_[0];
    Struct_020ac4f8* var8 = var7 + 1;
    if (mode == 0) {
        output = &display->unknown_b40_[0];
        saved = var7;
        GameState_GetTimeSinceMainTimestamp((TimeStamp020103f0*)game, &hours, &minutes, &seconds);
    } else if (mode == 1) {
        output = &display->unknown_b40_[1];
        saved = var8;
        SearchClock* search = LinkSession_GetInstance();
        int state = LinkSession_GetState((int*)search);
        int count = search->count;
        if ((state == 5 && count > 1) || state == 6) {
            func_020104cc((Struct_020104cc*)game, &hours, &minutes, &seconds);
        } else {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }
    if (!output || !saved) return;
    unsigned char var12 = output->minutes;
    func_ov008_02184598(output);
    func_020ac614(output, (unsigned short)(saved->hours + hours));
    func_020ac644(output, (unsigned char)(saved->minutes + minutes));
    output->seconds += (unsigned char)(saved->seconds + seconds);
    unsigned char total = output->seconds;
    if (total > 59) {
        unsigned char var14 = total / 60;
        if (output->hours == 9999 && output->minutes + var14 > 59) {
            output->hours = 9999;
            output->minutes = 59;
            output->seconds = 59;
        } else {
            func_020ac644(output, var14);
            output->seconds %= 60;
        }
    }
    if (output->minutes != var12) {
        if (mode == 0) display->unknown_b18_ |= 0x800;
        else if (mode == 1) display->unknown_b18_ |= 0x1000;
    }
}
