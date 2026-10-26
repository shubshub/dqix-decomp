#include <globaldefs.h>

struct Struct_0205c570;
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_0205c570(struct Struct_0205c570* s);
extern "C" void func_02042b10(void* obj, void* value);
extern "C" void WindowFrame_Draw(void* obj, int a, int b);
extern "C" void func_02042b1c(unsigned char* base);
extern "C" int func_0205cde8(unsigned char* p);
extern "C" void func_02045f3c(void* ctx, void* ptr, int a, int b, int c, int d, int e, int flag, int g, int h);

struct Struct_02042c68 {
    short a0;
    short a2;
    short a4;
    short a6;
    int a8;
    int ac;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Container0205a3d0;
struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    char pad8[0xd];
    unsigned char f15;
};
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" struct Entry0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_0205c96c
extern "C" ARM void func_0205c96c(unsigned char* obj, int flag) {
    if (obj[0x233] != 0 && obj[0x232] != 0) {
        unsigned char* ctx = (unsigned char*)MessageSystem_GetInstance();
        int var1 = *(int*)(obj + 0x50);
        int sum = func_0205c570((struct Struct_0205c570*)(obj + 0x1c));
        int var3 = 0x7fff;
        if (obj[0x234] == 0) var3 = 0x3def;

        if (flag == 0) {
            struct Struct_02042c68* foo = (struct Struct_02042c68*)(obj + 0xb4);
            foo->unknown_18_ = var3;
            func_02042b10((void*)ctx, (void*)foo);
            WindowFrame_Draw((void*)(ctx + 0x19e0), 1, 1);
            func_02042b1c(ctx);
        }

        if (func_0205cde8(obj) != 0) {
            ctx[0x19b0] = 1;

            int a = *(int*)(obj + 0x7c);
            int b = *(int*)(obj + 0x84);
            struct Struct_02042c68* var7 = (struct Struct_02042c68*)(obj + 0xb4);
            int c = var7->a2;
            int sb = a * b;
            int var10 = c + 8;
            int d = var7->a0;
            int var12 = sb + a;
            int var13 = d + 0xc;
            unsigned short* var14 = (unsigned short*)(obj + 0x120);
            int var15 = var10;

            for (; sb < var12; sb++) {
                int special = var3;
                if (sb == var1 && var1 == sum) special = 0xf0a;
                unsigned short idx = *(unsigned short*)(obj + 0x220 + sb * 2);
                func_02045f3c((void*)ctx, var14 + idx, var13, var10, special, 0xc, 0x14, flag, 1, 0x11);
                var10 += *(int*)(obj + 0xd8);
            }

            if ((obj[0xb0] | obj[0xb1]) != 0) {
                int e = *(int*)(obj + 0x88);
                int f = *(int*)(obj + 0x8c);
                int g = *(int*)(obj + 0xd4);
                int h = var13 - 0x10;
                void* p2d8 = *(void**)(ctx + 0x2d8);
                int var23 = *(int*)(obj + 0xd8);
                int var24 = var15 - 2;
                int val2 = f;
                int val1 = e * g + h;
                val2 = val2 * var23 + var24;
                void* ctx2 = *(void**)(ctx + 0x2e0);
                unsigned short ev = *(unsigned short*)(ctx + 0x2e4);

                if (p2d8 != NULL && ctx2 != NULL) {
                    SpriteEntryList_PlayAnimation((struct Container0205a3d0*)ctx2, ev);
                    struct Entry0205a3d0* entry = SpriteEntryList_Find((struct Container0205a3d0*)ctx2, ev);
                    if (entry != NULL) entry->f15 |= 8;
                    struct Entry0205a3d0* entry2 = SpriteEntryList_Find((struct Container0205a3d0*)ctx2, ev);
                    if (entry2 != NULL) {
                        entry2->f4 = val1;
                        entry2->unknown_6_ = val2;
                    }
                    SpriteContext_DrawEntries(p2d8);
                }
            }
        }
    }
}
