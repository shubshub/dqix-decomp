#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov008_0218aa24_6 {
    char unknown_0_[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int unknown_d_7_ : 17;
    char unknown_10_[0x2e - 0x10];
    unsigned char unknown_2e_0_ : 1;
    unsigned char unknown_2e_1_ : 7;
    char unknown_2f_[0x4e - 0x2f];
    unsigned char unknown_4e_0_ : 1;
    unsigned char unknown_4e_1_ : 4;
    unsigned char unknown_4e_5_ : 3;
    unsigned char unknown_4f_;
};

struct Struct_ov008_0218aa24_4 {
    unsigned char unknown_0_0_ : 8;
};

struct Struct_ov008_0218aa24_5 {
    char unknown_0_[0x16c];
    unsigned short unknown_16c_[(0x186 - 0x16c) / 2];
    Struct_ov008_0218aa24_4 unknown_186_[0x49c - 0x186];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int unknown_950_;
};

struct Struct_ov008_0218aa24_7 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov008_0218aa24_5* unknown_150_;
};

struct Struct_ov008_0218aa24 {
    char unknown_0_[0x56a];
    unsigned char unknown_56a_;
};

struct Struct_ov008_0218aa24_2 {
    char unknown_0_[0x115];
    signed char unknown_115_;
    char unknown_116_[0x13d - 0x116];
    signed char unknown_13d_;
};

struct Struct_ov008_0218aa24_3 {
    char unknown_0_[0x18];
    char unknown_18_[0xb8 - 0x18];
    short unknown_b8_;
    short unknown_ba_;
    short unknown_bc_;
    short unknown_be_;
    short unknown_c0_;
    short unknown_c2_;
    short unknown_c4_;
    short unknown_c6_;
    char unknown_c8_;
    unsigned char unknown_c9_;
    char unknown_ca_[0xcd - 0xca];
    unsigned char unknown_cd_;
    char unknown_ce_[0x1f8 - 0xce];
    Struct_ov008_0218aa24_2* unknown_1f8_;
    char unknown_1fc_[0x278 - 0x1fc];
    char unknown_278_[0x2a0 - 0x278];
    char* unknown_2a0_;
#if defined(jpn)
    char unknown_2a4_[0xdf2 - 0x2a4];
    char unknown_df2_[0xe18 - 0xdf2];
#else
    char unknown1_2a4_[0xdf6 - 0x2a4];
    char unknown_df6_[0xe1c - 0xdf6];
#endif
    unsigned int unknown_e1c_0_ : 12;
    unsigned int unknown_e1d_4_ : 4;
    unsigned int unknown_e1e_0_ : 5;
    unsigned int unknown_e1e_5_ : 11;
#if defined(jpn)
    char unknown_e1c_[0xeb1 - 0xe1c];
    signed char unknown_eb1_;
    char unknown_eb2_[0xeb4 - 0xeb2];
#else
    char unknown_e20_[0xeb9 - 0xe20];
    signed char unknown_eb9_;
    char unknown_eba_[0xebc - 0xeba];
#endif
    Struct_ov008_0218aa24_6* unknown_ebc_;
};

struct Struct_02072a68_2;
struct Struct_0205de24_2;
struct Struct_0205d81c;

extern char data_ov008_0218b590[];

void* MessageSystem_GetInstance();
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_02046380(void* w);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
char* FindEntryByKey_02072a68(TableA68*, int);
extern "C" void MessageSystem_FormatText(void* w, int a, char* str, char* buf, int b, int c, int d);
extern "C" int Font_GetTextWidth(const char* text, int large);
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" void* memset(void* p, int v, unsigned int n);
Ent0218aa24* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void func_ov008_0218b240(Self0218aa24* self);
extern "C" void Font_DecodeText(const void* codes, char* text, int value);
void* FindElementByC40205d81c(Struct_0205d81c*, int);
int AppendXYTag_02041a90(char* dst, int x, int y);
void Text_Append(char* text, const char* append);
void AppendLineXTag02041cf4(char* dst, int color, int a, int b, int c);
int Text_AppendPaletteTag(char* dst, int palette);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
extern "C" void func_020474a8(void* w, int a, const char* str, char* buf);
extern "C" int func_ov008_0218bb28(Self0218aa24* self, const char* str);
extern "C" unsigned int strlen(const char* s);
int AppendXTag_02041a28(char* dst, int x);

// USA: func_ov008_0218aa24
extern "C" ARM void func_ov008_0218aa24(Struct_ov008_0218aa24_3* arg0) {
    char var0[0x80];

    void* win = MessageSystem_GetInstance();
    GameState* gs = GameState::GetInstance();
    FindAndLinkMatchingEntry0205de24((Struct0205de24*)self->list, 0, 2);
    self->c9 = 0;
    self->bc = 0x15;
    self->be = 0;
    self->c0 = 8;
    self->c2 = 3;
    self->b8 = 11;
    self->ba = 7;
    self->c4 = 10;
    self->c6 = 12;
    self->cd = 1;
    memset(self->text, 0, 0x800);

    int var3;
    int var4;
    unsigned char var5;
    unsigned char var6;
    const char* var7;
    if (arg0->unknown_ebc_ == 0) {
        int var8 = 0;
        Struct_ov008_0218aa24_7* var9 = (Struct_ov008_0218aa24_7*)var2->GetPartyMemberByIndex(arg0->unknown_eb1_);
        Struct_ov008_0218aa24* var10 = 0;
        if (var9 == 0) {
            var8 = 1;
        } else {
            var10 = func_02053c6c((unsigned char*)var9);
            if (var10 == 0) var8 = 1;
        }
        if (var8) {
            func_ov008_0218b240(arg0);
            return;
        }
        Struct_ov008_0218aa24_5* var11 = var9->unknown_150_;
        var3 = var11->unknown_950_;
        var5 = var11->unknown_186_[var3].unknown_0_0_;
        var4 = var11->unknown_16c_[var3];
        var7 = arg0->unknown_df2_;
        var6 = var10->unknown_56a_;
    } else {
        Struct_ov008_0218aa24_6* var12 = arg0->unknown_ebc_;
        var3 = var12->unknown_c_0_;
        var4 = var12->unknown_d_0_;
        var5 = var12->unknown_4e_1_;
        var6 = var12->unknown_4f_;
        var7 = (const char*)var12;
    }
    FindElementByC40205d81c((Struct_0205d81c*)self->list, 0);
    AppendXYTag_02041a90(self->text, func_ov008_0218bb28(self, name), 3);
    Text_Append(self->text, name);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, 0x56, 0xf);

    char* str = FindEntryByKey_02072a68((TableA68*)self->texts, (short)vocation);
    int x = func_ov008_0218bb28(self, str);
    if (rank != 0) x -= 5;
    AppendXYTag_02041a90(self->text, x, 0x12);
    Text_Append(self->text, str);
    if (rank != 0) {
        if (rank >= 10) {
            rank = 10;
            Text_AppendPaletteTag(self->text, 0xd);
        } else {
            Text_AppendPaletteTag(self->text, 5);
        }
        int x2 = x + strlen(str) / 2 * 10;
        str = FindEntryByKey_02072a68((TableA68*)self->texts, (short)(rank + 0x12c));
        AppendXYTag_02041a90(self->text, x2, 0x11);
        Text_Append(self->text, str);
        Text_AppendPaletteTag(self->text, 0xf);
    }

    func_02046380(win);
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 0, scroll);
    SetByteAtIndex_020465d8((unsigned char*)win, 0, 0);
    SetByteInRange_020465f0((unsigned char*)win, 0, 3);
    func_020474a8(win, 10, FindEntryByKey_02072a68((TableA68*)self->texts, 0x1f6), buf80);
    AppendXYTag_02041a90(self->text, 0x1f, 0x1b);
    Text_Append(self->text, buf80);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, 0x56, 0x28);
    memset(buf80, 0, 0x80);
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 1, self->e1c_title);
    SetByteAtIndex_020465d8((unsigned char*)win, 1, 1);
    SetByteInRange_020465f0((unsigned char*)win, 1, 2);
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 2, self->e1c_scroll);
    SetByteAtIndex_020465d8((unsigned char*)win, 2, 1);
    SetByteInRange_020465f0((unsigned char*)win, 2, 2);
    func_020474a8(win, 10, FindEntryByKey_02072a68((TableA68*)self->texts, 0x1f8), buf80);
    AppendXTag_02041a28(self->text, 12);
    Text_Append(self->text, buf80);
    Window_OpenPane(self->list, self->text, 0, 0, 0, 1, 0);
    self->link->level115 = (signed char)level;
    self->link->level13d = (signed char)level;
}
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov008_0218aa24
extern "C" ARM void func_ov008_0218aa24(Struct_ov008_0218aa24_3* arg0) {
    char var16[0x80];
    char var17[0x40];
    char var18[0x30];

    void* win = MessageSystem_GetInstance();
    GameState* gs = GameState::GetInstance();
    __clear(buf40, 0x40);
    func_02046380(win);
    MessageSystem_SetStringArgument((Obj02046574*)win, 0, data_ov008_0218b590);
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 2, 0x21);
    MessageSystem_FormatText(win, 10, FindEntryByKey_02072a68((TableA68*)self->texts, 0x1f8), buf40, 0x100, 0, 0);
    int width = (Font_GetTextWidth(buf40, 0) + 0x17) & ~7;
    if (width < 0x58) width = 0x58;
    FindAndLinkMatchingEntry0205de24((Struct0205de24*)self->list, 0, 2);
    self->c9 = 0;
    self->bc = 0x20 - (width >> 3);
    self->be = 0;
    self->c0 = 8;
    self->c2 = 3;
    self->b8 = width >> 3;
    self->ba = 7;
    self->c4 = 10;
    self->c6 = 12;
    self->cd = 1;
    memset(self->text, 0, 0x960);
    __clear(name, 0x30);

    int var22;
    unsigned char var23;
    int var24;
    unsigned char var25;
    int var26;
    const void* var27;
    if (arg0->unknown_ebc_ == 0) {
        int var28 = 0;
        Struct_ov008_0218aa24_7* var29 = (Struct_ov008_0218aa24_7*)var20->GetPartyMemberByIndex(arg0->unknown_eb9_);
        Struct_ov008_0218aa24* var30 = 0;
        if (var29 == 0) {
            var28 = 1;
        } else {
            var30 = func_02053c6c((unsigned char*)var29);
            if (var30 == 0) var28 = 1;
        }
        if (var28) {
            func_ov008_0218b240(arg0);
            return;
        }
        Struct_ov008_0218aa24_5* var31 = var29->unknown_150_;
        var22 = var31->unknown_950_;
        var25 = var31->unknown_186_[var22].unknown_0_0_;
        var26 = var31->unknown_16c_[var22];
        var27 = arg0->unknown_df6_;
        var24 = var31->unknown_49c_0_;
        var23 = var30->unknown_56a_;
    } else {
        Struct_ov008_0218aa24_6* var32 = arg0->unknown_ebc_;
        var22 = var32->unknown_c_0_;
        var26 = var32->unknown_d_0_;
        var24 = var32->unknown_2e_0_;
        var25 = var32->unknown_4e_1_;
        var23 = var32->unknown_4f_;
        var27 = var32;
    }
    Font_DecodeText(codes, name, 1);
    FindElementByC40205d81c((Struct_0205d81c*)self->list, 0);
    AppendXYTag_02041a90(self->text, (width - Font_GetTextWidth(name, 0)) / 2, 3);
    Text_Append(self->text, name);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, width - 2, 0xf);

    char* var33;
    if (var24) {
        var33 = func_02072a68((Struct_02072a68_2*)arg0->unknown_278_, (short)(var22 + 0x46));
    } else {
        var33 = func_02072a68((Struct_02072a68_2*)arg0->unknown_278_, (short)var22);
    }
    int x = (width - Font_GetTextWidth(str, 0)) / 2;
    if (rank != 0) x -= 5;
    AppendXYTag_02041a90(self->text, x, 0x12);
    Text_Append(self->text, str);
    if (rank != 0) {
        if (rank >= 10) {
            rank = 10;
            Text_AppendPaletteTag(self->text, 0xd);
        } else {
            Text_AppendPaletteTag(self->text, 5);
        }
        int x2 = x + Font_GetTextWidth(str, 0);
        str = FindEntryByKey_02072a68((TableA68*)self->texts, (short)(rank + 0x12c));
        AppendXYTag_02041a90(self->text, x2 + 2, 0x12);
        Text_Append(self->text, str);
        Text_AppendPaletteTag(self->text, 0xf);
    }

    func_02046380(win);
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 0, scroll);
    SetByteAtIndex_020465d8((unsigned char*)win, 0, 0);
    SetByteInRange_020465f0((unsigned char*)win, 0, 3);
    MessageSystem_FormatText(win, 10, FindEntryByKey_02072a68((TableA68*)self->texts, 0x1f6), buf80, 0x100, 0, 0);
    AppendXYTag_02041a90(self->text, (width >> 1) - 13, 0x1e);
    Text_Append(self->text, buf80);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, width - 2, 0x28);
    memset(buf80, 0, 0x80);
    MessageSystem_SetStringArgument((Obj02046574*)win, 0, FindEntryByKey_02072a68((TableA68*)self->texts, (short)(self->e1c_title + 0x1f9)));
    StoreInArray0x8b0_020465c0((StoreStruct*)win, 2, self->e1c_scroll);
    MessageSystem_FormatText(win, 10, FindEntryByKey_02072a68((TableA68*)self->texts, 0x1f8), buf80, 0x100, 0, 0);
    AppendXYTag_02041a90(self->text, 12, 0x2a);
    Text_Append(self->text, buf80);
    Window_OpenPane(self->list, self->text, 0, 0, 0, 1, 0, 0);
    self->link->level115 = (signed char)level;
    self->link->level13d = (signed char)level;
}
#endif
