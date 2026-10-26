#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
extern "C" const char data_ov023_021fcdef[];
extern "C" const char data_ov023_021fcdfe[];
#endif

struct Struct_ov023_021db634;

struct Struct_ov023_021db634_2 {
    char pad0[0x16];
    unsigned char flags_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021db634_3 {
    int unk_0;
    Struct_ov023_021db634* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
};

struct Struct_ov023_021db634_4
{
    unsigned char unk_0;
    unsigned char unknown_1_;
    short unk_2;
    const char* text_;
};

struct Struct_ov023_021db634_5
{
    short unk_0;
    short count_;
    Struct_ov023_021db634_4* entries_;
};

struct Struct_ov023_021db634_6
{
    char unk_0[8];
    Struct_ov023_021db634_5* list_;
    char unk_c[4];
};

struct Struct_ov023_021db634_7
{
    const char* text_;
    unsigned char kind_;
};

struct Container020e0310;
struct Obj_0201bb78;
struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0 {
#if defined(jpn)
    struct Container020e0310* sTexts;
    void* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    void* unknown1_4_;
    int unknown_18_;
    void* sWindow;
    Struct_ov023_021db634_6* unknown_24_;
    struct Container020e0310* sFieldNames;
    int unknown_28_;

#else
    void* unknown_0_;
    void* unknown1_4_;
    struct Container020e0310* sFieldNames;
    int unknown1_c_;
    int unknown1_10_;
    struct Container020e0310* sTexts;
    int unknown1_18_;
    int unknown1_1c_;
    void* sWindow;
    Struct_ov023_021db634_6* unknown_24_;

#endif
};
extern "C" Struct_ov023_021ff9e0 data_ov023_021ff9e0;
extern "C" const short data_ov023_021fd5b8[3];

extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" const char* StandardStrings_Get(int id);
extern "C" Struct_ov023_021db634_2* func_ov023_021db4e4(Struct_ov023_021db634_3* layout, int id);
extern "C" void func_ov023_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char arg4);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" unsigned int strlen(const char* text);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" long func_02005a94(const char* text);
extern "C" void* Zone3D_GetInstance();
extern "C" int func_0201bb78(struct Obj_0201bb78* flags, unsigned int id);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int flags, unsigned char* flags2, int id);
extern "C" void func_020ac2d4(int, short* ids, void* arg2, int count);
extern "C" int func_0206e384(unsigned char* flags);
extern "C" int func_0206e3d4(int flags, int index);
extern "C" unsigned int func_ov023_021db564(char* text);
extern "C" void func_ov023_021dbb20(struct Struct_ov023_021db634_7* dst, struct Struct_ov023_021db634_7* src);
extern "C" int GameState_GetStoryChapter(char* gameState);
extern "C" void func_ov023_021db45c(void* layout, struct Struct_ov023_021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Struct_ov023_021db634_3* layout);
extern "C" void func_ov023_021db544(void* layout, void* id, int x, int y);

#define SHOW_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021db634_2* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ |= 1;                                          \
    }

#define HIDE_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021db634_2* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ &= ~1;                                         \
    }

// USA: func_ov023_021db634
extern "C" ARM void func_ov023_021db634(Struct_ov023_021db634_3* layout, Struct_ov023_021db634* canvas)
{
    const char* found;
    const char* none;
    const char* trade;
    const char* alchemy;
    Struct_ov023_021db634_7 var4[4];
    Struct_ov023_021db634_5* list;
    Struct_ov023_021db634_4* entry;
    short entries;
    unsigned char shown;
    int last;
    int i2;
    int j;
    int var12;
    unsigned char count;
    int i;
    found = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1f);
    none = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1e);
#if defined(jpn)
    trade = data_ov023_021fcdef;
    alchemy = data_ov023_021fcdfe;
#else
    trade = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x2a);
    alchemy = StandardStrings_Get(0x56);
#endif

    SHOW_ELEMENT(layout, 0xf);
    SHOW_ELEMENT(layout, 0xa);
    func_ov023_021e23d0(layout, 7, (int)found, 10, 15);
    func_ov023_021e23d0(layout, 8, (int)found, 10, 15);
    func_ov023_021e23d0(layout, 9, (int)found, 10, 15);
    func_ov023_021e23d0(layout, 0xa, (int)none, 10, 15);
    memset(var4, 0, sizeof(var4));
    count = 0;
    list = data_ov023_021ff9e0.unknown_24_->list_;
    if (list != NULL)
    {
        i = 0;
        entry = list->entries_;
        entries = list->count_;
        for (; i < entries; i++, entry++)
        {
            Struct_ov023_021db634_7 place;
            place.text_ = NULL;
            place.kind_ = 0;
            if (!entry->unknown_1_)
                continue;
            const char* text = entry->text_;
            if (text != NULL)
            {
            char c = text[0];
            if (c == 'f')
            {
                if (strlen(text) >= 5)
                {
                    char number[4] = {0};
                    memcpy(number, entry->text_ + 2, 2);
                    short field = func_02005a94(number);
                    if (!func_0201bb78((Obj_0201bb78*)Zone3D_GetInstance(), (unsigned short)(field + 20000)))
                        continue;
                    text = KeyTable_Get(data_ov023_021ff9e0.sFieldNames, (short)func_02005a94(entry->text_ + 5));
                    place.kind_ = 2;
                }
            }
            else if (c == 'a')
            {
                short var20 = func_02005a94(text + 1);
                void* flags = Scenario_GetInstance();
                if (!Scenario_TestFlag((int)flags, (unsigned char*)flags + 0x8c, 0x1198))
                    continue;
                struct
                {
                    short id_;
                    unsigned short unknown_2_0_ : 1;
                } result;
                memset(&result, 0, sizeof(result));
                func_020ac2d4(0, &var20, &result, 1);
                if (result.id_ == 0 || !result.unknown_2_0_)
                    continue;
                place.kind_ = 1;
                text = alchemy;
            }
            else if (c == 'b')
            {
                void* flags = Scenario_GetInstance();
                int bits = func_0206e384((unsigned char*)flags);
                if (!((1 << (func_0206e3d4((int)flags, 0x17) - 1)) & (bits << 0x10)))
                    continue;
                place.kind_ = 3;
                text = trade;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                void* flags = Zone3D_GetInstance();
                unsigned short id = func_ov023_021db564((char*)entry->text_);
                if (id == 0)
                    continue;
                if (!func_0201bb78((Obj_0201bb78*)flags, id))
                    continue;
                text = KeyTable_Get(data_ov023_021ff9e0.sFieldNames, (short)id);
                place.kind_ = 4;
            }
            }
            if (text == NULL)
                continue;
            place.text_ = text;
            func_ov023_021dbb20(&var4[count], &place);
            count++;
            if (count == 4)
                break;
        }
    }
    if (GameState_GetStoryChapter((char*)GameState::GetInstance()) == 1)
        count = 0;
    shown = count;
    if (count == 4)
        shown = 3;
    last = shown;
    last -= 1;
    for (i2 = 0; i2 < last; i2++)
    {
        for (j = 0; j < last - i2; j++)
        {
            if (var4[j].kind_ < var4[j + 1].kind_)
            {
                Struct_ov023_021db634_7 place = var4[j];
                func_ov023_021dbb20(&var4[j], &var4[j + 1]);
                func_ov023_021dbb20(&var4[j + 1], &place);
            }
        }
    }
    for (var12 = 0; var12 < 3; var12++)
    {
        if (var12 == count)
            break;
        func_ov023_021e23d0(layout, data_ov023_021fd5b8[var12], (int)var4[var12].text_, 10, 15);
    }
    if (count != 4)
        HIDE_ELEMENT(layout, 0xa);
    short x;
    short y;
    func_ov023_021db45c(layout, (Struct_ov023_021db45c*)canvas, 0xf, &x, &y);
    if (data_ov023_021ff9e0.unknown1_4_ != NULL)
    {
        layout->canvas_ = canvas;
        layout->unk_12 = 1;
        func_ov023_021e257c(layout);
    }
    func_ov023_021db544(layout, (void*)0xf, x, y);
    HIDE_ELEMENT(layout, 0xf);
}
