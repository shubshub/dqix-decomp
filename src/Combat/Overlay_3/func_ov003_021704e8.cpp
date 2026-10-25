#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_021704e8 func_ov003_0216fd3c
#endif

struct Struct_0205a254;
struct Struct_0205a254_2;
struct Struct_ov003_0216dee4;

extern "C" void func_ov003_021705d4(void* obj, short* out1, short* out2);
void SetElemFields0216dee4(struct Obj0216dee4* obj, int idx, int v14, int v18, int v22, int v25, int v26);
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0* c, int key);
void ComputeValues_0217063c(unsigned char* obj, unsigned short* out1, unsigned short* out2);

#if defined(jpn)
extern "C" void func_0205b724(Container0205a3d0*, int);
void SpriteEntryList_SetPosition(Container0205a3d0*, int, short, short);
extern "C" void SpriteContext_DrawEntries(void*);
#endif

// USA: func_ov003_021704e8
extern "C" ARM void func_ov003_021704e8(char* arg0) {
    Struct_0205a254* var0 = *(Struct_0205a254**)(arg0 + 0xa4);
    if (var0 == NULL) return;

    short var1, var2;
    func_ov003_021705d4(arg0, &var1, &var2);
    if (var1 != 0 && var2 != 0) {
#if defined(jpn)
        func_0205b724(cont, 2);
        Elem0205a3d0* e = SpriteEntryList_Find(cont, 2);
        if (e != NULL) *(unsigned char*)((char*)e + 0x15) |= 8;
        SpriteEntryList_SetPosition(cont, 2, a, b);
        SpriteContext_DrawEntries(obj + 0x68);
#else
        func_ov003_0216dee4((struct Struct_ov003_0216dee4*)(arg0 + 0x68), 8, var1, var2, -1, 1, 3);
#endif
    } else {
        Elem0205a3d0* e = SpriteEntryList_Find(cont, 2);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) &= ~8;
        }
    }

    short var5, var6;
    func_ov003_0217063c((unsigned char*)arg0, (unsigned short*)&var5, (unsigned short*)&var6);
    if (var5 != 0 && var6 != 0) {
#if defined(jpn)
        func_0205b724(cont, 3);
        Elem0205a3d0* e = SpriteEntryList_Find(cont, 3);
        if (e != NULL) *(unsigned char*)((char*)e + 0x15) |= 8;
        SpriteEntryList_SetPosition(cont, 3, c, d);
        SpriteContext_DrawEntries(obj + 0x68);
#else
        func_ov003_0216dee4((struct Struct_ov003_0216dee4*)(arg0 + 0x68), 8, var5, var6, -1, 1, 3);
#endif
    } else {
        Elem0205a3d0* e = SpriteEntryList_Find(cont, 3);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) &= ~8;
        }
    }
}
