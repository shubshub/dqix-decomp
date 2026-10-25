#include <globaldefs.h>

struct Struct_ov023_021df558_2 {
    char unknown_0_[0xe0];
};

struct Struct_ov023_021df558_5 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021df558 {
    int unknown_0_;
    Struct_ov023_021df558_2* unknown_4_;
    char unknown_8_[0x12 - 8];
    short unknown_12_;
    char unknown_14_[0x48 - 0x14];
    short unknown_48_;
    short unknown_4a_;
};

struct Struct_ov023_021df558_3 {
    void* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 3;
    unsigned int unknown_9_4_ : 6;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    int unknown_14_;
    short unknown_18_;
    unsigned short unknown_1a_;
    char unknown_1c_[0x20 - 0x1c];
};

struct Struct_ov023_021df558_4 {
    char unknown_0_[0x4c];
    Struct_ov023_021df558_3* unknown_4c_;
    char unknown_50_[0xcc - 0x50];
    Struct_ov023_021df558 unknown_cc_;
#if defined(jpn)
    char unknown1_118_[0x62c - 0x118];
    char unknown_62c_[0x6d8 - 0x62c];
#else
    char unknown_118_[0x630 - 0x118];
    char unknown_630_[0x75c - 0x630];
#endif

    unsigned int unknown_75c_;
};

struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0_13 {
#if defined(jpn)
    void* unknown_0_;
    int unknown_4_;
    int unknown1_18_;
    int unknown_c_;
    void* unknown_10_;
    void* unknown1_4_;
    void* unknown_18_;
#else
    void* unknown1_0_;
    void* unknown1_4_;
    void* unknown_8_;
    int unknown1_c_;
    int unknown1_10_;
    void* unknown_14_;
    int unknown1_18_;
#endif

};
extern "C" Struct_ov023_021ff9e0_13 data_ov023_021ff9e0;

extern "C" void WindowPane_Init(Canvas_021df558* canvas);
int InitBufferFromDataField4_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void* messages, int, const char* input, char* output, int, int, int);
extern "C" LayoutElement_021df558* func_ov023_021db4e4(Layout_021df558* layout, int id);
void SetEntryFields_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char shadow);
void UpdateEntryAndReset_021db45c(void* layout, struct StructAcAe021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Layout_021df558* layout);
void CreateAndSetFields8A_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021df558* canvas, unsigned int offset, unsigned short palette, int bg1);
unsigned short EvalOrDispatch020de194(void* item);
void SetPackedFields_021e24b0(void* layout, int id, int value, unsigned char color, unsigned char shadow,
                              unsigned char unk4, unsigned char digits, unsigned char unk5, unsigned char unk6);

#define SHOW_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021df558_5* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->unknown_16_ |= 1;                                          \
    }

#define HIDE_ELEMENT(layout, id)                                           \
    {                                                                      \
        Struct_ov023_021df558_5* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->unknown_16_ &= ~1;                                         \
    }

static inline int inline_ov023_021df558(const Struct_ov023_021df558_3* arg0)
{
    return arg0->unknown_8_0_ <= 7 ? 1 : 0;
}

// USA: func_ov023_021df558
extern "C" ARM void func_ov023_021df558(Struct_ov023_021df558_4* arg0)
{
    Canvas_021df558 canvas;
    WindowPane_Init(&canvas);
    if (InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 0xe, 8))
    {
        Struct_ov023_021df558_3* var1 = arg0->unknown_4c_;
        if (var1 != NULL)
        {
            short var2 = 0x14;
            short var3 = 4;
            if (inline_ov023_021df558(var1))
            {
                var2 = 0x1c;
                var3 = 7;
            }
#if defined(jpn)
            func_ov023_021e23d0(&arg0->unknown_cc_, var3, (int)arg0->unknown_62c_, 12, 15);
#else
            char formatted[0x100] = {0};
            MessageSystem_FormatText(MessageSystem_GetInstance(), 10, self->description_, formatted, 0x68, 0, 0);
            SetEntryFields_021e23d0(&self->layout_, text, (int)formatted, 10, 15);
#endif

            SHOW_ELEMENT(&arg0->unknown_cc_, var2);
            short var5;
            short var6;
            func_ov023_021db45c(&arg0->unknown_cc_, (Struct_ov023_021db45c*)&var0, var2, &var6, &var5);
            if (data_ov023_021ff9e0.unknown1_4_ != NULL)
            {
                arg0->unknown_cc_.unknown_4_ = &var0;
                arg0->unknown_cc_.unknown_12_ = 1;
#if defined(jpn)

#else
                arg0->unknown_cc_.unknown_48_ = 0xe;
#endif

                func_ov023_021e257c(&arg0->unknown_cc_);
            }
            func_ov023_021db544(&arg0->unknown_cc_, (void*)var2, var6, var5);
            HIDE_ELEMENT(&arg0->unknown_cc_, var2);
        }
        arg0->unknown_75c_ += func_ov023_021ddc98(&var0, arg0->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
    if (inline_ov023_021df558(arg0->unknown_4c_))
        return;
    if (func_ov023_021ddc34(&var0, 0, 0, 8, 2))
    {
        Struct_ov023_021df558_3* var7 = arg0->unknown_4c_;
        SHOW_ELEMENT(&arg0->unknown_cc_, 0x10);
        if (var7->unknown_8_0_ == 9 || func_020de194(var7) == 0)
        {
            HIDE_ELEMENT(&arg0->unknown_cc_, 5);
            HIDE_ELEMENT(&arg0->unknown_cc_, 0x17);
            SHOW_ELEMENT(&arg0->unknown_cc_, 0x19);
        }
        else
        {
            func_ov023_021e24b0(&arg0->unknown_cc_, 5, func_020de194(var7), 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&arg0->unknown_cc_, 5);
            SHOW_ELEMENT(&arg0->unknown_cc_, 0x17);
            HIDE_ELEMENT(&arg0->unknown_cc_, 0x19);
        }
        short var8;
        short var9;
        func_ov023_021db45c(&arg0->unknown_cc_, (Struct_ov023_021db45c*)&var0, 0x10, &var9, &var8);
        if (data_ov023_021ff9e0.unknown1_4_ != NULL)
        {
            arg0->unknown_cc_.unknown_4_ = &var0;
            arg0->unknown_cc_.unknown_12_ = 1;
            func_ov023_021e257c(&arg0->unknown_cc_);
        }
        func_ov023_021db544(&arg0->unknown_cc_, (void*)0x10, var9, var8);
        HIDE_ELEMENT(&arg0->unknown_cc_, 0x10);
        arg0->unknown_75c_ += func_ov023_021ddc98(&var0, arg0->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
    if (func_ov023_021ddc34(&var0, 0, 0, 8, 2))
    {
        Struct_ov023_021df558_3* var10 = arg0->unknown_4c_;
        SHOW_ELEMENT(&arg0->unknown_cc_, 0x12);
        unsigned short var11;
        if (var10->unknown_8_0_ == 9 || (var11 = var10->unknown_1a_) == 0)
        {
            HIDE_ELEMENT(&arg0->unknown_cc_, 6);
            HIDE_ELEMENT(&arg0->unknown_cc_, 0x18);
            SHOW_ELEMENT(&arg0->unknown_cc_, 0x1a);
        }
        else
        {
            func_ov023_021e24b0(&arg0->unknown_cc_, 6, var11, 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&arg0->unknown_cc_, 6);
            SHOW_ELEMENT(&arg0->unknown_cc_, 0x18);
            HIDE_ELEMENT(&arg0->unknown_cc_, 0x1a);
        }
        short var12;
        short var13;
        func_ov023_021db45c(&arg0->unknown_cc_, (Struct_ov023_021db45c*)&var0, 0x12, &var13, &var12);
        if (data_ov023_021ff9e0.unknown1_4_ != NULL)
        {
            arg0->unknown_cc_.unknown_4_ = &var0;
            arg0->unknown_cc_.unknown_12_ = 1;
            func_ov023_021e257c(&arg0->unknown_cc_);
        }
        func_ov023_021db544(&arg0->unknown_cc_, (void*)0x12, var13, var12);
        HIDE_ELEMENT(&arg0->unknown_cc_, 0x12);
        arg0->unknown_75c_ += func_ov023_021ddc98(&var0, arg0->unknown_75c_, data_ov023_021ff9e0.unknown1_18_, 0);
    }
}
