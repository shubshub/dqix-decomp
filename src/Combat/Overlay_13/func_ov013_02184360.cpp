#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02074b64;
extern "C" ARM void func_02074b64(struct Struct_02074b64* obj);
struct Struct_02074af4;
extern "C" ARM void func_02074af4(struct Struct_02074af4* obj);
struct InitTarget0205cfd4;
extern "C" ARM void Window_Init(struct InitTarget0205cfd4* s);
extern "C" ARM void func_0205c790(char* obj);
struct BackgroundGraphics;
extern "C" ARM void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void* obj);
struct Struct020dfc40;
extern "C" ARM void KeyTable_Reset(Struct020dfc40* p);

struct Struct_ov013_02184360 { unsigned int w[20]; };
struct Struct_ov013_02184360_2 { unsigned int w[16]; };

// USA: func_ov013_02184360
extern "C" ARM void func_ov013_02184360(void* entry, void* param) {
    unsigned char* obj = (unsigned char*)entry;
    obj[R(0x2e, 0x30)] = 0;
    obj[R(0x2f, 0x31)] = 0;
    obj[R(0x5cc, 0x640)] = (param != 0);

    void* var1 = obj + R(0x1e, 0x20);
    if (*(volatile unsigned char*)(obj + R(0x5cc, 0x640)) != 0) {
        func_02074b64((Struct_02074b64*)var1);
        unsigned int v = *(volatile unsigned int*)0x4001000;
        *(int*)(obj + R(0x30, 0x34)) = (v & 0x1f00u) >> 8;
    } else {
        func_02074af4((Struct_02074af4*)var1);
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        unsigned int v = *reg;
        *(int*)(obj + R(0x30, 0x34)) = (v & 0x1f00u) >> 8;
        v = *reg;
        *reg = (v & ~0x1f00u) | 0x100u;
    }

    Window_Init((InitTarget0205cfd4*)(obj + R(0x34, 0x38)));
    func_0205c790((char*)(obj + R(0x3d0, 0x3d4)));

    if (obj[R(0x5cc, 0x640)] != 0) {
        unsigned char* src = (unsigned char*)param + 0x188;
        *(Struct_ov013_02184360*)(obj + R(0x38, 0x3c)) = *(Struct_ov013_02184360*)(src + 0x4);
        *(Struct_ov013_02184360_2*)(obj + R(0x88, 0x8c)) = *(Struct_ov013_02184360_2*)(src + 0x54);

        obj[R(0xc8, 0xcc)] = src[0x94];
        obj[R(0xc9, 0xcd)] = src[0x95];
        obj[R(0xca, 0xce)] = src[0x96];
        obj[R(0xcb, 0xcf)] = src[0x97];
        *(unsigned int*)(obj + R(0xcc, 0xd0)) = *(unsigned int*)(src + 0x98);
        *(unsigned int*)(obj + R(0xd0, 0xd4)) = *(unsigned int*)(src + 0x9c);
        *(short*)(obj + R(0xd4, 0xd8)) = *(short*)(src + 0xa0);
        *(short*)(obj + R(0xd6, 0xda)) = *(short*)(src + 0xa2);
        *(short*)(obj + R(0xd8, 0xdc)) = *(short*)(src + 0xa4);
        *(short*)(obj + R(0xda, 0xde)) = *(short*)(src + 0xa6);
        *(short*)(obj + R(0xdc, 0xe0)) = *(short*)(src + 0xa8);
        *(short*)(obj + R(0xde, 0xe2)) = *(short*)(src + 0xaa);
        *(short*)(obj + R(0xe0, 0xe4)) = *(short*)(src + 0xac);
        *(short*)(obj + R(0xe2, 0xe6)) = *(short*)(src + 0xae);
        obj[R(0xe4, 0xe8)] = src[0xb0];
        obj[R(0xe5, 0xe9)] = src[0xb1];
        obj[R(0xe6, 0xea)] = src[0xb2];
        obj[R(0xe7, 0xeb)] = src[0xb3];
        obj[R(0xe8, 0xec)] = src[0xb4];
        obj[R(0xe9, 0xed)] = src[0xb5];
        obj[R(0xea, 0xee)] = src[0xb6];
        obj[R(0xeb, 0xef)] = src[0xb7];
        obj[R(0xec, 0xf0)] = src[0xb8];
        obj[R(0xed, 0xf1)] = src[0xb9];
        obj[R(0xee, 0xf2)] = src[0xba];
        obj[R(0xef, 0xf3)] = src[0xbb];
    }

    for (int i = 0; i < 2; i++) {
        Background_Init((BackgroundGraphics*)(obj + R(0xf0, 0xf4) + i * 0x20));
    }
    for (int i = 0; i < 3; i++) {
        WindowPane_Init((void*)(obj + R(0x130, 0x134) + i * 0xe0));
    }

    ((SafeAllocator*)(obj + R(0x598, 0x60c)))->ResetAllocatorPointer();
    KeyTable_Reset((Struct020dfc40*)(obj + R(0x5ac, 0x620)));
    ((SafeAllocator*)obj)->ResetAllocatorPointer();

    for (int i = 0; i < 3; i++) {
        unsigned char* p = obj + i;
        p[R(0x5c4, 0x638)] = 0;
    }

    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    *(short*)(obj + 0x1c) = 0xff;
#if !defined(jpn)
    *(short*)(obj + 0x1e) = 0;
#endif
    obj[R(0x5c8, 0x63c)] = 0;
    obj[R(0x5c9, 0x63d)] = 0;
    obj[R(0x5ca, 0x63e)] = 0;
    obj[R(0x5cb, 0x63f)] = 0;
#if !defined(jpn)
    *(int*)(obj + 0x644) = 0;
#endif
    *(int*)(obj + R(0x5d0, 0x648)) = 0;
    *(int*)(obj + R(0x5d4, 0x64c)) = 0;
    *(int*)(obj + R(0x5e4, 0x65c)) = 0;
    *(int*)(obj + R(0x5e8, 0x660)) = 0;
    obj[R(0x5ec, 0x664)] = 0;
    obj[R(0x5ed, 0x665)] = 0;
    *(int*)(obj + R(0x5f0, 0x668)) = 0;
    *(int*)(obj + R(0x5f4, 0x66c)) = 0;
    *(int*)(obj + R(0x5f8, 0x670)) = 0;
    *(int*)(obj + R(0x638, 0x6b0)) = 0;
    obj[R(0x63c, 0x6b4)] = 0;
    *(int*)(obj + R(0x5e0, 0x658)) = 0;
    *(int*)(obj + R(0x62c, 0x6a4)) = 0;
    obj[R(0x630, 0x6a8)] = 0;
    obj[R(0x644, 0x6bc)] = 0;
    *(int*)(obj + R(0x640, 0x6b8)) = 0;

    unsigned char* var10 = obj + 0x600;
    *(short*)(var10 + R(0x46, 0xbe)) = 0;
    *(short*)(var10 + R(0x48, 0xc0)) = 0;
    *(short*)(var10 + R(0x4a, 0xc2)) = 0;
    *(short*)(var10 + R(0x4c, 0xc4)) = 0;
    *(short*)(var10 + R(0x4e, 0xc6)) = 0;
    *(short*)(var10 + R(0x50, 0xc8)) = 0;
    *(short*)(var10 + R(0x52, 0xca)) = 0;

    for (int i = 0; i < 5; i++) {
        *(int*)(obj + R(0x5fc, 0x674) + i * 4) = 0;
    }
    for (int i = 0; i < 5; i++) {
        *(int*)(obj + R(0x610, 0x688) + i * 4) = 0;
    }
    for (int i = 0; i < 5; i++) {
        unsigned char* p = obj + i;
        p[R(0x624, 0x69c)] = 1;
    }

    *(int*)(obj + R(0x5dc, 0x654)) = (obj[R(0x5cc, 0x640)] != 0) ? *(int*)((unsigned char*)param + 0x178) : 0;

    for (int i = 0; i < 5; i++) {
        unsigned char* p = obj + i;
        p[R(0x631, 0x6a9)] = 0;
    }
}
