#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"


#if defined(jpn)
enum { Enum_ov017_021b24d0_261 = 0x125, Enum_ov017_021b24d0_716 = 0x27c };
#else
enum { Enum_ov017_021b24d0_261 = 0x105, Enum_ov017_021b24d0_716 = 0x2cc };
#endif

extern "C" void HaltSystem(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void Overlay_Load(unsigned int id);
void PushInputLogB_020a1ef0(int value);
void PushInputLogA_020a1df8(int value);
extern "C" void func_ov011_0218438c(char* obj);
extern "C" void func_ov011_02184550(char* obj, SafeAllocator* allocator, void* data, unsigned int length);
void InitAndCreateTypeB021845c8(char* obj, void* buffer, unsigned int size);
void InitEntry02184640(char* obj, char* entry);
extern "C" void func_ov011_02184694(char* obj);
void Set3DClearColor(int a, int b, int c, int d, int e);

struct Struct_ov017_021b24d0 {
    char unknown_0_[Enum_ov017_021b24d0_261];
    unsigned char unknown_105_;
};

struct Struct_ov017_021b24d0_2 {
    char unknown_0_[0xc40];
    char unknown_c40_[1];
};

struct Struct_ov017_021d83f0_6 {
    int unknown_0_;
    char* unknown_4_;
};

extern Struct_ov017_021d83f0_6 data_ov017_021d83f0;

struct Struct_ov017_021b24d0_3 {
    char unknown_0_[8];
    int unknown_8_;
    int unknown_c_;
    SafeAllocator unknown_10_;
    char unknown_24_[0x30 - 0x24];
    void (*unknown_30_)(SafeAllocator* allocator, char* scene);
    char unknown_34_[0x38 - 0x34];
    unsigned int unknown_38_0_ : 5;
    unsigned int unknown_38_5_ : 1;
};

// USA: func_ov017_021b24d0
extern "C" ARM int func_ov017_021b24d0(Struct_ov017_021b24d0_3* arg0) {
    GameResources* var0 = GetGameResources();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    if (IsBrightnessTransitionActive(var0)) {
        return arg0->unknown_8_;
    }
    if (var1->GetTaskStatus(arg0->unknown_c_) == 0) {
        return arg0->unknown_8_;
    }
    if (loader->GetDetailedTaskStatus(task->taskId) != 2) {
        HaltSystem();
    }
    Flags021b24d0* flags = (Flags021b24d0*)Zone3D_GetInstance();
    if (flags != NULL) {
        flags->flags |= 1;
    }
    unsigned int length;
    void* data;
    loader->GetLoadedFileByID(task->taskId, &data, &length);
    if (data == NULL || length == 0) {
        HaltSystem();
    }
    Overlay_Load(OVERLAY_ID(11));
    PushInputLogB_020a1ef0(1);
    PushInputLogA_020a1df8(4);
    data_ov017_021d83f0.scene = (char*)task->allocator.Allocate(0x1e0);
    if (data_ov017_021d83f0.scene == NULL) {
        HaltSystem();
    }
    func_ov011_0218438c(data_ov017_021d83f0.unknown_4_);
    func_ov011_02184550(data_ov017_021d83f0.unknown_4_, &arg0->unknown_10_, var4, var3);
    if (arg0->unknown_30_ != NULL) {
        arg0->unknown_30_(&arg0->unknown_10_, data_ov017_021d83f0.unknown_4_);
    }
    unsigned int var5 = arg0->unknown_10_.GetMaxPossibleAllocation();
    func_ov011_021845c8(data_ov017_021d83f0.unknown_4_, arg0->unknown_10_.Allocate(var5), var5);
    func_ov011_02184640(data_ov017_021d83f0.unknown_4_, ((Struct_ov017_021b24d0_2*)((char*)var0 + Enum_ov017_021b24d0_716))->unknown_c40_);
    var1->RemoveTask(arg0->unknown_c_);
#if !defined(jpn)
    arg0->unknown_c_ = -1;
#endif
    func_ov011_02184694(data_ov017_021d83f0.unknown_4_);
    if (!arg0->unknown_38_5_) {
        SetFlags04(var0, 0x609fe);
    }
    Set3DClearColor(0, 0, 0x7fff, 0, 0);
    return 2;
}
