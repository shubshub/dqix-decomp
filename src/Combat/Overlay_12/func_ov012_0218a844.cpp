#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_0201099c_3;

struct Struct_ov012_0218a844
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_[6];
};

struct Struct_0201099c_22
{
    char unknown_0_[0x54];
    Struct_ov012_0218a844 unknown_54_;
    char unknown_74_[LOW_REGION(0x128c, 0x1298) - 0x74];

    Struct_ov012_0218a844* inline_ov012_0218a844() { return &unknown_54_; }
};

struct Struct_ov012_0218a844_2
{
    char unknown_0_[LOW_REGION(0x90, 0xac)];
    Struct_0201099c_22 unknown_ac_;
    char unknown_1344_[LOW_REGION(0x1348, 0x1378) - LOW_REGION(0x131c, 0x1344)];
    const char* unknown_1378_;
    char unknown_137c_[LOW_REGION(0x1420, 0x13c8) - LOW_REGION(0x134c, 0x137c)];
    short* unknown_13c8_;
    char unknown_13cc_[LOW_REGION(0x1448, 0x13f0) - LOW_REGION(0x1424, 0x13cc)];
    int unknown_13f0_;

    Struct_0201099c_22* inline_ov012_0218a844_2() { return &unknown_ac_; }
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag_02041ea4(char* text, int a);
void* GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void AppendString02042058(char* text, const char* append);
void AppendXTag_02041a28(char* text, int x);
const char* KeyTable_Get(Container020e0310* texts, int id);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
void AppendXYTag_02041a90(char* text, int x, int y);
#if !defined(jpn)
extern "C" void func_ov012_021842a0(Struct_ov012_0218a844_2* arg0, int arg1, int arg2, int arg3);

extern "C" const char data_ov012_0218b310[];
#endif

#if defined(jpn)
struct Struct_020465c0;
struct Struct_02072a68_2;
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" const char* func_02072a68(Struct_02072a68_2*, int);
#endif

// USA: func_ov012_0218a844
extern "C" ARM void func_ov012_0218a844(Struct_ov012_0218a844_2* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int var0 = arg0->unknown_13f0_ & 0xf;
    if (arg2)
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    func_02041ea4(arg1, var0);
#if defined(jpn)
    void* var1 = func_020421a0();
#else
    func_020421a0();
#endif
    int var2;
    Struct_ov012_0218a844* var3 = arg0->inline_ov012_0218a844_2()->inline_ov012_0218a844();
    int var4 = var3->unknown_8_[3];
    int var5 = var3->unknown_4_;
    int var6;
    int var7;
    func_0205c508((Struct_0205c508*)var3, &var6, &var7);
    for (var2 = var6; var2 < var7; var2++)
    {
        if (var2 % 2 == 0)
        {
            if (var2 != var6)
                func_02042058(arg1, arg0->unknown_1378_);
        }
        else
        {
            func_02041a28(arg1, LOW_REGION(0x7c, 0x88));
        }
        AppendNameTag_02041b70(text, i & 0xf, KeyTable_Get((Container020e0310*)self->texts_, self->unk_13c8[i]));
    }
    if (var5 > 1)
    {
#if defined(jpn)
        func_02046380(var1);
        func_020465c0((Struct_020465c0*)var1, 0, var4 + 1);
        func_020465c0((Struct_020465c0*)var1, 1, var5);
        func_020465f0((unsigned char*)var1, 0, 2);
        func_020465f0((unsigned char*)var1, 1, 2);
        func_020465d8((unsigned char*)var1, 0, 1);
        func_020465d8((unsigned char*)var1, 1, 0);
        func_02042428(arg1, 8);
        func_02042058(arg1, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x1314), 0x7a));
#else
        func_ov012_021842a0(arg0, 12, var4, var5);
        func_02041a90(arg1, 0x56, 0x94);
        func_02042058(arg1, data_ov012_0218b310);
#endif
    }
}
