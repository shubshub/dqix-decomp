#include <globaldefs.h>

struct Canvas_021df558 {
    char data[0xe0];
};

struct Struct_ov023_021df558_5 {
    char pad0[0x16];
    unsigned char flags_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021df558 {
    int unk_0;
    Canvas_021df558* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
    char unknown_14_[0x48 - 0x14];
    short unknown_48_;
    short unknown_4a_;
};

struct Struct_ov023_021df558_3 {
    void* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int type_ : 5;
    unsigned int unknown_9_1_ : 3;
    unsigned int unknown_9_4_ : 6;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    unsigned int unk_c;
    unsigned int unk_10;
    int unk_14;
    short unknown_18_;
    unsigned short unknown_1a_;
    char unk_1c[0x20 - 0x1c];
};

struct Struct_ov023_021df558_4 {
    char pad0[0x4c];
    Struct_ov023_021df558_3* item_;
    char unknown_50_[0xcc - 0x50];
    Struct_ov023_021df558 layout_;
#if defined(jpn)
    char unknown1_118_[0x62c - 0x118];
    char description_[0x6d8 - 0x62c];
#else
    char unknown_118_[0x630 - 0x118];
    char description_[0x75c - 0x630];
#endif

    unsigned int unknown_75c_;
};

struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0_13 {
#if defined(jpn)
    void* sTexts;
    int unknown_4_;
    int unknown1_18_;
    int unknown_c_;
    void* sFieldNames;
    void* unknown1_4_;
    void* unknown_18_;
#else
    void* unknown1_0_;
    void* unknown1_4_;
    void* sFieldNames;
    int unknown1_c_;
    int unknown1_10_;
    void* sTexts;
    int unknown1_18_;
#endif

};
extern "C" Struct_ov023_021ff9e0_13 data_ov023_021ff9e0;

extern "C" void WindowPane_Init(Canvas_021df558* canvas);
extern "C" int func_ov023_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void* messages, int, const char* input, char* output, int, int, int);
extern "C" Struct_ov023_021df558_5* func_ov023_021db4e4(Struct_ov023_021df558* layout, int id);
extern "C" void func_ov023_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char arg4);
extern "C" void func_ov023_021db45c(void* layout, struct Struct_ov023_021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Struct_ov023_021df558* layout);
extern "C" void func_ov023_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021df558* canvas, unsigned int offset, unsigned short palette, int arg3);
extern "C" unsigned short func_020de194(void* item);
extern "C" void func_ov023_021e24b0(void* layout, int id, int value, unsigned char color, unsigned char arg4,
                              unsigned char unk4, unsigned char digits, unsigned char arg7, unsigned char arg8);

#define SHOW_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021df558_5* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ |= 1;                                          \
    }

#define HIDE_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021df558_5* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ &= ~1;                                         \
    }

static inline int inline_ov023_021df558(const Struct_ov023_021df558_3* item)
{
    return item->category_ <= 7 ? 1 : 0;
}

// USA: func_ov023_021df558
extern "C" ARM void func_ov023_021df558(Struct_ov023_021df558_4* self)
{
    Canvas_021df558 canvas;
    WindowPane_Init(&canvas);
    if (func_ov023_021ddc34(&canvas, 0, 0, 0xe, 8))
    {
        Struct_ov023_021df558_3* item = self->item_;
        if (item != NULL)
        {
            short group = 0x14;
            short text = 4;
            if (inline_ov023_021df558(item))
            {
                group = 0x1c;
                text = 7;
            }
#if defined(jpn)
            func_ov023_021e23d0(&self->layout_, text, (int)self->description_, 12, 15);
#else
            char formatted[0x100] = {0};
            MessageSystem_FormatText(MessageSystem_GetInstance(), 10, self->description_, formatted, 0x68, 0, 0);
            func_ov023_021e23d0(&self->layout_, text, (int)formatted, 10, 15);
#endif

            SHOW_ELEMENT(&self->layout_, group);
            short y;
            short x;
            func_ov023_021db45c(&self->layout_, (Struct_ov023_021db45c*)&canvas, group, &x, &y);
            if (data_ov023_021ff9e0.unknown1_4_ != NULL)
            {
                self->layout_.canvas_ = &canvas;
                self->layout_.unk_12 = 1;
#if defined(jpn)

#else
                self->layout_.unknown_48_ = 0xe;
#endif

                func_ov023_021e257c(&self->layout_);
            }
            func_ov023_021db544(&self->layout_, (void*)group, x, y);
            HIDE_ELEMENT(&self->layout_, group);
        }
        self->unknown_75c_ += func_ov023_021ddc98(&canvas, self->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
    if (inline_ov023_021df558(self->item_))
        return;
    if (func_ov023_021ddc34(&canvas, 0, 0, 8, 2))
    {
        Struct_ov023_021df558_3* item = self->item_;
        SHOW_ELEMENT(&self->layout_, 0x10);
        if (item->category_ == 9 || func_020de194(item) == 0)
        {
            HIDE_ELEMENT(&self->layout_, 5);
            HIDE_ELEMENT(&self->layout_, 0x17);
            SHOW_ELEMENT(&self->layout_, 0x19);
        }
        else
        {
            func_ov023_021e24b0(&self->layout_, 5, func_020de194(item), 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&self->layout_, 5);
            SHOW_ELEMENT(&self->layout_, 0x17);
            HIDE_ELEMENT(&self->layout_, 0x19);
        }
        short y;
        short x;
        func_ov023_021db45c(&self->layout_, (Struct_ov023_021db45c*)&canvas, 0x10, &x, &y);
        if (data_ov023_021ff9e0.unknown1_4_ != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        func_ov023_021db544(&self->layout_, (void*)0x10, x, y);
        HIDE_ELEMENT(&self->layout_, 0x10);
        self->unknown_75c_ += func_ov023_021ddc98(&canvas, self->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
    if (func_ov023_021ddc34(&canvas, 0, 0, 8, 2))
    {
        Struct_ov023_021df558_3* item = self->item_;
        SHOW_ELEMENT(&self->layout_, 0x12);
        unsigned short var11;
        if (item->category_ == 9 || (var11 = item->unknown_1a_) == 0)
        {
            HIDE_ELEMENT(&self->layout_, 6);
            HIDE_ELEMENT(&self->layout_, 0x18);
            SHOW_ELEMENT(&self->layout_, 0x1a);
        }
        else
        {
            func_ov023_021e24b0(&self->layout_, 6, var11, 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&self->layout_, 6);
            SHOW_ELEMENT(&self->layout_, 0x18);
            HIDE_ELEMENT(&self->layout_, 0x1a);
        }
        short y;
        short x;
        func_ov023_021db45c(&self->layout_, (Struct_ov023_021db45c*)&canvas, 0x12, &x, &y);
        if (data_ov023_021ff9e0.unknown1_4_ != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        func_ov023_021db544(&self->layout_, (void*)0x12, x, y);
        HIDE_ELEMENT(&self->layout_, 0x12);
        self->unknown_75c_ += func_ov023_021ddc98(&canvas, self->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
}
