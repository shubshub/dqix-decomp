#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Graphics/Background.h"

#if defined(jpn)
#define func_ov008_02187b20 func_ov008_021888fc
#endif
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>


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
    Struct_01ff8b48_26 unk_4;
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
    unsigned int flags_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 flags_;
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
    unsigned char female_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct TextTable {
    int unknown_0_[0x18 / 4];
};


struct TextWindow {
    int unknown_0_[0xbc / 4];
};

struct Canvas {
    int unknown_0_[0xe0 / 4];
};

struct WindowCursor {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    TextTable texts_;
    char* text_;
    char unknown_bc_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
#if !defined(jpn)
    int titleX_;
#endif
    const void* unknown_b30_;
    Struct_ov008_02187278* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct StoreStruct;
struct Container020e0310;

#if !defined(jpn)
extern char data_ov008_0218b4c3[];
#endif

extern "C" unsigned char* MessageSystem_GetInstance();
extern "C" void func_020ac0b4(void* count);
extern "C" void func_020465c0(StoreStruct* messages, int index, int value);
extern "C" void func_020465f0(unsigned char* messages, int index, unsigned char digits);
extern "C" void func_020465d8(unsigned char* messages, int index, unsigned char value);
extern "C" void Text_AppendPaletteTag(char* text, int color);
extern "C" int Scenario_TestFlag(int store, unsigned char* bits, int flag);
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_Append(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
void func_02046380(unsigned char* messages);
char* Scenario_GetInstance();
}

// USA: func_ov008_02187b20
extern "C" ARM void func_ov008_02187b20(Struct_ov008_021842a0_2* self, char* text, Struct_ov008_021843f8_2* records)
{
    Struct_ov008_021843f8* saved;
    int y;
    if (text == NULL)
        return;
    unsigned char* messages = MessageSystem_GetInstance();
    int count1;
    unsigned int count2;
    unsigned char shown;
    count2 = 0;
    saved = (Struct_ov008_021843f8*)((char*)GameState::GetInstance() + LOW_REGION(0x2c4 + 0x7000, 0x104 + 0x7400));
    int var6;
    Struct_ov008_02187278* var7 = self->unknown_b34_;
    int var8;
    int var9;
    int var10;
    if (var7 != NULL)
    {
        count1 = var7->unknown_5_6_;
        count2 = var7->unknown_1_6_;
        var6 = self->unknown_b34_->unknown_c_0_;
        var8 = self->unknown_b34_->unknown_10_0_;
        var9 = self->unknown_b34_->unknown_d_2_;
        var10 = self->unknown_b34_->unknown_11_1_;
    }
    else if (records != NULL)
    {
        count1 = records->unknown_8_0_;
        count2 = records->unknown_c_0_;
        var6 = records->unknown_10_0_;
        var8 = records->unknown_14_0_;
        var9 = records->unknown_11_1_;
        var10 = records->unknown_15_0_;
    }
    else
    {
        count1 = saved->unknown_3c_.unknown_8_0_;
        func_020ac0b4(&count2);
        var6 = saved->unknown_3c_.unknown_10_0_;
        var8 = saved->unknown_3c_.unknown_b_0_;
        var9 = saved->unknown_3c_.unknown_d_6_;
        var10 = saved->unknown_3c_.unknown_11_1_;
    }
    if (self->page_ != NULL)
        var6--;
    if (count1 > 99999)
        count1 = 99999;
    if ((int)count2 > 99999)
        count2 = 99999;
    if (var6 > 999)
        var6 = 999;
    if (var8 > 999)
        var8 = 999;
    if (var9 > 9999)
        var9 = 9999;
    if (var10 > 9999)
        var10 = 9999;
    func_02046380(messages);
    func_020465c0((StoreStruct*)messages, 0, count1);
    func_020465f0(messages, 0, 5);
    func_020465d8(messages, 0, 1);
    func_020465c0((StoreStruct*)messages, 1, count2);
    func_020465f0(messages, 1, 5);
    func_020465d8(messages, 1, 1);
    func_020465c0((StoreStruct*)messages, 2, var6);
    func_020465f0(messages, 2, LOW_REGION(3, 5));
    char* store;
    func_020465d8(messages, 2, 1);
    func_020465c0((StoreStruct*)messages, 3, var8);
    func_020465f0(messages, 3, LOW_REGION(3, 5));
    func_020465d8(messages, 3, 1);
    func_020465c0((StoreStruct*)messages, 4, var9);
    func_020465f0(messages, 4, LOW_REGION(4, 5));
    func_020465d8(messages, 4, 1);
    func_020465c0((StoreStruct*)messages, 5, var10);
    func_020465f0(messages, 5, LOW_REGION(4, 5));
    func_020465d8(messages, 5, 1);
    Text_AppendPaletteTag(text, 0xe);
    store = Scenario_GetInstance();
    shown = 0;
    if (records != NULL)
    {
        for (int i = 0; i < 6; i++)
            shown += 1 << i;
    }
    else
    {
        shown += 1;
        if (Scenario_TestFlag((int)store, (unsigned char*)(store + 0x8c), 0x1198))
            shown += 2;
        shown += 4;
        if (saved->unknown_3c_.unknown_b_0_ != 0)
            shown += 8;
        if (saved->unknown_3c_.unknown_d_6_ != 0)
            shown += 0x10;
        if (Scenario_TestFlag((int)store, (unsigned char*)(store + 0x8c), 0x1199))
            shown += 0x20;
    }
    int line = 0;
    for (int i = 0; i < 6; i++)
    {
        if (shown & (1 << i))
        {
#if defined(jpn)
            func_02041a90(text, 2, line * 15 + 1);
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x78)));
#else
            char label[0x40];
            y = line * 14;
            func_02041a90(text, 2, y + 7);
            __clear(label, sizeof(label));
            const char* name = KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x78));
            memcpy(label, name, strlen(name));
            char* value = strstr(label, data_ov008_0218b4c3);
            if (value != NULL)
                *value = 0;
            Text_Append(text, label);
            func_02041a90(text, 0x62, y + 7);
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 500)));
#endif
            line++;
        }
    }
}
