#include <globaldefs.h>

struct Canvas_021e0f44 {
    char data[0xe0];
};

struct Struct_ov023_021e0f44_4 {
    char pad0[0x16];
    unsigned char flags_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021e0f44 {
    int unk_0;
    Canvas_021e0f44* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
    char unknown_14_[0x4c - 0x14];
};

struct Struct_ov023_021e0f44_3 {
    char pad0[0xbc];
    short monsters_[3];
    short unknown_c2_;
    char unknown_c4_[0xcc - 0xc4];
    Struct_ov023_021e0f44 layout_;
#if defined(jpn)
    char unknown_118_[0x6d8 - 0x118];
#else
    char unknown1_118_[0x75c - 0x118];
#endif

    unsigned int unknown_75c_;
    char unknown_760_[0x774 - 0x760];
    unsigned short flags_;
};

struct Container020e0310;
struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0_15 {
#if defined(jpn)
    struct Container020e0310* sTexts;
    char pad4[8];
    int unknown_c_;
    int pad10;
    void* unknown_4_;
    int pad18;
    Struct_ov023_021e0f44_3* sWindow;
    char pad20[8];
    struct Container020e0310* sMonsterNames;

#else
    void* unknown_0_;
    void* unknown_4_;
    void* sFieldNames;
    int unknown_c_;
    int unknown_10_;
    struct Container020e0310* sTexts;
    int unknown_18_;
    int unknown_1c_;
    Struct_ov023_021e0f44_3* sWindow;
    void* unknown_24_;
    struct Container020e0310* sMonsterNames;

#endif
};
extern "C" Struct_ov023_021ff9e0_15 data_ov023_021ff9e0;
extern "C" const short data_ov023_021fd5a8[2] __attribute__((aligned(4)));

extern "C" void WindowPane_Init(Canvas_021e0f44* canvas);
extern "C" int func_ov023_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" Struct_ov023_021e0f44_4* func_ov023_021db4e4(Struct_ov023_021e0f44* layout, int id);
extern "C" void func_ov023_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char arg4);
extern "C" void func_0206819c(const char* input, char* output, int flag);
extern "C" void func_ov023_021db45c(void* layout, struct Struct_ov023_021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Struct_ov023_021e0f44* layout);
extern "C" void func_ov023_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021e0f44* canvas, unsigned int offset, unsigned short palette, int arg3);

#define SHOW_ELEMENT(layout, id)                                         \
    {                                                                    \
        Struct_ov023_021e0f44_4* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->flags_ |= 1;                                        \
    }

#define HIDE_ELEMENT(layout, id)                                         \
    {                                                                    \
        Struct_ov023_021e0f44_4* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->flags_ &= ~1;                                       \
    }

// USA: func_ov023_021e0f44
extern "C" ARM void func_ov023_021e0f44(Struct_ov023_021e0f44_3* self)
{
    Canvas_021e0f44 canvas;
    WindowPane_Init(&canvas);
    if (!func_ov023_021ddc34(&canvas, 0, 0, 0x1c, 3))
        return;
    if (!(self->flags_ & 0x400))
    {
#if defined(jpn)

#else
        char names[2][0x80] = {0};
#endif

        const char* found = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1f);
        const char* none = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1e);
        SHOW_ELEMENT(&self->layout_, 0xe);
        SHOW_ELEMENT(&self->layout_, 0xd);
        func_ov023_021e23d0(&self->layout_, 0xb, (int)found, 10, 15);
        func_ov023_021e23d0(&self->layout_, 0xc, (int)found, 10, 15);
        func_ov023_021e23d0(&self->layout_, 0xd, (int)none, 10, 15);
        int i = 0;
        short count = data_ov023_021ff9e0.sWindow->unknown_c2_;
        for (; i < count; i++)
        {
            if (i >= 2)
                break;
            const char* name = KeyTable_Get(data_ov023_021ff9e0.sMonsterNames, data_ov023_021ff9e0.sWindow->monsters_[i]);
            if (name != NULL)
            {
#if defined(jpn)
                func_ov023_021e23d0(&self->layout_, data_ov023_021fd5a8[i], (int)name, 10, 15);
#else
                func_0206819c(name, names[i], 0);
                func_ov023_021e23d0(&self->layout_, data_ov023_021fd5a8[i], (int)names[i], 10, 15);
#endif

            }
        }
        if (count != 3)
            HIDE_ELEMENT(&self->layout_, 0xd);
        short y;
        short x;
        func_ov023_021db45c(&self->layout_, (Struct_ov023_021db45c*)&canvas, 0xe, &x, &y);
        if (data_ov023_021ff9e0.unknown_4_ != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        func_ov023_021db544(&self->layout_, (void*)0xe, x, y);
        HIDE_ELEMENT(&self->layout_, 0xe);
    }
    self->unknown_75c_ += func_ov023_021ddc98(&canvas, self->unknown_75c_, data_ov023_021ff9e0.unknown_c_, 0);
}
