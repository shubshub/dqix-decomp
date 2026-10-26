#include "globaldefs.h"
#include "World/Object3D.h"

struct Struct_ov014_02184a64_4 {
    char unknown[0x13];
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
};
struct Struct_ov014_02184a64 {
    unsigned int count : 10;
    unsigned int special : 1;
    unsigned int unknown : 21;
};
struct Struct_ov014_02184a64_2 {
    char unknown_0_[0x14];
    int x, y;
    char unknown_1c_[0xc];
};
struct Struct_ov014_02184a64_3 {
    void* unknown_0_;
    void* list;
    Struct_ov014_02184a64_2* items;
    char unknown_c_[0x34];
    Object3D* model;
    void* unknown44;
    Struct_ov014_02184a64_4* monster;
    Struct_ov014_02184a64_4* unknown_4c_;
    Struct_ov014_02184a64* record;
    Struct_ov014_02184a64* unknown_54_;
    void* labels;
    char unknown_5c_[0x20];
    unsigned char state;
    char unknown_7d_[4];
    unsigned char flags;
    char unknown_82_[0xe];
    unsigned char unknown_90_[3];
    unsigned char unknown_93_;
    unsigned char currentIcon;
};
extern "C" {
extern "C" void func_ov023_021e2bdc(void*, short, short*, short*);
void SpriteContext_DrawSprite(void*, void*);
extern const short data_ov014_0218948c[6];
extern const short data_ov014_0218948e[6];
extern const short data_ov014_02189478[3];
}

extern "C" ARM void func_ov014_02184a64(Struct_ov014_02184a64_3* state) {
    if (!state->state) return;
    if (!state->monster || !state->record) return;
    int var0 = state->monster->unknown_13_1_;
    if (!var0) return;
    int first = 0, second = 0;
    if (state->flags & 0x20) {
        if (state->unknown_4c_ && state->unknown_4c_->unknown_13_1_) first = 1;
        if (state->unknown_54_ && state->unknown_54_->special) second = 1;
    } else {
        if (var0) first = 1;
        if (state->record->special) second = 1;
    }
    if (first || second) {
        for (int i = 0; i < 3; ++i) {
            short x = 0, y = 0;
            int visible = i == 2 ? second : first;
            if (visible) {
                func_ov023_021e2bdc(state->labels, data_ov014_02189478[i], &x, &y);
                if (state->unknown_90_[i]) {
                    x += data_ov014_0218948c[2*i];
                    y += data_ov014_0218948e[2*i];
                }
                Struct_ov014_02184a64_2* item = &state->items[i];
                item->x = x << 12;
                item->y = y << 12;
                if (state->currentIcon) SpriteContext_DrawSprite(state->list, &state->items[i]);
            }
        }
    }
    if ((state->flags & 4) && state->model) state->model->Draw(true);
}
