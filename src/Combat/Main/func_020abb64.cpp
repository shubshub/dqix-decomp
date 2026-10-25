#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include <GameState/GameState.h>
#include <NitroSDK/Memory.h>
struct Struct_020abb64 { unsigned int unknown_0_0_:12, unknown_1_4_:4, unknown_2_0_:5, unknown_2_5_:4, unknown_3_1_:1, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, unknown_3_5_:1, unknown_3_6_:1, unknown_3_7_:1; };
struct Struct_020abb64_2 { unsigned int unknown_0_0_:9, unknown_1_1_:10, unknown_2_3_:11, unknown_3_6_:1, unknown_3_7_:1; };
struct Struct_020abb64_3 { Struct_020abb64 unknown_0_; Struct_020abb64_2 unknown_4_; unsigned char unknown_8_; };
struct Struct_020abb64_4 { char unknown_0_[IS_JPN ? 0x543c : 0x569c]; Struct_020abb64_3 unknown_569c_; char unknown_56a8_[0xcd8]; char unknown_6380_[0x54]; };
extern "C" char* func_020108d8(char*, int);
extern "C" void func_02082828(char*);
extern "C" int func_020aba5c(int);
extern "C" int func_020abae8(int);
extern "C" void func_0208660c(char*);
// USA: func_020abb64
extern "C" ARM int func_020abb64() {
    GameState* state = GameState::GetInstance();
    for (int i = 0;i < 4;i++) { char* entry = GetSlotEntry020108d8((char*)state, i); if (entry) func_02082828(entry); }
    if (!SendShortBufferOrReturnZero020aba5c(0)) return 0;
    if (!SendShortBufferOrReturnZero020aba5c(1)) return 0;
    if (!SendBufferOrReturnZero_020abae8(0)) return 0;
    if (!SendBufferOrReturnZero_020abae8(1)) return 0;
    State020abb64* storage = (State020abb64*)state;
    storage->config.flags.value = 2000;
    storage->config.flags.mode = 1;
    storage->config.flags.index = 1;
    storage->config.flags.bit28 = 0;
    storage->config.flags.field_0x0_21 = 0;
    storage->config.flags.bit27 = 0;
    storage->config.flags.bit25 = 0;
    storage->config.flags.bit26 = 0;
    storage->config.flags.bit29 = 0;
    storage->config.flags.bit30 = 1;
    storage->config.flags.bit31 = 0;
    Config020abb64* config = &storage->config;
    config->fields.low = 511;
    config->fields.bit30 = 0;
    config->fields.middle = 300;
    config->fields.high = 706;
    config->statusByte = 0;
    InitBigManagerStruct0208660c((char*)GameState_GetParty(state));
    VectorizedMemset(storage->buffer, 0, 0x54);
    return 1;
}
