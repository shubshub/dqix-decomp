#include <globaldefs.h>
#include "GameState/GameState.h"

struct BackgroundGraphics;
struct Obj0204b878;
struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct Struct0217f5e4;

void Background_ClearMap(struct BackgroundGraphics*, void*);
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
void Window_ClearLayers(struct Cont0205d1e0*);
void Window_DrawPanes(struct Cont0205d228*);
void Window_FlushLayers(struct Cont0205d274*);
void* Background_GetScreen(struct BackgroundGraphics*, unsigned int);
void CallFunc0204b620IfField0x14_0204b878(struct Obj0204b878*, int, int, int, short, short, short, short, unsigned short);
void SetFieldRange0217f5e4(struct Struct0217f5e4*, int);

extern "C" void Background_FlushMap(void*, int);
extern "C" void* func_0202ae18(void*);
extern "C" void func_0203bd08(void*);
extern "C" void func_ov000_0217a8f4(void*);
extern "C" void func_ov000_021750e4(void*);
extern "C" void func_ov000_02175544(void*);
extern "C" void func_ov000_02180bac(void*);
extern "C" void func_ov000_02170538(void*, int, int, int);
extern "C" int func_ov000_0217f5dc(void*);
extern "C" void func_ov000_021707f0(void*);
extern "C" void func_ov000_02181164(void*, int, int, int, int, int, int, int);
extern "C" int func_ov000_02174324(void*, int, int, int);
extern "C" void func_ov000_02180ca8(void*, void*, void*);
#if defined(jpn)
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short);
#else
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short, short, short);
#endif
extern "C" void func_ov000_021741e0(void* arg0, float arg1, float arg2, int arg3, int arg4,
    unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8, unsigned char arg9);
#if defined(jpn)
extern "C" void func_ov000_021811f4(void*, int, void*, int, short, short);
#else
extern "C" void func_ov000_021811f4(void*, int, short, short);
#endif

extern const int data_ov000_021833cc[][2];
extern const int data_ov000_021833c8[][2];
extern const int data_ov000_02183390[];
extern const int data_ov000_02183398[];
extern const int data_ov000_021833dc[][2];
extern const int data_ov000_021833d8[][2];

struct Struct_ov000_02173954_2 {
    char unknown_0_[8];
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    char unknown_10_[0x24 - 0x10];
    unsigned char unknown_24_;
    char unknown_25_[0x44 - 0x25];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x47f - 0x50];
    unsigned char unknown_47f_;
#else
    char unknown1_50_[0x440 - 0x50];
#endif
    unsigned char unknown_440_;
#if defined(jpn)
    char unknown_481_[0x488 - 0x481];
#else
    char unknown_441_[0x448 - 0x441];
#endif
};

static inline int inline_ov000_0215f57c(int arg0) { return arg0 >= 0 && arg0 <= 3; }

// USA: func_ov000_02173954
extern "C" ARM void func_ov000_02173954(char* arg0) {
#if defined(jpn)
    if (*(unsigned short*)(arg0 + 0x1faa) & 0x80) {
#else
    if (*(unsigned short*)(arg0 + 0x1d72) & 0x80) {
#endif
        Background_ClearMap((struct BackgroundGraphics*)(obj + 0x8a4), 0);
        Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
        Window_ClearLayers((struct Cont0205d1e0*)(obj + 0x188));
        Background_FlushMap(obj + 0x8c4, 0);
        return;
    }
    func_ov000_0217a8f4(obj);
    func_ov000_021750e4(obj);
    Background_ClearMap((struct BackgroundGraphics*)(obj + 0x8a4), 0);
    Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Window_ClearLayers((struct Cont0205d1e0*)(obj + 0x188));
#if defined(jpn)
    if (*(unsigned char*)(arg0 + 0x1fb8) == 0 && (*(unsigned short*)(arg0 + 0x1faa) & 0x600)) {
#else
    if (*(unsigned char*)(arg0 + 0x1d80) == 0 && (*(unsigned short*)(arg0 + 0x1d72) & 0x600)) {
#endif
        Window_DrawPanes((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
        Background_FlushMap(obj + 0x8a4, 0);
        Background_FlushMap(obj + 0x8c4, 0);
        Window_FlushLayers((struct Cont0205d274*)(obj + 0x188));
        func_ov000_02180bac(obj);
        return;
    }
    func_0203bd08(func_0202ae18(GameState::GetInstance()));
    signed char* var0;
#if defined(jpn)
    int var10, var11;
#endif
    int var1, var2;
    int var3;
    int var4, var5;
#if defined(jpn)
    int var14, var15;
#endif
    short var6, var7;
    unsigned char var8;
#if defined(jpn)
    unsigned char var9;
#else
    int var10, var11;
#endif
    struct Struct_ov000_02173954_2* var12;
#if defined(jpn)
    int var13, var16;
#else
    int var13, var14, var15, var16;
#endif
    var3 = -1;
    for (var13 = 0; var13 < 4; var13++) {
        var0 = (signed char*)(arg0 + 0x6c);
        var12 = (struct Struct_ov000_02173954_2*)(arg0 + 0x958) + var0[var13];
        var14 = var12->unknown_4c_;
        if (var14 < 0) continue;
        var15 = var12->unknown_c_;
        var16 = var12->unknown_e_;
        var6 = var12->unknown_8_;
        var7 = var12->unknown_a_;
        var8 = var12->unknown_440_;
#if defined(jpn)
        var9 = var12->unknown_47f_;
#endif
        if (var12->unknown_24_ & 8) {
            func_ov000_02170538(var12, *(int*)(arg0 + 0x940), *(int*)(arg0 + 0x944), *(unsigned char*)(arg0 + 0x954));
        } else {
            func_ov000_02170538(var12, 0, 0, *(unsigned char*)(arg0 + 0x954));
        }
        var10 = var12->unknown_44_;
        var11 = var12->unknown_48_;
        var1 = var10 >> 3;
        var2 = var11 >> 3;
        if (!func_ov000_0217f5dc(var12)) continue;
        func_ov000_0217f5e4((struct Struct_ov000_02173954*)arg0, (int)var12);
        if (var12->unknown_24_ & 4) {
            var3 = var14;
            int var17[2];
            int var18[2] = { var10 + 0x37, var10 + 0x37 };
            int var19[2] = { var11 + 0x1c, var11 + 0x2c };
#if defined(jpn)
            int var20[2] = { var13 * 3 + 0x60, var13 * 3 + 0x6c };
#else
            int var20[2] = { var13 * 3 + 0x64, var13 * 3 + 0x70 };
#endif
            int var21 = *(int*)(arg0 + 0x170) + 0x118;
            var4 = 0;
            int var22[2];
            var17[0] = var15;
            var17[1] = var16;
            var22[0] = var21;
            var22[1] = var21;
            for (; var4 < 2; var4++) {
                func_ov000_02181164(arg0, var17[var4], var22[var4], var18[var4], var19[var4], 1, var20[var4], 0xa);
            }
            float var23[2];
            var23[0] = (1.52f * (float)var15) / (float)var6;
            var23[1] = (1.52f * (float)var16) / (float)var7;
            int var24[2] = { var15, var16 };
            int var25 = 0;
#if defined(jpn)
#else
            int var26 = var13 * 2 + 1;
#endif
            for (; var25 < 2; var25++) {
                if (var24[var25] > 0) {
                    int var27 = var11 + data_ov000_021833cc[var25][0];
                    unsigned char var28 = data_ov000_02183390[var25];
                    unsigned char var29 = var13 + data_ov000_02183398[var25];
#if defined(jpn)
                    unsigned char var30 = (var13 * 2 + 1) - (-var25);
#else
                    unsigned char var30 = var26 + var25;
#endif
                    func_ov000_021741e0(arg0, var23[var25], 1.52f, var10 + data_ov000_021833c8[var25][0], var27, var28, var29, var30, 1, 0);
                }
            }
            Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 1, 0, 0, tx, ty, 0x20, 0x19, idx + 2);
#if defined(jpn)
            if (!func_ov000_02174324(arg0, var0[var13], var10 + 0x25, var11 + 0x17)) {
                func_ov000_021811f4(arg0, var14, arg0 + 0x8c4, var9, var1 + 7, var2 + 3);
                func_ov000_0218124c(arg0, var14, arg0 + 0x8c4, var8, var1 + 2, var2 + 2);
#else
            if (!func_ov000_02174324(arg0, var0[var13], var10 + 0x24, var11 + 0x16)) {
                func_ov000_021811f4(arg0, var14, var10 + 0x2c, var11 + 0x16);
                func_ov000_0218124c(arg0, var14, arg0 + 0x8c4, var8, var1 + 2, var2 + 2, var10 + 0xc, var11 + 0x16);
#endif
            }
            func_ov000_021707f0(var12);
        } else {
            int var31 = 0;
            int var32 = 0;
            if (var12->unknown_24_ & 8) {
                var31 = *(int*)(arg0 + 0x940);
                var32 = *(int*)(arg0 + 0x944);
            }
            int var33[2];
#if defined(jpn)
            int var34[2] = { var10 + 0x72 + var31, var10 + 0x72 + var31 };
#else
            int var34[2] = { var10 + 0x6a + var31, var10 + 0x6a + var31 };
#endif
            int var35[2] = { var11 + 1 + var32, var11 + 0xf + var32 };
#if defined(jpn)
            int var36[2] = { var13 * 3 + 0x60, var13 * 3 + 0x6c };
#else
            int var36[2] = { var13 * 3 + 0x64, var13 * 3 + 0x70 };
#endif
            int var37 = *(int*)(arg0 + 0x170) + 0x118;
            var5 = 0;
            int var38[2] = { var37, var37 };
            var33[0] = var15;
            var33[1] = var16;
            for (; var5 < 2; var5++) {
                func_ov000_02181164(arg0, var33[var5], var38[var5], var34[var5], var35[var5], 1, var36[var5], 9);
            }
            float var39[2];
            var39[0] = (1.28f * (float)var15) / (float)var6;
            var39[1] = (1.28f * (float)var16) / (float)var7;
            int var40[2] = { var15, var16 };
            int var41 = 0;
#if defined(jpn)
#else
            int var42 = var13 * 2 + 1;
#endif
            for (; var41 < 2; var41++) {
                if (var40[var41] > 0) {
                    int var43 = var11 + data_ov000_021833dc[var41][0];
                    unsigned char var44 = data_ov000_02183390[var41];
                    unsigned char var45 = var13 + data_ov000_02183398[var41];
#if defined(jpn)
                    unsigned char var46 = (var13 * 2 + 1) - (-var41);
#else
                    unsigned char var46 = var42 + var41;
#endif
                    func_ov000_021741e0(arg0, var39[var41], 1.28f, var10 + data_ov000_021833d8[var41][0], var43, var44, var45, var46, 1, 1);
                }
            }
            char* list = obj + 0x8c4;
            if (e->flags & 8) list = obj + 0x8a4;
            void* ent = Background_GetScreen((struct BackgroundGraphics*)(obj + 0x8c4), 2);
#if defined(jpn)
            func_0204b878((struct Struct_0204b878*)var47, (int)var48, 0, 0, var1 + 2, var2, 0x20, 0x19, var14 + 2);
#else
            func_0204b878((struct Struct_0204b878*)var47, (int)var48, 0, 0, var1 + 1, var2, 0x20, 0x19, var14 + 2);
#endif
            func_ov000_02180ca8(arg0, var12, var47);
#if defined(jpn)
            if (!func_ov000_02174324(arg0, var14, var10 + 0x30, var11 + 0x16)) {
                func_ov000_021811f4(arg0, var14, var47, var9, var1 + 8, var2 + 3);
                func_ov000_0218124c(arg0, var14, var47, var8, var1 + 3, var2 + 2);
#else
            if (!func_ov000_02174324(arg0, var14, var10 + 0x28, var11 + 0x16)) {
                func_ov000_021811f4(arg0, var14, var10 + 0x2c, var11 + 0x16);
                func_ov000_0218124c(arg0, var14, var47, var8, var1 + 2, var2 + 2, var10 + 0x14, var11 + 0x16);
#endif
            }
        }
    }
    if (InRange(found)) {
        Window_DrawPanes((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
    }
    Background_FlushMap(obj + 0x8a4, 0);
    Background_FlushMap(obj + 0x8c4, 0);
    Window_FlushLayers((struct Cont0205d274*)(obj + 0x188));
}
