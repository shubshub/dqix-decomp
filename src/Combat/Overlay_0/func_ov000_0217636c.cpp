#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
struct GridCursor;
struct Struct_0205bcdc;

extern "C" void Window_ClosePane(struct Entry_0205d6a0* list, int mode);
extern "C" void func_0205cef8(void* chan);
extern "C" void func_0205cf04(void* chan);
extern "C" void func_0205cf28(unsigned char* p, int a, int b, int c);
extern "C" void GridCursor_SetCount(struct GridCursor* node, int val);
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* obj, int index);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);

struct GlobalField0x1c {
#if defined(jpn)
    char unk0[0x28];
#else
    char unk0[0x5c];
#endif
    void* tileBuffer;
};
extern "C" struct GlobalField0x1c* MessageSystem_GetInstance();

#if defined(jpn)
extern "C" void Window_OpenPane(void* window, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(void* window, void* buf, int a, int b, int c, int d, int e, int f);
#endif

struct Struct_ov000_0217636c_3 {
    int unk0;
    int unk4;
};

struct Window {
    char unk0[4];
    struct Struct_ov000_0217636c_3 nodeA;
    char unknown_c_[0x54 - 0xc];
    struct Struct_ov000_0217636c_3 nodeB;
    char unknown_5c_[0xa0 - 0x5c];
    short unknown_a0_;
    short unknown_a2_;
    short tileX;
    short tileY;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_0215ab88 {
    char unk0[0x38];
    struct Window* window;
    char unk3c[0x44 - 0x3c];
    int posX;
    int unknown_48_;
};

extern "C" void func_ov000_02176500(struct Struct_ov000_0215ab88* obj, void* buf, int arg);

// USA: func_ov000_0217636c
extern "C" ARM void func_ov000_0217636c(struct Struct_ov000_0215ab88* obj, int arg) {
    struct Window* window = obj->window;
    if (window != 0) {
        int x = obj->posX;
        int y = obj->unknown_48_;
        Window_ClosePane((struct Entry_0205d6a0*)window, 1);
        func_0205cef8(window);
        func_0205cf04(window);
        func_0205cf28((unsigned char*)window, 2, 3, 0);
        GridCursor_SetCount((struct GridCursor*)&window->nodeA, 6);
        GridCursor_SetCount((struct GridCursor*)&window->nodeB, 6);
        GridCursor_SelectIfValid((struct Struct_0205bcdc*)&window->nodeA, 0);
        GridCursor_SetSelectedIndex(&window->nodeB, 0);
        window->nodeA.unk4 = 1;
        window->nodeB.unk4 = 1;
        window->unknown_a0_ = 2;
        window->unknown_a2_ = 1;
        window->tileX = (x >> 3) + 9;
        window->tileY = (y >> 3) + 1;
        window->unknown_a8_ = 0xc;
        window->unknown_aa_ = 0xe;
        window->unknown_ac_ = 0xa;
        window->unknown_ae_ = 0xe;
        window->unknown_b1_ = 0xd;
        void* buf = MessageSystem_GetInstance()->tileBuffer;
#if defined(jpn)
        memset(buf, 0, 0x800);
#else
        memset(buf, 0, 0x960);
#endif
        func_ov000_02176500(obj, buf, arg);
#if defined(jpn)
        Window_OpenPane(obj->window, buf, 0, 1, 0, 1, 0);
#else
        Window_OpenPane(obj->window, buf, 0, 1, 0, 1, 0, 0);
#endif
    }
}
