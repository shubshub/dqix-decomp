#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"

extern "C" int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0* obj);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274* obj);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc* obj);
extern "C" void Window_Destroy(void* obj);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
extern "C" int LoadToMainBG1ScreenData(int src, int offset, unsigned int size);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* self);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void* __clear(void* dst, int count);

struct Struct_ov003_02158d4c {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    char unknown_50_[0x7c - 0x50];
    int unknown_7c_;
    char unknown_80_[0xf4 - 0x80];
    char list0f4[0x570 - 0xf4];
    struct Struct_020e25e8* selection;
    char unknown_574_[0x57c - 0x574];
    int unknown_57c_;
};

// USA: func_ov003_02158d4c
extern "C" ARM void func_ov003_02158d4c(Struct_ov003_02158d4c* self) {
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();

    if (self->selection != NULL && func_020e28dc((struct Struct_020e28dc*)self->selection)) {
        func_020e25e8(self->selection);
    }

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)self->unknown_80_);

    Window_ClearLayers((struct Cont0205d1e0*)self->list0f4);
    Window_FlushLayers((struct Cont0205d274*)self->list0f4);
    Window_TransferLayers((struct Obj0205d2bc*)self->list0f4);
    Window_Destroy(self->list0f4);

    self->alloc28.Reset();
    void* buf = self->alloc28.Allocate(0x800);
    memset(buf, 0, 0x800);
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    LoadToMainBG1ScreenData((int)buf, 0, 0x800);

    void* g = (void*)MessageSystem_GetInstance();
    MessageSystem_Stop(g);
    MessageSystem_Reset((char*)g);

    self->unknown_7c_ = 0;
    self->unknown_57c_ = 0;

    SafeAllocator* arr[5];
    __clear(arr, sizeof(arr));
    arr[0] = &self->alloc3c;
    arr[1] = &self->alloc28;
    arr[2] = &self->unknown_14_;
    arr[3] = &self->unknown_0_;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}
