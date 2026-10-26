#include <globaldefs.h>

#if defined(jpn)
struct Struct_02066a6c_8 { char pad[0x1c]; };
struct Struct_02066a6c_9 { short x; short y; int field4; int mode; int fieldc; int scaleX; int scaleY; int field18; };
struct Struct_02066a6c { char pad[0x440]; Struct_02066a6c_9* transform; };
struct Struct_02066a6c_2;
struct Struct_02066a6c_5 {
    void* context;
    char pad4[0x7e0]; Struct_02066a6c_9 backup; Struct_02066a6c_9 active;
    char unknown_81c_[0x6c]; Struct_02066a6c_8 glyphs[128];
    char unknown_1688_[0xc4]; unsigned short font;
    char unknown_174e_[4]; unsigned short text[16];
    unsigned short length;
    char unknown_1774_[0x80]; unsigned char unknown_17f4_; unsigned char visible;
    char unknown_17f6_[0xe]; Struct_02066a6c holder;
};
extern "C" void func_0206b804(char*, int*, int*);
extern "C" void func_02066cc0(Struct_02066a6c_2*, short*, short*);
struct Struct_02042b98_3;
extern "C" void func_02042c24(Struct_02042b98_3*, int, int);
extern "C" void WindowFrame_Draw(void*, int, int);
extern "C" void func_020681b4(Struct_02066a6c_8*, int, int, short);
extern "C" void func_020417b0(Struct_02066a6c_8*, int, int, int);
extern "C" void func_02066934(Struct_02066a6c_5*, void*, Struct_02066a6c_8*, int, int, int);

extern "C" ARM void func_02066a6c(Struct_02066a6c_5* obj, int arg1) {
    if (!obj->visible) return;
    Struct_02066a6c* holder = &obj->holder;
    unsigned int count;
    unsigned short* text;
    unsigned char i;
    count = 0;
    text = NULL;
    if (obj->unknown_17f4_) {
        text = obj->text;
        count = obj->length & 255;
    }
    if (text) {
        int offsetX, offsetY;
        short x, y;
        func_0206b804((char*)obj, &offsetX, &offsetY);
        func_02066cc0((Struct_02066a6c_2*)holder, &x, &y);
        y -= 19;
        holder->transform = &obj->active;
        if (holder->transform) {
            holder->transform->scaleX = 4096;
            holder->transform->scaleY = 4096;
        }
        if (holder->transform) holder->transform->mode = 2;
        if (arg1) func_02042c24((Struct_02042b98_3*)holder, x, y);
        else {
            func_02042c24((Struct_02042b98_3*)holder, (short)(x + offsetX), (short)(y + offsetY));
            WindowFrame_Draw(holder, 1, 0);
        }
        short var8 = 8 - ((count * 10) & 7);
        x += (var8 + 18) >> 1;
        y += 5;
        for (i = 0; i < count; i++) {
            unsigned short code = text[i];
            if ((code & 0xff00) == 0xff00) {
                if (code == 0xff01) break;
                if (code == 0xff19) { x += 10; continue; }
                if (code == 0xff1a) { x += 10; continue; }
                if (code == 0xff1b) { x += 5; continue; }
                code &= 0x7f;
            }
            Struct_02066a6c_8* glyph = &obj->glyphs[code];
            if (arg1) func_02066934(obj, obj->context, glyph, x, y, 15);
            else {
                func_020681b4(glyph, x, y, 0);
                func_020417b0(glyph, obj->font, 0, 31);
            }
            x += 10;
        }
    }
    holder->transform = &obj->backup;
}
#else
struct Struct_02066a6c_3 { char pad[4]; signed char width; };
struct Struct_02066a6c_4 {
    char pad[12]; int x; int y; short mode; short reserved; Struct_02066a6c_3* unknown_18_;
};
struct Struct_02066a6c_6 { short x; short y; int field4; int mode; int fieldc; int scaleX; int scaleY; int field18; };
struct Struct_02042b98_3 { char pad[0x440]; Struct_02066a6c_6* transform; };
struct Struct_02066a6c_2;
struct Struct_02066a6c_7 {
    char pad0[0x34]; void* context;
    char unknown_38_[0x8dc]; Struct_02066a6c_6 backup; Struct_02066a6c_6 active;
    char unknown_94c_[0x6c]; Struct_02066a6c_4 glyphs[80];
    char unknown_1278_[0x604]; unsigned short font;
    char unknown_187e_[4]; unsigned short text[96];
    unsigned short length; short width;
    char unknown_1946_[0x7d]; unsigned char unknown_19c3_; unsigned char visible;
    char unknown_19c5_[0x17]; unsigned char table;
    char unknown_19dd_[3]; Struct_02042b98_3 holder;
};
extern "C" void func_0206b804(char*, int*, int*);
extern "C" void func_02066cc0(Struct_02066a6c_2*, short*, short*);
extern "C" void func_02042c24(Struct_02042b98_3*, int, int);
extern "C" void WindowFrame_Draw(void*, int, int);
extern "C" int Font_GetFallbackWidth(int);
extern "C" void func_02066ce0(Struct_02066a6c_4*, int, int, short);
extern "C" void func_020417b0(Struct_02066a6c_4*, int, int, int);
extern "C" void func_020654b8(Struct_02066a6c_7*, void*, Struct_02066a6c_4*, int, int, int);

// USA: func_02066a6c
extern "C" ARM void func_02066a6c(Struct_02066a6c_7* obj, int arg1) {
    if (!obj->visible) return;
    Struct_02042b98_3* holder = &obj->holder;
    int count;
    unsigned short* text;
    Struct_02066a6c_4* glyph;
    int i;
    int spacing;
    count = 0;
    text = NULL;
    if (obj->unknown_19c3_) {
        text = obj->text;
        count = obj->length & 255;
    }
    if (text) {
        int offsetX, offsetY;
        short x, y;
        func_0206b804((char*)obj, &offsetX, &offsetY);
        func_02066cc0((Struct_02066a6c_2*)holder, &x, &y);
        y -= 19;
        holder->transform = &obj->active;
        if (holder->transform) {
            holder->transform->scaleX = 4096;
            holder->transform->scaleY = 4096;
        }
        if (holder->transform) holder->transform->mode = 2;
        if (arg1) func_02042c24(holder, x, y);
        else {
            func_02042c24(holder, (short)(x + offsetX), (short)(y + offsetY));
            WindowFrame_Draw(holder, 1, 0);
        }
        short var21 = 8 - (obj->width & 7);
        x += (var21 + 18) >> 1;
        y += 5;
        unsigned char fontWidth = Font_GetFallbackWidth(obj->table);
        for (i = 0; i < count; i++) {
            spacing = fontWidth + 1;
            unsigned short code = text[i];
            if ((code & 0xff00) == 0xff00) {
                if (code == 0xff01) break;
                if (code == 0xff19) { x += spacing; continue; }
            }
            glyph = &obj->glyphs[code];
            if (arg1) func_020654b8(obj, obj->context, glyph, x, y, 15);
            else {
                func_02066ce0(glyph, x, y, 0);
                func_020417b0(glyph, obj->font, 0, 31);
            }
            if (glyph->unknown_18_) x += glyph->unknown_18_->width + 1;
        }
    }
    holder->transform = &obj->backup;
}
#endif
