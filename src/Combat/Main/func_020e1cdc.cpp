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
struct Struct_020e1cdc { char pad[0x38]; unsigned char x, y, width, height; };
struct Struct_020e1cdc_2 { const void* unknown_0_; Struct_020e1cdc* panel; unsigned char count; };
extern "C" int StandardStrings_Get(int);
extern "C" int Font_GetTextWidth(int, unsigned char);
extern "C" void func_020e1b2c(Struct_020e1cdc_2*, int);
extern "C" int func_020e1f1c(Struct_020e1cdc_2*);
extern "C" void func_020e2110(Struct_020e1cdc_2*);
extern "C" void func_020e2310(char*, int, int, int, int, unsigned char, unsigned char);
extern "C" void func_020e23f4(Struct_020e1cdc_2*);
void FreeVRAMStagingMemory(const void*);
// USA: func_020e1cdc
extern "C" ARM int func_020e1cdc(Struct_020e1cdc_2* obj, int arg) {
    if (!obj->panel) return 1;
    obj->panel->x = 0xc2;
    obj->panel->y = 0x48;
    obj->panel->width = 0x3c;
    obj->panel->height = 0x2c;
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
    func_020e1b2c(obj, arg);
    if (func_020e1f1c(obj)) {
        obj->count = 0;
        func_020e2110(obj);
#if defined(jpn)
        func_020e2310((char*)obj, 0, 12, 8, (int)data_020f2d2c, Enum_020e1cdc_12, Enum_020e1cdc_9);
        func_020e2310((char*)obj, 1, 12, 24, (int)data_020f2d31, Enum_020e1cdc_12_2, Enum_020e1cdc_11);
#else
        func_020e2310((char*)obj, 0, 12, 8, first, Enum_020e1cdc_9_2, Enum_020e1cdc_1);
        func_020e2310((char*)obj, 1, 12, 24, second, Enum_020e1cdc_11_2, Enum_020e1cdc_1_2);
#endif
        func_020e23f4(obj);
        if (obj->unknown_0_) FreeVRAMStagingMemory(obj->unknown_0_);
        return 0;
    }
    return 1;
}
