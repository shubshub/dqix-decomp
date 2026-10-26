#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215e644 func_ov002_0215f7ac
#endif

struct Struct_ov002_0216c9fb {
    signed char v[4];
};

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void *GameState_GetParty(GameState *gameState);
extern "C" void func_020dc4d0(signed char *out, signed char *outCount);
extern "C" void func_ov002_0215be00(void *obj, int val, int a2, int a3);
extern "C" void func_ov002_0215e644(unsigned char *obj, void *buf, int a);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void *, void *, int, int, int, int, int);
#define data_ov002_0216c9fb data_ov002_0216d058
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void *, void *, int, int, bool, bool, void *, bool);
#endif
struct StructA0205d5d0;
extern "C" void Window_SetPaneText(StructA0205d5d0*, int, int, int, unsigned char);
struct Struct_0205d81c;
extern "C" unsigned char * func_0205d81c(Struct_0205d81c*, int);
extern "C" void func_0204f160(unsigned char* obj, int value, int b);
extern "C" void func_0204ecb4(unsigned char *wnd, int a, int b, int w, int h, signed char *arg5);
struct Struct_0204fbf8_2;
extern "C" void func_0204fbf8(Struct_0204fbf8_2*);
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);

extern Struct_ov002_0216c9fb data_ov002_0216c9fb;

// USA: func_ov002_0215e44c
extern "C" ARM void func_ov002_0215e44c(unsigned char *self) {
    GameState_GetParty(GameState::GetInstance());
    signed char count    = 0;
    Struct_ov002_0216c9fb slots = data_ov002_0216c9fb;
    func_020dc4d0(slots.v, &count);
    int x = 0x10;
    x -= count * 4;
    for (signed char i = 0; i < count; i++) {
        *(signed char *) (self + RG(0x1c20, 0x1ae8)) = slots.v[i];
        func_ov002_0215be00(self, (unsigned char) (*(signed char *) (self + RG(0x1c20, 0x1ae8)) + RG(0x2c, 0x2f)), (short) x, 3);
        memset(*(void **) (self + RG(0x1bd0, 0x1a98)), 0, RG(0x960, 0x800));
        func_ov002_0215e644(self, *(void **) (self + RG(0x1bd0, 0x1a98)), 0);
#if defined(jpn)
        Window_OpenPane(self + 0xe20, *(void **) (self + 0x1a98), 0, 0, 0, 1, 0);
#else
        Window_OpenPane(self + 0x2c8 + 0xc00, *(void **) (self + 0x1bd0), 0, 0, false, false, 0, false);
#endif
        unsigned char key = (unsigned char) (*(signed char *) (self + RG(0x1c20, 0x1ae8)) + RG(0x2c, 0x2f));
        if ((unsigned char) (key + RG(0xd4, 0xd1)) <= 3) {
#if !defined(jpn)
            Window_SetPaneText((StructA0205d5d0*)(self + 0x2c8 + 0xc00), key, (int)(*(void **) (self + 0x1bd0)), 1, 0);
#endif
            unsigned char *elem = func_0205d81c((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), key);
            if (elem != 0) {
                short var6 = *(short *) (elem + 0xac);
                short var7 = *(short *) (elem + 0xae);
                short var8 = *(short *) (elem + 0xa8);
                short var9 = *(short *) (elem + 0xaa);
                func_0204f160(elem, *(int *) (elem + 0xa0), key);
                func_0204ecb4(elem, var6, var7, var8, var9, 0);
                func_0204fbf8((Struct_0204fbf8_2*)elem);
            }
        }
        x += 8;
    }
    for (int j = 0; j < count; j++) {
        *(signed char *) (self + RG(0x1c20, 0x1ae8)) = slots.v[j];
        Window_SetPanePalette((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), (unsigned char) (*(signed char *) (self + RG(0x1c20, 0x1ae8)) + RG(0x2c, 0x2f)), (unsigned short) (*(signed char *) (self + RG(0x1c20, 0x1ae8)) + 6));
    }
    *(signed char *) (self + RG(0x1c20, 0x1ae8)) = -1;
}
