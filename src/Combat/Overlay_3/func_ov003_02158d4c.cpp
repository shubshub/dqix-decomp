#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"

extern "C" int func_02094a00(void);
extern "C" void func_02094ab0(void);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Cont0205d1e0;
void Window_ClearLayers(struct Cont0205d1e0* obj);
struct Cont0205d274;
void Window_FlushLayers(struct Cont0205d274* obj);
struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc* obj);
extern "C" void func_0205d048(void* obj);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
extern "C" int LoadToMainBG1ScreenData(int src, int offset, unsigned int size);
extern "C" int func_020421a0(void);
extern "C" void func_02043124(void* arg0);
extern "C" void func_02043204(char* arg0);
extern "C" void* __clear(void* arg0, int arg1);

struct Struct_ov003_02158d4c {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    char unknown_50_[0x7c - 0x50];
    int unknown_7c_;
    char unknown_80_[0xf4 - 0x80];
    char unknown_f4_[0x570 - 0xf4];
    struct Struct_020e25e8* unknown_570_;
    char unknown_574_[0x57c - 0x574];
    int unknown_57c_;
};

// USA: func_ov003_02158d4c
extern "C" ARM void func_ov003_02158d4c(Struct_ov003_02158d4c* arg0) {
    func_02094a00();
    func_02094ab0();

    if (arg0->unknown_570_ != NULL && func_020e28dc((struct Struct_020e28dc*)arg0->unknown_570_)) {
        func_020e25e8(arg0->unknown_570_);
    }

    unsigned int* var0 = (unsigned int*)0x4000000;
    *var0 = (*var0 & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)arg0->unknown_80_);

    Window_ClearLayers((struct Cont0205d1e0*)self->list0f4);
    Window_FlushLayers((struct Cont0205d274*)self->list0f4);
    Window_TransferLayers((struct Obj0205d2bc*)self->list0f4);
    func_0205d048(self->list0f4);

    arg0->unknown_28_.Reset();
    void* var1 = arg0->unknown_28_.Allocate(0x800);
    memset(var1, 0, 0x800);
    CleanInvalidateCacheRange(var1, 0x20);
    LoadToMainBG1CharacterData((int)var1, 0, 0x20);
    LoadToMainBG1ScreenData((int)var1, 0, 0x800);

    void* var2 = (void*)func_020421a0();
    func_02043124(var2);
    func_02043204((char*)var2);

    arg0->unknown_7c_ = 0;
    arg0->unknown_57c_ = 0;

    SafeAllocator* var3[5];
    __clear(var3, sizeof(var3));
    var3[0] = &arg0->unknown_3c_;
    var3[1] = &arg0->unknown_28_;
    var3[2] = &arg0->unknown_14_;
    var3[3] = &arg0->unknown_0_;

    for (int var4 = 0; var3[var4] != NULL; var4++) {
        if (var3[var4]->GetSignedAllocator() != NULL) {
            var3[var4]->Destroy();
        }
    }
}
