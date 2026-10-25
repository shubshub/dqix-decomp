#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205c570;
int MessageSystem_GetInstance(void);
int GetActiveScaledSum0205c570(struct Struct_0205c570* s);
void SetField0x1e20_02042b10(void* obj, void* value);
void EmitScaledField0x440_0202f404(void* obj, int a, int b);
void InitSelfPointer_02042b1c(unsigned char* base);
int CheckGlobalObjState2AndInit0205cde8(unsigned char* p);
#if defined(jpn)
extern "C" void func_02046c78(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#else
extern "C" void func_02045f3c(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);
#endif

struct Struct_0205a254;
struct Struct_0205c96c {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[0xd];
    unsigned char unknown_15_;
};
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
struct Entry0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteContext_DrawEntries(void* obj);

static inline int inline_0205c96c(unsigned char* arg0) { return *(int*)(arg0 + 0x88); }
static inline int inline_0205c96c_2(unsigned char* arg0) { return *(int*)(arg0 + 0x8c); }

// USA: func_0205c96c
extern "C" ARM void func_0205c96c(unsigned char* arg0, int arg1) {
    unsigned char* var0;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    void* var12;
    struct Struct_0205a254* var13;
    unsigned short var14;
    struct Struct_0205c96c* var15;

    if (arg0[RG(0x233, 0x1c3)] == 0 || arg0[RG(0x232, 0x1c2)] == 0) {
        return;
    }

    ctx = (unsigned char*)MessageSystem_GetInstance();
    cursor = *(int*)(obj + 0x50);
    sum = GetActiveScaledSum0205c570((struct Struct_0205c570*)(obj + 0x1c));
    color = 0x7fff;
    if (obj[RG(0x234, 0x1c4)] == 0) {
        color = 0x3def;
    }

    if (arg1 == 0) {
        *(short*)(arg0 + 0xcc) = var4;
        func_02042b10(var0, arg0 + 0xb4);
        func_0202f404(var0 + RG(0x19e0, 0x1804), 1, 1);
        func_02042b1c(var0);
    }

    if (func_0205cde8(arg0) == 0) {
        return;
    }

    var0[RG(0x19b0, 0x17e0)] = 1;

    var9 = *(int*)(arg0 + 0x7c);
    var8 = var9 * *(int*)(arg0 + 0x84);
    var5 = *(short*)(arg0 + 0xb4) + 0xc;
    var6 = *(short*)(arg0 + 0xb6) + 8;
    var2 = var8 + var9;
    var7 = var6;

    for (; var8 < var2; var8++) {
        int var16 = var4;
        if (var8 == var1 && var1 == var3) {
            var16 = 0xf0a;
        }
#if defined(jpn)
        func_02046c78(var0, (unsigned short*)(arg0 + 0x120) + *(unsigned short*)(arg0 + 0x1b0 + var8 * 2), var5, var6, var16, 0xc, 0x14, arg1);
#else
        func_02045f3c(var0, (unsigned short*)(arg0 + 0x120) + *(unsigned short*)(arg0 + 0x220 + var8 * 2), var5, var6, var16, 0xc, 0x14, arg1, 1, 0x11);
#endif
        var6 += *(int*)(arg0 + 0xd8);
    }

    if ((arg0[0xb0] | arg0[0xb1]) == 0) {
        return;
    }

    var10 = inline_0205c96c(arg0);
    var11 = inline_0205c96c_2(arg0);
    var5 = var10 * *(int*)(arg0 + 0xd4) + (var5 - 0x10);
    var6 = var11 * *(int*)(arg0 + 0xd8) + (var7 - 2);
    var12 = *(void**)(var0 + RG(0x2d8, 0x228));
    var13 = *(struct Struct_0205a254**)(var0 + RG(0x2e0, 0x230));
    var14 = *(unsigned short*)(var0 + RG(0x2e4, 0x234));
    if (var12 == NULL || var13 == NULL) {
        return;
    }

    SpriteEntryList_PlayAnimation(entries, key);
    entry = SpriteEntryList_Find(entries, key);
    if (entry != NULL) {
        entry->f15 |= 8;
    }
    entry = SpriteEntryList_Find(entries, key);
    if (entry != NULL) {
        entry->f4 = x;
        entry->f6 = y;
    }
    SpriteContext_DrawEntries(list);
}
