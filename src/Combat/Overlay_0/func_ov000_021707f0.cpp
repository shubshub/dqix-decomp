#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>

struct Struct_0205d81c;
struct ShortArrays0204c610;
struct Elem_0205d81c {
    char unknown_0_[0xac];
    short x;
    short y;
    char unknown_b0_[0x12];
    unsigned short unknown_c2_;
};
struct Struct_ov000_021707f0_2 {
    char unknown_0_[0x3b];
    unsigned char : 3;
    unsigned char active : 1;
    unsigned char mode : 4;
};
struct Struct_ov000_021707f0_3 {
    char unknown_0_[0x320];
    char drawEntry[0x14];
    int x;
    int y;
    char unknown_33c_[6];
    unsigned char size;
    char unknown_343_[3];
    unsigned char visible;
};
struct Struct_ov000_021707f0_4 {
    char storage[0x54];
};
struct Struct_ov000_021707f0_5 {
    char unknown_0_[0x11c];
    Struct_ov000_021707f0_4 unknown_11c_;
    Struct_ov000_021707f0_3* cursor;
    char unknown_174_[8];
    int unknown_17c_;
#if defined(jpn)
    char unknown_180_[0x1f98 - 0x180];
#else
    char unknown1_180_[0x1d60 - 0x180];
#endif
    signed char states[8];
    signed char unknown_1d68_;

    Struct_ov000_021707f0_4* inline_ov000_021707f0() { return &unknown_11c_; }
};
struct Struct_ov000_021707f0 {
    char unknown_0_[0x38];
    Struct_0205d81c* elements;
#if defined(jpn)
    char unknown_3c_[0x470 - 0x3c];
#else
    char unknown1_3c_[0x430 - 0x3c];
#endif
    unsigned short colors[2];
    float phase;
};

extern "C" void* func_ov000_02160f08(void*);
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c*, int);
extern "C" int WindowPane_IsReady(unsigned char*);
extern "C" void func_0204c610(ShortArrays0204c610*, int, short*, short*, short*, short*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" double func_02009424(double);
extern "C" void SpriteContext_DrawSprite(void*, void*);
struct Struct_ov000_02183488 {
    short value;
    short pad[2];
};
#if defined(jpn)
#define data_ov000_02183488 data_ov000_02184510
#define data_ov000_0218348a data_ov000_02184512
#define data_ov000_0218348c data_ov000_02184514
#endif
extern Struct_ov000_02183488 data_ov000_02183488[];
extern Struct_ov000_02183488 data_ov000_0218348a[];
extern Struct_ov000_02183488 data_ov000_0218348c[];

// USA: func_ov000_021707f0
extern "C" ARM void func_ov000_021707f0(Struct_ov000_021707f0* owner) {
    float amount;
    GameState* state = GameState::GetInstance();
    if (!state) {
        return;
    }
    GameResources* resources = state->GetResources();
    if (!resources || !resources->unknown_ptr_3718) {
        return;
    }
    void* battle = func_ov017_021b8468(resources->unknown_ptr_3718);
    if (!battle) {
        return;
    }
    Struct_ov000_021707f0_5* palette = (Struct_ov000_021707f0_5*)func_ov000_02160f08(battle);
    if (!palette) {
        return;
    }
    Struct_ov000_021707f0_4* list = palette->inline_ov000_021707f0();
    if (!list || !palette->cursor) {
        return;
    }
    Struct_ov000_021707f0_3* cursor = palette->cursor;
    if (palette->states[palette->unknown_1d68_] != 13) {
        return;
    }
    short left = 0;
    short top = 0;
    short right = 0;
    short bottom = 0;
    Elem_0205d81c* element = func_0205d81c(owner->elements, 13);
    signed char colorIndex = 0;
    short slot = 0;
    GameObject* unit = GameState::GetInstance()->GetCombatantByIndex(palette->unknown_17c_);
    if (unit) {
        Struct_ov000_021707f0_2* stats = (Struct_ov000_021707f0_2*)unit->currentStats_;
        if (stats->active) {
            if (stats->mode == 1) {
                colorIndex = 4;
                slot = 1;
            } else {
                slot = 1;
                if (stats->mode == 0) {
                    colorIndex = 0;
                }
            }
        }
    }
    if (!element || !slot) {
        return;
    }
    if (!WindowPane_IsReady((unsigned char*)element)) {
        return;
    }
    if (element->unknown_c2_) {
        return;
    }
    short x = element->x;
    short y = element->y;
    func_0204c610((ShortArrays0204c610*)element, 5, &left, &top, &right, &bottom);
    cursor->x = (left + (short)(x * 8)) << 12;
    cursor->y = (top + (short)(y * 8)) << 12;
    cursor->size = 0x7c;
    cursor->visible = 0;
    if (colorIndex) {
        float var18 = (float)func_02009424(owner->phase);
        int choice = 0;
        if (var18 >= 0.5f) {
            choice = 1;
        }
        slot = 0;
        for (; slot < 2; colorIndex += 2, ++slot) {
            int index = colorIndex + choice;
            owner->colors[slot] = data_ov000_02183488[index].value |
                (data_ov000_0218348a[index].value << 5) | (data_ov000_0218348c[index].value << 10);
        }
    } else {
        amount = (float)func_02009424(owner->phase);
        slot = 0;
        for (; slot < 2; colorIndex += 2, ++slot) {
            int index = colorIndex;
            int next = colorIndex + 1;
            short red = data_ov000_02183488[index].value +
                (int)((data_ov000_02183488[next].value - data_ov000_02183488[index].value) * amount);
            short green = data_ov000_0218348a[index].value +
                (int)((data_ov000_0218348a[next].value - data_ov000_0218348a[index].value) * amount);
            short blue = data_ov000_0218348c[index].value +
                (int)((data_ov000_0218348c[next].value - data_ov000_0218348c[index].value) * amount);
            owner->colors[slot] = red | (green << 5) | (blue << 10);
        }
    }
    CleanInvalidateCacheRange(owner->colors, 4);
    LoadToSubObjStandardPalette(owner->colors, 0x142, 4);
    SpriteContext_DrawSprite(list, cursor->drawEntry);
}
