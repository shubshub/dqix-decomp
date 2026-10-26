#include <globaldefs.h>

extern int g_sePlayer;
extern int g_bgmPlayer;

extern "C" unsigned char func_0205ea18(unsigned char* obj);
extern "C" void func_0209ca70(void* obj, int val);
struct Obj0205e9f4;
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

// USA: func_ov002_0215b268
extern "C" ARM void func_ov002_0215b268(char* p) {
#if defined(jpn)
    enum { Enum_ov002_0215b268_3116 = 0xaf4 };
#else
    enum { Enum_ov002_0215b268_3116 = 0xc2c };
#endif
    unsigned char a = func_0205ea18((unsigned char*)&g_sePlayer);
    unsigned char b1 = *(unsigned char*)(p + 0x1000 + Enum_ov002_0215b268_3116);
    func_0209ca70(&g_bgmPlayer, b1);
    unsigned char b2 = *(unsigned char*)(p + 0x1000 + Enum_ov002_0215b268_3116 + 1);
    func_0205e9f4((struct Obj0205e9f4*)&g_sePlayer, b2);
    unsigned char b3 = *(unsigned char*)(p + 0x1000 + Enum_ov002_0215b268_3116 + 1);
    if (a == b3) return;
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
}
