#include <globaldefs.h>

#if defined(jpn)
#define func_ov015_0219050c func_ov015_021910b0
#define func_02069fec func_02069ecc
#define func_02045d14 func_020469b0
#define PrepareLineMode 8
#else
#define PrepareLineMode 0
#endif
#include <std_library_functions.h>
#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

extern "C" void __clear(void* buffer, unsigned long size);

struct MessageSystem0219050c
{
#if defined(jpn)
    char unk_0[0x17e0];
#else
    char unk_0[0x19b0];
#endif
    unsigned char unknown_19b0_;
};

struct Struct_ov015_0219050c
{
    char name[0x18];
    int unknown_18_;
};

struct IndexList_0202a9ac;
struct Struct_ov015_0218f3c4_2;
struct Struct_ov015_0218f408_2;

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x34];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    short motion_;
};

struct Struct_ov015_0219050c_2
{
    char unk_0[0x30];
    Struct_ov015_0218c03c_2* current_;
    char unknown_34_[0x194 - 0x34];
    int menu_;
    char unknown_198_[0x1a0 - 0x198];
    unsigned char unknown_1a0_;
    char unknown_1a1_[0x24c - 0x1a1];
    float unknown_24c_;
    char unknown_250_[0x2c4 - 0x250];
    char menuList_[0x80];
};

extern "C" MessageSystem0219050c* MessageSystem_GetInstance();
extern "C" void func_02069fec(MessageSystem0219050c* system, const char* text, char* converted);
#if defined(jpn)
extern "C" int func_02045d14(MessageSystem0219050c* system, const char* converted, unsigned short* line, int unk);
#else
extern "C" void func_02045d14(MessageSystem0219050c* system, const char* converted, unsigned short* line, int unk);
#endif
#if defined(jpn)
extern "C" void func_02046c78(MessageSystem0219050c* system, unsigned short* line, int x, int y, int color, int a, int b, int c);
#else
extern "C" void func_02045f3c(MessageSystem0219050c* system, unsigned short* line, int x, int y, int color, int a, int b, int c, int d, int e);
#endif
extern "C" void* DebugMenu_GetItem(IndexList_0202a9ac* list, int index);
extern "C" void* func_02029560(void* item);
extern "C" Struct_ov015_0219050c* func_ov015_0218f39c(Struct_ov015_0218c03c_2* self, void* name);
extern "C" float func_ov015_0218f3c4(Struct_ov015_0218f3c4_2* obj);
extern "C" float func_ov015_0218f408(Struct_ov015_0218f408_2* obj);
extern "C" void func_ov015_0218f794(Struct_ov015_0218c03c_2* self);

extern const char data_ov015_02194256[];
extern const char data_ov015_02194261[];
extern const char data_ov015_0219426a[];
extern const char data_ov015_02194273[];
extern const char data_ov015_0219427b[];
extern const char data_ov015_02194288[];
extern const char data_ov015_02194295[];

#define PREPARE_TEXT()                                                    \
    {                                                                     \
        memset(line, 0, sizeof(line));                                    \
        MessageSystem0219050c* system = MessageSystem_GetInstance();     \
        char converted[0x40] = {};                                        \
        func_02069fec(system, text, converted);                           \
        func_02045d14(system, converted, line, PrepareLineMode);          \
    }

#if defined(jpn)
#define DRAW_LINE(x, y, color)                                                     \
    {                                                                              \
        messages->unknown_19b0_ = 1;                                                    \
        func_02046c78(messages, &line[1], x, y, color, 8, 0x14, 0);                  \
    }
#else
#define DRAW_LINE(x, y, color)                                                     \
    {                                                                              \
        messages->unknown_19b0_ = 1;                                                    \
        func_02045f3c(messages, &line[1], x, y, color, 8, 0x14, 0, 1, 0x11);       \
    }
#endif

// USA: func_ov015_0219050c
extern "C" ARM void func_ov015_0219050c(Struct_ov015_0219050c_2* self)
{
    char text[0x20];
    unsigned short line[0x20];

    MessageSystem0219050c* messages = MessageSystem_GetInstance();
    sprintf(text, data_ov015_02194256, (double)(self->unknown_24c_));
    PREPARE_TEXT();
    DRAW_LINE(0, 0xa0, 0x7fff);
    unsigned short triangles = 0;
    if (self->current_ != NULL)
        triangles = self->current_->unknown_34_;
    sprintf(text, data_ov015_02194261, triangles);
    PREPARE_TEXT();
    DRAW_LINE(0, 0xaa, 0x7fff);
    unsigned short var4 = 0;
    if (self->current_ != NULL)
        var4 = self->current_->unknown_36_;
    sprintf(text, data_ov015_0219426a, var4);
    PREPARE_TEXT();
    messages->unknown_19b0_ = 1;
#if defined(jpn)
    if (var4 != 0)
        func_02046c78(messages, &line[1], 0, 0xb4, 0x1f, 8, 0x14, 0);
    else
        func_02046c78(messages, &line[1], 0, 0xb4, 0x7fff, 8, 0x14, 0);
#else
    if (var4 != 0)
        func_02045f3c(messages, &line[1], 0, 0xb4, 0x1f, 8, 0x14, 0, 1, 0x11);
    else
        func_02045f3c(messages, &line[1], 0, 0xb4, 0x7fff, 8, 0x14, 0, 1, 0x11);
#endif
    if (self->menu_ == 1)
    {
        void* item = DebugMenu_GetItem((IndexList_0202a9ac*)&self->menuList_, self->current_->motion_);
        if (item == NULL)
            return;
        Struct_ov015_0219050c* record = func_ov015_0218f39c(self->current_, func_02029560(item));
        if (record == NULL)
            return;
        sprintf(text, data_ov015_02194273, record->name);
        PREPARE_TEXT();
        DRAW_LINE(0x96, 0x96, 0x7fff);
        sprintf(text, data_ov015_0219427b, (double)(record->unknown_18_ / 4096.0f));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xa0, 0x7fff);
        sprintf(text, data_ov015_02194288, (double)(func_ov015_0218f3c4((Struct_ov015_0218f3c4_2*)self->current_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xaa, 0x7fff);
        sprintf(text, data_ov015_02194295, (double)(func_ov015_0218f408((Struct_ov015_0218f408_2*)self->current_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xb4, 0x7fff);
    }
    if (self->unknown_1a0_ && self->current_ != NULL)
        func_ov015_0218f794(self->current_);
}
