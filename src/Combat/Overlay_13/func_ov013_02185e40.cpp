#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185e40 func_ov013_02186f4c
#endif
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern "C" int Font_GetTextWidth(void* p, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
#if defined(jpn)
extern "C" void func_02046380(void*);
extern "C" unsigned int strlen(const char*);
extern "C" int func_02042638(char*, const char*, int);
extern char data_ov013_02188d4c[];
#else
extern "C" void func_02046380(void);
#endif

struct Struct_ov013_021846a0_2 {
    char unknown0[0x1e];
    short unknown_1e_;
#if defined(jpn)
    char unknown20[0x5ac - 0x20];
#else
    char unknown20[0x620 - 0x20];
#endif
    char texts[0x18];
#if defined(jpn)
    char unknown_5c4_[0x62c - 0x5c4];
#else
    char unknown_638_[0x6a4 - 0x638];
#endif
    const char* name;
    unsigned char vocation;
    unsigned char unknown_6a9_[5];
    char unknown_6ae_[2];
    int level;
    unsigned char unknown_6b4_;
    char unknown_6b5_[3];
    int unknown_6b8_;
    unsigned char flags;
    unsigned char unknown_6bd_;
    unsigned short unknown_6be_;
    unsigned short maxHP;
    unsigned short unknown_6c2_;
    unsigned short maxMP;
    unsigned short attack;
    unsigned short defence;
    unsigned short agility;
};

struct Container020e0310;
extern "C" ARM int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" ARM int func_02041a5c(char* dst, int y);
extern "C" ARM int func_02041a28(char* dst, int x);
extern "C" ARM int func_02041acc(char* dst, int levelWidth);
extern "C" ARM int Text_AppendPaletteTag(char* dst, int palette);
extern "C" ARM int Text_Append(char* dst, const char* src);
extern "C" ARM int StandardStrings_Get(int value);
extern "C" ARM int func_02041fac(char* buf, int a, int b);
extern "C" void* MessageSystem_GetInstance(void);

struct StoreStruct;
extern "C" ARM void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" ARM void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" ARM void func_020465c0(struct StoreStruct* base, int index, int value);

extern char data_ov013_02187e3c;
extern char data_ov013_02187e3f;
extern char data_ov013_02187e44;
extern char data_ov013_02187e45;
extern short data_ov013_02187dac[];

// USA: func_ov013_02185e40
extern "C" ARM void func_ov013_02185e40(Struct_ov013_021846a0_2* menu, char* dst) {
    if (dst == 0) return;

    GameState::GetInstance();

    short labelKey = 0x190;
    short valueKey = 0x1f4;
#if defined(jpn)
    int var2 = strlen(menu->name) + 6;
    int marker;
    int var4;
    int palette;
    int markerIndex = menu->unknown_6b8_;
    marker = 0;
    var4 = 2;
    if (menu->unknown_6b4_ != 0) {
        var4 = 0;
        var2++;
        marker = 1;
    }
    palette = 5;
    if (markerIndex == 0xa) palette = 0xd;
    int x = 0x31 - (int)(((float)var2 / 4.0f) * 10.0f);
    int vocationMarkerText = KeyTable_Get((Container020e0310*)menu->texts, (short)(markerIndex + 0x12c));
    int vocationText = KeyTable_Get((Container020e0310*)menu->texts, (short)(menu->vocation + 0xc8));
    sprintf(dst, data_ov013_02188d4c, x, menu->name, vocationText, marker, palette, vocationMarkerText, var4, menu->level);
#else
    char heading[0x200];
    __clear(heading, 0x200);

    int nameWidth = Font_GetTextWidth((void*)menu->name, 0);
    if (menu->unknown_6b8_ != 0) {
        int key = (short)(menu->unknown_6b8_ + 0x12c);
        int vocationMarkerText = KeyTable_Get((Container020e0310*)menu->texts, key);
        int paletteId = 5;
        if (menu->unknown_6b8_ == 0xa) paletteId = 0xd;

        func_02041a5c(heading, 4);
        Text_Append(heading, menu->name);
        func_02041acc(heading, 0x10);
        Text_AppendPaletteTag(heading, paletteId);
        Text_Append(heading, (const char*)vocationMarkerText);
        func_02041acc(heading, 4);
        Text_AppendPaletteTag(heading, 0xf);
        int v = StandardStrings_Get(0x3f3);
        Text_Append(heading, (const char*)v);

        char levelText[0x10];
        __clear(levelText, 0x10);
        sprintf(levelText, &data_ov013_02187e3c, menu->level);
        Text_Append(heading, levelText);
    } else {
        func_02041a5c(heading, 4);
        Text_Append(heading, menu->name);
        func_02041acc(heading, 0x12);
        int v = StandardStrings_Get(0x3f3);
        Text_Append(heading, (const char*)v);

        char levelText[0x10];
        __clear(levelText, 0x10);
        sprintf(levelText, &data_ov013_02187e3c, menu->level);
        Text_Append(heading, levelText);
    }

    char levelLabel[0x100];
    __clear(levelLabel, 0x100);
    int v2 = StandardStrings_Get(0x3f3);
    sprintf(levelLabel, &data_ov013_02187e3f, v2, menu->level);
    int levelWidth = Font_GetTextWidth(levelLabel, 0);

    int var22 = nameWidth + 0x12 + levelWidth;
    if (menu->unknown_6b8_ != 0) var22 += 9;
    var22 = 0x78 - var22;

    menu->unknown_1e_ = (short)(nameWidth + (var22 >> 1) + 1);
    func_02041a28(dst, var22 >> 1);

    Text_Append(dst, heading);
#endif
#if defined(jpn)
    func_02042638(dst, &data_ov013_02187e44, 0x10);
#else
    func_02041fac(dst, (int)&data_ov013_02187e44, 0x10);
#endif

    void* textVariables = MessageSystem_GetInstance();
#if defined(jpn)
    func_02046380(textVariables);
#else
    func_02046380();
#endif

    int stats[7] = {
        menu->unknown_6be_, menu->maxHP, menu->unknown_6c2_, menu->maxMP,
        menu->attack, menu->defence, menu->agility
    };

    for (int i = 0; i < 7; i++) {
        func_020465d8((unsigned char*)textVariables, i, 1);
        func_020465f0((unsigned char*)textVariables, i, 3);
        func_020465c0((struct StoreStruct*)textVariables, i, stats[i]);
    }

    for (int i = 0; i < 5; i++) {
        int fieldA = KeyTable_Get((Container020e0310*)menu->texts, labelKey++);
        Text_Append(dst, (const char*)fieldA);

        short var28 = data_ov013_02187dac[i];
        func_02041a28(dst, var28);

        int fieldB = KeyTable_Get((Container020e0310*)menu->texts, valueKey++);
        Text_Append(dst, (const char*)fieldB);

        if (i != 4) {
            Text_Append(dst, &data_ov013_02187e45);
        }
    }
}
