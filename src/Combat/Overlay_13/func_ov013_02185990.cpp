#if defined(jpn)
#define func_0205cc50 func_0205dfa8
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185990 func_ov013_02186b88
#endif

struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);

extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" void func_0205cb74(char* obj, int value);

#if defined(jpn)
extern "C" void func_0205cc50(void* obj);
#else
extern "C" void func_0205cc50(void* obj, int a, int b);
#endif

struct Struct_0205c77c;
extern "C" void func_0205c77c(struct Struct_0205c77c* p, int val);

extern "C" void func_0205cd28(unsigned char* obj);
extern "C" void func_0205cd94(unsigned char* p);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern "C" void func_0205c790(char* obj);

extern int g_sePlayer;

// USA: func_ov013_02185990
extern "C" ARM void func_ov013_02185990(unsigned char* obj) {
    unsigned char* tag = obj + LOW_REGION(0, 0x3d4);

    func_0205c790((char*)(tag + LOW_REGION(0x3d0, 0)));

    *(unsigned char*)(tag + LOW_REGION(0x481, 0xb1)) = 1;
    *(unsigned char*)(tag + LOW_REGION(0x480, 0xb0)) = 1;

    GridCursor_SetDimensions((struct GridCursor*)(tag + LOW_REGION(0x3f0, 0x20)), 1, 2, 0);
    GridCursor_SetDimensions((struct GridCursor*)(tag + LOW_REGION(0x440, 0x70)), 1, 2, 0);
    GridCursor_SetCount((struct GridCursor*)(tag + LOW_REGION(0x3f0, 0x20)), 2);
    GridCursor_SetCount((struct GridCursor*)(tag + LOW_REGION(0x440, 0x70)), 2);

    int v0 = KeyTable_Get((struct Container020e0310*)(obj + LOW_REGION(0x5ac, 0x620)), 0xa);
    func_0205cb74((char*)(tag + LOW_REGION(0x3d0, 0)), v0);

    int v1 = KeyTable_Get((struct Container020e0310*)(obj + LOW_REGION(0x5ac, 0x620)), 0xb);
    func_0205cb74((char*)(tag + LOW_REGION(0x3d0, 0)), v1);

    *(unsigned short*)(tag + LOW_REGION(0x484, 0xb4)) = 0xc2;
    *(unsigned short*)(tag + LOW_REGION(0x486, 0xb6)) = 0x92;

#if defined(jpn)
    func_0205cc50(tag + 0x3d0);
#else
    func_0205cc50(tag, 0, -4);
#endif

    *(unsigned char*)(tag + LOW_REGION(0x594, 0x234)) = 1;
    func_0205c77c((struct Struct_0205c77c*)(tag + LOW_REGION(0x3d4, 0x4)), 1);

    *(unsigned char*)(tag + LOW_REGION(0x593, 0x233)) = 1;
    *(unsigned char*)(tag + LOW_REGION(0x594, 0x234)) = 1;
    func_0205c77c((struct Struct_0205c77c*)(tag + LOW_REGION(0x3d4, 0x4)), 1);

    func_0205cd28(tag + LOW_REGION(0x3d0, 0));
    func_0205cd94(tag + LOW_REGION(0x3d0, 0));

    SePlayer_Play((struct SePlayer*)&g_sePlayer, 5, 0);

#if !defined(jpn)
    short var3 = *(short*)(tag + 0xb6);
    short b8 = *(short*)(tag + 0xb8);
    *(unsigned short*)(tag + 0xb4) = 0xfe - b8;
    *(unsigned short*)(tag + 0xb6) = var3;
    func_0205cc50(tag, 0, -4);
#endif
}
