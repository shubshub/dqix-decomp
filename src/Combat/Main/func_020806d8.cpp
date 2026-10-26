#include <globaldefs.h>

struct TableA68;
struct Struct_020806d8_2 {
    unsigned int unknown0;
    short id;
    short unknown_6_;
    char unknown8[6];
    short textId;
    char unknown10[2];
    unsigned char kind;
    unsigned char unknown_13_0_ : 4;
    unsigned char unknown_13_4_ : 4;
};
struct Struct_020806d8 {
    char unknown0[0xe];
    short tileWidth;
};
struct Struct_0207f524 {
    Struct_020806d8_2* entries;
    short count;
};
struct Struct_0207f0ac {
    Struct_020806d8* entries;
    short count;
};
struct Struct_020806d8_3 {
    TableA68* unknown_0_;
    Struct_0207f524 items;
    Struct_0207f0ac groups;
};

extern "C" void* func_0207f6ac(Struct_0207f524*, int);
extern "C" Struct_020806d8* func_0207f0ac(Struct_0207f0ac*, int);
extern "C" void* func_02072a68(TableA68*, int);
#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
#else
extern "C" int func_02042190(int);
extern "C" int Font_GetTextWidth(char* text, int fontIndex);
#endif

// USA: func_020806d8
extern "C" ARM void func_020806d8(Struct_020806d8_3* menu, int arg1, int itemId, int arg3, short arg4) {
    Struct_020806d8_2* item = (Struct_020806d8_2*)func_0207f6ac(&menu->items, itemId);
    if (item == NULL) return;
    if (!arg3) {
        item->unknown_6_ = arg4;
        return;
    }
    if (item->kind != 0) return;
    char* text = (char*)func_02072a68(menu->unknown_0_, item->textId);
    if (text == NULL) return;
#if defined(jpn)
    int glyphCount = STD_GetStringLength(text) >> 1;
    int textWidth = glyphCount * item->unknown_13_0_;
#else
    int fontIndex = func_02042190(item->unknown_13_0_);
    int textWidth = Font_GetTextWidth(text, fontIndex);
#endif
    Struct_020806d8* group = func_0207f0ac(&menu->groups, arg1);
    if (group == NULL) return;
    short var6 = group->tileWidth << 3;
    item->unknown_6_ = var6 - textWidth - arg4;
}
