#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Graphics/Background.h"
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
    Struct_020ac4f8 unknown_b40_[2];
};

struct Container020e0310;

extern "C" void* MessageSystem_GetInstance();
extern "C" void Text_AppendPaletteTag(char* text, int color);
extern "C" void func_02041a5c(char* text, int y);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_Append(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
}

#if defined(jpn)
struct StoreStruct;
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020474a8(void*, int, const char*, char*);
#endif

// USA: func_ov008_02187278
extern "C" ARM void func_ov008_02187278(Struct_ov008_021842a0_2* self, char* text, int index, Struct_ov008_021843f8_2* records)
{
    if (text == NULL)
        return;
    Struct_020ac4f8* time = NULL;
    Struct_020ac4f8 var1;
    func_ov008_02184598(&var1);
    if (index == 0)
    {
        Struct_ov008_02187278* var2 = self->unknown_b34_;
        time = &self->unknown_b40_[0];
        if (var2 != NULL)
        {
            time = &var1;
            var1.hours = var2->unknown_0_0_;
            var1.minutes = self->unknown_b34_->unknown_8_0_;
        }
        else if (records != NULL)
        {
            time = &records->unknown_0_[0];
        }
    }
    else if (index == 1)
    {
        Struct_ov008_02187278* var3 = self->unknown_b34_;
        time = &self->unknown_b40_[1];
        if (var3 != NULL)
        {
            time = &var1;
            var1.hours = var3->unknown_4_0_;
            var1.minutes = self->unknown_b34_->unknown_8_7_;
        }
        else if (records != NULL)
        {
            time = &records->unknown_0_[1];
        }
    }
    if (time == NULL)
        return;
    GameState::GetInstance();
#if defined(jpn)
    void* messages = MessageSystem_GetInstance();
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    func_02046380(messages);
    func_020465c0((StoreStruct*)messages, 0, time->hours);
    func_020465f0((unsigned char*)messages, 0, 4);
    func_020465d8((unsigned char*)messages, 0, 1);
    func_020465c0((StoreStruct*)messages, 1, time->minutes);
    func_020465f0((unsigned char*)messages, 1, 2);
    func_020465d8((unsigned char*)messages, 1, 1);
    func_020474a8(messages, 10, KeyTable_Get((Container020e0310*)&self->texts_, 0x6e), buffer);
    Text_AppendPaletteTag(text, 0xe);
    Text_Append(text, buffer);
#else
    MessageSystem_GetInstance();
    Text_AppendPaletteTag(text, 0xe);
    func_02041a5c(text, 2);
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    const char* format = KeyTable_Get((Container020e0310*)&self->texts_, 0x6e);
    if (format != NULL)
        sprintf(buffer, format, time->hours, time->minutes);
    Text_Append(text, buffer);
#endif
}
