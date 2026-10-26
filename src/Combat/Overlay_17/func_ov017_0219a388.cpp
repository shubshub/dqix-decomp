#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* dst, unsigned int size);
extern "C" int func_02039730(void* unused, int index);
extern "C" void func_ov017_0219a544(unsigned char* a, char* buf, int type, int value);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

extern "C" int Window_Update(void* objPtr, int val);
extern "C" void func_ov017_0219a644(void* base, int value);

struct Struct_ov017_021d6448 { short v[4]; };
struct Struct_ov017_021d6444 { unsigned char v[4]; };
struct Struct_ov017_021d6484 { int v[7]; };

extern struct Struct_ov017_021d6448 data_ov017_021d6458;
extern struct Struct_ov017_021d6448 data_ov017_021d6450;
extern struct Struct_ov017_021d6448 data_ov017_021d6448;
extern struct Struct_ov017_021d6444 data_ov017_021d6444;
extern struct Struct_ov017_021d6484 data_ov017_021d6484;

struct Struct_ov017_0219a388 {
    unsigned char pad0[0xa0];
    short x;
    short unknown_a2_;
    short y;
    short width;
    short unknown_a8_;
    short unknown_aa_;
    short field_ac;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char type;
    unsigned char unknown_b2_[3];
    unsigned char unknown_b5_;
};

// USA: func_ov017_0219a388
extern "C" ARM void func_ov017_0219a388(unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0xa90};
#else
 enum {regionalOffset0=0xcb0};
#endif
    GameState* gs = GameState::GetInstance();
    GameObject* protagonist = gs->GetProtagonist();
    struct Struct_ov017_021d6448 xs = data_ov017_021d6458;
    struct Struct_ov017_021d6448 ys = data_ov017_021d6450;
    struct Struct_ov017_021d6448 widths = data_ov017_021d6448;
    struct Struct_ov017_021d6444 types = data_ov017_021d6444;
    struct Struct_ov017_021d6484 indices = data_ov017_021d6484;
    char buf[0x80];
    Struct_ov017_0219a388* win = *(Struct_ov017_0219a388**)(base + 0x3000 + regionalOffset0);
    int i;

    for (i = 0; i < 4; i++) {
        win->x = xs.v[i];
        win->unknown_a2_ = 2;
        win->y = ys.v[i];
        win->width = widths.v[i];
        win->unknown_a8_ = 2;
        win->unknown_aa_ = 2;
        win->field_ac = 0xa;
        win->unknown_ae_ = 0xb;
        unsigned char type = types.v[i];
        win->type = type;
        win->unknown_b5_ = 1;
        __clear(buf, 0x80);
        func_ov017_0219a544(base, buf, type, (signed char)func_02039730(protagonist, indices.v[i]));
#if defined(jpn)
        Window_OpenPane(win, buf, 0, 0, 0, 1, 0);
#else
        Window_OpenPane(win, buf, 0, 0, 0, 1, 0, 0);
#endif

        Window_Update(win, gs->GetTickCount());
    }
    func_ov017_0219a644(base, 0xff);
}
