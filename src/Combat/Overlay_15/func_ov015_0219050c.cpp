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

extern "C" void __clear(void* arg0, unsigned long arg1);

struct Struct_0204500c_5
{
#if defined(jpn)
    char unknown_0_[0x17e0];
#else
    char unknown1_0_[0x19b0];
#endif
    unsigned char unknown_19b0_;
};

struct Struct_ov015_0219050c
{
    char unknown_0_[0x18];
    int unknown_18_;
};

struct Struct_02029634;
struct Struct_ov015_0218f3c4_2;
struct Struct_ov015_0218f408_2;

struct Struct_ov015_0218c03c_2
{
    char unknown_0_[0x34];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    short unknown_38_;
};

struct Struct_ov015_0219050c_2
{
    char unknown_0_[0x30];
    Struct_ov015_0218c03c_2* unknown_30_;
    char unknown_34_[0x194 - 0x34];
    int unknown_194_;
    char unknown_198_[0x1a0 - 0x198];
    unsigned char unknown_1a0_;
    char unknown_1a1_[0x24c - 0x1a1];
    float unknown_24c_;
    char unknown_250_[0x2c4 - 0x250];
    char unknown_2c4_[0x80];
};

MessageSystem0219050c* MessageSystem_GetInstance();
extern "C" void func_02069fec(MessageSystem0219050c* system, const char* text, char* converted);
#if defined(jpn)
extern "C" int func_02045d14(Struct_0204500c_5* arg0, const char* arg1, unsigned short* arg2, int arg3);
#else
extern "C" void func_02045d14(Struct_0204500c_5* arg0, const char* arg1, unsigned short* arg2, int arg3);
#endif
#if defined(jpn)
extern "C" void func_02046c78(Struct_0204500c_5* arg0, unsigned short* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#else
extern "C" void func_02045f3c(Struct_0204500c_5* arg0, unsigned short* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);
#endif
extern "C" void* func_0202a9ac(Struct_02029634* arg0, int arg1);
extern "C" void* func_02029560(void* arg0);
extern "C" Struct_ov015_0219050c* func_ov015_0218f39c(Struct_ov015_0218c03c_2* arg0, void* arg1);
extern "C" float func_ov015_0218f3c4(Struct_ov015_0218f3c4_2* arg0);
extern "C" float func_ov015_0218f408(Struct_ov015_0218f408_2* arg0);
extern "C" void func_ov015_0218f794(Struct_ov015_0218c03c_2* arg0);

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
        func_02069fec(system, var0, converted);                           \
        func_02045d14(system, converted, var1, PrepareLineMode);          \
    }

#if defined(jpn)
#define DRAW_LINE(x, y, color)                                                     \
    {                                                                              \
        var2->unknown_19b0_ = 1;                                                    \
        func_02046c78(var2, &var1[1], x, y, color, 8, 0x14, 0);                  \
    }
#else
#define DRAW_LINE(x, y, color)                                                     \
    {                                                                              \
        var2->unknown_19b0_ = 1;                                                    \
        func_02045f3c(var2, &var1[1], x, y, color, 8, 0x14, 0, 1, 0x11);       \
    }
#endif

// USA: func_ov015_0219050c
extern "C" ARM void func_ov015_0219050c(Struct_ov015_0219050c_2* arg0)
{
    char var0[0x20];
    unsigned short var1[0x20];

    MessageSystem0219050c* messages = MessageSystem_GetInstance();
    sprintf(text, data_ov015_02194256, (double)(self->fps_));
    PREPARE_TEXT();
    DRAW_LINE(0, 0xa0, 0x7fff);
    unsigned short var3 = 0;
    if (arg0->unknown_30_ != NULL)
        var3 = arg0->unknown_30_->unknown_34_;
    sprintf(var0, data_ov015_02194261, var3);
    PREPARE_TEXT();
    DRAW_LINE(0, 0xaa, 0x7fff);
    unsigned short var4 = 0;
    if (arg0->unknown_30_ != NULL)
        var4 = arg0->unknown_30_->unknown_36_;
    sprintf(var0, data_ov015_0219426a, var4);
    PREPARE_TEXT();
    var2->unknown_19b0_ = 1;
#if defined(jpn)
    if (var4 != 0)
        func_02046c78(var2, &var1[1], 0, 0xb4, 0x1f, 8, 0x14, 0);
    else
        func_02046c78(var2, &var1[1], 0, 0xb4, 0x7fff, 8, 0x14, 0);
#else
    if (var4 != 0)
        func_02045f3c(var2, &var1[1], 0, 0xb4, 0x1f, 8, 0x14, 0, 1, 0x11);
    else
        func_02045f3c(var2, &var1[1], 0, 0xb4, 0x7fff, 8, 0x14, 0, 1, 0x11);
#endif
    if (arg0->unknown_194_ == 1)
    {
        void* var5 = func_0202a9ac((Struct_02029634*)&arg0->unknown_2c4_, arg0->unknown_30_->unknown_38_);
        if (var5 == NULL)
            return;
        Struct_ov015_0219050c* var6 = func_ov015_0218f39c(arg0->unknown_30_, func_02029560(var5));
        if (var6 == NULL)
            return;
        sprintf(var0, data_ov015_02194273, var6->unknown_0_);
        PREPARE_TEXT();
        DRAW_LINE(0x96, 0x96, 0x7fff);
        sprintf(var0, data_ov015_0219427b, (double)(var6->unknown_18_ / 4096.0f));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xa0, 0x7fff);
        sprintf(var0, data_ov015_02194288, (double)(func_ov015_0218f3c4((Struct_ov015_0218f3c4_2*)arg0->unknown_30_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xaa, 0x7fff);
        sprintf(var0, data_ov015_02194295, (double)(func_ov015_0218f408((Struct_ov015_0218f408_2*)arg0->unknown_30_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xb4, 0x7fff);
    }
    if (arg0->unknown_1a0_ && arg0->unknown_30_ != NULL)
        func_ov015_0218f794(arg0->unknown_30_);
}
