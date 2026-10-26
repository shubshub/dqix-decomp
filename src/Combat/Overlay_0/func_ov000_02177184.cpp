#include <globaldefs.h>
#include "std_library_functions.h"

struct Canvas0204e998;
struct Entry_0205d6a0;
extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" void func_0204c964(struct Canvas0204e998* canvas);
extern "C" void* func_ov000_02174da4(int unused, void* dest);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" void func_0205cf04(void* obj);
extern "C" void func_0205cef8(void* obj);
extern "C" void func_0205cf28(unsigned char* obj, int a, int count, int b);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_ov000_0217737c(void* obj, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" void func_ov000_0217a8f4(void* obj);

struct Struct_ov000_02177184 {
    char unknown_0_[0x54];
    char cursor[4];
    int unknown_58_;
    char unknown_5c_[0x9c - 0x5c];
    unsigned char* canvas;
    short left;
    short top;
    short width;
    short height;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02177184_2 {
    char unknown_0_[0x188];
    struct Struct_ov000_02177184 window;
#if defined(jpn)
    char unknown_23c_[0x1fa1 - 0x188 - sizeof(struct Struct_ov000_02177184)];
#else
    char unknown1_23c_[0x1d69 - 0x188 - sizeof(struct Struct_ov000_02177184)];
#endif
    signed char selection;
    char unknown_1d6a_[0x1d72 - 0x1d6a];
    unsigned short flags;
};

// USA: func_ov000_02177184
extern "C" ARM void func_ov000_02177184(struct Struct_ov000_02177184_2* menu, int active) {
    if (!active) {
        return;
    }
    struct Struct_ov000_02177184* window = &menu->window;
    unsigned char* canvas = window->canvas;
    if (WindowPane_IsOpen(canvas)) {
        func_0204c964((struct Canvas0204e998*)canvas);
        menu->flags &= ~2;
        return;
    }
    int entries[4];
    func_ov000_02174da4((int)menu, entries);
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (entries[i] >= 0) {
            count++;
        }
    }
    menu->selection = 0;
    Window_ClosePane((struct Entry_0205d6a0*)window, 1);
    func_0205cf04(window);
    func_0205cef8(window);
    func_0205cf28((unsigned char*)window, 1, count, 0);
    window->unknown_58_ = 1;
    GridCursor_SetSelectedIndex(window->cursor, 0);
    if (count == 3) {
        window->left = 8;
        window->top = 6;
    }
    if (count == 4) {
        window->left = 8;
        window->top = 1;
    }
    window->width = 9;
    window->height = 1;
    if (count == 3) {
        window->unknown_a8_ = 0xc;
        window->unknown_aa_ = 8;
    }
    if (count == 4) {
        window->unknown_a8_ = 0xc;
        window->unknown_aa_ = 4;
    }
    window->unknown_ac_ = 0xa;
    window->unknown_ae_ = 0xb;
    window->unknown_b1_ = 1;
    func_0205d7a0((unsigned char*)window, menu->selection);
#if defined(jpn)
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217737c(menu, buf);
#if defined(jpn)
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0, 0);
#endif
    func_ov000_0217a8f4(menu);
}
