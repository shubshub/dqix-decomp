#if defined(jpn)
#define R(j,u) (j)
#define func_0208b610 func_0208bf04
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void func_ov015_0218f22c(void* obj);

struct Struct_ov015_02190348 { int x, y, z; };
extern "C" void func_0208b610(struct Struct_ov015_02190348 v, unsigned short p, int a, int b, int c, short d);

struct Struct_ov015_02190348_2 { void* payload; struct Struct_ov015_02190348_2* next; };

struct Struct_ov015_02190348_3 {
    char pad0[0x2c];
    struct Struct_ov015_02190348_2* list;
    char pad1[0x19c - 0x2c - 4];
    unsigned char unknown_19c_;
    unsigned char unknown_19d_;
};

// USA: func_ov015_02190348
extern "C" ARM void func_ov015_02190348(struct Struct_ov015_02190348_3* obj) {
    if (obj->unknown_19d_) {
        *(volatile unsigned int*)0x040004a4 = 0x1f00c0;
        *(volatile unsigned int*)0x04000444 = 0;
        *(volatile unsigned int*)0x04000500 = 1;
        *(volatile unsigned int*)0x04000480 = 0x5294;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x04000504 = 0;
        *(volatile unsigned int*)0x04000448 = 1;
    }
    if (obj->unknown_19c_) {
        GameState* bs = GameState::GetInstance();
        void* f3b0 = bs->GetCamera();
        func_0208b610(*(struct Struct_ov015_02190348*)((char*)f3b0 + 0x10), 0x3dff, 0x800, 0x800, 0x800, 0);
    }
    struct Struct_ov015_02190348_2* node = obj->list;
    while (node != 0) {
        func_ov015_0218f22c(node->payload);
        node = node->next;
    }
}
