#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif
#if defined(jpn)
extern "C" const char data_ov023_021fcdef[];
extern "C" const char data_ov023_021fcdfe[];
#endif

struct Struct_ov023_021db634;

struct Struct_ov023_021db634_2 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021db634_3 {
    int unknown_0_;
    Struct_ov023_021db634* unknown_4_;
    char unknown_8_[0x12 - 8];
    short unknown_12_;
};

struct Struct_ov023_021db634_4
{
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    short unknown_2_;
    const char* unknown_4_;
};

struct Struct_ov023_021db634_5
{
    short unknown_0_;
    short unknown_2_;
    Struct_ov023_021db634_4* unknown_4_;
};

struct Struct_ov023_021db634_6
{
    char unknown_0_[8];
    Struct_ov023_021db634_5* unknown_8_;
    char unknown_c_[4];
};

struct Struct_ov023_021db634_7
{
    const char* unknown_0_;
    unsigned char unknown_4_;
};

struct Struct_0201099c_3;
struct Struct_0201bb78;
struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0 {
#if defined(jpn)
    struct Struct_0201099c_3* unknown_14_;
    void* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    void* unknown1_4_;
    int unknown_18_;
    void* unknown_1c_;
    Struct_ov023_021db634_6* unknown_24_;
    struct Struct_0201099c_3* unknown1_8_;
    int unknown_28_;

#else
    void* unknown_0_;
    void* unknown1_4_;
    struct Struct_0201099c_3* unknown1_8_;
    int unknown1_c_;
    int unknown1_10_;
    struct Struct_0201099c_3* unknown_14_;
    int unknown1_18_;
    int unknown1_1c_;
    void* unknown_20_;
    Struct_ov023_021db634_6* unknown_24_;

#endif
};
extern "C" Struct_ov023_021ff9e0 data_ov023_021ff9e0;
extern "C" const short data_ov023_021fd5b8[3];

const char* KeyTable_Get(struct Container020e0310* c, int key);
const char* CallFunc020e0434With02153694_020e51cc(int id);
extern "C" LayoutElement_021db634* func_ov023_021db4e4(Layout_021db634* layout, int id);
void SetEntryFields_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char shadow);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" unsigned int strlen(const char* text);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" long func_02005a94(const char* text);
extern "C" void* func_02012fe4();
extern "C" int func_0201bb78(struct Struct_0201bb78* arg0, unsigned int arg1);
extern "C" void* func_0205ec34();
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" void func_020ac2d4(int, short* arg1, void* arg2, int arg3);
extern "C" int func_0206e384(unsigned char* arg0);
extern "C" int func_0206e3d4(int arg0, int arg1);
extern "C" unsigned int func_ov023_021db564(char* arg0);
extern "C" void func_ov023_021dbb20(struct Struct_ov023_021db634_7* arg0, struct Struct_ov023_021db634_7* arg1);
extern "C" int func_0201079c(char* arg0);
extern "C" void func_ov023_021db45c(void* arg0, struct Struct_ov023_021db45c* arg1, int arg2, short* arg3, short* arg4);
extern "C" void func_ov023_021e257c(Struct_ov023_021db634_3* arg0);
extern "C" void func_ov023_021db544(void* arg0, void* arg1, int arg2, int arg3);

#define SHOW_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021db634_2* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->unknown_16_ |= 1;                                          \
    }

#define HIDE_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021db634_2* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->unknown_16_ &= ~1;                                         \
    }

// USA: func_ov023_021db634
extern "C" ARM void func_ov023_021db634(Struct_ov023_021db634_3* arg0, Struct_ov023_021db634* arg1)
{
    const char* found;
    const char* none;
    const char* trade;
    const char* alchemy;
    IntBytePair021dbb20 places[4];
    ItemInfoList_021db634* list;
    ItemInfoEntry_021db634* entry;
    short entries;
    unsigned char shown;
    int last;
    int i2;
    int j;
    int i3;
    unsigned char count;
    int i;
    found = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1f);
    none = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1e);
#if defined(jpn)
    var2 = data_ov023_021fcdef;
    var3 = data_ov023_021fcdfe;
#else
    trade = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x2a);
    alchemy = CallFunc020e0434With02153694_020e51cc(0x56);
#endif

    SHOW_ELEMENT(arg0, 0xf);
    SHOW_ELEMENT(arg0, 0xa);
    func_ov023_021e23d0(arg0, 7, (int)var0, 10, 15);
    func_ov023_021e23d0(arg0, 8, (int)var0, 10, 15);
    func_ov023_021e23d0(arg0, 9, (int)var0, 10, 15);
    func_ov023_021e23d0(arg0, 0xa, (int)var1, 10, 15);
    memset(var4, 0, sizeof(var4));
    var13 = 0;
    var5 = data_ov023_021ff9e0.unknown_24_->unknown_8_;
    if (var5 != NULL)
    {
        var14 = 0;
        var6 = var5->unknown_4_;
        var7 = var5->unknown_2_;
        for (; var14 < var7; var14++, var6++)
        {
            Struct_ov023_021db634_7 var15;
            var15.unknown_0_ = NULL;
            var15.unknown_4_ = 0;
            if (!var6->unknown_1_)
                continue;
            const char* var16 = var6->unknown_4_;
            if (var16 != NULL)
            {
            char var17 = var16[0];
            if (var17 == 'f')
            {
                if (strlen(var16) >= 5)
                {
                    char var18[4] = {0};
                    memcpy(var18, var6->unknown_4_ + 2, 2);
                    short var19 = func_02005a94(var18);
                    if (!func_0201bb78((Struct_0201bb78*)func_02012fe4(), (unsigned short)(var19 + 20000)))
                        continue;
                    text = KeyTable_Get(data_ov023_021ff9e0.sFieldNames, (short)func_02005a94(entry->text_ + 5));
                    place.kind_ = 2;
                }
            }
            else if (var17 == 'a')
            {
                short var20 = func_02005a94(var16 + 1);
                void* var21 = func_0205ec34();
                if (!func_0206dfb0((int)var21, (unsigned char*)var21 + 0x8c, 0x1198))
                    continue;
                struct
                {
                    short unknown_0_;
                    unsigned short unknown_2_0_ : 1;
                } var22;
                memset(&var22, 0, sizeof(var22));
                func_020ac2d4(0, &var20, &var22, 1);
                if (var22.unknown_0_ == 0 || !var22.unknown_2_0_)
                    continue;
                var15.unknown_4_ = 1;
                var16 = var3;
            }
            else if (var17 == 'b')
            {
                void* var23 = func_0205ec34();
                int var24 = func_0206e384((unsigned char*)var23);
                if (!((1 << (func_0206e3d4((int)var23, 0x17) - 1)) & (var24 << 0x10)))
                    continue;
                var15.unknown_4_ = 3;
                var16 = var2;
            }
            else if (var17 >= 'A' && var17 <= 'Z')
            {
                void* var25 = func_02012fe4();
                unsigned short var26 = func_ov023_021db564((char*)var6->unknown_4_);
                if (var26 == 0)
                    continue;
                if (!func_0201bb78((Struct_0201bb78*)var25, var26))
                    continue;
                text = KeyTable_Get(data_ov023_021ff9e0.sFieldNames, (short)id);
                place.kind_ = 4;
            }
            }
            if (var16 == NULL)
                continue;
            var15.unknown_0_ = var16;
            func_ov023_021dbb20(&var4[var13], &var15);
            var13++;
            if (var13 == 4)
                break;
        }
    }
    if (func_0201079c((char*)GameState::GetInstance()) == 1)
        var13 = 0;
    var8 = var13;
    if (var13 == 4)
        var8 = 3;
    var9 = var8;
    var9 -= 1;
    for (var10 = 0; var10 < var9; var10++)
    {
        for (var11 = 0; var11 < var9 - var10; var11++)
        {
            if (var4[var11].unknown_4_ < var4[var11 + 1].unknown_4_)
            {
                Struct_ov023_021db634_7 var27 = var4[var11];
                func_ov023_021dbb20(&var4[var11], &var4[var11 + 1]);
                func_ov023_021dbb20(&var4[var11 + 1], &var27);
            }
        }
    }
    for (var12 = 0; var12 < 3; var12++)
    {
        if (var12 == var13)
            break;
        func_ov023_021e23d0(arg0, data_ov023_021fd5b8[var12], (int)var4[var12].unknown_0_, 10, 15);
    }
    if (var13 != 4)
        HIDE_ELEMENT(arg0, 0xa);
    short var28;
    short var29;
    func_ov023_021db45c(arg0, (Struct_ov023_021db45c*)arg1, 0xf, &var28, &var29);
    if (data_ov023_021ff9e0.unknown1_4_ != NULL)
    {
        arg0->unknown_4_ = arg1;
        arg0->unknown_12_ = 1;
        func_ov023_021e257c(arg0);
    }
    func_ov023_021db544(arg0, (void*)0xf, var28, var29);
    HIDE_ELEMENT(arg0, 0xf);
}
