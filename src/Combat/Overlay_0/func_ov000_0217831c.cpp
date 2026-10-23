#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>

struct Struct_0205c508;
struct Struct_0201099c_3;
struct Struct_0201099c_10;
struct Struct_02054000;
struct Struct_ov000_0217831c {
    unsigned int unknown_0_;
    const char* unknown_4_;
};
struct Struct_ov000_0217831c_2 {
    unsigned char unknown_0_[0x18];
    short unknown_18_;
};

struct Struct_ov000_0217831c_3 {
    unsigned char unknown_0_[0x26];
    short unknown_26_[37];
    signed char unknown_70_[0x48];
    unsigned char unknown_b8_[0x48];
    unsigned char unknown_100_[0xdc];
#if defined(jpn)
    unsigned char unknown_1dc_[0x1dc7];
#else
    unsigned char unknown_1dc_[0x1b8f];
#endif
    signed char unknown_1d6b_;
    unsigned char unknown_1d6c_[3];
    signed char unknown_1d6f_;
};

void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* first, int* last);
const char* KeyTable_Get(struct Container020e0310* c, int key);
struct ActiveSub02054000* GetActiveSub_02054000(struct Outer_02054000* p);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
struct ItemNameEntry* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* arg0, int arg1);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* arg0, int arg1);
#endif
extern "C" int func_02041b70(char* arg0, int arg1, const char* arg2);
extern "C" void __clear(void* arg0, unsigned int arg1);

// USA: func_ov000_0217831c
extern "C" ARM void func_ov000_0217831c(Struct_ov000_0217831c_3* arg0, char* arg1)
{
    int first;
    int last;
    ComputeProductSums0205c508((struct UnkStruct0205c508*)menu->range, &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* texts = (struct Container020e0310*)menu->textTable;
    const char* separator = KeyTable_Get(texts, 0);
    signed char cursor = menu->cursor;
    const char* unknownName = KeyTable_Get(texts, 5);
    int n = 0;
    signed char combatantId = menu->combatantIds[menu->currentCombatant];
    int selectedKey = -1;
    GameState* state = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, combatantId);
    struct ActiveSub02054000* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
    if (sub != NULL) {
        selectedKey = sub->itemKey;
    }
    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg1, var6 - var2, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var6 - var2);
    for (signed char var14 = var2; var14 < var3; var14++) {
        char var15[0x40];
        __clear(var15, sizeof(var15));
        int var16 = arg0->unknown_26_[var14];
        struct Struct_ov000_0217831c* var17 = func_020dedd0((struct Struct_0201099c_10*)arg0->unknown_100_, var16);
        const char* var18 = var7;
        if (var17 != NULL) {
#if defined(jpn)
            var18 = var17->unknown_4_;
#else
            char var19[0x100];
            __clear(var19, sizeof(var19));
            func_0206819c(var17->unknown_4_, var19, 0);
            var18 = var19;
#endif
        }
        if (selectedKey == key) {
            AppendString02042058(line, KeyTable_Get(texts, 0x13));
#if !defined(jpn)
            func_02041acc(var15, 3);
#endif
        } else {
            func_02041acc(var15, 8);
        }
        func_02042058(var15, var18);
        func_02041b70(arg1, var8, var15);
        if (var14 != var3 - 1) {
            func_02042058(arg1, var5);
        }
        var8++;
    }
}
