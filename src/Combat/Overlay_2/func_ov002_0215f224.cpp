#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

#if defined(jpn)
#define func_02041fac func_02042638
#endif

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* arg0, int arg1);
extern "C" int Text_AppendFrameTag(char* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" int Text_AppendCursorTag(char* arg0, int arg1);
extern "C" int Text_AppendNTag(char* arg0, int arg1, const char* arg2);
extern "C" int Text_Append(char* arg0, const char* arg1);
extern "C" int func_02041fac(char* arg0, int arg1, int arg2);
extern "C" int func_02041a90(char* arg0, int arg1, int arg2);

struct Struct_ov002_0215f224;
extern "C" void func_0205c508(struct Struct_ov002_0215f224* arg0, int* arg1, int* arg2);

struct Struct_ov002_0215f224_2;
struct Struct_ov002_0215f224_3;
extern "C" struct Struct_ov002_0215f224_3* func_020a83b0(struct Struct_ov002_0215f224_2* arg0, int arg1);

extern "C" int _s32_div_f(int arg0, int arg1);
extern "C" void __clear(void* arg0, int arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" int Font_GetTextWidth(const char* arg0, int arg1);

extern int data_ov002_0216d2a8;

#if defined(jpn)
#define RG(u, j) (j)
struct StoreStruct;
extern "C" int MessageSystem_GetInstance();
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
#else
#define RG(u, j) (u)
#endif

// USA: func_ov002_0215f224
extern "C" ARM void func_ov002_0215f224(char* arg0, char* arg1, int arg2) {
    if (arg1 == NULL) {
        return;
    }
    if (*(int*)(arg0 + RG(0x2474, 0x22a4)) == 0) {
        return;
    }

    int var0 = *(short*)(arg0 + RG(0x1bfc, 0x1ac4)) % 6;

    if (arg2) {
        Text_AppendFrameTag(arg1, var0, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(arg1, var0);

    char* var1 = arg0 + RG(0x2c8 + 0xc00, 0xe20);
    int var2, var3;
    func_0205c508((struct Struct_ov002_0215f224*)(var1 + 0x54), &var2, &var3);

    int var4 = KeyTable_Get((struct Container020e0310*)(arg0 + RG(0x20, 8)), 0x578);
    func_02041fac(arg1, var4, 0x10);

    int var5;
    for (var5 = var2; var5 < var3; var5++) {
        struct Struct_ov002_0215f224_3* var6 = func_020a83b0((struct Struct_ov002_0215f224_2*)(*(int*)(arg0 + 0x2000 + RG(0x474, 0x2a4))), (short)var5);
        if (var6 != NULL) {
            int var7 = var5 % 6;
            Text_AppendNTag(arg1, var7, *(const char**)((char*)var6 + 4));
            if (var5 != var3 - 1) {
                Text_Append(arg1, *(char**)(arg0 + 0x1000 + RG(0xbdc, 0xaa4)));
            }
        }
    }

#if defined(jpn)
    int var8 = *(int*)(var1 + 0x58);
    var4 = *(int*)(var1 + 0x68);
    if (var8 > 1) {
        int var9 = MessageSystem_GetInstance();
        func_020465c0((StoreStruct*)var9, 0, var4 + 1);
        func_020465c0((StoreStruct*)var9, 1, var8);
        func_020465f0((unsigned char*)var9, 0, 1);
        func_020465f0((unsigned char*)var9, 1, 1);
        func_020465d8((unsigned char*)var9, 0, 1);
        func_020465d8((unsigned char*)var9, 1, 0);
        Text_Append(arg1, (const char*)KeyTable_Get((struct Container020e0310*)(arg0 + 8), 0x579));
    }
#else
    int var10 = *(int*)(var1 + 0x58);
    if (var10 > 1) {
        int var11 = *(int*)(var1 + 0x68);
        char var12[4];
        __clear(var12, 4);
        sprintf(var12, (const char*)&data_ov002_0216d2a8, var11 + 1, var10);
        int var13 = Font_GetTextWidth(var12, 0);
        int var14 = var13 + (var13 & 1);
        int var15 = (0x78 - var14) >> 1;
        func_02041a90(arg1, var15, 0x63);
        Text_Append(arg1, var12);
    }
#endif
}
