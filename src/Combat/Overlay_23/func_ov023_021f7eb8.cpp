#include <globaldefs.h>

struct Struct_ov023_021f7eb8_2 {
#if defined(jpn)
    char unk_0[0xb4];
    short fontHeight;
    short lineHeight;
    char unk_b8[0xe0 - 0xb8];
#else
    char unk_0[0xe0];
#endif

};

class Struct_ov023_021f7eb8 {
public:
    unsigned short type_;
    short id_;
    unsigned short unknown_8_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    Struct_ov023_021f7eb8* unknown_14_;
    Struct_ov023_021f7eb8* unknown_18_;
    int state_;

    virtual void inline_ov023_021f7eb8();
};

class Struct_ov023_021f7eb8_3 : public Struct_ov023_021f7eb8 {
public:
    Struct_ov023_021f7eb8_2 canvas_;
    unsigned short x_;
    unsigned short y_;
    short page_;
    short pages_;
    unsigned char frame_;
    char unknown_109_;
    unsigned char unknown_10a_;
    char unknown_10b_;
    unsigned short unknown_10c_;
    unsigned short unknown_10e_;
};

struct Glyph_021f7eb8 {
    int code;
    signed char width;
};

struct Struct_0204fbf8_2;

extern "C" void func_0204f160(unsigned char*, int, int);
extern "C" void func_0204f174(Struct_ov023_021f7eb8_2* canvas, short x, short y, short width, short height,
                              unsigned char frame, unsigned char a, unsigned char b, int);
extern "C" void func_0204fae8(Struct_ov023_021f7eb8_2* canvas);
extern "C" Glyph_021f7eb8* Font_FindCharacter(int, int);
extern "C" void func_0204f7e8(Struct_ov023_021f7eb8_2* canvas, short x, short y, int value, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int, int, int, int);
extern "C" void func_0204f41c(Struct_ov023_021f7eb8_2* canvas, short x, short y, const char* text, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int);
extern "C" void func_ov023_021f8240(Struct_ov023_021f7eb8_3* self, void* script);
extern "C" void func_0204fbf8(Struct_0204fbf8_2*);

extern const char data_ov023_021fd91c[];
#if defined(jpn)
extern "C" void func_02050cc0(Struct_ov023_021f7eb8_2*, short, short, int, unsigned char, unsigned char, unsigned short*, unsigned short*, int, int, int, int);
extern "C" void func_02050678(Struct_ov023_021f7eb8_2*, short, short, const char*, unsigned char, unsigned char, unsigned short*, unsigned short*);
#endif

// USA: func_ov023_021f7eb8
extern "C" ARM void func_ov023_021f7eb8(Struct_ov023_021f7eb8_3* self, void* script, int value, short x, short y,
                                        short width, short height, unsigned char frame, unsigned char a,
                                        unsigned char b) {
    func_0204f160((unsigned char*)&self->canvas_, value, self->id_);
    func_0204f174(&self->canvas_, x, y, width, height, frame, a, b, 0);
    if (self->flags_ & 4) {
        if (self->pages_ > 1)
            func_0204fae8(&self->canvas_);
#if defined(jpn)
        unsigned char color = self->unknown_10a_;
        self->canvas_.fontHeight = 8;
        self->canvas_.lineHeight = 9;
        width = (short)(width * 4) - 4;
        height = (short)(height * 8) - 12;
        unsigned short textWidth;
        unsigned short var2;
        func_02050cc0(&self->canvas_, (short)(width - 24), height, self->page_ + 1, 8, color, &textWidth, &var2, 1, 3, 0, 0);
        func_02050cc0(&self->canvas_, (short)(width + 8), height, self->pages_, 8, color, &textWidth, &var2, 0, 3, 0, 0);
        func_02050678(&self->canvas_, width, height, data_ov023_021fd91c, 8, color, &textWidth, &var2);

#else
        height = (short)(height * 8) - 13;
        unsigned char color;
        int var4 = 0;
        color = self->unknown_10a_;
        Glyph_021f7eb8* glyph = Font_FindCharacter((int)data_ov023_021fd91c, 0);
        if (glyph != NULL)
            var4 = glyph->width;
        unsigned short textWidth;
        unsigned short var7;
        short center = width * 4;
        func_0204f7e8(&self->canvas_, center - var4, height, self->page_ + 1, 8, color, &textWidth,
                      &var7, 1, 3, 0, 0);
        func_0204f7e8(&self->canvas_, center + var4 + 1, height, self->pages_, 8, color, &textWidth,
                      &var7, 0, 3, 0, 0);
        func_0204f41c(&self->canvas_, center - (var4 >> 1), height, data_ov023_021fd91c, 8, color,
                      &textWidth, &var7, 0);

#endif
    }
    func_ov023_021f8240(self, script);
    func_0204fbf8((Struct_0204fbf8_2*)&self->canvas_);
    self->x_ = x * 8;
    self->y_ = y * 8;
}
