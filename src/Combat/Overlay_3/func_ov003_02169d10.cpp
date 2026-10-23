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
void AppendPaletteTag_02041e70(char* text, int palette);
void AppendString02042058(char* text, const char* append);
void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendUaTag_02041ed8(char* text, int a, int b, int c);
void AppendDbTag_02041f24(char* text, int a, int b, int c);
void AppendSizeTag_02041d9c(char* text, int size);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
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
    func_02041a90(arg1, var1 * 8 + 0x23, 5);
    if (arg0->unknown_5a6_)
        func_02041e70(arg1, 0xd);
    else
        func_02041e70(arg1, 0xf);
    func_02042058(arg1, data_ov003_02180137);
    func_02041a90(arg1, var1 * 8 + 0x23, 0x1b);
    if (arg0->unknown_5a7_)
        func_02041e70(arg1, 0xd);
    else
        func_02041e70(arg1, 0xf);
    func_02042058(arg1, data_ov003_02180145);
    func_02041e70(arg1, 0xf);
 #endif
    if (arg2)
        func_02041c08(arg1, var1, 3, 0xb, 3, 0xa);
    func_02041ed8(arg1, var1, arg0->unknown_5a6_, 2);
    func_02041f24(arg1, var1, arg0->unknown_5a7_, 2);
    func_02041d9c(arg1, 0xc);
    for (int var2 = 0; var2 < 7; var2++)
    {
        memset(var0, 0, 2);
        sprintf(var0, data_ov003_02180156, arg0->unknown_4ef_[var2]);
#if !defined(jpn)
        func_02041a90(arg1, var2 * 8 + 0x24, 0x10);
#endif
        if (var2 < 4)
            func_02041b70(arg1, var2, var0);
        else
            func_02042058(arg1, data_ov003_02180159);
    }
#if !defined(jpn)
    func_02041a28(arg1, 0x5c);
#endif
    AppendString02042058(text, KeyTable_Get((Container020e0310*)self->texts_, 0x66));
}
