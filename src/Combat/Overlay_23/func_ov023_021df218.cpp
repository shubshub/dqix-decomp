#include <globaldefs.h>


// USA: func_ov023_021df218

struct Struct_ov023_021db45c;

extern "C" void WindowPane_Init(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" void* Scenario_GetInstance();
int Scenario_TestFlag(int flags, unsigned char* flags2, int id);
int MatchesAnyTableEntry020dd19c(unsigned int a, int b);
void SetByteField_021e29b8(void* a, int b, unsigned char v);
extern "C" void* func_ov023_021e2550(void* obj, int unused, int index);
void UpdateEntryAndReset_021db45c(void* obj, struct StructAcAe021db45c* p1, int p2, short* p3, short* p4);
extern "C" void func_ov023_021e257c(void* obj);
void* CreateAndSetFields8A_021db544(void* a, void* b, int c, int d);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern "C" unsigned short* func_ov023_021db2b8(signed char screen, int bg1);
void CleanInvalidateCacheRange(void const*, unsigned int);
extern "C" void func_ov023_021e2bdc(void* arg0, int arg1, short* arg2, short* arg3);

struct Struct_ov023_021ff9e0_12 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    void* unknown_20_;
};

extern "C" Struct_ov023_021ff9e0_12 data_ov023_021ff9e0;
extern "C" const unsigned char data_ov023_021fd626[];
extern "C" const short data_ov023_021fd64c[];
extern "C" const short data_ov023_021fd634[];

struct Struct_ov023_021df218 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 4;
    unsigned int unknown_1_3_ : 21;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
};

struct Struct_ov023_021df218_2 {
    int unknown_0_;
    void* unknown_4_;
    char unknown_8_[0x12 - 8];
    short unknown_12_;
};

struct Struct_ov023_021df218_3 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
};

struct Struct_ov023_021df218_4 {
    char unknown_0_[0x4c];
    int* unknown_4c_;
    char unknown_50_[0xcc - 0x50];
    Struct_ov023_021df218_2 unknown_cc_;
    char unknown_e0_[0x75c - 0xe0];
    int unknown_75c_;
};

extern "C" ARM void func_ov023_021df218(Struct_ov023_021df218_4* arg0)
{
    char var0[0xe0];
    unsigned char var1[14];
    short var2;
    short var3;
    unsigned short var4;
    short var5;
    short var6;
    int var7;
    int var8;
    short var9;
    unsigned short* var10;

    WindowPane_Init(buf);
    if (!InitBufferFromDataField4_021ddc34(buf, 0, 0, 7, 0x10))
        return;

    var8 = 0;
    {
        unsigned char var11;
        unsigned char var12;
        int var13;
        unsigned int var14 = 1;
        struct Struct_ov023_021df218* var15 = (struct Struct_ov023_021df218*)arg0->unknown_4c_[0];

        if (var15 != NULL)
        {
            Struct_ov023_021df218_3* var16 = (Struct_ov023_021df218_3*)func_ov023_021db4e4(&arg0->unknown_cc_, 0x1b);
            if (var16)
                var16->unknown_16_ |= 1;

            memcpy(var1, data_ov023_021fd626, 0xd);

            {
                void* f = Scenario_GetInstance();
                for (j = 7; j < 0xd; j++)
                {
                    if (Scenario_TestFlag((int)f, (unsigned char*)f + 0x8c, 0x113f + j))
                        flags[j] = 1;
                }
            }

            var11 = 1;
            var12 = 0;
            for (; var11 < 0xd; var12++, var11++)
            {
                if (var1[var11] != 0)
                {
                    var13 = 0xe;
                    if (var15->unknown_0_7_ != 0)
                    {
                        if (func_020dd19c(var11, var15->unknown_0_7_ & 0xff) != 0)
                            var13 = 0xf;
                    }
                    else
                    {
                        if (var15->unknown_4_0_ & ((unsigned short)(var14 << var12)))
                            var13 = 0xf;
                    }
                    if (var13 == 0xe)
                        var8 |= 1 << var12;
                    {
                        short var18 = data_ov023_021fd64c[var12];
                        func_ov023_021e29b8(&arg0->unknown_cc_, var18, 3);
                        func_ov023_021e2550(&arg0->unknown_cc_, var18, var11);
                    }
                }
            }

            func_ov023_021db45c(&arg0->unknown_cc_, (struct Struct_ov023_021db45c*)var0, 0x1b, &var3, &var2);
            if (data_ov023_021ff9e0.unknown_4_ != 0)
            {
                arg0->unknown_cc_.unknown_4_ = var0;
                arg0->unknown_cc_.unknown_12_ = 1;
                func_ov023_021e257c(&arg0->unknown_cc_);
            }
            func_ov023_021db544(&arg0->unknown_cc_, (void*)0x1b, var3, var2);
            var16 = (Struct_ov023_021df218_3*)func_ov023_021db4e4(&arg0->unknown_cc_, 0x1b);
            if (var16)
                var16->unknown_16_ &= ~1;
        }
    }

    var7 = func_ov023_021ddc98(var0, arg0->unknown_75c_, (unsigned short)data_ov023_021ff9e0.unknown_10_, 0);

    if (&arg0->unknown_cc_ != (Struct_ov023_021df218_2*)0)
    {
        var10 = func_ov023_021db2b8(*(signed char*)((char*)data_ov023_021ff9e0.unknown_20_ + 0x77c), 0);
        if (var10 != NULL)
        {
            int var19;
            int var20;
            int var21;
            int var22;
            int var23;
            for (var23 = 0; var23 < 0xc; var23++)
            {
                if (var8 & (1 << var23))
                {
                    int var24;

                    var6 = 0;
                    var5 = 0;
                    func_ov023_021e2bdc(&arg0->unknown_cc_, data_ov023_021fd634[var23], &var6, &var5);
                    var9 = var6 >> 3;
                    var19 = var5 >> 3;
                    var6 = (short)var9;
                    var5 = (short)var19;

                    for (var20 = 0; var20 < 2; var20++)
                    {
                        unsigned short* var25 = (unsigned short*)((char *)var10 + (var19 << 6));
                        var21 = var9;
                        for (var22 = 0; var22 < 2; var22++)
                        {
                            var24 = var21 << 1;
                            var4 = (short)(*(unsigned short*)((char*)var25 + var24) & 0xfff);
                            var4 |= 0x1000;
                            CleanInvalidateCacheRange(&var4, 2);
                            *(unsigned short*)((char*)var25 + var24) = var4;
                            var21 = var21 + 1;
                        }
                        var19 = var19 + 1;
                    }
                }
            }
        }
    }

    arg0->unknown_75c_ = arg0->unknown_75c_ + var7;
}
