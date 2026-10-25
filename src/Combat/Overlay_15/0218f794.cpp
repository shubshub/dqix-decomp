#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Overlay15ViewerContext.h"

extern "C" void __clear(void* arg0, unsigned long arg1);

struct Struct_ov015_0218f794
{
    char unknown_0_[0x19b0];
    unsigned char unknown_19b0_;
};

MessageSystem0218f794* MessageSystem_GetInstance();
extern "C" void func_02069fec(MessageSystem0218f794* system, const char* text, char* converted);
extern "C" void func_02045d14(MessageSystem0218f794* system, const char* converted, unsigned short* line, int unk);
extern "C" void func_02045f3c(MessageSystem0218f794* system, unsigned short* line, int x, int y, int color, int a, int b, int c, int d, int e);

extern const char data_ov015_0219417c[];
extern const char data_ov015_02194192[];
extern const char data_ov015_021941a8[];
extern const char data_ov015_021941be[];
extern const char data_ov015_021941d4[];
extern const char data_ov015_021941ea[];
extern const char data_ov015_02194200[];
extern const char data_ov015_02194216[];
extern const char data_ov015_0219422c[];
extern const char data_ov015_02194242[];

#define PRINT_HEAP(fmt, allocator)                                                \
    {                                                                             \
        unsigned int used = (allocator).GetSizeWithLargestBlockRemoved();         \
        unsigned int size = (allocator).GetSize();                                \
        sprintf(var0, fmt, used, size);                                           \
    }

#define PREPARE_TEXT()                                                            \
    {                                                                             \
        memset(line, 0, sizeof(line));                                            \
        MessageSystem0218f794* system = MessageSystem_GetInstance();        \
        char converted[0x40];                                                     \
        __clear(converted, sizeof(converted));                                    \
        func_02069fec(system, var0, converted);                                   \
        func_02045d14(system, converted, var1, 0);                                \
    }

#define DRAW_LINE(y)                                                              \
    {                                                                             \
        var2->unknown_19b0_ = 1;                                                   \
        func_02045f3c(var2, &var1[1], 0, y, 0x7fff, 8, 0x14, 0, 1, 0x11);     \
    }

// USA: func_ov015_0218f794
extern "C" ARM void func_ov015_0218f794(Struct_ov015_0218bcb0* arg0)
{
    char var0[0x20];
    unsigned short var1[0x20];

    MessageSystem0218f794* messages = MessageSystem_GetInstance();
    if (self->kind_ == 0 || self->kind_ == 1)
    {
        PRINT_HEAP(data_ov015_0219417c, arg0->unknown_8_[2]);
        PREPARE_TEXT();
        DRAW_LINE(0);
        PRINT_HEAP(data_ov015_02194192, arg0->unknown_8_[3]);
        PREPARE_TEXT();
        DRAW_LINE(0xa);
        PRINT_HEAP(data_ov015_021941a8, arg0->unknown_8_[7]);
        PREPARE_TEXT();
        var2->unknown_19b0_ = 1;
        DRAW_LINE(0x14);
        PRINT_HEAP(data_ov015_021941be, arg0->unknown_8_[0]);
        PREPARE_TEXT();
        DRAW_LINE(0x1e);
        PRINT_HEAP(data_ov015_021941d4, arg0->unknown_8_[5]);
        PREPARE_TEXT();
        DRAW_LINE(0x28);
        PRINT_HEAP(data_ov015_021941ea, arg0->unknown_8_[1]);
        PREPARE_TEXT();
        DRAW_LINE(0x32);
        PRINT_HEAP(data_ov015_02194200, arg0->unknown_8_[6]);
        PREPARE_TEXT();
        DRAW_LINE(0x3c);
        PRINT_HEAP(data_ov015_02194216, arg0->unknown_8_[8]);
        PREPARE_TEXT();
        DRAW_LINE(0x46);
        PRINT_HEAP(data_ov015_0219422c, arg0->unknown_8_[9]);
        PREPARE_TEXT();
        DRAW_LINE(0x50);
    }
    else
    {
        PRINT_HEAP(data_ov015_02194242, arg0->unknown_8_[0]);
        PREPARE_TEXT();
        DRAW_LINE(0);
    }
}
