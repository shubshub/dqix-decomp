#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;
struct Struct_02054000;

struct Struct_ov000_02177d04 {
    int unk_0;
    const char* name;
};

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* func_ov000_02161318(void* obj, int index);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_ov000_02170c7c(void* obj);
extern "C" int func_02041dd0(char* dst, int code);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int func_02041a28(char* dst, int x);
extern "C" Struct_ov000_02177d04* func_02054000(struct Struct_02054000* p);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_0206819c(const char* src, char* dst, int flag);
extern "C" int Text_Append(char* dst, const char* src);

// USA: func_ov000_02177d04
extern "C" ARM void func_ov000_02177d04(char* base, char* dst) {
    GameState* gs = GameState::GetInstance();
    unsigned char count = *((unsigned char*)GameState_GetParty(gs) + 0xf7c);
    const char* sep = (const char*)KeyTable_Get((struct Container020e0310*)(base + 0xb8), 0);
#if defined(jpn)
    signed char cursor = *(signed char*)(base + 0x1f00 + 0xa3);
#else
    signed char cursor = *(signed char*)(base + 0x1d00 + 0x6b);
#endif

    if (func_ov000_0217542c(base)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    for (unsigned char i = 0; i < count; i++) {
        signed char id = *(signed char*)(base + 0x70 + i);
        void* entry = func_ov000_02161318(base, id);
        if (entry == 0) {
            continue;
        }
        GameObject* combatant = func_0200ff1c(gs, id);
        if (combatant == 0) {
            continue;
        }
        func_02041dd0(dst, func_ov000_02170c7c(entry));
        Text_AppendNTag(dst, i, combatant->baseStats_->name);
        func_02041a28(dst, 0x46);
        func_02041dd0(dst, 0);
        Struct_ov000_02177d04* sub = func_02054000((struct Struct_02054000*)combatant);
        if (sub != 0) {
#if defined(jpn)
            Text_Append(dst, sub->name);
#else
            char text[0x100];
            __clear(text, 0x100);
            func_0206819c(sub->name, text, 0);
            Text_Append(dst, text);
#endif
        }
        if (i != count - 1) {
            Text_Append(dst, sep);
        }
    }
}
