#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValueCC_C8 = 0xc8 };
enum { kRegionValueE4_E0 = 0xe0 };
enum { Enum_ov003_02168324_728 = 0x228 };
enum { Enum_ov003_02168324_732 = 0x22c };
enum { Enum_ov003_02168324_736 = 0x230 };
enum { Enum_ov003_02168324_1252 = 0x4e0 };
#else
enum { kRegionValueCC_C8 = 0xcc };
enum { kRegionValueE4_E0 = 0xe4 };
enum { Enum_ov003_02168324_728 = 0x2d8 };
enum { Enum_ov003_02168324_732 = 0x2dc };
enum { Enum_ov003_02168324_736 = 0x2e0 };
enum { Enum_ov003_02168324_1252 = 0x4e4 };
#endif

extern "C" int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc*);
extern "C" void Window_Destroy(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* self);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void* __clear(void* dst, int count);

// USA: func_ov003_02168324
extern "C" ARM void func_ov003_02168324(char* obj) {
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();

    int* reg = (int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(short*)((char*)reg + 0x50) = 0;
    func_02074bd0((struct Struct_02074bd0*)(obj + kRegionValueCC_C8));

    Window_ClearLayers((Cont0205d1e0*)(obj + kRegionValueE4_E0));
    Window_FlushLayers((Cont0205d274*)(obj + kRegionValueE4_E0));
    Window_TransferLayers((Obj0205d2bc*)(obj + kRegionValueE4_E0));
    Window_Destroy(obj + kRegionValueE4_E0);

    memset(*(void**)(obj + 0x7c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(obj + 0x7c), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(obj + 0x7c), 0, 0x20);

    void* g = (void*)MessageSystem_GetInstance();
    MessageSystem_Stop(g);
    MessageSystem_Reset((char*)g);
    *(int*)((char*)g + Enum_ov003_02168324_728) = 0;
    *(int*)((char*)g + Enum_ov003_02168324_732) = 0;
    *(int*)((char*)g + Enum_ov003_02168324_736) = 0;
    *(int*)(obj + Enum_ov003_02168324_1252) = 0;

    SafeAllocator* arr[6];
    __clear(arr, sizeof(arr));
    arr[0] = (SafeAllocator*)(obj + 0x50);
    arr[1] = (SafeAllocator*)(obj + 0x3c);
    arr[2] = (SafeAllocator*)(obj + 0x28);
    arr[3] = (SafeAllocator*)(obj + 0x14);
    arr[4] = (SafeAllocator*)obj;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}
