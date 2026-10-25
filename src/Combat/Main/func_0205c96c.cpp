#include <globaldefs.h>

struct Struct_0205c570;
int MessageSystem_GetInstance(void);
int GetActiveScaledSum0205c570(struct Struct_0205c570* s);
void SetField0x1e20_02042b10(void* obj, void* value);
void EmitScaledField0x440_0202f404(void* obj, int a, int b);
void InitSelfPointer_02042b1c(unsigned char* base);
int CheckGlobalObjState2AndInit0205cde8(unsigned char* p);
extern "C" void func_02045f3c(void* ctx, void* ptr, int a, int b, int c, int d, int e, int flag, int g, int h);

struct Struct_02042c68 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

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

// USA: func_0205c96c
extern "C" ARM void func_0205c96c(unsigned char* obj, int flag) {
    if (obj[0x233] != 0 && obj[0x232] != 0) {
        unsigned char* ctx = (unsigned char*)MessageSystem_GetInstance();
        int bound50 = *(int*)(obj + 0x50);
        int sum = GetActiveScaledSum0205c570((struct Struct_0205c570*)(obj + 0x1c));
        int poolVal = 0x7fff;
        if (obj[0x234] == 0) poolVal = 0x3def;

        if (arg1 == 0) {
            struct Struct_02042c68* var4 = (struct Struct_02042c68*)(arg0 + 0xb4);
            var4->unknown_18_ = var3;
            func_02042b10((void*)var0, (void*)var4);
            func_0202f404((void*)(var0 + 0x19e0), 1, 1);
            func_02042b1c(var0);
        }

        if (func_0205cde8(arg0) != 0) {
            var0[0x19b0] = 1;

            int var5 = *(int*)(arg0 + 0x7c);
            int var6 = *(int*)(arg0 + 0x84);
            struct Struct_02042c68* var7 = (struct Struct_02042c68*)(arg0 + 0xb4);
            int var8 = var7->unknown_2_;
            int var9 = var5 * var6;
            int var10 = var8 + 8;
            int var11 = var7->unknown_0_;
            int var12 = var9 + var5;
            int var13 = var11 + 0xc;
            unsigned short* var14 = (unsigned short*)(arg0 + 0x120);
            int var15 = var10;

            for (; var9 < var12; var9++) {
                int var16 = var3;
                if (var9 == var1 && var1 == var2) var16 = 0xf0a;
                unsigned short var17 = *(unsigned short*)(arg0 + 0x220 + var9 * 2);
                func_02045f3c((void*)var0, var14 + var17, var13, var10, var16, 0xc, 0x14, arg1, 1, 0x11);
                var10 += *(int*)(arg0 + 0xd8);
            }

            if ((arg0[0xb0] | arg0[0xb1]) != 0) {
                int var18 = *(int*)(arg0 + 0x88);
                int var19 = *(int*)(arg0 + 0x8c);
                int var20 = *(int*)(arg0 + 0xd4);
                int var21 = var13 - 0x10;
                void* var22 = *(void**)(var0 + 0x2d8);
                int var23 = *(int*)(arg0 + 0xd8);
                int var24 = var15 - 2;
                int var25 = var19;
                int var26 = var18 * var20 + var21;
                var25 = var25 * var23 + var24;
                void* var27 = *(void**)(var0 + 0x2e0);
                unsigned short var28 = *(unsigned short*)(var0 + 0x2e4);

                if (p2d8 != NULL && ctx2 != NULL) {
                    SpriteEntryList_PlayAnimation((struct Container0205a3d0*)ctx2, ev);
                    struct Entry0205a3d0* entry = SpriteEntryList_Find((struct Container0205a3d0*)ctx2, ev);
                    if (entry != NULL) entry->f15 |= 8;
                    struct Entry0205a3d0* entry2 = SpriteEntryList_Find((struct Container0205a3d0*)ctx2, ev);
                    if (entry2 != NULL) {
                        entry2->f4 = val1;
                        entry2->f6 = val2;
                    }
                    SpriteContext_DrawEntries(p2d8);
                }
            }
        }
    }
}
