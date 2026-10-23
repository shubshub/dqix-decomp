#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" int func_020100a8(GameState* arg0);
extern "C" int func_020421a0(void);
extern "C" void func_020e4bf4(void* arg0, int arg1);

struct Struct_02046574_2;
extern "C" void func_02046574(struct Struct_02046574_2* arg0, int arg1, char* arg2);

extern "C" void func_02046380(void* arg0);
extern "C" void func_02046608(int arg0, int arg1, void* arg2, void* arg3, int arg4, int arg5, int arg6);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" void func_02042058(char*, const char*);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

struct Struct_ov023_021ed4b8 { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; };

// USA: func_ov023_021ed4b8
extern "C" ARM void func_ov023_021ed4b8(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021ed4b8_580=0x15c, Enum_ov023_021ed4b8_2400=0x800};
#else
 enum {Enum_ov023_021ed4b8_580=0x244, Enum_ov023_021ed4b8_2400=0x960};
#endif
    unsigned char var0 = ((struct Struct_ov023_021ed4b8*)(arg0 + 0xc0))->unknown_0_0_;
    func_0205de24((struct Struct_0205de24_2*)(arg0 + 0xc4), var0, 3);

    *(unsigned short*)(arg0 + 0x164) = 0x1e;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x166) = 6;
#else
    *(unsigned short*)(arg0 + 0x166) = 0x7;
#endif

    *(unsigned short*)(arg0 + 0x168) = 0x1;
    *(unsigned short*)(arg0 + 0x16a) = 0x9;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x16c) = 0xa;
#else
    *(unsigned short*)(arg0 + 0x16c) = 0x7;
#endif

    *(unsigned short*)(arg0 + 0x16e) = 0xa;
    *(unsigned short*)(arg0 + 0x170) = 0xc;
#if defined(jpn)
    *(unsigned short*)(arg0 + 0x172) = 0x14;
#else
    *(unsigned short*)(arg0 + 0x172) = 0xc;
#endif

    *(unsigned char*)(arg0 + 0x17b) = 0xc;
    *(unsigned char*)(arg0 + 0x175) = 2;
    unsigned char var1 = 0;
    *(unsigned char*)(arg0 + 0x179) = var1;
    *(unsigned char*)(arg0 + 0x17a) = var1;

    unsigned char var2 = *(unsigned char*)(arg0 + 0x28);
    char* var3 = *(char**)(arg0 + 0x20);
    char* var4 = var3 + var2 * Enum_ov023_021ed4b8_580;

    memset(*(void**)(arg0 + 0x1c), var1, Enum_ov023_021ed4b8_2400);

#if defined(jpn)
    int key = KeyTable_Get((struct Container020e0310*)(obj + 4), 0x64);
    AppendString02042058(*(char**)(obj + 0x1c), (char*)key);
    GameState* bs = GameState::GetInstance();
#else
    GameState* var6 = GameState::GetInstance();
#endif

    int var7 = func_020100a8(var6);
    GameObject* var8 = func_0200ff1c(var6, var7);
    if (var8 == NULL) return;

    int var9 = func_020421a0();
    func_02046380((void*)var9);

#if defined(jpn)
    func_02046574((struct Struct_02046574_2*)var9, 0, *(char**)((char*)var8 + 0x134));
    func_02046574((struct Struct_02046574_2*)var9, 1, var4 + 0xc);

#else
    char var10[0xc];
    int var11 = var8->obj3D_.unknown_4_;
    func_020e4bf4(var10, var11);

    *(void**)((char*)var9 + 0x0) = var10;
    func_02046574((struct Struct_02046574_2*)var9, 1, var4 + 0xc);

    int key = KeyTable_Get((struct Container020e0310*)(obj + 0x4), 0x64);
    func_02046608(g, 1, (void*)(long)key, *(void**)(obj + 0x1c), 0xe3, 0, 1);

#endif
#if defined(jpn)
    func_0205d304(arg0 + 0xc4, *(void**)(arg0 + 0x1c), 0, 0, 0, 0, 0);
#else
    func_0205d304(arg0 + 0xc4, *(void**)(arg0 + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
