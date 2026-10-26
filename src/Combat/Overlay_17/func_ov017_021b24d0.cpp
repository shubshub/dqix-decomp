#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"


#if defined(jpn)
enum { Enum_ov017_021b24d0_261 = 0x125, Field2cc = 0x27c };
#else
enum { Enum_ov017_021b24d0_261 = 0x105, Field2cc = 0x2cc };
#endif

extern "C" void HaltSystem(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_020a1ef0(int value);
extern "C" void func_020a1df8(int value);
extern "C" void func_ov011_0218438c(char* obj);
extern "C" void func_ov011_02184550(char* obj, SafeAllocator* allocator, void* data, unsigned int length);
extern "C" void func_ov011_021845c8(char* obj, void* buffer, unsigned int size);
extern "C" void func_ov011_02184640(char* obj, char* entry);
extern "C" void func_ov011_02184694(char* obj);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);

struct Flags021b24d0 {
    char pad[Enum_ov017_021b24d0_261];
    unsigned char flags;
};

struct Struct_ov017_021b24d0_2 {
    char pad[0xc40];
    char entry[1];
};

struct Struct_ov017_021d83f0_6 {
    int f0;
    char* scene;
};

extern Struct_ov017_021d83f0_6 data_ov017_021d83f0;

struct Struct_ov017_021b24d0_3 {
    char pad0[8];
    int result;
    int taskId;
    SafeAllocator allocator;
    char pad1[0x30 - 0x24];
    void (*unknown_30_)(SafeAllocator* allocator, char* scene);
    char pad2[0x38 - 0x34];
    unsigned int unknown_38_0_ : 5;
    unsigned int unknown_38_5_ : 1;
};

// USA: func_ov017_021b24d0
extern "C" ARM int func_ov017_021b24d0(Struct_ov017_021b24d0_3* task) {
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (IsBrightnessTransitionActive(res)) {
        return task->result;
    }
    if (loader->GetTaskStatus(task->taskId) == 0) {
        return task->result;
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
    func_020a1ef0(1);
    func_020a1df8(4);
    data_ov017_021d83f0.scene = (char*)task->allocator.Allocate(0x1e0);
    if (data_ov017_021d83f0.scene == NULL) {
        HaltSystem();
    }
    func_ov011_0218438c(data_ov017_021d83f0.scene);
    func_ov011_02184550(data_ov017_021d83f0.scene, &task->allocator, data, length);
    if (task->unknown_30_ != NULL) {
        task->unknown_30_(&task->allocator, data_ov017_021d83f0.scene);
    }
    unsigned int size = task->allocator.GetMaxPossibleAllocation();
    func_ov011_021845c8(data_ov017_021d83f0.scene, task->allocator.Allocate(size), size);
    func_ov011_02184640(data_ov017_021d83f0.scene, ((Struct_ov017_021b24d0_2*)((char*)res + Field2cc))->entry);
    loader->RemoveTask(task->taskId);
#if !defined(jpn)
    task->taskId = -1;
#endif
    func_ov011_02184694(data_ov017_021d83f0.scene);
    if (!task->unknown_38_5_) {
        SetFlags04(res, 0x609fe);
    }
    Set3DClearColor(0, 0, 0x7fff, 0, 0);
    return 2;
}
