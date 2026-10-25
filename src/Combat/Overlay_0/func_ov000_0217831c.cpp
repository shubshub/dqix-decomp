#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>

struct UnkStruct0205c508;
struct Container020e0310;
struct ItemTable;
struct Outer_02054000;
struct ItemNameEntry {
    unsigned int id;
    const char* name;
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
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
struct ItemNameEntry* ItemTable_Find(struct ItemTable* c, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* arg0, int arg1);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* arg0, int arg1);
#endif
int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void __clear(void* dst, unsigned int size);

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
    if (IsField0x118Equal2_ov000_0217542c(menu)) {
        Text_AppendFrameTag(dst, cursor - start, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        char line[0x40];
        __clear(line, sizeof(line));
        int key = menu->itemKeys[i];
        struct ItemNameEntry* item = ItemTable_Find((struct ItemTable*)menu->itemTable, key);
        const char* name = unknownName;
        if (item != NULL) {
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
            Text_Append(line, KeyTable_Get(texts, 0x13));
#if !defined(jpn)
            func_02041acc(var15, 3);
#endif
        } else {
            func_02041acc(var15, 8);
        }
        Text_Append(line, name);
        Text_AppendNTag(dst, n, line);
        if (i != end - 1) {
            Text_Append(dst, separator);
        }
        var8++;
    }
}
