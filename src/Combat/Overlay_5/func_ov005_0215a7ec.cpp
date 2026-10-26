#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
#define func_ov005_0215a418 func_ov005_0215b96c
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

struct MenuElement {
    char unk_0[0xac];
    short unknown_ac_;
    short unknown_ae_;
    char unk_b0[0xbc - 0xb0];
    short unknown_bc_;
    short unknown_be_;
    char unk_c0[0xc4 - 0xc0];
    unsigned char kind_;
};

struct EquipmentMenu {
    char unk_0[R(0xe60, 0xe64)];
    Struct_020e28dc* unknown_e64_;
    void* yesNoState_;
    char unknown_e6c_[0xee4 - 0xe6c];
    char window_[R(0x3d30 - 0xee0, 0x3db8 - 0xee4)];
    unsigned char state_;
    char unknown_3db9_[0x3dbc - 0x3db9];
    unsigned char kind_;
};

struct Struct_0205d81c;
extern "C" MenuElement* Window_GetActivePane(Struct_0205d81c*);
extern "C" int func_020e28dc(Struct_020e28dc* p);
extern "C" void SpriteContext_DrawEntries(void* obj);
extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* window);
extern "C" void* func_ov017_021a193c(int* p);
extern "C" void func_ov023_021e3304(void* cursor, short x, short y);

// USA: func_ov005_0215a7ec
extern "C" ARM void func_ov005_0215a7ec(EquipmentMenu* self) {
    MenuElement* elem = Window_GetActivePane((Struct_0205d81c*)self->window_);
    if (elem != NULL) {
        unsigned char kind = elem->kind_;
        if (self->unknown_e64_ != NULL && func_020e28dc(self->unknown_e64_)) {
            SpriteContext_DrawEntries(self->yesNoState_);
        } else if (kind == 1 && WindowPane_IsOpen((unsigned char*)elem)) {
            short x = (short)(elem->unknown_ac_ << 3) + elem->unknown_bc_;
            short y = (short)(elem->unknown_ae_ << 3) + elem->unknown_be_;
            if (kind == 2) {
                x = 0xd4;
                int sum = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
                if (sum == 0)
                    y = 0x57;
                else if (sum == 1)
                    y = 0x65;
            }
            func_ov023_021e3304(func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]), x - 8, y - 2);
        }
    }
    if (self->state_ == 0) {
        short y = self->kind_ * 0x18 + 4;
        void* cursor = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        func_ov023_021e3304(cursor, 0x74, y);
    }
}
