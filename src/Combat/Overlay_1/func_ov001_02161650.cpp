#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern SafeAllocator* data_ov001_021658b8[8];
extern "C" void* func_02010768(void* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_0204a120;
extern "C" void func_0204a120(struct Struct_0204a120* obj);

struct Struct_0204a3f0_2;
struct Struct_0204a3f0;
extern "C" void func_0204a3f0(struct Struct_0204a3f0_2* owner, struct Struct_0204a3f0* h);

extern "C" void func_0204a440(char* obj, const char* src);
extern "C" void func_0204a464(char* obj, const char* src);

struct Struct_ov001_02161650 { int type; int val; int pad2; void* child; };
struct Struct_ov001_02165880_46 { char pad0[4]; Struct_ov001_02161650* table; };
extern struct Struct_ov001_02165880_46 data_ov001_02165880;

// USA: func_ov001_02161650
extern "C" ARM int func_ov001_02161650(char* self) {
    GameState* bs = GameState::GetInstance();
    SafeAllocator* allocator = data_ov001_021658b8[0];
    void* fieldPtr = func_02010768(bs);

    int a = func_ov017_021d60f4(self);
    void* name = func_ov017_021d612c(self + 0x8);
    void* var5 = func_ov017_021d612c(self + 0x10);

    void* child = data_ov001_02165880.table[a].child;
    if (child == 0 || data_ov001_02165880.table[a].type != 1) {
        return 0;
    }

    void* newObj = allocator->Allocate(0x268);
    if (newObj == 0) return 0;

    *(void**)((char*)fieldPtr + 0x4) = bs->GetCamera();

    func_0204a120((struct Struct_0204a120*)newObj);
    func_0204a3f0((struct Struct_0204a3f0_2*)newObj, (struct Struct_0204a3f0*)child);
    ((Object3D*)child)->UntrackAllBones();
    func_0204a440((char*)newObj, (const char*)name);
    func_0204a464((char*)newObj, (const char*)var5);
    ((Object3D*)((unsigned char*)child))->StopCurrentAnimation();
    ((Object3D*)((unsigned char*)child))->EnableFlag(1);
    ((Object3D*)((unsigned char*)child))->EnableFlag(0x20);

    GameState_SetCamera(bs, (int)newObj);
    return 1;
}
