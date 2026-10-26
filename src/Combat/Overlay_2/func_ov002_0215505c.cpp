#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>


struct Struct020dfc40;
struct InitTarget0205cfd4;
struct BackgroundGraphics;
struct Struct020a9ea4;

struct Struct_ov002_0215505c {
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

extern "C" void *NameText_Clear(void *p);
struct Struct_ov002_0215505c_2;
extern "C" void func_ov023_021e1318(Struct_ov002_0215505c_2*);
extern "C" void KeyTable_Reset(struct Struct020dfc40 *s);
extern "C" void func_02074af4(void *state);
extern "C" void Window_Init(struct InitTarget0205cfd4 *t);
extern "C" void Background_Init(struct BackgroundGraphics *l);
extern "C" void WindowPane_Init(void *p);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" int GameState_GetOwnPartyOrder(char *obj, void *dst);
extern "C" char *Scenario_GetInstance(void);
extern "C" unsigned short func_0206e384(unsigned char *obj);
extern "C" short func_0206e3d4(int unused, int index);
extern "C" void func_ov002_0215b234(char *self);
extern "C" void func_020a9ea4(struct Struct020a9ea4 *s);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov002_0215b814(char *base);

extern "C" unsigned char data_ov002_0216d3ac;

#define RESET(off) ((SafeAllocator *) (self + (off)))->ResetAllocatorPointer()
#define S16(off) (*(short *) (self + (off)))
#define S32(off) (*(int *) (self + (off)))
#define U8(off) (*(unsigned char *) (self + (off)))
#define S8(off) (*(signed char *) (self + (off)))

// USA: func_ov002_0215505c
extern "C" ARM void func_ov002_0215505c(char *self) {
#if defined(jpn)
    unsigned char buf[4];
    RESET(0x7f0);
    RESET(0x7dc);
    RESET(0x7b4);
    RESET(0x7c8);
    RESET(0x7a0);
    RESET(0x78c);
    RESET(0x774);
    func_ov023_021e1318((Struct_ov002_0215505c_2*)(self + 0x768));
    RESET(0x804);
    KeyTable_Reset((struct Struct020dfc40 *) (self + 0x8));
    U8(0x30) = 0;
    U8(0x31) = 0;
    func_02074af4(self + 0x20);
    S32(0x34)                            = (*(volatile unsigned int *) 0x4000000 & 0x1f00) >> 8;
    *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1a6c) = -1;
    }
    Window_Init((struct InitTarget0205cfd4 *) (self + 0xe20));
    for (int i = 0; i < 3; i++) {
        Background_Init((struct BackgroundGraphics *) (self + 0xedc + i * 0x20));
    }
    for (int i = 0; i < 12; i++) {
        WindowPane_Init(self + 0xf3c + i * 0xe0);
    }
    S32(0x19bc) = 0;
    S32(0x19c0) = 0;
    for (int i = 0; i < 4; i++) {
        memset(self + 0x19c8 + i * 0x10, 0, 4);
        memset(self + 0x1a08 + i * 0x18, 0, 4);
    }
    S32(0x1a68) = 0;
    S32(0x1a80) = 0;
    S32(0x1a84) = 0x2e;
    S32(0x1a88) = 0;
    S32(0x1a8c) = -1;
    S32(0x228c) = -1;
    S32(0x1a90) = 0;
    S32(0x1a94) = 0;
    S32(0x1a98) = 0;
    S32(0x1a9c) = 0;
    S32(0x1aa0) = 0;
    S32(0x1aa4) = 0;
    for (int i = 0; i < 2; i++) {
        *(int *) (self + i * 4 + 0x22c0) = 0;
    }
    S16(0x1aa8)         = 0;
    S16(0x1aaa)         = -1;
    S16(0x1aac)         = -1;
    S16(0x1aae)         = -1;
    S16(0x1ab0)         = -1;
    S16(0x1ab2)         = -1;
    S16(0x1ab4)         = -1;
    S16(0x1ab6)         = -1;
    S16(0x1ab8)         = -1;
    S16(0x1aba)         = -1;
    S16(0x1abc)         = -1;
    S16(0x1abe)         = -1;
    S16(0x1ac0)         = -1;
    S16(0x1ac2)         = -1;
    S16(0x1ac4)         = -1;
    S16(0x1ac6)         = -1;
    S16(0x1ac8)         = 1;
    S16(0x1aca)         = -1;
    S16(0x1acc)         = -1;
    S16(0x1ace)         = -1;
    S16(0x1ad0)         = -1;
    U8(0x2288)          = 0;
    U8(0x2289)          = 0;
    S16(0x1ad2)         = 0;
    S16(0x1ad4)         = 0;
    S16(0x1ad6)         = 0;
    S16(0x1ad8)         = 0;
    S16(0x1ada)         = 0;
    S16(0x1adc)         = 0;
    S16(0x1ade)         = 0;
    S16(0x1ae0)         = 0;
    S32(0x1ae4)         = 0;
    U8(0x1b70)          = 0;
    U8(0x1b71)          = 0;
    U8(0x1b74)          = 0;
    U8(0x1b72)          = 0;
    U8(0x1b73)          = 0;
    U8(0x1b75)          = 0;
    U8(0x1b86)          = 0;
    U8(0x1b89)          = 0;
    S32(0x2280)         = 0;
    S32(0x2284)         = 0;
    U8(0x228a)          = 0;
    S32(0x2290)         = 0;
    S32(0x2294)         = 0;
    S32(0x2298)         = 0;
    S32(0x229c)         = 0;
    U8(0x22a0)          = 0;
    U8(0x22a1)          = 0;
    U8(0x22a2)          = 0;
    S8(0x1ae8)          = -1;
    S8(0x1ae9)          = -1;
    S16(0x1aea)         = -1;
    S16(0x1aec)         = -1;
    S16(0x1aee)         = -1;
    S16(0x1af2)         = -1;
    S16(0x1af0)         = S16(0x1af2);
    U8(0x1af6)          = 0;
    U8(0x1af7)          = 0;
    U8(0x1af8)          = 0;
    U8(0x1af9)          = 0;
    U8(0x1afa)          = 0;
    data_ov002_0216d3ac = 0;
    U8(0x1afb)          = 0;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1b00) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1b18) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(unsigned char *) (self + i + 0x1b2c) = 0;
    }
    U8(0x1b31)                              = 0;
    U8(0x1b47)                              = 0;
    U8(0x1b48)                              = 0;
    ((Struct_ov002_0215505c *) (self + 0x1b49))->b0 = 0;
    U8(0x1b3c)                              = 0;
    S32(0x1b38)                             = 0;
    U8(0x1b3d)                              = 2;
    U8(0x1b3e)                              = 0;
    U8(0x1b3f)                              = 0;
    S8(0x1b37)                              = 0;
    GameState *gs                           = GameState::GetInstance();
    S32(0x1afc)                             = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int i = 0; i < S32(0x1afc); i++) {
        *(int *) (self + i * 4 + 0x1b00) = buf[i];
        GameObject *m                    = gs->GetPartyMemberByIndex(buf[i]);
        if (m != 0 && *(int *) ((char *) m + 0x1b8) == 0) {
            *(unsigned char *) (self + S8(0x1b37) + 0x1b32) = buf[i];
            S8(0x1b37)++;
        }
    }
    S32(0x1b14) = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int i = 0; i < S32(0x1b14); i++) {
        *(int *) (self + i * 4 + 0x1b18) = buf[i];
    }
    *(int *) (self + S32(0x1b14) * 4 + 0x1b18) = 4;
    S32(0x1b14) += 1;
    U8(0x1b87)        = 0;
    U8(0x22a8)        = 0;
    U8(0x22aa)        = 0;
    char *x           = Scenario_GetInstance();
    unsigned int bits = (func_0206e384((unsigned char *) x) << 16) | 0xffff;
    S32(0x22b0)       = 0;
    for (int i = 0; i < 0x20; i++) {
        if (bits & 1) {
            short n = func_0206e3d4((int) x, (short) (i + 1));
            *(unsigned int *) (self + 0x22b0) |= 1 << (n - 1);
        }
        bits >>= 1;
    }
    U8(0x22b4) = 0;
    memset(self + 0x1b40, -1, 7);
    U8(0x22ab)  = 0;
    S32(0x22ac) = 0;
    U8(0x22b5)  = 0;
    U8(0x22b6)  = 0;
    U8(0x22b7)  = 0;
    S16(0x22b8) = -1;
    U8(0x22ba)  = 0;
    U8(0x22bc)  = 0;
    U8(0x22bd)  = 0;
    U8(0x2351)  = 0;
    U8(0x2352)  = 0;
    U8(0x2353)  = 0;
    memset(self + 0x2354, 0, 0xc);
    S32(0x2360) = 0;
    func_ov002_0215b234(self);
    RESET(0x774);
    RESET(0x78c);
    RESET(0x7a0);
    RESET(0x7b4);
    RESET(0x7c8);
    RESET(0x7dc);
    RESET(0x7f0);
    func_020a9ea4((struct Struct020a9ea4 *) (self + 0x22c8));
    for (unsigned char j = 0; j < 0x20; j++) {
        *(int *) (self + j * 4 + 0x22d0) = 0;
    }
    U8(0x2350)  = 0;
    S16(0x2370) = 0;
    S16(0x2372) = 0;
    S32(0x2374) = 0;
    func_ov016_0218b5c0(1, -1);
    U8(0x22be) = 0;
    U8(0x22bf) = 0;
    func_ov002_0215b814(self);
#else
    unsigned char buf[4];
    NameText_Clear(self + 8);
    NameText_Clear(self + 0x14);
    RESET(0x88c);
    RESET(0x878);
    RESET(0x850);
    RESET(0x864);
    RESET(0x83c);
    RESET(0x828);
    RESET(0x810);
    func_ov023_021e1318((Struct_ov002_0215505c_2*)(self + 0x804));
    RESET(0x8a0);
    KeyTable_Reset((struct Struct020dfc40 *) (self + 0x20));
    U8(0x48) = 0;
    U8(0x49) = 0;
    func_02074af4(self + 0x38);
    S32(0x4c)                            = (*(volatile unsigned int *) 0x4000000 & 0x1f00) >> 8;
    *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1ba4) = -1;
    }
    Window_Init((struct InitTarget0205cfd4 *) (self + 0x2c8 + 0xc00));
    for (int i = 0; i < 3; i++) {
        Background_Init((struct BackgroundGraphics *) (self + 0x384 + 0xc00 + i * 0x20));
    }
    for (int i = 0; i < 12; i++) {
        WindowPane_Init(self + 0x3e4 + 0xc00 + i * 0xe0);
    }
    S32(0x1a64) = 0;
    S32(0x1a68) = 0;
    for (int i = 0; i < 4; i++) {
        memset(self + 0xa70 + 0x1000 + i * 0x10, 0, 4);
        memset(self + 0xab0 + 0x1000 + i * 0x3c, 0, 4);
    }
    S32(0x1ba0) = 0;
    S32(0x1bb8) = 0;
    S32(0x1bbc) = 0x2b;
    S32(0x1bc0) = 0;
    S32(0x1bc4) = -1;
    S32(0x2458) = -1;
    S32(0x1bc8) = 0;
    S32(0x1bcc) = 0;
    S32(0x1bd0) = 0;
    S32(0x1bd4) = 0;
    S32(0x1bd8) = 0;
    S32(0x1bdc) = 0;
    for (int i = 0; i < 2; i++) {
        *(int *) (self + i * 4 + 0x2490) = 0;
    }
    S16(0x1be0)         = 0;
    S16(0x1be2)         = -1;
    S16(0x1be4)         = -1;
    S16(0x1be6)         = -1;
    S16(0x1be8)         = -1;
    S16(0x1bea)         = -1;
    S16(0x1bec)         = -1;
    S16(0x1bee)         = -1;
    S16(0x1bf0)         = -1;
    S16(0x1bf2)         = -1;
    S16(0x1bf4)         = -1;
    S16(0x1bf6)         = -1;
    S16(0x1bf8)         = -1;
    S16(0x1bfa)         = -1;
    S16(0x1bfc)         = -1;
    S16(0x1bfe)         = -1;
    S16(0x1c00)         = 1;
    S16(0x1c02)         = -1;
    S16(0x1c04)         = -1;
    S16(0x1c06)         = -1;
    S16(0x1c08)         = -1;
    U8(0x2454)          = 0;
    U8(0x2455)          = 0;
    S16(0x1c0a)         = 0;
    S16(0x1c0c)         = 0;
    S16(0x1c0e)         = 0;
    S16(0x1c10)         = 0;
    S16(0x1c12)         = 0;
    S16(0x1c14)         = 0;
    S16(0x1c16)         = 0;
    S16(0x1c18)         = 0;
    S32(0x1c1c)         = 0;
    U8(0x1cac)          = 0;
    U8(0x1cad)          = 0;
    U8(0x1cb0)          = 0;
    U8(0x1cae)          = 0;
    U8(0x1caf)          = 0;
    U8(0x1cb1)          = 0;
    U8(0x1cc2)          = 0;
    U8(0x1cc5)          = 0;
    S32(0x2448)         = 0;
    S32(0x244c)         = 0;
    S32(0x2450)         = 0;
    U8(0x2456)          = 0;
    S16(0x245c)         = 0;
    S32(0x2460)         = 0;
    S32(0x2464)         = 0;
    S32(0x2468)         = 0;
    S32(0x246c)         = 0;
    U8(0x2470)          = 0;
    U8(0x2471)          = 0;
    U8(0x2472)          = 0;
    S8(0x1c20)          = -1;
    S8(0x1c21)          = -1;
    S16(0x1c22)         = -1;
    S16(0x1c24)         = -1;
    S16(0x1c26)         = -1;
    S16(0x1c2a)         = -1;
    S16(0x1c28)         = S16(0x1c2a);
    U8(0x1c2e)          = 0;
    U8(0x1c2f)          = 0;
    U8(0x1c30)          = 0;
    U8(0x1c31)          = 0;
    U8(0x1c32)          = 0;
    data_ov002_0216d3ac = 0;
    U8(0x1c33)          = 0;
    U8(0x1c34)          = 0;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1c3c) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1c54) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(unsigned char *) (self + i + 0x1c68) = 0;
    }
    U8(0x1c6d)                              = 0;
    U8(0x1c83)                              = 0;
    U8(0x1c84)                              = 0;
    ((Struct_ov002_0215505c *) (self + 0x1c85))->b0 = 0;
    U8(0x1c78)                              = 0;
    S32(0x1c74)                             = 0;
    U8(0x1c79)                              = 2;
    U8(0x1c7a)                              = 0;
    U8(0x1c7b)                              = 0;
    S8(0x1c73)                              = 0;
    GameState *gs                           = GameState::GetInstance();
    S32(0x1c38)                             = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int i = 0; i < S32(0x1c38); i++) {
        *(int *) (self + i * 4 + 0x1c3c) = buf[i];
        GameObject *m                    = gs->GetPartyMemberByIndex(buf[i]);
        if (m != 0 && *(int *) ((char *) m + 0x1c4) == 0) {
            *(unsigned char *) (self + S8(0x1c73) + 0x1c6e) = buf[i];
            S8(0x1c73)++;
        }
    }
    S32(0x1c50) = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int i = 0; i < S32(0x1c50); i++) {
        *(int *) (self + i * 4 + 0x1c54) = buf[i];
    }
    *(int *) (self + S32(0x1c50) * 4 + 0x1c54) = 4;
    S32(0x1c50) += 1;
    U8(0x1cc3)        = 0;
    U8(0x2478)        = 0;
    U8(0x247a)        = 0;
    char *x           = Scenario_GetInstance();
    unsigned int bits = (func_0206e384((unsigned char *) x) << 16) | 0xffff;
    S32(0x2480)       = 0;
    for (int i = 0; i < 0x20; i++) {
        if (bits & 1) {
            short n = func_0206e3d4((int) x, (short) (i + 1));
            *(unsigned int *) (self + 0x2480) |= 1 << (n - 1);
        }
        bits >>= 1;
    }
    U8(0x2484) = 0;
    memset(self + 0x7c + 0x1c00, -1, 7);
    U8(0x247b)  = 0;
    S32(0x247c) = 0;
    U8(0x2485)  = 0;
    U8(0x2486)  = 0;
    U8(0x2487)  = 0;
    S16(0x2488) = -1;
    U8(0x248a)  = 0;
    U8(0x248c)  = 0;
    U8(0x248d)  = 0;
    U8(0x2521)  = 0;
    U8(0x2522)  = 0;
    U8(0x2523)  = 0;
    memset(self + 0x124 + 0x2400, 0, 0xc);
    S32(0x2530) = 0;
    S32(0x2534) = 0;
    S32(0x2538) = 0;
    func_ov002_0215b234(self);
    RESET(0x810);
    RESET(0x828);
    RESET(0x83c);
    RESET(0x850);
    RESET(0x864);
    RESET(0x878);
    RESET(0x88c);
    func_020a9ea4((struct Struct020a9ea4 *) (self + 0x98 + 0x2400));
    for (unsigned char j = 0; j < 0x20; j++) {
        *(int *) (self + j * 4 + 0x24a0) = 0;
    }
    U8(0x2520)  = 0;
    S16(0x2548) = 0;
    S16(0x254a) = 0;
    S32(0x254c) = 0;
    func_ov016_0218b5c0(1, -1);
    U8(0x248e) = 0;
    U8(0x248f) = 0;
    func_ov002_0215b814(self);
#endif
}
