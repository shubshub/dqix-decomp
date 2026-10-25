#include <globaldefs.h>

struct Struct_ov023_021e0f44_2 {
    char unknown_0_[0xe0];
};

struct Struct_ov023_021e0f44_4 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021e0f44 {
    int unknown_0_;
    Struct_ov023_021e0f44_2* unknown_4_;
    char unknown_8_[0x12 - 8];
    short unknown_12_;
    char unknown_14_[0x4c - 0x14];
};

struct Struct_ov023_021e0f44_3 {
    char unknown_0_[0xbc];
    short unknown_bc_[3];
    short unknown_c2_;
    char unknown_c4_[0xcc - 0xc4];
    Struct_ov023_021e0f44 unknown_cc_;
#if defined(jpn)
    char unknown_118_[0x6d8 - 0x118];
#else
    char unknown1_118_[0x75c - 0x118];
#endif

    unsigned int unknown_75c_;
    char unknown_760_[0x774 - 0x760];
    unsigned short unknown_774_;
};

struct Struct_0201099c_3;
struct Struct_ov023_021db45c;

struct Struct_ov023_021ff9e0_15 {
#if defined(jpn)
    struct Struct_0201099c_3* unknown_14_;
    char unknown1_4_[8];
    int unknown_c_;
    int unknown1_10_;
    void* unknown_4_;
    int unknown1_18_;
    Struct_ov023_021e0f44_3* unknown_20_;
    char unknown1_20_[8];
    struct Struct_0201099c_3* unknown_28_;

#else
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    struct Struct_0201099c_3* unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    Struct_ov023_021e0f44_3* unknown_20_;
    void* unknown_24_;
    struct Struct_0201099c_3* unknown_28_;

#endif
};
extern "C" Struct_ov023_021ff9e0_15 data_ov023_021ff9e0;
extern "C" const short data_ov023_021fd5a8[2] __attribute__((aligned(4)));

extern "C" void WindowPane_Init(Canvas_021e0f44* canvas);
int InitBufferFromDataField4_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" LayoutElement_021e0f44* func_ov023_021db4e4(Layout_021e0f44* layout, int id);
void SetEntryFields_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char shadow);
void CopyTextAndUppercaseIfFlagged0206819c(const char* input, char* output, int flag);
void UpdateEntryAndReset_021db45c(void* layout, struct StructAcAe021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Layout_021e0f44* layout);
void CreateAndSetFields8A_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021e0f44* canvas, unsigned int offset, unsigned short palette, int bg1);

#define SHOW_ELEMENT(layout, id)                                         \
    {                                                                    \
        Struct_ov023_021e0f44_4* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->unknown_16_ |= 1;                                        \
    }

#define HIDE_ELEMENT(layout, id)                                         \
    {                                                                    \
        Struct_ov023_021e0f44_4* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->unknown_16_ &= ~1;                                       \
    }

// USA: func_ov023_021e0f44
extern "C" ARM void func_ov023_021e0f44(Struct_ov023_021e0f44_3* arg0)
{
    Canvas_021e0f44 canvas;
    WindowPane_Init(&canvas);
    if (!InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 0x1c, 3))
        return;
    if (!(arg0->unknown_774_ & 0x400))
    {
#if defined(jpn)

#else
        char var1[2][0x80] = {0};
#endif

        const char* found = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1f);
        const char* none = KeyTable_Get(data_ov023_021ff9e0.sTexts, 0x1e);
        SHOW_ELEMENT(&self->layout_, 0xe);
        SHOW_ELEMENT(&self->layout_, 0xd);
        SetEntryFields_021e23d0(&self->layout_, 0xb, (int)found, 10, 15);
        SetEntryFields_021e23d0(&self->layout_, 0xc, (int)found, 10, 15);
        SetEntryFields_021e23d0(&self->layout_, 0xd, (int)none, 10, 15);
        int i = 0;
        short count = data_ov023_021ff9e0.sWindow->numMonsters_;
        for (; i < count; i++)
        {
            if (var4 >= 2)
                break;
            const char* name = KeyTable_Get(data_ov023_021ff9e0.sMonsterNames, data_ov023_021ff9e0.sWindow->monsters_[i]);
            if (name != NULL)
            {
#if defined(jpn)
                func_ov023_021e23d0(&arg0->unknown_cc_, data_ov023_021fd5a8[var4], (int)var6, 10, 15);
#else
                func_0206819c(var6, var1[var4], 0);
                func_ov023_021e23d0(&arg0->unknown_cc_, data_ov023_021fd5a8[var4], (int)var1[var4], 10, 15);
#endif

            }
        }
        if (var5 != 3)
            HIDE_ELEMENT(&arg0->unknown_cc_, 0xd);
        short var7;
        short var8;
        func_ov023_021db45c(&arg0->unknown_cc_, (Struct_ov023_021db45c*)&var0, 0xe, &var8, &var7);
        if (data_ov023_021ff9e0.unknown_4_ != NULL)
        {
            arg0->unknown_cc_.unknown_4_ = &var0;
            arg0->unknown_cc_.unknown_12_ = 1;
            func_ov023_021e257c(&arg0->unknown_cc_);
        }
        func_ov023_021db544(&arg0->unknown_cc_, (void*)0xe, var8, var7);
        HIDE_ELEMENT(&arg0->unknown_cc_, 0xe);
    }
    arg0->unknown_75c_ += func_ov023_021ddc98(&var0, arg0->unknown_75c_, data_ov023_021ff9e0.unknown_c_, 0);
}
