#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov013_021864f0 func_ov013_02187820
#endif
#include "GameState/GameState.h"

struct Struct0205d888;
extern "C" void* Window_GetTopPane(struct Struct0205d888* p);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_0205c904(unsigned char* p, int val);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

struct Struct_0205bc10;
extern "C" void func_0205bc10(struct Struct_0205bc10* s);

struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);

extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);

struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);

struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

extern "C" void GridCursor_SetSelectedIndex(void* s, int n);
extern "C" int Window_Update(void* p, int val);
extern "C" void func_ov013_02186bd4(void* obj);
extern "C" void func_ov013_02184d80(void* obj);
extern "C" void func_ov013_02186160(void* obj);
extern "C" void func_ov013_0218678c(void* obj);
extern "C" void func_ov013_021864f0(void* obj);
extern "C" void func_ov013_0218683c(void* obj);
extern "C" void func_ov013_02186590(void* obj);
extern "C" void func_ov013_021846a0(void* obj);

// USA: func_ov013_021847c4
extern "C" ARM unsigned char func_ov013_021847c4(void* obj, int param1) {
    unsigned char* o = (unsigned char*)obj;
    GameState* bs;
    void* last;
    int i;

    *(int*)(o + 0x14) = param1;
    bs = GameState::GetInstance();
    *(int*)(o + R(0x5d0,0x644)) = bs->GetTickCount();

    last = Window_GetTopPane((struct Struct0205d888*)(o + R(0x34,0x38)));
    if (last != 0) {
        if (WindowPane_IsReady((unsigned char*)last) != 0) {
            if ((((unsigned char*)last)[0xc5] & 2) == 0) {
                TouchGrid_SetTouchedCell(o + R(0x38,0x3c), -1);
            }
        }
    }

    *(int*)(o + R(0x5d4,0x648)) = Window_Update(o + R(0x34,0x38), *(int*)(o + R(0x5d0,0x644)));
    func_0205c904(o + R(0x3d0,0x3d4), *(int*)(o + R(0x5d0,0x644)));

    {
        int g = MessageSystem_GetInstance();
        struct Container0205a330* c = *(struct Container0205a330**)(g + R(0x230,0x2e0));
        if (c != 0) {
            SpriteEntryList_AdvanceAnimations(c, bs->GetTickCount());
        }
    }

    if (o[R(0x5cb,0x63f)] != 0) {
        if (o[R(0x5cc,0x640)] != 0) {
            func_0205bc10((struct Struct_0205bc10*)(o + R(0x38,0x3c)));
        }
        if (o[R(0x5c8,0x63c)] == 1) {
            o[R(0xe5,0xe9)] = 0;
            *(int*)(o + R(0x3c,0x40)) = 1;
            *(int*)(o + R(0x8c,0x90)) = 1;
            GridCursor_SetDimensions((struct GridCursor*)(o + R(0x38,0x3c)), 1, 6, 0);
            GridCursor_SetDimensions((struct GridCursor*)(o + R(0x88,0x8c)), 1, 6, 0);
            GridCursor_SetCount((struct GridCursor*)(o + R(0x38,0x3c)), 6);
            GridCursor_SetCount((struct GridCursor*)(o + R(0x88,0x8c)), 6);
            i = *(int*)(o + R(0x5e4,0x65c));
            GridCursor_SelectIfValid((struct Struct_0205bcdc*)(o + R(0x38,0x3c)), i);
            GridCursor_SetSelectedIndex(o + R(0x88,0x8c), i);
            func_ov013_02186bd4(obj);
        }
        if (o[R(0x5c8,0x63c)] == 3 && o[R(0x5cc,0x640)] != 0) {
            o[R(0xe5,0xe9)] = 3;
            *(int*)(o + R(0x3c,0x40)) = 1;
            *(int*)(o + R(0x8c,0x90)) = 1;
            GridCursor_SetDimensions((struct GridCursor*)(o + R(0x38,0x3c)), 1, 2, 0);
            GridCursor_SetDimensions((struct GridCursor*)(o + R(0x88,0x8c)), 1, 2, 0);
            GridCursor_SetCount((struct GridCursor*)(o + R(0x38,0x3c)), 2);
            GridCursor_SetCount((struct GridCursor*)(o + R(0x88,0x8c)), 2);
            GridCursor_SelectIfValid((struct Struct_0205bcdc*)(o + R(0x38,0x3c)), 0);
            GridCursor_SetSelectedIndex(o + R(0x88,0x8c), 0);
        }
        o[R(0x5cb,0x63f)] = 0;
        return o[R(0x5c8,0x63c)];
    }

    switch (o[R(0x5c8,0x63c)]) {
        case 0:
            func_ov013_02184d80(obj);
            break;
        case 1:
            func_ov013_02186160(obj);
            break;
        case 2:
            if (o[R(0x5cc,0x640)] != 0) func_ov013_0218678c(obj);
            else func_ov013_021864f0(obj);
            break;
        case 3:
        case 4:
            if (o[R(0x5cc,0x640)] != 0) func_ov013_0218683c(obj);
            else func_ov013_02186590(obj);
            break;
        case 5:
            func_ov013_021846a0(obj);
            break;
    }

    for (i = 0; i < 4; i++) {
        unsigned char* p = o + i;
        unsigned char v = p[R(0x5c4,0x638)];
        struct Struct_0205d81c* s = (struct Struct_0205d81c*)(o + R(0x34,0x38));
        Window_SetPanePalette(s, (unsigned char)i, v);
    }

    o[R(0x5cb,0x63f)] = (o[R(0x5c8,0x63c)] != o[R(0x5c9,0x63d)]) ? 1 : 0;
    o[R(0x5c9,0x63d)] = o[R(0x5c8,0x63c)];
    return o[R(0x5c8,0x63c)];
}
