#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov023_021e7cec(void* obj, int a, int b, int c);
#if defined(jpn)
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif

struct Struct_ov023_021e802c;
extern "C" void func_ov023_021e8cc0(struct Struct_ov023_021e802c* obj);
extern "C" void func_ov023_021e8cdc(void* obj);
extern "C" void func_ov023_021e8e34(void* obj);
extern "C" void func_ov023_021e8ef8(void* obj);

struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

struct Struct_ov023_021e802c_2 {
    char pad[0x5d8];
    void* field5d8;
};

// USA: func_ov023_021e802c
extern "C" ARM void func_ov023_021e802c(struct Struct_ov023_021e802c_2* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    Window_ClosePane((struct Entry_0205d6a0*)((char*)obj + 0x78), 1);
    func_ov023_021e7cec(obj, 0xc, 0, 5);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8cc0((struct Struct_ov023_021e802c*)obj);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 0, 0, 1);
#endif

#endif

    func_ov023_021e7cec(obj, 0xd, 0, 0x10);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8cdc(obj);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 0, 0, 1);
#endif

#endif

    func_ov023_021e7cec(obj, 0xe, 0, 2);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8e34(obj);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0, 0);
#endif

#endif

    func_ov023_021e7cec(obj, 0xf, 0, 0xd);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0, 0);
#endif

#endif

    func_ov023_021e7cec(obj, 0x10, 0xf, 0xd);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8ef8(obj);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 1, 0, 1, 0);
#else
    Window_OpenPane((char*)obj + 0x78, obj->field5d8, 1, 1, 0, 1, 0, 1);
#endif

    for (int i = 0; i < 5; i++) {
        Window_SetPanePalette((struct Struct_0205d81c*)((char*)obj + 0x78), (unsigned char)(i + 0xc), 0);
    }
}
