#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int FontBankLoader_GetInstance(void);
struct Obj02094ab0;
extern "C" void FontBankLoader_CancelLoads(struct Obj02094ab0* obj);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* arg0);

struct Cont0205d1e0;
void Window_ClearLayers(struct Cont0205d1e0*);
struct Cont0205d274;
void Window_FlushLayers(struct Cont0205d274*);
struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void Window_Destroy(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_ov008_021894b8
extern "C" ARM void func_ov008_021894b8(unsigned char* self) {
    FontBankLoader_CancelLoads((struct Obj02094ab0*)FontBankLoader_GetInstance());

    volatile unsigned int* var0 = (volatile unsigned int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)var0 + 0x50) = 0;

    func_02074bd0((struct Struct_02074bd0*)arg0);

    Window_ClearLayers((struct Cont0205d1e0*)(self + 0x18));
    Window_FlushLayers((struct Cont0205d274*)(self + 0x18));
    Window_TransferLayers((struct Obj0205d2bc*)(self + 0x18));
    Window_Destroy((void*)(self + 0x18));

    if (*(void**)(arg0 + 0x2a4) != 0) {
        memset(*(void**)(arg0 + 0x2a4), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(arg0 + 0x2a4), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(arg0 + 0x2a4), 0, 0x20);
    }

    *(int*)(arg0 + 0x2a0) = 0;
    *(int*)(arg0 + 0x2a4) = 0;

    void* var1[4];
    var1[0] = arg0 + 0x200;
    var1[1] = arg0 + 0x214;
    var1[2] = arg0 + 0x228;
    var1[3] = arg0 + 0x23c;

    for (int var2 = 0; var2 < 4; var2++) {
        SafeAllocator* var3 = (SafeAllocator*)var1[var2];
        if (var3->GetSignedAllocator()) {
            var3->Destroy();
        }
    }
}
