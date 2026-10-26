#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov017_021a316c_4544 = 0xfb0, Enum_ov017_021a316c_4412 = 0xf2c, Enum_ov017_021a316c_4676 = 0x1034, Field5dc = 0x58c, Enum_ov017_021a316c_9828 = 0x26a4 };
#else
enum { Enum_ov017_021a316c_4544 = 0x11c0, Enum_ov017_021a316c_4412 = 0x113c, Enum_ov017_021a316c_4676 = 0x1244, Field5dc = 0x5dc, Enum_ov017_021a316c_9828 = 0x2664 };
#endif

extern "C" void func_020da244(void* p);
extern "C" void* Zone3D_GetInstance(void);
extern int data_ov017_021d82fc;

extern "C" void func_ov017_021a27e8(void* controller);

extern "C" void* func_0203cf4c(void);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(struct Struct_0203cfb4* obj);

struct InitState0208f7ecStruct;
extern "C" void func_0208f7ec(struct InitState0208f7ecStruct* s);

struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);
struct PointerField330_ffd0;
extern "C" void* GameState_GetStarflight(struct PointerField330_ffd0* obj);

extern "C" void func_0200fd48(GameState* battleStruct, int id);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);

// USA: func_ov017_021a316c
extern "C" ARM void func_ov017_021a316c(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* globalPtr = (unsigned char*)Zone3D_GetInstance();
    int i;
    int j;
    int k;

    if (((SafeAllocator*)(obj + Enum_ov017_021a316c_4544))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4544))->Destroy();
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4544))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->Destroy();
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->Destroy();
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4412))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + Enum_ov017_021a316c_4676))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4676))->Destroy();
        ((SafeAllocator*)(obj + Enum_ov017_021a316c_4676))->ResetAllocatorPointer();
    }

    func_020da244(&data_ov017_021d82fc);
    func_ov017_021a27e8(obj);

    for (i = 0; i < 0x30; i++) {
        GameObject* c = battleStruct->GetFieldMonsterByIndex(i + 0x70);
        if (c) {
            ((Object3D*)((unsigned char*)c))->Destroy();
        }
    }

    ((SafeAllocator*)(obj + 0xc4))->Reset();
    VramState_Rewind((struct Foo0207df50*)(obj + Field5dc));

    for (j = 0; j < 0x30; j++) {
        GameObject* c = battleStruct->GetFieldMonsterByIndex(j + 0x70);
        if (c) {
            ((Object3D*)((unsigned char*)c))->Destroy();
        }
    }

    func_0203cfb4((struct Struct_0203cfb4*)func_0203cf4c());
    func_0208f7ec((struct InitState0208f7ecStruct*)(globalPtr + Enum_ov017_021a316c_9828));

    if (GameState_GetShip((struct PointerField32c_ffc0*)battleStruct)) {
        func_0200fd48(battleStruct, 0xc9);
    }
    if (GameState_GetStarflight((struct PointerField330_ffd0*)battleStruct)) {
        func_0200fd48(battleStruct, 0xca);
    }

    for (k = 1; k < 4; k++) {
        if (battleStruct->GetGameObjectByIndex(k + 0xca)) {
            func_0200fd48(battleStruct, k + 0xca);
        }
    }
    func_0200fd48(battleStruct, 0xce);
}
