#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct SePlayer;

struct EquipmentMenu {
    char unk_0[LOW_REGION(0x3d22, 0x3daa)];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3dbc - 0x3dab];
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int flags_;
    char unknown_3dd0_[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

extern int g_sePlayer;

extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);

// USA: func_ov005_02158560
extern "C" ARM int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent) {
    if (kind == self->kind_)
        return 0;
    if (silent == 0)
        SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
    self->unknown_3dbe_ = self->kind_;
    self->unknown_3dbf_ = self->page_;
    self->pages_[self->kind_] = self->page_;
    self->kind_ = kind;
    self->page_ = self->pages_[self->kind_];
    self->flags_ |= 0x800 | 0x40;
    self->unknown_3daa_ = 0;
    return 1;
}
