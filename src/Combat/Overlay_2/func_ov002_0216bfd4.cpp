#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Entry_0205d6a0;
struct Struct_020e28dc;
struct Struct_020e25e8;
extern "C" char *MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char *p);
extern "C" void Window_ClosePane(struct Entry_0205d6a0 *e, int a);
extern "C" void func_020e25e8(struct Struct_020e25e8 *o);
extern "C" int func_020e28dc(struct Struct_020e28dc *o);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);

// USA: func_ov002_0216bfd4
extern "C" ARM void func_ov002_0216bfd4(char *base, unsigned char mode) {
    char *g = MessageSystem_GetInstance();
    if (*(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) != 0) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
        *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
        func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)), 1);
        Window_ClosePane((struct Entry_0205d6a0 *) (base + RG(0x2c8 + 0xc00, 0xe20)), 0);
    }
    *(unsigned char *) (base + 0x1000 + RG(0xc79, 0xb3d)) = mode;
    *(unsigned char *) (base + 0x1000 + RG(0xc30, 0xaf8)) = 1;
    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80))           = RG(0x26, 0x29);
    *(int *) (base + 0x1000 + RG(0xbbc, 0xa84))           = RG(0x26, 0x29);
    int reset                                  = 0;
    int next                                   = 0;
    int var3                                 = 0;
    int force                                  = 0;
    switch (*(unsigned char *) (base + 0x1000 + RG(0xc79, 0xb3d))) {
        case 0:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x236f;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
            *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 1;
            next                                       = 1;
            *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda))          = 0;
            break;
        case 1: break;
        case 2:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0)) = 0x2371;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2)) = -1;
            next                              = 1;
            break;
        case 3:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x2372;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
            *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 1;
            next                                       = 1;
            *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda))          = 0;
            break;
        case 4:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0)) = 0x2373;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2)) = -1;
            var3                            = 1;
            next                              = 1;
            break;
        case 5:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x2377;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
            reset                                      = 1;
            var3                                     = 1;
            next                                       = 1;
            force                                      = 1;
            *(unsigned char *) (base + 0x1000 + RG(0xcc5, 0xb89)) = 1;
            break;
        case 6:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0)) = 0x2370;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2)) = -1;
            reset                             = 1;
            var3                            = 1;
            next                              = 1;
            break;
        case 7:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x2375;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
            reset                                      = 1;
            var3                                     = 1;
            next                                       = 1;
            force                                      = 1;
            *(unsigned char *) (base + 0x1000 + RG(0xcc5, 0xb89)) = 1;
            break;
        case 8: reset = 1; break;
        case 9:
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0)) = 0x2374;
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2)) = -1;
            var3                            = 1;
            next                              = 1;
            force                             = 1;
            break;
    }
    if (reset && *(void **) (base + 4) != NULL &&
        func_020e28dc(*(struct Struct_020e28dc **) (base + 4)))
    {
        func_020e25e8(*(struct Struct_020e25e8 **) (base + 4));
    }
    if (var3) {
        if (!next) {
            MessageSystem_Reset(g);
        } else if (force) {
            MessageSystem_Reset(g);
        }
        *(int *) (base + 0x1000 + RG(0xbbc, 0xa84))           = RG(9, 10);
        *(unsigned char *) (base + 0x1000 + RG(0xc30, 0xaf8)) = 0;
        if (*(unsigned char *) (base + 0x1000 + RG(0xc79, 0xb3d)) == 9) {
            *(int *) (base + 0x1000 + RG(0xbbc, 0xa84)) = 5;
        }
        if (*(unsigned char *) (base + 0x1000 + RG(0xc78, 0xb3c)) != 0) {
            *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8))   = 4;
            *(unsigned char *) (base + 0x1000 + RG(0xc78, 0xb3c)) = 0;
        }
    }
    if (next) {
        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x26, 0x29);
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
    }
}
