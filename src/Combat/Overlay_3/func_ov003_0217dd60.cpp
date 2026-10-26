#include <globaldefs.h>

struct Struct0205de24;
struct GridCursor;
struct Struct_0205d81c;
struct Container020e0310;

struct Struct_ov003_0217dd60 {
    char pad0[0x8];
    int field8;
    char unknown_c_[0x58 - 0xc];
    int unknown_58_;
    char unknown_5c_[0x68 - 0x5c];
    int page;
    char pad6c[0x94 - 0x6c];
    unsigned char field94;
    unsigned char unknown_95_;
    char pad96[0xa0 - 0x96];
    short a0;
    short a2;
    short a4;
    short a6;
    short a8;
    short unknown_aa_;
    short ac;
    short ae;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[0xb5 - 0xb2];
    unsigned char unknown_b5_;
};

#if defined(jpn)
struct Struct_ov003_0217dd60_2 {
    char pad0[0x14];
    unsigned char items[0x2c - 0x14];
    unsigned char itemCount;
    char unknown_2d_;
    unsigned char field32;
    char unknown_2f_[0x8c - 0x2f];
    struct Struct_ov003_0217dd60* window;
    char unknown_90_[0xc8 - 0x90];
    char names[4];
};
#else
struct Struct_ov003_0217dd60_2 {
    char pad0[0x10];
    int field10;
    char unknown_14_[0x18 - 0x14];
    unsigned char items[0x30 - 0x18];
    unsigned char itemCount;
    char unknown_31_;
    unsigned char field32;
    char unknown_33_[0x90 - 0x33];
    struct Struct_ov003_0217dd60* window;
    char unknown_94_[0xcc - 0x94];
    char names[4];
};
#endif

extern "C" void func_0205de24(struct Struct0205de24*, unsigned char, unsigned char);
extern "C" void func_0205cf04(void*);
extern "C" void func_0205cef8(void*);
extern "C" int MessageSystem_GetInstance();
extern "C" void Zone3D_GetInstance();
extern "C" void __clear(void* buf, int n);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void Text_Append(char* dst, const char* src);
extern "C" unsigned char* func_0205e00c(struct Struct_0205d81c* s, int key);
extern "C" void func_02050400(unsigned char* elem, int state);
extern "C" void WindowPane_SetIndicatorPage(unsigned char* elem, unsigned char value);
extern "C" void WindowPane_SetIndicatorPageCount(unsigned char* elem, int value);
#if defined(jpn)
struct StoreStruct;
extern "C" void Window_OpenPane(void* window, char* buf, int a, int b, int c, int d, int e);
extern "C" void func_02046380(void* w);
extern "C" void func_020465c0(struct StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char* dst, int size);
#else
extern "C" void Window_OpenPane(void* window, char* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void GridCursor_SetDimensions(struct GridCursor* t, int a, int b, int c);
extern "C" void GridCursor_SetCount(struct GridCursor* n, int value);

extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dd60
#if defined(jpn)
extern "C" ARM void func_ov003_0217dd60(struct Struct_ov003_0217dd60_2* menu) {
    char buf[0x400];
    Zone3D_GetInstance();
    struct StoreStruct* g = (struct StoreStruct*)MessageSystem_GetInstance();
    func_0205de24((struct Struct0205de24*)menu->window, 0, 1);
    menu->window->unknown_b1_ = 0;
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a0 = 14;
        w->a2 = 11;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a4 = 9;
        w->a6 = 2;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a8 = 13;
        w->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->ac = 10;
        w->ae = 13;
    }
    menu->window->unknown_b5_ = 1;
    func_0205cf04(menu->window);
    func_0205cef8(menu->window);
    int end;
    int i;
    int page = menu->window->page;
    __clear(buf, 0x400);
    end = (page + 1) * 6;
    if (end > menu->itemCount) {
        end = menu->itemCount;
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        Text_AppendNTag(buf, i % 6, name);
        if (i != end - 1) {
            Text_Append(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
        func_02046380(g);
        func_020465c0(g, 0, page + 1);
        func_020465c0(g, 1, menu->field32);
        func_020465f0((unsigned char*)g, 0, 2);
        func_020465f0((unsigned char*)g, 1, 2);
        func_020465d8((unsigned char*)g, 0, 1);
        func_020465d8((unsigned char*)g, 1, 0);
        func_02042428(buf, 8);
        Text_Append(buf, (const char*)KeyTable_Get((struct Container020e0310*)menu->names, 200));
    }
    if (menu->field32 > 1) {
        Window_OpenPane(menu->window, buf, 0, 0, 1, 1, 0);
    } else {
        Window_OpenPane(menu->window, buf, 0, 0, 0, 1, 0);
    }
    int field32 = menu->field32;
    struct Struct_ov003_0217dd60* window = menu->window;
    window->field8 = field32;
    window->unknown_58_ = field32;
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct GridCursor*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct GridCursor*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->unknown_95_ = 1;
}
#else
extern "C" ARM void func_ov003_0217dd60(struct Struct_ov003_0217dd60_2* menu) {
    char buf[0x400];
    Zone3D_GetInstance();
    MessageSystem_GetInstance();
    func_0205de24((struct Struct0205de24*)menu->window, 0, 1);
    int var14 = menu->field10;
    menu->window->unknown_b1_ = 0;
    short var15 = (short)(var14 >> 3);
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a0 = var15;
        w->a2 = 11;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a4 = (32 - var15) >> 1;
        w->a6 = 2;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a8 = 12;
        w->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->ac = 10;
        w->ae = 13;
    }
    if (menu->field32 > 1) {
        struct Struct_ov003_0217dd60* w = menu->window;
        w->a0 = var15;
        w->a2 = 12;
    }
    menu->window->unknown_b5_ = 1;
    func_0205cf04(menu->window);
    func_0205cef8(menu->window);
    int end;
    int i;
    int page = menu->window->page;
    __clear(buf, 0x400);
    end = (page + 1) * 6;
    if (end > menu->itemCount) {
        end = menu->itemCount;
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        Text_AppendNTag(buf, i % 6, name);
        if (i != end - 1) {
            Text_Append(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
        unsigned char* elem = func_0205e00c((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            func_02050400(elem, 1);
            WindowPane_SetIndicatorPage(elem, page);
            WindowPane_SetIndicatorPageCount(elem, menu->field32);
        }
    }
    if (menu->field32 > 1) {
        Window_OpenPane(menu->window, buf, 0, 0, 1, 1, 0, 0);
    } else {
        Window_OpenPane(menu->window, buf, 0, 0, 0, 1, 0, 0);
    }
    int field32 = menu->field32;
    struct Struct_ov003_0217dd60* window = menu->window;
    window->field8 = field32;
    window->unknown_58_ = field32;
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct GridCursor*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct GridCursor*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct GridCursor*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->unknown_95_ = 1;
}
#endif
