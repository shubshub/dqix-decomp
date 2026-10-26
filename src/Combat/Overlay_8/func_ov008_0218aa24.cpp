#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov008_0218aa24_6 {
    char pad0[0xc];
    unsigned int kind : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int scroll : 7;
    unsigned int unknown_d_7_ : 17;
    char pad10[0x2e - 0x10];
    unsigned char female : 1;
    unsigned char unknown_2e_1_ : 7;
    char unknown_2f_[0x4e - 0x2f];
    unsigned char unknown_4e_0_ : 1;
    unsigned char rank : 4;
    unsigned char unknown_4e_5_ : 3;
    unsigned char level;
};

struct Struct_ov008_0218aa24_4 {
    unsigned char count : 8;
};

struct Struct_ov008_0218aa24_5 {
    char pad0[0x16c];
    unsigned short scroll[(0x186 - 0x16c) / 2];
    Struct_ov008_0218aa24_4 rank[0x49c - 0x186];
    unsigned char female : 1;
    unsigned char unknown_49c_1_ : 7;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int vocation;
};

struct Struct_ov008_0218aa24_7 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    Struct_ov008_0218aa24_5* data;
};

struct Struct_ov008_0218aa24 {
    char pad0[0x56a];
    unsigned char level;
};

struct Struct_ov008_0218aa24_2 {
    char pad0[0x115];
    signed char unknown_115_;
    char unknown_116_[0x13d - 0x116];
    signed char unknown_13d_;
};

struct Struct_ov008_0218aa24_3 {
    char pad0[0x18];
    char list[0xb8 - 0x18];
    short b8;
    short unknown_ba_;
    short unknown_bc_;
    short unknown_be_;
    short c0;
    short c2;
    short c4;
    short c6;
    char unknown_c8_;
    unsigned char unknown_c9_;
    char unknown_ca_[0xcd - 0xca];
    unsigned char cd;
    char unknown_ce_[0x1f8 - 0xce];
    Struct_ov008_0218aa24_2* link;
    char unknown_1fc_[0x278 - 0x1fc];
    char texts[0x2a0 - 0x278];
    char* text;
#if defined(jpn)
    char unknown_2a4_[0xdf2 - 0x2a4];
    char codes[0xe18 - 0xdf2];
#else
    char unknown1_2a4_[0xdf6 - 0x2a4];
    char codes[0xe1c - 0xdf6];
#endif
    unsigned int unknown_e1c_0_ : 12;
    unsigned int e1c_title : 4;
    unsigned int unknown_e1e_0_ : 5;
    unsigned int unknown_e1e_5_ : 11;
#if defined(jpn)
    char unknown_e1c_[0xeb1 - 0xe1c];
    signed char member;
    char unknown_eb2_[0xeb4 - 0xeb2];
#else
    char unknown_e20_[0xeb9 - 0xe20];
    signed char member;
    char unknown_eba_[0xebc - 0xeba];
#endif
    Struct_ov008_0218aa24_6* unknown_ebc_;
};

struct TableA68;
struct Struct0205de24;
struct Struct_0205d81c;

extern char data_ov008_0218b590[];

extern "C" void* MessageSystem_GetInstance();
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_02046380(void* w);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" char* func_02072a68(TableA68*, int);
extern "C" void MessageSystem_FormatText(void* w, int a, char* str, char* buf, int b, int c, int d);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void func_0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" void* memset(void* p, int v, unsigned int n);
extern "C" Struct_ov008_0218aa24* func_02053c6c(unsigned char*);
extern "C" void func_ov008_0218b240(Struct_ov008_0218aa24_3* self);
extern "C" void Font_DecodeText(const void* codes, char* text, int value);
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
extern "C" int func_02041a90(char* dst, int x, int y);
extern "C" void Text_Append(char* text, const char* append);
extern "C" void func_02041cf4(char* dst, int color, int a, int b, int c);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
extern "C" void func_020474a8(void* w, int a, const char* str, char* buf);
extern "C" int func_ov008_0218bb28(Struct_ov008_0218aa24_3* self, const char* str);
extern "C" unsigned int strlen(const char* s);
extern "C" int func_02041a28(char* dst, int x);

// USA: func_ov008_0218aa24
extern "C" ARM void func_ov008_0218aa24(Struct_ov008_0218aa24_3* self) {
    char buf80[0x80];

    void* win = MessageSystem_GetInstance();
    GameState* gs = GameState::GetInstance();
    func_0205de24((Struct0205de24*)self->list, 0, 2);
    self->unknown_c9_ = 0;
    self->unknown_bc_ = 0x15;
    self->unknown_be_ = 0;
    self->c0 = 8;
    self->c2 = 3;
    self->b8 = 11;
    self->unknown_ba_ = 7;
    self->c4 = 10;
    self->c6 = 12;
    self->cd = 1;
    memset(self->text, 0, 0x800);

    int vocation;
    int scroll;
    unsigned char rank;
    unsigned char level;
    const char* name;
    if (self->unknown_ebc_ == 0) {
        int var8 = 0;
        Struct_ov008_0218aa24_7* m = (Struct_ov008_0218aa24_7*)gs->GetPartyMemberByIndex(self->member);
        Struct_ov008_0218aa24* ent = 0;
        if (m == 0) {
            var8 = 1;
        } else {
            ent = func_02053c6c((unsigned char*)m);
            if (ent == 0) var8 = 1;
        }
        if (var8) {
            func_ov008_0218b240(self);
            return;
        }
        Struct_ov008_0218aa24_5* data = m->data;
        vocation = data->vocation;
        rank = data->rank[vocation].count;
        scroll = data->scroll[vocation];
        name = self->codes;
        level = ent->level;
    } else {
        Struct_ov008_0218aa24_6* var12 = self->unknown_ebc_;
        vocation = var12->kind;
        scroll = var12->scroll;
        rank = var12->rank;
        level = var12->level;
        name = (const char*)var12;
    }
    func_0205d81c((Struct_0205d81c*)self->list, 0);
    func_02041a90(self->text, func_ov008_0218bb28(self, name), 3);
    Text_Append(self->text, name);
    func_02041cf4(self->text, 0x7fff, 2, 0x56, 0xf);

    char* str = func_02072a68((TableA68*)self->texts, (short)vocation);
    int x = func_ov008_0218bb28(self, str);
    if (rank != 0) x -= 5;
    func_02041a90(self->text, x, 0x12);
    Text_Append(self->text, str);
    if (rank != 0) {
        if (rank >= 10) {
            rank = 10;
            Text_AppendPaletteTag(self->text, 0xd);
        } else {
            Text_AppendPaletteTag(self->text, 5);
        }
        int x2 = x + strlen(str) / 2 * 10;
        str = func_02072a68((TableA68*)self->texts, (short)(rank + 0x12c));
        func_02041a90(self->text, x2, 0x11);
        Text_Append(self->text, str);
        Text_AppendPaletteTag(self->text, 0xf);
    }

    func_02046380(win);
    func_020465c0((StoreStruct*)win, 0, scroll);
    func_020465d8((unsigned char*)win, 0, 0);
    func_020465f0((unsigned char*)win, 0, 3);
    func_020474a8(win, 10, func_02072a68((TableA68*)self->texts, 0x1f6), buf80);
    func_02041a90(self->text, 0x1f, 0x1b);
    Text_Append(self->text, buf80);
    func_02041cf4(self->text, 0x7fff, 2, 0x56, 0x28);
    memset(buf80, 0, 0x80);
    func_020465c0((StoreStruct*)win, 1, self->e1c_title);
    func_020465d8((unsigned char*)win, 1, 1);
    func_020465f0((unsigned char*)win, 1, 2);
    func_020465c0((StoreStruct*)win, 2, self->unknown_e1e_0_);
    func_020465d8((unsigned char*)win, 2, 1);
    func_020465f0((unsigned char*)win, 2, 2);
    func_020474a8(win, 10, func_02072a68((TableA68*)self->texts, 0x1f8), buf80);
    func_02041a28(self->text, 12);
    Text_Append(self->text, buf80);
    Window_OpenPane(self->list, self->text, 0, 0, 0, 1, 0);
    self->link->unknown_115_ = (signed char)level;
    self->link->unknown_13d_ = (signed char)level;
}
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov008_0218aa24
extern "C" ARM void func_ov008_0218aa24(Struct_ov008_0218aa24_3* self) {
    char buf80[0x80];
    char buf40[0x40];
    char name[0x30];

    void* win = MessageSystem_GetInstance();
    GameState* gs = GameState::GetInstance();
    __clear(buf40, 0x40);
    func_02046380(win);
    MessageSystem_SetStringArgument((Obj02046574*)win, 0, data_ov008_0218b590);
    func_020465c0((StoreStruct*)win, 2, 0x21);
    MessageSystem_FormatText(win, 10, func_02072a68((TableA68*)self->texts, 0x1f8), buf40, 0x100, 0, 0);
    int width = (Font_GetTextWidth(buf40, 0) + 0x17) & ~7;
    if (width < 0x58) width = 0x58;
    func_0205de24((Struct0205de24*)self->list, 0, 2);
    self->unknown_c9_ = 0;
    self->unknown_bc_ = 0x20 - (width >> 3);
    self->unknown_be_ = 0;
    self->c0 = 8;
    self->c2 = 3;
    self->b8 = width >> 3;
    self->unknown_ba_ = 7;
    self->c4 = 10;
    self->c6 = 12;
    self->cd = 1;
    memset(self->text, 0, 0x960);
    __clear(name, 0x30);

    int vocation;
    unsigned char level;
    int female;
    unsigned char rank;
    int scroll;
    const void* codes;
    if (self->unknown_ebc_ == 0) {
        int var28 = 0;
        Struct_ov008_0218aa24_7* m = (Struct_ov008_0218aa24_7*)gs->GetPartyMemberByIndex(self->member);
        Struct_ov008_0218aa24* ent = 0;
        if (m == 0) {
            var28 = 1;
        } else {
            ent = func_02053c6c((unsigned char*)m);
            if (ent == 0) var28 = 1;
        }
        if (var28) {
            func_ov008_0218b240(self);
            return;
        }
        Struct_ov008_0218aa24_5* data = m->data;
        vocation = data->vocation;
        rank = data->rank[vocation].count;
        scroll = data->scroll[vocation];
        codes = self->codes;
        female = data->female;
        level = ent->level;
    } else {
        Struct_ov008_0218aa24_6* var32 = self->unknown_ebc_;
        vocation = var32->kind;
        scroll = var32->scroll;
        female = var32->female;
        rank = var32->rank;
        level = var32->level;
        codes = var32;
    }
    Font_DecodeText(codes, name, 1);
    func_0205d81c((Struct_0205d81c*)self->list, 0);
    func_02041a90(self->text, (width - Font_GetTextWidth(name, 0)) / 2, 3);
    Text_Append(self->text, name);
    func_02041cf4(self->text, 0x7fff, 2, width - 2, 0xf);

    char* str;
    if (female) {
        str = func_02072a68((TableA68*)self->texts, (short)(vocation + 0x46));
    } else {
        str = func_02072a68((TableA68*)self->texts, (short)vocation);
    }
    int x = (width - Font_GetTextWidth(str, 0)) / 2;
    if (rank != 0) x -= 5;
    func_02041a90(self->text, x, 0x12);
    Text_Append(self->text, str);
    if (rank != 0) {
        if (rank >= 10) {
            rank = 10;
            Text_AppendPaletteTag(self->text, 0xd);
        } else {
            Text_AppendPaletteTag(self->text, 5);
        }
        int x2 = x + Font_GetTextWidth(str, 0);
        str = func_02072a68((TableA68*)self->texts, (short)(rank + 0x12c));
        func_02041a90(self->text, x2 + 2, 0x12);
        Text_Append(self->text, str);
        Text_AppendPaletteTag(self->text, 0xf);
    }

    func_02046380(win);
    func_020465c0((StoreStruct*)win, 0, scroll);
    func_020465d8((unsigned char*)win, 0, 0);
    func_020465f0((unsigned char*)win, 0, 3);
    MessageSystem_FormatText(win, 10, func_02072a68((TableA68*)self->texts, 0x1f6), buf80, 0x100, 0, 0);
    func_02041a90(self->text, (width >> 1) - 13, 0x1e);
    Text_Append(self->text, buf80);
    func_02041cf4(self->text, 0x7fff, 2, width - 2, 0x28);
    memset(buf80, 0, 0x80);
    MessageSystem_SetStringArgument((Obj02046574*)win, 0, func_02072a68((TableA68*)self->texts, (short)(self->e1c_title + 0x1f9)));
    func_020465c0((StoreStruct*)win, 2, self->unknown_e1e_0_);
    MessageSystem_FormatText(win, 10, func_02072a68((TableA68*)self->texts, 0x1f8), buf80, 0x100, 0, 0);
    func_02041a90(self->text, 12, 0x2a);
    Text_Append(self->text, buf80);
    Window_OpenPane(self->list, self->text, 0, 0, 0, 1, 0, 0);
    self->link->unknown_115_ = (signed char)level;
    self->link->unknown_13d_ = (signed char)level;
}
#endif
