#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"

struct Struct_02000c9c_73
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Struct_ov023_021f5e70_3
{
    short id_;
    char unk_2[2];
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
    char unk_8[0x28 - 8];
};

struct Struct_ov023_021f5e70_4
{
    short unk_0;
    char unk_2[2];
    Struct_ov023_021f5e70_3 entries_[6];
    Struct_02000c9c_73 unknown_f4_;
    short itemId_;
    char unknown_fa_[2];
    unsigned short unknown_fc_;
    char unknown_fe_[2];
    Struct_02000c9c_73 unknown_100_;
    char unknown_104_[8];
    unsigned short flags_ : 13;
    unsigned short unknown_10d_5_ : 3;
    char unknown_10e_[0x114 - 0x10e];
};

struct Struct_ov023_021fff08_12
{
    unsigned char count_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    void* items_;
    char* unknown_8_;
    Struct_ov023_021f5e70_4* unknown_c_;
    const char* message_;
};

struct Struct_ov023_021f5e70
{
#if defined(jpn)
    char unk_0[0x5c0c];
#else
    char unk_0[0x5e6c];
#endif

    Struct_ov023_021f5e70_4 unknown_5e6c_;
};

struct Struct_ov023_021f5e70_2
{
    char unk_0[0x104];
};

extern "C" unsigned long long func_ov023_021f6324(int size, unsigned char* data);
extern "C" void func_ov031_022118a8(Struct_ov023_021f5e70_2* context, const char* key, int length);
extern "C" void func_ov031_02211938(Struct_ov023_021f5e70_2* context, const void* input, int size, void* output);

extern "C" Struct_ov023_021fff08_12 data_ov023_021fff08;
extern "C" unsigned char data_ov023_021fff1c[];
extern "C" Script::OpcodeLookupEntry data_ov023_021fe34c[];
extern "C" unsigned char data_ov023_021fe3c8[];

// USA: func_ov023_021f5e70
extern "C" ARM int func_ov023_021f5e70(unsigned char* data, int size, void* buffer)
{
    Script counter;
    Script script;
    if (func_ov023_021f6324(size, data) != 0)
        return 0;
    int i;
    Struct_ov023_021f5e70_2 context;
    const char* key = (const char*)data_ov023_021fe3c8;
    func_ov031_022118a8(&context, key, strlen(key));
    func_ov031_02211938(&context, data, size - 4, buffer);
    data = (unsigned char*)buffer;
    Struct_ov023_021f5e70_4* downloaded = &((Struct_ov023_021f5e70*)GameState::GetInstance())->unknown_5e6c_;
    data_ov023_021fff08.unknown_2_ = 0;
    data_ov023_021fff08.unknown_3_ = 0;
    data_ov023_021fff08.unknown_c_ = downloaded;
    counter.Initialize();
    counter.SetOpcodeLookup(data_ov023_021fe34c);
    int length = size - 4;
    counter.Load(buffer, length);
    counter.Execute();
    if (data_ov023_021fff08.unknown_3_ == 0)
        return 0;
    for (i = 0; i < 6; i++)
    {
        downloaded->entries_[i].id_ = -1;
        data_ov023_021fff1c[i] = 0xff;
    }
    data_ov023_021fff08.count_ = data_ov023_021fff08.unknown_3_;
    if (data_ov023_021fff08.count_ > 6)
        data_ov023_021fff08.count_ = 6;
    for (i = 0; i < data_ov023_021fff08.count_; i++)
    {
        short var7 = rand() % data_ov023_021fff08.unknown_3_;
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (var7 == data_ov023_021fff1c[j])
                break;
        }
        if (j >= 0)
            i--;
        else
            data_ov023_021fff1c[i] = var7;
    }
    data_ov023_021fff08.unknown_2_ = 1;
    data_ov023_021fff08.unknown_3_ = 0;
    data_ov023_021fff08.unknown_c_ = downloaded;
    script.Initialize();
    script.SetOpcodeLookup(data_ov023_021fe34c);
    script.Load(data, length);
    script.Execute();
    return 1;
}
