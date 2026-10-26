#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include <GameState/GameState.h>
#include <NitroSDK/Memory.h>
struct Struct_020abb64 { unsigned int value:12, mode:4, index:5, unknown_2_5_:4, unknown_3_1_:1, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, unknown_3_5_:1, unknown_3_6_:1, unknown_3_7_:1; };
struct Struct_020abb64_2 { unsigned int low:9, middle:10, high:11, unknown_3_6_:1, unknown_3_7_:1; };
struct Struct_020abb64_3 { Struct_020abb64 flags; Struct_020abb64_2 fields; unsigned char unknown_8_; };
struct Struct_020abb64_4 { char pad[IS_JPN ? 0x543c : 0x569c]; Struct_020abb64_3 config; char pad2[0xcd8]; char buffer[0x54]; };
extern "C" char* func_020108d8(char*, int);
extern "C" void func_02082828(char*);
extern "C" int func_020aba5c(int);
extern "C" int func_020abae8(int);
extern "C" void Party_Init(char*);
// USA: func_020abb64
extern "C" ARM int func_020abb64() {
    GameState* state = GameState::GetInstance();
    for (int i = 0;i < 4;i++) { char* entry = func_020108d8((char*)state, i); if (entry) func_02082828(entry); }
    if (!func_020aba5c(0)) return 0;
    if (!func_020aba5c(1)) return 0;
    if (!func_020abae8(0)) return 0;
    if (!func_020abae8(1)) return 0;
    Struct_020abb64_4* storage = (Struct_020abb64_4*)state;
    storage->config.flags.value = 2000;
    storage->config.flags.mode = 1;
    storage->config.flags.index = 1;
    storage->config.flags.unknown_3_4_ = 0;
    storage->config.flags.unknown_2_5_ = 0;
    storage->config.flags.unknown_3_3_ = 0;
    storage->config.flags.unknown_3_1_ = 0;
    storage->config.flags.unknown_3_2_ = 0;
    storage->config.flags.unknown_3_5_ = 0;
    storage->config.flags.unknown_3_6_ = 1;
    storage->config.flags.unknown_3_7_ = 0;
    Struct_020abb64_3* config = &storage->config;
    config->fields.low = 511;
    config->fields.unknown_3_6_ = 0;
    config->fields.middle = 300;
    config->fields.high = 706;
    config->unknown_8_ = 0;
    Party_Init((char*)GameState_GetParty(state));
    VectorizedMemset(storage->buffer, 0, 0x54);
    return 1;
}
