#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_02159c88 func_ov005_0215b1d4
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
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
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct Struct_020e28dc;
struct Struct_0205c570;

struct Struct_ov005_02158e04 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xbc - 0xb0];
    short unknown_bc_;
    short unknown_be_;
    char unknown_c0_[0xc4 - 0xc0];
    unsigned char unknown_c4_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0xe60, 0xe64)];
    Struct_020e28dc* unknown_e64_;
    void* unknown_e68_;
    char unknown_e6c_[0xee4 - 0xe6c];
    char unknown_ee4_[R(0x3d30 - 0xee0, 0x3db8 - 0xee4)];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dbc - 0x3db9];
    unsigned char unknown_3dbc_;
};

struct Struct_0205d81c;
MenuElement* FindElementForFieldB0_0205d8c4(Struct_0205d81c*);
int GetInnerFlagBit0020e28dc(Outer020e28dc* p);
extern "C" void func_0205ae8c(void* obj);
int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj);
int Window_GetSelectedIndex(Struct_0205c570* window);
void* GetField1c_021a193c(int* p);
extern "C" void func_ov023_021e3304(void* cursor, short x, short y);

// USA: func_ov005_0215a7ec
extern "C" ARM void func_ov005_0215a7ec(EquipmentMenu* self) {
    MenuElement* elem = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)self->window_);
    if (elem != NULL) {
        unsigned char kind = elem->kind_;
        if (self->yesNo_ != NULL && GetInnerFlagBit0020e28dc(self->yesNo_)) {
            func_0205ae8c(self->yesNoState_);
        } else if (kind == 1 && CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char*)elem)) {
            short x = (short)(elem->col_ << 3) + elem->offsetX_;
            short y = (short)(elem->row_ << 3) + elem->offsetY_;
            if (kind == 2) {
                x = 0xd4;
                int sum = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
                if (sum == 0)
                    y = 0x57;
                else if (sum == 1)
                    y = 0x65;
            }
            func_ov023_021e3304(func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]), var2 - 8, var3 - 2);
        }
    }
    if (arg0->unknown_3db8_ == 0) {
        short var5 = arg0->unknown_3dbc_ * 0x18 + 4;
        void* var6 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
        func_ov023_021e3304(var6, 0x74, var5);
    }
}
