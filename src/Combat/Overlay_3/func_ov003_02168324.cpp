#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_02168324_204 = 0xc8 };
enum { Enum_ov003_02168324_228 = 0xe0 };
enum { Enum_ov003_02168324_728 = 0x228 };
enum { Enum_ov003_02168324_732 = 0x22c };
enum { Enum_ov003_02168324_736 = 0x230 };
enum { Enum_ov003_02168324_1252 = 0x4e0 };
#else
enum { Enum_ov003_02168324_204 = 0xcc };
enum { Enum_ov003_02168324_228 = 0xe4 };
enum { Enum_ov003_02168324_728 = 0x2d8 };
enum { Enum_ov003_02168324_732 = 0x2dc };
enum { Enum_ov003_02168324_736 = 0x2e0 };
enum { Enum_ov003_02168324_1252 = 0x4e4 };
#endif

extern "C" int func_02094a00(void);
extern "C" void func_02094ab0(void);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Cont0205d1e0;
void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d274;
void Window_FlushLayers(Cont0205d274*);
struct Obj0205d2bc;
void Window_TransferLayers(Obj0205d2bc*);
extern "C" void func_0205d048(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int func_020421a0(void);
extern "C" void func_02043124(void* arg0);
extern "C" void func_02043204(char* arg0);
extern "C" void* __clear(void* arg0, int arg1);

// USA: func_ov003_02168324
extern "C" ARM void func_ov003_02168324(char* arg0) {
    func_02094a00();
    func_02094ab0();

    int* var0 = (int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;
    *(short*)((char*)var0 + 0x50) = 0;
    func_02074bd0((struct Struct_02074bd0*)(arg0 + Enum_ov003_02168324_204));

    Window_ClearLayers((Cont0205d1e0*)(obj + kRegionValueE4_E0));
    Window_FlushLayers((Cont0205d274*)(obj + kRegionValueE4_E0));
    Window_TransferLayers((Obj0205d2bc*)(obj + kRegionValueE4_E0));
    func_0205d048(obj + kRegionValueE4_E0);

    memset(*(void**)(arg0 + 0x7c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(arg0 + 0x7c), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(arg0 + 0x7c), 0, 0x20);

    void* var1 = (void*)func_020421a0();
    func_02043124(var1);
    func_02043204((char*)var1);
    *(int*)((char*)var1 + Enum_ov003_02168324_728) = 0;
    *(int*)((char*)var1 + Enum_ov003_02168324_732) = 0;
    *(int*)((char*)var1 + Enum_ov003_02168324_736) = 0;
    *(int*)(arg0 + Enum_ov003_02168324_1252) = 0;

    SafeAllocator* var2[6];
    __clear(var2, sizeof(var2));
    var2[0] = (SafeAllocator*)(arg0 + 0x50);
    var2[1] = (SafeAllocator*)(arg0 + 0x3c);
    var2[2] = (SafeAllocator*)(arg0 + 0x28);
    var2[3] = (SafeAllocator*)(arg0 + 0x14);
    var2[4] = (SafeAllocator*)arg0;

    for (int var3 = 0; var2[var3] != NULL; var3++) {
        if (var2[var3]->GetSignedAllocator() != NULL) {
            var2[var3]->Destroy();
        }
    }
}
