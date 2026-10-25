#include <globaldefs.h>

#if defined(jpn)
extern char data_020f2d2c[];
extern char data_020f2d31[];
enum { Enum_020e1cdc_12 = 12, Enum_020e1cdc_9 = 9, Enum_020e1cdc_12_2 = 12, Enum_020e1cdc_11 = 11 };
#else
enum { Enum_020e1cdc_9_2 = 9, Enum_020e1cdc_1 = 1, Enum_020e1cdc_11_2 = 11, Enum_020e1cdc_1_2 = 1 };
#endif

#if defined(jpn)
#define func_020e1cdc func_020e38d4
#endif
struct Panel020e1cdc { char pad[0x38]; unsigned char x, y, width, height; };
struct Object020e1cdc { const void* staging; Panel020e1cdc* panel; unsigned char count; };
int StandardStrings_Get(int);
extern "C" int Font_GetTextWidth(int, unsigned char);
extern "C" void func_020e1b2c(Object020e1cdc*, int);
extern "C" int func_020e1f1c(Object020e1cdc*);
extern "C" void func_020e2110(Object020e1cdc*);
void UpdateObj020e15f8Entry_020e2310(char*, int, int, int, int, unsigned char, unsigned char);
extern "C" void func_020e23f4(Object020e1cdc*);
void FreeVRAMStagingMemory(const void*);
// USA: func_020e1cdc
extern "C" ARM int func_020e1cdc(Struct_020e1cdc_2* arg0, int arg1) {
    if (!arg0->unknown_4_) return 1;
    arg0->unknown_4_->unknown_38_ = 0xc2;
    arg0->unknown_4_->unknown_39_ = 0x48;
    arg0->unknown_4_->unknown_3a_ = 0x3c;
    arg0->unknown_4_->unknown_3b_ = 0x2c;
#if !defined(jpn)
    int first = StandardStrings_Get(27);
    int second = StandardStrings_Get(28);
    int width = Font_GetTextWidth(first, 1);
    int otherWidth = Font_GetTextWidth(second, 1);
    if (width < otherWidth) width = otherWidth;
    int span = width + 24;
    obj->panel->x = 256 - (span + 2);
    obj->panel->width = span;
#endif
    func_020e1b2c(arg0, arg1);
    if (func_020e1f1c(arg0)) {
        arg0->unknown_8_ = 0;
        func_020e2110(arg0);
#if defined(jpn)
        func_020e2310((char*)arg0, 0, 12, 8, (int)data_020f2d2c, Enum_020e1cdc_12, Enum_020e1cdc_9);
        func_020e2310((char*)arg0, 1, 12, 24, (int)data_020f2d31, Enum_020e1cdc_12_2, Enum_020e1cdc_11);
#else
        func_020e2310((char*)arg0, 0, 12, 8, var0, Enum_020e1cdc_9_2, Enum_020e1cdc_1);
        func_020e2310((char*)arg0, 1, 12, 24, var1, Enum_020e1cdc_11_2, Enum_020e1cdc_1_2);
#endif
        func_020e23f4(arg0);
        if (arg0->unknown_0_) FreeVRAMStagingMemory(arg0->unknown_0_);
        return 0;
    }
    return 1;
}
