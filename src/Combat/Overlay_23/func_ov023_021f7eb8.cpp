#include <globaldefs.h>

struct Struct_ov023_021f7eb8_2 {
#if defined(jpn)
    char unknown1_0_[0xb4];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
#else
    char unknown_0_[0xe0];
#endif

};

class Struct_ov023_021f7eb8 {
public:
    unsigned short unknown_4_;
    short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    const char* unknown_10_;
    Struct_ov023_021f7eb8* unknown_14_;
    Struct_ov023_021f7eb8* unknown_18_;
    int unknown_1c_;

    virtual void inline_ov023_021f7eb8();
};

class Struct_ov023_021f7eb8_3 : public Struct_ov023_021f7eb8 {
public:
    Struct_ov023_021f7eb8_2 unknown_20_;
    unsigned short unknown_100_;
    unsigned short unknown_102_;
    short unknown_104_;
    short unknown_106_;
    unsigned char unknown_108_;
    char unknown_109_;
    unsigned char unknown_10a_;
    char unknown_10b_;
    unsigned short unknown_10c_;
    unsigned short unknown_10e_;
};

struct Struct_ov023_021f7eb8_4 {
    int unknown_0_;
    signed char unknown_4_;
};

struct Struct_0204fbf8_2;

void SetField0xa0AndByte0xc4IfFlag0x1Clear_0204f160(unsigned char*, int, int);
extern "C" void func_0204f174(Canvas_021f7eb8* canvas, short x, short y, short width, short height,
                              unsigned char frame, unsigned char a, unsigned char b, int);
extern "C" void func_0204fae8(Canvas_021f7eb8* canvas);
Glyph_021f7eb8* Font_FindCharacter(int, int);
extern "C" void func_0204f7e8(Canvas_021f7eb8* canvas, short x, short y, int value, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int, int, int, int);
extern "C" void func_0204f41c(Canvas_021f7eb8* canvas, short x, short y, const char* text, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int);
extern "C" void func_ov023_021f8240(MenuCanvas_021f7eb8* self, void* script);
void InvokeHandlerAfterCacheFlush0204fbf8(Obj0204fbf8*);

extern const char data_ov023_021fd91c[];
#if defined(jpn)
extern "C" void func_02050cc0(Struct_ov023_021f7eb8_2*, short, short, int, unsigned char, unsigned char, unsigned short*, unsigned short*, int, int, int, int);
extern "C" void func_02050678(Struct_ov023_021f7eb8_2*, short, short, const char*, unsigned char, unsigned char, unsigned short*, unsigned short*);
#endif

// USA: func_ov023_021f7eb8
extern "C" ARM void func_ov023_021f7eb8(Struct_ov023_021f7eb8_3* arg0, void* arg1, int arg2, short arg3, short arg4,
                                        short arg5, short arg6, unsigned char arg7, unsigned char arg8,
                                        unsigned char arg9) {
    func_0204f160((unsigned char*)&arg0->unknown_20_, arg2, arg0->unknown_6_);
    func_0204f174(&arg0->unknown_20_, arg3, arg4, arg5, arg6, arg7, arg8, arg9, 0);
    if (arg0->unknown_c_ & 4) {
        if (arg0->unknown_106_ > 1)
            func_0204fae8(&arg0->unknown_20_);
#if defined(jpn)
        unsigned char var0 = arg0->unknown_10a_;
        arg0->unknown_20_.unknown_b4_ = 8;
        arg0->unknown_20_.unknown_b6_ = 9;
        arg5 = (short)(arg5 * 4) - 4;
        arg6 = (short)(arg6 * 8) - 12;
        unsigned short var1;
        unsigned short var2;
        func_02050cc0(&arg0->unknown_20_, (short)(arg5 - 24), arg6, arg0->unknown_104_ + 1, 8, var0, &var1, &var2, 1, 3, 0, 0);
        func_02050cc0(&arg0->unknown_20_, (short)(arg5 + 8), arg6, arg0->unknown_106_, 8, var0, &var1, &var2, 0, 3, 0, 0);
        func_02050678(&arg0->unknown_20_, arg5, arg6, data_ov023_021fd91c, 8, var0, &var1, &var2);

#else
        height = (short)(height * 8) - 13;
        unsigned char color;
        int separatorWidth = 0;
        color = self->color_;
        Glyph_021f7eb8* glyph = Font_FindCharacter((int)data_ov023_021fd91c, 0);
        if (glyph != NULL)
            separatorWidth = glyph->width;
        unsigned short textWidth;
        unsigned short textHeight;
        short center = width * 4;
        func_0204f7e8(&self->canvas_, center - separatorWidth, height, self->page_ + 1, 8, color, &textWidth,
                      &textHeight, 1, 3, 0, 0);
        func_0204f7e8(&self->canvas_, center + separatorWidth + 1, height, self->pages_, 8, color, &textWidth,
                      &textHeight, 0, 3, 0, 0);
        func_0204f41c(&self->canvas_, center - (separatorWidth >> 1), height, data_ov023_021fd91c, 8, color,
                      &textWidth, &textHeight, 0);

#endif
    }
    func_ov023_021f8240(arg0, arg1);
    func_0204fbf8((Struct_0204fbf8_2*)&arg0->unknown_20_);
    arg0->unknown_100_ = arg3 * 8;
    arg0->unknown_102_ = arg4 * 8;
}
