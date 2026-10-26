#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" int FontBankLoader_GetInstance(void);
struct Obj02094ab0;
extern "C" void FontBankLoader_CancelLoads(struct Obj02094ab0* obj);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274*);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void Window_Destroy(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_ov008_021894b8
extern "C" ARM void func_ov008_021894b8(unsigned char* self) {
    FontBankLoader_CancelLoads((struct Obj02094ab0*)FontBankLoader_GetInstance());

    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)reg + 0x50) = 0;

    func_02074bd0((struct Struct_02074bd0*)self);

    Window_ClearLayers((struct Cont0205d1e0*)(self + 0x18));
    Window_FlushLayers((struct Cont0205d274*)(self + 0x18));
    Window_TransferLayers((struct Obj0205d2bc*)(self + 0x18));
    Window_Destroy((void*)(self + 0x18));

    if (*(void**)(self + 0x2a4) != 0) {
        memset(*(void**)(self + 0x2a4), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(self + 0x2a4), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(self + 0x2a4), 0, 0x20);
    }

    *(int*)(self + 0x2a0) = 0;
    *(int*)(self + 0x2a4) = 0;

    void* var1[4];
    var1[0] = self + 0x200;
    var1[1] = self + 0x214;
    var1[2] = self + 0x228;
    var1[3] = self + 0x23c;

    for (int i = 0; i < 4; i++) {
        SafeAllocator* p = (SafeAllocator*)var1[i];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}
