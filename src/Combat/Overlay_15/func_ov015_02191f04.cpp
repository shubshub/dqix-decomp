#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov015_02191f04 func_ov015_02192a48
#endif

struct IndexList_0202a9ac;

struct DebugMenu
{
    char unk_0[0x5c];
    short unknown_5c_;
    short unknown_5e_;
    short cursor_;
    char unknown_62_[0x80 - 0x62];
};

struct Struct_ov015_02190acc
{
    char unk_0[0x19c];
    unsigned char unknown_19c_;
    unsigned char unknown_19d_;
    unsigned char unknown_19e_;
    unsigned char unknown_19f_;
    unsigned char unknown_1a0_;
    char unknown_1a1_[0x2c4 - 0x1a1];
    DebugMenu menuList_;
    char unknown_344_[0x350 - 0x344];
    unsigned char unknown_350_;
};

extern "C" int func_ov015_02191284(DebugMenu* menu);
extern "C" void* DebugMenu_GetItem(IndexList_0202a9ac* menu, int index);
extern "C" void DebugMenuItem_SetText(void* item, const char* text);

extern char data_ov015_0219432e[];
extern char data_ov015_02194338[];
extern char data_ov015_02194342[];
extern char data_ov015_0219434b[];
extern char data_ov015_0219435a[];
extern char data_ov015_02194369[];
extern char data_ov015_02194378[];
extern char data_ov015_02194387[];
extern char data_ov015_02194396[];

#if defined(jpn)
extern char data_ov015_02194ec3[];
#endif

// USA: func_ov015_02191f04
extern "C" ARM void func_ov015_02191f04(Struct_ov015_02190acc* self)
{
    int index = func_ov015_02191284(&self->menuList_);
    void* item = DebugMenu_GetItem((IndexList_0202a9ac*)&self->menuList_, self->menuList_.cursor_);
    switch (index)
    {
    case 0:
    {
        self->unknown_19c_ = !self->unknown_19c_;
        if (self->unknown_19c_)
            DebugMenuItem_SetText(item, data_ov015_0219432e);
        else
            DebugMenuItem_SetText(item, data_ov015_02194338);
        break;
    }
    case 1:
        self->unknown_19d_ = self->unknown_19d_ == 0;
#if defined(jpn)
        if (self->unknown_19d_)
            DebugMenuItem_SetText(item, data_ov015_02194ec3);
        else
#endif
        DebugMenuItem_SetText(item, data_ov015_02194342);
        break;
    case 2:
    {
        self->unknown_19e_ = !self->unknown_19e_;
        if (self->unknown_19e_)
            DebugMenuItem_SetText(item, data_ov015_0219434b);
        else
            DebugMenuItem_SetText(item, data_ov015_0219435a);
        break;
    }
    case 3:
    {
        self->unknown_19f_ = !self->unknown_19f_;
        if (self->unknown_19f_)
            DebugMenuItem_SetText(item, data_ov015_02194369);
        else
            DebugMenuItem_SetText(item, data_ov015_02194378);
        break;
    }
    case 4:
    {
        self->unknown_1a0_ = !self->unknown_1a0_;
        if (self->unknown_1a0_)
            DebugMenuItem_SetText(item, data_ov015_02194387);
        else
            DebugMenuItem_SetText(item, data_ov015_02194396);
        break;
    }
    }
    self->unknown_350_ = 1;
}
