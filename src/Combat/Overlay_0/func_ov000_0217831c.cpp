#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>

struct Struct_0205c508;
struct Container020e0310;
struct ItemTable;
struct Struct_02054000;
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
    unsigned char itemTable[0xdc];
#if defined(jpn)
    unsigned char range[0x1dc7];
#else
    unsigned char range[0x1b8f];
#endif
    signed char unknown_1d6b_;
    unsigned char unknown_1d6c_[3];
    signed char cursor;
};

extern "C" void func_0205c508(struct Struct_0205c508* s, int* first, int* last);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" struct Struct_ov000_0217831c_2* func_02054000(struct Struct_02054000* p);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" struct ItemNameEntry* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_0206819c(const char* src, char* dst, int flag);
extern "C" int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* dst, int w);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* dst, int w);
#endif
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void __clear(void* dst, unsigned int size);

// USA: func_ov000_0217831c
extern "C" ARM void func_ov000_0217831c(Struct_ov000_0217831c_3* menu, char* dst)
{
    int first;
    int last;
    func_0205c508((struct Struct_0205c508*)menu->range, &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* texts = (struct Container020e0310*)menu->unknown_b8_;
    const char* separator = KeyTable_Get(texts, 0);
    signed char cursor = menu->cursor;
    const char* unknownName = KeyTable_Get(texts, 5);
    int n = 0;
    signed char combatantId = menu->unknown_70_[menu->unknown_1d6b_];
    int var10 = -1;
    GameState* state = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(state, combatantId);
    struct Struct_ov000_0217831c_2* sub = func_02054000((struct Struct_02054000*)combatant);
    if (sub != NULL) {
        var10 = sub->unknown_18_;
    }
    if (func_ov000_0217542c(menu)) {
        Text_AppendFrameTag(dst, cursor - start, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        char line[0x40];
        __clear(line, sizeof(line));
        int key = menu->unknown_26_[i];
        struct ItemNameEntry* item = ItemTable_Find((struct ItemTable*)menu->itemTable, key);
        const char* name = unknownName;
        if (item != NULL) {
#if defined(jpn)
            name = item->name;
#else
            char text[0x100];
            __clear(text, sizeof(text));
            func_0206819c(item->name, text, 0);
            name = text;
#endif
        }
        if (var10 == key) {
            Text_Append(line, KeyTable_Get(texts, 0x13));
#if !defined(jpn)
            func_02041acc(line, 3);
#endif
        } else {
            func_02041acc(line, 8);
        }
        Text_Append(line, name);
        Text_AppendNTag(dst, n, line);
        if (i != end - 1) {
            Text_Append(dst, separator);
        }
        n++;
    }
}
