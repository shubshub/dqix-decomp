#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov008_0218aee4 func_ov008_0218bb50
#endif

struct Struct_0205d0e0 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    char unknown_aa_[0xac - 0xaa];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;

struct Struct_ov008_0218aee4 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x28 - 0x1c];
};

struct Struct_ov008_0218aee4_2 {
    char unknown_0_[0xf0];
    Struct_ov008_0218aee4 unknown_f0_[2];
};

struct Struct_ov008_0218aee4_3 {
    char unknown_0_[0x18];
    char unknown_18_[0x1f4 - 0x18];
    void* unknown_1f4_;
    Struct_ov008_0218aee4_2* unknown_1f8_;
    char unknown_1fc_[LOW_REGION(0xe95, 0xe99) - 0x1fc];
    signed char unknown_e99_;
};

Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(void* renderer, Cell0218aee4* cell);

// USA: func_ov008_0218aee4
extern "C" ARM void func_ov008_0218aee4(Struct_ov008_0218aee4_3* arg0) {
    if (arg0->unknown_e99_ != 1) {
        return;
    }
    Struct_0205d0e0* var0 = func_0205d81c((Struct_0205d81c*)arg0->unknown_18_, 0);
    if (var0 == NULL) {
        return;
    }
    short x = elem->tileX * 8;
    short tileY = elem->tileY;
    Cursor0218aee4* cursor = self->cursor;
    short width = elem->width;
    cursor->cells[0].x = (x - 1) << 12;
    short y = tileY * 8;
    cursor->cells[0].y = (y - 1) << 12;
    SpriteContext_DrawSprite(self->renderer, &cursor->cells[0]);
    cursor = self->cursor;
    cursor->cells[1].x = LOW_REGION((x + 0x50), (x + (short)(width * 8) - 8)) << 12;
    cursor->cells[1].y = (y - 1) << 12;
    SpriteContext_DrawSprite(self->renderer, &cursor->cells[1]);
}
