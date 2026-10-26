#include <globaldefs.h>

struct Obj0205e9f4;

extern "C" void SoundPlayer_Init(void* obj);
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);
extern "C" void func_0205e944(void*, int);

struct Obj_0205e88c {
    char pad0[0xb0];
    int unknown_b0_;
    short unknown_b4_;
    char pad1[0xb8 - 0xb6];
    int fb8;
    short unknown_bc_;
    char pad2[0xc0 - 0xbe];
    int fc0;
    short fc4;
};

// Main, originally InitDisplayState0205e88c (USA 0x0205e88c, EUR 0x0205e89c, JPN 0x0205fb78)
extern "C" ARM void SePlayer_Init(struct Obj_0205e88c* a) {
    SoundPlayer_Init(a);
    a->unknown_b0_ = 0;
    a->unknown_b4_ = -1;
    a->fb8 = 0;
    a->unknown_bc_ = -1;
    a->fc0 = 0;
    a->fc4 = -1;
    func_0205e944(a, 0x7f);
    func_0205e9f4((struct Obj0205e9f4*)a, 3);
}
