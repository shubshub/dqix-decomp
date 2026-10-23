#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_ov005_0215ae7c func_ov005_0215c33c
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Struct_02021b84;
struct Struct_02052e14;
struct Struct_0201099c_10;
struct Struct_0201099c_3;

struct Struct_ov005_02153ba4_2
{
    char unknown_0_[LOW_REGION(0x4f8,0x4fc)];
    int unknown_4fc_;
};

struct Struct_0201099c_9
{
    int unknown_0_;
    const char* unknown_4_;
};

struct Struct_ov005_02153954
{
    char unknown_0_[0xdf4];
    Struct_0201099c_10* unknown_df4_;
    char unknown_df8_[LOW_REGION(0x3d7c,0x3e04) - 0xdf8];
    signed char unknown_3e04_;
    char unknown_3e05_[0x3e84 - 0x3e05];
    unsigned short unknown_3e84_[8][LOW_REGION(0xa,0x40)];
    unsigned char unknown_4284_[8];
};

MessageSystem* GetGlobalField0x1c020421a0();
MemberScreen* GetField1c_021a193c(int* obj);
short* GetField150Ptr0x488(Field150Holder02052e14* member);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" void __clear(void* buffer, unsigned long size);
void CopyTextAndUppercaseIfFlagged0206819c(const char* name, char* output, int flag);
extern "C" void func_02046608(MessageSystem* messages, int, const char* format, char* output, int size, int, int);
const char* KeyTable_Get(Container020e0310* texts, int id);
int FindSubstring_020d2f88(char* text, char* search);
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int);
extern "C" void func_020439b0(MessageSystem* messages, int);
#if defined(jpn)
extern "C" void func_020471d0(Struct_02021b84* arg0, int, unsigned short* arg2, int);
extern "C" void func_020469b0(Struct_02021b84* arg0, const char* arg1, unsigned short* arg2, int);
#endif

extern "C" const unsigned char data_ov005_0215cc04[8];
extern "C" char data_ov005_0215ce08[];

// USA: func_ov005_0215ae7c
extern "C" ARM void func_ov005_0215ae7c(Struct_ov005_02153954* arg0)
{
    Struct_02021b84* var0 = func_020421a0();
    GameState* var1 = GameState::GetInstance();
    Struct_02052e14* var2 =
        (Struct_02052e14*)func_0200ff1c(var1, func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3])->unknown_4fc_);
    if (var2 == NULL)
        return;
    short* var3 = func_02052e14(var2);
    for (int var4 = 0; var4 < 8; var4++)
    {
#if defined(jpn)
        func_020471d0(var0, 0xa, arg0->unknown_3e84_[var4], 0xa);
#else
        func_020462d0(var0, arg0->unknown_3e84_[var4], 0x40);
#endif
        for (int var5 = 0; var5 < LOW_REGION(0xa,0x40); var5++)
            arg0->unknown_3e84_[var4][var5] = 0xffff;
#if !defined(jpn)
        arg0->unknown_4284_[var4] = 0;
#endif
    }
    for (int var6 = 0; var6 < 8; var6++)
    {
        short var7 = var3[data_ov005_0215cc04[var6]];
        Struct_0201099c_9* var8 = func_020dedd0(arg0->unknown_df4_, var7);
#if defined(jpn)
        if (var8 != NULL)
        {
            func_020469b0(var0, var8->unknown_4_, arg0->unknown_3e84_[var6], 0xa);
        }
        else if (var7 <= 0)
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), self->names_[i], 0xa);
        }
        else
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), self->names_[i], 0xa);
        }
#else
        char var9[0x80];
        __clear(var9, sizeof(var9));
        if (var8 != NULL)
        {
            char var10[0x80];
            __clear(var10, sizeof(var10));
            func_0206819c(var8->unknown_4_, var10, 0);
            func_02046608(var0, 0, var10, var9, 0x58, 0, 0);
        }
        else if (var7 <= 0)
        {
            func_02046608(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), text, 0x58, 0, 0);
        }
        else
        {
            func_02046608(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), text, 0x58, 0, 0);
        }
        if (func_020d2f88(var9, data_ov005_0215ce08))
            arg0->unknown_4284_[var6] = 1;
        func_02045d14(var0, var9, arg0->unknown_3e84_[var6], 0);
#endif
        func_020439b0(var0, 0);
        arg0->unknown_3e04_ = 2;
    }
}
