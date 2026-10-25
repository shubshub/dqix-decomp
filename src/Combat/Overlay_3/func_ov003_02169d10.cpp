#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define PANEL_SHIFT 4
extern "C" void func_02042428(char*, int);
#define func_02041d9c func_02042428
#define data_ov003_02180156 data_ov003_0217e8e5
#define data_ov003_02180159 data_ov003_0217e8e8
#else
#define PANEL_SHIFT 0
#endif
struct Struct_0201099c_3;

struct Struct_ov003_02169d10
{
    char unknown_0_[0x64];
    char unknown_64_[0x4ee - PANEL_SHIFT - 0x64];
    signed char unknown_4ee_;
    signed char unknown_4ef_[7];
    char unknown_4f6_[0x5a6 - 0x4f6];
    unsigned char unknown_5a6_;
    unsigned char unknown_5a7_;
};

extern "C" void __clear(void* buf, int size);
void AppendXYTag_02041a90(char* text, int x, int y);
void Text_AppendPaletteTag(char* text, int palette);
void Text_Append(char* text, const char* append);
void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void AppendUaTag_02041ed8(char* text, int a, int b, int c);
void AppendDbTag_02041f24(char* text, int a, int b, int c);
void AppendSizeTag_02041d9c(char* text, int size);
void Text_AppendNTag(char* text, int item, const char* itemText);
void AppendXTag_02041a28(char* text, int x);
const char* KeyTable_Get(Container020e0310* c, int key);

extern "C" const char data_ov003_02180137[];
extern "C" const char data_ov003_02180145[];
extern "C" const char data_ov003_02180156[];
extern "C" const char data_ov003_02180159[];

// USA: func_ov003_02169d10
extern "C" ARM void func_ov003_02169d10(Struct_ov003_02169d10* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    char var0[2];
    __clear(var0, 2);
    int var1 = arg0->unknown_4ee_;
#if !defined(jpn)
    AppendXYTag_02041a90(text, cursor * 8 + 0x23, 5);
    if (self->upActive_)
        Text_AppendPaletteTag(text, 0xd);
    else
        Text_AppendPaletteTag(text, 0xf);
    Text_Append(text, data_ov003_02180137);
    AppendXYTag_02041a90(text, cursor * 8 + 0x23, 0x1b);
    if (self->downActive_)
        Text_AppendPaletteTag(text, 0xd);
    else
        Text_AppendPaletteTag(text, 0xf);
    Text_Append(text, data_ov003_02180145);
    Text_AppendPaletteTag(text, 0xf);
 #endif
    if (framed)
        Text_AppendFrameTag(text, cursor, 3, 0xb, 3, 0xa);
    AppendUaTag_02041ed8(text, cursor, self->upActive_, 2);
    AppendDbTag_02041f24(text, cursor, self->downActive_, 2);
    AppendSizeTag_02041d9c(text, 0xc);
    for (int i = 0; i < 7; i++)
    {
        memset(var0, 0, 2);
        sprintf(var0, data_ov003_02180156, arg0->unknown_4ef_[var2]);
#if !defined(jpn)
        func_02041a90(arg1, var2 * 8 + 0x24, 0x10);
#endif
        if (i < 4)
            Text_AppendNTag(text, i, buf);
        else
            Text_Append(text, data_ov003_02180159);
    }
#if !defined(jpn)
    func_02041a28(arg1, 0x5c);
#endif
    Text_Append(text, KeyTable_Get((Container020e0310*)self->texts_, 0x66));
}
