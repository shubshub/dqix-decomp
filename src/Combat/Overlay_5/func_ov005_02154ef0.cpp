#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a418 func_ov005_0215b96c
#define func_ov005_0215a620 func_ov005_0215bb74
#define func_ov005_0215a720 func_ov005_0215bc6c
#define func_ov005_0215aa44 func_ov005_0215bf64
#define func_ov005_0215ae7c func_ov005_0215c33c
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
#endif
#include <GameState/GameState.h>

struct Struct_0205d1e0;
struct Struct_0205d228;
struct Struct_0205d274;
struct Struct_020e28dc;
struct Struct_020e2794_2;

struct Struct_ov005_02153954 {
    char unknown_0_[R(0xe60, 0xe64)];
    void* unknown_e64_;
    int unknown_e68_;
    char unknown_e6c_[0xee4 - 0xe6c];
    char unknown_ee4_[R(0x19ac - 0xee0, 0x1a34 - 0xee4)];
    char unknown_1a34_[0x3db8 - 0x1a34];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dcc - 0x3db9];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3df0 - 0x3dd0];
    signed char unknown_3df0_;
    signed char unknown_3df1_;
    signed char unknown_3df2_;
    unsigned char unknown_3df3_;
    char unknown_3df4_[0x3e04 - 0x3df4];
    signed char unknown_3e04_;
};

extern "C" void func_ov005_021537bc(void* frame, int a, int color);
extern "C" void func_ov005_0215a37c(EquipmentMenu* self);
extern "C" void func_ov005_0215a720(EquipmentMenu* self);
extern "C" void func_ov005_0215a2c8(EquipmentMenu* self);
extern "C" void func_ov005_0215a3bc(EquipmentMenu* self);
extern "C" void func_ov005_0215aa44(EquipmentMenu* self);
extern "C" void func_ov005_0215acc0(EquipmentMenu* self);
void Window_ClearLayers(Cont0205d1e0* window);
void Window_DrawPanes(Cont0205d228* window);
void Window_FlushLayers(Cont0205d274* window);
extern "C" void func_ov005_02159c88(EquipmentMenu* self);
int GetInnerFlagBit0020e28dc(Outer020e28dc* p);
void UpdateEntryIfActive020e2794(Struct020e2794* p, void* a);
extern "C" void func_ov005_0215a7ec(EquipmentMenu* self);
extern "C" void func_ov005_0215a418(EquipmentMenu* self);
extern "C" void func_ov005_0215b0a0(EquipmentMenu* self);

// USA: func_ov005_02154ef0
extern "C" ARM void func_ov005_02154ef0(Struct_ov005_02153954* arg0) {
    if (arg0->unknown_3db8_ == 1)
        return;
    if (arg0->unknown_3db8_ != 0) {
        if (arg0->unknown_3db8_ == 3) {
            int var0 = GameState::GetInstance()->GetTickCount();
            if (var0 == 0)
                var0 = 1;
            if (arg0->unknown_3df0_ > 0) {
                arg0->unknown_3df1_ -= var0;
                if (arg0->unknown_3df1_ <= 0) {
                    if (!(arg0->unknown_3dcc_ & 0x1000)) {
                        arg0->unknown_3dcc_ |= 0x1000;
                        arg0->unknown_3df1_ += 30;
                    } else {
                        arg0->unknown_3dcc_ &= ~0x1000;
                        arg0->unknown_3df1_ += 30;
                        arg0->unknown_3df0_--;
                    }
                }
            }
            arg0->unknown_3df2_ -= var0;
            if (arg0->unknown_3df2_ <= 0) {
                if (!(arg0->unknown_3dcc_ & 0x2000)) {
                    arg0->unknown_3dcc_ |= 0x2000;
                    arg0->unknown_3df2_ += 30;
                } else {
                    arg0->unknown_3dcc_ &= ~0x2000;
                    arg0->unknown_3df2_ += 30;
                }
            }
        }
        if (!(self->flags_ & 0x1000))
            func_ov005_021537bc(self->frame_, 0, 0x7fff);
        if (!(self->flags_ & 0x2000))
            func_ov005_0215a37c(self);
        func_ov005_0215a720(self);
        func_ov005_0215a2c8(self);
        func_ov005_0215a3bc(self);
        func_ov005_0215aa44(self);
        func_ov005_0215acc0(self);
        Window_ClearLayers((Cont0205d1e0*)self->window_);
        Window_DrawPanes((Cont0205d228*)self->window_);
        Window_FlushLayers((Cont0205d274*)self->window_);
    }
    func_ov005_02159c88(arg0);
    if (arg0->unknown_e64_ != NULL && func_020e28dc((Struct_020e28dc*)arg0->unknown_e64_))
        func_020e2794((Struct_020e2794_2*)arg0->unknown_e64_, (void*)arg0->unknown_e68_);
    func_ov005_0215a7ec(arg0);
    func_ov005_0215a418(arg0);
    if (!(arg0->unknown_3dcc_ & 0x200) && arg0->unknown_3e04_ <= 0) {
        func_ov005_0215b0a0(arg0);
        return;
    }
    arg0->unknown_3e04_--;
}
