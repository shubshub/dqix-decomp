#include <globaldefs.h>

struct Container020e0310;
struct Struct0205de24;
struct BackgroundGraphics;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
extern "C" void memset(void* dst, int val, int size);
extern "C" void func_ov003_0215e13c(char* base, char* dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* window, char* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_ov003_0215df1c {
#if defined(jpn)
    char unk_0[0x64 + 0x18];
#else
    char unk_0[0x64];
#endif
    char messages[0x7c - 0x64];
    char* text;
    char unknown_80_[0x98 - 0x80];
    char window[0x138 - 0x98];
    short width;
    short height;
    short x;
    short y;
    short unknown_140_;
    short unknown_142_;
    short unknown_144_;
    short unknown_146_;
    char unknown_148_;
    unsigned char unknown_149_;
    char unknown_14a_[3];
    unsigned char unknown_14d_;
    char unknown_14e_;
    unsigned char unknown_14f_;
    char unknown_150_[4];
    char scrollers[2][0x20];
    char unknown_194_[0x3bd - 0x194];
    unsigned char keys[3];
    unsigned char count;
    signed char cursor;
    char unknown_3c2_[0x3d0 - 0x3c2];
    int unknown_3d0_;
    char unknown_3d4_[0x3f2 - 0x3d4];
    unsigned char unknown_3f2_;
};

// USA: func_ov003_0215df1c
extern "C" ARM void func_ov003_0215df1c(struct Struct_ov003_0215df1c* self) {
    void* ctx = LinkSession_GetInstance();
    self->count = 3;
    self->keys[0] = 0;
    self->keys[1] = 1;
    self->keys[2] = 2;
    if (LinkSession_IsGuest(ctx)) {
        self->count = 2;
        self->keys[0] = 1;
        self->keys[1] = 2;
        self->keys[2] = 0xff;
    } else if (self->unknown_3d0_ == 0) {
        self->count = 2;
        self->keys[0] = 0;
        self->keys[1] = 2;
        self->keys[2] = 0xff;
    }

    short height = (self->count * 14 + 0x12) / 8;
#if defined(jpn)
    short width = 7;
#else
    int var2 = 0;
    for (int i = 0; i < self->count; i++) {
        short w = Font_GetTextWidth((char*)KeyTable_Get((struct Container020e0310*)self->messages, self->keys[i]), 0);
        if (var2 < w) {
            var2 = w;
        }
    }
    short width = (var2 + 0x18) >> 3;
#endif

    func_0205de24((struct Struct0205de24*)self->window, 0, 2);
    self->width = width;
    self->height = height;
    self->x = 0x1f - width;
    self->y = 2;
    self->unknown_140_ = 0xc;
    self->unknown_142_ = 8;
    self->unknown_144_ = 0xa;
    self->unknown_146_ = 0xe;
    self->unknown_14f_ = 0xa;
    self->unknown_149_ = 1;
    self->unknown_14d_ = 1;

    if (self->unknown_3f2_) {
#if defined(jpn)
        short pos = *(short*)(MessageSystem_GetInstance() + 0x7e6);
#else
        short pos = *(short*)(MessageSystem_GetInstance() + 0x916);
#endif
        short row = pos / 8;
        short offset = pos % 8;
        self->x = 0x20 - width;
        self->y = row - height;
        for (int i = 0; i < 2; i++) {
            Background_SetScroll((struct BackgroundGraphics*)self->scrollers[i], 2, -offset);
        }
    }

    self->cursor = 0;
#if defined(jpn)
    memset(self->text, 0, 0x800);
#else
    memset(self->text, 0, 0x960);
#endif
    func_ov003_0215e13c((char*)self, self->text, 0);
#if defined(jpn)
    Window_OpenPane(self->window, self->text, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(self->window, self->text, 0, 1, 0, 1, 0, 0);
#endif
}
