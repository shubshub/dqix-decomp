#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_3;
struct Struct_02054000;

struct Struct_ov000_02177d04 {
    int unknown_0_;
    const char* unknown_4_;
};

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
int KeyTable_Get(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
extern "C" void* func_ov000_02161318(void* obj, int index);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_ov000_02170c7c(void* obj);
int FormatCombatLogSuffix02041dd0(char* dst, int code);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendXTag_02041a28(char* dst, int x);
ActiveSub_02054000* GetActiveSub_02054000(struct Outer_02054000* p);
extern "C" void* __clear(void* dst, int count);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov000_02177d04
extern "C" ARM void func_ov000_02177d04(char* base, char* dst) {
    GameState* gs = GameState::GetInstance();
    unsigned char count = *((unsigned char*)GetPtrField0x2a04_02010828(gs) + 0xf7c);
    const char* sep = (const char*)KeyTable_Get((struct Container020e0310*)(base + 0xb8), 0);
#if defined(jpn)
    signed char var3 = *(signed char*)(arg0 + 0x1f00 + 0xa3);
#else
    signed char var3 = *(signed char*)(arg0 + 0x1d00 + 0x6b);
#endif

    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg1, var3, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var3);

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
        func_02041dd0(arg1, func_ov000_02170c7c(var6));
        func_02041b70(arg1, var4, var7->baseStats_->unk);
        func_02041a28(arg1, 0x46);
        func_02041dd0(arg1, 0);
        Struct_ov000_02177d04* var8 = func_02054000((struct Struct_02054000*)var7);
        if (var8 != 0) {
#if defined(jpn)
            func_02042058(arg1, var8->unknown_4_);
#else
            char var9[0x100];
            __clear(var9, 0x100);
            func_0206819c(var8->unknown_4_, var9, 0);
            func_02042058(arg1, var9);
#endif
        }
        if (var4 != var1 - 1) {
            func_02042058(arg1, var2);
        }
    }
}
