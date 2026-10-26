#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215b5c4_2400 = 0x800 };
#else
enum { Enum_ov003_0215b5c4_2400 = 0x960 };
#endif

#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#endif

struct Container020e0310;
struct Struct0205de24;

extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_ov003_0215b6f0(char* base, char* dst, int flag);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_ov003_0215b5c4 {
    char unk_0[0x64];
    char texts_[0x7c - 0x64];
    char* buffer_;
    char unknown_80_[0xf4 - 0x80];
    char window_[0x194 - 0xf4];
    short width_;
    short height_;
    short x_;
    short y_;
    short unknown_19c_;
    short unknown_19e_;
    short unknown_1a0_;
    short unknown_1a2_;
    char unknown_1a4_;
    unsigned char unknown_1a5_;
    char unknown_1a6_[3];
    unsigned char unknown_1a9_;
    char unknown_1aa_[0x584 - 0x1aa];
    unsigned char cursor_;
    char unknown_585_[0x589 - 0x585];
    unsigned char count_;
    signed char entries_[1];
};

// USA: func_ov003_0215b5c4
extern "C" ARM void func_ov003_0215b5c4(Struct_ov003_0215b5c4* self) {
    func_0205de24((struct Struct0205de24*)self->window_, 0, 2);
    short height = (self->count_ * 14 + 0x12) / 8;
#if defined(jpn)
    short width = 0xb;
#else
    int var1 = 0;
    for (int i = 0; i < self->count_; i++) {
        short w = Font_GetTextWidth(KeyTable_Get((struct Container020e0310*)self->texts_, self->entries_[i]), 0);
        if (var1 < w) {
            var1 = w;
        }
    }
    short width = (var1 + 0x18) >> 3;
#endif
    self->width_ = width;
    self->height_ = height;
    self->x_ = 0x1f - width;
    self->y_ = 2;
    self->unknown_19c_ = 0xc;
    self->unknown_19e_ = 8;
    self->unknown_1a0_ = 0xa;
    self->unknown_1a2_ = 0xe;
    self->unknown_1a5_ = 1;
    self->unknown_1a9_ = 1;
    self->cursor_ = 0;
    memset(self->buffer_, 0, Enum_ov003_0215b5c4_2400);
    func_ov003_0215b6f0((char*)self, self->buffer_, 0);
#if defined(jpn)
    Window_OpenPane(self->window_, self->buffer_, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(self->window_, self->buffer_, 0, 1, 0, 1, 0, 0);
#endif
}
