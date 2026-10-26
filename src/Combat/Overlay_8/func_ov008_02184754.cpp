#include <globaldefs.h>
#include "Graphics/Background.h"
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
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
    int titleX_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

typedef void (Struct_ov008_021842a0_2::*Type_02000c9c_12)(unsigned int ticks);

struct Struct_ov008_0218b340 {
    Type_02000c9c_12 states[15];
};

extern Struct_ov008_0218b340 data_ov008_0218b340;
extern Type_02000c9c_12 __ptmf_null;

struct Struct_ov008_02184754;
struct Struct_0209ff6c;

extern "C" void func_ov008_021870e4(Struct_ov008_02184754* obj, unsigned int ticks);
extern "C" void func_0209ff6c(Struct_0209ff6c* arg0);

extern "C" {
void func_ov008_02188ef0(Struct_ov008_021842a0_2* self);
unsigned char Window_Update(TextWindow* window, int ticks);
void func_ov008_02186e4c(Struct_ov008_021842a0_2* self, unsigned int ticks);
void func_ov008_0218747c(Struct_ov008_021842a0_2* self, int index);
void func_ov023_021eb43c(void* arg0);
}

// USA: func_ov008_02184754
extern "C" ARM int func_ov008_02184754(Struct_ov008_021842a0_2* self)
{
    func_ov008_02188ef0(self);
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    Window_Update(&self->window_, ticks);
    func_ov008_02186e4c(self, ticks);
    self->model_.AdvanceEffects();
    func_ov008_021870e4((Struct_ov008_02184754*)self, ticks);
    func_ov008_0218747c(self, 0);
    func_ov008_0218747c(self, 1);
    Struct_ov008_0218b340 table = data_ov008_0218b340;
    table.states[14] = __ptmf_null;
    if (table.states[self->state_] == NULL)
        return 0;
    (self->*table.states[self->state_])(ticks);
    if (self->titles_ != NULL)
        func_0209ff6c((Struct_0209ff6c*)self->titles_);
    if (self->unknown_b08_ != NULL)
        func_ov023_021eb43c(self->unknown_b08_);
    if (self->state_ == 14)
        return 1;
    return 0;
}
