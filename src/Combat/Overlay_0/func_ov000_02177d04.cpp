#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_3;
struct Struct_02054000;

struct Struct_ov000_02177d04 {
    int unknown_0_;
    const char* unknown_4_;
};

void* GameState_GetParty(GameState* battleStruct);
int KeyTable_Get(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* func_ov000_02161318(void* obj, int index);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_ov000_02170c7c(void* obj);
int FormatCombatLogSuffix02041dd0(char* dst, int code);
int Text_AppendNTag(char* dst, int n, const char* name);
int AppendXTag_02041a28(char* dst, int x);
ActiveSub_02054000* GetActiveSub_02054000(struct Outer_02054000* p);
extern "C" void* __clear(void* dst, int count);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int Text_Append(char* dst, const char* src);

// USA: func_ov000_02177d04
extern "C" ARM void func_ov000_02177d04(char* base, char* dst) {
    GameState* gs = GameState::GetInstance();
    unsigned char count = *((unsigned char*)GameState_GetParty(gs) + 0xf7c);
    const char* sep = (const char*)KeyTable_Get((struct Container020e0310*)(base + 0xb8), 0);
#if defined(jpn)
    signed char var3 = *(signed char*)(arg0 + 0x1f00 + 0xa3);
#else
    signed char var3 = *(signed char*)(arg0 + 0x1d00 + 0x6b);
#endif

    if (IsField0x118Equal2_ov000_0217542c(base)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    for (unsigned char var4 = 0; var4 < var1; var4++) {
        signed char var5 = *(signed char*)(arg0 + 0x70 + var4);
        void* var6 = func_ov000_02161318(arg0, var5);
        if (var6 == 0) {
            continue;
        }
        GameObject* var7 = func_0200ff1c(var0, var5);
        if (var7 == 0) {
            continue;
        }
        FormatCombatLogSuffix02041dd0(dst, func_ov000_02170c7c(entry));
        Text_AppendNTag(dst, i, combatant->baseStats_->name);
        AppendXTag_02041a28(dst, 0x46);
        FormatCombatLogSuffix02041dd0(dst, 0);
        ActiveSub_02054000* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
        if (sub != 0) {
#if defined(jpn)
            Text_Append(dst, sub->name);
#else
            char text[0x100];
            __clear(text, 0x100);
            CopyTextAndUppercaseIfFlagged0206819c(sub->name, text, 0);
            Text_Append(dst, text);
#endif
        }
        if (i != count - 1) {
            Text_Append(dst, sep);
        }
    }
}
