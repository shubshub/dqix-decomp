#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_0215c800_128 = 0x98 };
enum { Enum_ov003_0215c800_152 = 0xb0 };
enum { Enum_ov003_0215c800_124 = 0x94 };
enum { Enum_ov003_0215c800_1009 = 0x409 };
enum { Enum_ov003_0215c800_728 = 0x228 };
enum { Enum_ov003_0215c800_732 = 0x22c };
enum { Enum_ov003_0215c800_736 = 0x230 };
enum { Enum_ov003_0215c800_948 = 0x3cc };
enum { Enum_ov003_0215c800_852 = 0x36c };
#else
enum { Enum_ov003_0215c800_128 = 0x80 };
enum { Enum_ov003_0215c800_152 = 0x98 };
enum { Enum_ov003_0215c800_124 = 0x7c };
enum { Enum_ov003_0215c800_1009 = 0x3f1 };
enum { Enum_ov003_0215c800_728 = 0x2d8 };
enum { Enum_ov003_0215c800_732 = 0x2dc };
enum { Enum_ov003_0215c800_736 = 0x2e0 };
enum { Enum_ov003_0215c800_948 = 0x3b4 };
enum { Enum_ov003_0215c800_852 = 0x354 };
#endif

int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Cont0205d1e0;
void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d274;
void Window_FlushLayers(Cont0205d274*);
struct Obj0205d2bc;
void Window_TransferLayers(Obj0205d2bc*);
extern "C" void Window_Destroy(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* self);
void MessageSystem_Reset(char* obj);
extern "C" void* __clear(void* dst, int count);

// USA: func_ov003_0215c800  (semantic: ShutdownControllerAndDestroyAllocators_0215c800)
extern "C" ARM void func_ov003_0215c800(char* obj) {
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();

    int* var0 = (int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;
    *(short*)((char*)var0 + 0x50) = 0;
    func_02074bd0((struct Struct_02074bd0*)(arg0 + Enum_ov003_0215c800_128));

    Window_ClearLayers((Cont0205d1e0*)(obj + kRegionValue98_B0));
    Window_FlushLayers((Cont0205d274*)(obj + kRegionValue98_B0));
    Window_TransferLayers((Obj0205d2bc*)(obj + kRegionValue98_B0));
    Window_Destroy(obj + kRegionValue98_B0);

    memset(*(void**)(arg0 + Enum_ov003_0215c800_124), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(arg0 + Enum_ov003_0215c800_124), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(arg0 + Enum_ov003_0215c800_124), 0, 0x20);

    void* g = (void*)MessageSystem_GetInstance();
    MessageSystem_Stop(g);
    MessageSystem_Reset((char*)g);

    if (*(unsigned char*)(arg0 + Enum_ov003_0215c800_1009) == 0) {
        *(int*)((char*)var1 + Enum_ov003_0215c800_728) = 0;
        *(int*)((char*)var1 + Enum_ov003_0215c800_732) = 0;
        *(int*)((char*)var1 + Enum_ov003_0215c800_736) = 0;
    }

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

    *(int*)(arg0 + Enum_ov003_0215c800_948) = 0;
    *(int*)(arg0 + Enum_ov003_0215c800_852) = 0;
}
