#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_02094a00(void);
struct Struct_02094ab0;
extern "C" void func_02094ab0(struct Struct_02094ab0* arg0);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* arg0);

struct Cont0205d1e0;
void Window_ClearLayers(struct Cont0205d1e0*);
struct Cont0205d274;
void Window_FlushLayers(struct Cont0205d274*);
struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void func_0205d048(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_ov012_02185af0
extern "C" ARM void func_ov012_02185af0(unsigned char* arg0) {
    func_02094ab0((struct Struct_02094ab0*)func_02094a00());

    volatile unsigned int* var0 = (volatile unsigned int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)var0 + 0x50) = 0;

    func_02074bd0((struct Struct_02074bd0*)(arg0 + R(0,8)));

    Window_ClearLayers((struct Cont0205d1e0*)(self + R(0x90,0xac)));
    Window_FlushLayers((struct Cont0205d274*)(self + R(0x90,0xac)));
    Window_TransferLayers((struct Obj0205d2bc*)(self + R(0x90,0xac)));
    func_0205d048((void*)(self + R(0x90,0xac)));

    memset(*(void**)(arg0 + R(0x134c,0x137c)), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(arg0 + R(0x134c,0x137c)), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(arg0 + R(0x134c,0x137c)), 0, 0x20);

    *(int*)(arg0 + R(0x1344,0x1374)) = 0;
    *(int*)(arg0 + R(0x134c,0x137c)) = 0;

    void* var1[5];
    var1[0] = arg0 + R(0x18,0x20);
    var1[1] = arg0 + R(0x2c,0x34);
    var1[2] = arg0 + R(0x40,0x48);
    var1[3] = arg0 + R(0x54,0x5c);
    var1[4] = arg0 + R(0x68,0x70);

    for (int var2 = 0; var2 < 5; var2++) {
        SafeAllocator* var3 = (SafeAllocator*)var1[var2];
        if (var3->GetSignedAllocator()) {
            var3->Destroy();
        }
    }
}
