#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02187b20 func_ov008_021888fc
#endif
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_2 {
    Struct_01ff8b48_26 unknown_0_[2];
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unknown_14_0_ : 8;
    unsigned int unknown_15_0_ : 14;
    unsigned int unknown_16_6_ : 10;
};

struct Struct_ov008_021843f8_3 {
    Struct_01ff8b48_26 unknown_0_;
    Struct_01ff8b48_26 unknown_4_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 8;
    unsigned int unknown_c_0_ : 7;
    unsigned int unknown_c_7_ : 7;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
};

struct Struct_ov000_021735d0 {
    unsigned int unknown_0_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 unknown_0_;
    Struct_ov008_021843f8_3 unknown_3c_;
};

struct Struct_ov008_02187278 {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short unknown_14_;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov003_021594c4 {
    int unknown_0_[0x20 / 4];
};

struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    int unknown_0_[0xe0 / 4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
#if !defined(jpn)
    int unknown_b2c_;
#endif
    const void* unknown_b30_;
    Struct_ov008_02187278* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct Struct_020465c0;
struct Struct_0201099c_3;

#if !defined(jpn)
extern char data_ov008_0218b4c3[];
#endif

unsigned char* GetGlobalField0x1c020421a0();
void CopyOutBattleField0x7ac0_020ac0b4(void* count);
void StoreInArray0x8b0_020465c0(StoreStruct* messages, int index, int value);
void SetByteInRange_020465f0(unsigned char* messages, int index, unsigned char digits);
void SetByteAtIndex_020465d8(unsigned char* messages, int index, unsigned char value);
void AppendPaletteTag_02041e70(char* text, int color);
int TestBitInByteArray_0206dfb0(int store, unsigned char* bits, int flag);
void AppendXYTag_02041a90(char* text, int x, int y);
const char* KeyTable_Get(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);

extern "C" {
void __clear(void* arg0, unsigned long arg1);
void func_02046380(unsigned char* arg0);
char* func_0205ec34();
}

// USA: func_ov008_02187b20
extern "C" ARM void func_ov008_02187b20(Struct_ov008_021842a0_2* arg0, char* arg1, Struct_ov008_021843f8_2* arg2)
{
    Struct_ov008_021843f8* var0;
    int var1;
    if (arg1 == NULL)
        return;
    unsigned char* var2 = func_020421a0();
    int var3;
    unsigned int var4;
    unsigned char var5;
    var4 = 0;
    var0 = (Struct_ov008_021843f8*)((char*)GameState::GetInstance() + LOW_REGION(0x2c4 + 0x7000, 0x104 + 0x7400));
    int var6;
    Struct_ov008_02187278* var7 = arg0->unknown_b34_;
    int var8;
    int var9;
    int var10;
    if (var7 != NULL)
    {
        var3 = var7->unknown_5_6_;
        var4 = var7->unknown_1_6_;
        var6 = arg0->unknown_b34_->unknown_c_0_;
        var8 = arg0->unknown_b34_->unknown_10_0_;
        var9 = arg0->unknown_b34_->unknown_d_2_;
        var10 = arg0->unknown_b34_->unknown_11_1_;
    }
    else if (arg2 != NULL)
    {
        var3 = arg2->unknown_8_0_;
        var4 = arg2->unknown_c_0_;
        var6 = arg2->unknown_10_0_;
        var8 = arg2->unknown_14_0_;
        var9 = arg2->unknown_11_1_;
        var10 = arg2->unknown_15_0_;
    }
    else
    {
        var3 = var0->unknown_3c_.unknown_8_0_;
        func_020ac0b4(&var4);
        var6 = var0->unknown_3c_.unknown_10_0_;
        var8 = var0->unknown_3c_.unknown_b_0_;
        var9 = var0->unknown_3c_.unknown_d_6_;
        var10 = var0->unknown_3c_.unknown_11_1_;
    }
    if (arg0->unknown_b0c_ != NULL)
        var6--;
    if (var3 > 99999)
        var3 = 99999;
    if ((int)var4 > 99999)
        var4 = 99999;
    if (var6 > 999)
        var6 = 999;
    if (var8 > 999)
        var8 = 999;
    if (var9 > 9999)
        var9 = 9999;
    if (var10 > 9999)
        var10 = 9999;
    func_02046380(var2);
    func_020465c0((Struct_020465c0*)var2, 0, var3);
    func_020465f0(var2, 0, 5);
    func_020465d8(var2, 0, 1);
    func_020465c0((Struct_020465c0*)var2, 1, var4);
    func_020465f0(var2, 1, 5);
    func_020465d8(var2, 1, 1);
    func_020465c0((Struct_020465c0*)var2, 2, var6);
    func_020465f0(var2, 2, LOW_REGION(3, 5));
    char* var11;
    func_020465d8(var2, 2, 1);
    func_020465c0((Struct_020465c0*)var2, 3, var8);
    func_020465f0(var2, 3, LOW_REGION(3, 5));
    func_020465d8(var2, 3, 1);
    func_020465c0((Struct_020465c0*)var2, 4, var9);
    func_020465f0(var2, 4, LOW_REGION(4, 5));
    func_020465d8(var2, 4, 1);
    func_020465c0((Struct_020465c0*)var2, 5, var10);
    func_020465f0(var2, 5, LOW_REGION(4, 5));
    func_020465d8(var2, 5, 1);
    func_02041e70(arg1, 0xe);
    var11 = func_0205ec34();
    var5 = 0;
    if (arg2 != NULL)
    {
        for (int var12 = 0; var12 < 6; var12++)
            var5 += 1 << var12;
    }
    else
    {
        var5 += 1;
        if (func_0206dfb0((int)var11, (unsigned char*)(var11 + 0x8c), 0x1198))
            var5 += 2;
        var5 += 4;
        if (var0->unknown_3c_.unknown_b_0_ != 0)
            var5 += 8;
        if (var0->unknown_3c_.unknown_d_6_ != 0)
            var5 += 0x10;
        if (func_0206dfb0((int)var11, (unsigned char*)(var11 + 0x8c), 0x1199))
            var5 += 0x20;
    }
    int var13 = 0;
    for (int var14 = 0; var14 < 6; var14++)
    {
        if (var5 & (1 << var14))
        {
#if defined(jpn)
            AppendXYTag_02041a90(text, 2, line * 15 + 1);
            AppendString02042058(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x78)));
#else
            char label[0x40];
            y = line * 14;
            AppendXYTag_02041a90(text, 2, y + 7);
            __clear(label, sizeof(label));
            const char* name = KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x78));
            memcpy(label, name, strlen(name));
            char* value = strstr(label, data_ov008_0218b4c3);
            if (value != NULL)
                *value = 0;
            AppendString02042058(text, label);
            AppendXYTag_02041a90(text, 0x62, y + 7);
            AppendString02042058(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 500)));
#endif
            var13++;
        }
    }
}
