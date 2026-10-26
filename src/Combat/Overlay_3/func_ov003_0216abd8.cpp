#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020474a8(void*, int, int, char*);
#endif
#include "GameState/GameState.h"

extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02046380(void* global);
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* container, int key);
extern "C" void MessageSystem_FormatText(void* global, int mode, int fmt, char* dst, int size, int a5, int a6);
extern "C" int Text_Append(char* dst, const char* src);

struct PartyData0216abd8 {
    char pad0[0xf68];
    int amount;
};

struct Struct_ov003_0216abd8_2 {
    char pad0[0x600];
    char text[0x100];
};

struct Struct_ov003_0216abd8_3 {
    char pad0[0x64];
    char messages[0x18];
    struct Struct_ov003_0216abd8_2* buf;
};

// USA: func_ov003_0216abd8
extern "C" ARM void func_ov003_0216abd8(struct Struct_ov003_0216abd8_3* self, char* out) {
#if defined(jpn)
    const volatile struct Struct_ov003_0216abd8_3* self_v = self;
#else
    struct Struct_ov003_0216abd8_3* self_v = self;
#endif
    if (out == NULL) {
        return;
    }
    GameState* gameState = GameState::GetInstance();
    void* global = MessageSystem_GetInstance();
    struct PartyData0216abd8* party = (struct PartyData0216abd8*)GameState_GetParty(gameState);
    struct Struct_ov003_0216abd8_2* buf = self_v->buf;
    func_02046380(global);
    if (party->amount != 0) {
        func_020465c0((struct StoreStruct*)global, 0, party->amount);
        func_020465f0((unsigned char*)global, 0, 0);
        int fmt = KeyTable_Get((struct Container020e0310*)self_v->messages, 0x443);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        MessageSystem_FormatText(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        Text_Append(out, buf->text);
    } else {
        char* name = (char*)gameState->GetProtagonist()->baseStats_;
        MessageSystem_SetStringArgument((struct Obj02046574*)global, 0, name);
        int fmt = KeyTable_Get((struct Container020e0310*)self_v->messages, 0x442);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        MessageSystem_FormatText(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        Text_Append(out, buf->text);
    }
}
