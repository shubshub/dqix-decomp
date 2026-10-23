#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"

#include <Memory/SafeAllocator.h>

struct Struct_ov008_021843f8_2 {
    Struct_020ac4f8 unknown_0_[2];
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
    Struct_020ac4f8 unknown_b40_[2];
};

struct Struct_0201099c_3;

void* GetGlobalField0x1c020421a0();
void AppendPaletteTag_02041e70(char* text, int color);
void AppendYTag_02041a5c(char* text, int y);
const char* KeyTable_Get(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);

extern "C" {
void __clear(void* arg0, unsigned long arg1);
int sprintf(char* arg0, const char* arg1, ...);
}

#if defined(jpn)
struct Struct_020465c0;
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020474a8(void*, int, const char*, char*);
#endif

// USA: func_ov008_02187278
extern "C" ARM void func_ov008_02187278(Struct_ov008_021842a0_2* arg0, char* arg1, int arg2, Struct_ov008_021843f8_2* arg3)
{
    if (arg1 == NULL)
        return;
    Struct_020ac4f8* var0 = NULL;
    Struct_020ac4f8 var1;
    func_ov008_02184598(&var1);
    if (arg2 == 0)
    {
        Struct_ov008_02187278* var2 = arg0->unknown_b34_;
        var0 = &arg0->unknown_b40_[0];
        if (var2 != NULL)
        {
            var0 = &var1;
            var1.unknown_0_ = var2->unknown_0_0_;
            var1.unknown_2_ = arg0->unknown_b34_->unknown_8_0_;
        }
        else if (arg3 != NULL)
        {
            var0 = &arg3->unknown_0_[0];
        }
    }
    else if (arg2 == 1)
    {
        Struct_ov008_02187278* var3 = arg0->unknown_b34_;
        var0 = &arg0->unknown_b40_[1];
        if (var3 != NULL)
        {
            var0 = &var1;
            var1.unknown_0_ = var3->unknown_4_0_;
            var1.unknown_2_ = arg0->unknown_b34_->unknown_8_7_;
        }
        else if (arg3 != NULL)
        {
            var0 = &arg3->unknown_0_[1];
        }
    }
    if (var0 == NULL)
        return;
    GameState::GetInstance();
#if defined(jpn)
    void* messages = GetGlobalField0x1c020421a0();
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    func_02046380(messages);
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, time->hours);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 4);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, time->minutes);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 2);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    func_020474a8(messages, 10, KeyTable_Get((Container020e0310*)&self->texts_, 0x6e), buffer);
    AppendPaletteTag_02041e70(text, 0xe);
    AppendString02042058(text, buffer);
#else
    GetGlobalField0x1c020421a0();
    AppendPaletteTag_02041e70(text, 0xe);
    AppendYTag_02041a5c(text, 2);
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    const char* format = KeyTable_Get((Container020e0310*)&self->texts_, 0x6e);
    if (format != NULL)
        sprintf(buffer, format, time->hours, time->minutes);
    AppendString02042058(text, buffer);
#endif
}
