#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
#if defined(jpn)
#define func_ov013_02185e40 func_ov013_02186f4c
extern "C" void Window_OpenPane(void*, char*, int, int, int, int, void*);
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,NULL)
enum { Enum_ov013_02185cc0_56=0x34, Enum_ov013_02185cc0_1600=0x5cc, Enum_ov013_02185cc0_1620=0x5dc, textSize=0x800 };
#else
extern "C" void Window_OpenPane(void* window, char* text, int c, int d, int e, int f, void* g, int h);
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,NULL,0)
enum { Enum_ov013_02185cc0_56=0x38, Enum_ov013_02185cc0_1600=0x640, Enum_ov013_02185cc0_1620=0x654, textSize=0x960 };
#endif
extern "C" void func_ov013_02185e40(void* self, char* text);

struct Struct_ov013_02185cc0_3 {
    char unk_0[8];
    unsigned short* unk_8;
};
extern "C" Struct_ov013_02185cc0_3* func_ov013_02184338(void* renderer, unsigned int index);
extern "C" void* func_020421b0(int index);
void CleanInvalidateCacheRange(const void* start, unsigned int size);
void CleanCacheRange(const void* start, unsigned int size);
extern "C" void LoadToSubObjVRAM(const void* src, unsigned int offset, unsigned int size);
extern "C" void LoadToMainObjVRAM(const void* src, unsigned int offset, unsigned int size);

extern const int data_ov013_02187d9c[2];
extern const int data_ov013_02187da4[2];

struct Struct_ov013_02185cc0 {
    char unk_0[0xa0];
    short width_;
    short height_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unk_ac;
    short unknown_ae_;
    unsigned char unk_b0;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
};

struct Struct_ov013_02185cc0_2 {
    char unk_0[0x18];
    void* spriteRenderer_;
    char unk_1c[Enum_ov013_02185cc0_56 - 0x1c];
    Struct_ov013_02185cc0 window_;
    char unk_ee[Enum_ov013_02185cc0_1600 - Enum_ov013_02185cc0_56 - sizeof(Struct_ov013_02185cc0)];
    bool subScreen_;
    char unknown_641_[Enum_ov013_02185cc0_1620 - Enum_ov013_02185cc0_1600 - 1];
    void* canvasPixels_;
    char* text_;
    char unknown_65c_[0x6a8 - 0x65c];
    unsigned char vocation_;
};

// USA: func_ov013_02185cc0
extern "C" ARM void func_ov013_02185cc0(Struct_ov013_02185cc0_2* self) {
    bool subScreen;
    void* renderer;
    void* pixels;
    unsigned char vocation;
    func_0205de24((struct Struct0205de24*)&self->window_, 0, 2);
    self->window_.width_ = 0xf;
    self->window_.height_ = 0xb;
    self->window_.unknown_a4_ = 1;
    self->window_.unknown_a6_ = 0xd;
    self->window_.unknown_a8_ = 6;
    self->window_.unknown_aa_ = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unknown_ae_ = 0xd;
    self->window_.unknown_b1_ = 4;
#if defined(jpn)
    if (self->subScreen_) {
        self->window_.unknown_b5_ = 0;
    } else {
        self->window_.unknown_b5_ = 1;
    }
#else
    self->window_.unknown_b5_ = self->subScreen_ ? 0 : 1;
#endif
    memset(self->text_, 0, textSize);
    func_ov013_02185e40(self, self->text_);
    DRAW_TEXT(&self->window_, self->text_);
#if !defined(jpn)
    renderer = self->spriteRenderer_;
    pixels = self->canvasPixels_;
    vocation = self->vocation_;
    subScreen = self->subScreen_;
    if (renderer != NULL && pixels != NULL)
    {
        const int* icon = data_ov013_02187da4;
        if (subScreen)
            icon = data_ov013_02187d9c;
        Struct_ov013_02185cc0_3* sprite = func_ov013_02184338(renderer, (unsigned short)icon[0]);
        unsigned short* oam;
        if (sprite != NULL && (oam = sprite->unk_8) != NULL)
        {
            memcpy(pixels, func_020421b0((unsigned char)(vocation * 4 + 0x28)), 0x80);
            unsigned int offset = (unsigned short)(oam[2] & 0x3ff) << icon[1];
            CleanInvalidateCacheRange(pixels, 0x80);
            if (subScreen)
                LoadToSubObjVRAM(pixels, offset, 0x80);
            else
                LoadToMainObjVRAM(pixels, offset, 0x80);
            CleanCacheRange(pixels, 0x80);
        }
    }
#endif
}
