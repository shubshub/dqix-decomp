#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_ov005_02153954 {
    char unknown_0_[LOW_REGION(0x3d22, 0x3daa)];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3dbc - 0x3dab];
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3df4 - 0x3dd0];
    unsigned char unknown_3df4_[8];
};

struct SePlayer;

extern "C" char g_sePlayer[];

void SePlayer_Play(SePlayer* sound, int effect, int unk);

// USA: func_ov005_021585fc
extern "C" ARM int func_ov005_021585fc(EquipmentMenu* self, int direction) {
    unsigned char last = self->pageCounts_[self->kind_] - 1;
    signed char page = self->page_;
    signed char next = page + direction;
    if (next < 0)
        next = last;
    if (next > last)
        next = 0;
    int changed = 1;
    if (next == page)
        changed = 0;
    if (changed) {
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
        if (direction < 0)
            self->flags_ |= 0x20000;
        else
            arg0->unknown_3dcc_ |= 0x40000;
        arg0->unknown_3dbe_ = arg0->unknown_3dbc_;
        arg0->unknown_3dbf_ = arg0->unknown_3dbd_;
        arg0->unknown_3dbd_ = var2;
        arg0->unknown_3dcc_ |= 0x40;
        arg0->unknown_3daa_ = 0;
    }
    return var3;
}
